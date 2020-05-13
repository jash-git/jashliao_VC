// chtvSignage_CommunicationDlg.cpp : implementation file
//

#include "stdafx.h"
#include "chtvSignage_Communication.h"
#include "chtvSignage_CommunicationDlg.h"
////////////////////////////
//要查MAC的函式庫
#include < windows.h >
#include < wincon.h >
#include < stdlib.h >
#include < stdio.h >
#include < time.h >
#include < nb30.h >
///////////////////////////
//要查MAC的結構體
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
typedef struct _ASTAT_{    
	ADAPTER_STATUS adapt;    
	NAME_BUFFER    NameBuff [30];
}ASTAT, * PASTAT;
ASTAT Adapter;
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
// CChtvSignage_CommunicationDlg dialog

CChtvSignage_CommunicationDlg::CChtvSignage_CommunicationDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChtvSignage_CommunicationDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChtvSignage_CommunicationDlg)
	m_Edit1 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChtvSignage_CommunicationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChtvSignage_CommunicationDlg)
	DDX_Text(pDX, IDC_EDIT1, m_Edit1);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChtvSignage_CommunicationDlg, CDialog)
	//{{AFX_MSG_MAP(CChtvSignage_CommunicationDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChtvSignage_CommunicationDlg message handlers

BOOL CChtvSignage_CommunicationDlg::OnInitDialog()
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
	m_Edit1="0";
	InitialVariable();
	CreateNetDir();
	UpLoadLogFile();
	//ReadXmlPlayList();
	//ListingDownLoadFile();
	SetTimer(1,6000,NULL);
	this->ShowWindow(SW_MINIMIZE); 
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChtvSignage_CommunicationDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChtvSignage_CommunicationDlg::OnPaint() 
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
HCURSOR CChtvSignage_CommunicationDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChtvSignage_CommunicationDlg::ReadXmlPlayList()
{
	////////////////////////////////////////////////////////////
	//區域變數宣告區
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMNodePtr pNodeRoot;
	MSXML2::IXMLDOMNodeListPtr  pNodeList;
	MSXML2::IXMLDOMNodePtr   pNode;
	_variant_t variantValue;
	int nLen=0;
	int i=0,j=0;
	CString StrPlayListDir="";
	CString StrPlayListData="";
	CString StrNodeName="";
	bool blnRead=false;
	////////////////////////////////////////////////////////////
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));//建立XML物件
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	//nLen= ::GetCurrentDirectory(500,m_chrCurDrt);//取得目前程式路徑
	StrPlayListDir=m_chrCurDrt;
	//StrPlayListDir+="\\Resources\\Data\\PlayList\\PlayList.xml";
	StrPlayListDir+=m_StrCheckPlayList_XML;
	blnRead=pDoc->load((_bstr_t)StrPlayListDir);//讀取設定檔
	if(blnRead)
	{
		m_ArrPlayListData.RemoveAll(); 
		pNodeRoot=pDoc->selectSingleNode("//appSetting");
		pNodeRoot->get_childNodes(&pNodeList);
		j=pNodeList->length;
		for(i=0;i<j;i++)
		{
			pNode=pNodeList->item[i];
			StrNodeName=(char *)pNode->GetnodeName(); 
			if(StrNodeName!="fcount")
			{
				pNode->get_nodeTypedValue(&variantValue);
				StrPlayListData=variantValue.bstrVal;
				m_ArrPlayListData.Add(StrPlayListData);
				//MessageBox(StrPlayListData);
			}
		}
	}
}

void CChtvSignage_CommunicationDlg::ListingDownLoadFile()
{
	/////////////////////////////////////////////////////
	//區域變數宣告區
	int i=0,j=0;
	CString StrPlayDataDir="";
	CString StrFileName="";
	bool blnIsOK=true;
	/////////////////////////////////////////////////////
	m_ArrDownLoadFileData.RemoveAll();
	StrPlayDataDir=m_chrCurDrt;
	//StrPlayDataDir+="\\Resources\\movies\\";
	StrPlayDataDir+=m_StrMovie_path;
	j=m_ArrPlayListData.GetSize();
	for(i=0;i<j;i++)
	{
		StrFileName=m_ArrPlayListData.GetAt(i);
		blnIsOK=SearchFile(StrPlayDataDir,StrFileName);
		if(blnIsOK==false)
		{
			m_ArrDownLoadFileData.Add(StrFileName);
			//StrFileName="要下載的檔案:"+StrFileName;
			//MessageBox(StrFileName);
		}
	}
}

bool CChtvSignage_CommunicationDlg::SearchFile(CString strDir,CString strFile)
{
	bool returnData=false;
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.GetFileName()==strFile)
		{
			returnData=true;
			break;
		}
	}
	ff.Close();//壽敕
	return returnData;;
}

