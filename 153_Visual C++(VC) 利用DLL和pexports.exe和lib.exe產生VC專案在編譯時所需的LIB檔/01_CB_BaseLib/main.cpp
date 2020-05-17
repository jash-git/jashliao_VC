#include "main.h"
#include "stdio.h"
#define LogFile "BaseLib.log"
static int g_intDebug=1;
// a sample exported function
void WriteLog(const char *Msg,int state)
{
    if(g_intDebug==1)
    {
        FILE *pf='\0';
        if(state==1)
        {
            pf=fopen(LogFile,"w");
        }
        else
        {
            pf=fopen(LogFile,"a");
        }
        fprintf(pf,Msg);
        fprintf(pf, "\n");
        fclose(pf);
    }
}
void DLL_EXPORT SomeFunction(const LPCSTR sometext)
{
    MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
}
double DLL_EXPORT Add(double a, double b)//test_API
{
    WriteLog("\t Add API...",0);
    return a + b;
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
