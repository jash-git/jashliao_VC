
// UpdateNowNewsAVDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "UpdateNowNewsAV.h"
#include "UpdateNowNewsAVDlg.h"

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


// CUpdateNowNewsAVDlg 對話方塊




CUpdateNowNewsAVDlg::CUpdateNowNewsAVDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUpdateNowNewsAVDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CUpdateNowNewsAVDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CUpdateNowNewsAVDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


// CUpdateNowNewsAVDlg 訊息處理常式

BOOL CUpdateNowNewsAVDlg::OnInitDialog()
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
	CString PostData;
	PostData=_T("op=source_nownews&row=1030050 || 政治 || 2010/05/26 09:42 || 12814169 || http://219.85.68.173/1030/v1030050.wmv || 現場消息？國軍天馬操演　射擊46枚拖式飛彈 ||");
	MessageBox(NowNewsHttpPost(PostData));
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

void CUpdateNowNewsAVDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CUpdateNowNewsAVDlg::OnPaint()
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
HCURSOR CUpdateNowNewsAVDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
CString CUpdateNowNewsAVDlg::NowNewsHttpPost(CString StrPostData)
{
	CString strHeaders =_T("Content-Type: application/x-www-form-urlencoded");
	// URL-encoded form variables -
	// name = "John Doe", userid = "hithere", other = "P&Q"
	CString strFormData; //= _T("op=source_nownews&row=1030050 || 政治 || 2010/05/26 09:42 || 12814169 || [Mail系統 警告: 帶有數字IP的網址通常都是有問題的]: http://219.85.68.173/1030/v1030050.wmv || 現場消息？國軍天馬操演　射擊46枚拖式飛彈 ||");
	CString strServerName;
	strFormData=StrPostData;
	strServerName=_T("xpe5tv.tw-airnet.net");
	CInternetSession session;
	CHttpConnection* pConnection = session.GetHttpConnection(strServerName);
	CHttpFile* pFile = pConnection->OpenRequest(CHttpConnection::HTTP_VERB_POST,_T("cgi-php/media_transform.php"));
	BOOL result = pFile->SendRequest(strHeaders,(LPVOID)(LPCTSTR)strFormData, strFormData.GetLength());
	char buf[2];
	CString resultString =_T("");
	//BOOL result1= pFile->ReadString(resultString);
	while( pFile->Read(buf, 1) > 0 )
	{
		resultString +=buf[0];
	}
	return resultString;
}
