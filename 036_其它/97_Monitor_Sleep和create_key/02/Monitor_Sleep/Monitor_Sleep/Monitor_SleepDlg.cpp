
// Monitor_SleepDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "Monitor_Sleep.h"
#include "Monitor_SleepDlg.h"
#include "afxdialogex.h"
#include <mmsystem.h>//Step 1
#include <string.h>
#include <cstdio>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define WM_SHOWTASK	WM_USER+5//Step 2

///
//http://www.cnblogs.com/TianFang/archive/2012/10/12/2721883.html
//https://msdn.microsoft.com/zh-tw/library/windows/desktop/aa373208(v=vs.85).aspx
enum ExecutionFlag
{
	System = 0x00000001,
	Display = 0x00000002,
	Continus = 0x80000000,
};
/// <summary>
///阻止系统休眠，直到线程结束恢复休眠策略
/// </summary>
/// <param name="includeDisplay">是否阻止关闭显示器</param>
void PreventSleep(bool includeDisplay = false)
{
	if (includeDisplay)
	{
		::SetThreadExecutionState(0x00000001| 0x00000002| 0x80000000);// ExecutionFlag.System | ExecutionFlag.Display | ExecutionFlag.Continus
	}
	else
	{
		::SetThreadExecutionState(0x00000001 | 0x8000000);// ExecutionFlag.System | ExecutionFlag.Continus)
	}
}
/// <summary>
///恢复系统休眠策略
/// </summary>
static void ResotreSleep()
{
	SetThreadExecutionState(0x80000000);//ExecutionFlag.Continus);
}
///
// CMonitor_SleepDlg 對話方塊
int gintY,gintM,gintD;
float gfltT;
bool gblnRun;
////////////////////////////////////////////////
char BASE64CODE[64] = {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};

void base64en(char *srcStr, char *desStr)
{
    unsigned char srcCode[3];
    unsigned int i,j,len;

    len = strlen(srcStr)/3;
    for (i = 0; i < len; i++)
    {
        srcCode[0] = srcStr[i * 3 + 0];
        srcCode[1] = srcStr[i * 3 + 1];
        srcCode[2] = srcStr[i * 3 + 2];

        desStr[i * 4 + 0] = BASE64CODE[srcCode[0] >> 2];
        desStr[i * 4 + 1] = BASE64CODE[((srcCode[0]&0x03)<<4) + (srcCode[1]>>4)];
        desStr[i * 4 + 2] = BASE64CODE[((srcCode[1]&0x0f)<<2) + (srcCode[2]>>6)];
        desStr[i * 4 + 3] = BASE64CODE[srcCode[2]&0x3f];
    }

    i = len;
    j = strlen(srcStr) - len * 3;
    if (j > 0)
    {
        srcCode[0] = srcStr[i * 3 + 0];
        srcCode[1] = (j > 1) ? srcStr[i * 3 + 1] : '\0';
        srcCode[2] = '\0';

        desStr[i * 4 + 0] = BASE64CODE[srcCode[0] >> 2];
        desStr[i * 4 + 1] = BASE64CODE[((srcCode[0]&0x03)<<4) + (srcCode[1]>>4)];
        desStr[i * 4 + 2] = (srcCode[1] == '\0') ? '=' : BASE64CODE[(srcCode[1]&0x0f)<<2];
        desStr[i * 4 + 3] = '=';

        i++;
    }

    desStr[i * 4] = '\0';
}

int base64_index(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return ch - 'A';
    if (ch >= 'a' && ch <= 'z')
        return ch - 'a' + 26;
    if (ch >= '0' && ch <= '9')
        return ch - '0' + 52;
    if (ch == '+')
        return 62;
    if (ch == '/')
        return 63;
}

