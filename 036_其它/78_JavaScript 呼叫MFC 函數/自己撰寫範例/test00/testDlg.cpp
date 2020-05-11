// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"


#include <atlbase.h>//modify by jash

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
// CTestDlg dialog

CTestDlg::CTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pIHTMLDoc		= NULL;//modify by jash
}
CTestDlg::~CTestDlg()//modify by jash
{

}
void CTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_wndWeb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlg message handlers

BOOL CTestDlg::OnInitDialog()
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
	CHAR		szPath[MAX_PATH];//modify by jash
	memset(szPath, 0, sizeof(CHAR)*MAX_PATH);//modify by jash
	GetCurrentDirectory(MAX_PATH, szPath);//modify by jash
	StrCat(szPath, _T("\\Custom.html"));//modify by jash
	m_wndWeb.Navigate(szPath, NULL, NULL, NULL, NULL);//modify by jash	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestDlg::OnPaint() 
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
HCURSOR CTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CTestDlg::InvokeFunc()//modify by jash
{
	MessageBox(_T("MFC MessageBox"));
}

void CTestDlg::InvokeFuncWithParams(const CString& strParam1, int iParam2)
{
	CString		str;
	str.Format("MFC String01:%s\nMFC String02:%d", strParam1, iParam2);
	MessageBox(str);
}

void CTestDlg::InvokeFuncAdd(int iParam1, int iParam2)
{

	CString		strResult;
	IHTMLWindow2*			pIHTMLWindow	= NULL;
	HRESULT					hr				= NOERROR;
	VARIANT					pvarRet;
	strResult.Format("fnSetText(\"%d\")", iParam1+iParam2);
	if(m_pIHTMLDoc)
	{
		m_pIHTMLDoc->get_parentWindow(&pIHTMLWindow);
		if(pIHTMLWindow)
		{
			hr = pIHTMLWindow->execScript(CComBSTR(strResult), CComBSTR("JScript"), &pvarRet);
			pIHTMLWindow->Release();
			pIHTMLWindow = NULL;
		}
	}

}

void CTestDlg::ShowModalDlg(const CString& strCaption, const CRect& rcPos)
{
	MessageBox(strCaption);
	CString StrBuf; 
	StrBuf.Format("Top=%d\nBottom=%d",rcPos.top,rcPos.bottom);
	MessageBox(StrBuf);
}

void CTestDlg::ShowModalLessDlg(const CString& strCaption, const CRect& rcPos)
{
	MessageBox(strCaption);
	CString StrBuf; 
	StrBuf.Format("right=%d\nleft=%d",rcPos.right,rcPos.left);
	MessageBox(StrBuf);
}

BEGIN_EVENTSINK_MAP(CTestDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CTestDlg)
	ON_EVENT(CTestDlg, IDC_EXPLORER1, 259 /* DocumentComplete */, OnDocumentCompleteExplorer1, VTS_DISPATCH VTS_PVARIANT)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CTestDlg::OnDocumentCompleteExplorer1(LPDISPATCH pDisp, VARIANT FAR* URL) 
{
	// TODO: Add your control notification handler code here
	IDispatch*				pIDisp			= NULL;
	pIDisp = m_wndWeb.GetDocument();
	if(pIDisp)
	{
		if(m_pIHTMLDoc)
		{
			m_pIHTMLDoc->Release();
			m_pIHTMLDoc = NULL;
		}
		pIDisp->QueryInterface(IID_IHTMLDocument2, (void**)&m_pIHTMLDoc);
		pIDisp->Release();
		pIDisp = NULL;
	}	
}

void CTestDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pIHTMLDoc)
	{
		m_pIHTMLDoc->Release();
		m_pIHTMLDoc = NULL;
	}	
	CDialog::OnClose();
}
