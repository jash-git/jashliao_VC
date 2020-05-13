// Cute_Main_ControlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Cute_Main_Control.h"
#include "Cute_Main_ControlDlg.h"
#include "LaunchDLL.h"//第九版->為了做鍵盤偵測
#include "DibSection.h"
#include <mmsystem.h>//Step 縮小到系統工作列1
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define Spday_Max 365	//gStrSpday
#define CommanCount_Max 11	//blnCommandArray
#define CFData_Max 50	//ChangeFormData最大陣列值
#define conData_Max 10	//Control_Data最大陣列值
//#define PDData_Max 10	//ProgramData最大陣列值---->在12.1版移到 H 檔 
#define WM_SHOWTASK	WM_USER+5//Step 縮小到系統工作列2
bool blnCheckHide=false;//Step 縮小到系統工作列2
CString gStrSpday[Spday_Max];
int gintSpdayCount=0;
/////////////////////////////////////////////////////////////////////
//第11.0版的功能
bool gblnLogFlag=false;//第11.4版的功能
bool gblnErrFlag=false;//第11.4版的功能
bool gblnControlErrorLog=false;//0檔案1，1檔案2
FILE *gpfControlError1=NULL;
FILE *gpfControlError2=NULL;
FILE *gpfControlLog1=NULL;
FILE *gpfControlLog2=NULL;
//WCHAR *gpUnicodeDataBuf=NULL;//第12.8版->Unicode
WCHAR gpUnicodeDataBuf[200];
CString gStr2UnicodeData;//第12.8版->Unicode
int gintUnicodeDataLen=0;//第12.8版->Unicode
char gunicode[2];//第12.8版->Unicode   
WCHAR *gpUnicode = L"000000,0,Cute_Main Create\r\n";//第13.1版
bool gblnGetError=false;//第13.2版
CString gStrYesterday="";
bool gblnMonitorOnCheck=false;
bool gblnMonitorOffCheck=false;
/////////////////////////////////////////////////////////////////////
CString gStrNowStyle="";//存放目其版型名稱
struct ProgramData//存放要被啟動程式資訊
{
	CString StrName;
	CString StrCaption;
}gstructPD[PDData_Max];
int gintProgramNumber=0;//存放要被啟動程式個數
int gintProgramZindex[PDData_Max][2];//第12.1版本------------------>儲存顯示層次
bool gblnRunZindex=false;//第12.2版本
/////////////////////////////////////////////////////////////////////
struct ChangeFormData//存放改變版型訓訊息
{
	int intStart_Hr;
	int intStart_Min;
	int intEnd_Hr;
	int intEnd_Min;
	char chrFormName[100];
}gstructCFD[CFData_Max];
int gintCFDnumber=0;//存放版型數量
bool gblnChangeForm=false;//存放是否要執行判斷更換版型旗標
/////////////////////////////////////////////////////////////////////
//存放螢幕開關資料
//step 讀取XML3
struct Control_Data//存放螢幕開關資料
{
	int intStart_Hr;
	int intStart_Min;
	int intEnd_Hr;
	int intEnd_Min;
};
struct Control_Data gstruct_SunCD[conData_Max];
struct Control_Data gstruct_MonCD[conData_Max];
struct Control_Data gstruct_TueCD[conData_Max];
struct Control_Data gstruct_WedCD[conData_Max];
struct Control_Data gstruct_ThuCD[conData_Max];
struct Control_Data gstruct_FriCD[conData_Max];
struct Control_Data gstruct_SatCD[conData_Max];
int gintData_Max[7];
TCHAR gstrCurDrt[500];//存放目其目錄字串
//////////////////////////////////////////////////
int gintMonitorWidthPixels,gintMonitorHeightPixels;//第12.8版
/////////////////////////////////////////////////////////////////////////////
FILE *gpfUpdateProgram;//第13.3版
int gintUpdateProgramCount;//第13.3版
char MAP_NAME0[20]=	"spacesoft1 corp0.";//第13.3版
char MAP_NAME1[20]=	"spacesoft1 corp1.";//第13.3版
char MAP_NAME2[20]=	"spacesoft1 corp2.";//第13.3版
char MAP_NAME3[20]=	"spacesoft1 corp3.";//第13.3版
#define	MAP_LENGTH	8//第13.3版
HANDLE hFileMap[4] ={NULL,NULL,NULL,NULL} ;//第13.3版
static char szOldData[MAP_LENGTH] = "" ;//第13.3版
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCute_Main_ControlDlg dialog

CCute_Main_ControlDlg::CCute_Main_ControlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCute_Main_ControlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCute_Main_ControlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCute_Main_ControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCute_Main_ControlDlg)
	DDX_Control(pDX, IDC_JPG1, m_JPG);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCute_Main_ControlDlg, CDialog)
	//{{AFX_MSG_MAP(CCute_Main_ControlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_MESSAGE(WM_SHOWTASK,onShowTask)//Step 縮小到系統工作列5
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCute_Main_ControlDlg message handlers

BOOL CCute_Main_ControlDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	// TODO: Add extra initialization here
	InstallLaunchEv();//第九版->為了做鍵盤偵測
	hFileMap[0] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME0 ) ;//第13.3版
	//hFileMap[1] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME1 ) ;//第13.3版
	//hFileMap[2] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME2 ) ;//第13.3版
	//hFileMap[3] = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH, MAP_NAME3 ) ;//第13.3版
	ShowWindow(SW_MINIMIZE);//縮小主視窗
	/////////////////////////////////////////////////////////////////
	//第12.1版->限定滑鼠移動區域
	CRect rc;
	rc.top=1080;
	rc.bottom=(1080+200);
	rc.left=1920;
	rc.right=(1920+200); 
	::SetCursorPos((1920+(200/2)),(1080+(200/2)));  //另類隱藏游標
	ClipCursor(&rc);
	////////////////////////////////////////////////////////////////
	m_MainMonitor_On=false;//變數初始化->預設都不做甚何螢幕強制動作
	m_MainMonitor_Off=false;//變數初始化->預設都不做甚何螢幕強制動作
	gblnRunZindex=false;//第12.2版本
	CreateLogFile();//開啟紀錄資訊功能//第11.0版的功能
	InitializeXMLMemory();//初始化所有結構體變數並呼叫相對應填值函數填值
	GetProgramInfo();//取得要被執行程式資料
	TimerFunction();//直接執行主程式
	Sleep(20000);//讓程式效能降低
	OnButton1();//啟動Timer->固定時間執行主程式
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCute_Main_ControlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCute_Main_ControlDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCute_Main_ControlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCute_Main_ControlDlg::OnButton2() //隱藏視窗到系統工作列
{
	// TODO: Add your control notification handler code here
	if(blnCheckHide==false)
	{
		NOTIFYICONDATA nid;
		nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);
		nid.hWnd=this->m_hWnd;
		nid.uID=IDR_MAINFRAME;
		nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;
		nid.uCallbackMessage=WM_SHOWTASK;//自定義的消息名稱
		nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
		strcpy(nid.szTip,"Cute_Control");//資訊提示條為"計畫任務提醒"
		Shell_NotifyIcon(NIM_ADD,&nid);//在託盤區添加圖示
		blnCheckHide=true;
	}
	ShowWindow(SW_HIDE);//隱藏主視窗	
}
LRESULT CCute_Main_ControlDlg::onShowTask(WPARAM wParam,LPARAM lParam)//Step 縮小到系統工作列6
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
			menu.AppendMenu(MF_STRING,WM_DESTROY,"關閉"); 
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

