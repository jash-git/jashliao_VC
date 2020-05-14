// playlistView.cpp : implementation of the CPlaylistView class
//

#include "stdafx.h"
#include "playlist.h"
#include "MainFrm.h"
#include "playlistDoc.h"
#include "playlistView.h"
#include <atlbase.h>
#include <comdef.h>
#include "C:\WMSDK\WMEncSDK9\include\wmencode.h"
#include "getwme.h"
///////////////////////////////////////////////////
#import "msxml3.dll"//step 1:讀取XML
using namespace MSXML2;
TCHAR gstrCurDrt01[500];//存放目其目錄字串
CString StrListUrl;
CString StrServiceUrl;
CString StrServiceID;
CString StrHostDir;
CString StrHomePath;
int ginthttpport;
bool blnMultiDir;
//**********************
CString StrKeepLive;
CString StrService01;
CString StrService00;
int intServiceCount=0;
///////////////////////////////////////////////////

int begin=0;

HRESULT hr;
IWMEncoder* pEncoder;
extern bool gblnreload;
int inttimercount=0;
///////////////////////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlaylistView

IMPLEMENT_DYNCREATE(CPlaylistView, CFormView)

BEGIN_MESSAGE_MAP(CPlaylistView, CFormView)
	//{{AFX_MSG_MAP(CPlaylistView)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlaylistView construction/destruction

CPlaylistView::CPlaylistView()
	: CFormView(CPlaylistView::IDD)
{
	//{{AFX_DATA_INIT(CPlaylistView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

CPlaylistView::~CPlaylistView()
{
}

void CPlaylistView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPlaylistView)
	DDX_Control(pDX, IDC_EDIT1, m_status);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_OCX1, m_player);
	DDX_Control(pDX, IDC_EXPLORER1, m_Web);
	//}}AFX_DATA_MAP
}

BOOL CPlaylistView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CPlaylistView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
}

/////////////////////////////////////////////////////////////////////////////
// CPlaylistView diagnostics

#ifdef _DEBUG
void CPlaylistView::AssertValid() const
{
	CFormView::AssertValid();
}

void CPlaylistView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPlaylistDoc* CPlaylistView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaylistDoc)));
	return (CPlaylistDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlaylistView message handlers

void CPlaylistView::OnFinalRelease() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CFormView::OnFinalRelease();
}

void CPlaylistView::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
   if (begin==0)
   {
		m_list.AddString("wait  5 seconds ...... ");
		SetTimer(1,1000*60,NULL); 
		SetTimer(2,1000*5,NULL); 
   }
}


void CPlaylistView::InitEncoder(void) 
{

pEncoder=NULL;  
 	 
hr = CoCreateInstance(CLSID_WMEncoder,
                     NULL,
                     CLSCTX_INPROC_SERVER,
                     IID_IWMEncoder,
                     (void**) &pEncoder);



 if ( SUCCEEDED( hr ) )
   m_list.AddString("create socket ok .....");
 else
 {
	 m_list.AddString("error create socket .....");
	 return;
 }

   CString StrPathBuf;
   StrPathBuf=StrHomePath+"live.wme";
   CComBSTR bstrFileName(_T(StrPathBuf.GetBuffer(0)));
   //CComBSTR bstrFileName(_T("c:\\media\\live.wme"));
   hr = pEncoder->Load(bstrFileName);
   if (SUCCEEDED( hr ))
	   m_list.AddString("load wme  ok .....");
   else {
	 m_list.AddString("error load wme .....");
	 return;
   }

}

