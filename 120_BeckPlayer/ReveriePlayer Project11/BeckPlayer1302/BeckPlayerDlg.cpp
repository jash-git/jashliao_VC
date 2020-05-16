// BeckPlayerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BeckPlayer.h"
#include "BeckPlayerDlg.h"
///////////////////////////////
#include "wmpcontrols.h"
#include "wmpmedia.h"
#include "wmpplaylist.h"
///////////////////////////////

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
int gintStep;
bool blnopenRS485;
bool blnInit;
bool blnTimer;
bool gblnclose;
bool gblnHook;
/////////////////////////////////////////////////////////////////////////////
#define ON_0 WM_USER + 500
#define ON_1 WM_USER + 501
#define ON_2 WM_USER + 502
#define ON_3 WM_USER + 503 
#define ON_4 WM_USER + 504 
#define ON_5 WM_USER + 505 
#define ON_6 WM_USER + 506 
#define ON_7 WM_USER + 507 
#define ON_8 WM_USER + 508 
#define ON_9 WM_USER + 509
HINSTANCE hInstLibrary;
typedef void (*SetKeyboardHook)();
typedef void (*ReleaseKeyboardHook)();
SetKeyboardHook _SetKeyboardHook;
ReleaseKeyboardHook _ReleaseKeyboardHook;
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
// CBeckPlayerDlg dialog

CBeckPlayerDlg::CBeckPlayerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBeckPlayerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBeckPlayerDlg)
	m_V1 = _T("");
	m_V2 = _T("");
	m_V3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBeckPlayerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBeckPlayerDlg)
	DDX_Control(pDX, IDC_OCX1, m_Player);
	DDX_Text(pDX, IDC_EDIT1, m_V1);
	DDX_Text(pDX, IDC_EDIT2, m_V2);
	DDX_Text(pDX, IDC_EDIT3, m_V3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CBeckPlayerDlg, CDialog)
	//{{AFX_MSG_MAP(CBeckPlayerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	ON_MESSAGE(ON_0,On_CtrlR)
	ON_MESSAGE(ON_1,On_CtrlO)
	ON_MESSAGE(ON_2,On_CtrlH)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBeckPlayerDlg message handlers

