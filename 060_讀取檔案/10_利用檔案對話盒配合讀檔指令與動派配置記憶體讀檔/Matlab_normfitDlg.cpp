// Matlab_normfitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Matlab_normfit.h"
#include "Matlab_normfitDlg.h"
#include <stdio.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CString Strfilename;
double *douFileData;
int MarrValue;
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
// CMatlab_normfitDlg dialog

CMatlab_normfitDlg::CMatlab_normfitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMatlab_normfitDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMatlab_normfitDlg)
	m_douMean = 0.0;
	m_douSigma = 0.0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMatlab_normfitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMatlab_normfitDlg)
	DDX_Text(pDX, IDC_EDIT1, m_douMean);
	DDX_Text(pDX, IDC_EDIT2, m_douSigma);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMatlab_normfitDlg, CDialog)
	//{{AFX_MSG_MAP(CMatlab_normfitDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMatlab_normfitDlg message handlers

BOOL CMatlab_normfitDlg::OnInitDialog()
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

void CMatlab_normfitDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMatlab_normfitDlg::OnPaint() 
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
HCURSOR CMatlab_normfitDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMatlab_normfitDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	char *chFileName;
	float floBufer;
	FILE *fp;
	///////////////////////////////////////////////
	CFileDialog fdlg(true,NULL,"openfile",NULL,"¤å¦rÀÉ|*.txt");
	if(fdlg.DoModal()==IDOK)
	{
		Strfilename=fdlg.GetPathName();
	}
	chFileName=Strfilename.GetBuffer(0);
	//////////////
	fp=fopen(chFileName,"r");
	MarrValue=0;
	while(fscanf(fp,"%f",&floBufer)!=EOF)
		MarrValue++;
	fclose(fp);
	douFileData=new double[MarrValue];
	fp=fopen(chFileName,"r");
	MarrValue=0;
	while(fscanf(fp,"%f",&floBufer)!=EOF)
	{
		*(douFileData+MarrValue)=floBufer;
		MarrValue++;
	}
	fclose(fp);
	///////////////////////////////////////////
	MessageBox("ÅªÀÉ§¹²¦");
		
}

void CMatlab_normfitDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	//MessageBox("ÅªÀÉ§¹²¦");
	CDialog::OnClose();
}

void CMatlab_normfitDlg::OnOK() 
{
	// TODO: Add extra validation here
	//MessageBox("ÅªÀÉ§¹²¦");
	CDialog::OnOK();
}

void CMatlab_normfitDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	delete [] douFileData;
	// TODO: Add your message handler code here
	
}

void CMatlab_normfitDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	
}
