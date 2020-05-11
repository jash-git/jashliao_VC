// 8136_3asixDlg.cpp : implementation file
//

#include "stdafx.h"
#include "8136_3asix.h"
#include "8136_3asixDlg.h"
#include "pci_8136m.h"
	
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define ms 1000
#define TotalAxis 5		//senyao

//8136 set
BOOL ThreadOn=false;
HANDLE hEvent[7];
U16	gInt_Sts[7]={0,0,0,0,0,0,0};
I32 gInt_Count[7]={0,0,0,0,0,0,0};
I16 CardNo;
I16 AxisNo=0;	//senyao
long encoder[TotalAxis];	//senyao

///Motion Ratio
int X_Ratio=200;
int Y_Ratio=200;
int Z_Ratio=250;
int R1_Ratio=167;
int R2_Ratio=167;

//8136 set
UINT AXIS0_ISR(LPVOID pParam)
{
	U16 Int_Sts;

	while( ThreadOn )
	{ 
		DWORD Ret=WaitForSingleObject(hEvent[0],500);
		if( Ret == WAIT_OBJECT_0 )
		{
			_8136_S_Get_Int_Status(CardNo,AXIS0,&Int_Sts);
			gInt_Sts[0]=Int_Sts;
			gInt_Count[0]++;
			ResetEvent(hEvent[0]);
		}
	}

	return 0;
}

UINT AXIS1_ISR(LPVOID pParam)
{
	U16 Int_Sts;

	while( ThreadOn )
	{
		DWORD Ret=WaitForSingleObject(hEvent[1],500);
		if( Ret == WAIT_OBJECT_0 )
		{
			_8136_S_Get_Int_Status(CardNo,AXIS1,&Int_Sts);
			gInt_Sts[1]=Int_Sts;
			gInt_Count[1]++;
			ResetEvent(hEvent[1]);
		}
	}

	return 0;
}

UINT AXIS2_ISR(LPVOID pParam)
{
	U16 Int_Sts;

	while( ThreadOn )
	{
		DWORD Ret=WaitForSingleObject(hEvent[2],500);
		if( Ret == WAIT_OBJECT_0 )
		{
			_8136_S_Get_Int_Status(CardNo,AXIS2,&Int_Sts);
			gInt_Sts[2]=Int_Sts;
			gInt_Count[2]++;
			ResetEvent(hEvent[2]);
		}
	}

	return 0;
}

UINT AXIS3_ISR(LPVOID pParam)
{
	U16 Int_Sts;

	while( ThreadOn )
	{
		DWORD Ret=WaitForSingleObject(hEvent[3],500);
		if( Ret == WAIT_OBJECT_0 )
		{
			_8136_S_Get_Int_Status(CardNo,AXIS3,&Int_Sts);
			gInt_Sts[3]=Int_Sts;
			gInt_Count[3]++;
			ResetEvent(hEvent[3]);
		}
	}

	return 0;
}


UINT AXIS4_ISR(LPVOID pParam)
{
	U16 Int_Sts;

	while( ThreadOn )
	{
		DWORD Ret=WaitForSingleObject(hEvent[4],500);
		if( Ret == WAIT_OBJECT_0 )
		{
			_8136_S_Get_Int_Status(CardNo,AXIS4,&Int_Sts);
			gInt_Sts[4]=Int_Sts;
			gInt_Count[4]++;
			ResetEvent(hEvent[4]);
		}
	}

	return 0;
}

UINT AXIS5_ISR(LPVOID pParam)
{
	U16 Int_Sts;

	while( ThreadOn )
	{
		DWORD Ret=WaitForSingleObject(hEvent[5],500);
		if( Ret == WAIT_OBJECT_0 )
		{
			_8136_S_Get_Int_Status(CardNo,AXIS5,&Int_Sts);
			gInt_Sts[5]=Int_Sts;
			gInt_Count[5]++;
			ResetEvent(hEvent[5]);
		}
	}

	return 0;
}

