// InternetFileDownLoadDlg.cpp : implementation file
//

#include "stdafx.h"
#include "InternetFileDownLoad.h"
#include "InternetFileDownLoadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CInternetSession *session;
CInternetFile *file = NULL;
long number;
long size;
unsigned char *data;
long lngsurplus;
bool blnsurplus;
long lngcount;
long lngNowPos;
CString s1;
long fsize;
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
// CInternetFileDownLoadDlg dialog

CInternetFileDownLoadDlg::CInternetFileDownLoadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CInternetFileDownLoadDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInternetFileDownLoadDlg)
	m_v1 = _T("");
	m_v2 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CInternetFileDownLoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInternetFileDownLoadDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CInternetFileDownLoadDlg, CDialog)
	//{{AFX_MSG_MAP(CInternetFileDownLoadDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInternetFileDownLoadDlg message handlers

BOOL CInternetFileDownLoadDlg::OnInitDialog()
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

void CInternetFileDownLoadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CInternetFileDownLoadDlg::OnPaint() 
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
HCURSOR CInternetFileDownLoadDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CInternetFileDownLoadDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here

	try
	{
		UpdateData(true);
			session=new CInternetSession (AfxGetAppName(),1, PRE_CONFIG_INTERNET_ACCESS); 
			file = (CInternetFile*) session->OpenURL(m_v1);
		UpdateData(false);
		//***********************************
		size=10240;//10Kbyte
		fsize=file->GetLength(); 
		number=fsize/size;
		data=new unsigned char [size];
		blnsurplus=false;
		if(fsize>(size*number))
		{
			blnsurplus=true;
			lngsurplus=fsize-(size*number);
			number++;
			lngcount=0;
			lngNowPos=0;
		}
		//************************************
		s1.Format("開始下載_共%d的檔案",number); 
		MessageBox(s1);
		SetTimer(1,2000,NULL);
	}
	catch (CInternetException* m_pException)
	{
		file = NULL; 
		m_pException->Delete();
	}	
}

void CInternetFileDownLoadDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	CFile f2;
	if(lngcount<number)
	{
		s1.Format("%d.jash",lngcount);
		//MessageBox(s1);
		f2.Open(s1,CFile::modeCreate|CFile::modeWrite); 
		memset(data,'\0',size);
		lngNowPos=lngcount*size;
		file->Seek((lngcount*size),CFile::begin);
		if((lngNowPos+size)>fsize)
		{
			//
			file->Read(data,lngsurplus);
			f2.Write(data,lngsurplus);
		}
		else
		{
			//
			file->Read(data,size);
			f2.Write(data,size);
		}
		f2.Close();
		lngcount++;
		SetTimer(1,2000,NULL);
	}
	else
	{
		MessageBox("下載完成");
	}
	CDialog::OnTimer(nIDEvent);
}

void CInternetFileDownLoadDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CFile f1,f2;
	UpdateData(true);
		f2.Open(m_v2,CFile::modeCreate|CFile::modeWrite); 
	UpdateData(false);
	for(int i=0;i<number;i++)
	{
		memset(data,'\0',size);
		s1.Format("%d.jash",i);
		f1.Open(s1,CFile::modeRead);
		size=f1.GetLength(); 
		f1.Read(data,size);
		f2.Write(data,size);
		f1.Close();
		DeleteFile(s1);
	}
	f2.Close();
	delete []data;
	MessageBox("組合完成");
}
