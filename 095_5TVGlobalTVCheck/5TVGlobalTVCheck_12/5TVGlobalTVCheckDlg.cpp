// 5TVGlobalTVCheckDlg.cpp : implementation file
//

#include "stdafx.h"
#include "5TVGlobalTVCheck.h"
#include "5TVGlobalTVCheckDlg.h"
#include "wmpcontrols.h"
#include "wmpmedia.h"
#include "wmpplaylist.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BUFFER_SIZE 2048//http_download
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
// CMy5TVGlobalTVCheckDlg dialog

CMy5TVGlobalTVCheckDlg::CMy5TVGlobalTVCheckDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMy5TVGlobalTVCheckDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMy5TVGlobalTVCheckDlg)
	m_V1 = _T("");
	m_V2 = _T("");
	m_v3 = _T("");
	m_v4 = _T("");
	m_v5 = _T("");
	m_v6 = _T("");
	m_v7 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMy5TVGlobalTVCheckDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMy5TVGlobalTVCheckDlg)
	DDX_Control(pDX, IDC_OCX1, m_WMPlayer);
	DDX_Text(pDX, IDC_EDIT1, m_V1);
	DDX_Text(pDX, IDC_EDIT2, m_V2);
	DDX_Control(pDX, IDC_EXPLORER1, m_Web01);
	DDX_Text(pDX, IDC_EDIT3, m_v3);
	DDX_Text(pDX, IDC_EDIT4, m_v4);
	DDX_Text(pDX, IDC_EDIT5, m_v5);
	DDX_Text(pDX, IDC_EDIT6, m_v6);
	DDX_Text(pDX, IDC_EDIT7, m_v7);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMy5TVGlobalTVCheckDlg, CDialog)
	//{{AFX_MSG_MAP(CMy5TVGlobalTVCheckDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMy5TVGlobalTVCheckDlg message handlers

