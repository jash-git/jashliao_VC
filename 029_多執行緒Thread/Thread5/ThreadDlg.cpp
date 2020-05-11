// ThreadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Thread.h"
#include "ThreadDlg.h"
#include <stdio.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
UINT ThreadFunction(LPVOID WinObjPtr);
UINT ThreadFunction1(LPVOID WinObjPtr);
CEvent CStartEven,CStartEven1;
//HANDLE ghThread=CreateEvent(NULL,FALSE,FALSE,NULL);
FILE *p;
int k=0;
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
// CThreadDlg dialog

CThreadDlg::CThreadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThreadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThreadDlg)
	m_v1 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThreadDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CThreadDlg, CDialog)
	//{{AFX_MSG_MAP(CThreadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnCreateThread)
	ON_BN_CLICKED(IDC_BUTTON2, OnRunThread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadDlg message handlers

BOOL CThreadDlg::OnInitDialog()
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

void CThreadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CThreadDlg::OnPaint() 
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
HCURSOR CThreadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CThreadDlg::OnCreateThread() 
{
	// TODO: Add your control notification handler code here
	CWinThread *pr=AfxBeginThread(ThreadFunction,this,0,0,0,NULL);
	CWinThread *pr1=AfxBeginThread(ThreadFunction1,this,0,0,0,NULL);
	p=fopen("¤p¬õ´U.txt","w");
}

void CThreadDlg::OnRunThread() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_v1+=1;
	UpdateData(false);
	CStartEven.SetEvent(); 
	//CStartEven1.SetEvent(); 
}
UINT ThreadFunction(LPVOID WinObjPtr)
{
	CThreadDlg *u=(CThreadDlg *)AfxGetMainWnd();
	while(k<20)
	{
		CStartEven.Lock(INFINITE); 
		fprintf(p,"%d\n",200);
		k++;
		CStartEven.Unlock(); 
	}

	u->MessageBox("ok");
	fclose(p);
	return 0;
}
UINT ThreadFunction1(LPVOID WinObjPtr)
{
	CThreadDlg *u=(CThreadDlg *)AfxGetMainWnd();
	CStartEven1.Lock(INFINITE); 
	CEdit *cj=(CEdit *)(u->GetDlgItem(IDC_EDIT1));
	cj->SetWindowText("500");
	//u->MessageBox("ok");
	CStartEven1.Unlock();
	return 1;
}