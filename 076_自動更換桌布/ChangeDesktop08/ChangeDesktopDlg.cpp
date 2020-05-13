// ChangeDesktopDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChangeDesktop.h"
#include "ChangeDesktopDlg.h"
#include "GlobalVar.h"
#include "SetDlg.h"
#include <shlobj.h>//Step 3:ChangeDesktop
#include <mmsystem.h>//Step 1:ICON
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define WM_SHOWTASK	WM_USER+5//Step 2:ICON
HRESULT hr;//Step 4:ChangeDesktop
int gOnTimercount=0;
int gintCount=0;
char gunicode[2];
TCHAR gstrCurDrt[500];//存放目其目錄字串
NOTIFYICONDATA nid;
bool gblnIcon;
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
// CChangeDesktopDlg dialog

CChangeDesktopDlg::CChangeDesktopDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChangeDesktopDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChangeDesktopDlg)
	m_ALL = 0;
	m_NOW = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CChangeDesktopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChangeDesktopDlg)
	DDX_Text(pDX, IDC_ALL, m_ALL);
	DDX_Text(pDX, IDC_NOW, m_NOW);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChangeDesktopDlg, CDialog)
	//{{AFX_MSG_MAP(CChangeDesktopDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Hide, OnHide)
	ON_MESSAGE(WM_SHOWTASK,onShowTask)//Step 5:ICON
	ON_BN_CLICKED(IDC_Run, OnRun)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_SetShow, OnSetShow)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_COMMAND(IDC_NextPage, OnNextPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChangeDesktopDlg message handlers

BOOL CChangeDesktopDlg::OnInitDialog()
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
	/*
	m_blnOnTimer=false;
	if(!GetandSetParameter())
	{
		CreateXMLParameter();
		GetandSetParameter();
	}
	*/
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChangeDesktopDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChangeDesktopDlg::OnPaint() 
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
HCURSOR CChangeDesktopDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CChangeDesktopDlg::OnHide() 
{
	// TODO: Add your control notification handler code here
	/////////////////////////////////////////
	//Step 3 :ICON
	//NOTIFYICONDATA nid;
	if(!gblnIcon)
	{
		nid.cbSize=(DWORD)sizeof(NOTIFYICONDATA);
		nid.hWnd=this->m_hWnd;
		nid.uID=IDR_MAINFRAME;
		nid.uFlags=NIF_ICON|NIF_MESSAGE|NIF_TIP ;
		nid.uCallbackMessage=WM_SHOWTASK;//自定義的消息名稱
		nid.hIcon=LoadIcon(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME));
		strcpy(nid.szTip,"自動更換桌布");//資訊提示條為"計畫任務提醒"
		Shell_NotifyIcon(NIM_ADD,&nid);//在託盤區添加圖示
		ShowWindow(SW_HIDE);//隱藏主視窗
		gblnIcon=true;
	}
	else
	{
		ShowWindow(SW_HIDE);//隱藏主視窗
	}
	////////////////////////////////////////	
}
void CChangeDesktopDlg::BrowseDir(CString strDir)//Step 1:列出檔案清單
{
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.jpg";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			BrowseDir(ff.GetFilePath());
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			m_Array.Add(ff.GetFilePath());
		}
	}
	ff.Close();
}
LRESULT CChangeDesktopDlg::onShowTask(WPARAM wParam,LPARAM lParam)//Step 6:ICON
{
	//wParam接收的是圖示的ID，而lParam接收的是滑鼠的行為
	if(wParam!=IDR_MAINFRAME)
		return 1;
	switch(lParam)
	{
		case WM_RBUTTONUP://右鍵起來時彈出快顯功能表，這裏只有一個"關閉"
		{ 
			LPPOINT lpoint=new tagPOINT;
			::GetCursorPos(lpoint);//得到滑鼠位置
			CMenu menu;
			menu.CreatePopupMenu();//聲明一個彈出式功能表
			//增加功能表項"關閉"，點擊則發送消息WM_DESTROY給主視窗（已
			//隱藏），將程式結束。
			menu.AppendMenu(MF_STRING,WM_DESTROY,"關閉");
			menu.AppendMenu(MF_STRING,IDC_NextPage,"下一張桌布");
			//確定彈出式菜單的位置
			menu.TrackPopupMenu(TPM_LEFTALIGN,lpoint->x,lpoint->y,this);
			//資源回收
			HMENU hmenu=menu.Detach();
			menu.DestroyMenu();
			delete lpoint;
		}
		break;
		case WM_LBUTTONDBLCLK://雙擊左鍵的處理
		{
			this->ShowWindow(SW_SHOW);//簡單的顯示主視窗完事兒
		}
		break;
	}
	return 0;
}

