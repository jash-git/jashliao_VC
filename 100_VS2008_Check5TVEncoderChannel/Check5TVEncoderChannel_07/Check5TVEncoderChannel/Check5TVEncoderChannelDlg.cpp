// Check5TVEncoderChannelDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "Check5TVEncoderChannel.h"
#include "Check5TVEncoderChannelDlg.h"
using namespace net_tw_airnetnoc;//WebService_Step 1
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define BUFFER_SIZE 2048//http_download
TCHAR gstrCurDrt[500];//存放目其目錄字串
// 對 App About 使用 CAboutDlg 對話方塊

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 對話方塊資料
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支援

// 程式碼實作
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCheck5TVEncoderChannelDlg 對話方塊




CCheck5TVEncoderChannelDlg::CCheck5TVEncoderChannelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCheck5TVEncoderChannelDlg::IDD, pParent)
	, m_StrShowChannel(_T(""))
	, m_StrShowLoadingTime(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCheck5TVEncoderChannelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_OCX1, m_Player);
	DDX_Text(pDX, IDC_EDIT1, m_StrShowChannel);
	DDX_Text(pDX, IDC_EDIT2, m_StrShowLoadingTime);
}

BEGIN_MESSAGE_MAP(CCheck5TVEncoderChannelDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CCheck5TVEncoderChannelDlg 訊息處理常式

BOOL CCheck5TVEncoderChannelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
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

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO: 在此加入額外的初始設定
	//////////////////////////////////////////
	//jash Write
	//CString StrUrl;
	//StrUrl="mms://dtv.iptv.tw-airnet.net/S-195";
	//m_Player.put_URL(StrUrl);
	//m_control = static_cast<CWMPControls>(m_Player.get_controls());
	//m_control.play();
	init();
	///////////////////////////////////////////
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CCheck5TVEncoderChannelDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CCheck5TVEncoderChannelDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CCheck5TVEncoderChannelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CCheck5TVEncoderChannelDlg::init()
{
	GetEncoderList();
	GetXmlParameter();
	if(m_intMMSUrlNumber>0)
	{
		/////////////////////////////////////////////////////////////
		m_intTimerCount=0;
		m_intMMSUrlCount=0;
		m_intSec=0;
		m_blnState=false;
		CString StrShowText; 
		m_StrID=m_ArrayServiceID.GetAt(m_intMMSUrlCount);
		m_StrMMSUrl=m_ArrayChannelUrl.GetAt(m_intMMSUrlCount);
		m_StrMMSName=m_ArrayChannelName.GetAt(m_intMMSUrlCount);
		StrShowText="Check5TVEncoderChannel- ";
		StrShowText=StrShowText+m_StrMMSName;
		UpdateData(true);
			m_StrShowChannel="目前頻道： ";
			m_StrShowChannel=m_StrShowChannel+m_StrMMSName;
		UpdateData(false);
		//this->SetWindowText(StrShowText);
		m_Player.put_URL(m_StrMMSUrl);
		m_control = static_cast<CWMPControls>(m_Player.get_controls());
		m_control.play();
		/////////////////////////////////////////////////////////////
		SetTimer(1,1000,NULL);
	}
}
void CCheck5TVEncoderChannelDlg::GetEncoderList(void)
{
	/*
	CoInitialize(NULL);
		CString StrEnableList;
		String ^netStrEnableList;
		noc_Service noc_S;
		netStrEnableList=noc_S.GetChannelEnableList();
		StrEnableList=netStrEnableList;
	CoUninitialize();
	*/
	::DeleteFile(_T("EncoderList.xml"));
	::DeleteFile(_T("WebServiceList.txt"));
	CString StrUrl;
	CString StrXMLFileName;
	StrUrl="http://noc.tw-airnet.net/monitor/wService.aspx?OP=GetChannelEnableList";
	StrXMLFileName="EncoderList.xml";
	GetWebFile(StrUrl,StrXMLFileName);
}
bool CCheck5TVEncoderChannelDlg::GetWebFile(CString theUrl, CString Filename)//http_download
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
void CCheck5TVEncoderChannelDlg::GetXmlParameter()//step 4:讀取XML
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
	m_intMMSUrlNumber=0;
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
	strFileName1 +="EncoderList.xml";
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
			char pstr01[200];
			char *pstr02;
			char pstr03[200];
			size_t sz01=0;
			size_t sz02=0;
			size_t sz03=0;
			const size_t strsize01=(StrServiceID.GetLength()+1)*2;
			const size_t strsize02=(StrChannelName.GetLength()+1)*2;
			const size_t strsize03=(StrChannelUrl.GetLength()+1)*2;
			wcstombs_s(&sz01,pstr01,strsize01,StrServiceID,_TRUNCATE);//CString2char
			//////////////////////////////////////////////////////////////////////
			//UTF8 to ANSI
			DWORD dwNum = WideCharToMultiByte(CP_ACP, NULL, StrChannelName, -1, NULL, 0, NULL, FALSE);
			pstr02=new char [dwNum];
			WideCharToMultiByte(CP_ACP, NULL, StrChannelName, StrChannelName.GetLength(), pstr02, dwNum, NULL, FALSE);
			pstr02[dwNum-1]= '\0';
			///////////////////////////////////////////////////////////////////////
			wcstombs_s(&sz03,pstr03,strsize03,StrChannelUrl,_TRUNCATE);//CString2char
			fprintf(pf,"%s,%s,%s\n",pstr01,pstr02,pstr03);
			delete [] pstr02;
		}
	}
	m_intMMSUrlNumber=m_ArrayServiceID.GetSize();
	fclose(pf);
}
void CCheck5TVEncoderChannelDlg::WebServiceUpdate(int id,int state,int value)
{
	CString StrBuf;
	StrBuf="";
	try
	{
		CoInitialize(NULL);
			String ^netStrBuf;
			netStrBuf= gcnew String (StrBuf);
			noc_Service noc_S;
			noc_S.SetServiceStatusByID(id,state,value,netStrBuf);
		CoUninitialize();
	}
	catch(...)
	{
		FILE *pferror;
		pferror=fopen("errorlog.txt","a");
		fprintf(pferror,"%d-%d-%d\n",id,state,value);
		fclose(pferror);	
	}
}
void CCheck5TVEncoderChannelDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	CString StrShowText;
	CTime time = CTime::GetCurrentTime();
	m_intTimerCount++;
	long lngPlayState;
	CString StrStateText;
	char pstr01[200];
	char pstr03[200];
	size_t sz01=0;
	size_t sz02=0;
	size_t sz03=0;
	const size_t strsize01=(m_StrID.GetLength()+1)*2;
	const size_t strsize03=(m_StrMMSName.GetLength()+1)*2;
	FILE *pflog;//test
	if(m_intTimerCount>=20)
	{
		KillTimer(1);
		m_intTimerCount=0;
		m_control.stop();
		//m_StrID=m_ArrayServiceID.GetAt(m_intMMSUrlCount);
		//m_StrMMSUrl=m_ArrayChannelUrl.GetAt(m_intMMSUrlCount);
		//m_StrMMSName=m_ArrayChannelName.GetAt(m_intMMSUrlCount);
		wcstombs_s(&sz01,pstr01,strsize01,m_StrID,_TRUNCATE);//CString2char
		pflog=fopen("error_log.txt","a");//test
		int intServiceID=atoi(pstr01);
		if(m_blnState==true)
		{
			//fprintf(pflog,"%s,%d\n",pstr01,m_intSec);//test
			WebServiceUpdate(intServiceID,0,m_intSec);
		}
		else
		{
			CString str =time.Format("%Y-%m-%d-%H-%M-%S");
			int n = str.GetLength();
			int len = WideCharToMultiByte(CP_ACP,0,str,str.GetLength(),NULL,0,NULL,NULL);
			char * chrtime = new char[len+1];   //以位元組為單位
			WideCharToMultiByte(CP_ACP,0,str,str.GetLength(),chrtime,len,NULL,NULL);
			chrtime[len] = '\0';
			fprintf(pflog,"%d,%s\n",intServiceID,chrtime);//test
			delete [] chrtime;
			WebServiceUpdate(intServiceID,1,0);
		}
		fclose(pflog);//test
		m_intSec=0;
		m_intMMSUrlCount++;
		if(m_intMMSUrlCount < m_intMMSUrlNumber)
		{
			m_blnState=false;
			m_StrID=m_ArrayServiceID.GetAt(m_intMMSUrlCount);
			m_StrMMSUrl=m_ArrayChannelUrl.GetAt(m_intMMSUrlCount);
			m_StrMMSName=m_ArrayChannelName.GetAt(m_intMMSUrlCount);
			StrShowText="Check5TVEncoderChannel- ";
			StrShowText=StrShowText+m_StrMMSName;
			UpdateData(true);
				m_StrShowChannel="目前頻道： ";
				m_StrShowChannel=m_StrShowChannel+m_StrMMSName;
			UpdateData(false);
			//this->SetWindowText(StrShowText);
			m_Player.put_URL(m_StrMMSUrl);
			m_control = static_cast<CWMPControls>(m_Player.get_controls());
			m_control.play();
			SetTimer(1,1000,NULL);
		}
		else
		{
			init();
		}
	}
	else
	{
		if(m_blnState==false)
		{
			lngPlayState=m_Player.get_playState();//1->STOP 2->PAUSE 3->RUN
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
					StrStateText= "The player is playing a stream.";
					m_blnState=true;
					m_intSec=m_intTimerCount;
					UpdateData(true);
						m_StrShowLoadingTime.Format(_T("頻道載入時間 : %d sec"),m_intSec);
					UpdateData(false);
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

void CCheck5TVEncoderChannelDlg::OnClose()
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	this->ShowWindow(SW_MINIMIZE);
}