UINT CARD_ISR(LPVOID pParam)
{
	U16 Int_Sts;

	while( ThreadOn )
	{
		DWORD Ret=WaitForSingleObject(hEvent[6],500);
		if( Ret == WAIT_OBJECT_0 )
		{
			_8136_S_Get_Int_Status(CardNo,AXIS0,&Int_Sts);
			gInt_Sts[6]=Int_Sts;
			gInt_Count[6]++;
			ResetEvent(hEvent[6]);
		}
	}

	return 0;
}

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
// CMy8136_3asixDlg dialog

CMy8136_3asixDlg::CMy8136_3asixDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy8136_3asixDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy8136_3asixDlg)
	m_ParaDis = 1.0f;
	m_ParaMV = 1000;
	m_ParaSV = 100;
	m_ParaTacc = 0.2f;
	m_ParaTdec = 0.2f;
	m_Sensor = 0;
	m_Pressure = 0;
	m_Axis = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy8136_3asixDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy8136_3asixDlg)
	DDX_Text(pDX, IDC_ParaDis, m_ParaDis);
	DDX_Text(pDX, IDC_ParaMV, m_ParaMV);
	DDX_Text(pDX, IDC_ParaSV, m_ParaSV);
	DDX_Text(pDX, IDC_ParaTacc, m_ParaTacc);
	DDX_Text(pDX, IDC_ParaTdec, m_ParaTdec);
	DDX_Text(pDX, IDC_Sensor, m_Sensor);
	DDX_Text(pDX, IDC_Pressure, m_Pressure);
	DDX_Text(pDX, IDC_Axis, m_Axis);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy8136_3asixDlg, CDialog)
	//{{AFX_MSG_MAP(CMy8136_3asixDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_Exit, OnExit)
	ON_BN_CLICKED(IDC_XR, OnXr)
	ON_BN_CLICKED(IDC_XL, OnXl)
	ON_BN_CLICKED(IDC_YF, OnYf)
	ON_BN_CLICKED(IDC_YB, OnYb)
	ON_BN_CLICKED(IDC_ZD, OnZd)
	ON_BN_CLICKED(IDC_ZU, OnZu)
	ON_BN_CLICKED(IDC_Stop, OnStop)
	ON_BN_CLICKED(IDC_Reset, OnReset)
	ON_BN_CLICKED(IDC_XL2, OnXl2)
	ON_BN_CLICKED(IDC_XR2, OnXr2)
	ON_BN_CLICKED(IDC_YF2, OnYf2)
	ON_BN_CLICKED(IDC_YB2, OnYb2)
	ON_BN_CLICKED(IDC_ZD2, OnZd2)
	ON_BN_CLICKED(IDC_BUTTON1, OnTest)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_Home, OnHome)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy8136_3asixDlg message handlers

