// NabroSTBToolDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NabroSTBTool.h"
#include "NabroSTBToolDlg.h"
#include "NetUsebat.h"
#include "FileCopyDelete.h"
#include "AccessforSTB.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BUFFER_SIZE 2048//http_download
TCHAR gstrCurDrt[500];//存放目其目錄字串
CAccessforSTB MainAfS;
CAccessforSTB *threadAfS;
bool blnthreadcheck[50];
bool blnALLthreadcheck;
int gintthreadnumber=10;
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
	afx_msg void OnTimer(UINT nIDEvent);
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
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNabroSTBToolDlg dialog

CNabroSTBToolDlg::CNabroSTBToolDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNabroSTBToolDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNabroSTBToolDlg)
	m_Uid = _T("");
	m_State = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNabroSTBToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNabroSTBToolDlg)
	DDX_Control(pDX, IDC_IPADDRESS1, m_IP);
	DDX_Control(pDX, IDC_test, m_testButton);
	DDX_Text(pDX, IDC_EDIT1, m_Uid);
	DDX_Text(pDX, IDC_State, m_State);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CNabroSTBToolDlg, CDialog)
	//{{AFX_MSG_MAP(CNabroSTBToolDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_test, Ontest)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNabroSTBToolDlg message handlers

BOOL CNabroSTBToolDlg::OnInitDialog()
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
	UpdateData(true);
		m_State="目前狀態 :正在下載清單";
		m_testButton.EnableWindow(false);
	UpdateData(false);
	SetTimer(1,100,NULL);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNabroSTBToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CNabroSTBToolDlg::OnPaint() 
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
HCURSOR CNabroSTBToolDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CNabroSTBToolDlg::GetConfigParameter()//step 4:讀取XML
{
	char d1[200]={'\0'},d2[200]={'\0'},d3[200]={'\0'};
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	bool blnRead=false;
	long i=0,lngDataCount=0;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="NabroSTBToolConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)//第11.0版的功能
	{
		MSXML2::IXMLDOMNodePtr pNodeData;
		pNodeData=pDoc->selectSingleNode("//EnableSTBUrl");
		pNodeData->get_nodeTypedValue(&vtStr);
		m_StrEnableSTBUrl=vtStr.bstrVal;
		pNodeData=pDoc->selectSingleNode("//NetDir");
		pNodeData->get_nodeTypedValue(&vtStr);
		m_StrNetDir=vtStr.bstrVal;
		pNodeData=pDoc->selectSingleNode("//EnableuidUrl");
		pNodeData->get_nodeTypedValue(&vtStr);
		m_StrEnableuidUrl=vtStr.bstrVal;
	}
	/*
	////////////////////////////////
	//test
	MessageBox(m_StrEnableSTBUrl);
	MessageBox(m_StrNetDir);
	///////////////////////////////
	*/
}
bool CNabroSTBToolDlg::GetWebFile(CString theUrl, CString Filename)//http_download
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
void CNabroSTBToolDlg::GetSTBInformation()
{
	int i,j;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMDocumentPtr pxmldom1;
	MSXML2::IXMLDOMNodeListPtr pNodeList;
	MSXML2::IXMLDOMNodePtr pNodeData;
	MSXML2::IXMLDOMNodePtr pNodeSTBuid;
	MSXML2::IXMLDOMNodePtr pNodeSTBIP;
	CString StrSTBuid;
	CString StrSTBIP;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	_bstr_t bt1;
	bool blnRead=false;
	long lngDataCount=0;
	m_ArraySTBuid.RemoveAll();//CArray Step
	m_ArraySTBIP.RemoveAll();//CArray Step
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="STBEnableList.xml";
	FILE *pfIPMappingUid;
	pfIPMappingUid=fopen("IPMappingUid.txt","w");
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)//第11.0版的功能
	{
		i=0;
		j=0;
		///////////////////////////////////////////////////
		pNodeList=pDoc->selectNodes("//STB");
		j=pNodeList->length;
		for(i=0;i<j;i++)
		{
			pNodeData=pNodeList->item[i];
			bt1=pNodeData->Getxml();
			hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
			blnRead=pxmldom1->loadXML(bt1);
			////////////////////////////////////////////////////////
			pNodeSTBuid=pxmldom1->selectSingleNode("//STB_uid");
			pNodeSTBuid->get_nodeTypedValue(&vtStr);
			StrSTBuid=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeSTBIP=pxmldom1->selectSingleNode("//STB_IP");
			pNodeSTBIP->get_nodeTypedValue(&vtStr);
			StrSTBIP=vtStr.bstrVal;
			///////////////////////////////////////////////////////
			m_ArraySTBuid.Add(StrSTBuid);
			m_ArraySTBIP.Add(StrSTBIP);
			fprintf(pfIPMappingUid,"%s\t%s\n",StrSTBIP.GetBuffer(0),StrSTBuid.GetBuffer(0));
		}
		fclose(pfIPMappingUid);
	}
	/*
	////////////////////////////////
	//test
	MessageBox(StrSTBuid);
	MessageBox(StrSTBIP);
	///////////////////////////////
	*/
}
void CNabroSTBToolDlg::GetSTBMovieInformation(CString StrSTBuid)
{
	CString StrUrl;
	CString StrFileName;
	StrUrl=m_StrEnableuidUrl;
	StrUrl+="&STBuid=";
	StrUrl+=StrSTBuid;
	StrFileName=StrSTBuid;
	StrFileName+=".xml";
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="\\STBMovieInformation\\";
	strFileName1 +=StrFileName;
	GetWebFile(StrUrl,strFileName1);

}

