// Create_mms_htmDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Create_mms_htm.h"
#include "Create_mms_htmDlg.h"
#include<fstream.h>
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
// CCreate_mms_htmDlg dialog

CCreate_mms_htmDlg::CCreate_mms_htmDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreate_mms_htmDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreate_mms_htmDlg)
	m_v1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreate_mms_htmDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreate_mms_htmDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreate_mms_htmDlg, CDialog)
	//{{AFX_MSG_MAP(CCreate_mms_htmDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreate_mms_htmDlg message handlers

BOOL CCreate_mms_htmDlg::OnInitDialog()
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

void CCreate_mms_htmDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreate_mms_htmDlg::OnPaint() 
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
HCURSOR CCreate_mms_htmDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCreate_mms_htmDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	char fg[700];
	FILE *pf;
	pf=fopen("01.htm","a");
	a.open("FileHead.txt",ios::in);
	while(!a.eof())
	{
		a.getline(fg,500);
		fprintf(pf,"%s\n",fg);
	}
	a.close(); 
	fclose(pf);
}

void CCreate_mms_htmDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	FILE *pf;
	pf=fopen("01.htm","a");
	CString StrData;
	StrData="vFileName = ";
	UpdateData(true);
		StrData+=m_v1;
	UpdateData(false);
	fprintf(pf,"%s\n",StrData.GetBuffer(0));
	fclose(pf);

}

void CCreate_mms_htmDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	fstream a;
	char fg[700];
	FILE *pf;
	pf=fopen("01.htm","a");
	a.open("FileRear.txt",ios::in);
	while(!a.eof())
	{
		a.getline(fg,500);
		fprintf(pf,"%s\n",fg);
	}
	a.close(); 
	fclose(pf);	
}

void CCreate_mms_htmDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CString StrFileName;
	CString StrData;
	fstream fslist,a;
	int intcount=0;
	FILE *pf;
	char fg[700];
	char fg1[700];
	fslist.open("list.txt",ios::in);
	while(!fslist.eof())
	{
		//***********************************
		StrData="			vFileName = ";
		fslist.getline(fg,500);
		StrData+=fg;
		//***********************************
		intcount++;
		if(intcount<10)
		{
			StrFileName.Format("htm\\0%d.htm",intcount); 
		}
		else
		{
			StrFileName.Format("htm\\%d.htm",intcount);
		}
		pf=fopen(StrFileName.GetBuffer(0),"w");
		//****************************************
		a.open("FileHead.txt",ios::in);
		while(!a.eof())
		{
			a.getline(fg1,500);
			fprintf(pf,"%s\n",fg1);
		}
		a.close(); 
		//****************************************
		fprintf(pf,"%s\n",StrData.GetBuffer(0));
		//****************************************
		a.open("FileRear.txt",ios::in);
		while(!a.eof())
		{
			a.getline(fg1,500);
			fprintf(pf,"%s\n",fg1);
		}
		a.close();
		//****************************************
		fclose(pf);	
	}
	fslist.close();
	MessageBox("OK");
}