void CPlaylistView::OnButton1() 
{
	// TODO: Add your control notification handler code here
		CString StrPlayURL;
		StrPlayURL.Format("http://localhost:%d",ginthttpport);
		m_player.SetUrl(StrPlayURL.GetBuffer(0));
		//m_player.SetUrl("http://localhost:8080");
}
bool CPlaylistView::GetPlayerState()
{
	long lngPlayState;
	CString StrStateText;
	lngPlayState=m_player.GetPlayState();//1->STOP 2->PAUSE 3->RUN
	switch (lngPlayState)
	{
		case 0:
			StrStateText= "The playback state is undefined.";
			return false;
			break;//不明確的             
		case 1:
			StrStateText= "Playback is stopped.";
			return false;
			break;//被停止          
		case 2:
			StrStateText= "Playback is paused.";
			return false;
			break;//被暫停           
		case 3:
			StrStateText= "The player is playing a stream.";
			return true;
			break;//在執行            
		case 4:
			StrStateText= "The player is scanning a stream forward.";
			return false;
			break;//還在正向尋找     
		case 5:
			StrStateText= "The player is scanning a stream in reverse.";
			return false;
			break;//還在反向尋找 
		case 6:
			StrStateText= "The player is buffering media.";
			return true;
			break;//讀取Buf     
		case 7:
			StrStateText= "The player is waiting for streaming data.";
			return true;
			break;//等待    
		case 8:
			StrStateText= "The player has reached the end of the media.";
			return false;
			break;//以播放完   
		case 9:
			StrStateText= "The player is preparing new media.";
			return false;
			break;//正在準備新的檔案           
		case 10:
			StrStateText= "The player is ready to begin playback.";
			return false;
			break;//已經移到檔頭    
		default:
			StrStateText= "No value";
			return false;
			break;//無定義
	}
	return false;
}
void CPlaylistView::WriteLogFile(int intindex,CString StrMessage)
{
	FILE *pf=NULL;
	CTime TimeNow;
	CString StrWriteMessage;
	TimeNow=CTime::GetCurrentTime();
	StrWriteMessage=TimeNow.Format("%Y-%m-%d %H:%M:%S ::");
	StrWriteMessage+=StrMessage;
	if(intindex==0)
	{
		//Errlog
		pf=fopen("Errlog.txt","a");
	}
	else
	{
		//Meslog
		pf=fopen("Meslog.txt","a");
	}
	if(pf!=NULL);
	{
		fprintf(pf,"%s\n",StrWriteMessage.GetBuffer(0));
		fclose(pf);
	}
}
void CPlaylistView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString StrMessage;
	CString StrURL;
    CTime tm;
	CString str;
	tm=CTime::GetCurrentTime();
	str=tm.Format("%H : %M");
	m_status.SetWindowText(str);


	if (nIDEvent==1)
	{
      if (tm.GetHour()==6 && tm.GetMinute()==15)
	  {
			m_list.AddString("Stop reload wme ......");
			pEncoder->Stop();
			pEncoder->Release();
	  }
	  if (tm.GetHour()==6 && tm.GetMinute()==17)
	  {
		m_list.ResetContent();
		if(!ReadXMLConfig())
		{
			m_list.AddString("Read Config ERROR !!!!!!!");
			StrMessage="讀取設定檔失敗";
			WriteLogFile(0,StrMessage);
			EmailError(StrMessage);
		}
		else
		{
			m_list.AddString("Read Config ok....");
			StrMessage="讀取設定檔成功";
			WriteLogFile(1,StrMessage);
		}		
        getwme dlg;
	    m_list.AddString("Begin init ......");
        dlg.DoModal();
        	
        InitEncoder();
	    m_list.AddString("start.....");
        pEncoder->Start();
	    m_list.AddString("start  ok .....");
		CString StrPlayURL;
		StrPlayURL.Format("http://localhost:%d",ginthttpport);
		m_player.SetUrl(StrPlayURL.GetBuffer(0));
		//m_player.SetUrl("http://localhost:8080");
	  }
	  if(gblnreload)
	  {
		m_list.ResetContent();
		inttimercount++;
		CFileStatus rStatus;
		bool blnrelodcmd=false;
		CString StrCmdFile = gstrCurDrt01;
		StrCmdFile +="reload.cmd";
		if(CFile::GetStatus(StrCmdFile, rStatus))
		{
			blnrelodcmd=true;
		}
		if( (inttimercount>120) || blnrelodcmd )//從原本30分重新讀取片單改成2小時 或偵測到reload.cmd  by jash 20120730 //if(inttimercount>30)
		{
			if(blnrelodcmd)
			{
				DeleteFile( StrCmdFile.GetBuffer(0) );
			}
			inttimercount=0;
			//*****************
			pEncoder->Stop();
			pEncoder->Release();
			//*****************
			getwme dlg;
			dlg.DoModal();
			InitEncoder();
			pEncoder->Start();
		}
	  }
	  intServiceCount++;
	  if(!GetPlayerState())
	  {
		CString StrMessage;
		StrMessage="無法連結/播放Encoding";
		WriteLogFile(0,StrMessage);
		EmailError(StrMessage);
		m_list.AddString("無法連結/播放Encoding");
		CString StrPlayURL;
		StrPlayURL.Format("http://localhost:%d",ginthttpport);
		m_player.SetUrl(StrPlayURL.GetBuffer(0));
		//m_player.SetUrl("http://localhost:8080");
		StrURL=StrService01;
		intServiceCount=0;
	  }
	  else
	  {
		if(intServiceCount==0)
		{
			StrURL=StrKeepLive;
		}
		else
		{
			intServiceCount=0;
			StrURL=StrService00;
		}
	  }
	  COleVariant vaUrl=StrURL;
	  COleVariant vtMissing;
	  m_Web.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
	}




