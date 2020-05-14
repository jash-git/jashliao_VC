// ChangeSTBforJennyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeSTBforJenny.h"
#include "ChangeSTBforJennyDlg.h"
#include "FileCopyDelete.h"
#include "NetUsebat.h"
#include "AccessforSTB.h"
#include "WebInformation.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BUFFER_SIZE 2048//http_download
TCHAR gstrCurDrt[500];//存放目其目錄字串
CAccessforSTB MainAfS;
CFileCopyDelete FCDUpdateData;
CFileCopyDelete FCDUpdateData1;
CFileCopyDelete FCDUpdateData2;
CFileCopyDelete FCDUpdateData3;
CFileCopyDelete FCDUpdateData4;
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
// CChangeSTBforJennyDlg dialog

CChangeSTBforJennyDlg::CChangeSTBforJennyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeSTBforJennyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeSTBforJennyDlg)
	m_ShowState = _T("");
	m_blnLayout = FALSE;
	m_blnMovie = FALSE;
	m_blnRegist = FALSE;
	m_blnRemoteControl = FALSE;
	m_blnTime = FALSE;
	m_blnUpdateData = FALSE;
	m_blnVolume = FALSE;
	m_StrLayout = _T("");
	m_StrTime = _T("");
	m_StrUID = _T("");
	m_blnDeleteMovie = FALSE;
	m_blnTUKA = FALSE;
	m_blnEIPFlow = FALSE;
	m_blnCompletionSerch = FALSE;
	m_blnSTBCommand = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeSTBforJennyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeSTBforJennyDlg)
	DDX_Control(pDX, IDC_COMBOSTBCommand, m_ComboSTBCommand);
	DDX_Control(pDX, IDC_ButtSTBCommand, m_ButtSTBCommand);
	DDX_Control(pDX, IDC_ButtCompletionSerch, m_ButtCompletionSerch);
	DDX_Control(pDX, IDC_ButtEIPFlow, m_ButtEIPFlow);
	DDX_Control(pDX, IDC_ButtTUKA, m_ButtTUKA);
	DDX_Control(pDX, IDC_ButtDeleteMovie, m_ButtDeleteMovie);
	DDX_Control(pDX, IDC_IPADDRESS, m_IP);
	DDX_Control(pDX, IDC_COMBOVolume, m_ComboVolume);
	DDX_Control(pDX, IDC_ButtVolume, m_ButtVolume);
	DDX_Control(pDX, IDC_ButtUpdateData, m_ButtUpdateData);
	DDX_Control(pDX, IDC_ButtSetIPandUID, m_ButtSetIPandUID);
	DDX_Control(pDX, IDC_ButtSelectLayout, m_ButtSelectLayout);
	DDX_Control(pDX, IDC_ButtRemoteControl, m_ButtRemoteControl);
	DDX_Control(pDX, IDC_ButtRegistration, m_ButtRegistration);
	DDX_Control(pDX, IDC_ButtMovie, m_ButtMovie);
	DDX_Control(pDX, IDC_ButtLayout, m_ButtLayout);
	DDX_Control(pDX, IDC_ButtBootTime, m_ButtBootTime);
	DDX_Control(pDX, IDC_ButtALLAuto, m_ButtALLAuto);
	DDX_Text(pDX, IDC_ShowState, m_ShowState);
	DDX_Check(pDX, IDC_CHECKLayout, m_blnLayout);
	DDX_Check(pDX, IDC_CHECKMovie, m_blnMovie);
	DDX_Check(pDX, IDC_CHECKRegist, m_blnRegist);
	DDX_Check(pDX, IDC_CHECKRemoteControl, m_blnRemoteControl);
	DDX_Check(pDX, IDC_CHECKTime, m_blnTime);
	DDX_Check(pDX, IDC_CHECKUpdateData, m_blnUpdateData);
	DDX_Check(pDX, IDC_CHECKVolume, m_blnVolume);
	DDX_Text(pDX, IDC_EDITLayout, m_StrLayout);
	DDX_Text(pDX, IDC_EDITTime, m_StrTime);
	DDX_Text(pDX, IDC_EDITUID, m_StrUID);
	DDX_Check(pDX, IDC_CHECKDeleteMovie, m_blnDeleteMovie);
	DDX_Check(pDX, IDC_CHECKTUKA, m_blnTUKA);
	DDX_Check(pDX, IDC_CHECKEIPFlow, m_blnEIPFlow);
	DDX_Check(pDX, IDC_CHECKCompletionSerch, m_blnCompletionSerch);
	DDX_Check(pDX, IDC_CHECKSTBCommand, m_blnSTBCommand);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeSTBforJennyDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeSTBforJennyDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_ButtSetIPandUID, OnButtSetIPandUID)
	ON_BN_CLICKED(IDC_ButtSelectLayout, OnButtSelectLayout)
	ON_BN_CLICKED(IDC_ButtRegistration, OnButtRegistration)
	ON_BN_CLICKED(IDC_ButtMovie, OnButtMovie)
	ON_BN_CLICKED(IDC_ButtLayout, OnButtLayout)
	ON_BN_CLICKED(IDC_ButtVolume, OnButtVolume)
	ON_BN_CLICKED(IDC_ButtBootTime, OnButtBootTime)
	ON_NOTIFY(IPN_FIELDCHANGED, IDC_IPADDRESS, OnFieldchangedIpaddress)
	ON_BN_CLICKED(IDC_ButtUpdateData, OnButtUpdateData)
	ON_BN_CLICKED(IDC_ButtALLAuto, OnButtALLAuto)
	ON_BN_CLICKED(IDC_ButtRemoteControl, OnButtRemoteControl)
	ON_BN_CLICKED(IDC_ButtDeleteMovie, OnButtDeleteMovie)
	ON_BN_CLICKED(IDC_ButtTUKA, OnButtTUKA)
	ON_BN_CLICKED(IDC_ButtEIPFlow, OnButtEIPFlow)
	ON_BN_CLICKED(IDC_ButtCompletionSerch, OnButtCompletionSerch)
	ON_BN_CLICKED(IDC_ButtSTBCommand, OnButtSTBCommand)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeSTBforJennyDlg message handlers