BOOL CBeckPlayerDlg::OnInitDialog()
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
	InitialVariable();
	/////////////////////////////////////////////////////////////////////////////	
	ModifyStyle(0, WS_SYSMENU);
	SetWindowPos(&CWnd::wndTopMost,m_lngLeft,m_lngTop,m_lngWidth,m_lngHeight,SWP_SHOWWINDOW);
	this->MoveWindow(m_lngLeft,m_lngTop,m_lngWidth,m_lngHeight,TRUE);
	RECT rc;
	this->GetClientRect(&rc);
	m_Player.MoveWindow( &rc, true );
	/////////////////////////////////////////////////////
	this->SetWindowText("ReveriePlayer");
	///////////////////////////////////////////////////////////////////
	hInstLibrary = LoadLibrary("KeybHook.dll");
	if (hInstLibrary == NULL)
	{
		FreeLibrary(hInstLibrary);
	}
	_SetKeyboardHook = (SetKeyboardHook)GetProcAddress(hInstLibrary, "SetKeyboardHook");
	_ReleaseKeyboardHook = (ReleaseKeyboardHook)GetProcAddress(hInstLibrary, "ReleaseKeyboardHook");
	if ((_SetKeyboardHook == NULL) || (_ReleaseKeyboardHook == NULL))
	{
		FreeLibrary(hInstLibrary);
		gblnHook=false;
		MessageBox("No Hook Control...");
		ShellExecute(NULL,"open","ReveriePlayer.exe",NULL,NULL,SW_SHOW);
		this->OnOK();
	}
	else
	{
		gblnHook=true;
	}
	_SetKeyboardHook();
	///////////////////////////////////////////////////////////////////
	CString Strfilename;
	Strfilename=m_StrTitelVideo;
	//newMedia1=m_Player.newMedia(Strfilename);
	//curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	//m_Player.SetCurrentPlaylist(curPlaylist);
	m_Player.SetUrl(Strfilename);
	m_Player.GetControls().play();
	SetTimer(2,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBeckPlayerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CBeckPlayerDlg::OnPaint() 
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
HCURSOR CBeckPlayerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CBeckPlayerDlg::timer01()
{
	float flttime=0;
	int i;
	KillTimer(1);
	blnTimer=false;
	i=ShowCursor(FALSE);
	UpdateData(true);
		if(!blnInit)
		{
			SetWindowPos(&CWnd::wndTopMost,m_lngLeft,m_lngTop,m_lngWidth,m_lngHeight,SWP_SHOWWINDOW);
			InitRS485andBed();
			StepControl00();
			blnInit=true;
		}
		flttime=m_Player.GetControls().GetCurrentPosition();
		m_V2.Format("%f",m_Player.GetControls().GetCurrentPosition());
		m_V1.Format("%f",m_Player.GetCurrentMedia().GetDuration());
		/*
		if(flttime>50 && flttime<267)
		{
			//關閉螢幕
			::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) 2);
		}
		else
		{
			//開起螢幕
			::SendMessage(HWND_BROADCAST, WM_SYSCOMMAND, SC_MONITORPOWER, (LPARAM) -1);
		}
		*/
		 switch(gintStep)
		 {
		  case 0://TV mode
			//背景音樂
			//StepControl00();
			m_V3.Format("%d",gintStep);
			gintStep=1;
		   break;
		  case 1://TV mode->flat (foot position(0), head position(0))
			//-歡迎體驗Reverie電動床
			if(flttime>34 && flttime<35)
			{
				//StepControl00();
				m_V3.Format("%d",gintStep);
				gintStep=2;
			}
		   break;
		  case 2://foot position(71)
			//-我們即將帶您 享受最舒適的體驗之旅
			if(flttime>62 && flttime<63)
			{
				StepControl01();
				m_V3.Format("%d",gintStep);
				gintStep=3;
			}
		   break;
		  case 3://-foot vibration (6)
			//-您的腰也開始享受到舒服的按摩
			if(flttime>79 && flttime<80)
			{
				StepControl02();
				m_V3.Format("%d",gintStep);
				gintStep=4;
			}
		   break;
		  case 4://-foot vibration (10)
			//-同時，您的雙腳不再有任何緊繃感
			if(flttime>86 && flttime<87)
			{
				StepControl03();
				m_V3.Format("%d",gintStep);
				gintStep=5;
			}
		   break;
		  case 5://head position (30)
			//-現在, 您的身體即將進入  最輕鬆的零重力狀態
			if(flttime>113 && flttime<114)
			{
				StepControl04();
				m_V3.Format("%d",gintStep);
				gintStep=6;
			}
		   break;
		  case 6://-Head vibration (1)
			//-這種姿勢與背部的按摩感覺 彷彿母親輕拍您的背
				//安撫您入睡 這是一種安全感 更是一份幸福感
			if(flttime>131 && flttime<132)
			{
				StepControl05();
				m_V3.Format("%d",gintStep);
				gintStep=7;
			}
		   break;
		  case 7://-Head vibration (2)
			//-這種姿勢與背部的按摩感覺 彷彿母親輕拍您的背
				//安撫您入睡 這是一種安全感 更是一份幸福感
			if(flttime>157 && flttime<158)
			{
				StepControl06();
				m_V3.Format("%d",gintStep);
				gintStep=8;
			}
		   break;
		  case 8://-Head vibration (3)
			//-這種姿勢與背部的按摩感覺 彷彿母親輕拍您的背
				//安撫您入睡 這是一種安全感 更是一份幸福感
			if(flttime>161 && flttime<162)
			{
				StepControl07();
				m_V3.Format("%d",gintStep);
				gintStep=9;
			}
		   break;
		  case 9://-Head vibration (4)
			//-這種姿勢與背部的按摩感覺 彷彿母親輕拍您的背
				//安撫您入睡 這是一種安全感 更是一份幸福感
			if(flttime>164 && flttime<165)
			{
				StepControl08();
				m_V3.Format("%d",gintStep);
				gintStep=10;
			}
		   break;
		  case 10://-Head vibration (5)
			//-這種姿勢與背部的按摩感覺 彷彿母親輕拍您的背
				//安撫您入睡 這是一種安全感 更是一份幸福感
			if(flttime>169 && flttime<170)
			{
				StepControl09();
				m_V3.Format("%d",gintStep);
				gintStep=11;
			}
		   break;
		  case 11://-Head vibration (6)
			//-這種姿勢與背部的按摩感覺 彷彿母親輕拍您的背
				//安撫您入睡 這是一種安全感 更是一份幸福感
			if(flttime>171 && flttime<173)
			{
				StepControl10();
				m_V3.Format("%d",gintStep);
				gintStep=12;
			}
		   break;	
		  case 12://-Head vibration (7)
			//-這種姿勢與背部的按摩感覺 彷彿母親輕拍您的背
				//安撫您入睡 這是一種安全感 更是一份幸福感
			if(flttime>177 && flttime<178)
			{
				StepControl11();
				m_V3.Format("%d",gintStep);
				gintStep=13;
			}
		   break;
		  case 13://-foot position(0)
			//據統計, 現代成年人近6成都有睡覺打呼的困擾
			if(flttime>188 && flttime<189)
			{
				StepControl12();
				m_V3.Format("%d",gintStep);
				gintStep=14;
			}
		  case 14://-head position(13)
			//據統計, 現代成年人近6成都有睡覺打呼的困擾
			if(flttime>205 && flttime<206)
			{
				StepControl14();
				m_V3.Format("%d",gintStep);
				gintStep=15;
			}
		  case 15://Memory function(1)
			//-經過了一夜的舒眠，您的身體已經再次充滿能量，肌肉也可以進入戰鬥狀態
			if(flttime>214 && flttime<215)
			{
				StepControl13();
				m_V3.Format("%d",gintStep);
				gintStep=16;
			}
		   break;
		  case 16://Memory function(1)
			//-經過了一夜的舒眠，您的身體已經再次充滿能量，肌肉也可以進入戰鬥狀態
			if(flttime>283 && flttime<284)
			{
				StepControl15();
				m_V3.Format("%d",gintStep);
				gintStep=17;
			}
		   break;
		 }	
	UpdateData(false);
	if((gintStep<17))
	{
		blnTimer=true;
		SetTimer(1,50,NULL);
	}
	else
	{
		if(flttime>385)
		{
			m_Player.GetControls().stop();
			m_Player.close();
			gblnclose=true;
			//ShellExecute(NULL,"open","ReveriePlayer.exe",NULL,NULL,SW_SHOW);/*移動到On_CtrlH()*/
			//this->OnOK();/*移動到On_CtrlH()*/
		}
		else
		{
			blnTimer=true;
			SetTimer(1,50,NULL);
		}
	}
}
void CBeckPlayerDlg::timer02()
{
	long lngPlayState;
	lngPlayState=m_Player.GetPlayState();//1->STOP 2->PAUSE 3->RUN
	CString Strfilename;
	Strfilename=m_StrTitelVideo;
	switch(lngPlayState)
	{
		case 1:
			m_Player.SetUrl(Strfilename);
			m_Player.GetControls().play();
			break;
		case 2:
			m_Player.SetUrl(Strfilename);
			m_Player.GetControls().play();
			break;
	}
}
void CBeckPlayerDlg::timer03()
{
	KillTimer(3);
	CFileFind fFind;
	if(!fFind.FindFile("close.msg"))
	{
		SetTimer(3,1000,NULL);
	}
	else
	{
		m_Player.close();
		DeleteFile("close.msg");
		StepControl00();
		ShellExecute(NULL,"open","ReveriePlayer.exe",NULL,NULL,SW_SHOW);/*移動到On_CtrlH()*/
		this->OnOK();/*移動到On_CtrlH()*/
	}
}
void CBeckPlayerDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch (nIDEvent)
	{
		case 1:
			timer01();
			break;
		case 2:
			timer02();
			break;
		case 3:
			timer03();
			break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CBeckPlayerDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	int j;
	j=ShowCursor(TRUE);
	if(gblnHook)
	{
		_ReleaseKeyboardHook();
		FreeLibrary(hInstLibrary);
		gblnHook=false;
	}
	if(blnTimer)
	{
		KillTimer(1);
		blnTimer=false;
	}
	if(blnopenRS485)
	{
		RS.Close();
		blnopenRS485=false;
	}
	else
	{
		MessageBox("Close_Not Open RS485");	
	}
}
void CBeckPlayerDlg::StepControl00()
{
	char buf[3];
	//buf[0]=35;//#
	//buf[1]=71;//G
	//buf[2]=buf[0]^buf[1];//# XOR G
	//if(blnopenRS485)
	//{
	//	RS.Write(buf,3);
	//}
	//else
		//MessageBox("Not Open RS485");	
	//Sleep(1000);
	buf[0]=35;//#
	buf[1]=66;//B
	buf[2]=buf[0]^buf[1];//# XOR B
	if(blnopenRS485)
	{
		RS.Write(buf,3);
	}
	else
		MessageBox("00_Not Open RS485");
	///////////////
}	
void CBeckPlayerDlg::StepControl01()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=74;//J
	buf[2]=71;//十進位伸長量(50)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR J XOR 十進位伸長量(50)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("01_Not Open RS485");	
}
void CBeckPlayerDlg::StepControl02()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=10;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("02_Not Open RS485");	
}
void CBeckPlayerDlg::StepControl03()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=6;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("03_Not Open RS485");
}
void CBeckPlayerDlg::StepControl04()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=0;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("04_Not Open RS485");
}
void CBeckPlayerDlg::StepControl05()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=73;//I
	buf[2]=30;//十進位伸長量(50)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 十進位伸長量(50)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("05_Not Open RS485");
}
void CBeckPlayerDlg::StepControl06()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=1;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("06_Not Open RS485");
}
void CBeckPlayerDlg::StepControl07()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=3;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("07_Not Open RS485");
}
void CBeckPlayerDlg::StepControl08()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=5;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("08_Not Open RS485");
}
void CBeckPlayerDlg::StepControl09()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=7;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("09_Not Open RS485");
}
void CBeckPlayerDlg::StepControl10()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=5;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("10_Not Open RS485");
}
void CBeckPlayerDlg::StepControl11()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=3;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("11_Not Open RS485");
}
void CBeckPlayerDlg::StepControl12()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=0;//十進位振動量(9)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(9)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("12_Not Open RS485");
}
void CBeckPlayerDlg::StepControl13()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=74;//J
	buf[2]=0;//十進位伸長量(50)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR J XOR 十進位伸長量(50)
	if(blnopenRS485)
	{
		RS.Write(buf,5);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("13_Not Open RS485");
}
void CBeckPlayerDlg::StepControl14()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=73;//I
	buf[2]=7;//十進位伸長量(50)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 十進位伸長量(50)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("14_Not Open RS485");
}
void CBeckPlayerDlg::StepControl15()
{
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=01;//1->TV,2->Zero
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 1
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		char Output[50];
		long count;
		RS.Read(Output,&count);
		//MessageBox(Output);
	}
	else
		MessageBox("15_Not Open RS485");
}
void CBeckPlayerDlg::InitRS485andBed()
{
	/////////////////////////////////////////////////////
	//open RS485
	blnopenRS485=RS.OpenCom(m_intCOMPort,9600,8,0,1);
	////////////////////////////////////////////////
	/*
	//step 00
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=01;//1->TV,2->Zero
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 1
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		Sleep(1000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("init_Not Open RS485");
	*/
}
void CBeckPlayerDlg::On_CtrlR()
{
	SetTimer(3,1000,NULL);
	gblnclose=true;
	if(blnTimer)
		KillTimer(1);
	if(blnopenRS485)
		RS.Close();
	blnInit=false;
	blnTimer=false;
	KillTimer(2);
	m_Player.GetControls().stop();
	//**
	CString Strfilename;
	Strfilename=m_StrRVideo;
	//newMedia1=m_Player.newMedia(Strfilename);
	//curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	//m_Player.SetCurrentPlaylist(curPlaylist);
	m_Player.SetUrl(Strfilename);
	m_Player.GetControls().play();
	gintStep=0;
	blnTimer=true;
	SetTimer(1,50,NULL);
}
void CBeckPlayerDlg::On_CtrlO()
{
	SetTimer(3,1000,NULL);
	gblnclose=true;
	if(blnTimer)
		KillTimer(1);
	if(blnopenRS485)
		RS.Close();
	blnInit=false;
	blnTimer=false;
	KillTimer(2);
	m_Player.GetControls().stop();
	//**
	CString Strfilename;
	Strfilename=m_StrOVideo;
	//newMedia1=m_Player.newMedia(Strfilename);
	//curPlaylist.insertItem(0,newMedia1.m_lpDispatch);
	//m_Player.SetCurrentPlaylist(curPlaylist);
	m_Player.SetUrl(Strfilename);
	m_Player.GetControls().play();
	gintStep=0;
	blnTimer=true;
	SetTimer(1,50,NULL);
}
void CBeckPlayerDlg::On_CtrlH()
{
	if(gblnclose)
	{
		m_Player.GetControls().stop();
		m_Player.close();
		if(gblnHook)
		{
			_ReleaseKeyboardHook();
			FreeLibrary(hInstLibrary);
			gblnHook=false;
		}
		
		if(blnTimer)
		{
			KillTimer(1);
			blnTimer=false;
		}
		
		StepControl00();

		if(blnopenRS485)
		{
			RS.Close();
			blnopenRS485=false;
		}
		else
		{
			MessageBox("Close_Not Open RS485");	
		}
		Sleep(25000);
		ShellExecute(NULL,"open","ReveriePlayer.exe",NULL,NULL,SW_SHOW);
		this->OnOK();
	}
}
void CBeckPlayerDlg::InitialVariable(void)
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	int nLen=0;
	bool blnRead=false;
	_variant_t vtStr;
	CString StrValue;
	m_lngTop=0;m_lngLeft=0;m_lngWidth=0;m_lngHeight=0;
	m_intCOMPort=1;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	nLen= ::GetCurrentDirectory(500,m_chrCurDrt);//取得目前程式路徑
	m_StrSettingFileName+="Resources\\Config.xml";
	blnRead=pDoc->load((_bstr_t)m_StrSettingFileName);
	if(blnRead)
	{
		//////////////////////////////////////////////////
		MSXML2::IXMLDOMNodePtr Position_Size;
		Position_Size=pDoc->selectSingleNode("//Top");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngTop=_ttoi(static_cast<LPCTSTR>(StrValue)); 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Left");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngLeft=_ttoi(static_cast<LPCTSTR>(StrValue));  
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Width");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngWidth=_ttoi(static_cast<LPCTSTR>(StrValue));  
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Height");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngHeight=_ttoi(static_cast<LPCTSTR>(StrValue)); 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//COM_Port");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_intCOMPort=_ttoi(static_cast<LPCTSTR>(StrValue)); 
		//////////////////////////////////////////////////
		Position_Size=pDoc->selectSingleNode("//R_Video");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrRVideo=StrValue;
		//////////////////////////////////////////////////
		Position_Size=pDoc->selectSingleNode("//O_Video");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrOVideo=StrValue;
		//////////////////////////////////////////////////
		Position_Size=pDoc->selectSingleNode("//Title_Video");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrTitelVideo=StrValue;
	}
}