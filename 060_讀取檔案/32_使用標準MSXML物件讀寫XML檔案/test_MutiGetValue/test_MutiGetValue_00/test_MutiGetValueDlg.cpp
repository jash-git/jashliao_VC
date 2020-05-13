// test_MutiGetValueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_MutiGetValue.h"
#include "test_MutiGetValueDlg.h"

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
// CTest_MutiGetValueDlg dialog

CTest_MutiGetValueDlg::CTest_MutiGetValueDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_MutiGetValueDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_MutiGetValueDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_MutiGetValueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_MutiGetValueDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_MutiGetValueDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_MutiGetValueDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_MutiGetValueDlg message handlers

BOOL CTest_MutiGetValueDlg::OnInitDialog()
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

void CTest_MutiGetValueDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_MutiGetValueDlg::OnPaint() 
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
HCURSOR CTest_MutiGetValueDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_MutiGetValueDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	SetTimer(1,5000,NULL);
}

void CTest_MutiGetValueDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	SetTimer(2,5000,NULL);
}

void CTest_MutiGetValueDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   MessageBox("Error!");
	   return;
	}
	pDoc->load("test.xml"); 
	CString strName1;
	CString strName2;
	CString strName3;
	_variant_t vtStr;
	//CString strValue;
	MSXML2::IXMLDOMNodePtr  pNode1;
	MSXML2::IXMLDOMNodePtr  pNode2;
	MSXML2::IXMLDOMNodePtr  pNode3;
	MSXML2::DOMNodeType nodeType1;
	MSXML2::DOMNodeType nodeType2;
	MSXML2::DOMNodeType nodeType3;
	//////////////////////////////////////////////////////
	pNode1=pDoc->selectSingleNode("//Message1/value");
	pNode1->get_nodeType(&nodeType1); 
	strName1=(char *)pNode1->GetnodeName();
	pNode1->get_nodeTypedValue(&vtStr);
	strName1=vtStr.bstrVal;
	//MessageBox(strName1);
	//////////////////////////////////////////////////////
	pNode2=pDoc->selectSingleNode("//Message2/value");
	pNode2->get_nodeType(&nodeType2); 
	strName2=(char *)pNode2->GetnodeName();
	pNode2->get_nodeTypedValue(&vtStr);
	strName2=vtStr.bstrVal;
	//MessageBox(strName2);
	//////////////////////////////////////////////////////
	pNode3=pDoc->selectSingleNode("//Message3/value");
	pNode3->get_nodeType(&nodeType3); 
	strName3=(char *)pNode3->GetnodeName();
	pNode3->get_nodeTypedValue(&vtStr);
	strName3=vtStr.bstrVal;
	//MessageBox(strName3);
	switch(nIDEvent)
	{
	case 1:
		MessageBox(strName1);
		MessageBox(strName2);
		MessageBox(strName3);
		break;
	case 2:
		MessageBox(strName3);
		MessageBox(strName2);
		MessageBox(strName1);
		break;
	}
	CDialog::OnTimer(nIDEvent);
}