void CChangeDesktopDlg::OnRun() 
{
	// TODO: Add your control notification handler code here
	///*
	FILE *pf;
	CString Strbuf;
	if(m_blnOnTimer)
	{
		m_blnOnTimer=!m_blnOnTimer;
		KillTimer(1);
	}
	m_Array.RemoveAll(); 
	pf=fopen("data.txt","w");
	BrowseDir(gStrImageDir);
	int size=m_Array.GetSize();
	for(int i=0;i<size;i++)
	{
		Strbuf=m_Array.GetAt(i);
		fprintf(pf,"%s\n",Strbuf.GetBuffer(0)); 
	}
	fclose(pf);
	//MessageBox("OK");
	//*/
	gOnTimercount=0;
	m_intCount=m_Array.GetSize();
	if(!m_blnOnTimer)
	{
		m_blnOnTimer=!m_blnOnTimer;
		SetTimer(1,10000,NULL);
	}
}
bool CChangeDesktopDlg::GetandSetParameter()//step 4:讀取XML
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	bool blnRead=false;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return false;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="Config.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
		MSXML2::IXMLDOMNodePtr  NodeData;
		////////////////////////////////////////////////////////////
		NodeData=pDoc->selectSingleNode("//Style");	
		NodeData->get_nodeTypedValue(&vtStr);
		gStrImageDir=vtStr.bstrVal;
		gintStyle=atoi(gStrImageDir.GetBuffer(0));
		//*************************************************
		NodeData=pDoc->selectSingleNode("//time");	
		NodeData->get_nodeTypedValue(&vtStr);
		gStrImageDir=vtStr.bstrVal;
		gintChangetime=atoi(gStrImageDir.GetBuffer(0));
		//*************************************************
		NodeData=pDoc->selectSingleNode("//Dir");	
		NodeData->get_nodeTypedValue(&vtStr);
		gStrImageDir=vtStr.bstrVal;
		//*************************************************
	}
	return blnRead;
}
void CChangeDesktopDlg::CreateXMLParameter()
{
	FILE *pf;
	gunicode[0] = 0xFF;   
	gunicode[1] = 0xFE;
	CString StrDataBuf;
	int intUnicodeDataLen;
	WCHAR UnicodeDataBuf[200];

	//****************************************************************
	pf=fopen("Config.xml","wb");
	fwrite(gunicode,sizeof(char),2,pf);
	//****************************************************************
	StrDataBuf="\<?xml version=\"1.0\" encoding=\"unicode\" ?>";
	StrDataBuf+="\r\n";
	intUnicodeDataLen=StrDataBuf.GetLength();//計算資料長度
	MultiByteToWideChar(CP_ACP, 0,StrDataBuf.GetBuffer(0),-1,UnicodeDataBuf,StrDataBuf.GetLength());//ANSI轉換UNICODE
	fwrite(UnicodeDataBuf,sizeof(WCHAR),StrDataBuf.GetLength(),pf);//寫檔
	//*****************************************************************
	UnicodeDataBuf[0] = '\0';
	StrDataBuf="<appSetting>";
	StrDataBuf+="\r\n";
	intUnicodeDataLen=StrDataBuf.GetLength();//計算資料長度
	MultiByteToWideChar(CP_ACP, 0,StrDataBuf.GetBuffer(0),-1,UnicodeDataBuf,StrDataBuf.GetLength());//ANSI轉換UNICODE
	fwrite(UnicodeDataBuf,sizeof(WCHAR),StrDataBuf.GetLength(),pf);//寫檔
	//********************************************************************
	UnicodeDataBuf[0] = '\0';
	StrDataBuf.Format("\t<Style>0</Style>");//置中
	StrDataBuf+="\r\n";
	intUnicodeDataLen=StrDataBuf.GetLength();//計算資料長度
	MultiByteToWideChar(CP_ACP, 0,StrDataBuf.GetBuffer(0),-1,UnicodeDataBuf,StrDataBuf.GetLength());//ANSI轉換UNICODE
	fwrite(UnicodeDataBuf,sizeof(WCHAR),StrDataBuf.GetLength(),pf);//寫檔
	//**********************************************************************
	UnicodeDataBuf[0] = '\0';
	StrDataBuf.Format("\t<time>40</time>");
	StrDataBuf+="\r\n";
	intUnicodeDataLen=StrDataBuf.GetLength();//計算資料長度
	MultiByteToWideChar(CP_ACP, 0,StrDataBuf.GetBuffer(0),-1,UnicodeDataBuf,StrDataBuf.GetLength());//ANSI轉換UNICODE
	fwrite(UnicodeDataBuf,sizeof(WCHAR),StrDataBuf.GetLength(),pf);//寫檔
	//********************************************************************
	UnicodeDataBuf[0] = '\0';
	StrDataBuf.Format("\t<Dir>Desktop_file</Dir>");
	StrDataBuf+="\r\n";
	intUnicodeDataLen=StrDataBuf.GetLength();//計算資料長度
	MultiByteToWideChar(CP_ACP, 0,StrDataBuf.GetBuffer(0),-1,UnicodeDataBuf,StrDataBuf.GetLength());//ANSI轉換UNICODE
	fwrite(UnicodeDataBuf,sizeof(WCHAR),StrDataBuf.GetLength(),pf);//寫檔
	//**********************************************************************
	UnicodeDataBuf[0] = '\0';
	StrDataBuf="";
	StrDataBuf="</appSetting>";
	StrDataBuf+="\r\n";
	intUnicodeDataLen=StrDataBuf.GetLength();//計算資料長度
	MultiByteToWideChar(CP_ACP, 0,StrDataBuf.GetBuffer(0),-1,UnicodeDataBuf,StrDataBuf.GetLength());//ANSI轉換UNICODE
	fwrite(UnicodeDataBuf,sizeof(WCHAR),StrDataBuf.GetLength(),pf);//寫檔
	//**********************************************************************
	fclose(pf);
}
void CChangeDesktopDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	CString StrShowWaitTime;
	BOOL res;
	gOnTimercount++;
	if(gOnTimercount==(gintChangetime/10))
	{
		gOnTimercount=0;
		CString Strbuf;
		CString Strbuf1;
		IActiveDesktop *pIAD;
		Strbuf1.Format("第%d筆",gintCount); 
		this->SetWindowText(Strbuf1);
		strcpy(nid.szTip,Strbuf1.GetBuffer(0)); 
		res = Shell_NotifyIcon(NIM_MODIFY, &nid);//更新提示文字
		m_ALL=m_intCount;
		m_NOW=gintCount+1;
		UpdateData(false);		
		Strbuf=m_Array.GetAt(gintCount);
		gintCount++;
		if(gintCount>=m_intCount)
		{
			gintCount=0;
		}
		hr = CoCreateInstance( CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,IID_IActiveDesktop, (void**)&pIAD);
		if ( !SUCCEEDED(hr) )
			MessageBox("error1");
		// 設定牆紙前先打開活動桌面開關
		COMPONENTSOPT co = {0};
		co.dwSize = sizeof(COMPONENTSOPT);
		co.fEnableComponents = TRUE;
		co.fActiveDesktop = TRUE;
		hr = pIAD->SetDesktopItemOptions(&co, 0);
		if ( !SUCCEEDED(hr) ) 
			MessageBox("error2");
		// 設定牆紙
		CString strPath;
		strPath=Strbuf;
		WCHAR wszPath[100];
		LPTSTR lpStr = strPath.GetBuffer(strPath.GetLength());
		MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszPath, 100);
		strPath.ReleaseBuffer();
		hr=pIAD->SetWallpaper(wszPath,0);

		WALLPAPEROPT wp = {0};
		wp.dwSize = sizeof(WALLPAPEROPT);
		/*
		WPSTYLE_CENTER
		WPSTYLE_TILE
		WPSTYLE_STRETCH
		WPSTYLE_MAX
		*/
		if(gintStyle==0)
		{
			wp.dwStyle |= WPSTYLE_CENTER;//置中
		}
		if(gintStyle==1)
		{
			wp.dwStyle |= WPSTYLE_STRETCH;//填滿
		}
		if(gintStyle==2)
		{
			wp.dwStyle |= WPSTYLE_TILE;//並排
		}
		hr = pIAD->SetWallpaperOptions(&wp, 0);
		hr = pIAD->ApplyChanges(AD_APPLY_ALL);
		pIAD->Release();
	}
	else
	{
		StrShowWaitTime.Format("還要等待 %d 秒",(gintChangetime-(gOnTimercount*10)));
		this->SetWindowText(StrShowWaitTime);
	}
	CDialog::OnTimer(nIDEvent);
}

