// WowTVDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WowTV.h"
#include "WowTVDlg.h"
#include "StrXorEncoder.h"
//////////////////////////
//檔案搜尋是否存在
#include "io.h"
#include "fcntl.h"
//////////////////////////
//網卡
#include < windows.h >
#include < wincon.h >
#include < stdlib.h >
#include < stdio.h >
#include < time.h >
#include < nb30.h >
#include <Wininet.h>
///////////////////////
#include <iostream>//Base64
#include <string>
//////////////////////////
#include "DlgLoginFrm.h"//登錄確定
///////////////////////////////////
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
//Base64
static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";
CString base64_encode(unsigned char const* , unsigned int len);
CString base64_decode(std::string const& s);
/////////////////////////////////////////////////////////////////////////////
//HOOK
#define ON_0 WM_USER + 500
#define ON_1 WM_USER + 501
#define ON_2 WM_USER + 502
#define ON_3 WM_USER + 503 
#define ON_4 WM_USER + 504 
#define ON_5 WM_USER + 505 
#define ON_6 WM_USER + 506 
#define ON_7 WM_USER + 507 
#define ON_8 WM_USER + 508 
#define ON_9 WM_USER + 509
HINSTANCE hInstLibrary;
typedef void (*SetKeyboardHook)();
typedef void (*ReleaseKeyboardHook)();
SetKeyboardHook _SetKeyboardHook;
ReleaseKeyboardHook _ReleaseKeyboardHook;
/////////////////////////////////////////////////////////////////////////////
TCHAR gstrCurDrt[500];//存放目前目錄字串
CString gStrLocalFile;//動畫網頁網址
CPoint gCPosition;//視窗起始位置
CPoint gCPSize;//視窗大小
CString gStrMAC;//網卡號碼
CString gStrNowTime;//登錄時間
CString gStrVolumeSerialNumber;//磁碟機序號
CString gStrDisDriver;//磁碟機種類
CString gStrEncrypt1,gStrEncrypt2,gStrEncrypt3,gStrEncrypt4,gStrEncrypt5;//XOR資料
CString gStrDecrypt1,gStrDecrypt2,gStrDecrypt3,gStrDecrypt4,gStrDecrypt5;//解XOR資料
CString StrBase64Encoded1,StrBase64Encoded2,StrBase64Encoded3,StrBase64Encoded4,StrBase64Encoded5;//Base64資料
CString StrBase64Decoded1,StrBase64Decoded2,StrBase64Decoded3,StrBase64Decoded4,StrBase64Decoded5;//解Base64資料
CString gStrKey;
bool gblnLogin=false;//啟動登錄確定
/////////////////////////////////////////////////////////////////////////////
//網卡
typedef struct _ASTAT_
{
    ADAPTER_STATUS adapt;
    NAME_BUFFER    NameBuff [30];
}ASTAT, * PASTAT;
ASTAT Adapter;
typedef struct AdapterStrct
{
	int nIndex;			//厙縐晤瘍
	CString strMac;		//Mac華硊ㄗ趼睫揹倛宒ㄘ
}ADPTSTRCT;
///////////////////////////////////////////////////////
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
// CWowTVDlg dialog

CWowTVDlg::CWowTVDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWowTVDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWowTVDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWowTVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWowTVDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_Web);
	DDX_Control(pDX, IDC_EXPLORER2, m_Web2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWowTVDlg, CDialog)
	//{{AFX_MSG_MAP(CWowTVDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_MESSAGE(ON_0,On_click0)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWowTVDlg message handlers

BOOL CWowTVDlg::OnInitDialog()
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
	//SetIcon(m_hIcon, TRUE);			// Set big icon
	//SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	/////////////////////////////////////////////////////
	//HOOK
///*
	hInstLibrary = LoadLibrary("KeybHook.dll");
	if (hInstLibrary == NULL)
	{
		FreeLibrary(hInstLibrary);
	}
	_SetKeyboardHook = (SetKeyboardHook)GetProcAddress(hInstLibrary, "SetKeyboardHook");
	_ReleaseKeyboardHook = (ReleaseKeyboardHook)GetProcAddress(hInstLibrary, "ReleaseKeyboardHook");
	if ((_SetKeyboardHook == NULL) || (_ReleaseKeyboardHook == NULL))
	{
		FreeLibrary(hInstLibrary);
	}
	_SetKeyboardHook();
