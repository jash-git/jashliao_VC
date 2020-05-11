// OPenCloseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "OPenClose.h"
#include "OPenCloseDlg.h"
#include "stdio.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
FILE *fp;
int **GetDay;
int datanumer=0;
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
// COPenCloseDlg dialog

COPenCloseDlg::COPenCloseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COPenCloseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COPenCloseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COPenCloseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COPenCloseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COPenCloseDlg, CDialog)
	//{{AFX_MSG_MAP(COPenCloseDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COPenCloseDlg message handlers

BOOL COPenCloseDlg::OnInitDialog()
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
	SetWindowPos(&CWnd::wndTop,0,0,0,0,SWP_HIDEWINDOW); //jash_liao write
	///測試筆數
	int a,b,i,j;//a,b為月日，i,j為旗標
	fp=fopen("day.txt","r");
	j=0;
	while(fscanf(fp,"%d%d",&a,&b)!=EOF)
		j++;
	fclose(fp);
	////
	////讀取資料
	GetDay=new int *[j];
	for(i=0;i<j;i++)
	{
		GetDay[i]=new int[2];
	}
	fp=fopen("day.txt","r");
	j=0;
	while(fscanf(fp,"%d%d",&a,&b)!=EOF)
	{
		*(*(GetDay+j)+0)=a;//月
		*(*(GetDay+j)+1)=b;//日
		j++;
	}
	datanumer=j;

	SetTimer(1,600000,NULL);//4小時
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void COPenCloseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COPenCloseDlg::OnPaint() 
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
HCURSOR COPenCloseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void COPenCloseDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CTime t1=CTime::GetCurrentTime(); 
	int Month=t1.GetMonth(); 
	int Day=t1.GetDay();
	int i,a,b;
	bool bnlCloseApp=false;
	for(i=0;i<datanumer;i++)
	{
		a=*(*(GetDay+i)+0);//月
		b=*(*(GetDay+i)+1);//日
		if(a==Month && b==Day)
		{
			bnlCloseApp=true;
			break;
		}
		else
		{
			bnlCloseApp=false;
		}
	}
	if(bnlCloseApp==true)//式設定日期
	{
		CWnd* hWnd3 = FindWindow(NULL, "Auto Monitor");
		if(hWnd3!=NULL)
			hWnd3->SendMessage(WM_CLOSE,0,0);

	}
	else
	{
		CWnd* hWnd3 = FindWindow(NULL, "Auto Monitor");
		if(hWnd3==NULL)
		ShellExecute(NULL,"open","D:\\Command\\AutoMonitor",NULL,NULL,SW_SHOWNORMAL);
	}
}

void COPenCloseDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CWnd* hWnd3 = FindWindow(NULL, "未命名 - 記事本");
	if(hWnd3==NULL)
	{
		MessageBox("NO Program");
	}
	else
	{
		hWnd3->SendMessage(WM_CLOSE,0,0);
	}
}

void COPenCloseDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CTime t1=CTime::GetCurrentTime(); 
	int Month=t1.GetMonth(); 
	int Day=t1.GetDay();
	int i,a,b;
	bool bnlCloseApp=false;
	for(i=0;i<datanumer;i++)
	{
		a=*(*(GetDay+i)+0);//月
		b=*(*(GetDay+i)+1);//日
		if(a==Month && b==Day)
		{
			bnlCloseApp=true;
			break;
		}
		else
		{
			bnlCloseApp=false;
		}
	}
	if(bnlCloseApp==true)//式設定日期
	{
		CWnd* hWnd3 = FindWindow(NULL, "Auto Monitor");
		if(hWnd3!=NULL)
			hWnd3->SendMessage(WM_CLOSE,0,0);

	}
	else
	{
		CWnd* hWnd3 = FindWindow(NULL, "Auto Monitor");
		if(hWnd3==NULL)
		ShellExecute(NULL,"open","D:\\Command\\AutoMonitor",NULL,NULL,SW_SHOWNORMAL);
	}
/*
	CWnd* hWnd3 = FindWindow(NULL, "未命名 - 記事本");
	if(hWnd3==NULL)
	{
		ShellExecute(NULL,"open","C:\\WINDOWS\\NOTEPAD.EXE",NULL,NULL,SW_SHOWNORMAL);
	}
	else
	{
		hWnd3->SendMessage(WM_CLOSE,0,0);
	}
*/
	CDialog::OnTimer(nIDEvent);
}

BOOL COPenCloseDlg::DestroyWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	delete [] GetDay;
	return CDialog::DestroyWindow();
}
