// test_createXMLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_createXML.h"
#include "test_createXMLDlg.h"

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
// CTest_createXMLDlg dialog

CTest_createXMLDlg::CTest_createXMLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_createXMLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_createXMLDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_createXMLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_createXMLDlg)

	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_createXMLDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_createXMLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_createXMLDlg message handlers

BOOL CTest_createXMLDlg::OnInitDialog()
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

void CTest_createXMLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_createXMLDlg::OnPaint() 
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
HCURSOR CTest_createXMLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_createXMLDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMElementPtr xmlRoot;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
		MessageBox("Error");
		return;
	}
	//根節點的名稱為Book
	//創建元素並添加到文檔中
	xmlRoot=pDoc->createElement((_bstr_t)"Book");
	//設置屬性
	xmlRoot->setAttribute("id",(const char *)"bk101");
	pDoc->appendChild(xmlRoot);
	MSXML2::IXMLDOMElementPtr pNode;
	//添加"author"元素
	pNode=pDoc->createElement((_bstr_t)"Author");
	pNode->Puttext((_bstr_t)(const char *)"Lizlex");
	xmlRoot->appendChild(pNode);
 
	//添加"Title"元素
	pNode=pDoc->createElement("Title");
	pNode->Puttext((const char *)"Xml User");
	xmlRoot->appendChild(pNode);
 
	//保存到檔 
	//如果不存在就建立,存在就覆蓋 
	pDoc->save("d:\\he.xml");
MessageBox("OK");	
}

void CTest_createXMLDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
//FILE *fp;
//fp=fopen("text.txt","w");
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   MessageBox("Error!");
	   return;
	}
	pDoc->load("d:\\he.xml"); 
 
	MSXML2::IXMLDOMNodePtr  pNode;
 
	//在樹中查找名為Book的節點,"//"表示在任意一層查找 
	pNode=pDoc->selectSingleNode("//Book");
	MSXML2::DOMNodeType nodeType; 
 
	//得到節點類型 
	pNode->get_nodeType(&nodeType); 
 
	//節點名稱 
	CString strName; 
	strName=(char *)pNode->GetnodeName();
	MessageBox(strName);
	//節點屬性,放在鏈表中 
	MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap=NULL;
	MSXML2::IXMLDOMNodePtr   pAttrItem;
	_variant_t variantValue;
	pNode->get_attributes(&pAttrMap);

	long count;
	count=pAttrMap->get_length(&count);
 
	pAttrMap->get_item(0,&pAttrItem);
	//取得節點的值
	pAttrItem->get_nodeTypedValue(&variantValue);
	CString m_strId;
	m_strId=(char *)(_bstr_t)variantValue;
	MessageBox(m_strId);
	MessageBox("OK");
}

void CTest_createXMLDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   MessageBox("Error!");
	   return;
	}
	pDoc->load("d:\\he.xml"); 
 
	MSXML2::IXMLDOMNodePtr  pNode;
 
	//在樹中查找名為Book的節點,"//"表示在任意一層查找 
	pNode=pDoc->selectSingleNode("//Author");
	MSXML2::DOMNodeType nodeType; 
	//得到節點類型 
	pNode->get_nodeType(&nodeType); 
 
	//節點名稱 
	CString strName; 
	strName=(char *)pNode->GetnodeName();
	MessageBox(strName);
	
	_variant_t vtStr;
	CString strValue;
	pNode->get_nodeTypedValue(&vtStr);  
	strValue=vtStr.bstrVal; 
	MessageBox(strValue);
	MessageBox("OK");
}

void CTest_createXMLDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   MessageBox("Error!");
	   return;
	}
	pDoc->load("d:\\he.xml"); 
 
	MSXML2::IXMLDOMNodePtr  pNode;
 
	//在樹中查找名為Book的節點,"//"表示在任意一層查找 
	pNode=pDoc->selectSingleNode("//Title");
	MSXML2::DOMNodeType nodeType; 
 
	//得到節點類型 
	pNode->get_nodeType(&nodeType); 
 
	//節點名稱 
	CString strName; 
	strName=(char *)pNode->GetnodeName();
	MessageBox(strName);
	
	_variant_t vtStr;
	CString strValue;
	pNode->get_nodeTypedValue(&vtStr);  
	strValue=vtStr.bstrVal; 
	MessageBox(strValue);
	MessageBox("OK");	
}

void CTest_createXMLDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMElementPtr xmlRoot;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
		MessageBox("Error");
		return;
	}
	pDoc->load("d:\\he.xml"); 
	xmlRoot=pDoc->selectSingleNode("//Book");
	MSXML2::DOMNodeType nodeType; 
	//得到節點類型 
	xmlRoot->get_nodeType(&nodeType); 
	//節點名稱 
	CString strName; 
	strName=(char *)xmlRoot->GetnodeName();
	MessageBox(strName);

	MSXML2::IXMLDOMElementPtr pNode;
	//添加"author"元素
	pNode=pDoc->createElement((_bstr_t)"測試1");
	pNode->Puttext((_bstr_t)(const char *)"test");
	xmlRoot->appendChild(pNode);
	pDoc->save("d:\\he.xml");
	MessageBox("OK");
}

void CTest_createXMLDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMElementPtr xmlRoot;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
		MessageBox("Error");
		return;
	}
	pDoc->load("d:\\he.xml"); 
	xmlRoot=pDoc->selectSingleNode("//測試1");
	MSXML2::DOMNodeType nodeType; 
	//得到節點類型 
	xmlRoot->get_nodeType(&nodeType); 
	//節點名稱 
	CString strName; 
	strName=(char *)xmlRoot->GetnodeName();
	MessageBox(strName);

	_variant_t vtStr;
	CString strValue;
	xmlRoot->get_nodeTypedValue(&vtStr);  
	strValue=vtStr.bstrVal; 
	MessageBox(strValue);
	xmlRoot->put_text((_bstr_t)(const char *)"200"); 
	pDoc->save("d:\\he.xml");
	MessageBox("OK");	
}