BOOL CChangeSTBforJennyDlg::OnInitDialog()
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
	UpdateData(true);
		m_ShowState="目前狀態 :正在下載清單";
		m_blnLayout=0;
		m_blnMovie=0;
		m_blnRegist=0;
		m_blnRemoteControl=0;
		m_blnTime=0;
		m_blnUpdateData=0;
		m_blnVolume=0;
		m_StrLayout="Non ...";
		m_StrTime="Non ...";
		m_StrUID="Non ...";
	UpdateData(false);
	m_IP.SetWindowText("0.0.0.0");
	m_ComboVolume.SetWindowText("Non ...");
	//m_ButtVolume.EnableWindow(false);
	//m_ButtUpdateData.EnableWindow(false);
	//m_ButtSetIPandUID.EnableWindow(false);
	//m_ButtSelectLayout.EnableWindow(false);
	//m_ButtRemoteControl.EnableWindow(false);
	//m_ButtRegistration.EnableWindow(false);
	m_ButtMovie.EnableWindow(false);
	//m_ButtLayout.EnableWindow(false);
	//m_ButtBootTime.EnableWindow(false);
	//m_ButtALLAuto.EnableWindow(false);
	SetTimer(1,100,NULL);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChangeSTBforJennyDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChangeSTBforJennyDlg::OnPaint() 
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
HCURSOR CChangeSTBforJennyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

HBRUSH CChangeSTBforJennyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetBkColor(RGB(255,255,255));
	pDC->SetTextColor(RGB(0,0,255)); 
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CChangeSTBforJennyDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	iniFunction();
	//this->OnOK();
	CDialog::OnTimer(nIDEvent);
}
bool CChangeSTBforJennyDlg::iniFunction()
{
	CFileCopyDelete FCD;
	CFileCopyDelete FCD1;
	CArray <CString,CString&> m_ArrayVolume;
	CArray <CString,CString&> m_ArrayCommand;
	GetConfigParameter();
	CString Filename;
	CString StrLayoutBuf;
	CString StrVolumeBuf;
	CString StrCommandBuf;
	CString StrFCDBuf;
	Filename="STBEnableList.xml";
	if(GetWebFile(m_StrEnableSTBUrl,Filename))
	{
		GetSTBInformation();
		int i,j;
		/*
		j=m_ArraySTBuid.GetSize();
		for(i=0;i<j;i++)
		{	
			GetSTBMovieInformation(m_ArraySTBuid.GetAt(i));
		}
		*/
		AfxBeginThread(ThreadDownLoadMovieList,this,0,0,0,NULL);
		StrLayoutBuf=m_StrNetDir+"\\Act_Template\\On_3_airnet_01_80%_30sCmd.Msg";
		StrFCDBuf=m_StrNetDir+"\\Volume\\";
		FCD.BrowseDir(StrFCDBuf,1);
		FCD.GetArrayData(1,&m_ArrayVolume);
		j=m_ArrayVolume.GetSize();
		m_ComboVolume.SetWindowText("");
		for(i=0;i<j;i++)
		{
			StrVolumeBuf=m_StrNetDir+"\\Volume\\";
			StrVolumeBuf+=m_ArrayVolume.GetAt(i);
			m_ComboVolume.AddString(StrVolumeBuf);
			m_ComboVolume.SetWindowText(StrVolumeBuf);
		}
		StrVolumeBuf=m_StrNetDir+"\\Volume\\";
		StrVolumeBuf+="Volume15Cmd.Msg";
		m_ComboVolume.SetWindowText(StrVolumeBuf);
		//*************************************
		StrFCDBuf=m_StrNetDir+"\\Command\\";
		FCD1.BrowseDir(StrFCDBuf,1);
		FCD1.GetArrayData(1,&m_ArrayCommand);
		j=m_ArrayCommand.GetSize();
		for(i=0;i<j;i++)
		{
			StrCommandBuf=m_StrNetDir+"\\Command\\";
			StrCommandBuf+=m_ArrayCommand.GetAt(i);
			m_ComboSTBCommand.AddString(StrCommandBuf);
			m_ComboSTBCommand.SetWindowText(StrCommandBuf);
		}
		UpdateData(true);
			m_ShowState="目前狀態 :已下載完所有清單";
			m_StrLayout=StrLayoutBuf;
			m_StrTime="";
			m_StrUID="";
		UpdateData(false);
		m_ButtSetIPandUID.EnableWindow(true);
		m_ButtVolume.EnableWindow(true);
		m_ButtUpdateData.EnableWindow(true);
		m_ButtSelectLayout.EnableWindow(true);
		m_ButtRemoteControl.EnableWindow(true);
		m_ButtRegistration.EnableWindow(true);
		m_ButtLayout.EnableWindow(true);
		m_ButtBootTime.EnableWindow(true);
		m_ButtALLAuto.EnableWindow(true);
		return true;
	}
}
void CChangeSTBforJennyDlg::GetConfigParameter()//step 4:讀取XML
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
bool CChangeSTBforJennyDlg::GetWebFile(CString theUrl, CString Filename)//http_download
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
void CChangeSTBforJennyDlg::GetSTBInformation()
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
void CChangeSTBforJennyDlg::GetSTBMovieInformation(CString StrSTBuid)
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

