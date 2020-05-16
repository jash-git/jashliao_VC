// Reverie_PC_1Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "Reverie_PC_1.h"
#include "Reverie_PC_1Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
bool blnopenRS485;
int intStep;
int intCount;
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
// CReverie_PC_1Dlg dialog

CReverie_PC_1Dlg::CReverie_PC_1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReverie_PC_1Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReverie_PC_1Dlg)
	m_StrState = _T("State : ");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReverie_PC_1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReverie_PC_1Dlg)
	DDX_Control(pDX, IDC_BUTRightUp, m_ButtRightUp);
	DDX_Control(pDX, IDC_BUTStandard2, m_ButtStandard2);
	DDX_Control(pDX, IDC_BUTLeftUp, m_ButtLeftUp);
	DDX_Control(pDX, IDC_BUTFootUp, m_ButtFootUp);
	DDX_Control(pDX, IDC_BUTStandard1, m_ButtStandard1);
	DDX_Control(pDX, IDC_BUTHeadUp, m_ButtHeadUp);
	DDX_Control(pDX, IDC_BUTCalibrateBed, m_ButtCalibrateBed);
	DDX_Control(pDX, IDC_BUTAuto, m_ButtAuto);
	DDX_Text(pDX, IDC_State, m_StrState);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReverie_PC_1Dlg, CDialog)
	//{{AFX_MSG_MAP(CReverie_PC_1Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTAuto, OnBUTAuto)
	ON_BN_CLICKED(IDC_BUTCalibrateBed, OnBUTCalibrateBed)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTHeadUp, OnBUTHeadUp)
	ON_BN_CLICKED(IDC_BUTStandard1, OnBUTStandard1)
	ON_BN_CLICKED(IDC_BUTFootUp, OnBUTFootUp)
	ON_BN_CLICKED(IDC_BUTLeftUp, OnBUTLeftUp)
	ON_BN_CLICKED(IDC_BUTStandard2, OnBUTStandard2)
	ON_BN_CLICKED(IDC_BUTRightUp, OnBUTRightUp)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReverie_PC_1Dlg message handlers

BOOL CReverie_PC_1Dlg::OnInitDialog()
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
	OnOpenRS485();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReverie_PC_1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReverie_PC_1Dlg::OnPaint() 
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
HCURSOR CReverie_PC_1Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReverie_PC_1Dlg::OnBUTAuto() 
{
	// TODO: Add your control notification handler code here
	CStatic *Static;
	Static=((CStatic *)this->GetDlgItem(IDC_State));
	Static->SetWindowText("State : 自動展示"); 
	OnBUTFootUp();//mf(3)
	ButtonDisable();
	intStep=1;
	intCount=0;
	SetTimer(1,1000,NULL);
}

void CReverie_PC_1Dlg::OnBUTCalibrateBed() 
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
void CReverie_PC_1Dlg::OnOpenRS485()
{
	// TODO: Add your control notification handler code here
	blnopenRS485=RS.OpenCom(m_intCOMPort,9600,8,0,1);
	if(!blnopenRS485)
	{
		MessageBox("Open RS485 Fail");
		this->OnOK();
	}
		
}
void CReverie_PC_1Dlg::InitialVariable(void)
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	int nLen=0;
	bool blnRead=false;
	_variant_t vtStr;
	CString StrValue;
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
		MSXML2::IXMLDOMNodePtr Position_Size;
		Position_Size=pDoc->selectSingleNode("//COM_Port");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_intCOMPort=_ttoi(static_cast<LPCTSTR>(StrValue)); 
	}
}

void CReverie_PC_1Dlg::OnDestroy() 
{
	CDialog::OnDestroy();
	if(blnopenRS485)
		RS.Close();	
	// TODO: Add your message handler code here
	
}

void CReverie_PC_1Dlg::OnBUTHeadUp() 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=01;//1->頭上
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 1
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	///////////////////////////////////////////////
	m_StrState="State : 頭上";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_1Dlg::OnBUTStandard1() //mf(2)
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=02;//2->恢復水平
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 2
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	///////////////////////////////////////////////
	m_StrState="State : 恢復水平01";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_1Dlg::OnBUTFootUp()//mf(3) 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=03;//3->腳上
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 3
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	///////////////////////////////////////////////
	m_StrState="State : 腳上";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_1Dlg::OnBUTLeftUp()//mf(4) 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=04;//4->左上
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 左上
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	///////////////////////////////////////////////
	m_StrState="State : 左上";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_1Dlg::OnBUTStandard2()//mf(5) 
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=05;//5->恢復水平
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 恢復水平
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	///////////////////////////////////////////////
	m_StrState="State : 恢復水平02";
	UpdateData(false);
	ButtonEnable();
}

void CReverie_PC_1Dlg::OnBUTRightUp()//mf(6)
{
	// TODO: Add your control notification handler code here
	ButtonDisable();
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=06;//6->右上
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 右上
	if(blnopenRS485)
	{
		RS.Write(buf,4);
	}
	///////////////////////////////////////////////
	m_StrState="State : 右上";
	UpdateData(false);
	ButtonEnable();
}
void CReverie_PC_1Dlg::ButtonEnable()
{
	m_ButtRightUp.EnableWindow(TRUE);
	m_ButtStandard2.EnableWindow(TRUE);
	m_ButtLeftUp.EnableWindow(TRUE);
	m_ButtFootUp.EnableWindow(TRUE);
	m_ButtStandard1.EnableWindow(TRUE);
	m_ButtHeadUp.EnableWindow(TRUE);
	m_ButtCalibrateBed.EnableWindow(TRUE);
	m_ButtAuto.EnableWindow(TRUE);
}
void CReverie_PC_1Dlg::ButtonDisable()
{
	m_ButtRightUp.EnableWindow(FALSE);
	m_ButtStandard2.EnableWindow(FALSE);
	m_ButtLeftUp.EnableWindow(FALSE);
	m_ButtFootUp.EnableWindow(FALSE);
	m_ButtStandard1.EnableWindow(FALSE);
	m_ButtHeadUp.EnableWindow(FALSE);
	m_ButtCalibrateBed.EnableWindow(FALSE);
	m_ButtAuto.EnableWindow(FALSE);
}

void CReverie_PC_1Dlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	switch(intStep)
	{
		case 1://25
			intCount++;
			if(intCount>=25)
			{
				OnBUTStandard1();//mf(2)
				ButtonDisable();
				intStep++;
				intCount=0;
			}
			break;
		case 2://55
			intCount++;
			if(intCount>=30)
			{
				OnBUTRightUp();//mf(6)
				ButtonDisable();
				intStep++;
				intCount=0;
			}
			break;
		case 3://65
			intCount++;
			if(intCount>=10)
			{
				OnBUTStandard2();//mf(5) 
				ButtonDisable();
				intStep++;
				intCount=0;
			}
			break;
		case 4://95
			intCount++;
			if(intCount>=30)
			{
				OnBUTLeftUp();//mf(4) 
				ButtonDisable();
				intStep++;
				intCount=0;
			}
			break;
		case 5://100
			intCount++;
			if(intCount>=5)
			{
				OnBUTStandard2();//mf(5) 
				ButtonDisable();
				intStep++;
				intCount=0;
			}
			break;
		case 6:
			intCount++;
			intStep=0;
			KillTimer(1);
			ButtonEnable();
			intCount=0;
			break;
	}
	CDialog::OnTimer(nIDEvent);
}
