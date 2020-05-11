// zipdlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "zipdlg.h"
#include "zipdlgDlg.h"

#include "czip.h"

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
// CZipdlgDlg dialog

CZipdlgDlg::CZipdlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CZipdlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CZipdlgDlg)
	m_newfilename = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CZipdlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CZipdlgDlg)
	DDX_Text(pDX, IDC_NEWFILENAME, m_newfilename);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CZipdlgDlg, CDialog)
	//{{AFX_MSG_MAP(CZipdlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BROWSEFILEFORZIP, OnBrowsefileforzip)
	ON_BN_CLICKED(IDC_ZIPIT, OnZipit)
	ON_BN_CLICKED(IDC_EXTRACT, OnExtract)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CZipdlgDlg message handlers

BOOL CZipdlgDlg::OnInitDialog()
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

void CZipdlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CZipdlgDlg::OnPaint() 
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
HCURSOR CZipdlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CZipdlgDlg::OnBrowsefileforzip() 
{
	CFileDialog fd( TRUE , NULL,NULL,OFN_HIDEREADONLY,"All file (*.*)|*.*||");
	if (fd.DoModal())
	{
		SetDlgItemText(IDC_FILEFORZIP,fd.GetPathName());
		CString fzip;
		fzip.Format("%s.zip",fd.GetFileTitle());
		SetDlgItemText(IDC_FILEZIP,fzip);
	}
}

void CZipdlgDlg::OnZipit() 
{
	try{
		char fileforzip[100],filezip[100];
		GetDlgItemText(IDC_FILEFORZIP,fileforzip,100);
		GetDlgItemText(IDC_FILEZIP,filezip,100);

		CZip oZip( fileforzip );
		oZip.SwapSize( filezip );
		MessageBox("OK. Zip successfull");
	}
	catch( CZipException e )
	{
		CString s;
		s.Format("%s",e.GetString());
		MessageBox(s);
	}
}


void CZipdlgDlg::OnOK() 
{
	CFileDialog fd( TRUE , NULL,NULL,OFN_HIDEREADONLY,"Zip file (*.zip)|*.zip||");
	if (fd.DoModal()==IDOK)
	{
		SetDlgItemText(IDC_FILEFORUNZIP,fd.GetPathName());
	}
}

void CZipdlgDlg::OnExtract() 
{
	UpdateData(TRUE);
	if (m_newfilename=="")
	{
		MessageBox("input file name pls!");
	}else{
		try{
			char fileforunzip[100],newfile[100];
			GetDlgItemText(IDC_FILEFORUNZIP,fileforunzip,100);
			GetDlgItemText(IDC_NEWFILENAME,newfile,100);

			CUnzip oUnzip( fileforunzip );
			oUnzip.SwapSize( newfile );
		}
		catch( CZipException e )
		{
			CString s;
			s.Format("%s",e.GetString());
			MessageBox(s);
		}
	}
	
}
