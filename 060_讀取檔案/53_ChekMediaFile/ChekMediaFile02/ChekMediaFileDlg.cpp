// ChekMediaFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChekMediaFile.h"
#include "ChekMediaFileDlg.h"
#include<fstream.h>
///////////////////////////////////////////////////////
#include <afxinet.h>		//http_download
#define BUFFER_SIZE 2048//http_download
///////////////////////////////////////////////////////
#include <afxtempl.h>//CArray Step_01 
///////////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR gstrCurDrt[500];//存放目其目錄字串
CString StrGetListUrl;
CArray <CString,CString&> m_ArrayId;//CArray Step
int gintArrayCount;
int gintArrayi;
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
// CChekMediaFileDlg dialog

CChekMediaFileDlg::CChekMediaFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChekMediaFileDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChekMediaFileDlg)
	m_StrID = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChekMediaFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChekMediaFileDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_But01);
	DDX_Text(pDX, IDC_EDIT1, m_StrID);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChekMediaFileDlg, CDialog)
	//{{AFX_MSG_MAP(CChekMediaFileDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChekMediaFileDlg message handlers

BOOL CChekMediaFileDlg::OnInitDialog()
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
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	//
	MSXML2::IXMLDOMDocumentPtr pDoc;//宣告XML物件
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));//建立XML物件
	if(!SUCCEEDED(hr))
	{
	   return false;
	}
	bool blnRead=false;
	_variant_t vtStr;//存放Node資料
	CString StrBuff;
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Config.xml";//建立XML檔案路徑
	blnRead=pDoc->load((_bstr_t)strFileName1); //載入XML
	MSXML2::IXMLDOMNodePtr pNodeRoot;//XML Node物件
	if(blnRead)//第11.0版的功能
	{
		pNodeRoot=pDoc->selectSingleNode("//GetListUrl");//取得Node內容
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrGetListUrl=StrBuff;
	}
	else
	{
		MessageBox("無法讀取設定檔,程式即將關閉");
		this->OnOK();
	}	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChekMediaFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChekMediaFileDlg::OnPaint() 
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
HCURSOR CChekMediaFileDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChekMediaFileDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here

	//UpdateData(true);
		//StrUrl=StrGetListUrl+m_StrID;
	//UpdateData(false);
	m_But01.EnableWindow(false);
	CString StrUrl;
	fstream a;
	char fg[700];
	gintArrayCount=0;
	m_ArrayId.RemoveAll();
	a.open("mediaID.txt",ios::in);
	while(!a.eof())
	{
		a.getline(fg,500);
		StrUrl=StrGetListUrl+fg;
		m_ArrayId.Add(StrUrl);
	}
	a.close();
	gintArrayCount=m_ArrayId.GetSize();
	gintArrayi=-1;
	MessageBox("Read File Finish ...");
	SetTimer(1,1000,NULL);
}
bool CChekMediaFileDlg::GetWebFile(CString theUrl, CString Filename)//http_download
{
    CInternetSession session;
    CInternetFile* file = NULL;
    try
    {
        // Try to connect with the URL
        file = (CInternetFile*)session.OpenURL(theUrl); 
    }
    catch (CInternetException* m_pException)
    {
        // if some error occurs, set the file with NULL
        file = NULL; 
        m_pException->Delete();
        return FALSE;
    }

    BOOL bRet = FALSE;
    // use dataStore to save the file content
    CStdioFile dataStore;
    if(dataStore.Open(Filename, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeBinary))
    {
        if (file)
        {
            UINT somelen = 0;
            BYTE somecode[BUFFER_SIZE];
            while((somelen = file->Read(somecode, BUFFER_SIZE)) > 0)
            {
                dataStore.Write(somecode, somelen);
            }
            bRet = TRUE;
        }
        dataStore.Close();
    }
    if(file)
    {
        file->Close();
        delete file;
    }
    return bRet;
}
void CChekMediaFileDlg::Function()
{
	::CoInitialize(NULL); //step 2:讀取XML
	MSXML2::IXMLDOMDocumentPtr pDoc;//宣告XML物件
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));//建立XML物件
	if(!SUCCEEDED(hr))
	{
	   return;
	}

	_variant_t vtStr;//存放Node資料
	CString StrBuff;	
	int i,j;
	bool blnRead=false;
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="list.xml";//建立XML檔案路徑
	MSXML2::IXMLDOMNodeListPtr pNodeListfile;//XML list Node物件
	blnRead=pDoc->load((_bstr_t)strFileName1); //載入XML

	FILE *pfAll,*pfErr;
	CTime t1=CTime::GetCurrentTime();
	CString StrTime;
	StrTime=t1.Format("%Y-%m-%d %H:%M:%S");
	CString Strlogfile;
	CString StrErrfile;
	Strlogfile=gstrCurDrt;
	StrErrfile=gstrCurDrt;
	Strlogfile+="ALLlog.txt";
	StrErrfile+="Errlog.txt";
	pfAll=fopen(Strlogfile.GetBuffer(0),"a");
	pfErr=fopen(StrErrfile.GetBuffer(0),"a");
	fprintf(pfAll,"%s\n",StrTime.GetBuffer(0));
	CString Strlog;

	if(blnRead)//第11.0版的功能
	{
		pNodeListfile=pDoc->selectNodes("//path");
		j=pNodeListfile->length;
		for(i=0;i<j;i++)
		{
			MSXML2::IXMLDOMNodePtr pNodeBuf01;
			pNodeListfile->get_item(i,&pNodeBuf01);
			pNodeBuf01->get_nodeTypedValue(&vtStr);
			StrBuff=vtStr.bstrVal;
			fprintf(pfAll,"%s\n",StrBuff.GetBuffer(0));
			StrBuff.Replace("/","\\");
			StrBuff.Replace("mms1","R:");
			StrBuff.Replace("mms2","S:");
			StrBuff.Replace("mms3","T:");
			StrBuff.Replace("mms4","U:");
			StrBuff.Replace("\\smooth","S:\\smooth");
			bool blncheck;
			CFileStatus rStatus;
			blncheck=CFile::GetStatus(StrBuff, rStatus);
			if(blncheck)
			{
				fprintf(pfAll,"%s -> OK\n",StrBuff.GetBuffer(0));
			}
			else
			{
				fprintf(pfAll,"%s -> Fail\n",StrBuff.GetBuffer(0));
				fprintf(pfErr,"%s -> Fail\n",StrBuff.GetBuffer(0));
			}
		}//for(i=0
		fclose(pfAll);
		fclose(pfErr);
	}//if(blnRead)
	SetTimer(1,1000,NULL);
}

void CChekMediaFileDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	gintArrayi++;
	if(gintArrayi<gintArrayCount)
	{
		UpdateData(true);
			m_StrID=m_ArrayId.GetAt(gintArrayi);
		UpdateData(false);
		AfxBeginThread(ThreadFunction,this,0,0,0,NULL);	
	}
	else
	{
		m_But01.EnableWindow(false);
		MessageBox("ALL Finish ...");
		this->OnOK();
	}
	CDialog::OnTimer(nIDEvent);
}
UINT CChekMediaFileDlg::ThreadFunction(LPVOID lpram)
{
	CChekMediaFileDlg *u=(CChekMediaFileDlg *)lpram;
	CString StrUrl;
	CString StrListFilePath;
	StrListFilePath=gstrCurDrt;
	StrListFilePath+="list.xml";
	StrUrl=m_ArrayId.GetAt(gintArrayi);
	u->GetWebFile(StrUrl,StrListFilePath);
	///////////////////////////////////////
	u->Function();
	return 0;
}
