// ReadMultiLevelXMLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ReadMultiLevelXML.h"
#include "ReadMultiLevelXMLDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR gstrCurDrt[500];//存放目其目錄字串
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
// CReadMultiLevelXMLDlg dialog

CReadMultiLevelXMLDlg::CReadMultiLevelXMLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReadMultiLevelXMLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReadMultiLevelXMLDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CReadMultiLevelXMLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReadMultiLevelXMLDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CReadMultiLevelXMLDlg, CDialog)
	//{{AFX_MSG_MAP(CReadMultiLevelXMLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReadMultiLevelXMLDlg message handlers

BOOL CReadMultiLevelXMLDlg::OnInitDialog()
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

	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CReadMultiLevelXMLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CReadMultiLevelXMLDlg::OnPaint() 
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
HCURSOR CReadMultiLevelXMLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CReadMultiLevelXMLDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;//宣告XML物件
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));//建立XML物件
	if(!SUCCEEDED(hr))
	{
	   return;
	}

	_variant_t vtStr;//存放Node資料
	CString StrBuff;	
	int i,j;
	int k,l;
	int m,n;
	bool blnRead=false;
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="test.xml";//建立XML檔案路徑
	MSXML2::IXMLDOMNodeListPtr pNodeListwork;//XML list Node物件
	MSXML2::IXMLDOMNodeListPtr pNodeListfile;//XML list Node物件
	MSXML2::IXMLDOMNodeListPtr pNodeListsmil;//XML list Node物件
	MSXML2::IXMLDOMNodePtr pNodeRoot;//XML Node物件
	MSXML2::IXMLDOMNodePtr pNodework_id;//XML Node物件
	MSXML2::IXMLDOMNodePtr pNodesource_path;//XML Node物件
	MSXML2::IXMLDOMNodePtr pNodestorage_path;//XML Node物件
	MSXML2::IXMLDOMNodePtr pNodefilename;//XML Node物件
	MSXML2::IXMLDOMNodePtr pNodedestination_filename;
	blnRead=pDoc->load((_bstr_t)strFileName1); //載入XML
	if(blnRead)//第11.0版的功能
	{
		//抓根節點
		pNodeRoot=pDoc->selectSingleNode("//works");//取得Node內容
		//將所有子節點放到list中
		pNodeRoot->get_childNodes(&pNodeListwork);
		j=pNodeListwork->length;
		for(i=0;i<j;i++)
		{
			MSXML2::IXMLDOMNodePtr pNodeBuf;
			pNodeListwork->get_item(i,&pNodeBuf);
			pNodework_id=pNodeBuf->selectSingleNode("work_id");
			pNodework_id->get_nodeTypedValue(&vtStr);
			StrBuff=vtStr.bstrVal;
			//
			pNodesource_path=pNodeBuf->selectSingleNode("source_path");
			pNodesource_path->get_nodeTypedValue(&vtStr);
			StrBuff=vtStr.bstrVal;
			//
			pNodestorage_path=pNodeBuf->selectSingleNode("storage_path");
			pNodestorage_path->get_nodeTypedValue(&vtStr);
			StrBuff=vtStr.bstrVal;
			//
			//抓次根節點，重點在於開頭不能加上雙斜線否則會搜尋全域
			pNodeListfile=pNodeBuf->selectNodes("videofiles//file");
			l=pNodeListfile->length;
			for(k=0;k<l;k++)
			{
				//搜尋子節點
				MSXML2::IXMLDOMNodePtr pNodeBuf01;
				pNodeListfile->get_item(k,&pNodeBuf01);
				pNodefilename=pNodeBuf01->selectSingleNode("filename");
				pNodefilename->get_nodeTypedValue(&vtStr);
				StrBuff=vtStr.bstrVal;
			}
			//
			//抓次根節點，重點在於開頭不能加上雙斜線否則會搜尋全域
			pNodeListsmil=pNodeBuf->selectNodes("smils//smil");
			n=pNodeListsmil->length;
			for(m=0;m<n;m++)
			{
				//搜尋子節點
				MSXML2::IXMLDOMNodePtr pNodeBuf02;
				pNodeListsmil->get_item(m,&pNodeBuf02);
				pNodedestination_filename=pNodeBuf02->selectSingleNode("destination_filename");
				pNodedestination_filename->get_nodeTypedValue(&vtStr);
				StrBuff=vtStr.bstrVal;
			}
		}
	}
}