void CCute_Main_ControlDlg::TimerFunction()//主程式
{
	int i=0,j=0;
	int startmin,endmin;
	CString StrStyleBuf;
	CString strFileName1;
	CString StrControlFileName;
	CString StrNowday;
	CString StrDayBuf;
	CString StrMonthBuf;
	bool blnSpday;
	bool blnRunChangeForm=false;
	int hr,min;
	/////////////////////////////////////////////////////////////////
	//第12.1版->限定滑鼠移動區域
	CRect rc;
	rc.top=1080;
	rc.bottom=(1080+200);
	rc.left=1920;
	rc.right=(1920+200); 
	::SetCursorPos((1920+(200/2)),(1080+(200/2)));  //另類隱藏游標
	ClipCursor(&rc);
	////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////
	//取得目前系統時間
	::SetCursorPos((1920+(200/2)),1080+(200/2));  //另類隱藏游標
	CTime t1=CTime::GetCurrentTime();
	int Year=t1.GetYear();//年 
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	/////////////////////////////////
	StrNowday.Format("%d",Year);
	if(Month<10)
	{
		StrMonthBuf.Format("0%d",Month); 
	}
	else
	{
		StrMonthBuf.Format("%d",Month);
	}
	if(Day<10)
	{
		StrDayBuf.Format("0%d",Day); 
	}
	else
	{
		StrDayBuf.Format("%d",Day);
	}
	StrNowday=StrNowday+StrMonthBuf+StrDayBuf;
	CreateLogFile();//開啟紀錄資訊功能//第11.0版的功能
	/////////////////////////////////
	int week=t1.GetDayOfWeek()-1;//標準為1 -> 7;改成0 -> 6  
	hr=t1.GetHour();
	min=t1.GetMinute();
	min+=hr*60;
	////////////////////////////////////////////////////////////////////////////////
	//和螢幕開關機做比對，判對是否要改變旗標
	bool blnMonitor_On=false;
	switch(week)
	{
		case 0:
			for(i=0;i<gintData_Max[week];i++)
			{
				startmin=gstruct_SunCD[i].intStart_Hr*60+gstruct_SunCD[i].intStart_Min;
				endmin=gstruct_SunCD[i].intEnd_Hr*60+gstruct_SunCD[i].intEnd_Min;
				if(min>=startmin && min<endmin)
				{
					blnMonitor_On=true;
					break;
				}
			}
			break;
		case 1:
			for(i=0;i<gintData_Max[week];i++)
			{
				startmin=gstruct_MonCD[i].intStart_Hr*60+gstruct_MonCD[i].intStart_Min;
				endmin=gstruct_MonCD[i].intEnd_Hr*60+gstruct_MonCD[i].intEnd_Min;
				if(min>=startmin && min<endmin)
				{
					blnMonitor_On=true;
					break;
				}
			}
			break;
		case 2:
			for(i=0;i<gintData_Max[week];i++)
			{
				startmin=gstruct_TueCD[i].intStart_Hr*60+gstruct_TueCD[i].intStart_Min;
				endmin=gstruct_TueCD[i].intEnd_Hr*60+gstruct_TueCD[i].intEnd_Min;
				if(min>=startmin && min<endmin)
				{
					blnMonitor_On=true;
					break;
				}
			}
			break;
		case 3:
			for(i=0;i<gintData_Max[week];i++)
			{
				startmin=gstruct_WedCD[i].intStart_Hr*60+gstruct_WedCD[i].intStart_Min;
				endmin=gstruct_WedCD[i].intEnd_Hr*60+gstruct_WedCD[i].intEnd_Min;
				if(min>=startmin && min<endmin)
				{
					blnMonitor_On=true;
					break;
				}
			}
			break;
		case 4:
			for(i=0;i<gintData_Max[week];i++)
			{
				startmin=gstruct_ThuCD[i].intStart_Hr*60+gstruct_ThuCD[i].intStart_Min;
				endmin=gstruct_ThuCD[i].intEnd_Hr*60+gstruct_ThuCD[i].intEnd_Min;
				if(min>=startmin && min<endmin)
				{
					blnMonitor_On=true;
					break;
				}
			}
			break;
		case 5:
			for(i=0;i<gintData_Max[week];i++)
			{
				startmin=gstruct_FriCD[i].intStart_Hr*60+gstruct_FriCD[i].intStart_Min;
				endmin=gstruct_FriCD[i].intEnd_Hr*60+gstruct_FriCD[i].intEnd_Min;
				if(min>=startmin && min<endmin)
				{
					blnMonitor_On=true;
					break;
				}
			}
			break;
		case 6:
			for(i=0;i<gintData_Max[week];i++)
			{
				startmin=gstruct_SatCD[i].intStart_Hr*60+gstruct_SatCD[i].intStart_Min;
				endmin=gstruct_SatCD[i].intEnd_Hr*60+gstruct_SatCD[i].intEnd_Min;
				if(min>=startmin && min<endmin)
				{
					blnMonitor_On=true;
					break;
				}
			}
			break;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////
	//偵測是否有命令訊息
	Detect_Command();
	//////////////////////////////////
	//讀取是否有今日切換版型的命令
	gblnChangeForm=Read_ChangeForm();
	if(gblnChangeForm)
	{
		for(i=0;i<gintCFDnumber;i++)
		{
			startmin=gstructCFD[i].intStart_Hr*60+gstructCFD[i].intStart_Min;  
			endmin=gstructCFD[i].intEnd_Hr*60+gstructCFD[i].intEnd_Min;
			if(min>=startmin && min<endmin)
			{
				StrStyleBuf=gstructCFD[i].chrFormName;
				if(StrStyleBuf!=gStrNowStyle)
				{
					Run_Command(3);//Stop_Program
					ChangeStyle(StrStyleBuf);
					GetProgramInfo();
					Run_Command(2);//Start_Program
					gStrNowStyle=StrStyleBuf;
				}
				blnRunChangeForm=true;//第11.0版的功能,保持隔天回到預設版型
				break;//第11.0版的功能,保持隔天回到預設版型
			}
			blnRunChangeForm=false;//第11.0版的功能,保持隔天回到預設版型
		}
		////////////////////////////////////////////////////
		//第11.0版的功能,保持隔天回到預設版型
		if(blnRunChangeForm==false)
		{
			if(gStrNowStyle!="Default")
			{
				gStrNowStyle="Default";
				Run_Command(3);//Stop_Program
				ChangeStyle(gStrNowStyle);
				GetProgramInfo();
				Run_Command(2);//Start_Program
			}
		}
		////////////////////////////////////////////////////
	}
	//////////////////////////////////////////////////////////////////////////
	if(!(m_MainMonitor_On^m_MainMonitor_Off))
	{
		blnSpday=false;
		for(i=0;i<gintSpdayCount;i++)
		{
			if(gStrSpday[i]==StrNowday)
			{
				blnSpday=true;
				break;
			}
		}
		if(blnSpday)
		{
			Run_Command(3);//Stop_Program
			Run_Command(1);//Monitor_Off
			//this->SetWindowText("Cute_Main_Control-Off");//第九版的功能 ->為了可以有固定標題
		}
		else
		{
			if(blnMonitor_On)
			{
				SwitchMonitor();//第12.7版->送CTRL+ALT+F9使新的STBㄧ定要選監視器輸出
				Run_Command(2);//Start_Program
				Run_Command(0);//Monitor_On
				::SetCursorPos((1920+(200/2)),(1080+(200/2)));  //另類隱藏游標
				//this->SetWindowText("Cute_Main_Control-On");//第九版的功能 ->為了可以有固定標題 
			}
			else
			{
				Run_Command(3);//Stop_Program
				CreateCommunication();//以確保通訊程式永遠存在----->第八版的功能
				Run_Command(1);//Monitor_Off
				//this->SetWindowText("Cute_Main_Control-Off");//第九版的功能 ->為了可以有固定標題 
			}
		}
	}
	else
	{
		CreateCommunication();//以確保通訊程式永遠存在----->第八版的功能
		if(m_MainMonitor_On)
		{
			SwitchMonitor();//第12.7版->送CTRL+ALT+F9使新的STBㄧ定要選監視器輸出
			Run_Command(0);//Monitor_On
		}
		else
		{
			Run_Command(1);//Monitor_Off
		}
	}
	m_WDT.ResetWDT();//第14.1版->Watch Dog Timer 
}
void CCute_Main_ControlDlg::OnTimer(UINT nIDEvent) //step 讀取XML4
{
	// TODO: Add your message handler code here and/or call default
	TimerFunction();
	CDialog::OnTimer(nIDEvent);
}

void CCute_Main_ControlDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,10000,NULL);
}

