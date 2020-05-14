
// DaAiNewsDownloadDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "DaAiNewsDownload.h"
#include "DaAiNewsDownloadDlg.h"
#include <stdio.h>				//C file lib
#include <fstream>				//C++ file lib
using namespace std;
using namespace net_tw_airnetnoc;//Step 1_WebService
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#define BUFFER_SIZE 2048//Step 3:Http
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


// CDaAiNewsDownloadDlg 對話方塊




CDaAiNewsDownloadDlg::CDaAiNewsDownloadDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDaAiNewsDownloadDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDaAiNewsDownloadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDaAiNewsDownloadDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDaAiNewsDownloadDlg 訊息處理常式

BOOL CDaAiNewsDownloadDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 將 [關於...] 功能表加入系統功能表。

	// IDM_ABOUTBOX 必須在系統命令範圍之中。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	SetTimer(1,1000,NULL);
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CDaAiNewsDownloadDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDaAiNewsDownloadDlg::OnPaint()
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
HCURSOR CDaAiNewsDownloadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CDaAiNewsDownloadDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	KillTimer(1);
	CString StrUrl;
	bool blnGetFileList=false;
	StrUrl="http://xpe5tv.tw-airnet.net/cgi-php/media_transform2.php?op=getVodInputXml&nst_id=2";
	blnGetFileList=GetWebFile(StrUrl,"FileList.xml");
	if(blnGetFileList)
	{
		ReadFileDownLoadXML();
		DownLoadWMVFile();
	}
	this->OnOK();
	CDialog::OnTimer(nIDEvent);
}
void CDaAiNewsDownloadDlg::ReadFileDownLoadXML()
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	bool blnRead=false;
	int i,j;
	int k,l;
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
	strFileName1 +="FileList.xml";
	m_Array1.RemoveAll();
	m_Array2.RemoveAll();
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)//第11.0版的功能
	{
		MSXML2::IXMLDOMNodeListPtr ListData;
		MSXML2::IXMLDOMNodeListPtr ListchildsData;
		MSXML2::IXMLDOMNodePtr pNodeData;
		MSXML2::IXMLDOMNodePtr pNodechildData;
		_variant_t vtStr;
		CString StrValue;
		ListData=pDoc->selectNodes("//Items");
		j=ListData->length;
		for(i=0;i<j;i++)
		{
			pNodeData=ListData->item[i];
			pNodeData->get_childNodes(&ListchildsData);
			l=ListchildsData->length;
			for(k=0;k<l;k++)
			{
				pNodechildData=ListchildsData->item[k];
				pNodechildData->get_nodeTypedValue(&vtStr);
				StrValue=vtStr.bstrVal;
				if(k==0)
				{
					m_Array0.Add(StrValue);//ID
				}
				if(k==1)
				{
					m_Array1.Add(StrValue);//WMV
				}
				if(k==2)
				{
					m_Array2.Add(StrValue);//PATH
				}				
			}
		}
		m_intHttpNumber=m_Array1.GetSize();
	}
}
void CDaAiNewsDownloadDlg::DownLoadWMVFile()
{
	//noc_ID=323
	int i;
	CString StrValue0;
	CString StrValue1;
	CString StrValue2;
	CString StrWMVFileName;
	////////////////////////////////////
	CString StrUpdateDaAiAVLog;
	CTime timeNow=CTime::GetCurrentTime();
	FILE *pfUpdateDaAiAVLog;
	StrUpdateDaAiAVLog=timeNow.Format("%Y%m%d");
	StrUpdateDaAiAVLog+="DaAiUpdatelog.txt";
	///////////////////////////////////
	CString StrNetPath;
	CString PostData;
	CString StrHttpPostAns;
	CString StrWebServiceError;
	bool blnGetWMV;
	bool blncopy;
	bool blncheckwmv;
	CoInitialize(NULL);
	noc_Service noc_S;
	try
	{
		noc_S.KeepaLive(323);
	}
	catch(...)
	{
		StrWebServiceError="WebService Error...";
	}
	String ^netStrBuf;
	netStrBuf= gcnew String ("");
	for(i=0;i<m_intHttpNumber;i++)
	{
		StrValue0=m_Array0.GetAt(i);
		StrValue1=m_Array1.GetAt(i);
		StrValue2=m_Array2.GetAt(i);
		StrWMVFileName=GetFileName(StrValue1);
		blnGetWMV=GetWebFile(StrValue1,StrWMVFileName);
		if(blnGetWMV)
		{
			StrNetPath="\\\\192.168.0.66\\";
			StrNetPath+=StrValue2;
			StrNetPath+=StrWMVFileName;
			blncopy=CopyFile(StrWMVFileName,StrNetPath,false);
			if(blncopy)
			{
				m_wmvVideoStream = new CWmvStream();//判斷WMV格式是否符合標準
				blncheckwmv=m_wmvVideoStream->OpenStream(StrWMVFileName);//判斷WMV格式是否符合標準
				if(blncheckwmv)//判斷WMV格式是否符合標準
				{//判斷WMV格式是否符合標準
					PostData="op=getVodInput2DB&nst_id=2&mi_id=";
					PostData+=StrValue0;
					StrHttpPostAns=NowNewsHttpPost(PostData);
					m_wmvVideoStream->CloseStream();
				}//判斷WMV格式是否符合標準
				pfUpdateDaAiAVLog=fopen(StrUpdateDaAiAVLog.GetBuffer(0),"a");
				if(blncheckwmv)//判斷WMV格式是否符合標準
				{//判斷WMV格式是否符合標準
					fprintf(pfUpdateDaAiAVLog,"%s;;;%s\n",StrWMVFileName.GetBuffer(0),StrHttpPostAns.GetBuffer(0));
				}//判斷WMV格式是否符合標準
				else//判斷WMV格式是否符合標準
				{//判斷WMV格式是否符合標準
					fprintf(pfUpdateDaAiAVLog,"%s;;;%s\n",StrWMVFileName.GetBuffer(0),"程式判斷檔案格式不對，所以沒有回報HTTP");//判斷WMV格式是否符合標準
				}//判斷WMV格式是否符合標準
				fclose(pfUpdateDaAiAVLog);
				pfUpdateDaAiAVLog=NULL;
				delete m_wmvVideoStream;//判斷WMV格式是否符合標準
				DeleteFile(StrWMVFileName);
				netStrBuf="";
				try
				{
					noc_S.SetServiceStatusByID(323,0,i,netStrBuf);
				}
				catch(...)
				{
					StrWebServiceError="WebService Error...";
				}
			}
			else
			{
				try
				{
					netStrBuf="檔案無法複製到網路磁碟機";
					noc_S.SetServiceStatusByID(323,1,0,netStrBuf);
				}
				catch(...)
				{
					StrWebServiceError="WebService Error...";
				}
			}
		}
	}
	CoUninitialize();
}
CString CDaAiNewsDownloadDlg::NowNewsHttpPost(CString StrPostData)
{
	CString strHeaders =_T("Content-Type: application/x-www-form-urlencoded");
	// URL-encoded form variables -
	// name = "John Doe", userid = "hithere", other = "P&Q"
	CString strFormData; //= _T("op=source_nownews&row=1030050 || 政治 || 2010/05/26 09:42 || 12814169 || [Mail系統 警告: 帶有數字IP的網址通常都是有問題的]: http://219.85.68.173/1030/v1030050.wmv || 現場消息？國軍天馬操演　射擊46枚拖式飛彈 ||");
	CString strServerName;
	strFormData=StrPostData;
	char buf[2];
	CString resultString =_T("");
	strServerName=_T("xpe5tv.tw-airnet.net");
	CInternetSession session;
	CHttpConnection* pConnection = session.GetHttpConnection(strServerName);
	try
	{
		if(pConnection!= NULL)
		{
			CHttpFile* pFile = pConnection->OpenRequest(CHttpConnection::HTTP_VERB_POST,_T("cgi-php/media_transform2.php"));
			BOOL result = pFile->SendRequest(strHeaders,(LPVOID)(LPCTSTR)strFormData, strFormData.GetLength());
			if(result)
			{
				//BOOL result1= pFile->ReadString(resultString);
				while( pFile->Read(buf, 1) > 0 )
				{
					resultString +=buf[0];
				}
			}
			else
			{
				resultString="Server time out";
			}
		}
		else
		{
			resultString="not Connecting Server";
		}
	}
	catch(...)
	{
		resultString="Server error";
	}
	return resultString;
}
CString CDaAiNewsDownloadDlg::GetFileName(CString Strdata)
{
	int i,intnumber;
	CString Strbuf;
	intnumber=Strdata.GetLength();
	Strbuf="";
	for(i=(intnumber-1);i>=0;i--)
	{
		if(Strdata.Mid(i,1)!="/")
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
bool CDaAiNewsDownloadDlg::GetWebFile(CString theUrl, CString Filename)//Step 4:Http
{
    CInternetSession session;
	CTime t1=CTime::GetCurrentTime();
    CInternetFile* file = NULL;
	CString StrBuf;
	StrBuf.Format("%d%d%d%d%d%d",t1.GetYear(),t1.GetMonth(),t1.GetDay(),t1.GetHour(),t1.GetMinute(),t1.GetSecond());          
    try
    {
        // Try to connect with the URL
		theUrl=theUrl+"?aa=";
		theUrl=theUrl+StrBuf;
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