// Reverie_PC_2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Reverie_PC_2.h"
#include "Reverie_PC_2Dlg.h"
#include "vfw.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
bool blnopenRS485;
int intcount;
int intstep;
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
// CReverie_PC_2Dlg dialog

CReverie_PC_2Dlg::CReverie_PC_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReverie_PC_2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReverie_PC_2Dlg)
	m_StrState = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReverie_PC_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReverie_PC_2Dlg)
	DDX_Control(pDX, IDC_BUTNoSnore, m_ButtNoSnore);
	DDX_Control(pDX, IDC_BUTMovie, m_ButtMovie);
	DDX_Control(pDX, IDC_BUTTVMode, m_ButtTVMode);
	DDX_Control(pDX, IDC_BUTMother, m_ButtMother);
	DDX_Control(pDX, IDC_BUTMemoryFunction2, m_ButtMemoryFunction2);
	DDX_Control(pDX, IDC_BUTStopVibration, m_ButtStopVibration);
	DDX_Control(pDX, IDC_BUTFootMassage, m_ButtFootMassage);
	DDX_Control(pDX, IDC_BUTWaistMassage, m_ButtWaistMassage);
	DDX_Control(pDX, IDC_BUTFootUp, m_ButtFootUp);
	DDX_Control(pDX, IDC_BUTMusic, m_ButtMusic);
	DDX_Control(pDX, IDC_BUTAuto, m_ButtAuto);
	DDX_Control(pDX, IDC_BUTCalibrateBed, m_ButtCalibrateBed);
	DDX_Text(pDX, IDC_State, m_StrState);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReverie_PC_2Dlg, CDialog)
	//{{AFX_MSG_MAP(CReverie_PC_2Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTCalibrateBed, OnBUTCalibrateBed)
	ON_BN_CLICKED(IDC_BUTAuto, OnBUTAuto)
	ON_BN_CLICKED(IDC_BUTMusic, OnBUTMusic)
	ON_BN_CLICKED(IDC_BUTFootUp, OnBUTFootUp)
	ON_BN_CLICKED(IDC_BUTWaistMassage, OnBUTWaistMassage)
	ON_BN_CLICKED(IDC_BUTFootMassage, OnBUTFootMassage)
	ON_BN_CLICKED(IDC_BUTStopVibration, OnBUTStopVibration)
	ON_BN_CLICKED(IDC_BUTMemoryFunction2, OnBUTMemoryFunction2)
	ON_BN_CLICKED(IDC_BUTMother, OnBUTMother)
	ON_BN_CLICKED(IDC_BUTTVMode, OnBUTTVMode)
	ON_BN_CLICKED(IDC_BUTMovie, OnBUTMovie)
	ON_BN_CLICKED(IDC_BUTNoSnore, OnBUTNoSnore)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReverie_PC_2Dlg message handlers

BOOL CReverie_PC_2Dlg::OnInitDialog()
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
	m_mp3player=NULL;
	InitialVariable();
	OnOpenRS485();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReverie_PC_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReverie_PC_2Dlg::OnPaint() 
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
HCURSOR CReverie_PC_2Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CReverie_PC_2Dlg::InitialVariable(void)
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
	m_StrSettingFileName=m_chrCurDrt;
	m_StrSettingFileName+="\\Resources\\Config.xml";
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
		Position_Size=pDoc->selectSingleNode("//SHexhv_Video");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrSHexhvVideo=StrValue;
		//////////////////////////////////////////////////
		Position_Size=pDoc->selectSingleNode("//SHexha_Audio");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrSHexhaAudio=StrValue;
	}
}
void CReverie_PC_2Dlg::OnOpenRS485()
{
	// TODO: Add your control notification handler code here
	blnopenRS485=RS.OpenCom(m_intCOMPort,9600,8,0,1);
	if(!blnopenRS485)
	{
		MessageBox("Open RS485 Fail");
		this->OnOK();
	}
		
}

void CReverie_PC_2Dlg::OnDestroy() 
{
	CDialog::OnDestroy();
	if(m_mp3player !=NULL)
	{
		MCIWndStop(m_mp3player);
		MCIWndDestroy(m_mp3player);
	}
	if(blnopenRS485)
		RS.Close();		
	// TODO: Add your message handler code here
	
}

void CReverie_PC_2Dlg::OnBUTCalibrateBed() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[3];
	buf[0]=35;//#
	buf[1]=66;//B
	buf[2]=buf[0]^buf[1];//# XOR B
	if(blnopenRS485)
	{
		RS.Write(buf,3);
	}
	///////////////////////////////////////////////
	m_StrState="State : Calibrate Bed";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTAuto() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,1000,NULL);
	intcount=0;
	OnBUTMusic();
	ButtonDisable();
	intstep=1;
}

