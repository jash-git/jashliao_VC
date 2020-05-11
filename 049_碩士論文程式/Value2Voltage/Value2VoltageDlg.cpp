// Value2VoltageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Value2Voltage.h"
#include "Value2VoltageDlg.h"
#include <stdio.h>
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
// CValue2VoltageDlg dialog

CValue2VoltageDlg::CValue2VoltageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CValue2VoltageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CValue2VoltageDlg)
	m_v1 = _T("Âà´«");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CValue2VoltageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CValue2VoltageDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CValue2VoltageDlg, CDialog)
	//{{AFX_MSG_MAP(CValue2VoltageDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnInt2Vol)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CValue2VoltageDlg message handlers

BOOL CValue2VoltageDlg::OnInitDialog()
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

void CValue2VoltageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CValue2VoltageDlg::OnPaint() 
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
HCURSOR CValue2VoltageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CValue2VoltageDlg::OnInt2Vol() 
{
	// TODO: Add your control notification handler code here
	FILE *r1,*r2,*r3,*w1,*w2,*w3;
	double Tovalue;
	int Getvalue;
	char *head;
	CString a[3];
	////////////////////////////////////////
	UpdateData(true);
	head=m_v1.GetBuffer(0);
	a[0]="0.txt";
	a[1]="1.txt";
	a[2]="2.txt";
	a[0]=head+a[0];
	a[1]=head+a[1];
	a[2]=head+a[2];
		///////////////////////////////
	head=a[0].GetBuffer(0);
	w1=fopen(head,"w");
	head=a[1].GetBuffer(0);
	w2=fopen(head,"w");
	head=a[2].GetBuffer(0);
	w3=fopen(head,"w");
		//////////////////////////////
	UpdateData(false);
	////////////////////////////////////////
	r1=fopen("aV1.txt","r");
	r2=fopen("aV2.txt","r");
	r3=fopen("aV3.txt","r");
	
	while(fscanf(r1,"%d",&Getvalue)!=EOF)
	{
		Tovalue=(2.5*(double)Getvalue)/(double)32768;
		fprintf(w1,"%f\n",Tovalue);
	}
	while(fscanf(r2,"%d",&Getvalue)!=EOF)
	{
		Tovalue=(2.5*(double)Getvalue)/(double)32768;
		fprintf(w2,"%f\n",Tovalue);
	}
	while(fscanf(r3,"%d",&Getvalue)!=EOF)
	{
		Tovalue=(2.5*(double)Getvalue)/(double)32768;
		fprintf(w3,"%f\n",Tovalue);
	}
	MessageBox("Âà´«§¹²¦");
	fclose(w1);
	fclose(r1);
	fclose(w2);
	fclose(r2);
	fclose(w3);
	fclose(r3);
}