//*/
	///////////////////////////////////////////////////////////////////
	//設定畫面大小
	GetandSetParameter();
	//this->MoveWindow(gCPosition.x,gCPosition.y,gCPSize.x,gCPSize.y,TRUE);
	this->ShowWindow(SW_MAXIMIZE);
	////////////////////////////////////////////////////
	RECT rc;
	this->GetClientRect(&rc);
	rc.left=rc.left-2;//使WEB填滿整個畫面做的調整
	rc.right=rc.right+2;//使WEB填滿整個畫面做的調整
	rc.top=rc.top-2;//使WEB填滿整個畫面做的調整
	rc.bottom=rc.bottom+2;//使WEB填滿整個畫面做的調整 
	m_Web.MoveWindow( &rc, true );
	////////////////////////////////////////////////////
	gStrKey="";
	//GetMac();
	//GetNowTime();
	//GetSrlNum();
	DisDriver();
	//Encrypt();	
	//Base64Encoded();
	//Base64Decoded();
	//Decrypt();
	bool checkin=false;
	//////////////////////////////////////////////////////////
	if(gStrDisDriver=="硬碟")
	{
		
		checkin=CheckInternet(gStrLocalFile);
		if(checkin)
		{
			////////////////////////////////////////////////////
			//gStrLocalFile+="?xmac=";
			//gStrLocalFile+=StrBase64Encoded4;
			COleVariant vaUrl=gStrLocalFile;
			COleVariant vtMissing;
			m_Web.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing);
			SetTimer(2,1000,NULL);
			/*
			COleVariant vaUrl_1="http://61.67.117.69/~5tv_xpe/auth/form";
			COleVariant vtMissing_1;
			m_Web2.Navigate2(&vaUrl_1,&vtMissing_1,&vtMissing_1,&vtMissing_1,&vtMissing_1);
			*/
			////////////////////////////////////////////////////
		}
		else
		{
			MessageBox("目前本主機無法連上網路，請使用者先移除WowTV並檢查網路是否正常");
			this->OnCancel(); 
		}
	}
	else
	{
		MessageBox("親愛的用戶你好，您可能已變成非法使用者，請儘快與原廠連絡保障自身權益。");
		this->OnCancel(); 
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWowTVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWowTVDlg::OnPaint() 
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
HCURSOR CWowTVDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CWowTVDlg::GetandSetParameter()//step 4:讀取XML
{
	/*
	MSXML2::IXMLDOMDocumentPtr pDoc;
	_variant_t vtStr;
	bool blnRead=false;
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
	CString StrBuf;
	strFileName1 +="WowTV.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
			MSXML2::IXMLDOMNodePtr  NodeData;
			////////////////////////////////////////////////////////////
			NodeData=pDoc->selectSingleNode("//Local_File");	
			NodeData->get_nodeTypedValue(&vtStr);
			StrBuf=vtStr.bstrVal;
			gStrLocalFile=StrBuf;
			//*************************************************
			NodeData=pDoc->selectSingleNode("//position_x");	
			NodeData->get_nodeTypedValue(&vtStr);
			StrBuf=vtStr.bstrVal;
			gCPosition.x=atoi(StrBuf.GetBuffer(0));  
			//*************************************************
			NodeData=pDoc->selectSingleNode("//position_y");	
			NodeData->get_nodeTypedValue(&vtStr);
			StrBuf=vtStr.bstrVal;
			gCPosition.y=atoi(StrBuf.GetBuffer(0));
			//*************************************************
			NodeData=pDoc->selectSingleNode("//Size_w");	
			NodeData->get_nodeTypedValue(&vtStr);
			StrBuf=vtStr.bstrVal;
			gCPSize.x=atoi(StrBuf.GetBuffer(0));
			//*************************************************
			NodeData=pDoc->selectSingleNode("//Size_h");	
			NodeData->get_nodeTypedValue(&vtStr);
			StrBuf=vtStr.bstrVal;
			gCPSize.y=atoi(StrBuf.GetBuffer(0));
	}
	*/
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	FILE *pf='\0';
	CStrXorEncoder CSXE;
	int j,data;
	j=0;
	data=-1;
	pf=fopen("url.txt","r");
	while(fscanf(pf,"%d,",&data)!=EOF)
	{
		CSXE.intDecoder[j]=data;
		j++;
	}
	fclose(pf);
	CSXE.XorDecoder(j);
	gStrLocalFile=CSXE.chrDecoder;
}

void CWowTVDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	_ReleaseKeyboardHook();
	FreeLibrary(hInstLibrary);		
}
void CWowTVDlg::On_click0()
{
	SetTimer(3,1000,NULL);
	MessageBox("本軟體並無提供滑鼠右鍵功能，還請見諒。","Wow TV");
}
BOOL CWowTVDlg::CheckHW()
{
	CString strResult,strRootPathName;
	strRootPathName=gstrCurDrt;
	strRootPathName=strRootPathName.Mid(0,3);
	LPCTSTR lpRootPathName = strRootPathName;
	LPTSTR lpVolumeNameBuffer=new char[12];
	DWORD nVolumeNameSize=12;
	DWORD VolumeSerialNumber=-1;
	DWORD MaximumComponentLength;
	DWORD FileSystemFlags;
	LPTSTR lpFileSystemNameBuffer=new char[10];
	DWORD nFileSystemNameSize=10;
	GetVolumeInformation(lpRootPathName,
				lpVolumeNameBuffer, nVolumeNameSize,
				&VolumeSerialNumber, 
				&MaximumComponentLength,
				&FileSystemFlags,
				lpFileSystemNameBuffer, nFileSystemNameSize);
	strResult.Format("%x",VolumeSerialNumber);
	if(strResult=="ffffffff")
		return false;
	else
		return true;
}
BOOL CWowTVDlg::CheckInternet(LPCTSTR URL)
{
	// TODO: Add your dispatch handler code here
	DWORD dwFlags;
	dwFlags=0;
	if(InternetCheckConnection(URL,FLAG_ICC_FORCE_CONNECTION,dwFlags))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
void CWowTVDlg::Base64Decoded()
{
	std::string encoded1=StrBase64Encoded1.GetBuffer(0); 
	StrBase64Decoded1 = base64_decode(encoded1);
	
	///////////////////////////////////////
	std::string encoded2=StrBase64Encoded2.GetBuffer(0); 
	StrBase64Decoded2 = base64_decode(encoded2);
	
	//////////////////////////////////////
	std::string encoded3=StrBase64Encoded3.GetBuffer(0); 
	StrBase64Decoded3 = base64_decode(encoded3);

	/////////////////////////////////////
	std::string encoded4=StrBase64Encoded4.GetBuffer(0); 
	StrBase64Decoded4 = base64_decode(encoded4);
	/////////////////////////////////////
}
void CWowTVDlg::Base64Encoded()
{
	//std::string s1 =gStrEncrypt1.GetBuffer(0); 
	StrBase64Encoded1 =base64_encode(reinterpret_cast<const unsigned char*>(gStrEncrypt1.GetBuffer(0)), gStrEncrypt1.GetLength());
	 
	/////////////////////////////////////////
	//std::string s2 =gStrEncrypt2.GetBuffer(0); 
	StrBase64Encoded2 =base64_encode(reinterpret_cast<const unsigned char*>(gStrEncrypt2.GetBuffer(0)), gStrEncrypt2.GetLength());
	
	/////////////////////////////////////////
	//std::string s3 =gStrEncrypt3.GetBuffer(0); 
	StrBase64Encoded3 =base64_encode(reinterpret_cast<const unsigned char*>(gStrEncrypt3.GetBuffer(0)),gStrEncrypt3.GetLength());

	/////////////////////////////////////////
	//std::string s4 =gStrEncrypt4.GetBuffer(0); 
	StrBase64Encoded4 =base64_encode(reinterpret_cast<const unsigned char*>(gStrEncrypt4.GetBuffer(0)),gStrEncrypt4.GetLength());	
	////////////////////////////////////////////
	//最後不可以有
	/*
	FILE *p1;
	p1=fopen("data2.txt","a");
	fprintf(p1,"%s\n",StrBase64Encoded4.GetBuffer(0));
	fclose(p1);
	*/
}
void CWowTVDlg::Encrypt()
{
	int intlen,intlen1;
	char chrbuf,chrbuf1,chrbuf2;
	int i,intbuf;
	CString StrBuf1,StrBuf2;
	////////////////////////////////////////////////
	CString StrKey="jashliao2266";
	intlen=gStrMAC.GetLength();
	intlen1=StrKey.GetLength();
	gStrEncrypt1="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		StrBuf1=gStrMAC.Mid(i,1);
		StrBuf2=StrKey.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrEncrypt1+=chrbuf;
	}
	////////////////////////////////////////////////
	StrKey="jashliao778878";
	intlen=gStrNowTime.GetLength();
	intlen1=StrKey.GetLength();
	gStrEncrypt2="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		StrBuf1=gStrNowTime.Mid(i,1);
		StrBuf2=StrKey.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrEncrypt2+=chrbuf;
	}
	/////////////////////////////////////////////////
	StrKey="7788go78";
	intlen=gStrVolumeSerialNumber.GetLength();
	intlen1=StrKey.GetLength();
	gStrEncrypt3="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		StrBuf1=gStrVolumeSerialNumber.Mid(i,1);
		StrBuf2=StrKey.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrEncrypt3+=chrbuf;
	}
	/////////////////////////////////////////////////
	CString Str1,Str2;
	Str1=gStrMAC+","+gStrNowTime+","+gStrVolumeSerialNumber;
	//**************
	Str2="jashliao2266 ";
	Str2+="jashliao778878 ";
	Str2+="7788go78";
	//****************
	intlen=Str1.GetLength();
	intlen1=Str2.GetLength();
	gStrEncrypt4="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		StrBuf1=Str1.Mid(i,1);
		StrBuf2=Str2.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrEncrypt4+=chrbuf;
	}
	////////////////////////////////////////////
	//最後不可以有
	/*
	FILE *p1;
	p1=fopen("data1.txt","a");
	fprintf(p1,"%s\n",Str1.GetBuffer(0));
	fclose(p1);
	*/
	//MessageBox(gStrEncrypt3);
	//MessageBox(gStrEncrypt2);
	//MessageBox(gStrEncrypt1);
}
void CWowTVDlg::Decrypt()
{
	int intlen,intlen1;
	char chrbuf,chrbuf1,chrbuf2;
	int i,intbuf;
	CString StrBuf1,StrBuf2;
	////////////////////////////////////////////////
	CString StrKey="jashliao2266";
	//intlen=gStrEncrypt1.GetLength();
	intlen=StrBase64Decoded1.GetLength();
	intlen1=StrKey.GetLength();
	gStrDecrypt1="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		//StrBuf1=gStrEncrypt1.Mid(i,1);
		StrBuf1=StrBase64Decoded1.Mid(i,1);
		StrBuf2=StrKey.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrDecrypt1+=chrbuf;
	}
	////////////////////////////////////////////////
	StrKey="jashliao778878";
	//intlen=gStrEncrypt2.GetLength();
	intlen=StrBase64Decoded2.GetLength();
	intlen1=StrKey.GetLength();
	gStrDecrypt2="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		//StrBuf1=gStrEncrypt2.Mid(i,1);
		StrBuf1=StrBase64Decoded2.Mid(i,1);
		StrBuf2=StrKey.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrDecrypt2+=chrbuf;
	}
	/////////////////////////////////////////////////
	StrKey="7788go78";
	//intlen=gStrEncrypt3.GetLength();
	intlen=StrBase64Decoded3.GetLength();
	intlen1=StrKey.GetLength();
	gStrDecrypt3="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		//StrBuf1=gStrEncrypt3.Mid(i,1);
		StrBuf1=StrBase64Decoded3.Mid(i,1);
		StrBuf2=StrKey.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrDecrypt3+=chrbuf;
	}
	/////////////////////////////////////////////////
	StrKey="jashliao2266 ";
	StrKey+="jashliao778878 ";
	StrKey+="7788go78";
	//intlen=gStrEncrypt4.GetLength();
	intlen=StrBase64Decoded4.GetLength();
	intlen1=StrKey.GetLength();
	gStrDecrypt3="";
	for(i=0;i<intlen1;i++)
	{
		StrBuf1="";
		StrBuf2="";
		//StrBuf1=gStrEncrypt3.Mid(i,1);
		StrBuf1=StrBase64Decoded4.Mid(i,1);
		StrBuf2=StrKey.Mid(i,1);
		strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
		strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
		chrbuf=chrbuf1^chrbuf2;
		intbuf=chrbuf;
		gStrDecrypt4+=chrbuf;
	}
	/////////////////////////////////////////////////
}
void CWowTVDlg::DisDriver()
{
	CString strResult,strRootPathName;
	strRootPathName=gstrCurDrt;
	strRootPathName=strRootPathName.Mid(0,3);
	UINT DrvType = GetDriveType(strRootPathName);
	switch(DrvType)
	{
	case DRIVE_CDROM:
		strResult = "光碟";
		break;
	case DRIVE_FIXED:
		strResult = "硬碟";
		break;
	case DRIVE_REMOVABLE:
		strResult = "磁片/USB";
		break;
	default:
		return;
		break;
	}
	gStrDisDriver=strResult;
	//MessageBox(strResult);
}
void CWowTVDlg::GetSrlNum()
{
	FILE *pf;
	char chrResult[10];
	pf=fopen("SrlNum.dll","r");
	if(pf!=NULL)
	{
		fscanf(pf,"%s",chrResult);
		fclose(pf);
	}
	pf=NULL;
	gStrVolumeSerialNumber=chrResult;
	//MessageBox(strResult);
}
void CWowTVDlg::GetNowTime()
{
	CString strResult;
	CTime time=CTime::GetCurrentTime();
	strResult=time.Format("%Y%m%d%H%M%S"); 
	gStrNowTime=strResult;
	//MessageBox(strResult);
}
void CWowTVDlg::GetMac()
{
	CString strResult;
	// TODO: Add your property handler here
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
     sprintf(sMacAddress, "%02x%02x%02x%02x%02x%02x",
     Adapter.adapt.adapter_address[0],
     Adapter.adapt.adapter_address[1],
     Adapter.adapt.adapter_address[2],
     Adapter.adapt.adapter_address[3],
     Adapter.adapt.adapter_address[4],
     Adapter.adapt.adapter_address[5] );
	}
	strResult=sMacAddress;
	gStrMAC=strResult;
	//MessageBox(strResult);
}

