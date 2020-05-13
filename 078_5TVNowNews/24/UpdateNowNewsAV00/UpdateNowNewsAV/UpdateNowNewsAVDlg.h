
// UpdateNowNewsAVDlg.h : 標頭檔
//

#pragma once


// CUpdateNowNewsAVDlg 對話方塊
class CUpdateNowNewsAVDlg : public CDialog
{
// 建構
public:
	CUpdateNowNewsAVDlg(CWnd* pParent = NULL);	// 標準建構函式
	CString NowNewsHttpPost(CString StrPostData);
	CArray <CString,CString&> m_Array1;//CArray Step_02
	CArray <CString,CString&> m_Array2;//CArray Step_02
	BYTE toHex(const BYTE &x);
	CString URLEncode(CString sIn);
	DWORD GetFileSize(CString filepath);
// 對話方塊資料
	enum { IDD = IDD_UPDATENOWNEWSAV_DIALOG };

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
