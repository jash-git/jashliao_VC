// ProjCombDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProjComb.h"
#include "ProjCombDlg.h"

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
// CProjCombDlg dialog

CProjCombDlg::CProjCombDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProjCombDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CProjCombDlg)
	m_v1 = _T("");
	m_v2 = _T("");
	m_v3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProjCombDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CProjCombDlg)
	DDX_CBString(pDX, IDC_COMBO1, m_v1);
	DDX_LBString(pDX, IDC_LIST1, m_v2);
	DDX_Text(pDX, IDC_EDIT1, m_v3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CProjCombDlg, CDialog)
	//{{AFX_MSG_MAP(CProjCombDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_LBN_DBLCLK(IDC_LIST1, OnDblclkList1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_CBN_EDITUPDATE(IDC_COMBO1, OnEditupdateCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO1, OnDropdownCombo1)
	ON_CBN_CLOSEUP(IDC_COMBO1, OnCloseupCombo1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CProjCombDlg message handlers

BOOL CProjCombDlg::OnInitDialog()
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

	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProjCombDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CProjCombDlg::OnPaint() 
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
HCURSOR CProjCombDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CProjCombDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CListBox *listBox=(CListBox *)GetDlgItem(IDC_LIST1);
	UpdateData(true);
	listBox->AddString(m_v1);
	listBox->SetCurSel(0); 
	UpdateData(false);
}

void CProjCombDlg::OnEditchangeCombo1() 
{
	// TODO: Add your control notification handler code here
}

void CProjCombDlg::OnDblclkList1() 
{
	// TODO: Add your control notification handler code here
	/////////////////////////////////////////////////////

	//PS被注解的程式碼與非注解的程式碼功能相同
	
	/////////////////////////////////////////////////////
	CListBox *listBox=(CListBox *)GetDlgItem(IDC_LIST1);
	int a=listBox->GetCurSel();
	listBox->GetText(a,m_v3);
	UpdateData(false);
	/////////////////////////////////////////////////////
	//UpdateData(true);
	//m_v3=m_v2;
	//UpdateData(false);
}

void CProjCombDlg::OnSelchangeCombo1() 
{
	// TODO: Add your control notification handler code here
}

void CProjCombDlg::OnEditupdateCombo1() 
{
	// TODO: Add your control notification handler code here	
}

void CProjCombDlg::OnDropdownCombo1() 
{
	// TODO: Add your control notification handler code here
}

void CProjCombDlg::OnCloseupCombo1() 
{
	// TODO: Add your control notification handler code here
}
