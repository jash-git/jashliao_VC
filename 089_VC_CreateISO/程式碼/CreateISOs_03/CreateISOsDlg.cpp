// CreateISOsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateISOs.h"
#include "CreateISOsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
long glngHead=0;
CString gStrHead;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
long i;
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
// CCreateISOsDlg dialog

CCreateISOsDlg::CCreateISOsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateISOsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateISOsDlg)
	m_CStrSou = _T("");
	m_CStrISO = _T("");
	m_lngCount = 0;
	m_lngNow = 0;
	m_StrHead = _T("");
	m_lngHead = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateISOsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateISOsDlg)
	DDX_Text(pDX, IDC_EDIT1, m_CStrSou);
	DDX_Text(pDX, IDC_EDIT2, m_CStrISO);
	DDX_Text(pDX, IDC_EDIT3, m_lngCount);
	DDX_Text(pDX, IDC_EDIT4, m_lngNow);
	DDX_Text(pDX, IDC_EDIT5, m_StrHead);
	DDX_Text(pDX, IDC_EDIT6, m_lngHead);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateISOsDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateISOsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnCreate)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateISOsDlg message handlers

BOOL CCreateISOsDlg::OnInitDialog()
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

void CCreateISOsDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreateISOsDlg::OnPaint() 
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
HCURSOR CCreateISOsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCreateISOsDlg::OnCreate() 
{
	// TODO: Add your control notification handler code here
	/*
	long i;
	FILE *pf;
	i=1;
	CString StrData;
	UpdateData(true);
	for(i=1;i<=m_lngCount;i++)
	{
		pf=fopen("miso.bat","w");
		//MISO d:\test.iso -a C:\WowTV_USB5tv_13_5_X_1\* -l WOWTV
		if(i<10)
		{
			StrData.Format("miso.exe %s\\000%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		else if(i<100)
		{
			StrData.Format("miso.exe %s\\00%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		else if(i<1000)
		{
			StrData.Format("miso.exe %s\\0%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		else
		{
			StrData.Format("miso.exe %s\\%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		fprintf(pf,"%s",StrData.GetBuffer(0)); 
		fclose(pf);
		pf=NULL;
		ShellExecute(NULL,"open","miso.bat",NULL,NULL,SW_MINIMIZE);
		m_lngNow=i;
		UpdateData(false);
		Sleep(1000);
	}
	MessageBox("Create ISO OK");
	*/
	UpdateData(true);
	glngHead=m_lngHead;
	gStrHead=m_StrHead;
	i=1;
	SetTimer(1,1000,NULL);
}

void CCreateISOsDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CString str;
	BROWSEINFO bi;
	char name[MAX_PATH];
	ZeroMemory(&bi,sizeof(BROWSEINFO));
	bi.hwndOwner=GetSafeHwnd();
	bi.pszDisplayName=name;
	bi.lpszTitle="Select folder";
	//bi.ulFlags=BIF_BROWSEINCLUDEURLS;
	LPITEMIDLIST idl=SHBrowseForFolder(&bi);
	if(idl==NULL)
		return;
	SHGetPathFromIDList(idl,str.GetBuffer(MAX_PATH));
	str.ReleaseBuffer();
	m_CStrSou=str;
	UpdateData(false);	
}

void CCreateISOsDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CString str;
	BROWSEINFO bi;
	char name[MAX_PATH];
	ZeroMemory(&bi,sizeof(BROWSEINFO));
	bi.hwndOwner=GetSafeHwnd();
	bi.pszDisplayName=name;
	bi.lpszTitle="Select folder";
	//bi.ulFlags=BIF_BROWSEINCLUDEURLS;
	LPITEMIDLIST idl=SHBrowseForFolder(&bi);
	if(idl==NULL)
		return;
	SHGetPathFromIDList(idl,str.GetBuffer(MAX_PATH));
	str.ReleaseBuffer();
	m_CStrISO=str;
	UpdateData(false);
}

void CCreateISOsDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	FILE *pf,*pf1,*pf2;
	CString StrData;
	CString StrSrlNumFilePath;
	CString StrKeyData;
	if(i<=m_lngCount)
	{
		StrSrlNumFilePath=m_CStrSou+"\\SrlNum.dll";
		pf1=fopen(StrSrlNumFilePath.GetBuffer(0),"w");
		if(pf1!=NULL)
		{
			if(glngHead<10)
			{
				StrKeyData.Format("%s00000%d",gStrHead.GetBuffer(0),glngHead);  
			}
			else if(glngHead<100)
			{
				StrKeyData.Format("%s0000%d",gStrHead.GetBuffer(0),glngHead);
			}
			else if(glngHead<1000)
			{
				StrKeyData.Format("%s000%d",gStrHead.GetBuffer(0),glngHead);
			}
			else if(glngHead<10000)
			{
				StrKeyData.Format("%s00%d",gStrHead.GetBuffer(0),glngHead);
			}
			else if(glngHead<100000)
			{
				StrKeyData.Format("%s0%d",gStrHead.GetBuffer(0),glngHead);
			}
			else
			{
				StrKeyData.Format("%s%d",gStrHead.GetBuffer(0),glngHead);
			}
			fprintf(pf1,"%s",StrKeyData.GetBuffer(0)); 
			fclose(pf1);
			pf1=NULL;
			pf2=fopen("log.txt","a");
			fprintf(pf2,"%s\n",StrKeyData.GetBuffer(0));
			fclose(pf2);
			pf2=NULL;
			glngHead++;
		}
		pf=fopen("miso.bat","w");
		//MISO d:\test.iso -a C:\WowTV_USB5tv_13_5_X_1\* -l WOWTV
		if(i<10)
		{
			StrData.Format("miso.exe %s\\000%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		else if(i<100)
		{
			StrData.Format("miso.exe %s\\00%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		else if(i<1000)
		{
			StrData.Format("miso.exe %s\\0%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		else
		{
			StrData.Format("miso.exe %s\\%d.iso -a %s\\* -l WOWTV",m_CStrISO.GetBuffer(0),i,m_CStrSou.GetBuffer(0));
		}
		fprintf(pf,"%s",StrData.GetBuffer(0)); 
		fclose(pf);
		pf=NULL;
		ShellExecute(NULL,"open","miso.bat",NULL,NULL,SW_MINIMIZE);
		m_lngNow=i;
		i++;
		UpdateData(false);
	}
	else
	{
		KillTimer(1);
		MessageBox("Create ISO OK");
	}
	CDialog::OnTimer(nIDEvent);
}
