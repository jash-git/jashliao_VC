// thread6Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "thread6.h"
#include "thread6Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define ONtest WM_USER + 619 
int k=0;
int k1=0;
FILE *p,*p1;
UINT ThreadFunction(LPVOID WinObjPtr);
UINT ThreadFunction1(LPVOID WinObjPtr);
HANDLE MsgEvent,MsgEvent1;
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
// CThread6Dlg dialog

CThread6Dlg::CThread6Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThread6Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThread6Dlg)
	m_v1 = 0.0f;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThread6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThread6Dlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThread6Dlg, CDialog)
	//{{AFX_MSG_MAP(CThread6Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_MESSAGE(ONtest,clearvalue)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThread6Dlg message handlers

BOOL CThread6Dlg::OnInitDialog()
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

void CThread6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThread6Dlg::OnPaint() 
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
HCURSOR CThread6Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CThread6Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	p=fopen("¤p¬õ´U.txt","w");
	p1=fopen("¤p¬õ´U1.txt","w");
	MsgEvent=CreateEvent(NULL,FALSE,FALSE,NULL);
	MsgEvent1=CreateEvent(NULL,FALSE,FALSE,NULL);
	CWinThread *pr=AfxBeginThread(ThreadFunction,this,0,0,0,NULL);
	CWinThread *pr1=AfxBeginThread(ThreadFunction1,this,0,THREAD_PRIORITY_TIME_CRITICAL,0,NULL);

}

void CThread6Dlg::OnButton2() 
{
	UpdateData(true);
	m_v1+=1;
	UpdateData(false);
	SetEvent(MsgEvent);
	SetEvent(MsgEvent1);
}
void CThread6Dlg::clearvalue()
{
	UpdateData(true);
		m_v1+=100;
	UpdateData(false);
	//this->SetDlgItemText(IDC_EDIT1,"100"); 
}
UINT ThreadFunction(LPVOID WinObjPtr)
{
	CThread6Dlg *u=(CThread6Dlg *)AfxGetMainWnd();
	while(k<20)
	{
		WaitForSingleObject(MsgEvent,INFINITE);
		fprintf(p,"%d\n",200);
		k++;
		ResetEvent(MsgEvent);
	}
	//u->clearvalue();
	HWND hWnd = FindWindow(NULL, "thread6");
	::PostMessage(hWnd,ONtest,0,0);
	u->MessageBox("ok");
	fclose(p);
	return 0;
}
UINT ThreadFunction1(LPVOID WinObjPtr)
{
	WaitForSingleObject(MsgEvent1,INFINITE);
	CThread6Dlg *u=(CThread6Dlg *)AfxGetMainWnd();
	while(k1<20)
	{
		fprintf(p1,"%d\n",k1);
		k1++;
	}
	u->MessageBox("KO");
	fclose(p1);
	return 0;
}