BEGIN_EVENTSINK_MAP(CWowTVDlg, CDialog)
    //{{AFX_EVENTSINK_MAP(CWowTVDlg)
	ON_EVENT(CWowTVDlg, IDC_EXPLORER1, 271 /* NavigateError */, OnNavigateErrorExplorer1, VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
	ON_EVENT(CWowTVDlg, IDC_EXPLORER1, 252 /* NavigateComplete2 */, OnNavigateComplete2Explorer1, VTS_DISPATCH VTS_PVARIANT)
	ON_EVENT(CWowTVDlg, IDC_EXPLORER1, 104 /* DownloadComplete */, OnDownloadCompleteExplorer1, VTS_NONE)
	ON_EVENT(CWowTVDlg, IDC_EXPLORER2, 104 /* DownloadComplete */, OnDownloadCompleteExplorer2, VTS_NONE)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CWowTVDlg::OnNavigateErrorExplorer1(LPDISPATCH pDisp, VARIANT FAR* URL, VARIANT FAR* Frame, VARIANT FAR* StatusCode, BOOL FAR* Cancel) 
{
	// TODO: Add your control notification handler code here
	
}
///////////////////////////////////////////////////////////
static inline bool is_base64(unsigned char c) {
  return (isalnum(c) || (c == '+') || (c == '/'));
}

CString base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
  CString ret;
  int i = 0;
  int j = 0;
  unsigned char char_array_3[3];
  unsigned char char_array_4[4];

  while (in_len--) {
    char_array_3[i++] = *(bytes_to_encode++);
    if (i == 3) {
      char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
      char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
      char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
      char_array_4[3] = char_array_3[2] & 0x3f;

      for(i = 0; (i <4) ; i++)
        ret += base64_chars[char_array_4[i]];
      i = 0;
    }
  }

  if (i)
  {
    for(j = i; j < 3; j++)
      char_array_3[j] = '\0';

    char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
    char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
    char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
    char_array_4[3] = char_array_3[2] & 0x3f;

    for (j = 0; (j < i + 1); j++)
      ret += base64_chars[char_array_4[j]];

    while((i++ < 3))
      ret += '=';

  }

  return ret;

}