void CChtvSignage_CommunicationDlg::InitialVariable()
{
	////////////////////////////////////////////////////////////
	//區域變數宣告區
	MSXML2::IXMLDOMDocumentPtr pDoc1;
	MSXML2::IXMLDOMNodePtr pNode;
	_variant_t variantValue;
	bool blnRead=false;
	CString StrSettingFilePath;
	int nLen=0;
	////////////////////////////////////////////////////////////
	HRESULT hr = pDoc1.CreateInstance(__uuidof(MSXML2::DOMDocument30));//建立XML物件
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	nLen= ::GetCurrentDirectory(500,m_chrCurDrt);//取得目前程式路徑
	StrSettingFilePath=m_chrCurDrt;
	StrSettingFilePath+="\\Resources\\Setting\\Communication.xml";
	blnRead=pDoc1->load((_bstr_t)StrSettingFilePath);//讀取設定檔
	if(blnRead)
	{
		//CSting m_StrGet_Data,m_StrRunText_XML,m_StrCheckPlayList_XML,m_StrPlayList_XML;
		//CSting m_StrMovie_path,m_StrCreateNet_Bat,m_StrDownLoad_Path,m_StrUpLoad_Path;	
		pNode=pDoc1->selectSingleNode("//Get_Data");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrGet_Data=variantValue.bstrVal;
		///////////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//RunText_XML");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrRunText_XML=variantValue.bstrVal;
		////////////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//CheckPlayList_XML");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrCheckPlayList_XML=variantValue.bstrVal;
		///////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//PlayList_XML");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrPlayList_XML=variantValue.bstrVal;
		/////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//Movie_path");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrMovie_path=variantValue.bstrVal;
		////////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//CreateNet_Bat");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrCreateNet_Bat=variantValue.bstrVal;
		////////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//DownLoad_Path");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrDownLoad_Path=variantValue.bstrVal;
		/////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//UpLoad_Path");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrUpLoad_Path=variantValue.bstrVal;
		////////////////////////////////////////////////
		pNode=pDoc1->selectSingleNode("//PlayLog");
		pNode->get_nodeTypedValue(&variantValue);
		m_StrUpLoad_FilePath=variantValue.bstrVal;
	}
	///////////////////////////////////////////////////////////////////////////////////
}

void CChtvSignage_CommunicationDlg::UpLoadLogFile()
{
	/////////////////////////////////////////////////////
	//區域變數宣告區
	CTime t1;
	CTime tmPreOneDay;
	CTimeSpan tmspanTwoDay(1,0,0,0);  
	CString StrFileName;
	CString StrLoadUploadPath;
	CString StrLoadUploadFile;
	CString StrNetUploadFile;
	bool blnCopyOK=true;
	///////////////////////////////////////////////////////
	t1=CTime::GetCurrentTime();
	tmPreOneDay=t1-tmspanTwoDay;
	StrFileName=tmPreOneDay.Format("%Y%m%d"); 
	StrFileName+="run_";
	////////////////////////////////////////////////////////////////
	NCB Ncb;
    UCHAR uRetCode;
    //char NetName[50];
    LANA_ENUM lenum;
    int i;
	char sMacAddress[100];
    memset( &Ncb, 0, sizeof(Ncb) );
    Ncb.ncb_command = NCBENUM;
    Ncb.ncb_buffer = (UCHAR *)&lenum;
    Ncb.ncb_length = sizeof(lenum);
    uRetCode = Netbios( &Ncb );
    for(i=0; i < lenum.length ;i++)
    {
		memset( &Ncb, 0, sizeof(Ncb) );
		Ncb.ncb_command = NCBRESET;
		Ncb.ncb_lana_num = lenum.lana[i];
		uRetCode = Netbios( &Ncb );

		memset( &Ncb, 0, sizeof (Ncb) );
		Ncb.ncb_command = NCBASTAT;
		Ncb.ncb_lana_num = lenum.lana[i];

		strcpy( (char*)Ncb.ncb_callname, "* " );
		Ncb.ncb_buffer = (unsigned char *) &Adapter;
		Ncb.ncb_length = sizeof(Adapter);
		uRetCode = Netbios( &Ncb );
	}
	if ( uRetCode == 0 )
	{		
     sprintf(sMacAddress, "%02x%02x%02x%02x%02x%02x\n",
     Adapter.adapt.adapter_address[0],
     Adapter.adapt.adapter_address[1],
     Adapter.adapt.adapter_address[2],
     Adapter.adapt.adapter_address[3],
     Adapter.adapt.adapter_address[4],
     Adapter.adapt.adapter_address[5] );

	}
	//UpdateData(true);
		m_StrMAC=sMacAddress;
		m_StrMAC.MakeUpper();
		m_StrMAC=m_StrMAC.Mid(0,12);
	//UpdateData(false);
	//////////////////////////////////////////////////////////////////
	StrFileName+=m_StrMAC;
	StrFileName+=".log";
	StrLoadUploadFile=m_chrCurDrt;
	StrLoadUploadFile+=m_StrUpLoad_FilePath;
	StrLoadUploadPath=StrLoadUploadFile;
	StrLoadUploadFile+=StrFileName;
	//======================================================
	blnCopyOK=SearchFile(StrLoadUploadPath,StrFileName);
	if(blnCopyOK)
	{
		StrNetUploadFile=m_StrUpLoad_Path;
		StrNetUploadFile+=StrFileName;
		blnCopyOK=CopyFile(StrLoadUploadFile,StrNetUploadFile,false);
		if(blnCopyOK)
		{
			DeleteFile(StrLoadUploadFile);
		}
	}
	///////////////////////////////////////////////////////////////////
}