BOOL CMy5TVGlobalTVCheckDlg::OnInitDialog()
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
	m_StrWebServiceUrl="http://noc.tw-airnet.net/monitor/wService.aspx?OP=GetGlobalChannelList";
	m_StrWebServiceXmlName="WebServiceList.xml";
	if(GetWebFile(m_StrWebServiceUrl,m_StrWebServiceXmlName)==true)
	{
		GetXmlParameter();
		initfunction();
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMy5TVGlobalTVCheckDlg::OnSysCommand(UINT nID, LPARAM lParam)
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
void CMy5TVGlobalTVCheckDlg::initfunction()
{
	bool blncheck=false;
	CString StrUrl="";
	CString StrFileName="";
	CString StrANSIFileName="";
	StrANSIFileName="ANSI.txt";
	StrFileName="UTF8.txt";
	CTime t1=CTime::GetCurrentTime();
	int hr,min;
	int Year=t1.GetYear();//年
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	hr=t1.GetHour();
	min=t1.GetMinute();
	CString PlayStatelogName;
	PlayStatelogName.Format("%d-%d-%d-%d-%d-PlayStatelog.txt",Year,Month,Day,hr,min);
	StrUrl="http://5tv.tw-airnet.net/810a/db/module/mms_view/get_all_mms.php?type=tv&online=1";
	blncheck=this->GetWebFile(StrUrl,StrFileName);
	if(blncheck)
	{
		UTF8File2ANSIFile(StrFileName,StrANSIFileName);
	}
	m_ArrayName.RemoveAll();
	m_ArrayMMS.RemoveAll();
	m_ArrayMMSPlayTime.RemoveAll();
	m_ArrayMMSState.RemoveAll();
	m_TimerCount=0;
	DissolutionDataString(StrANSIFileName);
	m_pfPlayState=fopen(PlayStatelogName,"w");
	UpdateData(true);
		m_V1.Format("第%d筆",(m_intMMSUrlCount+1));
		m_V2.Format("共%d筆",m_intMMSUrlNumber);
		m_v4.Format("估計總時間 %d s",(m_intMMSUrlNumber*20));
		m_v5.Format("目前花費時間 %d s",(m_intMMSUrlCount*20));
		m_v6.Format("估計剩餘時間 %d s",((m_intMMSUrlNumber-m_intMMSUrlCount)*20));
		m_v7="State:    testing...";
	UpdateData(false);
	this->SetWindowText(m_StrMMSName);
	m_blnState=false;
	fprintf(m_pfPlayState,"%s,",m_StrMMSName.GetBuffer(0));
	m_WMPlayer.SetUrl(m_StrMMSUrl);
	m_WMPlayer.GetControls().play();
	SetTimer(0,1000,NULL);
}
void CMy5TVGlobalTVCheckDlg::OnPaint() 
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
HCURSOR CMy5TVGlobalTVCheckDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
bool CMy5TVGlobalTVCheckDlg::DissolutionDataString(CString StrFileName)
{
	bool blncheck=false;
	CStdioFile file;
	/*
	////////////////////////////////////////
	//test
	FILE *pf01=NULL;
	FILE *pf02=NULL;
	pf01=fopen("NameANSI.txt","w");
	pf02=fopen("MMSANSI.txt","w");
	////////////////////////////////////////
	*/
	CString StrSoure="";
	CString StrName="";
	CString StrMMS="";
	CString Strdtv="";
	m_intMMSUrlNumber=0;
	m_intMMSUrlCount=0;
	m_StrMMSUrl="";
	blncheck=file.Open(StrFileName,CFile::modeRead);
	if(!blncheck)
		return blncheck;
	int intindex=0;
	while(file.ReadString(StrSoure))
	{
		if(StrSoure!="")
		{
			intindex=StrSoure.Find(",");
			StrName=StrSoure.Mid(0,intindex);
			StrMMS=StrSoure.Mid((intindex+1));
			Strdtv=StrMMS.Mid(0,29);
			if(Strdtv!="mms://dtv.iptv.tw-airnet.net/")
			{
				m_ArrayName.Add(StrName);
				m_ArrayMMS.Add(StrMMS);
			}
			/*
			///////////////////////////////////////////
			//test
			fprintf(pf01,"%s\n",StrName.GetBuffer(0));
			fprintf(pf02,"%s\n",StrMMS.GetBuffer(0));
			//////////////////////////////////////////
			*/
		}
	}
	/*
	//////////////
	//test
	fclose(pf01);
	fclose(pf02);
	//////////////
	*/
	m_intMMSUrlNumber=m_ArrayMMS.GetSize();
	m_StrMMSUrl=m_ArrayMMS.GetAt(m_intMMSUrlCount);
	m_StrMMSName=m_ArrayName.GetAt(m_intMMSUrlCount);
	return true;
}
bool CMy5TVGlobalTVCheckDlg::UTF8File2ANSIFile(CString StrUTF8,CString StrANSI)
{
   //UTF8 to Unicode
	bool check;
	CStdioFile file;
	CStdioFile fileANSI;
	CString Str01,Str02;
	FILE *pf;
	pf=fopen(StrANSI,"w");
	fclose(pf);
	check=file.Open(StrUTF8,CFile::modeRead);
	if(check==false)
		return check;
	check=fileANSI.Open(StrANSI,CFile::modeWrite);
	if(check==false)
		return check;
	char* szU8;
	while(file.ReadString(Str01))
	{
		//UTF8 to Unicode 
		szU8=Str01.GetBuffer(0);
		int wcsLen = ::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), NULL, 0); 
		wchar_t* wszString = new wchar_t[wcsLen + 1]; 
		::MultiByteToWideChar(CP_UTF8, NULL, szU8, strlen(szU8), wszString, wcsLen); 
		wszString[wcsLen] = '\0'; 
		//::MessageBoxW(GetSafeHwnd(), wszString, wszString, MB_OK); 		
		/////////////////////////////////////////////////////////////////////////////////
		// Unicode to Ansi 
		int ansiLen = ::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), NULL, 0, NULL, NULL); 
		char* szAnsi = new char[ansiLen + 1]; 
		::WideCharToMultiByte(CP_ACP, NULL, wszString, wcslen(wszString), szAnsi, ansiLen, NULL, NULL); 
		szAnsi[ansiLen] = '\0'; 
		//::MessageBoxA(GetSafeHwnd(), szAnsi, szAnsi, MB_OK);
		/////////////////////////////////////////////////////////////////////////////////
		Str02.Format("%s\n",szAnsi);
		if(Str02!="<body>\n" && Str02!="</pre></body>\n")
		{
			CString StrTag;
			StrTag=Str02.Mid(0,5);
			if(StrTag=="<pre>")
			{
				Str02=Str02.Mid(5);
			}
			if(Str02.GetLength()>6)//阻止單純換行
			{
				fileANSI.Seek(0,CFile::end);
				fileANSI.WriteString(Str02);
			}
		}
		delete [] szAnsi;
		delete [] wszString;
	}
	file.Close();
	fileANSI.Close();
	return true;
}