BOOL CMy8136_3asixDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	SetTimer1 = 100;

	m_CloseCard = false;

	x_dir = 1;//改變馬達方向變數
	y_dir = 1;
	z_dir = 1;
	x_pos = 0;
	y_pos = 0;
	z_pos = 0;

	Axis_Reset_Index = 0;	//s_reset
	Axis_Reset_Counter = 0;	//s_reset

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
	
	//8136	設定
	_8136_Initial(&m_nCards);	

	if( m_nCards == 0 ) exit(0);	// 如果沒有卡就離開

	int i;

	SetTimer(1,SetTimer1,NULL);//路徑規化計時器

	CardNo=0;
	//_8136_M_Switch_Logic(CardNo,0,0,0);//senyao
	_8136_M_Switch_Logic(CardNo,0,1,0);
	_8136_S_Set_Int_Factor(CardNo,AXIS0,0x1f,0x02);
	_8136_S_Set_Int_Factor(CardNo,AXIS1,0x1f,0x02);
	_8136_S_Set_Int_Factor(CardNo,AXIS2,0x1f,0x02);
	_8136_S_Set_Int_Factor(CardNo,AXIS3,0x1f,0x02);
	_8136_S_Set_Int_Factor(CardNo,AXIS4,0x1f,0x02);
	_8136_S_Set_Int_Factor(CardNo,AXIS5,0x1f,0x02);

	_8136_INT_Enable(CardNo,&hEvent[0]);
	_8136_S_INT_Control(CardNo,ENABLE);

	_8136_M_Set_System_Param(CardNo,4,1);

	_8136_P_Initial(CardNo);

	for(i=0;i<6;i++)
	{
		_8136_M_Set_IO_Active(CardNo,i,1);
		_8136_P_Set_Output_Type(CardNo, i , CW_CCW );
		_8136_P_Set_Input_Type(CardNo, i , E_A_B , X1 );
		_8136_P_Clear(CardNo,i);
		_8136_P_Set_Compare_Value(CardNo,i,10000);
		_8136_M_Set_SVON(CardNo,i,0);	//senyao
	}

	for(i=6;i<9;i++)
		_8136_P_Set_Input_Type(CardNo, i , E_CW_CCW , X4 );
	
	ThreadOn=true;
	AfxBeginThread(AXIS0_ISR,NULL);
	AfxBeginThread(AXIS1_ISR,NULL);
	AfxBeginThread(AXIS2_ISR,NULL);
	AfxBeginThread(AXIS3_ISR,NULL);
	AfxBeginThread(AXIS4_ISR,NULL);
	AfxBeginThread(AXIS5_ISR,NULL);
	AfxBeginThread(CARD_ISR,NULL);

	_8136_A_Initial(CardNo);

	for(i=0;i<6;i++)
		_8136_A_Set_Compare_Volt(CardNo,i,-5.0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy8136_3asixDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMy8136_3asixDlg::OnPaint() 
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
HCURSOR CMy8136_3asixDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMy8136_3asixDlg::CloseCard()
{
	int i;

	if(m_CloseCard == true)
	{
		_8136_R_Write(CardNo,0,0,0);
		_8136_R_Write(CardNo,0,1,0);
		_8136_R_Write(CardNo,0,2,0);
		_8136_R_Write(CardNo,0,3,0);
	
		for(i=0;i<m_nCards;i++)
			_8136_S_Close(i);
	
		_8136_S_INT_Control(CardNo,DISABLE);
		_8136_INT_Disable(CardNo);
		m_CloseCard = true;
	}
}

void CMy8136_3asixDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == 1)
	{
		OnSensor();
	}
	if(nIDEvent == 2)
	{
		Reset11();
		Reset12();
		Reset13();
		Reset14();
		Reset15();
	}	
	CDialog::OnTimer(nIDEvent);
}

void CMy8136_3asixDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	for(int i=0;i<6;i++)
	{
		_8136_M_Set_SVON(CardNo,i,1);	//senyao	
	}
	_8136_INT_Disable(CardNo);			//senyao
	_8136_S_INT_Control(CardNo,0);		//senyao
	CloseCard();
	KillTimer(1);
	KillTimer(2);
	CDialog::OnClose();
}

void CMy8136_3asixDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	for(int i=0;i<6;i++)
	{
		_8136_M_Set_SVON(CardNo,i,1);	//senyao	
	}
	_8136_INT_Disable(CardNo);			//senyao
	_8136_S_INT_Control(CardNo,0);		//senyao
	CloseCard();
	KillTimer(1);
	KillTimer(2);	
	// TODO: Add your message handler code here
	
}

void CMy8136_3asixDlg::OnSensor()
{
	double Volt;
	_8136_D_InputA(CardNo,&m_lDinput);	//讀取SENSOR值
	_8136_A_Read_Volt(CardNo,0,&Volt);	//讀取LOADCELL值
	/*
	if( !(m_lDinput & ( 1L << MEL2 )) )
		{
			m_sensor = 1;
		}
	else
		m_sensor = 0;*/
	SetDlgItemInt(IDC_Sensor, (long)m_lDinput);
//	SetDlgItemInt(IDC_Pressure, (float)Volt);
	m_Sensor = m_lDinput;	//感測器量測值
	m_Pressure = Volt;		//LOADCELL值
	for(int i=0; i<=TotalAxis; i++)
	{
		_8136_P_Read(CardNo, i, (encoder+i));		//encoder
	}

	SetDlgItemInt(IDC_Encoder0, encoder[0]);	//encoder
	SetDlgItemInt(IDC_Encoder1, encoder[1]);
	SetDlgItemInt(IDC_Encoder2, encoder[2]);
	SetDlgItemInt(IDC_Encoder3, encoder[3]);
	SetDlgItemInt(IDC_Encoder4, encoder[4]);

//	UpdateData(FALSE);		//senyao
}