void CChangeDesktopDlg::OnSetShow() 
{
	// TODO: Add your control notification handler code here
	CSetDlg Setdlg(this);
	if(m_blnOnTimer)
	{
		m_blnOnTimer=!m_blnOnTimer;
		KillTimer(1);
	}
	if(Setdlg.DoModal()==IDOK)
	{
		gStrImageDir=Setdlg.m_Dir;
		if(Setdlg.m_time>10)
		{
			gintChangetime=Setdlg.m_time;
		}
		else
		{
			gintChangetime=10;
		}
		if(Setdlg.m_Style=="置中:0")
		{
			gintStyle=0;
		}
		if(Setdlg.m_Style=="填滿:1")
		{
			gintStyle=1;
		}
		if(Setdlg.m_Style=="並排:2")
		{
			gintStyle=2;
		}
		SaveParameter();
		OnRun();
	}
}
void CChangeDesktopDlg::SaveParameter()//step 7:讀取XML
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	CString StrBuf;
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
	strFileName1 +="Config.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
			MSXML2::IXMLDOMNodePtr  NodeData;
			////////////////////////////////////////////////////////////
			NodeData=pDoc->selectSingleNode("//Style");	
			StrBuf.Format("%d",gintStyle); 
			NodeData->put_text((_bstr_t)(const char *)StrBuf);
			//**************************************************
			NodeData=pDoc->selectSingleNode("//time");	
			StrBuf.Format("%d",gintChangetime); 
			NodeData->put_text((_bstr_t)(const char *)StrBuf);
			//**************************************************
			NodeData=pDoc->selectSingleNode("//Dir");	
			StrBuf=gStrImageDir;
			NodeData->put_text((_bstr_t)(const char *)StrBuf);
			//**************************************************
			pDoc->save((_bstr_t)strFileName1); 
	}
}

