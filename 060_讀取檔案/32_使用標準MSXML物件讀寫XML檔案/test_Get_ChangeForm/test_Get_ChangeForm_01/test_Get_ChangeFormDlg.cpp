// test_Get_ChangeFormDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test_Get_ChangeForm.h"
#include "test_Get_ChangeFormDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define conData_Max 50
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
// CTest_Get_ChangeFormDlg dialog

CTest_Get_ChangeFormDlg::CTest_Get_ChangeFormDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTest_Get_ChangeFormDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTest_Get_ChangeFormDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTest_Get_ChangeFormDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTest_Get_ChangeFormDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTest_Get_ChangeFormDlg, CDialog)
	//{{AFX_MSG_MAP(CTest_Get_ChangeFormDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest_Get_ChangeFormDlg message handlers

BOOL CTest_Get_ChangeFormDlg::OnInitDialog()
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

void CTest_Get_ChangeFormDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTest_Get_ChangeFormDlg::OnPaint() 
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
HCURSOR CTest_Get_ChangeFormDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTest_Get_ChangeFormDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   MessageBox("Error!");
	   return;
	}
	pDoc->load("SignageConfig.xml"); 
 
	MSXML2::IXMLDOMNodePtr  pNode;
 
	//在樹中查找名為Book的節點,"//"表示在任意一層查找 
	pNode=pDoc->selectSingleNode("//s20080310");
	if(pNode!=NULL)
	{
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
		RipData(strValue);
		MessageBox(strValue);
		MessageBox("OK");
	}
	else
	{
		MessageBox("KO");
	}
}

void CTest_Get_ChangeFormDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	MSXML2::IXMLDOMDocumentPtr pDoc;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   MessageBox("Error!");
	   return;
	}
	pDoc->load("SignageConfig.xml"); 
 
	MSXML2::IXMLDOMNodePtr  pNode;
 
	//在樹中查找名為Book的節點,"//"表示在任意一層查找 
	pNode=pDoc->selectSingleNode("//s20080311");
	if(pNode!=NULL)
	{
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
	else
	{
		MessageBox("KO");
	}
}

void CTest_Get_ChangeFormDlg::RipData(CString Datainput)
{
	////////////////////////////////////
	CString StrIP="";
	CString StrBuf="";
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	long lngLen=0;//建立長度暫存變數
	long lngGetLen1=0;//提取資料長度
	long lngGetLen2=0;//剩餘資料長度
	CString m_strInData="";//主
	CString strInData="";//m_strInData分身
	CString strRemain="";//剩餘資料
	char chrSeps[]=";";//建立分割符號
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	bool blnLen=false;//判斷長度是否為0
	int intCount=0;//紀錄第幾筆資料
	////////////////////////////////////////
	char chrxmldata[100];
	int intHr1,intMin1,intHr2,intMin2;
	m_strInData=Datainput;
	strInData=m_strInData;//取出原來資料
	do
	{
		chrInBuf=strInData.GetBuffer(0);//賦予資料
		lngLen=strlen(chrInBuf);
		if(lngLen<= 0)//防堵最後一筆資料換行所造成誤判
		{
			blnLen=true;
			break;
		}
		chrOutBuf=strtok(chrInBuf,chrSeps);//擷取的資料
		sscanf(chrOutBuf,"%d:%d-%d:%d-%s",&intHr1,&intMin1,&intHr2,&intMin2,chrxmldata);
		intCount++;
		lngGetLen1=strlen(chrOutBuf);//提取資料長度
		lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
		if(intCount==1)
		{
			if(lngGetLen2>0)
				strRemain=m_strInData.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			else
				strRemain="";
		}
		else
		{
			if(lngGetLen2>0)
				strRemain=strRemain.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			else
				strRemain="";
		}
		strInData=strRemain;
	}while(intCount<conData_Max);
}
