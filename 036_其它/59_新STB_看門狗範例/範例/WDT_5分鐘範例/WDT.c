#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
//
typedef struct
{
    short int pitch;
    short int duration;
} NOTE;
//
NOTE notes[] = {{14, 500}, {16, 500}, {12, 500}, {0, 500}, {7, 1000}};
//
void ShowErrorMsg(const char* szName, const DWORD dwLine,
                  const DWORD dwError)
{
    void* lpMsgBuf;
    char  szBuf[MAX_PATH] = {0};
//    
    if (!FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | 
                       FORMAT_MESSAGE_FROM_SYSTEM | 
                       FORMAT_MESSAGE_IGNORE_INSERTS,
                       0L,
                       dwError,
                       MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                       (LPTSTR)&lpMsgBuf,
                       0,
                       0L))
        return;
//
    sprintf(szBuf, "%s\nLine:%ld\nMessage:%s", szName,
            dwLine, (const char *)lpMsgBuf);
    MessageBox(NULL, szBuf, "Error", MB_OK | MB_ICONSTOP);
//
    LocalFree(lpMsgBuf);
};
//
char EnablePrivilege(IN const char*szPrivilege,
                     IN const char bEnable)
{
    TOKEN_PRIVILEGES tkp    = {0};
    HANDLE           hToken = 0L;
    char             ret    = 0;
//
    tkp.PrivilegeCount = 1;
    if (bEnable)
        tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    else
        tkp.Privileges[0].Attributes = 0;
//
    if (LookupPrivilegeValue(0L, szPrivilege, &tkp.Privileges[0].Luid))
    {
        HANDLE hProcess = GetCurrentProcess();
//
        if (hProcess)
        {
            if (OpenProcessToken(hProcess,
                                 TOKEN_ALL_ACCESS,
                                 &hToken))
            {
                tkp.PrivilegeCount = 1;
                if (!AdjustTokenPrivileges(hToken, 
                                           0,
                                           &tkp,
                                           0,
                                           0L,
                                           0))
                {
                    ShowErrorMsg("EnablePrivilege : AdjustTokenPrivileges",
                                 __LINE__, GetLastError());
                }
                else
                    ret = 1;
                CloseHandle(hToken);
                hToken = 0L;
            };
        };
    }
    else
    {
        ShowErrorMsg("EnablePrivilege : LookupPrivilegeValue",
                      __LINE__, GetLastError());
    };
//
    return ret;
};
//
void setfreq(int hz)
{
    hz = 1193180 / hz;
//
    __asm
    {
        xor eax, eax
        mov dx, 67   //43h
        mov ax, 182  //0b6h
        out dx, al

        xor eax, eax
        mov dx, 42h
        mov ax, word ptr hz
        out dx, al

        xor eax, eax
        mov ax, word ptr hz
        shr ax, 8
        mov dx, 66   //42h
        out dx, al
    };
/*
    _outp(67, 182);
    _outp(66, hz);
    _outp(66, hz >> 8);
*/
};
//
void playnote(NOTE note)
{
    _outp(0x61, _inp(0x61) | 0x03);
    setfreq((int)(400 * pow(2, note.pitch / 12.0)));
    Sleep(note.duration);
    _outp(0x61, _inp(0x61) & ~0x03);
};
//
void UnlockWDT()
{
    _outp(0x2e, 0x87);    //Un-lock super I/O
    _outp(0x2e, 0x87);    //Un-lock super I/O
};
//
void SelectDevice()
{
    _outp(0x2e, 0x07);
    _outp(0x2f, 0x08);
};
//
void ActivateWDT()
{
    _outp(0x2e, 0x30);
    _outp(0x2f, 0x01);
};
//
void SetSeconds()
{
    _outp(0x2e, 0xf5);
    //_outp(0x2f, 0x00);  //change to 0x08 for set minute
	_outp(0x2f, 0x08);  //5 minute change to 0x08 for set minute
};
//
void SetBaseTime()
{
    _outp(0x2e, 0xf6);
    //_outp(0x2f, 0x1e); //30 seconds, 00,01,02,¡KFF(Hex) ,Value=0 to 255
	//_outp(0x2f, 0x3c); //60 seconds, 00,01,02,¡KFF(Hex) ,Value=0 to 255
	//_outp(0x2f, 0xff); //255 seconds, 00,01,02,¡KFF(Hex) ,Value=0 to 255
	_outp(0x2f, 0x05);//_outp(0x2f, 0x08);  //5 minute change to 0x08 for set minute
};
//
void ResetWDT()
{
    _outp(0x2e, 0xf6);
    //_outp(0x2f, 0x1d);
	_outp(0x2f, 0x05);//_outp(0x2f, 0x08);  //5 minute change to 0x08 for set minute
};
//
void StartWDT()
{
    UnlockWDT();
    SelectDevice();
    ActivateWDT();
    SetSeconds();
    SetBaseTime();
};
//
void DisableWDT()
{
    _outp(0x2e, 0x30);
    _outp(0x2f, 0x00);
};
void main()
{
    short i;
    void* hnd = 0L;
//
    EnablePrivilege(SE_DEBUG_NAME, 1);
    hnd = CreateFile(TEXT("\\\\.\\iceportio"),
                     0L, 0L, 0L, OPEN_EXISTING, 0L, 0L);
    if (hnd == (void*)-1)
    {
        DWORD dw = GetLastError();
        return;
    };
    // for test i/o only
    for (i = 0; i < sizeof(notes)/sizeof(int); ++i)
        playnote(notes[i]);
    StartWDT();
	///*
    __try
    {
        while (1)
        {
            Sleep(1000*270);//WDT=5 minute
            ResetWDT();
        };
    }
    __finally
    {
        DisableWDT();        
        CloseHandle(hnd);
    };
	//*/
};