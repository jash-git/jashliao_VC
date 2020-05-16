// CreateMediaXMLDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CreateMediaXML.h"
#include "CreateMediaXMLDlg.h"

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
// CCreateMediaXMLDlg dialog

CCreateMediaXMLDlg::CCreateMediaXMLDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCreateMediaXMLDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCreateMediaXMLDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCreateMediaXMLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCreateMediaXMLDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCreateMediaXMLDlg, CDialog)
	//{{AFX_MSG_MAP(CCreateMediaXMLDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Start, OnStart)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCreateMediaXMLDlg message handlers

BOOL CCreateMediaXMLDlg::OnInitDialog()
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
	InitialVariable();
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCreateMediaXMLDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCreateMediaXMLDlg::OnPaint() 
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
HCURSOR CCreateMediaXMLDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CCreateMediaXMLDlg::BrowseDir(CString strDir)
{
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	CTime t1;
	CString StrData;
	BOOL res = ff.FindFile(szDir);
	
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			//進入遞迴
			BrowseDir(ff.GetFilePath());
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			//紀錄已知檔案資訊
			StrData=ff.GetFileName();
			StrData=StrData.Mid(StrData.FindOneOf(".")+1);
			StrData.MakeLower();
			if(StrData=="wmv")
			{
				StrData=ff.GetFileTitle();
				m_ArrayTitle.Add(StrData);
			}
		}
	}
	ff.Close();//結束搜尋
}
void CCreateMediaXMLDlg::InitialVariable(void)
{
	m_ArrayTitle.RemoveAll();
	MSXML2::IXMLDOMDocumentPtr pDoc;
	int nLen=0;
	bool blnRead=false;
	_variant_t vtStr;
	CString StrValue;

	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	nLen= ::GetCurrentDirectory(500,m_chrCurDrt);//取得目前程式路徑
	m_StrSettingFileName+="Resources\\Config.xml";
	blnRead=pDoc->load((_bstr_t)m_StrSettingFileName);
	if(blnRead)
	{
		//////////////////////////////////////////////////
		MSXML2::IXMLDOMNodePtr Position_Size;
		Position_Size=pDoc->selectSingleNode("//input_path");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrInputPath=StrValue; 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//output_path");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrOutputPath=StrValue;  
	}
}
void CCreateMediaXMLDlg::OnStart() 
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
	xmlRoot=pDoc->createElement((_bstr_t)"streamEditor");
	pDoc->appendChild(xmlRoot);
	CString Str01,Str02,Str03,StrTitle;
	BrowseDir(m_StrInputPath);
	int i,j;
	j=m_ArrayTitle.GetSize();
	for(i=0;i<j;i++)
	{
		StrTitle=m_ArrayTitle.GetAt(i);
		//output
		MSXML2::IXMLDOMElementPtr pNode;
		//Str01="C:\\Documents and Settings\\Administrator\\桌面\\p00001.wmv";
		Str01=m_StrOutputPath+StrTitle;
		Str01+=".wmv";
		pNode=pDoc->createElement((_bstr_t)"output");
		pNode->setAttribute("outputFile",Str01.GetBuffer(0));
		xmlRoot->appendChild(pNode);
		
		//audience
		MSXML2::IXMLDOMElementPtr paudience;
		paudience=pDoc->createElement((_bstr_t)"audience");
		pNode->appendChild(paudience);
		//stream01
		//Str02="C:\\Documents and Settings\\Administrator\\桌面\\p00001.wma";
		Str02=m_StrInputPath+StrTitle;
		Str02+=".wma";
		MSXML2::IXMLDOMElementPtr pstream01;
		pstream01=pDoc->createElement((_bstr_t)"stream");
		pstream01->setAttribute("inputFile",Str02.GetBuffer(0));
		pstream01->setAttribute("type",(const char *)"1");
		pstream01->setAttribute("inputAudienceIndex",(const char *)"0");
		pstream01->setAttribute("inputRenderSite",(const char *)"0");
		pstream01->setAttribute("bitrate",(const char *)"64008");
		pstream01->setAttribute("inputLangID",(const char *)"1028");
		paudience->appendChild(pstream01);
		//stream02
		//Str03="C:\\Documents and Settings\\Administrator\\桌面\\p00001.wmv";
		Str03=m_StrInputPath+StrTitle;
		Str03+=".wmv";
		MSXML2::IXMLDOMElementPtr pstream02;
		pstream02=pDoc->createElement((_bstr_t)"stream");
		pstream02->setAttribute("inputFile",Str03.GetBuffer(0));
		pstream02->setAttribute("type",(const char *)"2");
		pstream02->setAttribute("inputAudienceIndex",(const char *)"0");
		pstream02->setAttribute("inputRenderSite",(const char *)"0");
		pstream02->setAttribute("bitrate",(const char *)"1000000");
		pstream02->setAttribute("inputLangID",(const char *)"1028");
		paudience->appendChild(pstream02);
	}
	//保存到檔 
	//如果不存在就建立,存在就覆蓋 
	pDoc->save("stream.xml");
	MessageBox("Finish .");
	this->OnOK();
}
