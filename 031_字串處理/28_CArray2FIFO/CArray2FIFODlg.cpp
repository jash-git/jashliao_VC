// CArray2FIFODlg.cpp : implementation file
//

#include "stdafx.h"
#include "CArray2FIFO.h"
#include "CArray2FIFODlg.h"

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
// CCArray2FIFODlg dialog

CCArray2FIFODlg::CCArray2FIFODlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCArray2FIFODlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCArray2FIFODlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCArray2FIFODlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCArray2FIFODlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCArray2FIFODlg, CDialog)
	//{{AFX_MSG_MAP(CCArray2FIFODlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnIN1)
	ON_BN_CLICKED(IDC_BUTTON2, OnDel1)
	ON_BN_CLICKED(IDC_BUTTON3, OnIN2)
	ON_BN_CLICKED(IDC_BUTTON4, OnShow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCArray2FIFODlg message handlers

BOOL CCArray2FIFODlg::OnInitDialog()
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
	m_ArrayData.RemoveAll();	////CArray Step_03
	m_intArrayCount=0;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCArray2FIFODlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCArray2FIFODlg::OnPaint() 
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
HCURSOR CCArray2FIFODlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCArray2FIFODlg::OnIN1() ////CArray Step_04
{
	// TODO: Add your control notification handler code here
	CString Buf;
	Buf="1";
	m_ArrayData.Add(Buf);
	Buf="2";
	m_ArrayData.Add(Buf);
	Buf="3";
	m_ArrayData.Add(Buf);
	Buf="4";
	m_ArrayData.Add(Buf);
	m_intArrayCount=m_ArrayData.GetSize();
	Buf.Format("羆ゑ计 %d",m_intArrayCount);
	MessageBox(Buf);
}

void CCArray2FIFODlg::OnDel1() 
{
	// TODO: Add your control notification handler code here
	CString Buf;
	m_ArrayData.RemoveAt(0);
	m_intArrayCount=m_ArrayData.GetSize();
	Buf.Format("羆ゑ计 %d",m_intArrayCount);
	MessageBox(Buf);
	for(int i=0;i<m_intArrayCount;i++)
	{
		Buf=m_ArrayData.GetAt(i);
		MessageBox(Buf);
	}
}

void CCArray2FIFODlg::OnIN2() 
{
	// TODO: Add your control notification handler code here
	CString Buf;
	Buf="5";
	m_ArrayData.Add(Buf);
	m_intArrayCount=m_ArrayData.GetSize();
	Buf.Format("羆ゑ计 %d",m_intArrayCount);
	MessageBox(Buf);	
}

void CCArray2FIFODlg::OnShow() 
{
	// TODO: Add your control notification handler code here
	CString Buf;
	m_intArrayCount=m_ArrayData.GetSize();
	Buf.Format("羆ゑ计 %d",m_intArrayCount);
	MessageBox(Buf);
	for(int i=0;i<m_intArrayCount;i++)
	{
		Buf=m_ArrayData.GetAt(i);
		MessageBox(Buf);
	}	
}