void CChangeSTBforJennyDlg::OnButtSetIPandUID() 
{
	// TODO: Add your control notification handler code here
	int i,j;
	bool blnfind=false;
	CString StrIPBuf;
	CString StrUIDBuf;
	CString StrTimeBuf;
	j=m_ArraySTBuid.GetSize();
	m_IP.GetWindowText(StrIPBuf);
	if(StrIPBuf!="0.0.0.0")
	{
		for(i=0;i<j;i++)
		{
			blnfind=false;
			StrUIDBuf="";
			if(m_ArraySTBIP.GetAt(i)==StrIPBuf)
			{
				StrUIDBuf=m_ArraySTBuid.GetAt(i);
				blnfind=true;
				break;
			}
		}
		if(blnfind)
		{
			StrTimeBuf=m_StrNetDir+"\\Vga_Template\\";
			StrTimeBuf+=StrIPBuf;
			StrTimeBuf+="Cmd.msg";
			UpdateData(true);
				m_StrUID=StrUIDBuf;
				m_StrNowIP=StrIPBuf;
				m_StrTime=StrTimeBuf;
				m_StrNowUID=StrUIDBuf;
			UpdateData(false);
			m_ButtVolume.EnableWindow(true);
			m_ButtUpdateData.EnableWindow(true);
			m_ButtSelectLayout.EnableWindow(true);
			m_ButtRemoteControl.EnableWindow(true);
			m_ButtRegistration.EnableWindow(true);
			m_ButtMovie.EnableWindow(true);
			m_ButtLayout.EnableWindow(true);
			m_ButtBootTime.EnableWindow(true);
			m_ButtALLAuto.EnableWindow(true);
		}
		else
		{
			UpdateData(true);
				m_StrUID="Not finded";
			UpdateData(false);
			m_ButtVolume.EnableWindow(false);
			m_ButtUpdateData.EnableWindow(false);
			m_ButtSelectLayout.EnableWindow(false);
			m_ButtRemoteControl.EnableWindow(false);
			m_ButtRegistration.EnableWindow(false);
			m_ButtMovie.EnableWindow(false);
			m_ButtLayout.EnableWindow(false);
			m_ButtBootTime.EnableWindow(false);
			m_ButtALLAuto.EnableWindow(false);
		}
	}
}

void CChangeSTBforJennyDlg::OnButtSelectLayout() 
{
	// TODO: Add your control notification handler code here
	CFileDialog fdlg(true,NULL,"On_3_airnet_01_80%_30sCmd",NULL,"MSG|*.msg");
	fdlg.m_ofn.lpstrInitialDir=m_StrNetDir+"\\Act_Template\\";  
	if(fdlg.DoModal()==IDOK)
	{
		UpdateData(true);
			m_StrLayout=fdlg.GetPathName();
		UpdateData(false);
	}
}

