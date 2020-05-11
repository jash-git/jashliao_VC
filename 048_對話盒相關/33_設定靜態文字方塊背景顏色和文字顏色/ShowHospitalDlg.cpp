// ShowHospitalDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowHospital.h"
#include "ShowHospitalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

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
// CShowHospitalDlg dialog

CShowHospitalDlg::CShowHospitalDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowHospitalDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowHospitalDlg)
	m_ShowData00 = _T("00");
	m_ShowData01 = _T("01");
	m_ShowData02 = _T("02");
	m_ShowData03 = _T("03");
	m_ShowData04 = _T("04");
	m_ShowData05 = _T("05");
	m_ShowData06 = _T("06");
	m_ShowData07 = _T("07");
	m_ShowData08 = _T("08");
	m_ShowData09 = _T("09");
	m_ShowData10 = _T("10");
	m_ShowData11 = _T("11");
	m_ShowData12 = _T("12");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShowHospitalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowHospitalDlg)
	DDX_Text(pDX, IDC_STATIC_00, m_ShowData00);
	DDX_Text(pDX, IDC_STATIC_01, m_ShowData01);
	DDX_Text(pDX, IDC_STATIC_02, m_ShowData02);
	DDX_Text(pDX, IDC_STATIC_03, m_ShowData03);
	DDX_Text(pDX, IDC_STATIC_04, m_ShowData04);
	DDX_Text(pDX, IDC_STATIC_05, m_ShowData05);
	DDX_Text(pDX, IDC_STATIC_06, m_ShowData06);
	DDX_Text(pDX, IDC_STATIC_07, m_ShowData07);
	DDX_Text(pDX, IDC_STATIC_08, m_ShowData08);
	DDX_Text(pDX, IDC_STATIC_09, m_ShowData09);
	DDX_Text(pDX, IDC_STATIC_10, m_ShowData10);
	DDX_Text(pDX, IDC_STATIC_11, m_ShowData11);
	DDX_Text(pDX, IDC_STATIC_12, m_ShowData12);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShowHospitalDlg, CDialog)
	//{{AFX_MSG_MAP(CShowHospitalDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowHospitalDlg message handlers

BOOL CShowHospitalDlg::OnInitDialog()
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
	InitialVariable();//呼叫讀取設定檔
	/////////////////////////////////////////////////////////////////////////////
	SetindowPositionSize();//呼叫視窗裁剪(切)
	//////////////////////////////////////////////////////////////////////////////
	SetTimer(1,10000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShowHospitalDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CShowHospitalDlg::OnPaint() 
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
HCURSOR CShowHospitalDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CShowHospitalDlg::InitialVariable(void)
{
	////////////////////////////////////////////////////////////
	//區域變數宣告區
	MSXML2::IXMLDOMDocumentPtr pDoc;
	int nLen=0;
	bool blnRead=false;
	_variant_t vtStr;
	CString StrValue;
	////////////////////////////////////////////////////////////
	//成員變數初始化區
	m_lngTop=0;m_lngLeft=0;m_lngWidth=0;m_lngHeight=0;
	////////////////////////////////////////////////////////////
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));//建立XML物件
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	nLen= ::GetCurrentDirectory(500,m_chrCurDrt);//取得目前程式路徑
	m_StrSettingFileName+="Resources\\Config.xml";//產生設定檔路徑
	blnRead=pDoc->load((_bstr_t)m_StrSettingFileName);//讀取設定檔
	if(blnRead)
	{
		//////////////////////////////////////////////////
		//依序讀取視窗大小嶼位置設定值
		//並將設定值設定到相關成員變數
		MSXML2::IXMLDOMNodePtr Position_Size;
		Position_Size=pDoc->selectSingleNode("//Top");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngTop=atol(StrValue.GetBuffer(0)); 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Left");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngLeft=atol(StrValue.GetBuffer(0)); 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Width");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngWidth=atol(StrValue.GetBuffer(0)); 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Height");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngHeight=atol(StrValue.GetBuffer(0)); 
		//////////////////////////////////////////////////
	}
}
void CShowHospitalDlg::SetindowPositionSize(void)
{
	CRect rect;
	this->MoveWindow(m_lngLeft,(m_lngTop-29),m_lngWidth,(m_lngHeight+29),TRUE);
	this->GetClientRect(rect);
	m_rgn.CreateRectRgn(0,29,rect.Width(),(rect.Height()));
	::SetWindowRgn(GetSafeHwnd(),(HRGN)m_rgn,TRUE);
	//this->MoveWindow(m_lngLeft,(m_lngTop-29),m_lngWidth,(m_lngHeight+29),TRUE);
}
void CShowHospitalDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	InitialVariable();
	CDialog::OnTimer(nIDEvent);
}

HBRUSH CShowHospitalDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if(nCtlColor==CTLCOLOR_STATIC)//設定靜態文字方塊背景顏色和文字顏色
	{
		pDC->SetBkColor(RGB(155,255,205));
		pDC->SetTextColor(RGB(0,0,0)); 
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}