void CMy5TVGlobalTVCheckDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	long lngPlayState;
	CString StrStateText;
	m_TimerCount++;
	if(	m_TimerCount>=20)
	{
			m_TimerCount=0;
			m_intMMSUrlCount++;
			if(m_intMMSUrlCount < m_intMMSUrlNumber)
			{
				UpdateData(true);
					m_V1.Format("第%d筆",(m_intMMSUrlCount+1));
					m_V2.Format("共%d筆",m_intMMSUrlNumber);
					m_v4.Format("估計總時間 %d s",(m_intMMSUrlNumber*20));
					m_v5.Format("目前花費時間 %d s",(m_intMMSUrlCount*20));
					m_v6.Format("估計剩餘時間 %d s",((m_intMMSUrlNumber-m_intMMSUrlCount)*20));
					m_v7="State:    testing...";
				UpdateData(false);
				lngPlayState=m_WMPlayer.GetPlayState();//1->STOP 2->PAUSE 3->RUN
				if(m_blnState==false)
				{
					StrStateText="not play";
					m_ArrayMMSPlayTime.Add(StrStateText);
					fprintf(m_pfPlayState,"%s,",StrStateText.GetBuffer(0));
				}
				if(lngPlayState==3)
				{
					StrStateText="OK";
					m_ArrayMMSState.Add(StrStateText);
					fprintf(m_pfPlayState,"%s\n",StrStateText.GetBuffer(0));
				}
				else
				{
					StrStateText="KO";
					m_ArrayMMSState.Add(StrStateText);
					fprintf(m_pfPlayState,"%s\n",StrStateText.GetBuffer(0));
				}
				m_WMPlayer.GetControls().stop();
				m_StrMMSUrl=m_ArrayMMS.GetAt(m_intMMSUrlCount);
				m_StrMMSName=m_ArrayName.GetAt(m_intMMSUrlCount);
				this->SetWindowText(m_StrMMSName);
				m_blnState=false;
				fprintf(m_pfPlayState,"%s,",m_StrMMSName.GetBuffer(0));
				m_WMPlayer.SetUrl(m_StrMMSUrl);
				m_WMPlayer.GetControls().play();	
			}
			else
			{
				KillTimer(0);
				lngPlayState=m_WMPlayer.GetPlayState();//1->STOP 2->PAUSE 3->RUN
				if(lngPlayState==3)
				{
					StrStateText="OK";
					m_ArrayMMSState.Add(StrStateText);
					fprintf(m_pfPlayState,"%s\n",StrStateText.GetBuffer(0));
				}
				else
				{
					StrStateText="KO";
					m_ArrayMMSState.Add(StrStateText);
					fprintf(m_pfPlayState,"%s\n",StrStateText.GetBuffer(0));
				}
				fclose(m_pfPlayState);
				m_WMPlayer.GetControls().stop();
				::DeleteFile("ANSI.txt");
				::DeleteFile("UTF8.txt");
				UpdateData(true);
					m_v7="State:    Updating...";
				UpdateData(false);
				CompareAndAnalyzeChannel();
				if(GetWebFile(m_StrWebServiceUrl,m_StrWebServiceXmlName)==true)
				{
					GetXmlParameter();
					initfunction();
				}
				//MessageBox("OK");
			}
	}
	else
	{
		if(m_blnState==false)
		{
			lngPlayState=m_WMPlayer.GetPlayState();//1->STOP 2->PAUSE 3->RUN
			switch (lngPlayState)
			{
				case 0:
					StrStateText= "The playback state is undefined.";
					break;//不明確的             
				case 1:
					StrStateText= "Playback is stopped.";
					break;//被停止          
				case 2:
					StrStateText= "Playback is paused.";
					break;//被暫停           
				case 3:
					//StrStateText= "The player is playing a stream.";
					m_blnState=true;
					StrStateText.Format("%d",m_TimerCount);
					m_ArrayMMSPlayTime.Add(StrStateText);
					fprintf(m_pfPlayState,"%s,",StrStateText.GetBuffer(0));
					break;//在執行            
				case 4:
					StrStateText= "The player is scanning a stream forward.";
					break;//還在正向尋找     
				case 5:
					StrStateText= "The player is scanning a stream in reverse.";
					break;//還在反向尋找 
				case 6:
					StrStateText= "The player is buffering media.";
					break;//讀取Buf     
				case 7:
					StrStateText= "The player is waiting for streaming data.";
					break;//等待    
				case 8:
					StrStateText= "The player has reached the end of the media.";
					break;//以播放完   
				case 9:
					StrStateText= "The player is preparing new media.";
					break;//正在準備新的檔案           
				case 10:
					StrStateText= "The player is ready to begin playback.";
					break;//已經移到檔頭    
				default:
					StrStateText= "No value";
					break;//無定義
			}
		}
	}
	CDialog::OnTimer(nIDEvent);
}