void CReverie_PC_2Dlg::OnBUTMusic() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	if(m_mp3player !=NULL)
	{
		MCIWndStop(m_mp3player);
		MCIWndDestroy(m_mp3player);
	}
	m_mp3player=NULL;
	if(m_mp3player == NULL)
	{
		m_mp3player = MCIWndCreate(this->GetSafeHwnd(),
		  AfxGetInstanceHandle(),
		  WS_CHILD | WS_VISIBLE| MCIWNDF_NOMENU| MCIWNDF_NOPLAYBAR,m_StrSHexhaAudio);
		MCIWndPlay(m_mp3player);
		
	}
	else
	{
		MCIWndHome(m_mp3player);
	}
	//////////////////////////////////
	m_StrState="State : 播放音樂";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTFootUp() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=74;//J
	buf[2]=71;//十進位伸長量(50)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR J XOR 十進位伸長量(50)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	//////////////////////////////////
	m_StrState="State : 腳抬";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTWaistMassage() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=5;//十進位振動量(5)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(10)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep(5000);
	//
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=4;//十進位振動量(5)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(10)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep(6000);
	//
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=3;//十進位振動量(5)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(10)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep(6000);
	//
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=2;//十進位振動量(5)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(10)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	//////////////////////////////////
	m_StrState="State : 腰部按摩";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTFootMassage() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=6;//十進位振動量(6)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(6)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	//////////////////////////////////
	m_StrState="State : 腳部按摩";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTStopVibration() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=83;//S
	buf[2]=0;//十進位振動量(0)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(0)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	//////////////////////////////////
	m_StrState="State : 停止震動";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTMemoryFunction2() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=02;//1->TV,2->Zero
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 2
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		//MessageBox(Output);
	}
	m_StrState="State : 零重力";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTMother() 
{
	// TODO: Add your control notification handler code here
	//m_StrState="State : 母親拍背";
	//UpdateData(false);
	ButtonDisable();
	CStatic *Static;
	Static=((CStatic *)this->GetDlgItem(IDC_State));
	Static->SetWindowText("State : 母親拍背1"); 
	m_ButtMother.EnableWindow(FALSE);
	char buf[4];
	buf[0]=35;//#
	buf[1]=82;//R
	buf[2]=1;//十進位振動量(1)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(1)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep((151-143)*1000);
	/////////////////////
	Static->SetWindowText("State : 母親拍背3"); 
	buf[2]=3;//十進位振動量(3)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(3)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep((159-151)*1000);
	/////////////////////
	Static->SetWindowText("State : 母親拍背5"); 
	buf[2]=5;//十進位振動量(5)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(5)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep((167-159)*1000);
	/////////////////////
	Static->SetWindowText("State : 母親拍背6"); 
	buf[2]=6;//十進位振動量(7)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(7)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep((175-167)*1000);
	/////////////////////
	Static->SetWindowText("State : 母親拍背5"); 
	buf[2]=5;//十進位振動量(5)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(5)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep((183-175)*1000);
	/////////////////////
	Static->SetWindowText("State : 母親拍背3"); 
	buf[2]=3;//十進位振動量(3)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(3)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep((191-183)*1000);
	/////////////////////
	Static->SetWindowText("State : 母親拍背0"); 
	buf[2]=0;//十進位振動量(0)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR R XOR 十進位振動量(0)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	m_ButtMother.EnableWindow(TRUE);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTTVMode() 
{
	// TODO: Add your control notification handler code here
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=01;//1->TV,2->Zero
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 1
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		//MessageBox(Output);
	}
	m_StrState="State : TV mode";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTMovie() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	CString StrBuf;
	StrBuf=m_chrCurDrt;
	StrBuf+="\\ReveriePlayer.exe";
	ShellExecute(NULL,"open",StrBuf,NULL,NULL,SW_SHOWNORMAL); 
	m_StrState="State : 播放影片";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_2Dlg::OnBUTNoSnore() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	CStatic *Static;
	Static=((CStatic *)this->GetDlgItem(IDC_State));
	Static->SetWindowText("State : 防打呼"); 
	m_ButtNoSnore.EnableWindow(FALSE);
	char buf[4];
	buf[0]=35;//#
	buf[1]=73;//I
	buf[2]=7;//十進位伸長量(7)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 十進位伸長量(7)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	Sleep((209-199)*1000);
	///////////////////////////////
	buf[0]=35;//#
	buf[1]=74;//J
	buf[2]=0;//十進位伸長量(0)
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR J XOR 十進位伸長量(0)
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	m_ButtNoSnore.EnableWindow(TRUE);
	ButtonEnable();
}
void CReverie_PC_2Dlg::ButtonEnable()
{
	m_ButtNoSnore.EnableWindow(TRUE);
	m_ButtMovie.EnableWindow(TRUE);
	m_ButtTVMode.EnableWindow(TRUE);
	m_ButtMother.EnableWindow(TRUE);
	m_ButtMemoryFunction2.EnableWindow(TRUE);
	m_ButtStopVibration.EnableWindow(TRUE);
	m_ButtFootMassage.EnableWindow(TRUE);
	m_ButtWaistMassage.EnableWindow(TRUE);
	m_ButtFootUp.EnableWindow(TRUE);
	m_ButtMusic.EnableWindow(TRUE);
	m_ButtAuto.EnableWindow(TRUE);
	m_ButtCalibrateBed.EnableWindow(TRUE);
}
void CReverie_PC_2Dlg::ButtonDisable()
{
	m_ButtNoSnore.EnableWindow(FALSE);
	m_ButtMovie.EnableWindow(FALSE);
	m_ButtTVMode.EnableWindow(FALSE);
	m_ButtMother.EnableWindow(FALSE);
	m_ButtMemoryFunction2.EnableWindow(FALSE);
	m_ButtStopVibration.EnableWindow(FALSE);
	m_ButtFootMassage.EnableWindow(FALSE);
	m_ButtWaistMassage.EnableWindow(FALSE);
	m_ButtFootUp.EnableWindow(FALSE);
	m_ButtMusic.EnableWindow(FALSE);
	m_ButtAuto.EnableWindow(FALSE);
	m_ButtCalibrateBed.EnableWindow(FALSE);
}

