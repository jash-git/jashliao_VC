// test_MFC_WebserviceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_MFC_Webservice.h"
#include "test_MFC_WebserviceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
using namespace TService;//Step 1
using namespace Web_ValidEmail;//Step 1
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Ctest_MFC_WebserviceDlg dialog




Ctest_MFC_WebserviceDlg::Ctest_MFC_WebserviceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(Ctest_MFC_WebserviceDlg::IDD, pParent)
	, m_value(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctest_MFC_WebserviceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_value);
}

BEGIN_MESSAGE_MAP(Ctest_MFC_WebserviceDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &Ctest_MFC_WebserviceDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Ctest_MFC_WebserviceDlg message handlers

BOOL Ctest_MFC_WebserviceDlg::OnInitDialog()
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

void Ctest_MFC_WebserviceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Ctest_MFC_WebserviceDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ctest_MFC_WebserviceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void Ctest_MFC_WebserviceDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CoInitialize(NULL);
	/*
	TranslateService TranService;
	String ^Str1="Hello,world!";
	String ^StrResult;
	Language Lan=Language::EnglishTOChinese; 
	StrResult=TranService.Translate(Lan,Str1);
	*/
	UpdateData(true);
	ValidateEmail ValidateEmail1;
	//String ^Str1="jash@gmail.com";
	CString m_Strv1;
	String ^Str1;
	//m_Strv1=m_value;
	Str1= gcnew String (m_value);
	BOOL  blnResult;
	blnResult=ValidateEmail1.IsValidEmail(Str1);
	if(blnResult)
	{
		MessageBox("OK");
	}
	else
	{
		MessageBox("KO");
	}
	m_Strv1=Str1;
	MessageBox(m_Strv1);
	CoUninitialize();
}