void CChtvSignage_CommunicationDlg::CreateNetDir()
{
	CString StrBatFile;
	StrBatFile=m_chrCurDrt;
	StrBatFile+=m_StrCreateNet_Bat;
	ShellExecute(NULL,"open",StrBatFile,NULL,NULL,SW_SHOWNORMAL); 
}

void CChtvSignage_CommunicationDlg::DownLoadMovieFile()
{
	///////////////////////////////////////////////////////
	//區域變數宣告區
	CString StrFileName;
	CString StrSourceFile;
	CString StrLocalFile;
	CString StrSourceListFile;
	CString StrLocalListFile;
	int i,j;
	bool blnCopyOK=true;
	///////////////////////////////////////////////////////
	j=m_ArrDownLoadFileData.GetSize();
	for(i=0;i<j;i++)
	{
		StrFileName=m_ArrDownLoadFileData.GetAt(i);
		StrSourceFile=m_StrDownLoad_Path;
		StrSourceFile+=StrFileName;
		//==================================================
		StrLocalFile=m_chrCurDrt;
		StrLocalFile+=m_StrMovie_path;
		StrLocalFile+=StrFileName;
		//===================================================
		blnCopyOK=SearchFile(m_StrDownLoad_Path,StrFileName);
		if(blnCopyOK)
		{
			blnCopyOK=CopyFile(StrSourceFile,StrLocalFile,false);
		}
		if(blnCopyOK==false)
		{
			break;
		}
	}
	if(blnCopyOK)
	{
		StrSourceListFile=m_chrCurDrt;
		StrSourceListFile+=m_StrCheckPlayList_XML;
		//=======================================
		StrLocalListFile=m_chrCurDrt;
		StrLocalListFile+=m_StrPlayList_XML;
		blnCopyOK=CopyFile(StrSourceListFile,StrLocalListFile,false);
	}
}

bool CChtvSignage_CommunicationDlg::DownLoadXML()
{
	////////////////////////////////////////////////////////
	//區域變數宣告區
	CString StrSourceRunTextFile,StrSourcePlayListFile;
	CString StrLocalRunTextFile,StrLocalPlayListFile;
	CString StrRunTextName,StrPlayListName;
	bool blnFindRunText=false,blnFindPlayList=false;
	bool blnCopyRunText=false,blnCopyPlayList=false;
	bool blndel=false;
	////////////////////////////////////////////////////////
	StrRunTextName="chtvInfoData.xml";
	StrPlayListName="PlayList.xml";
	StrSourceRunTextFile=m_StrDownLoad_Path+StrRunTextName;
	StrSourcePlayListFile=m_StrDownLoad_Path+StrPlayListName;
	StrLocalRunTextFile=m_chrCurDrt;
	StrLocalRunTextFile+=m_StrRunText_XML;
	StrLocalPlayListFile=m_chrCurDrt;
	StrLocalPlayListFile+=m_StrCheckPlayList_XML;
	////////////////////////////////////////////////////////////////////////
	blnFindRunText=SearchFile(m_StrDownLoad_Path,StrRunTextName);
	if(blnFindRunText)
	{
		blnCopyRunText=CopyFile(StrSourceRunTextFile,StrLocalRunTextFile,false);
		if(blnCopyRunText)
		{
			blndel=DeleteFile(StrSourceRunTextFile);
		}
	}
	/////////////////////////////////////////////////////////////////////////
	blnFindPlayList=SearchFile(m_StrDownLoad_Path,StrPlayListName);
	if(blnFindPlayList)
	{
		blnCopyPlayList=CopyFile(StrSourcePlayListFile,StrLocalPlayListFile,false);
		if(blnCopyPlayList)
		{
			DeleteFile(StrSourcePlayListFile);
		}
		return blnCopyPlayList;
	}
	else
	{
		return false;
	}
}

void CChtvSignage_CommunicationDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	bool blnGetXML=false;
	KillTimer(1);
	UpLoadLogFile();
	blnGetXML=DownLoadXML();//下載播放清單和跑馬資料
	if(blnGetXML)
	{
		ReadXmlPlayList();
		ListingDownLoadFile();
		DownLoadMovieFile();
	}
	UpdateData(true);
		if(m_Edit1==m_StrMAC)
			m_Edit1="0";
		else
			m_Edit1=m_StrMAC;
	UpdateData(false);
	SetTimer(1,6000,NULL);
	CDialog::OnTimer(nIDEvent);
}