void CCute_Main_ControlDlg::Read_Monitor()//step 讀取XML4
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	bool blnRead=false;
	CString strValue;
	//int intHr,intMin;
	char chrDataBuf[1000];
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
		MSXML2::IXMLDOMNodePtr  Sunday_Start;
		MSXML2::IXMLDOMNodePtr  Monday_Start; 
		MSXML2::IXMLDOMNodePtr  Tuesday_Start; 
		MSXML2::IXMLDOMNodePtr  Wednesday_Start; 
		MSXML2::IXMLDOMNodePtr  Thursday_Start; 
		MSXML2::IXMLDOMNodePtr  Friday_Start; 
		MSXML2::IXMLDOMNodePtr  Saturday_Start; 
		//在樹中尋找節點,"//"表示在任意一層查找 
		////////////////////////////////////////////////////////////
		Sunday_Start=pDoc->selectSingleNode("//Sunday_Start");	
		Sunday_Start->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0)); 
		MonitorRipData(strValue,0);
		//MessageBox(chrDataBuf);
		Monday_Start=pDoc->selectSingleNode("//Monday_Start");	
		Monday_Start->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0));
		MonitorRipData(strValue,1);
		//MessageBox(chrDataBuf);
		Tuesday_Start=pDoc->selectSingleNode("//Tuesday_Start");	
		Tuesday_Start->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0));
		MonitorRipData(strValue,2);
		//MessageBox(chrDataBuf);
		Wednesday_Start=pDoc->selectSingleNode("//Wednesday_Start");	
		Wednesday_Start->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0));
		MonitorRipData(strValue,3);
		//MessageBox(chrDataBuf);
		Thursday_Start=pDoc->selectSingleNode("//Thursday_Start");	
		Thursday_Start->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0));
		MonitorRipData(strValue,4);
		//MessageBox(chrDataBuf);
		Friday_Start=pDoc->selectSingleNode("//Friday_Start");	
		Friday_Start->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0));
		MonitorRipData(strValue,5);
		//MessageBox(chrDataBuf);
		Saturday_Start=pDoc->selectSingleNode("//Saturday_Start");	
		Saturday_Start->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0));
		MonitorRipData(strValue,6);
		//MessageBox(chrDataBuf);
	}
	else//第11.0版的功能
	{
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				////delete [] gpUnicodeDataBuf;//釋放記憶體
				////gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				////delete [] gpUnicodeDataBuf;//釋放記憶體
				////gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}
void CCute_Main_ControlDlg::MonitorRipData(CString Datainput,int day)
{
	////////////////////////////////////
	CString StrIP="";
	CString StrBuf="";
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	long lngLen=0;//建立長度暫存變數
	long lngGetLen1=0;//提取資料長度
	long lngGetLen2=0;//剩餘資料長度
	CString m_strInData="";//主
	CString strInData="";//m_strInData分身
	CString strRemain="";//剩餘資料
	char chrSeps[]="+";//建立分割符號
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	bool blnLen=false;//判斷長度是否為0
	int intCount=0;//紀錄第幾筆資料
	////////////////////////////////////////
	int intHr1,intHr2;
	int intMin1,intMin2;
	m_strInData=Datainput;
	strInData=m_strInData;//取出原來資料
	do
	{
		chrInBuf=strInData.GetBuffer(0);//賦予資料
		lngLen=strlen(chrInBuf);
		if(lngLen<= 0)//防堵最後一筆資料換行所造成誤判
		{
			blnLen=true;
			break;
		}
		chrOutBuf=strtok(chrInBuf,chrSeps);//擷取的資料
		sscanf(chrOutBuf,"%d:%d-%d:%d",&intHr1,&intMin1,&intHr2,&intMin2);
		switch(day)
		{
			case 0:
				gstruct_SunCD[intCount].intStart_Hr=intHr1;
				gstruct_SunCD[intCount].intStart_Min=intMin1;
				gstruct_SunCD[intCount].intEnd_Hr=intHr2;
				gstruct_SunCD[intCount].intEnd_Min=intMin2;
				break;
			case 1:
				gstruct_MonCD[intCount].intStart_Hr=intHr1;
				gstruct_MonCD[intCount].intStart_Min=intMin1; 
				gstruct_MonCD[intCount].intEnd_Hr=intHr2; 
				gstruct_MonCD[intCount].intEnd_Min=intMin2; 
				break;
			case 2:
				gstruct_TueCD[intCount].intStart_Hr=intHr1;
				gstruct_TueCD[intCount].intStart_Min=intMin1;  
				gstruct_TueCD[intCount].intEnd_Hr=intHr2; 
				gstruct_TueCD[intCount].intEnd_Min=intMin2;  
				break;
			case 3:
				gstruct_WedCD[intCount].intStart_Hr=intHr1;
				gstruct_WedCD[intCount].intStart_Min=intMin1;
				gstruct_WedCD[intCount].intEnd_Hr=intHr2; 
				gstruct_WedCD[intCount].intEnd_Min=intMin2;  
				break;
			case 4:
				gstruct_ThuCD[intCount].intStart_Hr=intHr1;
				gstruct_ThuCD[intCount].intStart_Min=intMin1;
				gstruct_ThuCD[intCount].intEnd_Hr=intHr2; 
				gstruct_ThuCD[intCount].intEnd_Min=intMin2; 
				break;
			case 5:
				gstruct_FriCD[intCount].intStart_Hr=intHr1;
				gstruct_FriCD[intCount].intStart_Min=intMin1;
				gstruct_FriCD[intCount].intEnd_Hr=intHr2; 
				gstruct_FriCD[intCount].intEnd_Min=intMin2;  
				break;
			case 6:
				gstruct_SatCD[intCount].intStart_Hr=intHr1; 
				gstruct_SatCD[intCount].intStart_Min=intMin1; 
				gstruct_SatCD[intCount].intEnd_Hr=intHr2; 
				gstruct_SatCD[intCount].intEnd_Min=intMin2;  
				break;
		}
		intCount++;
		lngGetLen1=strlen(chrOutBuf);//提取資料長度
		lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
		if(intCount==1)
		{
			if(lngGetLen2>0)
				strRemain=m_strInData.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			else
				strRemain="";
		}
		else
		{
			if(lngGetLen2>0)
				strRemain=strRemain.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			else
				strRemain="";
		}
		strInData=strRemain;
	}while(intCount<conData_Max);
	gintData_Max[day]=intCount;
}
void CCute_Main_ControlDlg::InitializeXMLMemory()
{
	int i,j;
	gunicode[0] = 0xFF;//第12.8版->Unicode   
	gunicode[1] = 0xFE;//第12.8版->Unicode 
	gblnRunZindex=false;
	GetSpeciallyDay();
	///////////////////////////////////////////////////
	for(i=0;i<conData_Max;i++)
	{
		gstruct_SunCD[i].intEnd_Hr=0;
		gstruct_SunCD[i].intEnd_Min=0; 
		gstruct_SunCD[i].intStart_Hr=0; 
		gstruct_SunCD[i].intStart_Min=0; 
		/////////////////
		gstruct_MonCD[i].intEnd_Hr=0; 
		gstruct_MonCD[i].intEnd_Min=0; 
		gstruct_MonCD[i].intStart_Hr=0; 
		gstruct_MonCD[i].intStart_Min=0;
		////////////////
		gstruct_TueCD[i].intEnd_Hr=0; 
		gstruct_TueCD[i].intEnd_Min=0; 
		gstruct_TueCD[i].intStart_Hr=0; 
		gstruct_TueCD[i].intStart_Min=0;
		/////////////////
		gstruct_WedCD[i].intEnd_Hr=0; 
		gstruct_WedCD[i].intEnd_Min=0; 
		gstruct_WedCD[i].intStart_Hr=0; 
		gstruct_WedCD[i].intStart_Min=0; 
		/////////////////
		gstruct_ThuCD[i].intEnd_Hr=0; 
		gstruct_ThuCD[i].intEnd_Min=0; 
		gstruct_ThuCD[i].intStart_Hr=0; 
		gstruct_ThuCD[i].intStart_Min=0; 
		////////////////
		gstruct_FriCD[i].intEnd_Hr=0; 
		gstruct_FriCD[i].intEnd_Min=0; 
		gstruct_FriCD[i].intStart_Hr=0; 
		gstruct_FriCD[i].intStart_Min=0;
		/////////////////
		gstruct_SatCD[i].intEnd_Hr=0; 
		gstruct_SatCD[i].intEnd_Min=0; 
		gstruct_SatCD[i].intStart_Hr=0; 
		gstruct_SatCD[i].intStart_Min=0; 
	}
	for(j=0;j<7;j++)
		gintData_Max[j]=0;
	Read_Monitor();//----->由於改版因此將要將程式放到InitializeXMLMemory
	///////////////////////////////////////////////////////////////////////
	char chrbuf[100]="";
	for(i=0;i<CFData_Max;i++)
	{
		gstructCFD[i].intEnd_Hr=0;
		gstructCFD[i].intEnd_Min=0;
		gstructCFD[i].intStart_Hr=0; 
		gstructCFD[i].intStart_Min=0;
		strcpy(gstructCFD[i].chrFormName,chrbuf); 
	}
	Create_ChangeForm();
	////////////////////////////////////////////////////////////////////////
	SetVolume();
	//////////////
	ChangMonitorSize();//第12.8版->擷取與設定螢幕解析度
}
void CCute_Main_ControlDlg::Detect_Command()//偵測是否有命令訊息
{
	CString StrFileName;//第13.3版 
	MSXML2::IXMLDOMDocumentPtr pDoc;
	_variant_t vtStr;
	CString strValue;
	bool blnRead=false;
	int intCommandNumber=-1;
	char chrDataBuf[1000];
	int intcommand=-1;
	int i=0;
	CTime t1=CTime::GetCurrentTime();
	bool blnCommandArray[CommanCount_Max];
	//////////////////////////////////
	//出使命令旗標陣列
	for(i=0;i<CommanCount_Max;i++)
	{
		/*
		00->reload progran
		01->progran stop
		02->progran start
		03->reload setting
		04->movie stop
		05->movie start
		06->強制 monitor on
		07->強制 monitor off
		08->normal
		09->GetMonitorPicture
		10->Reset_Computer
		*/
		blnCommandArray[i]=false;
	}
	//////////////////////////////////////
	//讀取命令檔案
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Command\\Command.msg"; 
	blnRead=pDoc->load((_bstr_t)strFileName1);
	///////////////////////////////////////////////////////////////
	//拆解命令->並放到旗標陣列之中
	if(blnRead)
	{
		MSXML2::IXMLDOMNodePtr  Command;
		//在樹中尋找節點,"//"表示在任意一層查找 
		////////////////////////////////////////////////////////////
		Command=pDoc->selectSingleNode("//Command");	
		Command->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal;
		strcpy(chrDataBuf,strValue.GetBuffer(0));
		intcommand=atoi(chrDataBuf);
		////////////////////////////////////////////////////////////
		//第11.0版的功能
		if(gblnLogFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlLog2,"%s,0,Run Command Number (%d)\n",strTime.GetBuffer(0),intcommand);
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,0,Run Command Number (%d)\r\n",strTime.GetBuffer(0),intcommand);//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
				////delete [] gpUnicodeDataBuf;//釋放記憶體
				////gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlLog1,"%s,0,Run Command Number (%d)\n",strTime.GetBuffer(0),intcommand);
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,0,Run Command Number (%d)\r\n",strTime.GetBuffer(0),intcommand);//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
				////delete [] gpUnicodeDataBuf;//釋放記憶體
				////gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////
		for(i=0;i<CommanCount_Max;i++)
		{
			/*
			00->reload progran
			01->progran stop
			02->progran start
			03->reload setting
			04->movie stop
			05->movie start
			06->強制 monitor on
			07->強制 monitor off
			08->normal
			09->GetMonitorPicture
			10->Reset_Computer
			*/
			blnCommandArray[i]=(bool)(intcommand &((int)pow(2,i)));
		}
		//////////////////////////////////////////////
		//////權限高,優先做一次
		if(blnCommandArray[6])//->強制 monitor on
		{
			Run_Command(8);
		}
		if(blnCommandArray[7])//->強制 monitor off
		{
			Run_Command(9);
		}
		if(blnCommandArray[8])//->normal
		{
			Run_Command(10);
		}
		////////////////////////////////////////////////
		//依序執行每項命令
		for(i=0;i<CommanCount_Max;i++)
		{
			if(blnCommandArray[i])
			{
				switch(i)
				{
					case 0://->reload progran
						gpfUpdateProgram=fopen("UpdateProgram.txt","w");//開啟更新程式記錄檔
						gintUpdateProgramCount=0;//更新程式數量旗標初始化
						StrFileName = gstrCurDrt;//取得目前程式路徑
						StrFileName +="Resources\\Data\\ProgUpdate\\";//產生更新檔所在路徑
						BrowseUpdateProgram(StrFileName);//搜尋更新檔
						fclose(gpfUpdateProgram);//關閉更新程式記錄檔
						if(gintUpdateProgramCount>0)//判斷是否要更新程式
						{
							/////////////////////////////////////////////////////////
							//記憶體映射初始化
							LPVOID mapView[4];
							char ch1[10];
							//for(int i=0;i<4;i++)
							//{
								//mapView[i] = MapViewOfFile( hFileMap[i],FILE_MAP_WRITE, 0, 0, 0 ) ;
							//}
							mapView[0] = MapViewOfFile( hFileMap[0],FILE_MAP_WRITE, 0, 0, 0 ) ;
							//////////////////////////////////////////////////////////
							if( mapView[0] != NULL ) 
							{
								itoa(gintUpdateProgramCount,ch1,10);//將更新筆數從數值變字串
								strcpy((LPTSTR)mapView[0],ch1);//將筆數資料給映射變數
								UnmapViewOfFile( (LPVOID)mapView[0]);//更新映射變數
								//strcpy((LPTSTR)mapView[1],ch1);//將筆數資料給映射變數
								//UnmapViewOfFile( (LPVOID)mapView[1]);//更新映射變數
								//strcpy((LPTSTR)mapView[2],ch1);//將筆數資料給映射變數
								//UnmapViewOfFile( (LPVOID)mapView[2]);//更新映射變數
								//strcpy((LPTSTR)mapView[3],ch1);//將筆數資料給映射變數
								//UnmapViewOfFile( (LPVOID)mapView[3]);//更新映射變數	
							}
						}
						else
						{
							Run_Command(4);//不用更新程式直接執行reload progran
						}
						break;
					case 1://->progran stop
						Run_Command(3);
						break;
					case 2://->progran start
						Run_Command(2);
						break;
					case 3://->reload setting
						Run_Command(5);
						break;
					case 4://->movie stop
						Run_Command(6);
						break;
					case 5://->movie start
						Run_Command(7);
						break;
					case 6://->強制 monitor on
						Run_Command(8);
						break;
					case 7://->強制 monitor off
						Run_Command(9);
						break;
					case 8://->normal
						Run_Command(10);
						break;
					case 9://GetMonitorPicture
						Run_Command(11);
						break;
					case 10://Reset_Computer
						Run_Command(12);
						break;
				}
			}
		}
		DeleteFile(strFileName1);//刪除命令檔
	}
}
void CCute_Main_ControlDlg::Run_Command(int intCommandNumber)
{
	int nLen;
	CString StrFileName;
	CTime t1=CTime::GetCurrentTime();
	switch(intCommandNumber)
	{
	case 0://Monitor_On
		////////////////////////////////////
		//第11.0版的功能
		if(gblnLogFlag==true)
		{
			if(gblnMonitorOnCheck==false)
			{
				CString strTime = t1.Format("%H%M%S"); 
				if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
				{
					//fprintf(gpfControlLog2,"%s,0,Normal Monitor_On\n",strTime.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,0,Normal Monitor_On\r\n",strTime.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
					////delete [] gpUnicodeDataBuf;//釋放記憶體
					////gpUnicodeDataBuf=NULL;//釋放記憶體
				}
				else
				{
					//fprintf(gpfControlLog1,"%s,0,Normal Monitor_On\n",strTime.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,0,Normal Monitor_On\r\n",strTime.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
					////delete [] gpUnicodeDataBuf;//釋放記憶體
					////gpUnicodeDataBuf=NULL;//釋放記憶體
				}			
				gblnMonitorOnCheck=true;
				gblnMonitorOffCheck=false;
			}
		}
		/////////////////////////////////////
		::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);//Turnon
		//MessageBox("Monitor_On");
		break;
	case 1://Monitor_Off
		/////////////////////////////////////
		//第11.0版的功能
		if(gblnLogFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(gblnMonitorOffCheck==false)
			{
				if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
				{
					//fprintf(gpfControlLog2,"%s,0,Normal Monitor_Off\n",strTime.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,0,Normal Monitor_Off\r\n",strTime.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
					////delete [] gpUnicodeDataBuf;//釋放記憶體
					////gpUnicodeDataBuf=NULL;//釋放記憶體					
				}
				else
				{
					//fprintf(gpfControlLog1,"%s,0,Normal Monitor_Off\n",strTime.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,0,Normal Monitor_Off\r\n",strTime.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
					//delete [] gpUnicodeDataBuf;//釋放記憶體
					//gpUnicodeDataBuf=NULL;//釋放記憶體
				}
				gblnMonitorOnCheck=false;
				gblnMonitorOffCheck=true;
			}
		}
		//////////////////////////////////////
		::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);//Turnoff
		//MessageBox("Monitor_Off");
		break;
	case 2://Start_Program
		Start_Program();
		break;
	case 3://Stop_Program
		Stop_Program();
		nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
		if( gstrCurDrt[nLen]!='\\' )
		{
			gstrCurDrt[nLen++] = '\\';
			gstrCurDrt[nLen] = '\0';
		}
		gpfUpdateProgram=fopen("UpdateProgram.txt","w");//開啟更新程式記錄檔
		gintUpdateProgramCount=0;//更新程式數量旗標初始化
		StrFileName = gstrCurDrt;//取得目前程式路徑
		StrFileName +="Resources\\Data\\ProgUpdate\\";//產生更新檔所在路徑
		BrowseUpdateProgram(StrFileName);//搜尋更新檔
		fclose(gpfUpdateProgram);//關閉更新程式記錄檔
		if(gintUpdateProgramCount>0)//判斷是否要更新程式
		{
			/////////////////////////////////////////////////////////
			//記憶體映射初始化
			LPVOID mapView[4];
			char ch1[10];
			//for(int i=0;i<4;i++)
			//{
				//mapView[i] = MapViewOfFile( hFileMap[i],FILE_MAP_WRITE, 0, 0, 0 ) ;
			//}
			mapView[0] = MapViewOfFile( hFileMap[0],FILE_MAP_WRITE, 0, 0, 0 ) ;
			//////////////////////////////////////////////////////////
			if( mapView[0] != NULL ) 
			{
				itoa(gintUpdateProgramCount,ch1,10);//將更新筆數從數值變字串
				strcpy((LPTSTR)mapView[0],ch1);//將筆數資料給映射變數
				UnmapViewOfFile( (LPVOID)mapView[0]);//更新映射變數
				//strcpy((LPTSTR)mapView[1],ch1);//將筆數資料給映射變數
				//UnmapViewOfFile( (LPVOID)mapView[1]);//更新映射變數
				//strcpy((LPTSTR)mapView[2],ch1);//將筆數資料給映射變數
				//UnmapViewOfFile( (LPVOID)mapView[2]);//更新映射變數
				//strcpy((LPTSTR)mapView[3],ch1);//將筆數資料給映射變數
				//UnmapViewOfFile( (LPVOID)mapView[3]);//更新映射變數	
			}
		}
		break;
	case 4://Reload_Program
		CWnd* hWnd1;
		hWnd1=FindWindow(NULL, "卸除式磁碟 (E:)");
		if(hWnd1!=NULL)
		{
			hWnd1->SendMessage(WM_CLOSE,0,0);
			/*
			ShowWindow(SW_SHOWNORMAL);
			POINT lpPoint; 
			GetCursorPos(&lpPoint);
			SetCursorPos(10,5); 
			mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
			mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			*/
		}
		Stop_Program();
		InitializeXMLMemory();
		GetProgramInfo();
		Start_Program();
		Sleep(10000);//第11.2版的功能，降低系統效能
		break;
	case 5://Reload_Setting
		InitializeXMLMemory();
		break;
	case 6://Movie_Stop
		OnlyControlMovie(false);
		break;
	case 7://Movie_Start
		OnlyControlMovie(true);
		break;
	case 8://強制Monitor_On
		m_MainMonitor_On=true;
		m_MainMonitor_Off=false;
		::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);//Turnon
		break;
	case 9://強制Monitor_Off
		m_MainMonitor_On=false;
		m_MainMonitor_Off=true;
		::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);//Turnoff
		break;
	case 10://Normal
		m_MainMonitor_On=false;
		m_MainMonitor_Off=false;
		break;
	case 11://GetMonitorPicture
		GetMonitorPicture();
		break;
	case 12://Reset_Computer
		Reset_Computer();
		break;
	}
}
void CCute_Main_ControlDlg::Start_Program()
{
	CWnd* hWnd0;
	CString StrName,StrCaption;
	CString StrVersion;
	HINSTANCE result;
	CTime t1=CTime::GetCurrentTime();
	KillTimer(1);//第12.1版，為了防止程式被重複啟動
	//////////////////////////////////////////////////////////
	//依序取出程式名稱和標題，並判斷是否友執行，若無執行則執行
	int i;
	int j,k;
	for(i=0;i<gintProgramNumber;i++)
	{
		j=gintProgramZindex[i][0];//程式編號，第12.1版
		k=gintProgramZindex[i][1];//第12.1版
		StrName=gstructPD[j].StrName+".exe"; 
		StrCaption=gstructPD[j].StrCaption;
		hWnd0=NULL;
		hWnd0 = FindWindow(NULL, StrCaption.GetBuffer(0));
		if(hWnd0==NULL)
		{
			/*
			if(StrName=="chtvSignage_Player.exe")
			{
				ShowWindow(SW_SHOWNORMAL);
				POINT lpPoint; 
				GetCursorPos(&lpPoint);
				SetCursorPos(10,5); 
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
			}
			*/		
			result=ShellExecute(NULL,"open",StrName.GetBuffer(0),NULL,NULL,SW_SHOWNORMAL);
			if((int)result>32)//第11.0版的功能
			{
				StrVersion="";//第13.7版->查詢程式版本
				StrVersion=GetProgramVersion(StrName);//第13.7版->查詢程式版本
				///////////////////////////////////////////////////////////////////////
				gblnRunZindex=true;//第12.2版本
				///////////////////////////////////////////////////////////////////////
				CString strTime = t1.Format("%H%M%S"); 
				if(gblnLogFlag==true)
				{
					if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
					{
						//fprintf(gpfControlLog2,"%s,0,Start program OK->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
						//第12.8版->Unicode
						gStr2UnicodeData.Format("%s,0,Start program OK->%s %s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0),StrVersion.GetBuffer(0));//產生要寫入資料 
						gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
						////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
						MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
						fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
						//delete [] gpUnicodeDataBuf;//釋放記憶體
						//gpUnicodeDataBuf=NULL;//釋放記憶體
					}
					else
					{
						//fprintf(gpfControlLog1,"%s,0,Start program OK->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
						//第12.8版->Unicode
						gStr2UnicodeData.Format("%s,0,Start program OK->%s %s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0),StrVersion.GetBuffer(0));//產生要寫入資料 
						gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
						////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
						MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
						fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
						//delete [] gpUnicodeDataBuf;//釋放記憶體
						//gpUnicodeDataBuf=NULL;//釋放記憶體
					}
				}
			}
			else
			{
				CString strTime = t1.Format("%H%M%S"); 
				if(gblnErrFlag==true)
				{
					if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
					{
						//fprintf(gpfControlError2,"%s,9,Not Create program->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
						//第12.8版->Unicode
						gStr2UnicodeData.Format("%s,9,Not Create program->%s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0));//產生要寫入資料 
						gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
						////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
						MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
						fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
						gblnGetError=true;//第13.2版
						//delete [] gpUnicodeDataBuf;//釋放記憶體
						//gpUnicodeDataBuf=NULL;//釋放記憶體
					}
					else
					{
						//fprintf(gpfControlError1,"%s,9,Not Create program->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
						//第12.8版->Unicode
						gStr2UnicodeData.Format("%s,9,Not Create program->%s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0));//產生要寫入資料 
						gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
						////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
						MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
						fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
						gblnGetError=true;//第13.2版
						//delete [] gpUnicodeDataBuf;//釋放記憶體
						//gpUnicodeDataBuf=NULL;//釋放記憶體
					}
				}
			}
		}
		//else//第11.2版的功能，防堵隨身碟更新勝無法顯示在上層
		//{
		if(gblnRunZindex)
		{
			hWnd0=NULL;
			do
			{
				hWnd0 = FindWindow(NULL, StrCaption.GetBuffer(0));
			}while(hWnd0==NULL);
			gblnRunZindex=false;
			if(k<1000)
			{
				bool blnget=false;
				this->ShowWindow(SW_SHOWNORMAL);
				::SetWindowPos(this->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
				POINT lpPoint; 
				GetCursorPos(&lpPoint);
				SetCursorPos(10,5); 
				mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
				mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
				do
				{
					blnget=::SetWindowPos(hWnd0->m_hWnd,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
					Sleep(1000);
				}while(blnget==false);
			}
		}
		//}
		
	}
	//////////////////////////////////////////////////////////////////////////////////
	//MessageBox("Start_Program");
	this->ShowWindow(SW_MINIMIZE);
	::SetCursorPos((1920+(200/2)),(1080+(200/2)));  //另類隱藏游標
	SetTimer(1,10000,NULL);//第12.1版，為了防止程式被重複啟動
}
void CCute_Main_ControlDlg::Stop_Program()
{
	//MessageBox("Stop_Program");
	CWnd* hWnd[PDData_Max];
	int i;
	CString StrCaption;
	///////////////////////////////////////////////////////////////////
	//依序取出程式名稱和標題，並判斷是否友執行，若有執行則關閉
	for(i=0;i<gintProgramNumber;i++)
	{
		StrCaption=gstructPD[i].StrCaption;
		if(StrCaption!="chtvSignage_Communication")//禁止殺Communication
		{
			hWnd[i]= FindWindow(NULL,StrCaption.GetBuffer(0));
			if(hWnd[i]!=NULL)
				hWnd[i]->SendMessage(WM_CLOSE,0,0);
		}
	}
	//////////////////////////////////////////////////////////////////////
	gblnRunZindex=false;//第12.2版本
}

void CCute_Main_ControlDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default

	CDialog::OnClose();
}

BOOL CCute_Main_ControlDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	CWnd* hWnd[PDData_Max];
	int i;
	CString StrCaption;
	CTime t1=CTime::GetCurrentTime();
	CString strFileName1;//第13.2版
	CString DeleteFileName;//第13.2版
	///////////////////////////////////////////////////////////////////
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Export_Data\\Main\\";
	///////////////////////////////////////////////////////////////////
	//依序取出程式名稱和標題，並判斷是否友執行，若有執行則關閉
	for(i=0;i<gintProgramNumber;i++)
	{
		StrCaption=gstructPD[i].StrCaption;
		hWnd[i]= FindWindow(NULL,StrCaption.GetBuffer(0));
		if(hWnd[i]!=NULL)
			hWnd[i]->SendMessage(WM_CLOSE,0,0);
	}
	//////////////////////////////////////////////////////////////////////
	//第11.0版的功能
	if(gblnLogFlag==true)//1紀錄檔打開執行,0不要記錄
	{
		CString strTime = t1.Format("%H%M%S"); 
		if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
		{
			//fprintf(gpfControlLog2,"%s,0,End time\n",strTime.GetBuffer(0));
			//第12.8版->Unicode
			gStr2UnicodeData.Format("%s,0,End time\r\n",strTime.GetBuffer(0));//產生要寫入資料 
			gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
			////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
			MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
			fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
			//delete [] gpUnicodeDataBuf;//釋放記憶體
			//gpUnicodeDataBuf=NULL;//釋放記憶體
		}
		else
		{
			//fprintf(gpfControlLog1,"%s,0,End time\n",strTime.GetBuffer(0));
			//第12.8版->Unicode
			gStr2UnicodeData.Format("%s,0,End time\r\n",strTime.GetBuffer(0));//產生要寫入資料 
			gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
			////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
			MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
			fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
			//delete [] gpUnicodeDataBuf;//釋放記憶體
			//gpUnicodeDataBuf=NULL;//釋放記憶體
		}
		if(gpfControlError1!=NULL)
		{
			fclose(gpfControlError1);
			if(gblnGetError!=true)
			{
				DeleteFileName=strFileName1;
				DeleteFileName+=gStrYesterday+"err";
				DeleteFileName+=".log";
				DeleteFile(DeleteFileName);
			}
		}
		if(gpfControlError2!=NULL)
		{
			fclose(gpfControlError2);
			if(gblnGetError!=true)
			{
				DeleteFileName=strFileName1;
				DeleteFileName+=gStrYesterday+"err";
				DeleteFileName+=".log";
				DeleteFile(DeleteFileName);
			}
		}
		if(gpfControlLog1!=NULL)
		{
			fclose(gpfControlLog1);
		}
		if(gpfControlLog2!=NULL)
		{
			fclose(gpfControlLog2);
		}
	}
	//////////////////////////////////////////////////////////////////////
	ClipCursor(NULL);//第12.1版->解除限定滑鼠移動區域
	return CDialog::DestroyWindow();
}

bool CCute_Main_ControlDlg::Read_ChangeForm()
{
	gblnChangeForm=false;
	int i;
	char chrbuf[100]="";
	CString StrFindTag="//s";
	CString StrBuf[3];
	bool blnRead=false;
	//int hr,min;
	///////////////////////////////////
	//讀取年月日
	CTime t1=CTime::GetCurrentTime();
	int Year=t1.GetYear();//年
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	////////////////////////////////////////////////
	//合成搜尋標籤
	StrBuf[0].Format("%d",Year); 
	StrBuf[1].Format("%d",Month);
	if(StrBuf[1].GetLength()==1)
		StrBuf[1]="0"+StrBuf[1];
	StrBuf[2].Format("%d",Day);
	if(StrBuf[2].GetLength()==1)
		StrBuf[2]="0"+StrBuf[2];
	StrFindTag+=StrBuf[0]+StrBuf[1]+StrBuf[2];
	///////////////////////////////////////////////////
	//讀取載入設定檔
	_variant_t vtStr;
	CString strValue;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hre = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hre))
	{
	   return false;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\changeform.dat";
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)
	{
		//pDoc->load("changeform.dat"); 
		////////////////////////////////////////////////////////////////
		//搜尋今日標籤
		MSXML2::IXMLDOMNodePtr  pNode;
		//在樹中查找名為Book的節點,"//"表示在任意一層查找 
		pNode=pDoc->selectSingleNode((_bstr_t)StrFindTag);
		//pNode=pDoc->selectSingleNode("//s20080310");
		if(pNode!=NULL)
		{
			//////////////////////////////////////////
			//初始化變數
			for(i=0;i<CFData_Max;i++)
			{
				gstructCFD[i].intEnd_Hr=0;
				gstructCFD[i].intEnd_Min=0;
				gstructCFD[i].intStart_Hr=0; 
				gstructCFD[i].intStart_Min=0;
				strcpy(gstructCFD[i].chrFormName,chrbuf); 
			}
			gintCFDnumber=0;
			//////////////////////////////////////////////
			//取得XML值
			pNode->get_nodeTypedValue(&vtStr);
			strValue=vtStr.bstrVal;
			/////////////////////////////////////////////////
			ChangeFormRipData(strValue);//拆解資料放到指定的變數中
			return true;
		}
		else
		{
			return false;
		}
		///////////////////////////////////////////////
	}
	else
	{
		//第11.0版的功能
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H:%M:%S");
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
		return false;
	}
}

void CCute_Main_ControlDlg::Create_ChangeForm()
{
	bool blnRead=false;
	CTime t1=CTime::GetCurrentTime();
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	//pDoc->load("SignageConfig.xml");
	if(blnRead)
	{
		MSXML2::IXMLDOMNodePtr  pNode;
 
		//在樹中查找名為Book的節點,"//"表示在任意一層查找 
		pNode=pDoc->selectSingleNode("//changeform");
		if(pNode!=NULL)
		{
			_bstr_t bstrData;
			CString StrData;
			CFile file1;
			bstrData=pNode->Getxml();
			StrData=(LPCSTR)bstrData;
			strFileName1 = gstrCurDrt;
			strFileName1 +="Resources\\Setting\\changeform.dat";
			file1.Open(strFileName1.GetBuffer(0),CFile::modeCreate|CFile::modeWrite);
			file1.Write( StrData.GetBuffer(0),StrData.GetLength());
			file1.Close(); 
		}
	}
	else
	{
		//第11.0版的功能
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體				
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}

void CCute_Main_ControlDlg::ChangeFormRipData(CString Datainput)
{
	CString StrIP="";
	CString StrBuf="";
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	long lngLen=0;//建立長度暫存變數
	long lngGetLen1=0;//提取資料長度
	long lngGetLen2=0;//剩餘資料長度
	CString m_strInData="";//主
	CString strInData="";//m_strInData分身
	CString strRemain="";//剩餘資料
	char chrSeps[]=";";//建立分割符號
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	bool blnLen=false;//判斷長度是否為0
	int intCount=0;//紀錄第幾筆資料
	////////////////////////////////////////
	char chrxmldata[100];
	int intHr1,intMin1,intHr2,intMin2;
	m_strInData=Datainput;
	strInData=m_strInData;//取出原來資料
	do
	{
		chrInBuf=strInData.GetBuffer(0);//賦予資料
		lngLen=strlen(chrInBuf);
		if(lngLen<= 0)//防堵最後一筆資料換行所造成誤判
		{
			blnLen=true;
			break;
		}
		chrOutBuf=strtok(chrInBuf,chrSeps);//擷取的資料
		//////////////////////////////////////////////////////////////////////////////////////////
		//分析
		sscanf(chrOutBuf,"%d:%d-%d:%d-%s",&intHr1,&intMin1,&intHr2,&intMin2,chrxmldata);
		gstructCFD[intCount].intEnd_Hr=intHr2;
		gstructCFD[intCount].intEnd_Min=intMin2;
		gstructCFD[intCount].intStart_Hr=intHr1; 
		gstructCFD[intCount].intStart_Min=intMin1;
		//////////////////////////////////////////////////////////////////////////////////////////
		strcpy(gstructCFD[intCount].chrFormName,chrxmldata); 		
		intCount++;
		lngGetLen1=strlen(chrOutBuf);//提取資料長度
		lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
		if(intCount==1)
		{
			if(lngGetLen2>0)
				strRemain=m_strInData.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			else
				strRemain="";
		}
		else
		{
			if(lngGetLen2>0)
				strRemain=strRemain.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			else
				strRemain="";
		}
		strInData=strRemain;
	}while(intCount<CFData_Max);
	gintCFDnumber=intCount;
}

void CCute_Main_ControlDlg::GetProgramInfo()
{
	int i,j;
	int k,l;
	CString StrBuf="";
	gintProgramNumber=0;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	bool blnRead=false;
	///////////////////////////////////////////////////////////////////
	gblnRunZindex=false;//第12.2版本
	///////////////////////////////////////////////////////////////////
	//變數初始化
	for(i=0;i<PDData_Max;i++)
	{
		gstructPD[i].StrCaption="";
		gstructPD[i].StrName=""; 
		gintProgramZindex[i][0]=0;//第12.1版本------------------>儲存顯示層次,ID
		gintProgramZindex[i][1]=0;;//第12.1版本------------------>儲存顯示層次,Z
	}
	//////////////////////////////////////////////////////////////////
	//載入設定檔
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	///////////////////////////////////////////////////////////////
	if(blnRead)
	{
		//pDoc->load("SignageConfig.xml");
		MSXML2::IXMLDOMNodePtr pNodeRoot;
		MSXML2::IXMLDOMNodeListPtr  pNodeList;
		MSXML2::IXMLDOMNodePtr   pNode;
 		MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap=NULL;
		MSXML2::IXMLDOMNodePtr   pAttrItem;
		MSXML2::IXMLDOMNodePtr   pAttrItem_0;
		_variant_t variantValue_0;
		_variant_t variantValue;
		MSXML2::IXMLDOMDocumentPtr   pxmldom1;
		MSXML2::IXMLDOMNodeListPtr  pNodeList1;
		MSXML2::IXMLDOMNodePtr   pNode1;
 		MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap1=NULL;
		MSXML2::IXMLDOMNodePtr   pAttrItem1;
		_variant_t variantValue1;
		//////////////////////////////////////////////////
		MSXML2::IXMLDOMNodeListPtr  pNodeList3;
		MSXML2::IXMLDOMNodePtr   pNode3;
 		MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap3=NULL;
		MSXML2::IXMLDOMNodePtr   pAttrItem2;
		_variant_t variantValue3;
		CString StrZindex;
		char *charZbuf;
		int m;
		///////////////////////////////////////////////////
		//在樹中查找名為Book的節點,"//"表示在任意一層查找
		///////////////////////////////////////////////////////
		//找尋程式資料標籤
		pNodeRoot=pDoc->selectSingleNode("//startPrograms");
		pNodeRoot->get_childNodes(&pNodeList);
		j=pNodeList->length;
		////////////////////////////////////////////////////////
		//依序取出子節點
		for(i=0;i<j;i++)
		{
			CString StrData;
			pNode=pNodeList->item[i];
			pNode->get_attributes(&pAttrMap);
			pAttrMap->get_item(0,&pAttrItem_0);
			//pAttrMap->get_item(1,&pAttrItem);
			//取得節點的值
			pAttrItem_0->get_nodeTypedValue(&variantValue_0);
			//pAttrItem->get_nodeTypedValue(&variantValue);
			StrBuf=(char *)pNode->GetnodeName();;
			StrData=(char *)(_bstr_t)variantValue_0;
			////////////////////////////////////////////////////////////
			//判斷是否為TRUE
			StrData.MakeLower();//第13.2版->防呆全部轉小寫 
			if(StrData=="true")
			{
				_bstr_t bt1;
				gStrNowStyle=StrBuf;
				bt1=pNode->Getxml();
				hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
				pxmldom1->loadXML(bt1);
				pNodeList1=pxmldom1->selectNodes("//program");
				l=pNodeList1->length;
				gintProgramNumber=l;
				//////////////////////////////////////////////////////////
				//把為TRUE的資料放到變數
				for(k=0;k<l;k++)
				{
					pNode1=pNodeList1->item[k];
					pNode1->get_attributes(&pAttrMap1);
					pAttrMap1->get_item(0,&pAttrItem1);
					//取得節點的值
					pAttrItem1->get_nodeTypedValue(&variantValue1);
					gstructPD[k].StrName=(char *)(_bstr_t)variantValue1;
					//////////////////////////////////////////////////
					MSXML2::IXMLDOMDocumentPtr   pxmldom2;
					MSXML2::IXMLDOMNodePtr   pNode2;
					_bstr_t bt2;
					bt2=pNode1->Getxml();
					hr = pxmldom2.CreateInstance(__uuidof(MSXML2::DOMDocument30));
					pxmldom2->loadXML(bt2);
					pNode2=pxmldom2->selectSingleNode("//formname");
					_variant_t vtStr;
					pNode2->get_nodeTypedValue(&vtStr);  
					gstructPD[k].StrCaption=vtStr.bstrVal; 	
					//////////////////////////////////////////
					gintProgramZindex[k][0]=k;//第12.1版本------------------>儲存顯示層次,ID
					pNodeList3=pxmldom2->selectNodes("//zindex");
					m=pNodeList3->length;
					if(m>0)
					{
						pNode3=pNodeList3->item[0];
						pNode3->get_nodeTypedValue(&variantValue3); 
						StrZindex=variantValue3.bstrVal;
						charZbuf=StrZindex.GetBuffer(0);
						gintProgramZindex[k][1]=atoi(charZbuf);//第12.1版本------------------>儲存顯示層次,Z
					}
					else
					{
						gintProgramZindex[k][1]=1000;;//第12.1版本------------------>儲存顯示層次,Z
						//Z值,越小越上層
					}
				}
				///////////////////////////////////////////////////////////////
				BoBoProgramZindex(gintProgramZindex,gintProgramNumber);
				break;//跳離I迴圈
			}
			///////////////////////////////////////////////////////////////////
		}
		///////////////////////////////////////////////////////////////////////
	}
	else
	{
		//第11.0版的功能
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體				
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}

void CCute_Main_ControlDlg::ChangeStyle(CString StrStyleName)
{
	int i,j;
	CString StrBuf="";
	VARIANT varString;
	CTime t1=CTime::GetCurrentTime();
	bool blnRead=false;
	///////////////////////////////////////////////////////////////////////
	//載入設定檔
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)
	{
		////////////////////////////////////////////////////////////////////////
		//pDoc->load("SignageConfig.xml");
		MSXML2::IXMLDOMNodePtr pNodeRoot;
		MSXML2::IXMLDOMNodeListPtr  pNodeList;
		MSXML2::IXMLDOMNodePtr   pNode;
 		MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap=NULL;
		MSXML2::IXMLDOMNodePtr   pAttrItem;
		MSXML2::IXMLDOMNodePtr   pAttrItem_0;
		_variant_t variantValue_0;
		_variant_t variantValue;
		//在樹中查找名為Book的節點,"//"表示在任意一層查找 
		////////////////////////////////////////////////////
		//找尋節點
		pNodeRoot=pDoc->selectSingleNode("//startPrograms");
		pNodeRoot->get_childNodes(&pNodeList);
		j=pNodeList->length;
		/////////////////////////////////////////////////////
		//依序取出各子節點值，修改確認
		for(i=0;i<j;i++)
		{
			CString StrData;
			pNode=pNodeList->item[i];
			pNode->get_attributes(&pAttrMap);
			pAttrMap->get_item(0,&pAttrItem_0);
			//pAttrMap->get_item(1,&pAttrItem);
			//取得節點的值
			pAttrItem_0->get_nodeTypedValue(&variantValue_0);
			//pAttrItem->get_nodeTypedValue(&variantValue);
			StrBuf=(char *)pNode->GetnodeName();;
			StrData=(char *)(_bstr_t)variantValue_0;
			if(StrBuf==StrStyleName)
			{
				StrData="true";
			}
			else
			{
				StrData="false";
			}
			variantValue=(_bstr_t)StrData;
			pAttrItem->put_nodeTypedValue(variantValue);
		}
		//////////////////////////////////////////////////////
		//第11.0版的功能
		if(gblnLogFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlLog2,"%s,0,ChangeStyle->%s\n",strTime.GetBuffer(0),StrStyleName.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,0,ChangeStyle->%s\r\n",strTime.GetBuffer(0),StrStyleName.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlLog1,"%s,0,ChangeStyle->%s\n",strTime.GetBuffer(0),StrStyleName.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,0,ChangeStyle->%s\r\n",strTime.GetBuffer(0),StrStyleName.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
		//////////////////////////////////////////////////////
		//儲存修改
		varString.bstrVal = strFileName1.AllocSysString ();
		pDoc->save(varString);
	}
	else
	{
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H:%M:%S");
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}

void CCute_Main_ControlDlg::OnlyControlMovie(bool blnflag)
{
	CWnd* hWnd0;
	CString StrName,StrCaption;
	int i;
	if(blnflag)//開啟
	{
		//////////////////////////////////////////////////////////
		//依序取出程式名稱和標題，並判斷frmPlayer是否友執行，若無執行則執行
		for(i=0;i<gintProgramNumber;i++)
		{
			StrName=gstructPD[i].StrName+".exe"; 
			StrCaption=gstructPD[i].StrCaption;
			if(StrCaption=="frmPlayer")
			{
				hWnd0=NULL;
				hWnd0 = FindWindow(NULL, StrCaption.GetBuffer(0));
				if(hWnd0==NULL)
					ShellExecute(NULL,"open",StrName.GetBuffer(0),NULL,NULL,SW_SHOWNORMAL);
				break;
			}
		}
		//////////////////////////////////////////////////////////////////////////////////
	}
	else//關閉
	{
		///////////////////////////////////////////////////////////////////
		//依序取出程式名稱和標題，並判斷是否友執行，若有執行則關閉
		for(i=0;i<gintProgramNumber;i++)
		{
			StrCaption=gstructPD[i].StrCaption;
			if(StrCaption=="frmPlayer")
			{
				hWnd0=NULL;
				hWnd0= FindWindow(NULL,StrCaption.GetBuffer(0));
				if(hWnd0!=NULL)
					hWnd0->SendMessage(WM_CLOSE,0,0);
				break;
			}
		}
		//////////////////////////////////////////////////////////////////////
	}
}

void CCute_Main_ControlDlg::GetMonitorPicture()
{
	CDibSection dib1;
	CDC dc1;
	CString strFileName1;
	CString strFileName2;
	CString strFileName3;
	CString Strbuf;
	/////////////////////////////////////////////////////////////////////////
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	/////////////////////////////////////////////////////////////////////////
	strFileName1=gstrCurDrt;
	strFileName2=gstrCurDrt;
	strFileName1+="Resources\\Export_Data\\NowMonitorPicture.bmp";
	strFileName2+="Resources\\Export_Data\\";
	/////////////////////////////////////////////////////////////////////////
	dc1.CreateDC ("DISPLAY",NULL,NULL,NULL);
	int Width=GetSystemMetrics(SM_CXSCREEN);
	int Height=GetSystemMetrics(SM_CYSCREEN);
	dib1.Create(Width,Height,24);
	BitBlt(CDibDC(dib1), 0, 0, Width, Width, dc1, 0, 0, SRCCOPY);
	dib1.SaveBmp(strFileName1.GetBuffer(0));
	///////////////////////////////////////////////////////////////////////////
	m_JPG.SetBmpFile(strFileName1.GetBuffer(0));
	m_JPG.SetQuality((long)95);
	CTime t1=CTime::GetCurrentTime();
	//strFileName3.Format("%d%d%d%d%d%d.jpg",t1.GetYear(),t1.GetMonth(),t1.GetDay(),t1.GetHour(),t1.GetMinute(),t1.GetSecond());
	strFileName3.Format("%d",t1.GetYear());
	///////////////////////////////////////////////////////////////////////////
	Strbuf="";
	if(t1.GetMonth()<10)
	{
		Strbuf.Format("0%d",t1.GetMonth()); 
	}
	else
	{
		Strbuf.Format("%d",t1.GetMonth());
	}
	strFileName3+=Strbuf;
	///////////////////////////////////////
	Strbuf="";
	if(t1.GetDay()<10)
	{
		Strbuf.Format("0%d",t1.GetDay()); 
	}
	else
	{
		Strbuf.Format("%d",t1.GetDay());
	}
	strFileName3+=Strbuf;
	///////////////////////////////////////
	Strbuf="";
	if(t1.GetHour()<10)
	{
		Strbuf.Format("0%d",t1.GetHour()); 
	}
	else
	{
		Strbuf.Format("%d",t1.GetHour());
	}
	strFileName3+=Strbuf;
	///////////////////////////////////////
	Strbuf="";
	if(t1.GetMinute()<10)
	{
		Strbuf.Format("0%d",t1.GetMinute()); 
	}
	else
	{
		Strbuf.Format("%d",t1.GetMinute());
	}
	strFileName3+=Strbuf;
	///////////////////////////////////////
	Strbuf="";
	if(t1.GetSecond()<10)
	{
		Strbuf.Format("0%d",t1.GetSecond()); 
	}
	else
	{
		Strbuf.Format("%d",t1.GetSecond());
	}
	strFileName3+=Strbuf;
	////////////////////////////////////////////////////////////////////////////
	strFileName2+=strFileName3;
	strFileName2+=".jpg";
	m_JPG.BmpToJPG(strFileName2.GetBuffer(0));	
	//////////////////////////////////////////////////////////////////////////////
}

void CCute_Main_ControlDlg::GetSpeciallyDay()
{
	int i,j;
	CString StrBuf="";
	gintSpdayCount=0;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	bool blnRead=false;
	///////////////////////////////////////////////////////////////////
	//變數初始化
	for(i=0;i<Spday_Max;i++)
	{
		gStrSpday[i]="";
	}
	//////////////////////////////////////////////////////////////////
	//載入設定檔
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)
	{
		/////////////////////////////////////////////////////////////////////
		MSXML2::IXMLDOMNodePtr pNodeRoot;
		MSXML2::IXMLDOMNodeListPtr  pNodeList;
		MSXML2::IXMLDOMNodePtr   pNode;
		_variant_t vtStr;
		/////////////////////////////////////////////////////////////////////
		pNodeRoot=pDoc->selectSingleNode("//spday");
		pNodeRoot->get_childNodes(&pNodeList);
		j=pNodeList->length;
		gintSpdayCount=j;
		////////////////////////////////////////////////////////
		//依序取出子節點的值
		for(i=0;i<j;i++)
		{
			CString StrData;
			pNode=pNodeList->item[i];
			pNode->get_nodeTypedValue(&vtStr);  
			gStrSpday[i]=vtStr.bstrVal;
		}
	}
	else
	{
		//第11.0版的功能
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}

void CCute_Main_ControlDlg::CreateCommunication()
{
	HINSTANCE result;
	CWnd* hWnd0;
	CString StrVersion;
	CTime t1=CTime::GetCurrentTime();
	CString StrCaption,StrName;
	StrCaption=gstructPD[0].StrCaption;
	StrName=gstructPD[0].StrName+".exe"; 
	hWnd0 = FindWindow(NULL,StrCaption.GetBuffer(0));
	if(hWnd0==NULL)
	{
		result=ShellExecute(NULL,"open",StrName.GetBuffer(0),NULL,NULL,SW_SHOWNORMAL);
		if((int)result>32)//第11.0版的功能
		{
			StrVersion="";//第13.7版->查詢程式版本
			StrVersion=GetProgramVersion(StrName);//第13.7版->查詢程式版本
			if(gblnLogFlag==true)
			{
				CString strTime = t1.Format("%H%M%S"); 
				if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
				{
					//fprintf(gpfControlLog2,"%s,9,Start program OK->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,9,Start program OK->%s %s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0),StrVersion.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
					//delete [] gpUnicodeDataBuf;//釋放記憶體
					//gpUnicodeDataBuf=NULL;//釋放記憶體
				}
				else
				{
					//fprintf(gpfControlLog1,"%s,9,Start program OK->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,9,Start program OK->%s %s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0),StrVersion.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
					//delete [] gpUnicodeDataBuf;//釋放記憶體
					//gpUnicodeDataBuf=NULL;//釋放記憶體
				}
			}
		}
		else
		{
			if(gblnErrFlag==true)
			{
				CString strTime = t1.Format("%H%M%S"); 
				if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
				{
					//fprintf(gpfControlError2,"%s,9,Not Create program->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,9,Not Create program->%s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
					gblnGetError=true;//第13.2版
					//delete [] gpUnicodeDataBuf;//釋放記憶體
					//gpUnicodeDataBuf=NULL;//釋放記憶體
				}
				else
				{
					//fprintf(gpfControlError1,"%s,9,Not Create program->%s\n",strTime.GetBuffer(0),StrName.GetBuffer(0));
					//第12.8版->Unicode
					gStr2UnicodeData.Format("%s,9,Not Create program->%s\r\n",strTime.GetBuffer(0),StrName.GetBuffer(0));//產生要寫入資料 
					gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
					////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
					MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
					fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
					gblnGetError=true;//第13.2版
					//delete [] gpUnicodeDataBuf;//釋放記憶體
					//gpUnicodeDataBuf=NULL;//釋放記憶體
				}
			}
		}
	}
}
void CCute_Main_ControlDlg::CreateLogFile()//開啟紀錄資訊功能//第11.0版的功能
{
	CString strFileName1;
	CString StrVersion;
	CString StrMeName;
	CString StrControlFileName;
	CString StrNowday;
	CString StrDayBuf;
	CString StrMonthBuf;
	CString DeleteFileName;////第13.2版
	gunicode[0] = 0xFF;//第12.8版->Unicode   
	gunicode[1] = 0xFE;//第12.8版->Unicode 
	///////////////////////////////////////////////////////////////////////////
	//取得目前系統時間
	CTime t1=CTime::GetCurrentTime();
	int Year=t1.GetYear();//年 
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	/////////////////////////////////
	StrNowday.Format("%d",Year);
	if(Month<10)
	{
		StrMonthBuf.Format("0%d",Month); 
	}
	else
	{
		StrMonthBuf.Format("%d",Month);
	}
	if(Day<10)
	{
		StrDayBuf.Format("0%d",Day); 
	}
	else
	{
		StrDayBuf.Format("%d",Day);
	}
	StrNowday=StrNowday+StrMonthBuf+StrDayBuf;
	GetCreateFileFlag();//第11.4版的功能
	//////////////////////////////////////////////////
	//第11.0版的功能
	//開啟記錄檔
	if(gblnLogFlag==true||gblnErrFlag==true)
	{
		if(gStrYesterday!=StrNowday)
		{
			int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
			if( gstrCurDrt[nLen]!='\\' )
			{
				gstrCurDrt[nLen++] = '\\';
				gstrCurDrt[nLen] = '\0';
			}
			StrMeName = gstrCurDrt;
			StrMeName +="Cute_Main_Control.exe";
			StrVersion="";//第13.7版->查詢程式版本
			StrVersion=GetProgramVersion(StrMeName);//第13.7版->查詢程式版本
			strFileName1 = gstrCurDrt;
			strFileName1 +="Resources\\Export_Data\\Main\\";
			if(gblnControlErrorLog==false)
			{
				//0
				StrControlFileName=strFileName1;
				StrControlFileName+=StrNowday+"err";
				StrControlFileName+=".log";
				gpfControlError1=fopen(StrControlFileName.GetBuffer(0),"wb"); 
				fwrite(gunicode,sizeof(char),2,gpfControlError1);
				fwrite(gpUnicode,sizeof(WCHAR),lstrlenW(gpUnicode),gpfControlError1);
				if(gpfControlError2!=NULL)
				{
					fclose(gpfControlError2);
					gpfControlError2=NULL;
					if(gblnGetError!=true)
					{
						DeleteFileName=strFileName1;
						DeleteFileName+=gStrYesterday+"err";
						DeleteFileName+=".log";
						DeleteFile(DeleteFileName);
					}
				}
				StrControlFileName=strFileName1;
				StrControlFileName+=StrNowday+"run";
				StrControlFileName+=".log";
				gpfControlLog1=fopen(StrControlFileName.GetBuffer(0),"wb");
				fwrite(gunicode,sizeof(char),2,gpfControlLog1);//第12.8版->Unicode
				fwrite(gpUnicode,sizeof(WCHAR),lstrlenW(gpUnicode),gpfControlLog1);
				CString strTime = t1.Format("%H%M%S"); 
				//fprintf(gpfControlLog1,"%s,0,Start time\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,0,Start time %s\r\n",strTime.GetBuffer(0),StrVersion.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog1);//寫檔
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
				if(gpfControlLog2!=NULL)
				{
					fclose(gpfControlLog2);
					gpfControlLog2=NULL;
				}
			}
			else
			{
				//1
				StrControlFileName=strFileName1;
				StrControlFileName+=StrNowday+"err";
				StrControlFileName+=".log";
				gpfControlError2=fopen(StrControlFileName.GetBuffer(0),"wb");
				fwrite(gunicode,sizeof(char),2,gpfControlError2);
				fwrite(gpUnicode,sizeof(WCHAR),lstrlenW(gpUnicode),gpfControlError2);
				if(gpfControlError1!=NULL)
				{
					fclose(gpfControlError1);
					gpfControlError1=NULL;
					if(gblnGetError!=true)
					{
						DeleteFileName=strFileName1;
						DeleteFileName+=gStrYesterday+"err";
						DeleteFileName+=".log";
						DeleteFile(DeleteFileName);
					}
				}
				StrControlFileName=strFileName1;
				StrControlFileName+=StrNowday+"run";
				StrControlFileName+=".log";
				gpfControlLog2=fopen(StrControlFileName.GetBuffer(0),"wb");
				fwrite(gunicode,sizeof(char),2,gpfControlLog2);//第12.8版->Unicode
				fwrite(gpUnicode,sizeof(WCHAR),lstrlenW(gpUnicode),gpfControlLog2);
				CString strTime = t1.Format("%H%M%S"); 
				//fprintf(gpfControlLog2,"%s,0,Start time\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,0,Start time %s\r\n",strTime.GetBuffer(0),StrVersion.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlLog2);//寫檔
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
				if(gpfControlLog1!=NULL)
				{
					fclose(gpfControlLog1);
					gpfControlLog1=NULL;
				}
			}
			gStrYesterday=StrNowday;
			gblnControlErrorLog=!gblnControlErrorLog;
		}
	}
	/////////////////////////////////
}
void CCute_Main_ControlDlg::Stop_ALL()
{
	CWnd* hWnd[PDData_Max];
	int i;
	CString StrCaption;
	///////////////////////////////////////////////////////////////////
	//依序取出程式名稱和標題，並判斷是否友執行，若有執行則關閉
	for(i=0;i<gintProgramNumber;i++)
	{
		StrCaption=gstructPD[i].StrCaption;
		hWnd[i]= FindWindow(NULL,StrCaption.GetBuffer(0));
		if(hWnd[i]!=NULL)
			hWnd[i]->SendMessage(WM_CLOSE,0,0);
	}
	//////////////////////////////////////////////////////////////////////
}
void CCute_Main_ControlDlg::GetCreateFileFlag()//讀取是否建立記錄檔案旗標
{
	int i,j;
	CString StrBuf="";
	MSXML2::IXMLDOMDocumentPtr pDoc;
	gblnLogFlag=false;//第11.4版的功能
	gblnErrFlag=false;//第11.4版的功能
	CTime t1=CTime::GetCurrentTime();
	bool blnRead=false;
	//載入設定檔
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	///////////////////////////////////////////////////////////////
	if(blnRead)
	{
		//pDoc->load("SignageConfig.xml");
		MSXML2::IXMLDOMNodePtr pNodeRoot;
		MSXML2::IXMLDOMNodeListPtr  pNodeList;
		MSXML2::IXMLDOMNodePtr   pNode;
 		MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap=NULL;
		MSXML2::IXMLDOMNodePtr   pAttrItem;
		MSXML2::IXMLDOMNodePtr   pAttrItem_0;
		_variant_t vtStr;
		CString StrData,StrBuf;
		//在樹中查找名為Book的節點,"//"表示在任意一層查找
		///////////////////////////////////////////////////////
		//找尋程式資料標籤
		pNodeRoot=pDoc->selectSingleNode("//report");
		pNodeRoot->get_childNodes(&pNodeList);
		j=pNodeList->length;
		////////////////////////////////////////////////////////
		//依序取出子節點
		for(i=0;i<j;i++)
		{
			pNode=pNodeList->item[i];
			StrBuf=(char *)pNode->GetnodeName();;
			if(StrBuf=="errorlog")
			{
				pNode->get_nodeTypedValue(&vtStr); 
				StrBuf=vtStr.bstrVal;
				StrBuf.MakeLower();//第13.2版->防呆全部轉小寫
				if(StrBuf=="true")
				{
					gblnErrFlag=true;//第11.4版的功能
				}
				else
				{
					gblnErrFlag=false;//第11.4版的功能
				}
			}
			if(StrBuf=="playbacklog")
			{
				pNode->get_nodeTypedValue(&vtStr); 
				StrBuf=vtStr.bstrVal;
				StrBuf.MakeLower();//第13.2版->防呆全部轉小寫
				if(StrBuf=="true")
				{
					gblnLogFlag=true;//第11.4版的功能
				}
				else
				{
					gblnLogFlag=false;//第11.4版的功能
				}
			}
			///////////////////////////////////////////////////////////////////
		}
		///////////////////////////////////////////////////////////////////////
	}
	else
	{
		//第11.0版的功能
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}
void CCute_Main_ControlDlg::BoBoProgramZindex(int p[PDData_Max][2],long n)
{
	long i,j,key;
	int temp,temp1;
	for(i=0;i<n;i++)
	{
		key=0;
		for(j=0;j<(n-i-1);j++)
		{
			if(p[j][1]>p[j+1][1])
			{
				temp1=p[j][1];
				p[j][1]=p[j+1][1];
				p[j+1][1]=temp1;
				///////////////////////////////
				temp=p[j][0];
				p[j][0]=p[j+1][0];
				p[j+1][0]=temp;
				key=1;
			}
		}
		if(key==0)
			break;
	}
}
void CCute_Main_ControlDlg::SetSystemVolume( const DWORD dwVolume )//設定系統音量//第12.5版->系統音量設定
{
    MMRESULT                        result;
    HMIXER                          hMixer;
    MIXERLINE                       ml   = {0};
    MIXERLINECONTROLS               mlc  = {0};
    MIXERCONTROL                    mc   = {0};
    MIXERCONTROLDETAILS             mcd  = {0};
    MIXERCONTROLDETAILS_UNSIGNED    mcdu = {0};


    // get a handle to the mixer device
    result = mixerOpen(&hMixer, MIXER_OBJECTF_MIXER, 0, 0, 0);
    if (MMSYSERR_NOERROR == result)
    {
        ml.cbStruct        = sizeof(MIXERLINE);
        ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;

        // get the speaker line of the mixer device
        result = mixerGetLineInfo((HMIXEROBJ) hMixer, &ml, MIXER_GETLINEINFOF_COMPONENTTYPE);
        if (MMSYSERR_NOERROR == result)
        {
            mlc.cbStruct      = sizeof(MIXERLINECONTROLS);
            mlc.dwLineID      = ml.dwLineID;
            mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
            mlc.cControls     = 1;
            mlc.pamxctrl      = &mc;
            mlc.cbmxctrl      = sizeof(MIXERCONTROL);

            // get the volume controls associated with the speaker line
            result = mixerGetLineControls((HMIXEROBJ) hMixer, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
            if (MMSYSERR_NOERROR == result)
            {
                mcdu.dwValue    = dwVolume;

                mcd.cbStruct    = sizeof(MIXERCONTROLDETAILS);
                mcd.hwndOwner   = 0;
                mcd.dwControlID = mc.dwControlID;
                mcd.paDetails   = &mcdu;
                mcd.cbDetails   = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
                mcd.cChannels   = 1;

                // set the volume
                result = mixerSetControlDetails((HMIXEROBJ) hMixer, &mcd, MIXER_SETCONTROLDETAILSF_VALUE);
                //if (MMSYSERR_NOERROR == result)
                    //AfxMessageBox("Volume changed!");
                //else
                    //AfxMessageBox("mixerSetControlDetails() failed");
            }
            //else
                //AfxMessageBox("mixerGetLineControls() failed");
        }
        //else
            //AfxMessageBox("mixerGetLineInfo() failed");
    
        mixerClose(hMixer);
    }
    //else
        //AfxMessageBox("mixerOpen() failed");
}

DWORD CCute_Main_ControlDlg::GetSystemVolume( void )//取得系統音量//第12.5版->系統音量設定
{
    DWORD                           dwVolume = -1;
    MMRESULT                        result;
    HMIXER                          hMixer;
    MIXERLINE                       ml   = {0};
    MIXERLINECONTROLS               mlc  = {0};
    MIXERCONTROL                    mc   = {0};
    MIXERCONTROLDETAILS             mcd  = {0};
    MIXERCONTROLDETAILS_UNSIGNED    mcdu = {0};


    // get a handle to the mixer device
    result = mixerOpen(&hMixer, 0, 0, 0, MIXER_OBJECTF_HMIXER);
    if (MMSYSERR_NOERROR == result)
    {
        ml.cbStruct        = sizeof(MIXERLINE);
        ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;

        // get the speaker line of the mixer device
        result = mixerGetLineInfo((HMIXEROBJ) hMixer, &ml, MIXER_GETLINEINFOF_COMPONENTTYPE);
        if (MMSYSERR_NOERROR == result)
        {
            mlc.cbStruct      = sizeof(MIXERLINECONTROLS);
            mlc.dwLineID      = ml.dwLineID;
            mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
            mlc.cControls     = 1;
            mlc.pamxctrl      = &mc;
            mlc.cbmxctrl      = sizeof(MIXERCONTROL);

            // get the volume controls associated with the speaker line
            result = mixerGetLineControls((HMIXEROBJ) hMixer, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
            if (MMSYSERR_NOERROR == result)
            {
                mcd.cbStruct    = sizeof(MIXERCONTROLDETAILS);
                mcd.hwndOwner   = 0;
                mcd.dwControlID = mc.dwControlID;
                mcd.paDetails   = &mcdu;
                mcd.cbDetails   = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
                mcd.cChannels   = 1;

                // get the volume
                result = mixerGetControlDetails((HMIXEROBJ) hMixer, &mcd, MIXER_SETCONTROLDETAILSF_VALUE);
                if (MMSYSERR_NOERROR == result)
                    dwVolume = mcdu.dwValue;
                else
                    AfxMessageBox("mixerGetControlDetails() failed");
            }
            else
                AfxMessageBox("mixerGetLineControls() failed");
        }
        else
            AfxMessageBox("mixerGetLineInfo() failed");
    
        mixerClose(hMixer);
    }
    else
        AfxMessageBox("mixerOpen() failed");

    return (dwVolume);
}
void CCute_Main_ControlDlg::SetVolume()////第12.5版->讀取音量設定值並修改系統值
{
	bool blnRead=false;
	CTime t1=CTime::GetCurrentTime();
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	//pDoc->load("SignageConfig.xml");
	if(blnRead)
	{
		MSXML2::IXMLDOMNodeListPtr  pNodeList;
		MSXML2::IXMLDOMNodePtr  pNode;
		_variant_t vtStr;
		CString StrBuf;
		int intVolume;
		int intSetValue;
		int l;
		//在樹中查找名為Book的節點,"//"表示在任意一層查找 
		pNodeList=pDoc->selectNodes("//volume");
		l=pNodeList->length;
		if(pNodeList!=NULL)
		{
			pNode=pNodeList->item[(l-1)];
			pNode->get_nodeTypedValue(&vtStr); 
			StrBuf=vtStr.bstrVal;
			intVolume=atoi(StrBuf.GetBuffer(0));
			intSetValue=65535*intVolume/100;
			SetSystemVolume(intSetValue);
		}
	}
	else
	{
		//第11.0版的功能
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				//delete [] gpUnicodeDataBuf;//釋放記憶體
				//gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}
void CCute_Main_ControlDlg::SwitchMonitor()//第12.7版->送CTRL+ALT+F9使新的STBㄧ定要選監視器輸出
{
	char cha;
	cha=18;//Alt
	//VK_CONTROL;
	//cha;
	//VK_F9;
	keybd_event(VK_CONTROL, 0, 0 ,0);
	keybd_event(cha, 0, 0 ,0);
	keybd_event(VK_F9, 0, 0 ,0);
	Sleep(1000);
	keybd_event(VK_F9, 0, KEYEVENTF_KEYUP ,0);
	keybd_event(cha, 0, KEYEVENTF_KEYUP ,0);
	keybd_event(VK_CONTROL, 0, KEYEVENTF_KEYUP ,0);
}
void CCute_Main_ControlDlg::ChangMonitorSize()//第12.8版->擷取與設定螢幕解析度
{
	gintMonitorWidthPixels=0;
	gintMonitorHeightPixels=0;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	bool blnRead=false;
	CString strValue;
	//int intHr,intMin;
	char chrDataBuf[1000];
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Resources\\Setting\\SignageConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
		MSXML2::IXMLDOMNodePtr   pNode;
		MSXML2::IXMLDOMDocumentPtr   pxmldom1;
		MSXML2::IXMLDOMNodePtr   pNode1;
		_bstr_t bt1;
		_variant_t vtStr;
		CString StrValue;
		char chrDataBuf[1000];
		DEVMODE lpDevMode;
		////////////////////////////////////////////
		pNode=pDoc->selectSingleNode("//Monitor");
		bt1=pNode->Getxml();
		////////////////////////////////////////////
		hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
		pxmldom1->loadXML(bt1);
		////////////////////////////////////////////////////////////////
		pNode1=pxmldom1->selectSingleNode("//size");
		pNode1->get_nodeTypedValue(&vtStr);  
		StrValue=vtStr.bstrVal;
		strcpy(chrDataBuf,StrValue.GetBuffer(0));
		sscanf(chrDataBuf,"%dx%d",&gintMonitorWidthPixels,&gintMonitorHeightPixels);
		/////////////////////////////////////////////////////////////////////////////
		lpDevMode.dmBitsPerPel = 32;
		lpDevMode.dmPelsWidth = gintMonitorWidthPixels;
		lpDevMode.dmPelsHeight = gintMonitorHeightPixels;
		lpDevMode.dmSize = sizeof(lpDevMode);
		lpDevMode.dmFields = DM_PELSWIDTH|DM_PELSHEIGHT|DM_BITSPERPEL;
		LONG result = ChangeDisplaySettings(&lpDevMode,0);
		if(result == DISP_CHANGE_SUCCESSFUL)
		{
			ChangeDisplaySettings(&lpDevMode,CDS_UPDATEREGISTRY);
			//使用CDS_UPDATEREGISTRY表示次修改是持久的,
			//並在註冊表中寫入了相關的資料 
		}
		else
		{
			ChangeDisplaySettings(NULL,0);
		}
	}
	else//第11.0版的功能
	{
		if(gblnErrFlag==true)
		{
			CString strTime = t1.Format("%H%M%S"); 
			if(!gblnControlErrorLog)//0檔案1，1檔案2 ->ps 一定要取反向因為當開啟檔案時已改變狀態
			{
				//fprintf(gpfControlError2,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError2);//寫檔
				gblnGetError=true;//第13.2版
				////delete [] gpUnicodeDataBuf;//釋放記憶體
				////gpUnicodeDataBuf=NULL;//釋放記憶體
			}
			else
			{
				//fprintf(gpfControlError1,"%s,9,Not Find XML\n",strTime.GetBuffer(0));
				//第12.8版->Unicode
				gStr2UnicodeData.Format("%s,9,Not Find XML\r\n",strTime.GetBuffer(0));//產生要寫入資料 
				gintUnicodeDataLen=gStr2UnicodeData.GetLength();//計算資料長度
				//////////////gpUnicodeDataBuf= new WCHAR[gintUnicodeDataLen];//產生動態配置記憶體
				MultiByteToWideChar(CP_ACP, 0,gStr2UnicodeData.GetBuffer(0),-1,gpUnicodeDataBuf,gStr2UnicodeData.GetLength());//ANSI轉換UNICODE
				fwrite(gpUnicodeDataBuf,sizeof(WCHAR),gStr2UnicodeData.GetLength(),gpfControlError1);//寫檔
				gblnGetError=true;//第13.2版
				////delete [] gpUnicodeDataBuf;//釋放記憶體
				////gpUnicodeDataBuf=NULL;//釋放記憶體
			}
		}
	}
}

void CCute_Main_ControlDlg::BrowseUpdateProgram(CString strDir)//第13.3版->搜尋更新程式數量與紀錄
{
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	CString StrData;
	BOOL res = ff.FindFile(szDir);
	
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			BrowseUpdateProgram(ff.GetFilePath());
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			gintUpdateProgramCount++;
			StrData=ff.GetFilePath();
			fprintf(gpfUpdateProgram,"%s\n",StrData.GetBuffer(0));
			StrData=ff.GetFileName();
			fprintf(gpfUpdateProgram,"%s\n",StrData.GetBuffer(0));
		}
	}
	ff.Close();
}
CString CCute_Main_ControlDlg::GetProgramVersion(CString StrDir)//第13.7版->查詢程式版本
{
	CString StrOutPut;
	DWORD dwDummy; 
	DWORD dwFVISize = GetFileVersionInfoSize(StrDir.GetBuffer(0),&dwDummy); 
	LPBYTE lpVersionInfo = new BYTE[dwFVISize]; 
	GetFileVersionInfo(StrDir.GetBuffer(0),0,dwFVISize,lpVersionInfo); 
	UINT uLen; 
	VS_FIXEDFILEINFO *lpFfi; 
	VerQueryValue( lpVersionInfo , _T("\\") , (LPVOID *)&lpFfi , &uLen ); 
	DWORD dwFileVersionMS = lpFfi->dwFileVersionMS; 
	DWORD dwFileVersionLS = lpFfi->dwFileVersionLS; 
	delete [] lpVersionInfo; 
	DWORD dwLeftMost = HIWORD(dwFileVersionMS); 
	DWORD dwSecondLeft = LOWORD(dwFileVersionMS); 
	DWORD dwSecondRight = HIWORD(dwFileVersionLS); 
	DWORD dwRightMost = LOWORD(dwFileVersionLS);
	StrOutPut="";
	StrOutPut.Format("Version: %d.%d.%d.%d" ,dwLeftMost,dwSecondLeft,dwSecondRight,dwRightMost);
	return StrOutPut; 
}
void CCute_Main_ControlDlg::Reset_Computer()//第13.8版
{
	CString data;
	data=" -f -r -t 0 ";
	ShellExecute(NULL,"open","C:\\WINDOWS\\system32\\shutdown.exe",data.GetBuffer(0),NULL,SW_SHOW);	
}