void CChangeSTBforJennyDlg::OnButtRegistration() 
{
	// TODO: Add your control notification handler code here
	//ShowWindow(SW_MINIMIZE);
	CString StrIPBuf;
	UpdateData(true);
		m_blnRegist=true;
		m_ShowState="目前狀態 :執行註冊中 ...";
	UpdateData(false);
	///////////////////////////////////////////////////////
	m_IP.GetWindowText(StrIPBuf);
	m_StrNowIP=StrIPBuf;
	CString StrTimeBuf;
	StrTimeBuf=m_StrNetDir+"\\Vga_Template\\";
	StrTimeBuf+=StrIPBuf;
	StrTimeBuf+="Cmd.msg";
	UpdateData(true);
		m_StrTime=StrTimeBuf;
	UpdateData(false);
	///////////////////////////////////////////////////////
	m_ButtRegistration.EnableWindow(false);
	AfxBeginThread(ThreadRegistration,this,0,0,0,NULL);
}
UINT CChangeSTBforJennyDlg::ThreadRegistration(LPVOID lpram)//Step 2:執行緒
{
	CChangeSTBforJennyDlg *u=(CChangeSTBforJennyDlg *)lpram;
	u->RegistrationFunction();
	u->ShowWindow(SW_SHOW);
	u->MessageBox("OK");
	return 0;
}
void CChangeSTBforJennyDlg::RegistrationFunction()
{
	CNetUsebat NUB;
	CString SQL;
	CString StrNetPath;
	bool checkDB=false;
	StrNetPath="\\\\";
	StrNetPath+=m_StrNowIP;
	StrNetPath+="\\D$\\NabroClient";
	NUB.Createbat("nabro","nabro",StrNetPath,0);
	CTime t1=CTime::GetCurrentTime();
	CString StrlogFileName;
	StrlogFileName.Format("%d%d%d_%s.txt",t1.GetYear(),t1.GetMonth(),t1.GetDay(),m_StrNowIP);
	FILE *pf;
	SetDlgItemText(IDC_ShowState,"目前狀態 :連結STB中...");
	if(NUB.CreateShareDir())
	{
		FILE *pf;
		//////////////////////////////////////////////////////////////////
		//取得MAC
		m_StrSTBMAC=GetMac(); 
		pf=fopen(StrlogFileName.GetBuffer(0),"w");
		fprintf(pf,"%s -> 連線成功\n",m_StrNowIP.GetBuffer(0));
		fprintf(pf,"%s -> %s\n",m_StrNowIP.GetBuffer(0) ,m_StrSTBMAC.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,"目前狀態 :取得MAC");
		fclose(pf);
		//////////////////////////////////////////////////////////////////
		CString StrBuf1,StrBuf2;
		CString StrNetBuf1,StrNetBuf2;
		StrNetBuf1=StrNetPath;
		StrNetBuf1+="\\Setting\\Registry\\HKEY_LOCAL_MACHINE\\SOFTWARE\\COMTREND\\NABRO\\Client\\FEEDBACKURL";
		StrBuf1=m_StrNetDir;
		StrBuf1+="\\Registry\\FEEDBACKURL";
		pf=fopen(StrlogFileName.GetBuffer(0),"a");
		if(CopyFile(StrBuf1,StrNetBuf1,false))
		{
			fprintf(pf,"%s -> %s OK\n",StrBuf1.GetBuffer(0),StrNetBuf1.GetBuffer(0));
		}
		else
		{
			fprintf(pf,"%s -> %s Not OK\n",StrBuf1.GetBuffer(0),StrNetBuf1.GetBuffer(0));
		}
		//********************
		StrNetBuf2=StrNetPath;
		StrNetBuf2+="\\Setting\\Registry\\HKEY_LOCAL_MACHINE\\SOFTWARE\\COMTREND\\NABRO\\Client\\LASTREGTIME";
		StrBuf2=m_StrNetDir;
		StrBuf2+="\\Registry\\LASTREGTIME";
		if(CopyFile(StrBuf2,StrNetBuf2,false))
		{
			fprintf(pf,"%s -> %s OK\n",StrBuf2.GetBuffer(0),StrNetBuf2.GetBuffer(0));
		}
		else
		{
			fprintf(pf,"%s -> %s Not OK\n",StrBuf2.GetBuffer(0),StrNetBuf2.GetBuffer(0));
		}
		fclose(pf);
		/////////////////////////////////////////////////////////////////
		//取得GUID
		FILE *pfGUID;
		CString StrGUID;
		char chrData[500];
		m_StrSTBSTBGUID="\\\\";
		m_StrSTBSTBGUID+=m_StrNowIP;
		m_StrSTBSTBGUID+="\\D$\\NabroClient\\Setting\\Registry\\HKEY_LOCAL_MACHINE\\SOFTWARE\\COMTREND\\NABRO\\Client\\GUID";
		pfGUID=fopen(m_StrSTBSTBGUID.GetBuffer(0),"r"); 
		while(fscanf(pfGUID,"%s",chrData)!=EOF)
		{
			StrGUID=chrData;
		}
		fclose(pfGUID);
		//*****************
		pf=fopen(StrlogFileName.GetBuffer(0),"a");
		fprintf(pf,"%s -> %s\n",m_StrNowIP.GetBuffer(0) ,StrGUID.GetBuffer(0));
		fclose(pf);
		SetDlgItemText(IDC_ShowState,"目前狀態 :取得GUID");
		/////////////////////////////////////////////////////////////////
		m_DB=new CDatabase();
		m_WebDB=new CDatabase();
		m_StrSouODBC="NabroDB";
		pf=fopen(StrlogFileName.GetBuffer(0),"a");
		checkDB=m_DB->Open(m_StrSouODBC);
		if(checkDB)
		{		
			//SQL="UPDATE client SET mac='mac' WHERE ip='ip' AND deleted=false";
			fprintf(pf,"連結資料庫 -> 成功\n");
			SetDlgItemText(IDC_ShowState,"目前狀態 :連結資料庫 -> 成功");
			SQL="UPDATE client SET mac='";
			SQL+=m_StrSTBMAC;
			SQL+="' WHERE ip='";
			SQL+=m_StrNowIP;
			SQL+="' AND deleted=false";
			m_DB->ExecuteSQL(SQL);
			fprintf(pf,"%s\n",SQL.GetBuffer(0));
			//SQL="UPDATE client SET guid='guid' WHERE ip='ip' AND deleted=false";
			SQL="UPDATE client SET guid='";
			SQL+=StrGUID;
			SQL+="' WHERE ip='";
			SQL+=m_StrNowIP;
			SQL+="' AND deleted=false";
			m_DB->ExecuteSQL(SQL);
			fprintf(pf,"%s\n",SQL.GetBuffer(0));
			//SQL="UPDATE client SET setup_date='2008-12-03 16:30:00' WHERE ip='ip' AND deleted=false";
			CString s;
			CTime t=CTime::GetCurrentTime();
			s= t.Format( "%Y-%m-%d %H:%M:%S" );
			SQL="UPDATE client SET setup_date='";
			SQL+=s;
			SQL+="' WHERE ip='";
			SQL+=m_StrNowIP;
			SQL+="' AND deleted=false";
			m_DB->ExecuteSQL(SQL);
			fprintf(pf,"%s\n",SQL.GetBuffer(0));
			m_DB->Close(); 
		}
		else
		{
			fprintf(pf,"連結資料庫 -> 失敗\n");
			SetDlgItemText(IDC_ShowState,"目前狀態 :連結資料庫 -> 失敗");
		}
		m_StrSouWebODBC="NabroWebDB";
		checkDB=m_WebDB->Open(m_StrSouWebODBC);
		if(checkDB)
		{
			fprintf(pf,"連結WEB資料庫 -> 成功\n");
			SetDlgItemText(IDC_ShowState,"目前狀態 :連結WEB資料庫 -> 成功");
			SQL="UPDATE running_text SET guid='";
			SQL+=StrGUID;
			SQL+="' WHERE ip='";
			SQL+=m_StrNowIP;
			SQL+="';";
			//u->MessageBox(SQL); 
			m_WebDB->ExecuteSQL(SQL);
			fprintf(pf,"%s\n",SQL.GetBuffer(0));
			SQL="UPDATE tuka SET guid='";
			SQL+=StrGUID;
			SQL+="' WHERE ip='";
			SQL+=m_StrNowIP;
			SQL+="';";
			//u->MessageBox(SQL); 
			m_WebDB->ExecuteSQL(SQL);
			fprintf(pf,"%s\n",SQL.GetBuffer(0));
			m_WebDB->Close(); 
			SetDlgItemText(IDC_ShowState,"完成註冊");
		}
		else
		{
			fprintf(pf,"連結WEB資料庫 -> 失敗\n");
			SetDlgItemText(IDC_ShowState,"連結WEB資料庫 -> 失敗");
		}
		fclose(pf);
		//*/
		delete m_DB;
		delete m_WebDB;
		/////////////////////////////////////////////////////////////////
	}
	else
	{
		SetDlgItemText(IDC_ShowState,"連結STB -> 失敗");
	}
}
CString CChangeSTBforJennyDlg::GetMac()
{
	bool blncheckbuf;
	FILE *pf;
	char chrData[500];
	CString StrBuf,StrBuf1; 
	StrBuf.Format("nbtstat -a %s >%s.txt",m_StrNowIP.GetBuffer(0),"mac");
	system(StrBuf.GetBuffer(0)); 
	Sleep(1000);
	blncheckbuf=false;
	//
	do
	{
		StrBuf.Format("%s.txt","mac");
		pf=fopen(StrBuf.GetBuffer(0),"r");
		if(pf==NULL)
		{
			blncheckbuf=false;
		}
		else
		{
			blncheckbuf=true;
		}
	}while(blncheckbuf==false);
	//
	blncheckbuf=false;
	while(fscanf(pf,"%s",chrData)!=EOF)
	{
		StrBuf=chrData;
		if(blncheckbuf)
		{
			break;	
		}
		if(StrBuf=="=")
		{
			blncheckbuf=true;
		}
	}
	fclose(pf);
	DeleteFile("mac.txt");
	return StrBuf;
}