BOOL CChangeDesktopDlg::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext) 
{
	// TODO: Add your specialized code here and/or call the base class	
	return CDialog::Create(IDD, pParentWnd);
}

int CChangeDesktopDlg::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_blnOnTimer=false;
	gblnIcon=false;
	if(!GetandSetParameter())
	{
		CreateXMLParameter();
		GetandSetParameter();
	}	
	return 0;
}

void CChangeDesktopDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	if(gblnIcon)
		Shell_NotifyIcon(NIM_DELETE,&nid);//在託盤區添刪圖示
}

void CChangeDesktopDlg::OnNextPage() 
{
	// TODO: Add your command handler code here
	gOnTimercount=0;
	CString Strbuf;
	CString Strbuf1;
	IActiveDesktop *pIAD;
	Strbuf1.Format("第%d筆",gintCount); 
	this->SetWindowText(Strbuf1);
	strcpy(nid.szTip,Strbuf1.GetBuffer(0)); 
	Shell_NotifyIcon(NIM_MODIFY, &nid);//更新提示文字
	m_ALL=m_intCount;
	m_NOW=gintCount+1;
	UpdateData(false);		
	Strbuf=m_Array.GetAt(gintCount);
	gintCount++;
	if(gintCount>=m_intCount)
	{
		gintCount=0;
	}
	hr = CoCreateInstance( CLSID_ActiveDesktop, NULL, CLSCTX_INPROC_SERVER,IID_IActiveDesktop, (void**)&pIAD);
	if ( !SUCCEEDED(hr) )
		MessageBox("error1");
	// 設定牆紙前先打開活動桌面開關
	COMPONENTSOPT co = {0};
	co.dwSize = sizeof(COMPONENTSOPT);
	co.fEnableComponents = TRUE;
	co.fActiveDesktop = TRUE;
	hr = pIAD->SetDesktopItemOptions(&co, 0);
	if ( !SUCCEEDED(hr) ) 
		MessageBox("error2");
	// 設定牆紙
	CString strPath;
	strPath=Strbuf;
	WCHAR wszPath[100];
	LPTSTR lpStr = strPath.GetBuffer(strPath.GetLength());
	MultiByteToWideChar(CP_ACP, 0, lpStr, -1, wszPath, 100);
	strPath.ReleaseBuffer();
	hr=pIAD->SetWallpaper(wszPath,0);

	WALLPAPEROPT wp = {0};
	wp.dwSize = sizeof(WALLPAPEROPT);
	/*
	WPSTYLE_CENTER
	WPSTYLE_TILE
	WPSTYLE_STRETCH
	WPSTYLE_MAX
	*/
	if(gintStyle==0)
	{
		wp.dwStyle |= WPSTYLE_CENTER;//置中
	}
	if(gintStyle==1)
	{
		wp.dwStyle |= WPSTYLE_STRETCH;//填滿
	}
	if(gintStyle==2)
	{
		wp.dwStyle |= WPSTYLE_TILE;//並排
	}
	hr = pIAD->SetWallpaperOptions(&wp, 0);
	hr = pIAD->ApplyChanges(AD_APPLY_ALL);
	pIAD->Release();
}
