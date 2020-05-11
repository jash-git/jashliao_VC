// combox_controlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "combox_control.h"
#include "combox_controlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
FILE *pf;
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
// CCombox_controlDlg dialog

CCombox_controlDlg::CCombox_controlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCombox_controlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCombox_controlDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCombox_controlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCombox_controlDlg)
	DDX_Control(pDX, IDC_CHECK8, m_combox8);
	DDX_Control(pDX, IDC_CHECK7, m_combox7);
	DDX_Control(pDX, IDC_CHECK6, m_combox6);
	DDX_Control(pDX, IDC_CHECK4, m_combox4);
	DDX_Control(pDX, IDC_CHECK5, m_combox5);
	DDX_Control(pDX, IDC_CHECK3, m_combox3);
	DDX_Control(pDX, IDC_CHECK2, m_combox2);
	DDX_Control(pDX, IDC_CHECK1, m_combox1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCombox_controlDlg, CDialog)
	//{{AFX_MSG_MAP(CCombox_controlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCombox_controlDlg message handlers

BOOL CCombox_controlDlg::OnInitDialog()
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
	m_Array1.RemoveAll();
	pf=fopen("data.txt","w");
	BrowseDir("f:\\");
	fclose(pf);
	m_combox1.SetWindowText(m_Array1.GetAt(0));
	m_combox2.SetWindowText(m_Array1.GetAt(1));
	m_combox3.SetWindowText(m_Array1.GetAt(2));
	m_combox4.SetWindowText(m_Array1.GetAt(3));
	m_combox5.SetWindowText(m_Array1.GetAt(4));
	m_combox6.SetWindowText(m_Array1.GetAt(5));
	m_combox7.SetWindowText(m_Array1.GetAt(6));
	m_combox8.SetWindowText(m_Array1.GetAt(7));
	/*
	m_combox1.SetCheck(1);
	m_combox2.SetCheck(!m_combox1.GetCheck()); 
	m_combox3.SetCheck(1);
	m_combox4.SetCheck(!m_combox1.GetCheck()); 
	m_combox5.SetCheck(1);
	m_combox6.SetCheck(!m_combox1.GetCheck()); 
	m_combox7.SetCheck(1);
	m_combox8.SetCheck(!m_combox1.GetCheck());
	*/
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCombox_controlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCombox_controlDlg::OnPaint() 
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
HCURSOR CCombox_controlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CCombox_controlDlg::BrowseDir(CString strDir)
{
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			//�蝚偶禤ぃ�
			BrowseDir(ff.GetFilePath());
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			//為檔案
			CString str;
			int result;
			char *chrall;
			char chrname[100];
			char chrtype[10];
			CString StrFileName;
			CString StrFileType;
			StrFileName=ff.GetFileName();
			chrall=StrFileName.GetBuffer(0);
			result = sscanf(chrall,"%[^'.'].%s",chrname,chrtype);
			StrFileType=chrtype;
			StrFileType.MakeLower();
			if(StrFileType=="rmvb"||StrFileType=="rm"||StrFileType=="wmv"||StrFileType=="avi")
			{
				str.Format("目前檔案%s",ff.GetFilePath());
				m_Array1.Add(ff.GetFilePath());
				fprintf(pf,"%s\n",ff.GetFilePath());
			}
			//Sleep(500);
		}
	}
	ff.Close();//關閉
}