void CChangeSTBforJennyDlg::OnButtMovie() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_blnMovie=true;
		m_ShowState="目前狀態 :準備執行影片刪/補檔 ...";
	UpdateData(false);
	m_ButtMovie.EnableWindow(false);
	AfxBeginThread(ThreadMovie,this,0,0,0,NULL);	
}
UINT CChangeSTBforJennyDlg::ThreadMovie(LPVOID lpram)
{
	CChangeSTBforJennyDlg *u=(CChangeSTBforJennyDlg *)lpram;
	::CoInitialize(NULL); //step 2:讀取XML
	u->Movie();
	u->ShowWindow(SW_SHOW);
	u->MessageBox("OK");
	u->OnOK();
	return 0;
}
void CChangeSTBforJennyDlg::Movie()
{
	CString Struid;
	CString StrIP;
	CString StrBuf;
	CString StrRunStateFileName;
	int i=0,j=0;
	int intindex=0;
	Struid=m_StrNowUID;
	StrIP=m_StrNowIP;
	StrBuf.Format("目前狀態 :讀取IP=%s的影片清單...",StrIP.GetBuffer(0));
	SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	//MainAfS.InitReadXML();
	MainAfS.ReadAVListXML(Struid);
	StrBuf.Format("目前狀態 :連線IP=%s的STB...",StrIP.GetBuffer(0));
	SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	StrRunStateFileName.Format("RunState%d.txt",intindex);
	FILE *pfRunState;
	pfRunState=fopen(StrRunStateFileName.GetBuffer(0),"w");
	if(MainAfS.ConnectSTB(StrIP,0))
	{
		Sleep(200);
		StrBuf.Format("目前狀態 :讀取IP=%s的STB內的檔案清單...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		MainAfS.ReadSTBAVList(StrIP);
		StrBuf.Format("目前狀態 :對IP=%s的STB進行補檔...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		MainAfS.STBAddAVFile(Struid,StrIP);
		StrBuf.Format("目前狀態 :對IP=%s的STB進行刪檔...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		MainAfS.STBDelAVFile(Struid,StrIP);
		fprintf(pfRunState,"%s\t%s\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
		StrBuf.Format("目前狀態 :完成所有刪補檔工作",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
	else
	{
		fprintf(pfRunState,"%s\t%s\tNo Connect\n",Struid.GetBuffer(0),StrIP.GetBuffer(0));
		StrBuf.Format("目前狀態 :連線IP=%s的STB失敗",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
	fclose(pfRunState);
}
void CChangeSTBforJennyDlg::STBAddAVFile(CString Struid,CString StrIP)
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
			SetDlgItemText(IDC_ShowState,"目前狀態： 複製檔案中 ...");
			if(CopyFile(StrNewFilePath.GetBuffer(0),StrNetPathName.GetBuffer(0),false))
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
			FILE *pfInfo;
			pfInfo=fopen(StrNetPathName.GetBuffer(0),"w");
			if(pfInfo!=NULL)
			{
				fprintf(pfLogFile,"%s\t%s\n",StrInfoFileName.GetBuffer(0),"OK");
				fprintf(pfLogFile,"\n");
				fclose(pfInfo);
			}
			else
			{
				fprintf(pfLogFile,"%s\t%s\n",StrInfoFileName.GetBuffer(0),"Not OK");
				fprintf(pfLogFile,"\n");
			}
			pfInfo=NULL;
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
void CChangeSTBforJennyDlg::STBDelAVFile(CString Struid,CString StrIP)
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
			SetDlgItemText(IDC_ShowState,"目前狀態： 刪除檔案中 ...");
			if(DeleteFile(StrOldFilePath.GetBuffer(0)))
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
void CChangeSTBforJennyDlg::ReadAVListXML(CString Struid)
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
bool CChangeSTBforJennyDlg::ConnectSTB(CString StrIP)
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
void CChangeSTBforJennyDlg::ReadSTBAVList(CString StrIP)
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
CString CChangeSTBforJennyDlg::GetFilePath2FileName(CString Strdata)
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
CString CChangeSTBforJennyDlg::CreatInfoFileHead(CString StrStart,CString StrEnd)
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
UINT CChangeSTBforJennyDlg::ThreadDownLoadMovieList(LPVOID lpram)
{
	CChangeSTBforJennyDlg *u=(CChangeSTBforJennyDlg *)lpram;
	u->DownLoadMovieList();
	u->ShowWindow(SW_SHOW);
	return 0;
}
void CChangeSTBforJennyDlg::DownLoadMovieList()
{
	::CoInitialize(NULL); //step 2:讀取XML
	GetSTBInformation();
	int i,j;
	j=m_ArraySTBuid.GetSize();
	for(i=0;i<j;i++)
	{	
		GetSTBMovieInformation(m_ArraySTBuid.GetAt(i));
	}
}

void CChangeSTBforJennyDlg::OnButtLayout() 
{
	// TODO: Add your control notification handler code here
	CString StrIP;
	CString StrSourceFileName;
	CString StrNewFileName;
	CString StrBuf;
	CString StrNetPath;
	/*
	UpdateData(true);
		m_blnLayout=true;
	UpdateData(false);
	m_ButtLayout.EnableWindow(false);
	*/
	m_IP.GetWindowText(m_StrNowIP);
	StrIP=m_StrNowIP;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\Message\\";
	StrBuf.Format("目前狀態 :連線IP=%s的STB...",StrIP.GetBuffer(0));
	SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	if(ConnectSTB(StrIP))
	{
		StrBuf.Format("目前狀態 :傳送版型中 ...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		this->GetDlgItemText(IDC_EDITLayout,StrSourceFileName);
		StrNewFileName=GetFilePath2FileName(StrSourceFileName);
		StrNewFileName=StrNetPath+StrNewFileName;
		if(CopyFile(StrSourceFileName.GetBuffer(0),StrNewFileName.GetBuffer(0),false))
		{
			StrBuf.Format("目前狀態 :傳送版型完成 ...",StrIP.GetBuffer(0));
			SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		}
	}
	else
	{
		StrBuf.Format("目前狀態 :連線IP=%s的STB失敗",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
	MessageBox("OK");
}

void CChangeSTBforJennyDlg::OnButtVolume() 
{
	// TODO: Add your control notification handler code here
	CString StrIP;
	CString StrSourceFileName;
	CString StrNewFileName;
	CString StrBuf;
	CString StrNetPath;
	/*
	UpdateData(true);
		m_blnVolume=true;
	UpdateData(false);
	m_ButtVolume.EnableWindow(false);
	*/
	m_IP.GetWindowText(m_StrNowIP);
	StrIP=m_StrNowIP;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\Message\\";
	StrBuf.Format("目前狀態 :連線IP=%s的STB...",StrIP.GetBuffer(0));
	SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	if(ConnectSTB(StrIP))
	{
		StrBuf.Format("目前狀態 :傳送音量設定中 ...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		this->GetDlgItemText(IDC_COMBOVolume,StrSourceFileName);
		StrNewFileName=GetFilePath2FileName(StrSourceFileName);
		StrNewFileName=StrNetPath+StrNewFileName;
		if(CopyFile(StrSourceFileName.GetBuffer(0),StrNewFileName.GetBuffer(0),false))
		{
			StrBuf.Format("目前狀態 :傳送版型完成 ...",StrIP.GetBuffer(0));
			SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		}
	}
	else
	{
		StrBuf.Format("目前狀態 :連線IP=%s的STB失敗",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
	MessageBox("OK");	
}

void CChangeSTBforJennyDlg::OnButtBootTime() 
{
	// TODO: Add your control notification handler code here
	CString StrIP;
	CString StrSourceFileName;
	CString StrNewFileName;
	CString StrBuf;
	CString StrNetPath;
	m_IP.GetWindowText(m_StrNowIP);
	StrIP=m_StrNowIP;
	UpdateData(true);
		m_blnTime=true;
	UpdateData(false);
	m_ButtBootTime.EnableWindow(false);
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\Message\\";
	StrBuf.Format("目前狀態 :連線IP=%s的STB...",StrIP.GetBuffer(0));
	SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	if(ConnectSTB(StrIP))
	{
		StrBuf.Format("目前狀態 :傳送開關機設定中 ...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		this->GetDlgItemText(IDC_EDITTime,StrSourceFileName);
		StrNewFileName=GetFilePath2FileName(StrSourceFileName);
		StrNewFileName=StrNetPath+StrNewFileName;
		if(CopyFile(StrSourceFileName.GetBuffer(0),StrNewFileName.GetBuffer(0),false))
		{
			StrBuf.Format("目前狀態 :傳送開關機設定完成 ...",StrIP.GetBuffer(0));
			SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		}
	}
	else
	{
		StrBuf.Format("目前狀態 :連線IP=%s的STB失敗",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
	MessageBox("OK");		
}

void CChangeSTBforJennyDlg::OnFieldchangedIpaddress(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	CString StrTimeBuf;
	CString StrIP;
	m_IP.GetWindowText(m_StrNowIP);
	StrIP=m_StrNowIP;
	StrTimeBuf=m_StrNetDir+"\\Vga_Template\\";
	StrTimeBuf+=StrIP;
	StrTimeBuf+="Cmd.msg";
	UpdateData(true);
		m_StrTime=StrTimeBuf;
	UpdateData(false);
	*pResult = 0;
}

void CChangeSTBforJennyDlg::OnButtUpdateData() 
{
	// TODO: Add your control notification handler code here
	CString StrIPBuf;
	UpdateData(true);
		m_blnUpdateData=true;
		m_ShowState="目前狀態 :準備執行更新Data ...";
	UpdateData(false);
	///////////////////////////////////////////////////////
	m_IP.GetWindowText(StrIPBuf);
	m_StrNowIP=StrIPBuf;
	///////////////////////////////////////////////////////
	m_ButtUpdateData.EnableWindow(false);
	AfxBeginThread(ThreadUpdateData,this,0,0,0,NULL);	
}
UINT CChangeSTBforJennyDlg::ThreadUpdateData(LPVOID lpram)
{
	CChangeSTBforJennyDlg *u=(CChangeSTBforJennyDlg *)lpram;
	u->UpdateDataFun();
	u->ShowWindow(SW_SHOW);
	u->MessageBox("OK");
	return 0;
}
void CChangeSTBforJennyDlg::UpdateDataFun()
{
	CString StrSourcePath;
	CString StrSTBPath;
	CString StrSTBPath1;
	CString StrSTBPath2;
	CString StrSTBPath3;
	CString StrSTBPath4;
	CString StrIP;
	CString StrBuf;
	CString StrFileName;
	StrIP=m_StrNowIP;
	StrBuf.Format("目前狀態 :連線IP=%s的STB...",StrIP.GetBuffer(0));
	SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	if(ConnectSTB(StrIP))
	{
		StrSTBPath="\\\\";
		StrSTBPath+=StrIP;
		StrSTBPath+="\\D$\\NabroClient\\Data\\";
		StrSourcePath=m_StrNetDir;
		StrSourcePath+="\\Data\\";
		StrBuf="目前狀態 :正在刪除Data內的資訊 ...";
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		FCDUpdateData.DeleteAllFile(StrSourcePath,StrSTBPath);
		StrSTBPath1=StrSTBPath+"Schedule\\";
		FCDUpdateData1.DeleteAllFile(StrSourcePath,StrSTBPath1,1);
		FCDUpdateData1.RecursiveDelete(StrSTBPath1);
		StrSTBPath2=StrSTBPath+"Standby\\";
		FCDUpdateData2.DeleteAllFile(StrSourcePath,StrSTBPath2,1);
		FCDUpdateData2.RecursiveDelete(StrSTBPath2);
		StrSTBPath3=StrSTBPath+"Tuka\\";
		FCDUpdateData3.DeleteAllFile(StrSourcePath,StrSTBPath3,1);
		FCDUpdateData3.RecursiveDelete(StrSTBPath3);
		StrSTBPath4=StrSTBPath+"RunText\\";
		FCDUpdateData4.DeleteAllFile(StrSourcePath,StrSTBPath3,1);
		FCDUpdateData4.RecursiveDelete(StrSTBPath4);
		StrBuf="目前狀態 :正在複製資訊到Data內 ...";
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		FCDUpdateData.CopyAllFile(StrSourcePath,StrSTBPath);
		StrBuf="目前狀態 :正在輸出Update Data結果 ...";
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		StrFileName=gstrCurDrt;
		StrFileName+="\\STBCheckLogs\\";
		StrFileName+=StrIP;
		StrFileName+="UpdateDatalog.txt";
		FCDUpdateData.Output2File(StrFileName);
		StrBuf="目前狀態 :完成Update Data...";
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
	else
	{
		StrBuf.Format("目前狀態 :連線IP=%s的STB失敗",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
}

void CChangeSTBforJennyDlg::OnButtALLAuto() 
{
	// TODO: Add your control notification handler code here
	CString StrIPBuf;
	UpdateData(true);
		m_ShowState="目前狀態 :執行自動模式中 ...";
	UpdateData(false);
	m_ButtALLAuto.EnableWindow(false);
	AfxBeginThread(ThreadALLAuto,this,0,0,0,NULL);	
}
UINT CChangeSTBforJennyDlg::ThreadALLAuto(LPVOID lpram)
{
	CChangeSTBforJennyDlg *u=(CChangeSTBforJennyDlg *)lpram;
	u->ALLAuto();
	u->ShowWindow(SW_SHOW);
	u->MessageBox("OK");
	return 0;
}
void CChangeSTBforJennyDlg::ALLAuto()
{
	OnButtSetIPandUID();
	Sleep(2000);
	OnButtRegistration();
	Sleep(2000);
	OnButtUpdateData();
	Sleep(2000);
	OnButtLayout();
	Sleep(2000);
	OnButtVolume();
	Sleep(2000);
	OnButtBootTime();
	Sleep(2000);
	OnButtMovie();
}

void CChangeSTBforJennyDlg::OnButtRemoteControl() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_blnRemoteControl=true;
	UpdateData(false);
	m_ButtRemoteControl.EnableWindow(false);
	CWebInformation WebInfor(this);
	WebInfor.SetInformation("http://61.67.114.196/NmConsole/CoreNm/User/DlgUserLogin/DlgUserLogin.asp","User: 「chtvh」","Pass:「1369」");
	WebInfor.DoModal();
}

void CChangeSTBforJennyDlg::OnButtDeleteMovie() 
{
	// TODO: Add your control notification handler code here
	CString StrBuf;
	StrBuf="下檔操作說明書 :  ";
	StrBuf+=m_StrNetDir;
	StrBuf+="\\Download\\01_del.doc";
	UpdateData(true);
		m_blnDeleteMovie=true;
	UpdateData(false);
	m_ButtDeleteMovie.EnableWindow(false);
	CWebInformation WebInfor(this);
	WebInfor.SetInformation("http://eip.chtv.com.tw/MediaForceOut.aspx","備註：「到NabroServer 172.17.254.200 ，做檔案刪除動作。」\n User：「Administrator」 Pass：「chtv_nabro」",StrBuf);
	WebInfor.DoModal();	
}

void CChangeSTBforJennyDlg::OnButtTUKA() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_blnTUKA=true;
	UpdateData(false);
	m_ButtTUKA.EnableWindow(false);
	CWebInformation WebInfor(this);
	WebInfor.SetInformation("http://stbadmin.chtv.com.tw/admin_login.php","User: 「chtv」","Pass: 「27882575」");
	WebInfor.DoModal();		
}

void CChangeSTBforJennyDlg::OnButtEIPFlow() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_blnEIPFlow=true;
	UpdateData(false);
	m_ButtEIPFlow.EnableWindow(false);
	CWebInformation WebInfor(this);
	WebInfor.SetInformation("http://eipflow.chtv.com.tw/eipflow_login.php","","");
	WebInfor.DoModal();		
}

void CChangeSTBforJennyDlg::OnButtCompletionSerch() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_blnCompletionSerch=true;
	UpdateData(false);
	m_ButtCompletionSerch.EnableWindow(false);
	CWebInformation WebInfor(this);
	WebInfor.SetInformation("http://eservice.tw-airnet.net/index.php","User：「chtv」","Pass：「27882575」");
	WebInfor.DoModal();			
}

void CChangeSTBforJennyDlg::OnButtSTBCommand() 
{
	// TODO: Add your control notification handler code here
	CString StrIP;
	CString StrSourceFileName;
	CString StrNewFileName;
	CString StrBuf;
	CString StrNetPath;
	/*
	UpdateData(true);
		m_blnSTBCommand=true;
	UpdateData(false);
	m_ButtSTBCommand.EnableWindow(false);
	*/
	m_IP.GetWindowText(m_StrNowIP);
	StrIP=m_StrNowIP;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\Message\\";
	StrBuf.Format("目前狀態 :連線IP=%s的STB...",StrIP.GetBuffer(0));
	SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	if(ConnectSTB(StrIP))
	{
		StrBuf.Format("目前狀態 :傳送命命設定中 ...",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		this->GetDlgItemText(IDC_COMBOSTBCommand,StrSourceFileName);
		StrNewFileName=GetFilePath2FileName(StrSourceFileName);
		StrNewFileName=StrNetPath+StrNewFileName;
		if(CopyFile(StrSourceFileName.GetBuffer(0),StrNewFileName.GetBuffer(0),false))
		{
			StrBuf.Format("目前狀態 :傳送命命完成 ...",StrIP.GetBuffer(0));
			SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
		}
	}
	else
	{
		StrBuf.Format("目前狀態 :連線IP=%s的STB失敗",StrIP.GetBuffer(0));
		SetDlgItemText(IDC_ShowState,StrBuf.GetBuffer(0));
	}
	MessageBox("OK");	
}
