// H264FilesCopyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "H264FilesCopy.h"
#include "H264FilesCopyDlg.h"
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
CString StrDirS,StrDirD,StrGetListUrl,StrSetWorkIdUrl,StrSetWorkErrorUrl;
CString StrsetUrlandId;
int intTimerCount;
CArray <CString,CString&> m_ArraySource;//Step 2:CArray//存放來源檔案資料
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
// CH264FilesCopyDlg dialog

CH264FilesCopyDlg::CH264FilesCopyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CH264FilesCopyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CH264FilesCopyDlg)
	m_V1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CH264FilesCopyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CH264FilesCopyDlg)
	DDX_Control(pDX, IDC_BUTTON1, m_B1);
	DDX_Text(pDX, IDC_Count, m_V1);
	DDX_Control(pDX, IDC_EXPLORER1, m_Web);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CH264FilesCopyDlg, CDialog)
	//{{AFX_MSG_MAP(CH264FilesCopyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CH264FilesCopyDlg message handlers

BOOL CH264FilesCopyDlg::OnInitDialog()
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
		pNodeRoot=pDoc->selectSingleNode("//DirS");//取得Node內容
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrDirS=StrBuff;
		pNodeRoot=pDoc->selectSingleNode("//DirD");//取得Node內容
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrDirD=StrBuff;
		pNodeRoot=pDoc->selectSingleNode("//GetListUrl");//取得Node內容
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrGetListUrl=StrBuff;
		pNodeRoot=pDoc->selectSingleNode("//SetWorkIdUrl");//取得Node內容
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrSetWorkIdUrl=StrBuff;
		pNodeRoot=pDoc->selectSingleNode("//SetWorkErrorUrl");//取得Node內容
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrSetWorkErrorUrl=StrBuff;
	}
	else
	{
		MessageBox("無法讀取設定檔,程式即將關閉");
		this->OnOK();
	}
	intTimerCount=300;
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CH264FilesCopyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CH264FilesCopyDlg::OnPaint() 
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
HCURSOR CH264FilesCopyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CH264FilesCopyDlg::Function()
{
	KillTimer(1);
	CString StrSFilePath,StrDFilePath;
	CString Strworkid;
	m_B1.EnableWindow(false);
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
	int k,l;
	int m,n;
	int o,p;
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

	FILE *pf;
	FILE *pfCutImageList;
	CTime t1=CTime::GetCurrentTime();
	CString StrTime;
	StrTime=t1.Format("%Y-%m-%d %H:%M:%S");
	CString Strlogfile;
	Strlogfile=gstrCurDrt;
	Strlogfile+="log.txt";
	pf=fopen(Strlogfile.GetBuffer(0),"a");
	fprintf(pf,"%s\n",StrTime.GetBuffer(0));
	CString StrSPath,StrDPath;
	CString Strlog;
	m_ArraySource.RemoveAll(); 

	pfCutImageList=fopen("CutImageList.txt","w");
	
	if(blnRead)//第11.0版的功能
	{
		//抓根節點
		pNodeRoot=pDoc->selectSingleNode("//works");//取得Node內容
		//將所有子節點放到list中
		pNodeRoot->get_childNodes(&pNodeListwork);
		j=pNodeListwork->length;
		
		for(i=0;i<j;i++)
		{
			bool blnALLOK=true;
			MSXML2::IXMLDOMNodePtr pNodeBuf;
			pNodeListwork->get_item(i,&pNodeBuf);
			pNodework_id=pNodeBuf->selectSingleNode("work_id");
			pNodework_id->get_nodeTypedValue(&vtStr);
			StrBuff=vtStr.bstrVal;
			Strworkid=vtStr.bstrVal;
			Strlog="work_id : "+StrBuff;
			fprintf(pf,"%s\n",Strlog.GetBuffer(0));
			//
			pNodesource_path=pNodeBuf->selectSingleNode("source_path");
			pNodesource_path->get_nodeTypedValue(&vtStr);
			StrBuff=vtStr.bstrVal;
			StrSPath=StrBuff;
			//
			pNodestorage_path=pNodeBuf->selectSingleNode("storage_path");
			pNodestorage_path->get_nodeTypedValue(&vtStr);
			StrBuff=vtStr.bstrVal;
			StrDPath=StrBuff;
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
				Strlog=StrDirS+StrSPath+StrBuff+" -> "+StrDirD+StrDPath+"videos\\"+StrBuff;
				StrSFilePath=StrDirS+StrSPath+StrBuff;
				StrDFilePath=StrDirD+StrDPath+"videos\\"+StrBuff;
				m_ArraySource.Add(StrSFilePath);

				if(k==0)
					fprintf(pfCutImageList,"%s\n",StrDFilePath.GetBuffer(0));
				
				if(CopyFile(StrSFilePath,StrDFilePath,false))
				{
					Strlog+="  ->OK";
					//DeleteFile(StrSFilePath);
				}
				else
				{
					Strlog+="  ->Fail";
					blnALLOK=false;
				}
				fprintf(pf,"%s\n",Strlog.GetBuffer(0));				
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
				Strlog=StrDirS+StrSPath+StrBuff+" -> "+StrDirD+StrDPath+StrBuff;
				StrSFilePath=StrDirS+StrSPath+StrBuff;
				StrDFilePath=StrDirD+StrDPath+StrBuff;
				m_ArraySource.Add(StrSFilePath);
				if(CopyFile(StrSFilePath,StrDFilePath,false))
				{
					Strlog+="  ->OK";
					//DeleteFile(StrSFilePath);
				}
				else
				{
					Strlog+="  ->Fail";
					blnALLOK=false;
				}
				fprintf(pf,"%s\n",Strlog.GetBuffer(0));
			}
			if(blnALLOK)
			{
				//回報完成http
				COleVariant vaUrl;
				COleVariant vtMissing;
				StrsetUrlandId=StrSetWorkIdUrl+Strworkid;
				vaUrl=StrsetUrlandId;
				p=m_ArraySource.GetSize();
				for(o=0;o<p;o++)
				{
					StrSFilePath=m_ArraySource.GetAt(o);
					DeleteFile(StrSFilePath);
				}

				fclose(pfCutImageList);
				CopyFile("CutImageList.txt","\\\\192.168.0.201\\cutimageforsmooth\\CutImageList.txt",false);

				m_ArraySource.RemoveAll(); 
				m_Web.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
				Sleep(30000);
				CreateSmilCmd(StrSFilePath,(StrDirD+StrDPath));
			}
			else
			{
				//回報失敗email，停止程式
				m_ArraySource.RemoveAll(); 
				blnALLOK=true;
				FILE *pferror;
				CString StrEXEPath;
				pferror=fopen("ErrorInfo.txt","w");
				fprintf(pferror,"檔案複製異常\n");
				fprintf(pferror,"請儘快處理\n");
				fclose(pferror);
				StrEXEPath=gstrCurDrt;
				StrEXEPath+="MyEmailClient.exe";
				ShellExecute(NULL,"open",StrEXEPath.GetBuffer(0),NULL,NULL,SW_SHOWNORMAL); 
				
				COleVariant vaUrl;
				COleVariant vtMissing;
				StrsetUrlandId=StrSetWorkErrorUrl+Strworkid;
				StrsetUrlandId+="&ErrorMsg=File not found";
				vaUrl=StrsetUrlandId;
				m_Web.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
				Sleep(30000);
			}
		}
		fclose(pf);
		intTimerCount=300;
		m_B1.EnableWindow(true);
		SetTimer(1,1000,NULL);
	}
	else
	{
		fprintf(pf,"List XML error\n");
		//回報失敗email
		FILE *pferror;
		CString StrEXEPath;
		pferror=fopen("ErrorInfo.txt","w");
		fprintf(pferror,"List XML error,請儘快處理\n");
		fclose(pferror);
		fclose(pf);
		intTimerCount=300;
		StrEXEPath=gstrCurDrt;
		StrEXEPath+="MyEmailClient.exe";
		ShellExecute(NULL,"open",StrEXEPath.GetBuffer(0),NULL,NULL,SW_SHOWNORMAL); 
		m_B1.EnableWindow(true);
		SetTimer(1,1000,NULL);
	}

	fclose(pfCutImageList);
	DeleteFile("CutImageList.txt");
	pfCutImageList='\0';
}
void CH264FilesCopyDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString Strlistfile;
	Strlistfile=gstrCurDrt;
	Strlistfile+="test.xml";
	DeleteFile(Strlistfile);
	if(GetWebFile(StrGetListUrl,Strlistfile))
	{
		Function();
	}
	else
	{
		intTimerCount=300;
	}
}