void CReverie_PC_2Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	intcount++;

	//
	char lp[3];
	long lMode;
	if(m_mp3player !=NULL && intstep < 9)
	{
		lMode=MCIWndGetMode(m_mp3player,lp,sizeof(lp));
		if(lMode==MCI_MODE_STOP)
		{ 
			MCIWndStop(m_mp3player);
			MCIWndDestroy(m_mp3player);

			m_mp3player=NULL;

			m_mp3player = MCIWndCreate(this->GetSafeHwnd(),AfxGetInstanceHandle(),WS_CHILD | WS_VISIBLE| MCIWNDF_NOMENU| MCIWNDF_NOPLAYBAR,m_StrSHexhaAudio);
			MCIWndPlay(m_mp3player);
		} 		
	}
	//

	switch(intstep)
	{
	case 1://30
		if(intcount>=30)
		{
			intcount=0;
			intstep=2;
			OnBUTFootUp();
			ButtonDisable();
		}
		break;
	case 2://60
		if(intcount>=30)
		{
			intcount=0;
			intstep=3;
			OnBUTWaistMassage();
			ButtonDisable();
		}
		break;
	case 3://77
		if(intcount>=6)
		{
			intcount=0;
			intstep=4;
			OnBUTFootMassage();
			ButtonDisable();
		}
		break;
	case 4://100
		if(intcount>=23)
		{
			intcount=0;
			intstep=5;
			OnBUTStopVibration();
			ButtonDisable();
		}
		break;
	case 5://114
		if(intcount>=14)
		{
			intcount=0;
			intstep=6;
			OnBUTMemoryFunction2();
			ButtonDisable();
		}
		break;
	case 6://143~191
		if(intcount>=29)
		{
			intcount=0;
			intstep=7;
			OnBUTMother();
			ButtonDisable();
		}
		break;
	case 7://199~209
		if(intcount>=8)
		{
			intcount=0;
			intstep=8;
			OnBUTNoSnore();
			ButtonDisable();
		}
		break;
	case 8://240
		if(intcount>=31)
		{
			intcount=0;
			intstep=9;
			OnBUTTVMode();
			ButtonDisable();
		}
		break;
	case 9://270
		if(intcount>=30)
		{

			MCIWndStop(m_mp3player);
			MCIWndDestroy(m_mp3player);
			
			intcount=0;
			intstep=10;
			OnBUTMovie();
			ButtonDisable();
		}
		break;
	case 10://330
		if(intcount>=60)
		{
			intcount=0;
			intstep=11;
			OnBUTCalibrateBed();
			ButtonDisable();
		}
		break;
	case 11:
		intcount=0;
		intstep=0;
		KillTimer(1);
		ButtonEnable();
		break;
	}
	CDialog::OnTimer(nIDEvent);
}