void CMy8136_3asixDlg::OnExit() 
{
	// TODO: Add your control notification handler code here
	for(int i=0;i<6;i++)
	{
		_8136_M_Set_SVON(CardNo,i,1);	//senyao	
	}
	_8136_INT_Disable(CardNo);			//senyao
	_8136_S_INT_Control(CardNo,0);		//senyao
	CloseCard();
	KillTimer(1);
	KillTimer(2);
	exit(0);
}


void CMy8136_3asixDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	_8136_A_Write_Value(CardNo, AXIS0, 0);	//senyao
	for(int i=0;i<6;i++)
	{
		_8136_Motion_Stop(CardNo,i);
	}
}

void CMy8136_3asixDlg::OnXr() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	float x_Dis;
	int x_SV;
	int x_MV;
	float x_Tacc;
	float x_Tdec;
	x_Dis = m_ParaDis;
	x_SV  = m_ParaSV;
	x_MV  = m_ParaMV;
	x_Tacc= m_ParaTacc;
	x_Tdec= m_ParaTdec;

	x_pos = x_Dis;
	x_dir = 1;
	_8136_Start_SR_Move(CardNo, AXIS0, (long)x_pos*x_dir*ms, x_SV, x_MV, x_Tacc, x_Tdec);
}

void CMy8136_3asixDlg::OnXl() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	float x_Dis;
	int x_SV;
	int x_MV;
	float x_Tacc;
	float x_Tdec;
	x_Dis = m_ParaDis;
	x_SV  = m_ParaSV;
	x_MV  = m_ParaMV;
	x_Tacc= m_ParaTacc;
	x_Tdec= m_ParaTdec; 

	x_pos = x_Dis;
	x_dir = -1;
	_8136_Start_SR_Move(CardNo, AXIS0, (long)x_pos*x_dir*ms, x_SV, x_MV, x_Tacc, x_Tdec);	
}

void CMy8136_3asixDlg::OnYf() 
{
	// TODO: Add your control notification handler code here
	
	UpdateData(TRUE);
	float y_Dis;
	int y_SV;
	int y_MV;
	float y_Tacc;
	float y_Tdec;
	y_Dis = m_ParaDis;
	y_SV  = m_ParaSV;
	y_MV  = m_ParaMV;
	y_Tacc= m_ParaTacc;
	y_Tdec= m_ParaTdec; 

	y_pos = y_Dis;
	y_dir = 1;
	_8136_Start_SR_Move(CardNo, AXIS2, (long)y_pos*y_dir*ms, y_SV, y_MV, y_Tacc, y_Tdec);	
}

void CMy8136_3asixDlg::OnYb() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	float y_Dis;
	int y_SV;
	int y_MV;
	float y_Tacc;
	float y_Tdec;
	y_Dis = m_ParaDis;
	y_SV  = m_ParaSV;
	y_MV  = m_ParaMV;
	y_Tacc= m_ParaTacc;
	y_Tdec= m_ParaTdec; 

	y_pos = y_Dis;
	y_dir = -1;
	_8136_Start_SR_Move(CardNo, AXIS2, (long)y_pos*y_dir*ms, y_SV, y_MV, y_Tacc, y_Tdec);
}

void CMy8136_3asixDlg::OnZd() 
{
	// TODO: Add your control notification handler code here
	float z_Dis;
	int z_SV;
	int z_MV;
	float z_Tacc;
	float z_Tdec;
	z_Dis = m_ParaDis;
	z_SV  = m_ParaSV;
	z_MV  = m_ParaMV;
	z_Tacc= m_ParaTacc;
	z_Tdec= m_ParaTdec; 

	z_pos = z_Dis;
	z_dir = 1;
	_8136_Start_SR_Move(CardNo, AXIS4, (long)z_pos*z_dir*ms, z_SV, z_MV, z_Tacc, z_Tdec);	
}