if (nIDEvent ==2)
{	
	if (begin==0)
	{
		if(!ReadXMLConfig())
		{
			m_list.AddString("Read Config ERROR !!!!!!!");
			StrMessage="讀取設定檔失敗";
			WriteLogFile(0,StrMessage);
			EmailError(StrMessage);
		}
		else
		{
			m_list.AddString("Read Config ok ....");
			StrMessage="讀取設定檔成功";
			WriteLogFile(1,StrMessage);
		}
		getwme dlg;
		m_list.AddString("Begin init ......");
		 dlg.DoModal();
		m_list.AddString("system wme ......");
		//system("c:\\media\\makewme.exe");
		InitEncoder();
		m_list.AddString("start.....");
		pEncoder->Start();
		m_list.AddString("start  ok .....");
		CString StrPlayURL;
		StrPlayURL.Format("http://localhost:%d",ginthttpport);
		m_player.SetUrl(StrPlayURL.GetBuffer(0));
		//m_player.SetUrl("http://localhost:8080");	

		
		begin=1;
		this->KillTimer(2);
	}

}
	CFormView::OnTimer(nIDEvent);
}
bool CPlaylistView::ReadXMLConfig()
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	_variant_t vtStr;
	bool blnRead=false;
	blnMultiDir=false;
	::CoInitialize(NULL); //step 2:讀取XML
	CString StrMessage;
	CString StrBuff;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   StrMessage="建立讀取清單物件失敗";
	   WriteLogFile(0,StrMessage);
	   EmailError(StrMessage);
	   return false;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt01);//取得目前程式路徑
	if( gstrCurDrt01[nLen]!='\\' )
	{
		gstrCurDrt01[nLen++] = '\\';
		gstrCurDrt01[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt01;
	strFileName1 +="Config.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
		MSXML2::IXMLDOMNodePtr pNodeRoot;
		pNodeRoot=pDoc->selectSingleNode("//ListURL");
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrListUrl=StrBuff;
		//**********************************************
		pNodeRoot=pDoc->selectSingleNode("//ServicURL");
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrServiceUrl=StrBuff;
		//**********************************************
		pNodeRoot=pDoc->selectSingleNode("//ServicID");
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrServiceID=StrBuff;
		//**********************************************
		pNodeRoot=pDoc->selectSingleNode("//HostDir");
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrHostDir=StrBuff;
		//**********************************************
		pNodeRoot=pDoc->selectSingleNode("//MultiDir");
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrBuff.MakeLower();
		if(StrBuff=="false")
		{
			blnMultiDir=false;
		}
		else
		{
			blnMultiDir=true;
		}
		//**********************************************
		StrKeepLive=StrServiceUrl+"OP=KeepaLive&ServiceID="+StrServiceID;
		StrService01=StrServiceUrl+"OP=SetServiceStatusByID&ServiceID="+StrServiceID+"&Status=1&Value=0";
		StrService00=StrServiceUrl+"OP=SetServiceStatusByID&ServiceID="+StrServiceID+"&Status=0&Value=0";
		//**********************************************
		pNodeRoot=pDoc->selectSingleNode("//HomePath");
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrBuff.MakeLower();
		StrHomePath=StrBuff;
		//**********************************************
		pNodeRoot=pDoc->selectSingleNode("//HttpPort");
		pNodeRoot->get_nodeTypedValue(&vtStr);
		StrBuff=vtStr.bstrVal;
		StrBuff.MakeLower();
		ginthttpport=atoi(StrBuff.GetBuffer(0));
		return true;
	}
	else
	{
		return false;
	}
}
void CPlaylistView::EmailError(CString StrWriteMessage)
{
	FILE *pfError;
	pfError=NULL;
	pfError=fopen("ErrorInfo.txt","w");
	if(pfError!=NULL)
	{
		fprintf(pfError,"%s\t%s",StrListUrl.GetBuffer(0),StrWriteMessage.GetBuffer(0));
		fclose(pfError);
	}
	ShellExecute(NULL,"open","MyEmailClient.exe",NULL,NULL,SW_SHOWNORMAL); 
}