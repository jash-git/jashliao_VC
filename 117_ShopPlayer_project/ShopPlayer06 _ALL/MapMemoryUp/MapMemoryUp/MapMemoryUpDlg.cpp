// MapMemoryUpDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "MapMemoryUp.h"
#include "MapMemoryUpDlg.h"
#include <winbase.h>//MAP memory_step 01
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//////////////////////////////////////
//MAP memory_step 02
#define	MAP_Data	"data info"
#define	MAP_LENGTH	1024
HANDLE hDataMap = NULL ;
static char szOldData[MAP_LENGTH] = "" ;
//////////////////////////////////////
HANDLE m_hPro;//CreateProcess step01, step 00同MAP memory_step01
int inttimercount;
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


// CMapMemoryUpDlg 對話方塊




CMapMemoryUpDlg::CMapMemoryUpDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMapMemoryUpDlg::IDD, pParent)
	, m_V1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMapMemoryUpDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_V1);
}

BEGIN_MESSAGE_MAP(CMapMemoryUpDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CMapMemoryUpDlg 訊息處理常式

BOOL CMapMemoryUpDlg::OnInitDialog()
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
	hDataMap = CreateFileMapping( (HANDLE)0xFFFFFFFF,NULL, PAGE_READWRITE, 0, MAP_LENGTH,	TEXT(MAP_Data) ) ;//MAP memory_step 03
	LPVOID mapView = MapViewOfFile( hDataMap,FILE_MAP_WRITE, 0, 0, 0 ) ;//MAP memory_step 04
	////////////////////////////////////////////////////////////////////////////////////////
	//MAP memory_step 05
	inttimercount=2;
	CString theString( "d:\\22.wmv,0" ); 
	LPTSTR lpsz = new TCHAR[theString.GetLength()+1]; 
	_tcscpy(lpsz, theString);
	_tcscpy((LPTSTR)mapView,lpsz);
	UnmapViewOfFile( (LPVOID)mapView);
	delete []lpsz;
	////////////////////////////////////////////////////////////////////////////////////////
	SetTimer(1,1000,NULL);
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CMapMemoryUpDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMapMemoryUpDlg::OnPaint()
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
HCURSOR CMapMemoryUpDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMapMemoryUpDlg::OnTimer(UINT_PTR nIDEvent)
{
	CString StrData;
	CString theString;
	LPVOID mapView = MapViewOfFile( hDataMap,FILE_MAP_WRITE, 0, 0, 0 ) ;
	if(!m_hPro)//判斷是否可以關閉此程式
	{
		CallPlayer();
	}
	UpdateData(true);
	if( mapView != NULL ) 
	{
		StrData=(LPTSTR)mapView;
		if(StrData=="")
		{
			if(inttimercount==2)
			{
				inttimercount=1;
				theString=_T("d:\\11.wmv,0");
			}
			else
			{
				inttimercount=2;
				theString=_T("d:\\22.wmv,0");
			}
			m_V1=theString;
			UpdateData(false);
			LPTSTR lpsz = new TCHAR[theString.GetLength()+1]; 
			_tcscpy(lpsz, theString);
			_tcscpy((LPTSTR)mapView,lpsz);
			UnmapViewOfFile( (LPVOID)mapView);
			delete []lpsz;
		}
	}	

	CDialog::OnTimer(nIDEvent);
}
void CMapMemoryUpDlg::CallPlayer()//CreateProcess step03
{
	///*
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	//變數初始化
	ZeroMemory( &si, sizeof(si) );//memset(&si,0,sizeof(si));
	si.cb=sizeof(si);
	si.wShowWindow=SW_SHOW;
	si.dwFlags |= STARTF_USESHOWWINDOW;
	wchar_t  szExeFile[] = L"C:\\Shop\\ShopPlayer.exe";
	//打開程式
	BOOL fRet=CreateProcess(szExeFile,
							NULL,
							NULL,
							NULL,
							FALSE,
							NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
							NULL,
							NULL,
							&si,
							&pi);

	if(!fRet)
	{//開啟失敗，顯示錯誤訊息
		LPVOID lpMsgBuf;
		FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | 
						FORMAT_MESSAGE_FROM_SYSTEM | 
						FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL,
						GetLastError(),
						MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
						(LPTSTR) &lpMsgBuf,
						0,
						NULL );
		AfxMessageBox( (LPCTSTR)lpMsgBuf);
		LocalFree( lpMsgBuf );

	}
	else
	{
		m_hPro=pi.hProcess;
		AfxMessageBox(_T("CreateProcess成功"));
	}
	//*/
}
void CMapMemoryUpDlg::OnDestroy()//CreateProcess step04
{
	CDialog::OnDestroy();
	// TODO: Add your control notification handler code here
	if(m_hPro)//判斷是否可以關閉此程式
	{
		
		if(!TerminateProcess(m_hPro,0))//執行關閉程式
		{
			//顯示關閉錯誤訊息
			LPVOID lpMsgBuf;
			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | 
						FORMAT_MESSAGE_FROM_SYSTEM | 
						FORMAT_MESSAGE_IGNORE_INSERTS,
						NULL,
						GetLastError(),
						MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Default language
						(LPTSTR) &lpMsgBuf,
						0,
						NULL );
			AfxMessageBox( (LPCTSTR)lpMsgBuf);
			LocalFree( lpMsgBuf );
		}
		else
		{
			AfxMessageBox(_T("TerminateProcess成功"));
		}
		m_hPro=NULL;
	}
	else
	{
		AfxMessageBox(_T("程式不存在"));
	}
}
