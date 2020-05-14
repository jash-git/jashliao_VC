
// DaAiNewsDownloadDlg.h : 標頭檔
//

#pragma once


// CDaAiNewsDownloadDlg 對話方塊
class CDaAiNewsDownloadDlg : public CDialog
{
// 建構
public:
	CDaAiNewsDownloadDlg(CWnd* pParent = NULL);	// 標準建構函式
	CString NowNewsHttpPost(CString StrPostData);
	CString GetFileName(CString Strdata);
	void ReadFileDownLoadXML();
	void DownLoadWMVFile();
	bool GetWebFile(CString theUrl, CString Filename);//Step 2:Http
	CArray <CString,CString&> m_Array0;//CArray Step_02
	CArray <CString,CString&> m_Array1;//CArray Step_02
	CArray <CString,CString&> m_Array2;//CArray Step_02
	int m_intHttpNumber;
// 對話方塊資料
	enum { IDD = IDD_DAAINEWSDOWNLOAD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
