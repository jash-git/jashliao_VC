// VS2008ExecuteAConsoleDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "VS2008ExecuteAConsole.h"
#include "VS2008ExecuteAConsoleDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CVS2008ExecuteAConsoleDlg 對話方塊




CVS2008ExecuteAConsoleDlg::CVS2008ExecuteAConsoleDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVS2008ExecuteAConsoleDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVS2008ExecuteAConsoleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CVS2008ExecuteAConsoleDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CVS2008ExecuteAConsoleDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CVS2008ExecuteAConsoleDlg 訊息處理常式

BOOL CVS2008ExecuteAConsoleDlg::OnInitDialog()
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

	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CVS2008ExecuteAConsoleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CVS2008ExecuteAConsoleDlg::OnPaint()
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
HCURSOR CVS2008ExecuteAConsoleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVS2008ExecuteAConsoleDlg::OnBnClickedButton1()
{
	SECURITY_ATTRIBUTES sa,sa2;
	HANDLE hInputRead,hInputWrite;
	HANDLE hOutputRead,hOutputWrite;
	//CreatePipe1
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreatePipe(&hOutputRead,&hOutputWrite,&sa,0))
	{
		return;
	}
	//CreatePipe2
	sa2.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa2.lpSecurityDescriptor = NULL;
	sa2.bInheritHandle = TRUE;
	if (!CreatePipe(&hInputRead,&hInputWrite,&sa2,0))
	{
		return;
	}
	//CreateProcess
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	si.cb = sizeof(STARTUPINFO);
	GetStartupInfo(&si);
	si.hStdError = hOutputWrite;
	si.hStdOutput = hOutputWrite;
	si.hStdInput = hInputRead;
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	DWORD dwWritten;
	if (!CreateProcess(_T("C:\\Windows\\System32\\cmd.exe"),NULL,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
	{
		MessageBox(L"Error On CreateProcess");
		return;
	}
	CloseHandle(hInputRead);
	CloseHandle(hOutputWrite);
	//Write and read
	char szInPut[20] ="ping 127.0.0.1\n";// 設置輸入內容
	WriteFile(hInputWrite, szInPut, strlen(szInPut), &dwWritten, NULL);
	char buffer[4096] = {0};
	DWORD bytesRead;
	bool blncheck;
	while (true)
	{ 
		Sleep(500);
		blncheck=false;
		buffer[0]='\0';
		blncheck=PeekNamedPipe(hOutputRead,buffer,1024,&bytesRead,0,0);
		if(bytesRead>0)
			blncheck=ReadFile(hOutputRead,buffer,bytesRead,&bytesRead,0);
		else
			break;
		//計算char *陣列大小，以位元組為單位，一個漢字占兩個位元組
		int len;
		int charLen = strlen(buffer);
		//計算多位元組字元的大小，按字元計算。
		len = MultiByteToWideChar(CP_ACP,0,buffer,charLen,NULL,0);
		//為寬位元組字元陣列申請空間，陣列大小為按位元組計算的多位元組字元大小
		TCHAR *buf = new TCHAR[len + 1];
		//多位元組編碼轉換成寬位元組編碼
		MultiByteToWideChar(CP_ACP,0,buffer,charLen,buf,len);
		buf[len] = '\0'; //添加字串結尾，注意不是len+1
		CString pWideChar;
		pWideChar.Append(buf);
		delete [] buf;
		MessageBox(pWideChar);// 輸出
		
	}
	CloseHandle(hInputWrite);
	CloseHandle(hOutputRead);
	MessageBox(L"finish...");// 輸出	
}
