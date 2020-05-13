// test_msxml4Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_msxml4.h"
#include "test_msxml4Dlg.h"

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
// CTest_msxml4Dlg dialog

CTest_msxml4Dlg::CTest_msxml4Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_msxml4Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_msxml4Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_msxml4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_msxml4Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_msxml4Dlg, CDialog)
	//{{AFX_MSG_MAP(CTest_msxml4Dlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_msxml4Dlg message handlers

BOOL CTest_msxml4Dlg::OnInitDialog()
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

void CTest_msxml4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_msxml4Dlg::OnPaint() 
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
HCURSOR CTest_msxml4Dlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_msxml4Dlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
  int   i,k;   
  CString   name,value;   
  MSXML2::IXMLDOMDocumentPtr   pxmldom;   
  MSXML2::IXMLDOMNodeListPtr   pnl;   
  MSXML2::IXMLDOMNodePtr   pnode; 
  MSXML2::IXMLDOMNodePtr   Data; 
  HRESULT hr = pxmldom.CreateInstance(__uuidof(MSXML2::DOMDocument30));
  if(!SUCCEEDED(hr))
  {
	  MessageBox("Error!");
	  return;
  }
  pxmldom->load("SignageConfig.xml");
  pnl=pxmldom->selectNodes("//program");  //selectnodes("//program");
  CString strName;
  CString m_strId;
  k=pnl->length;
  for(i=0;i<k;i++)   
  {   
    pnode=pnl->item[i]; 
	strName=(char *)pnode->GetnodeName();
	//節點屬性,放在鏈表中 
	MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap=NULL;
	MSXML2::IXMLDOMNodePtr   pAttrItem;
	_variant_t variantValue;
	pnode->get_attributes(&pAttrMap);

	long count;
	count=pAttrMap->get_length(&count);
 
	pAttrMap->get_item(0,&pAttrItem);
	//取得節點的值
	pAttrItem->get_nodeTypedValue(&variantValue);
	m_strId=(char *)(_bstr_t)variantValue;
	if(m_strId=="BackGround")
	{
		_bstr_t bt1;
		bt1=pnode->Getxml();
		MSXML2::IXMLDOMDocumentPtr   pxmldom1;
		hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
		pxmldom1->loadXML(bt1);
		MSXML2::IXMLDOMNodePtr pNode;
		pNode=pxmldom1->selectSingleNode("//bgimage");
		_variant_t vtStr;
		CString strValue;
		pNode->get_nodeTypedValue(&vtStr);  
		strValue=vtStr.bstrVal; 
		//MessageBox(strValue);
	}
	//MessageBox(m_strId);
  }  

}

void CTest_msxml4Dlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
  int   i,k;   
  CString   name,value;   
  MSXML2::IXMLDOMDocumentPtr   pxmldom;
  MSXML2::IXMLDOMDocumentPtr   pxmldom1; 
  MSXML2::IXMLDOMNodeListPtr   pnl;   
  MSXML2::IXMLDOMNodePtr   pnode;
  MSXML2::IXMLDOMNodePtr   pnode1;
  MSXML2::IXMLDOMNodePtr   Data; 
  HRESULT hr = pxmldom.CreateInstance(__uuidof(MSXML2::DOMDocument30));
  if(!SUCCEEDED(hr))
  {
	  MessageBox("Error!");
	  return;
  }
  pxmldom->load("SignageConfig.xml");
  pnode=pxmldom->selectSingleNode("//Default");
  if(pnode!=NULL)
  {
		_bstr_t bt1;
		bt1=pnode->Getxml();
		hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
		pxmldom1->loadXML(bt1);
		pnl=pxmldom1->selectNodes("//program");  //selectnodes("//program");
		k=pnl->length;
	    CString strName;
	    CString m_strId;
	    k=pnl->length;
	    for(i=0;i<k;i++)   
		{   
			pnode1=pnl->item[i]; 
			strName=(char *)pnode1->GetnodeName();
			//節點屬性,放在鏈表中 
			MSXML2::IXMLDOMNamedNodeMapPtr pAttrMap=NULL;
			MSXML2::IXMLDOMNodePtr   pAttrItem;
			_variant_t variantValue;
			pnode1->get_attributes(&pAttrMap);

			long count;
			count=pAttrMap->get_length(&count);
 
			pAttrMap->get_item(0,&pAttrItem);
			//取得節點的值
			pAttrItem->get_nodeTypedValue(&variantValue);
			m_strId=(char *)(_bstr_t)variantValue;
			MessageBox(m_strId);
		}
		
  }
}