void CNabroSTBToolDlg::Ontest() 
{
	// TODO: Add your control notification handler code here
	CString Struid;
	CString StrIP;
	CString StrBuf;
	int i=0,j=0;
	Struid="0000";
	//"4082"
	StrIP="0.0.0.0";
	//"172.17.254.126"
	j=m_ArraySTBuid.GetSize();
	FILE *pfRunState;
	pfRunState=fopen("RunState.txt","w");
	fclose(pfRunState);
	pfRunState=NULL;
	m_testButton.EnableWindow(false);
	this->ShowWindow(SW_MINIMIZE);
	////////////////////////////////////////////////////////////
	/*
	UpdateData(true);
	Struid=m_Uid;
	m_IP.GetWindowText(StrIP);
	UpdateData(false);
	ReadAVListXML(Struid);
	if(ConnectSTB(StrIP))
	{
		ReadSTBAVList(StrIP);
		STBAddAVFile(Struid,StrIP);
		STBDelAVFile(Struid,StrIP);
		pfRunState=fopen("RunState.txt","a");
		fprintf(pfRunState,"%s\t%s\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
		fclose(pfRunState);
		pfRunState=NULL;
	}
	else
	{
		pfRunState=fopen("RunState.txt","a");
		fprintf(pfRunState,"%s\t%s\t Not Connect\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
		fclose(pfRunState);
		pfRunState=NULL;
	}
	////////////////////////////////////////////////////////////////////
	*/
	///*//ALL
	for(i=0;i<j;i++)
	{
		Struid=m_ArraySTBuid.GetAt(i);
		StrIP=m_ArraySTBIP.GetAt(i);
		SetDlgItemText(IDC_EDIT1,Struid.GetBuffer(0));
		SetDlgItemText(IDC_IPADDRESS1,StrIP.GetBuffer(0));
		StrBuf.Format("目前狀態 :讀取IP=%s的影片清單...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
		ReadAVListXML(Struid);
		StrBuf.Format("目前狀態 :IP=%s網路連線中...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
		if(ConnectSTB(StrIP))
		{
			StrBuf.Format("目前狀態 :讀取IP=%s的STB內的檔案清單...",StrIP.GetBuffer(0));
			SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			ReadSTBAVList(StrIP);
			StrBuf.Format("目前狀態 :對IP=%s的STB進行補檔...",StrIP.GetBuffer(0));
			SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			STBAddAVFile(Struid,StrIP);
			StrBuf.Format("目前狀態 :對IP=%s的STB進行刪檔...",StrIP.GetBuffer(0));
			SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			STBDelAVFile(Struid,StrIP);
			pfRunState=fopen("RunState.txt","a");
			fprintf(pfRunState,"%s\t%s\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
			fclose(pfRunState);
			pfRunState=NULL;
		}
		else
		{
			pfRunState=fopen("RunState.txt","a");
			fprintf(pfRunState,"%s\t%s\t Not Connect\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
			fclose(pfRunState);
			pfRunState=NULL;
		}
	}
	//*/
	m_testButton.EnableWindow(true);
	this->ShowWindow(SW_MAXIMIZE);
	////////////////////////
	//test
	//MessageBox("完成");
	////////////////////////
	this->OnOK();
}
bool CNabroSTBToolDlg::ConnectSTB(CString StrIP)
{
	CNetUsebat NUB;
	CString StrNetPath;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient";
	NUB.Createbat("nabro","nabro",StrNetPath,0);
	if(NUB.CreateShareDir())
	{
		/*
		////////////////////////////////
		//test
		MessageBox(StrIP);
		///////////////////////////////
		*/
		return true;
	}
	return false;
}
void CNabroSTBToolDlg::ReadAVListXML(CString Struid)
{
	CString StrFileName;
	StrFileName=Struid;
	StrFileName+=".xml";
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="\\STBMovieInformation\\";
	strFileName1 +=StrFileName;
	////////////////////////////////////////////////////////////////
	m_ArrayFileSourcePath.RemoveAll();
	m_ArrayFileDestPath.RemoveAll();
	m_ArrayFileStartDate.RemoveAll();
	m_ArrayFileEndDate.RemoveAll();
	///////////////////////////////////////////////////////////////
	int i,j;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMDocumentPtr pxmldom1;
	MSXML2::IXMLDOMNodeListPtr pNodeList;
	MSXML2::IXMLDOMNodePtr pNodeData;
	MSXML2::IXMLDOMNodePtr pNodeFileSourcePath;
	MSXML2::IXMLDOMNodePtr pNodeFileDestPath;
	MSXML2::IXMLDOMNodePtr pNodeFileStartDate;
	MSXML2::IXMLDOMNodePtr pNodeFileEndDate;
	CString StrFileSourcePath;
	CString StrFileDestPath;
	CString StrFileStartDate;
	CString StrFileEndDate;
	_variant_t vtStr;
	_bstr_t bt1;
	bool blnRead=false;
	long lngDataCount=0;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)//第11.0版的功能
	{
		i=0;
		j=0;
		///////////////////////////////////////////////////
		pNodeList=pDoc->selectNodes("//File");
		j=pNodeList->length;
		for(i=0;i<j;i++)
		{
			pNodeData=pNodeList->item[i];
			bt1=pNodeData->Getxml();
			hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
			blnRead=pxmldom1->loadXML(bt1);
			////////////////////////////////////////////////////////
			pNodeFileSourcePath=pxmldom1->selectSingleNode("//FileSourcePath");
			pNodeFileSourcePath->get_nodeTypedValue(&vtStr);
			StrFileSourcePath=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeFileDestPath=pxmldom1->selectSingleNode("//FileDestPath");
			pNodeFileDestPath->get_nodeTypedValue(&vtStr);
			StrFileDestPath=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeFileStartDate=pxmldom1->selectSingleNode("//FileStartDate");
			pNodeFileStartDate->get_nodeTypedValue(&vtStr);
			StrFileStartDate=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeFileEndDate=pxmldom1->selectSingleNode("//FileEndDate");
			pNodeFileEndDate->get_nodeTypedValue(&vtStr);
			StrFileEndDate=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			m_ArrayFileSourcePath.Add(StrFileSourcePath);
			m_ArrayFileDestPath.Add(StrFileDestPath);
			m_ArrayFileStartDate.Add(StrFileStartDate);
			m_ArrayFileEndDate.Add(StrFileEndDate);
		}
	}
	/*
	////////////////////////////////
	//test
	MessageBox(StrFileSourcePath);
	MessageBox(StrFileDestPath);
	MessageBox(StrFileStartDate);
	MessageBox(StrFileEndDate);
	///////////////////////////////
	*/
}
void CNabroSTBToolDlg::ReadSTBAVList(CString StrIP)
{
	int i,j;
	i=0;j=0;
	CString StrNetPath;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\AV\\";
	CFileCopyDelete FCD;
	FCD.BrowseDir(StrNetPath,2);
	m_ArrayBrowseData.RemoveAll();
	FCD.GetArrayData(2,&m_ArrayBrowseData);
	/*
	//////////////////////////////////////////////
	//test
	j=m_ArrayBrowseData.GetSize();
	for(i=0;i<j;i++)
	{
		MessageBox(m_ArrayBrowseData.GetAt(i));
	}
	/////////////////////////////////////////////
	*/
}
void CNabroSTBToolDlg::STBAddAVFile(CString Struid,CString StrIP)
{
	int i,j;
	int k,l;
	//來源->m_ArrayFileSourcePath
	//目的->m_ArrayBrowseData
	CString StrNewFilePath;
	CString StrNewFileName;
	CString StrOldFilePath;
	CString StrOldFileName;
	CString StrLogFileName;
	CString StrStartTime;
	CString StrEndTime;
	CString StrInfoFileName;
	j=m_ArrayFileSourcePath.GetSize();//New
	l=m_ArrayBrowseData.GetSize();//Old
	CString StrNetPath;
	CString StrNetPathName;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\AV\\";
	bool blnNotFind=true;
	for(i=0;i<j;i++)
	{
		//New Get
		StrStartTime=m_ArrayFileStartDate.GetAt(i);
		StrEndTime=m_ArrayFileEndDate.GetAt(i);
		StrNewFilePath=m_ArrayFileSourcePath.GetAt(i);
		StrNewFileName=GetFilePath2FileName(StrNewFilePath);
		for(k=0;k<l;k++)
		{
			//Old Get
			StrOldFilePath=m_ArrayBrowseData.GetAt(k);
			StrOldFileName=GetFilePath2FileName(StrOldFilePath);
			if(StrNewFileName==StrOldFileName)
			{
				blnNotFind=false;
				break;
			}
		}
		if(blnNotFind==true)
		{
			/////////////////////////////////////////////////////////
			int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
			if( gstrCurDrt[nLen]!='\\' )
			{
				gstrCurDrt[nLen++] = '\\';
				gstrCurDrt[nLen] = '\0';
			}
			CString strFileName1 = gstrCurDrt;
			strFileName1 +="\\STBCheckLogs\\";
			StrLogFileName=StrIP+"_";
			StrLogFileName+=Struid+"_Addlog.txt";
			strFileName1 +=StrLogFileName;
			StrInfoFileName=CreatInfoFileHead(StrStartTime,StrEndTime);
			StrInfoFileName+=StrNewFileName;
			StrInfoFileName+=".info";
			FILE *pfLogFile;
			pfLogFile=fopen(strFileName1.GetBuffer(0),"a");
			StrNetPathName=StrNetPath+StrNewFileName;
			if(true)
			{
				fprintf(pfLogFile,"%s\t%s\n",StrNewFilePath.GetBuffer(0),"OK");
			}
			else
			{
				fprintf(pfLogFile,"%s\t%s\n",StrNewFilePath.GetBuffer(0),"Not OK");
			}
			StrNetPathName="";
			StrNetPathName=StrNetPath+"\\Schedule\\";
			StrNetPathName+=StrInfoFileName;
			//FILE *pfInfo;
			//pfInfo=fopen(StrNetPathName.GetBuffer(0),"w");
			if(true)
			{
				fprintf(pfLogFile,"%s\t%s\n",StrInfoFileName.GetBuffer(0),"OK");
				fprintf(pfLogFile,"\n");
				//fclose(pfInfo);
			}
			else
			{
				fprintf(pfLogFile,"%s\t%s\n",StrInfoFileName.GetBuffer(0),"Not OK");
				fprintf(pfLogFile,"\n");
			}
			//pfInfo=NULL;
			fclose(pfLogFile);
			pfLogFile=NULL;
			/////////////////////////////////////////////////////////
		}
		else
		{
			blnNotFind=true;
		}
	}
}
void CNabroSTBToolDlg::STBDelAVFile(CString Struid,CString StrIP)
{
	int i,j;
	int k,l;
	//來源->m_ArrayFileSourcePath
	//目的->m_ArrayBrowseData
	CString StrNewFilePath;
	CString StrNewFileName;
	CString StrOldFilePath;
	CString StrOldFileName;
	CString StrLogFileName;
	l=m_ArrayFileSourcePath.GetSize();//New
	j=m_ArrayBrowseData.GetSize();//Old
	bool blnNotFind=true;
	for(i=0;i<j;i++)
	{
		//Old Get
		StrOldFilePath=m_ArrayBrowseData.GetAt(i);
		StrOldFileName=GetFilePath2FileName(StrOldFilePath);
		for(k=0;k<l;k++)
		{
			//New Get
			StrNewFilePath=m_ArrayFileSourcePath.GetAt(k);
			StrNewFileName=GetFilePath2FileName(StrNewFilePath);
			if(StrNewFileName==StrOldFileName)
			{
				blnNotFind=false;
				break;
			}
		}
		if(blnNotFind==true)
		{
			/////////////////////////////////////////////////////////
			int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
			if( gstrCurDrt[nLen]!='\\' )
			{
				gstrCurDrt[nLen++] = '\\';
				gstrCurDrt[nLen] = '\0';
			}
			CString strFileName1 = gstrCurDrt;
			strFileName1 +="\\STBCheckLogs\\";
			StrLogFileName=StrIP+"_";
			StrLogFileName+=Struid+"_Dellog.txt";
			strFileName1 +=StrLogFileName;
			FILE *pfLogFile;
			pfLogFile=fopen(strFileName1.GetBuffer(0),"a");
			if(true)
			{
				fprintf(pfLogFile,"%s\t%s\n",StrOldFilePath.GetBuffer(0),"OK");
			}
			else
			{
				fprintf(pfLogFile,"%s\t%s\n",StrOldFilePath.GetBuffer(0),"Not OK");
			}
			fclose(pfLogFile);
			pfLogFile=NULL;
			/////////////////////////////////////////////////////////
		}
		else
		{
			blnNotFind=true;
		}
	}
}
CString CNabroSTBToolDlg::GetFilePath2FileName(CString Strdata)
{
	int i,intnumber;
	CString Strbuf;
	intnumber=Strdata.GetLength();
	Strbuf="";
	for(i=(intnumber-1);i>=0;i--)
	{
		if(Strdata.Mid(i,1)!="\\")
		{
			Strbuf=Strdata.Mid(i,1)+Strbuf;

		}
		else
		{
			break;
		}
	}
	return Strbuf;
}
CString CNabroSTBToolDlg::CreatInfoFileHead(CString StrStart,CString StrEnd)
{
	CString StrStart_Date,StrEnd_Date; 
	//////////////////////////////////
	CString StrYear,StrMonth,StrDay,StrCount;
	CString StrOutBuf;
	CString StrBuf;
	char *chrbuf;
	int intLen=0;
	int intCountYear=0;
	int intResultYear=0;
	int intYear,intMonth,intDay,intCount;
	/////////////////////////////////////
	int y1,m1,d1;
	int y2,m2,d2;
	//gStrInfoFileHead="";
	StrEnd_Date=StrEnd;
	StrStart_Date=StrStart;
	StrBuf=StrStart_Date.Mid(0,4);
	y1=_ttoi(StrBuf);
	StrBuf=StrStart_Date.Mid(4,2);
	m1=_ttoi(StrBuf);
	StrBuf=StrStart_Date.Mid(6,2);
	d1=_ttoi(StrBuf);
	StrBuf=StrEnd_Date.Mid(0,4);
	y2=_ttoi(StrBuf);
	StrBuf=StrEnd_Date.Mid(4,2);
	m2=_ttoi(StrBuf);
	StrBuf=StrEnd_Date.Mid(6,2);
	d2=_ttoi(StrBuf);
	//sscanf(StrStart_Date.GetBuffer(StrStart_Date.GetLength()),"%d-%d-%d",&y1,&m1,&d1);
	//sscanf(StrEnd_Date.GetBuffer(StrEnd_Date.GetLength()),"%d-%d-%d",&y2,&m2,&d2); 
	CTime t1(y1,m1,d1,0,0,0);//起始時間     
	CTime t2(y2,m2,d2,0,0,0);//終止時間     
	CTimeSpan ts;
	ts =t2-t1;
	//intCount=ts.GetDays()+1;//天數=終止時間-起始時間+1
	intCount=ts.GetDays();
	intYear=y1;
	intMonth=m1;
	intDay=d1;
	do
	{
		intCountYear+=1000;
		intResultYear=intYear-intCountYear;
	}
	while(intResultYear>=0);
	intCountYear-=1000;
	intYear-=intCountYear;
	//////////////////////////////
	StrYear.Format("%x",intYear);
	chrbuf=StrYear.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrYear="0"+StrYear;
	}
	///////////////////////////////
	StrMonth.Format("%x",intMonth);
	chrbuf=StrMonth.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrMonth="0"+StrMonth;
	}
	///////////////////////////
	StrDay.Format("%x",intDay);
	chrbuf=StrDay.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrDay="0"+StrDay;
	}
	///////////////////////////
	StrCount.Format("%x",intCount);
	chrbuf=StrCount.GetBuffer(0);
	intLen=strlen(chrbuf);
	while(intLen<4)
	{
		StrCount="0"+StrCount;
		chrbuf=StrCount.GetBuffer(0);
		intLen=strlen(chrbuf);
	}
	/////////////////////
	StrOutBuf=StrYear+StrMonth+StrDay+StrCount;
	return StrOutBuf;
}
bool CNabroSTBToolDlg::iniFunction()
{
	UpdateData(true);
		m_State="目前狀態 :正在下載清單";
		m_testButton.EnableWindow(false);
	UpdateData(false);
	GetConfigParameter();
	CString Filename;
	Filename="STBEnableList.xml";
	if(GetWebFile(m_StrEnableSTBUrl,Filename))
	{
		GetSTBInformation();
		int i,j;
		j=m_ArraySTBuid.GetSize();
		for(i=0;i<j;i++)
		{
			
			GetSTBMovieInformation(m_ArraySTBuid.GetAt(i));
		}
		UpdateData(true);
		m_State="目前狀態 :已下載完所有清單";
		m_testButton.EnableWindow(true);
		UpdateData(false);
		return true;
	}
	else
	{
		UpdateData(true);
		m_State="目前狀態 :以下載清單失敗";
		UpdateData(false);
		return false;
	}
}

void CAboutDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnTimer(nIDEvent);
}

void CNabroSTBToolDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	int i,j,k,l,m;
	CString Filename;
	CString StrSTBIP,StrSTBuid;
	if(nIDEvent==1)
	{
		KillTimer(1);
		blnALLthreadcheck=false;
		//CWinThread *pr=AfxBeginThread(ThreadFun,this,0,0,0,NULL);
		this->SetDlgItemText(IDC_State,"目前狀態 :正在下載清單");
		this->m_testButton.EnableWindow(false);
		MainAfS.GetConfigParameter();
		Filename="STBEnableList.xml";
		if(MainAfS.GetWebFile(MainAfS.m_StrEnableSTBUrl,Filename))
		{
			MainAfS.GetSTBInformation();
			threadAfS=new CAccessforSTB[50];
			i=0;
			k=0;
			l=0;
			j=MainAfS.m_ArraySTBuid.GetSize();
			m=j/gintthreadnumber;
			if((m*gintthreadnumber)!=j)
			{
				m=m+1;
			}
			for(i=0;i<j;i++)
			{
				l++;
				StrSTBIP=MainAfS.m_ArraySTBIP.GetAt(i);
				StrSTBuid=MainAfS.m_ArraySTBuid.GetAt(i);
				threadAfS[k].m_StrEnableuidUrl=MainAfS.m_StrEnableuidUrl;
				threadAfS[k].m_ArraySTBIP.Add(StrSTBIP);
				threadAfS[k].m_ArraySTBuid.Add(StrSTBuid);
				if(l%m==0)
				{
					k++;
				}
			}
			j=gintthreadnumber;
			i=0;
			ShowWindow(SW_MINIMIZE);
			for(i=0;i<j;i++)
			{
				blnthreadcheck[i]=false;
				AfxBeginThread(Thread50Fun,&i,0,0,0,NULL);
				Sleep(200);
			}
		}
		SetTimer(2,100,NULL);
	}
	else
	{
		if(blnALLthreadcheck==true)
		{
			KillTimer(2);
			delete [] threadAfS;
			this->OnOK();
		}
	}
	CDialog::OnTimer(nIDEvent);
}
UINT CNabroSTBToolDlg::Thread50Fun(LPVOID lpram)
{
	CNabroSTBToolDlg *u=(CNabroSTBToolDlg *)::AfxGetMainWnd();
	int intindex,*pintdata;
	int i,j,m;
	CString Struid;
	CString StrIP;
	CString StrBuf;
	CString StrRunStateFileName;
	pintdata=(int *) lpram;
	intindex=0;
	intindex=*pintdata;
	j=threadAfS[intindex].m_ArraySTBuid.GetSize();
	for(i=0;i<j;i++)
	{
		threadAfS[intindex].GetSTBMovieInformation(threadAfS[intindex].m_ArraySTBuid.GetAt(i));
	}
	//u->SetDlgItemText(IDC_State,"目前狀態 :已下載完所有清單");
	//u->m_testButton.EnableWindow(true);
	//u->m_testButton.EnableWindow(false);
	//u->ShowWindow(SW_MINIMIZE);
	j=threadAfS[intindex].m_ArraySTBuid.GetSize();
	StrRunStateFileName.Format("RunState%d.txt",intindex);
	FILE *pfRunState;
	pfRunState=fopen(StrRunStateFileName.GetBuffer(0),"w");
	for(i=0;i<j;i++)
	{
		Struid=threadAfS[intindex].m_ArraySTBuid.GetAt(i);
		StrIP=threadAfS[intindex].m_ArraySTBIP.GetAt(i);
		u->SetDlgItemText(IDC_EDIT1,Struid.GetBuffer(0));
		u->SetDlgItemText(IDC_IPADDRESS1,StrIP.GetBuffer(0));
		StrBuf.Format("目前狀態 :讀取IP=%s的影片清單...",StrIP.GetBuffer(0));
		u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
		threadAfS[intindex].InitReadXML();
		threadAfS[intindex].ReadAVListXML(Struid);
		StrBuf.Format("目前狀態 :IP=%s網路連線中...",StrIP.GetBuffer(0));
		u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
		if(threadAfS[intindex].ConnectSTB(StrIP,intindex))
		{
			Sleep(200);
			StrBuf.Format("目前狀態 :讀取IP=%s的STB內的檔案清單...",StrIP.GetBuffer(0));
			u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			threadAfS[intindex].ReadSTBAVList(StrIP);
			StrBuf.Format("目前狀態 :對IP=%s的STB進行補檔...",StrIP.GetBuffer(0));
			u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			threadAfS[intindex].STBAddAVFile(Struid,StrIP);
			StrBuf.Format("目前狀態 :對IP=%s的STB進行刪檔...",StrIP.GetBuffer(0));
			u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			threadAfS[intindex].STBDelAVFile(Struid,StrIP);
			fprintf(pfRunState,"%s\t%s\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
		}
		else
		{
			fprintf(pfRunState,"%s\t%s\tNo Connect\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
		}
	}
	fclose(pfRunState);
	////////////////////////////////////////////////////////////////////////////////////////////
	blnthreadcheck[intindex]=true;
	j=gintthreadnumber;
	m=0;
	for(i=0;i<j;i++)
	{
		if(blnthreadcheck[i]==true)
		{
			m++;
		}
	}
	if(m==gintthreadnumber)
	{
		blnALLthreadcheck=true;
	}
	return 0;
}
UINT CNabroSTBToolDlg::ThreadFun(LPVOID lpram)//Step 2:執行緒
{
	CNabroSTBToolDlg *u=(CNabroSTBToolDlg *)lpram;
	CAccessforSTB AfS;
	CString Struid;
	CString StrIP;
	CString StrBuf;
	//////////////////////////////////////////////////////
	//iniFunction()
	u->SetDlgItemText(IDC_State,"目前狀態 :正在下載清單");
	u->m_testButton.EnableWindow(false);
	AfS.GetConfigParameter();
	CString Filename;
	Filename="STBEnableList.xml";
	if(AfS.GetWebFile(AfS.m_StrEnableSTBUrl,Filename))
	{
		AfS.GetSTBInformation();
		int i,j;
		j=AfS.m_ArraySTBuid.GetSize();
		for(i=0;i<j;i++)
		{
			
			AfS.GetSTBMovieInformation(AfS.m_ArraySTBuid.GetAt(i));
		}
		u->SetDlgItemText(IDC_State,"目前狀態 :已下載完所有清單");
		u->m_testButton.EnableWindow(true);
		//////////////////////////////////////////////////////////////
		FILE *pfRunState;
		pfRunState=fopen("RunState.txt","w");
		fclose(pfRunState);
		pfRunState=NULL;
		u->m_testButton.EnableWindow(false);
		u->ShowWindow(SW_MINIMIZE);
		j=AfS.m_ArraySTBuid.GetSize();
		for(i=0;i<j;i++)
		{
			Struid=AfS.m_ArraySTBuid.GetAt(i);
			StrIP=AfS.m_ArraySTBIP.GetAt(i);
			u->SetDlgItemText(IDC_EDIT1,Struid.GetBuffer(0));
			u->SetDlgItemText(IDC_IPADDRESS1,StrIP.GetBuffer(0));
			StrBuf.Format("目前狀態 :讀取IP=%s的影片清單...",StrIP.GetBuffer(0));
			u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			AfS.ReadAVListXML(Struid);
			StrBuf.Format("目前狀態 :IP=%s網路連線中...",StrIP.GetBuffer(0));
			u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
			if(AfS.ConnectSTB(StrIP,0))
			{
				StrBuf.Format("目前狀態 :讀取IP=%s的STB內的檔案清單...",StrIP.GetBuffer(0));
				u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
				AfS.ReadSTBAVList(StrIP);
				StrBuf.Format("目前狀態 :對IP=%s的STB進行補檔...",StrIP.GetBuffer(0));
				u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
				AfS.STBAddAVFile(Struid,StrIP);
				StrBuf.Format("目前狀態 :對IP=%s的STB進行刪檔...",StrIP.GetBuffer(0));
				u->SetDlgItemText(IDC_State,StrBuf.GetBuffer(0));
				AfS.STBDelAVFile(Struid,StrIP);
				pfRunState=fopen("RunState.txt","a");
				fprintf(pfRunState,"%s\t%s\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
				fclose(pfRunState);
				pfRunState=NULL;
			}
			else
			{
				pfRunState=fopen("RunState.txt","a");
				fprintf(pfRunState,"%s\t%s\t Not Connect\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
				fclose(pfRunState);
				pfRunState=NULL;
			}
		}
		//*/
		u->m_testButton.EnableWindow(true);
		u->OnOK();
	}
	else
	{
		u->SetDlgItemText(IDC_State,"目前狀態 :以下載清單失敗");
	}
	///////////////////////////////////////////////////////////////
	return 0;
}