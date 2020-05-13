// FileWorkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileWork.h"
#include "FileWorkDlg.h"

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
// CFileWorkDlg dialog

CFileWorkDlg::CFileWorkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileWorkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileWorkDlg)
	m_v1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileWorkDlg)
	DDX_Control(pDX, IDC_COMBO2, m_Comb1);
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFileWorkDlg, CDialog)
	//{{AFX_MSG_MAP(CFileWorkDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileWorkDlg message handlers

BOOL CFileWorkDlg::OnInitDialog()
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

void CFileWorkDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFileWorkDlg::OnPaint() 
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
HCURSOR CFileWorkDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CFileWorkDlg::OnButton1() 
{
	
	UpdateData(true);
		pData.strData=m_v1; 
	UpdateData(false);
	AddObject(pData);
}
void CFileWorkDlg::AddObject(CData &g)
{
	gArray.Add(g); 
}

void CFileWorkDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CFile file;
    CFileException fe;
	char* pFileName = "test.jas";
    if(!file.Open(pFileName,CFile::modeCreate | CFile::modeWrite,&fe))
    {
		fe.ReportError();
        return;
    }
	CArchive arc(&file, CArchive::store);
	Serialize(arc);
    arc.Flush();
    arc.Close();
    file.Close();
	gArray.RemoveAll(); 
}

void CFileWorkDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	int i=0;
	CFile file;
    CFileException fe;
	char* pFileName = "test.jas";
    if(!file.Open(pFileName,CFile::modeRead,&fe))
    {
		fe.ReportError();
        return;
    }
	CArchive arc(&file, CArchive::load);
	Serialize(arc);
	int num=gArray.GetSize(); 
	for(i=0;i<num;i++)
	{
		CData d=(gArray[i]);
		m_Comb1.AddString(d.strData);   
	}
	arc.Flush();
    arc.Close();
    file.Close();
}

void CFileWorkDlg::Serialize(CArchive& ar) 
{
	/*
	if (ar.IsStoring())
	{	// storing code
	}
	else
	{	// loading code
	}
	*/
	gArray.Serialize(ar);

}