void base64de(char *srcStr, char *desStr)
{
    unsigned char srcCode[4];
    unsigned int i, j, len;

    len = strlen(srcStr)/4 - 1;
    for (i = 0; i < len; i++)
    {
        srcCode[0] = base64_index(srcStr[i * 4 + 0]);
        srcCode[1] = base64_index(srcStr[i * 4 + 1]);
        srcCode[2] = base64_index(srcStr[i * 4 + 2]);
        srcCode[3] = base64_index(srcStr[i * 4 + 3]);

        desStr[i * 3 + 0] = (srcCode[0]<<2) + (srcCode[1]>>4);
        desStr[i * 3 + 1] = (srcCode[1]<<4) + (srcCode[2]>>2);
        desStr[i * 3 + 2] = ((srcCode[2]&0x03)<<6) + srcCode[3];
    }

    i = len;

    srcCode[0] = base64_index(srcStr[i * 4 + 0]);
    srcCode[1] = base64_index(srcStr[i * 4 + 1]);

    desStr[i * 3 + 0] = (srcCode[0]<<2) + (srcCode[1]>>4);

    if (srcStr[i * 4 + 2] == '=')
    {
        desStr[i * 3 + 1] = '\0';
    }
    else if (srcStr[i * 4 + 3] == '=')
    {
        srcCode[2] = base64_index(srcStr[i * 4 + 2]);

        desStr[i * 3 + 1] = (srcCode[1]<<4) + (srcCode[2]>>2);
        desStr[i * 3 + 2] = '\0';
    }
    else
    {
        srcCode[2] = base64_index(srcStr[i * 4 + 2]);
        srcCode[3] = base64_index(srcStr[i * 4 + 3]);

        desStr[i * 3 + 1] = (srcCode[1]<<4) + (srcCode[2]>>2);
        desStr[i * 3 + 2] = ((srcCode[2]&0x03)<<6) + srcCode[3];
        desStr[i * 3 + 3] = '\0';
    }
}

CString GetPassword()
{
    char src[1000] = {0};
    char en[1000] = {0},de[1000];
    char chrkey[100];
    int intdatalen,intkeylen;
    int i,j;
    int a=0;
    FILE *pf;
    strcpy_s(chrkey, "jashkey");
	CString StrReturn="OOXXP@$$WORD";//CString StrReturn=L"OOXXP@$$WORD";
	pf='\0';
    fopen_s(&pf,"data.txt","r");
	if(pf!='\0')
	{
		j=0;
		while(fscanf_s(pf,"%d",&a)!=EOF)
		{
			if(a>0)
			{
				 //printf("%d\n",a);
				 en[j]=a;
				 //printf("en=%d\n",en[j]);
				 j++;
			}
		}
		fclose(pf);
		intdatalen=strlen(en);
		intkeylen=strlen(chrkey);
		j=-1;
		for(i=0;i<intdatalen;i++)
		{
			if(j<intkeylen)
			{
				j++;
			}
			else
			{
				j=0;
			}
			en[i]=en[i]^chrkey[j];
		}
		base64de(en, de);
		CString StrBuf(de);
		StrReturn=StrBuf;
	}
	return StrReturn;
}
////////////////////////////////////////////////


CMonitor_SleepDlg::CMonitor_SleepDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMonitor_SleepDlg::IDD, pParent)
	, m_StrSetTime(_T(""))
	, m_StrPassword(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMonitor_SleepDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StrSetTime);
	DDX_Text(pDX, IDC_EDIT2, m_StrPassword);
	DDX_Control(pDX, IDC_BUTTON1, m_b1);
	DDX_Control(pDX, IDC_BUTTON2, m_b2);
}

