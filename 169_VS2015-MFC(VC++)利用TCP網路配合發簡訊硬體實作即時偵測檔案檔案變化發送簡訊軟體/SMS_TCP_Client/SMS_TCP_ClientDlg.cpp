
// SMS_TCP_ClientDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "SMS_TCP_Client.h"
#include "SMS_TCP_ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSMS_TCP_ClientDlg 對話方塊



CSMS_TCP_ClientDlg::CSMS_TCP_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SMS_TCP_CLIENT_DIALOG, pParent)
	, m_StrNowTime(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSMS_TCP_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NowTime, m_StrNowTime);
}

BEGIN_MESSAGE_MAP(CSMS_TCP_ClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSMS_TCP_ClientDlg 訊息處理常式

BOOL CSMS_TCP_ClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	ShowWindow(SW_MINIMIZE);

	// TODO: 在此加入額外的初始設定
	SetTimer(1, 1000, NULL);//開啟Timer
	
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CSMS_TCP_ClientDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CSMS_TCP_ClientDlg::OnQueryDragIcon()
{

	return static_cast<HCURSOR>(m_hIcon);
}



void CSMS_TCP_ClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此加入您的訊息處理常式程式碼和 (或) 呼叫預設值
	CString SendData;
	FILE *pf = NULL;
	TCHAR gstrCurDrt[500];//存放目其目錄字串
	int nLen = ::GetCurrentDirectory(500, gstrCurDrt);//取得目前程式路徑
	if (gstrCurDrt[nLen] != '\\')
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}

	KillTimer(1);
	CString StrCallExePath;
	CString StrCallExeName;
	CString StrListName;
	StrCallExeName = gstrCurDrt;
	StrCallExeName += "SMS_DATA\\get_list.bat ";
	StrCallExePath = gstrCurDrt;
	StrCallExePath += "SMS_DATA\\";
	StrListName = gstrCurDrt;
	StrListName += "SMS_DATA\\list.txt";

	fopen_s(&pf,StrCallExeName.GetBuffer(0), "w");
	fprintf(pf, "dir /b /on >list.txt");
	fclose(pf);

	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	si.wShowWindow = SW_MINIMIZE;
	si.dwFlags = STARTF_USESHOWWINDOW;
	BOOL fRet = CreateProcess(NULL,
		StrCallExeName.GetBuffer(0),
		NULL,
		NULL,
		FALSE,
		NORMAL_PRIORITY_CLASS | CREATE_NEW_CONSOLE,
		NULL,
		StrCallExePath.GetBuffer(0),
		&si,
		&pi);
	if (fRet)
	{
		WaitForSingleObject(pi.hProcess, INFINITE);
	}

	pf = NULL;
	char buf[513];
	CArray <CString, CString&> ArrayData;
	ArrayData.RemoveAll();
	fopen_s(&pf, StrListName.GetBuffer(0), "r");
	while (fgets(buf, 512, pf) != NULL)
	{
		CString StrBuf = buf;
		if ( (StrBuf != "\n") && (StrBuf != "get_list.bat\n") && (StrBuf != "list.txt\n") )
		{

			ArrayData.Add(StrBuf.Left(StrBuf.GetLength()-1));
		}
	}
	fclose(pf);
	
	CTime timeNow = CTime::GetCurrentTime();
	UpdateData(true);
	if (ArrayData.GetCount() == 0)
	{
		m_StrNowTime = timeNow.Format("%Y/%m/%d %H:%M:%S") + "\nWaiting...";
	}
	else
	{
		CSocket m_socket01;//Socket Step02
		m_socket01.Create();//Socket Step03
		bool check = m_socket01.Connect("192.168.0.102", 10006);
		if (check == true)
		{
			for (int i = 0; i < ArrayData.GetCount(); i++)
			{
				CString StrFileName = gstrCurDrt;
				StrFileName += "SMS_DATA\\";
				StrFileName += ArrayData.GetAt(i);
				pf = NULL;
				fopen_s(&pf, StrFileName.GetBuffer(0), "r");
				while (fgets(buf, 512, pf) != NULL)
				{
					SendData.Format("%s", buf);
					m_socket01.Send(SendData.GetBuffer(0), SendData.GetLength());//Socket Step04

					char szRecv[20];
					m_socket01.Receive(szRecv, 20);//Socket Step04
					m_StrNowTime = timeNow.Format("%Y/%m/%d %H:%M:%S") + "\n" + SendData + "\n" + szRecv;
					break;
				}
				fclose(pf);
				::DeleteFile(StrFileName.GetBuffer());
				::Sleep(1000);
			}	
		}
		m_socket01.Close();//Socket Step05
	}
	UpdateData(false);

	SetTimer(1, 3000, NULL);//開啟Timer
	CDialogEx::OnTimer(nIDEvent);
}