void CMy8136_3asixDlg::OnZu() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	float z_Dis;
	int z_SV;
	int z_MV;
	float z_Tacc;
	float z_Tdec;
	z_Dis = m_ParaDis;
	z_SV  = m_ParaSV;
	z_MV  = m_ParaMV;
	z_Tacc= m_ParaTacc;
	z_Tdec= m_ParaTdec; 

	z_pos = z_Dis;
	z_dir = -1;
	_8136_Start_SR_Move(CardNo, AXIS4, (long)z_pos*z_dir*ms, z_SV, z_MV, z_Tacc, z_Tdec);	
}

void CMy8136_3asixDlg::OnReset() 
{
	// TODO: Add your control notification handler code here
	SetTimer(2,SetTimer1,NULL);
	Axis_Reset_Index = 1;
}

void CMy8136_3asixDlg::Reset11()
{
	// TODO: Add your control notification handler code here

	Axis_Reset_Counter++;
	float o_Dis;
	int o_SV, o_MV;
	double o_Tacc, o_Tdec;
	o_Dis = 20;
	o_SV  = 100;
	o_MV  = 10000;
	o_Tacc= 0.2;
	o_Tdec= 0.2;
	
	if(Axis_Reset_Index == 1)
	{
		_8136_Start_SR_Move(CardNo, AXIS0, (long)o_Dis*ms, o_SV, o_MV, o_Tacc, o_Tdec);
		_8136_Start_SR_Move(CardNo, AXIS2, (long)o_Dis*ms, o_SV, o_MV, o_Tacc, o_Tdec);
		_8136_Start_SR_Move(CardNo, AXIS4, (long)5*ms, o_SV, o_MV, o_Tacc, o_Tdec);
		Axis_Reset_Index = 2;
	}
	
	//計算動作時間
	if((Axis_Reset_Counter > (1000*(o_Tacc+o_Tdec+(o_Dis/o_MV))/SetTimer1)) && (Axis_Reset_Index == 2))
	{
		Axis_Reset_Counter = 0;
		Axis_Reset_Index = 3;
	}
}

void CMy8136_3asixDlg::Reset12()
{
	// TODO: Add your control notification handler code here

}

void CMy8136_3asixDlg::Reset13()
{
	// TODO: Add your control notification handler code here
	Axis_Reset_Counter++;
	if((Axis_Reset_Index == 3) && (Axis_Reset_Counter >= 20))
	{
		Axis_Reset_Index = 4;
		Axis_Reset_Counter = 0;
	}

	if(Axis_Reset_Index==4)
	{
		_8136_Home_Move(CardNo, AXIS0, 100, -10000, 0.5);
		_8136_Home_Move(CardNo, AXIS2, 100, -10000, 0.5);
		_8136_Home_Move(CardNo, AXIS4, 100, -10000, 0.5);
		KillTimer(2);
	}
}

void CMy8136_3asixDlg::Reset14()
{
	// TODO: Add your control notification handler code here
}

void CMy8136_3asixDlg::Reset15()
{
	// TODO: Add your control notification handler code here
}

void CMy8136_3asixDlg::OnXr2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	float x_Dis;
	int x_SV;
	int x_MV;
	float x_Tacc;
	float x_Tdec;
	x_Dis = m_ParaDis;
	x_SV  = m_ParaSV;
	x_MV  = m_ParaMV;
	x_Tacc= m_ParaTacc;
	x_Tdec= m_ParaTdec;

	x_pos = x_Dis;
	x_dir = 1;
	_8136_Start_SR_Move(CardNo, AXIS1, (long)x_pos*x_dir*ms, x_SV, x_MV, x_Tacc, x_Tdec);	
}


void CMy8136_3asixDlg::OnXl2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	float x_Dis;
	int x_SV;
	int x_MV;
	float x_Tacc;
	float x_Tdec;
	x_Dis = m_ParaDis;
	x_SV  = m_ParaSV;
	x_MV  = m_ParaMV;
	x_Tacc= m_ParaTacc;
	x_Tdec= m_ParaTdec; 

	x_pos = x_Dis;
	x_dir = -1;
	_8136_Start_SR_Move(CardNo, AXIS1, (long)x_pos*x_dir*ms, x_SV, x_MV, x_Tacc, x_Tdec);
}