BEGIN_MESSAGE_MAP(CMonitor_SleepDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMonitor_SleepDlg::OnBnClickedButton1)
	ON_WM_TIMER()
	ON_MESSAGE(WM_SHOWTASK,onShowTask)//Step 5
	ON_BN_CLICKED(IDC_BUTTON2, &CMonitor_SleepDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CMonitor_SleepDlg 訊息處理常式

BOOL CMonitor_SleepDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	gblnRun=false;
	m_b1.EnableWindow(!gblnRun);
	m_b2.EnableWindow(gblnRun);

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CMonitor_SleepDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CMonitor_SleepDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMonitor_SleepDlg::OnBnClickedButton1()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	PreventSleep(true);
	UpdateData(true);
		CString StrBuf="";//CString StrBuf=L"";
		//StrBuf=L"輸入秒數:"+m_StrSetTime+L"\n";
		//StrBuf+=L"輸入密碼:"+ m_StrPassword+L"\n";
		gfltT = _ttof(m_StrSetTime);
		StrBuf=GetPassword();
		CString StrPassword=StrBuf.Mid(0,StrBuf.FindOneOf(","));
		CString StrDate=StrBuf.Mid(StrBuf.FindOneOf(",")+1);
		gintY=_ttoi(StrDate)/10000;
		gintM=(_ttoi(StrDate)%10000)/100;
		gintD=(_ttoi(StrDate)%10000)%100;
		CTime time = CTime::GetCurrentTime();
		int m_nYear = time.GetYear();      ///年
		int m_nMonth = time.GetMonth();      ///月
		int m_nDay = time.GetDay();      ///日
		if(StrPassword==m_StrPassword && gfltT>0 && (gintY>=m_nYear) && (gintM>=m_nMonth) && (gintD>=m_nDay))
		{
			DeleteFile("data.txt");//DeleteFile(L"data.txt");
			//--
			NOTIFYICONDATA nid;
			nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);
			nid.hWnd=this->m_hWnd;
			nid.uID=IDR_MAINFRAME;
			nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;
			nid.uCallbackMessage=WM_SHOWTASK;//自定義的消息名稱
			nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
			lstrcpyn(nid.szTip, _T("中文"),sizeof(nid.szTip));
			Shell_NotifyIcon(NIM_ADD,&nid);//在託盤區添加圖示
			ShowWindow(SW_HIDE);//隱藏主視窗
			//--
			::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);

			SetTimer(1,gfltT*1000,NULL);
			gblnRun=true;
			m_b1.EnableWindow(!gblnRun);
			m_b2.EnableWindow(gblnRun);

		}
		else
		{
			MessageBox("輸入資料有錯，程式即將關閉");//MessageBox(L"輸入資料有錯，程式即將關閉");
			AfxGetMainWnd()->SendMessage(WM_CLOSE);
		}

	UpdateData(false);
}


void CMonitor_SleepDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	KillTimer(1);
	PreventSleep(true);
	gblnRun=false;
	m_b1.EnableWindow(!gblnRun);
	m_b2.EnableWindow(gblnRun);
	CTime time = CTime::GetCurrentTime();
	int m_nYear = time.GetYear();      ///年
	int m_nMonth = time.GetMonth();      ///月
	int m_nDay = time.GetDay();      ///日
	if((gintY>=m_nYear) && (gintM>=m_nMonth) && (gintD>=m_nDay))
	{
		::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
	}
	else
	{
		::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 1);
		MessageBox("使用期限已過期，程式即將關閉");
		AfxGetMainWnd()->SendMessage(WM_CLOSE);
	}

	SetTimer(1,gfltT*1000,NULL);
	gblnRun=true;
	m_b1.EnableWindow(!gblnRun);
	m_b2.EnableWindow(gblnRun);

	CDialogEx::OnTimer(nIDEvent);
}
LRESULT CMonitor_SleepDlg::onShowTask(WPARAM wParam,LPARAM lParam)//Step 6
{
	//wParam接收的是圖示的ID，而lParam接收的是滑鼠的行為
	if(wParam!=IDR_MAINFRAME)
		return 1;
	switch(lParam)
	{
		case WM_RBUTTONUP://右鍵起來時彈出快顯功能表，這裏只有一個"關閉"
		{ 
			LPPOINT lpoint=new tagPOINT;
			::GetCursorPos(lpoint);//得到滑鼠位置
			CMenu menu;
			menu.CreatePopupMenu();//聲明一個彈出式功能表
			//增加功能表項"關閉"，點擊則發送消息WM_DESTROY給主視窗（已
			//隱藏），將程式結束。
			menu.AppendMenu(MF_STRING,WM_DESTROY,"關閉"); //menu.AppendMenu(MF_STRING,WM_DESTROY,L"關閉"); 
			//確定彈出式菜單的位置
			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);
			//資源回收
			HMENU hmenu=menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
		}
		break;
		case WM_LBUTTONDBLCLK://雙擊左鍵的處理
		{
			this->ShowWindow(SW_SHOW);//簡單的顯示主視窗完事兒
		}
		break;
	}
	return 0;
}


void CMonitor_SleepDlg::OnBnClickedButton2()
{
	// TODO: 在此加入控制項告知處理常式程式碼
	if(gblnRun==true)
	{
		::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 1);
		KillTimer(1);
		gblnRun=false;
		m_b1.EnableWindow(!gblnRun);
		m_b2.EnableWindow(gblnRun);
		PreventSleep(false);
		ResotreSleep();
	}
}