///////////////Web_start
bool CMy5TVGlobalTVCheckDlg::HasItem(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch>pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	if(pDisp==NULL)
		return false;
	else 
		return true; 
}
void CMy5TVGlobalTVCheckDlg::PutIEText(IHTMLElementCollection *pobjAllElement,CString strName,CString strText)
{
	CComPtr<IDispatch> pDisp; 
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp); 
	CComQIPtr<IHTMLInputTextElement,&IID_IHTMLInputTextElement>pElement; 
	if(pDisp==NULL)
	{
		MessageBox(strName + "沒有找到!"); 
	}
	else
	{
		pElement=pDisp; 
		pElement->put_value(strText.AllocSysString()); 
	}
} 
void CMy5TVGlobalTVCheckDlg::SubmitPage(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch> pDisp; 
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp); 
	CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement; 
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!"); 
	}
	else
	{
		pElement=pDisp;
		pElement->click();
	}
} 
void CMy5TVGlobalTVCheckDlg::CheckItem(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr<IHTMLElement, &IID_IHTMLElement>pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->click();
	}
}
CString CMy5TVGlobalTVCheckDlg::GetHidText(IHTMLElementCollection *pobjAllElement,CString strName)
{
	_bstr_t   bstText;   
	BSTR   bsText;
	CString str;
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr < IHTMLInputHiddenElement,&IID_IHTMLInputHiddenElement > pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->get_value(&bsText);
		bstText=bsText;
		str=(LPCSTR)bstText;
	}
	return   str; 
}
void CMy5TVGlobalTVCheckDlg::SelectItemValue(IHTMLElementCollection *pobjAllElement,CString strName,long number)
{
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr < IHTMLSelectElement,&IID_IHTMLSelectElement > pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		pElement=pDisp;
		pElement->put_selectedIndex(number);
	}
}
void CMy5TVGlobalTVCheckDlg::PutIEFile(IHTMLElementCollection *pobjAllElement,CString strName,CString strText)
{
	CComPtr<IDispatch> pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	CComQIPtr < IHTMLInputFileElement,&IID_IHTMLInputFileElement > pElement;
	if(pDisp==NULL)
	{
		AfxMessageBox(strName + "沒有找到!");
	}
	else
	{
		char cha;
		
		pElement=pDisp;
		CComQIPtr <IHTMLElement,&IID_IHTMLElement > pelmBody(pElement);
		SetTimer(1,100,NULL);
		pelmBody->click();
		//pelmBody->put_outerText(strText.AllocSysString());  
		//pElement->put_value(strText.AllocSysString()); 

	}
}
///////////////Web_end
bool CMy5TVGlobalTVCheckDlg::GetWebFile(CString theUrl, CString Filename)//http_download
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
void CMy5TVGlobalTVCheckDlg::GetXmlParameter()//step 4:讀取XML
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMDocumentPtr pxmldom1;
	MSXML2::IXMLDOMNodePtr pNodeServiceID;
	MSXML2::IXMLDOMNodePtr pNodeChannelName;
	MSXML2::IXMLDOMNodePtr pNodeChannelUrl;
	MSXML2::IXMLDOMNodePtr pNode;
	MSXML2::IXMLDOMNodeListPtr pNodeList;
	m_ArrayServiceID.RemoveAll();
	m_ArrayChannelName.RemoveAll();
	m_ArrayChannelUrl.RemoveAll();
	_bstr_t bt1;
	_variant_t vtStr;
	CTime t1=CTime::GetCurrentTime();
	bool blnRead=false;
	FILE *pf;
	//////////////////////////
	pf=fopen("WebServiceList.txt","w");
	//////////////////////////
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
	strFileName1 +="WebServiceList.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
		//
		int i,j;
		i=0;
		j=0;
		///////////////////////////////////////////////////
		//在樹中查找名為Channel的節點,"//"表示在任意一層查找
		//////////////////////////////////////////////////////
		pNodeList=pDoc->selectNodes("//Channel");
		j=pNodeList->length;
		////////////////////////////////////////////////////////
		//依序取出子節點
		for(i=0;i<j;i++)
		{
			CString StrServiceID,StrChannelName,StrChannelUrl;
			pNode=pNodeList->item[i];
			bt1=pNode->Getxml();
			hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
			blnRead=pxmldom1->loadXML(bt1); 
			////////////////////////////////////////////////////////
			pNodeServiceID=pxmldom1->selectSingleNode("//ServiceID");
			pNodeServiceID->get_nodeTypedValue(&vtStr);
			StrServiceID=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeChannelName=pxmldom1->selectSingleNode("//ChannelName");
			pNodeChannelName->get_nodeTypedValue(&vtStr);
			StrChannelName=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeChannelUrl=pxmldom1->selectSingleNode("//ChannelUrl");
			pNodeChannelUrl->get_nodeTypedValue(&vtStr);
			StrChannelUrl=vtStr.bstrVal;
			///////////////////////////////////////////////////////
			m_ArrayServiceID.Add(StrServiceID);
			m_ArrayChannelName.Add(StrChannelName);
			m_ArrayChannelUrl.Add(StrChannelUrl);
			fprintf(pf,"%s,%s,%s\n",StrServiceID.GetBuffer(0),StrChannelName.GetBuffer(0),StrChannelUrl.GetBuffer(0));
		}
	}
	fclose(pf);
	UpdateData(true);
		m_v3.Format("WebService 共有%d頻道",m_ArrayChannelName.GetSize());
	UpdateData(false);
}
void CMy5TVGlobalTVCheckDlg::CompareAndAnalyzeChannel()
{
	int i,j;
	int k,l;
	bool blnfind;
	j=m_ArrayName.GetSize();
	l=m_ArrayChannelName.GetSize();
	CString StrTestName;
	CString StrTestMMSPlayTime;
	CString StrServiceName;
	CString StrServiceID;
	CString StrChannelUrl;
	//**************************************
	CTime t1=CTime::GetCurrentTime();
	int hr,min;
	int Year=t1.GetYear();//年
	int Month=t1.GetMonth(); //月
	int Day=t1.GetDay();//日
	hr=t1.GetHour();
	min=t1.GetMinute();
	FILE *pfFindAndOK,*pfFindAndKO,*pfNotFindAndOK,*pfNotFindAndKO;
	FILE *pfAdditionChannel,*pfDisableChannel;
	FILE *pfCallWebServiceData;
	CString FindAndOKName;
	CString FindAndKOName;
	CString NotFindAndOKName;
	CString NotFindAndKOName;
	CString AdditionChannelName;
	CString DisableChannelName;
	FindAndOKName.Format("%d-%d-%d-%d-%d-FindAndOK.txt",Year,Month,Day,hr,min);
	FindAndKOName.Format("%d-%d-%d-%d-%d-FindAndKO.txt",Year,Month,Day,hr,min);
	NotFindAndOKName.Format("%d-%d-%d-%d-%d-NotFindAndOK.txt",Year,Month,Day,hr,min);
	NotFindAndKOName.Format("%d-%d-%d-%d-%d-NotFindAndKO.txt",Year,Month,Day,hr,min);
	AdditionChannelName.Format("%d-%d-%d-%d-%d-AdditionChannel.txt",Year,Month,Day,hr,min);
	DisableChannelName.Format("%d-%d-%d-%d-%d-DisableChannel.txt",Year,Month,Day,hr,min);
	pfFindAndOK=fopen(FindAndOKName.GetBuffer(0),"w");
	pfFindAndKO=fopen(FindAndKOName.GetBuffer(0),"w");
	pfNotFindAndOK=fopen(NotFindAndOKName.GetBuffer(0),"w");
	pfNotFindAndKO=fopen(NotFindAndKOName.GetBuffer(0),"w");
	pfAdditionChannel=fopen(AdditionChannelName.GetBuffer(0),"w");
	pfDisableChannel=fopen(DisableChannelName.GetBuffer(0),"w");
	//********************************************************
	CString StrPlayState;
	CString StrTestMMS;
	for(i=0;i<j;i++)
	{
		blnfind=false;
		StrTestName=m_ArrayName.GetAt(i);
		StrTestName.TrimLeft();//刪除空白字元
		StrTestName.TrimRight();//刪除空白字元
		StrPlayState=m_ArrayMMSState.GetAt(i);
		StrTestMMS=m_ArrayMMS.GetAt(i);
		for(k=0;k<l;k++)
		{
			StrServiceName=m_ArrayChannelName.GetAt(k);
			StrServiceName.TrimLeft();//刪除空白字元
			StrServiceName.TrimRight();//刪除空白字元
			if(StrTestName==StrServiceName)
			{
				blnfind=true;
				StrServiceID=m_ArrayServiceID.GetAt(k);
				break;
			}
		}
		if(blnfind==true)//finded
		{
			//m_ArrayMMSState
			//m_ArrayName
			//m_ArrayMMS
			////////////////////////////////////////////////////////////////
			//enable channel CallWebService
			pfCallWebServiceData=fopen("C:\\CallWebServiceData.txt","w");
			fprintf(pfCallWebServiceData,"%d\n",4);
			fprintf(pfCallWebServiceData,"%s",StrServiceID.GetBuffer(0));
			fclose(pfCallWebServiceData);
			pfCallWebServiceData=NULL;
			CallWebService();
			///////////////////////////////////////////////////////////////
			if(StrPlayState=="OK")
			{
				StrTestMMSPlayTime=m_ArrayMMSPlayTime.GetAt(i);
				fprintf(pfFindAndOK,"%s,%s,%s\n",StrTestName.GetBuffer(0),StrTestMMS.GetBuffer(0),StrTestMMSPlayTime.GetBuffer(0));
				////////////////////////////////////////////////////////////////////
				//update channel CallWebService
				pfCallWebServiceData=fopen("C:\\CallWebServiceData.txt","w");
				fprintf(pfCallWebServiceData,"%d\n",1);
				fprintf(pfCallWebServiceData,"%s\n",StrServiceID.GetBuffer(0));
				fprintf(pfCallWebServiceData,"%s\n",StrTestMMSPlayTime.GetBuffer(0));
				fprintf(pfCallWebServiceData,"%d\n",0);
				fprintf(pfCallWebServiceData,"%s","OK");
				fclose(pfCallWebServiceData);
				pfCallWebServiceData=NULL;
				CallWebService();
				////////////////////////////////////////////////////////////////////
			}
			else
			{
				fprintf(pfFindAndKO,"%s,%s\n",StrTestName.GetBuffer(0),StrTestMMS.GetBuffer(0));
				////////////////////////////////////////////////////////////////////
				//update channel CallWebService
				pfCallWebServiceData=fopen("C:\\CallWebServiceData.txt","w");
				fprintf(pfCallWebServiceData,"%d\n",1);
				fprintf(pfCallWebServiceData,"%s\n",StrServiceID.GetBuffer(0));
				fprintf(pfCallWebServiceData,"%d\n",0);
				fprintf(pfCallWebServiceData,"%d\n",1);
				fprintf(pfCallWebServiceData,"%s","KO");
				fclose(pfCallWebServiceData);
				pfCallWebServiceData=NULL;
				CallWebService();
				////////////////////////////////////////////////////////////////////
			}
		}
		else//not find
		{
			//m_ArrayMMSState
			//m_ArrayName
			//m_ArrayMMS
			////////////////////////////////////////////////////////////////////
			//add channel CallWebService
			pfCallWebServiceData=fopen("C:\\CallWebServiceData.txt","w");
			fprintf(pfCallWebServiceData,"%d\n",2);
			fprintf(pfCallWebServiceData,"%s\n",StrTestName.GetBuffer(0));
			fprintf(pfCallWebServiceData,"%s",StrTestMMS.GetBuffer(0));
			fclose(pfCallWebServiceData);
			pfCallWebServiceData=NULL;
			CallWebService();
			////////////////////////////////////////////////////////////////////
			fprintf(pfAdditionChannel,"%s,%s\n",StrTestName.GetBuffer(0),StrTestMMS.GetBuffer(0));
			if(StrPlayState=="OK")
			{
				fprintf(pfNotFindAndOK,"%s,%s\n",StrTestName.GetBuffer(0),StrTestMMS.GetBuffer(0));
			}
			else
			{
				fprintf(pfNotFindAndKO,"%s,%s\n",StrTestName.GetBuffer(0),StrTestMMS.GetBuffer(0));
			}
		}
	}
	//************************************
	i=0;
	k=0;
	blnfind=false;
	for(k=0;k<l;k++)
	{
		StrServiceName=m_ArrayChannelName.GetAt(k);
		for(i=0;i<j;i++)
		{
			StrTestName=m_ArrayName.GetAt(i);
			if(StrServiceName==StrTestName)
			{
				blnfind=true;
				break;
			}
		}
		if(blnfind!=true)
		{
			StrServiceID=m_ArrayServiceID.GetAt(k);
			StrChannelUrl=m_ArrayChannelUrl.GetAt(k);
			fprintf(pfDisableChannel,"%s,%s,%s\n",StrServiceID.GetBuffer(0),StrServiceName.GetBuffer(0),StrChannelUrl.GetBuffer(0));
			////////////////////////////////////////////////////////////////////
			//disable channel CallWebService
			pfCallWebServiceData=fopen("C:\\CallWebServiceData.txt","w");
			fprintf(pfCallWebServiceData,"%d\n",3);
			fprintf(pfCallWebServiceData,"%s",StrServiceID.GetBuffer(0));
			fclose(pfCallWebServiceData);
			pfCallWebServiceData=NULL;
			CallWebService();
			////////////////////////////////////////////////////////////////////
		}
		else
		{
			blnfind=false;
		}
	}
	fclose(pfDisableChannel);
	fclose(pfAdditionChannel);
	fclose(pfFindAndOK);
	fclose(pfFindAndKO);
	fclose(pfNotFindAndOK);
	fclose(pfNotFindAndKO);
}
void CMy5TVGlobalTVCheckDlg::CallWebService()
{
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString StrCallWebServiceExeName;
	StrCallWebServiceExeName=gstrCurDrt;
	StrCallWebServiceExeName+="CallWebService.exe";
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=SW_MINIMIZE;
	si.dwFlags=STARTF_USESHOWWINDOW;
	BOOL fRet=CreateProcess(NULL,
							StrCallWebServiceExeName.GetBuffer(0),
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
}

void CMy5TVGlobalTVCheckDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	this->ShowWindow(SW_MINIMIZE);
}