void CMy8136_3asixDlg::OnYf2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	float y_Dis;
	int y_SV;
	int y_MV;
	float y_Tacc;
	float y_Tdec;
	y_Dis = m_ParaDis;
	y_SV  = m_ParaSV;
	y_MV  = m_ParaMV;
	y_Tacc= m_ParaTacc;
	y_Tdec= m_ParaTdec; 

	y_pos = y_Dis;
	y_dir = 1;
	_8136_Start_SR_Move(CardNo, AXIS3, (long)y_pos*y_dir*ms, y_SV, y_MV, y_Tacc, y_Tdec);
}

void CMy8136_3asixDlg::OnYb2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	float y_Dis;
	int y_SV;
	int y_MV;
	float y_Tacc;
	float y_Tdec;
	y_Dis = m_ParaDis;
	y_SV  = m_ParaSV;
	y_MV  = m_ParaMV;
	y_Tacc= m_ParaTacc;
	y_Tdec= m_ParaTdec; 

	y_pos = y_Dis;
	y_dir = -1;
	_8136_Start_SR_Move(CardNo, AXIS3, (long)y_pos*y_dir*ms, y_SV, y_MV, y_Tacc, y_Tdec);
}

void CMy8136_3asixDlg::OnZd2() 
{
	// TODO: Add your control notification handler code here
	float z_Dis;
	int z_SV;
	int z_MV;
	float z_Tacc;
	float z_Tdec;
	z_Dis = m_ParaDis;
	z_SV  = m_ParaSV;
	z_MV  = m_ParaMV;
	z_Tacc= m_ParaTacc;
	z_Tdec= m_ParaTdec; 

	z_pos = z_Dis;
	z_dir = 1;
	_8136_A_Write_Volt(CardNo, AXIS0, 3);	//senyao
}


void CMy8136_3asixDlg::OnTest() 
{
	// TODO: Add your control notification handler code here
	_8136_Start_SA_Move(0, 2, 10*Z_Ratio, 100, 10000, 0.1, 0.1);
	
}

void CMy8136_3asixDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	//_8136_Start_SA_Move(0, 2,-10*Z_Ratio, 100, 10000, 0.1, 0.1);
	_8136_Start_SA_Move(0, 1, 50*X_Ratio, 100, 1000, 0.1, 0.1);
	_8136_Start_SA_Move(0, 0,-50*Y_Ratio, 100, 1000, 0.1, 0.1);
	_8136_Start_SA_Move(0, 2, 50*Z_Ratio, 100, 1000, 0.1, 0.1);
	_8136_Start_SA_Move(0, 3, 90*R1_Ratio, 100, 1000, 0.1, 0.1);
	_8136_Start_SA_Move(0, 4,-90*R2_Ratio, 100, 1000, 0.1, 0.1);
}

void CMy8136_3asixDlg::OnHome() 
{
	// TODO: Add your control notification handler code here
	_8136_Home_Move(0, 1, 100, -1000, 0.1);//X Axis Home
	_8136_Home_Move(0, 0, 100,  1000, 0.1);//Y Axis Home
	_8136_Home_Move(0, 2, 100, -1000, 0.1);//Z Axis Home
	_8136_Start_SA_Move(0, 3, 0*R1_Ratio, 100, 1000, 0.1, 0.1);
//	_8136_Home_Move(0, 3, 100, -1000, 0.1);//R1 Home
	_8136_Home_Move(0, 4, 100,  1000, 0.1);//R2 Home

//	_8136_Start_SR_Move(0,4,15000,100,10000,0.1,0.1);
}

void CMy8136_3asixDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int axis;
	long Dis;
	int SV;
	int MV;
	float Tacc;
	float Tdec;
	axis = m_Axis;
	Dis = m_ParaDis;
	SV  = m_ParaSV;
	MV  = m_ParaMV;
	Tacc= m_ParaTacc;
	Tdec= m_ParaTdec; 
	_8136_Start_SR_Move(0,axis,Dis,SV,MV,Tacc,Tdec);
}