CString base64_decode(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  CString ret;

  while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}
//////////////////////////////////////////////////////////////////////////////////////////

void CWowTVDlg::OnNavigateComplete2Explorer1(LPDISPATCH pDisp, VARIANT FAR* URL) 
{
	// TODO: Add your control notification handler code here	
	//沒用到
}

void CWowTVDlg::OnDownloadCompleteExplorer1() 
{
	// TODO: Add your control notification handler code here
	//傳送資料
	IHTMLElementCollection *objAllElement=NULL;
	IHTMLDocument2 *objDocument=NULL;
	CString strUrl,strTemp;
	strUrl=m_Web.GetLocationURL();//得到當前網頁的URL
	if(strUrl.IsEmpty())
		return;
	if(strUrl==gStrLocalFile)//修正Media Player無法放大
	{
		objDocument=(IHTMLDocument2 *)m_Web.GetDocument(); //由控制項得到IHTMLDocument2介面指標
		objDocument->get_all(&objAllElement); //得到網頁所有元素的集合
		//由於所有頁面下載完後都會執行這個函數，所以必須根據URL判斷消息來源網頁
		////////////////////////////////////
		IHTMLElement  *HTMLElement=NULL;
		objDocument->get_body(&HTMLElement);
		CString StrHTML;
		BSTR pdata;
		HTMLElement->get_outerHTML(&pdata);
		StrHTML=pdata;
		////////////////////////////////////////
		if(strUrl==gStrLocalFile) 
		{
			CComPtr<IDispatch>pDisp;
			if(HasItem(objAllElement,"auth")==true) //voteform為投票選項所在的Form
			{
				objAllElement->item(COleVariant("auth"),COleVariant((long)0),&pDisp);
				CComQIPtr<IHTMLFormElement , &IID_IHTMLFormElement >pElement; 
				if(pDisp==NULL)
				{
					return;
				}
				gStrKey=GetHidText(objAllElement,"key");
				std::string encoded5=gStrKey.GetBuffer(0); 
				StrBase64Decoded5 = base64_decode(encoded5);
				/////////////////////////////////////////////////
				int intlen,intlen1;
				char chrbuf,chrbuf1,chrbuf2;
				int i,intbuf;
				CString StrBuf1,StrBuf2;
				CString Str1,Str2;
				Str1=StrBase64Decoded5;
				//**************
				Str2="jashliao2266 ";
				Str2+="jashliao778878 ";
				Str2+="7788go78";
				//****************
				intlen=Str1.GetLength();
				intlen1=Str2.GetLength();
				gStrEncrypt5="";
				for(i=0;i<intlen1;i++)
				{
					StrBuf1="";
					StrBuf2="";
					StrBuf1=Str1.Mid(i,1);
					StrBuf2=Str2.Mid(i,1);
					strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
					strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
					chrbuf=chrbuf1^chrbuf2;
					intbuf=chrbuf;
					gStrEncrypt5+=chrbuf;
				}
				////////////////////////////////////////////
				Str1=gStrMAC+","+gStrNowTime+","+gStrVolumeSerialNumber;
				//**************
				Str2=gStrEncrypt5;
				//****************
				intlen=Str1.GetLength();
				intlen1=Str2.GetLength();
				gStrEncrypt4="";
				for(i=0;i<intlen1;i++)
				{
					StrBuf1="";
					StrBuf2="";
					StrBuf1=Str1.Mid(i,1);
					StrBuf2=Str2.Mid(i,1);
					strcpy(&chrbuf1,StrBuf1.GetBuffer(0));
					strcpy(&chrbuf2,StrBuf2.GetBuffer(0));
					chrbuf=chrbuf1^chrbuf2;
					intbuf=chrbuf;
					gStrEncrypt4+=chrbuf;
				}
				////////////////////////////////////////////
				StrBase64Encoded4 =base64_encode(reinterpret_cast<const unsigned char*>(gStrEncrypt4.GetBuffer(0)),gStrEncrypt4.GetLength());
				PutIEText(objAllElement,"xmac",StrBase64Encoded4);
				SubmitPage(objAllElement,"submit_login"); //提交網頁，vote為submit按鈕的id或name
			}
		}
	}
}

void CWowTVDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CDlgLoginFrm LoginFrm(this);
	switch(nIDEvent)
	{
		case 1:
			KillTimer(1);
			if(LoginFrm.DoModal()==IDOK)
			{
				COleVariant vaUrl;
				COleVariant vtMissing;
				vaUrl="http://develop.tw-airnet.net";
				m_Web.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing);
				SetTimer(2,1000,NULL);
			}
			else
			{
				this->OnCancel(); 
			}
			break;
		case 2:
			if(!CheckHW())
			{
				KillTimer(2);
				MessageBox("由於WowTV硬體已移除，因此程式及將關閉，如有不便敬請見諒。");
				this->OnCancel();
			}
			break;
		case 3:
			CWnd* pWnd=FindWindow(NULL,"Wow TV");
			if(pWnd!=NULL)
				::PostMessage(pWnd->m_hWnd, WM_CLOSE, 0, 0);   
			KillTimer(3);
			break;
	}
	CDialog::OnTimer(nIDEvent);
}

void CWowTVDlg::OnDownloadCompleteExplorer2() 
{
	// TODO: Add your control notification handler code here
	/*
	//傳送資料
	IHTMLElementCollection *objAllElement=NULL;
	IHTMLDocument2 *objDocument=NULL;
	CString strUrl,strTemp;
	strUrl=m_Web2.GetLocationURL();//得到當前網頁的URL
	if(strUrl.IsEmpty())
		return;
	objDocument=(IHTMLDocument2 *)m_Web2.GetDocument(); //由控制項得到IHTMLDocument2介面指標
	objDocument->get_all(&objAllElement); //得到網頁所有元素的集合
	//由於所有頁面下載完後都會執行這個函數，所以必須根據URL判斷消息來源網頁
	////////////////////////////////////
	IHTMLElement  *HTMLElement=NULL;
	objDocument->get_body(&HTMLElement);
	CString StrHTML;
	BSTR pdata;
	HTMLElement->get_outerHTML(&pdata);
	StrHTML=pdata;
	////////////////////////////////////////
	if(strUrl=="http://61.67.117.69/~5tv_xpe/auth/form") 
	{
		CComPtr<IDispatch>pDisp;
		if(HasItem(objAllElement,"auth")==true) //voteform為投票選項所在的Form
		{
			objAllElement->item(COleVariant("auth"),COleVariant((long)0),&pDisp);
			CComQIPtr<IHTMLFormElement , &IID_IHTMLFormElement >pElement; 
			if(pDisp==NULL)
			{
				return;
			}
			PutIEText(objAllElement,"c1",StrBase64Encoded4);
			SubmitPage(objAllElement,"submit_login"); //提交網頁，vote為submit按鈕的id或name
		}
	}
	*/
}
bool CWowTVDlg::HasItem(IHTMLElementCollection *pobjAllElement,CString strName)
{
	CComPtr<IDispatch>pDisp;
	pobjAllElement->item(COleVariant(strName),COleVariant((long)0),&pDisp);
	if(pDisp==NULL)
		return false;
	else 
		return true; 
}
void CWowTVDlg::PutIEText(IHTMLElementCollection *pobjAllElement,CString strName,CString strText)
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
void CWowTVDlg::SubmitPage(IHTMLElementCollection *pobjAllElement,CString strName)
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
void CWowTVDlg::CheckItem(IHTMLElementCollection *pobjAllElement,CString strName)
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
CString CWowTVDlg::GetHidText(IHTMLElementCollection *pobjAllElement,CString strName)
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
void CWowTVDlg::SelectItemValue(IHTMLElementCollection *pobjAllElement,CString strName,long number)
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

void CWowTVDlg::OnOK() 
{
	// TODO: Add extra validation here
	//CDialog::OnOK();
}

BOOL CWowTVDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message==WM_KEYDOWN)   
	{   
		if(pMsg->wParam==VK_ESCAPE)   
			return   TRUE;   
	}   	
	return CDialog::PreTranslateMessage(pMsg);
}
