// JashtestFTPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "JashtestFTP.h"
#include "JashtestFTPDlg.h"
#include<fstream.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
FILE *pf1;
bool gblnConnet=false;
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
// CJashtestFTPDlg dialog

CJashtestFTPDlg::CJashtestFTPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CJashtestFTPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CJashtestFTPDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJashtestFTPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CJashtestFTPDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CJashtestFTPDlg, CDialog)
	//{{AFX_MSG_MAP(CJashtestFTPDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJashtestFTPDlg message handlers

BOOL CJashtestFTPDlg::OnInitDialog()
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
	SetTimer(1,10000,NULL);
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CJashtestFTPDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CJashtestFTPDlg::OnPaint() 
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
HCURSOR CJashtestFTPDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CJashtestFTPDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	//FTP_3
	CString StrDownLoadFileName;
	CTime t1=CTime::GetCurrentTime();
	StrDownLoadFileName=t1.Format( "%Y%m%d" );
	StrDownLoadFileName="Log\\FTP_"+StrDownLoadFileName;
	StrDownLoadFileName+=".txt";
	pf1=fopen(StrDownLoadFileName.GetBuffer(0),"w");
	m_pInetSession=new CInternetSession (AfxGetAppName(),1, PRE_CONFIG_INTERNET_ACCESS); 
	CString StrBuf;
	try 
	{ 
		//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
		m_pFtpConnection=m_pInetSession->GetFtpConnection(m_StrServerName,m_StrUserName,m_StrPassWord);
		///////////////////////////////////////////////////////////
		t1=t1.GetCurrentTime();
		StrBuf=t1.Format("%Y%m%d%H%M%S");
		StrBuf+=";;Connect success;;";
		fprintf(pf1,"%s\n",StrBuf.GetBuffer(0)); 
		///////////////////////////////////////////////////////////
		//MessageBox("OK_01");
		gblnConnet=true;
	} 
	catch(CInternetException *pEx) 
	{ 
		TCHAR szError[1024]; 
		pEx->GetErrorMessage(szError,1024); 
		pEx->Delete(); 
		m_pFtpConnection=NULL;
		///////////////////////////////////////////////
		t1=t1.GetCurrentTime();
		StrBuf=t1.Format("%Y%m%d%H%M%S");
		StrBuf+=";;Connect faill;;";
		fprintf(pf1,"%s\n",StrBuf.GetBuffer(0));
		//////////////////////////////////////////////
		gblnConnet=false;
	}
}

void CJashtestFTPDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	fstream pf;
	CString StrFileData;
	CString StrSaveFileData;
	CTime t1=CTime::GetCurrentTime();
	CString StrBuf;
	int intGetDataAns=0;
	char chrdata[500]; 
	pf.open("webfilelist.txt",ios::in);
	while(!pf.eof())
	{
		pf.getline(chrdata,500);
		StrFileData=chrdata;
		if(StrFileData!="")
		{
			StrSaveFileData="AV\\"+StrFileData;
			intGetDataAns=m_pFtpConnection->GetFile(StrFileData,StrSaveFileData,true,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1);
			///////////////////////////////////////////////
			t1=t1.GetCurrentTime();
			StrBuf=t1.Format("%Y%m%d%H%M%S");
			if(intGetDataAns)
			{
				StrBuf+=";;DownLoad success;;";
			}
			else
			{
				StrBuf+=";;DownLoad faill;;";
			}
			StrBuf+=StrFileData;
			fprintf(pf1,"%s\n",StrBuf.GetBuffer(0));
			//////////////////////////////////////////////			
		}
	}
}

void CJashtestFTPDlg::OnClose() 
{

	CDialog::OnClose();
}

void CJashtestFTPDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	//FTP_4
	CTime t1=CTime::GetCurrentTime();
	CString StrBuf;
	if(m_pFtpConnection!=NULL) 
	{ 
		m_pFtpConnection->Close();
		///////////////////////////////////////////////
		t1=t1.GetCurrentTime();
		StrBuf=t1.Format("%Y%m%d%H%M%S");
		StrBuf+=";;DisConnect success;;";
		fprintf(pf1,"%s\n",StrBuf.GetBuffer(0));
		//////////////////////////////////////////////		
		delete m_pFtpConnection; 
		fclose(pf1);
		delete m_pInetSession;
	} 	
}

void CJashtestFTPDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	KillTimer(1);
	GetSettingData();
	OnButton1();
	if(gblnConnet)
	{
		OnButton2();
	}
	ShellExecute(NULL,"open","test_Analyse_Data.exe",NULL,NULL,SW_SHOWNORMAL);
	this->OnOK();	
	CDialog::OnTimer(nIDEvent);
}
void CJashtestFTPDlg::GetSettingData()
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMNodePtr   pNode;
	_variant_t vtStr;
	bool blnRead=false;
	CString StrValue;
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
	strFileName1 +="FTPSetting.dat";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
		pNode=pDoc->selectSingleNode("//SERVERNAME");
		pNode->get_nodeTypedValue(&vtStr);  
		StrValue=vtStr.bstrVal;
		m_StrServerName=StrValue;
		//************************************************
		pNode=pDoc->selectSingleNode("//USERNAME");
		pNode->get_nodeTypedValue(&vtStr);  
		StrValue=vtStr.bstrVal;
		m_StrUserName=StrValue;
		//************************************************
		pNode=pDoc->selectSingleNode("//PassWord");
		pNode->get_nodeTypedValue(&vtStr);  
		StrValue=vtStr.bstrVal;
		m_StrPassWord=StrValue;
		//************************************************
	}
}