void CH264FilesCopyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString Strlistfile;
	Strlistfile=gstrCurDrt;
	Strlistfile+="test.xml";
	DeleteFile(Strlistfile);
	char buffer[33];
	intTimerCount--;
	itoa(intTimerCount,buffer,10);
	UpdateData(true);
		m_V1=buffer;
	UpdateData(false);
	if(intTimerCount==0)
	{
		if(GetWebFile(StrGetListUrl,Strlistfile))
		{
			AfxBeginThread(ThreadFunction,this,0,0,0,NULL);
		}
		else
		{
			intTimerCount=300;
		}
	}
	CDialog::OnTimer(nIDEvent);
}
UINT CH264FilesCopyDlg::ThreadFunction(LPVOID lpram)
{
	CH264FilesCopyDlg *u=(CH264FilesCopyDlg *)lpram;
	u->Function();
	return 0;
}

BEGIN_EVENTSINK_MAP(CH264FilesCopyDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CH264FilesCopyDlg)
	ON_EVENT(CH264FilesCopyDlg, IDC_EXPLORER1, 104 /* DownloadComplete */, OnDownloadCompleteExplorer1, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CH264FilesCopyDlg::OnDownloadCompleteExplorer1() 
{
	// TODO: Add your control notification handler code here
	CString Strlogfile;
	FILE *pf;
	Strlogfile=gstrCurDrt;
	Strlogfile+="log.txt";
	pf=fopen(Strlogfile.GetBuffer(0),"a");
	fprintf(pf,"%s\n",StrsetUrlandId.GetBuffer(0));
	fclose(pf);
	
}
bool CH264FilesCopyDlg::GetWebFile(CString theUrl, CString Filename)//http_download
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
void CH264FilesCopyDlg::CreateSmilCmd(CString Data,CString StrDir)
{
	CString StrBuf,StrBuf1,StrBuf2;
	int intnumber,i;
	bool blncheck;
	blncheck=false;
	intnumber=Data.GetLength();
	for(i=(intnumber-1);i>=0;i--)
	{
		StrBuf=Data.Mid(i,1);
		if((StrBuf=="\\") && (!blncheck))
		{
			blncheck=true;
			continue;
		}
		if(blncheck)
		{
			StrBuf1=Data.Mid(i,1)+StrBuf1;
		}
		else
		{
			StrBuf2=Data.Mid(i,1)+StrBuf2;
		}

	}
	StrBuf1=StrBuf2.Mid(0,StrBuf2.ReverseFind('_'));
	///////////////////////////////////////////////////////////////////////
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString StrCallExeName;
	StrCallExeName=gstrCurDrt;
	StrCallExeName+="SearchFileCmd.exe ";
	StrCallExeName+=StrDir;
	StrCallExeName+="videos\\";
	StrCallExeName+=" ";
	StrCallExeName+=StrBuf1;
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=SW_MINIMIZE;
	si.dwFlags=STARTF_USESHOWWINDOW;
	BOOL fRet=CreateProcess(NULL,
							StrCallExeName.GetBuffer(0),
							NULL,
							NULL,
							FALSE,
							NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
							NULL,
							NULL,
							&si,
							&pi);
	if(fRet)
	{
		WaitForSingleObject(pi.hProcess,INFINITE);
	}
	////////////////////////////////////////////////////////////////////
	
	StrBuf1="All.cmd";
	FILE *pf;
		pf=fopen(StrBuf1.GetBuffer(0),"a");
		fprintf(pf,"%s",StrCallExeName.GetBuffer(0));
	fclose(pf);
	

}
