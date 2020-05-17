
// SMS_TCP_ClientDlg.h : 標頭檔
//

#pragma once


// CSMS_TCP_ClientDlg 對話方塊
class CSMS_TCP_ClientDlg : public CDialogEx
{
// 建構
public:
	CSMS_TCP_ClientDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SMS_TCP_CLIENT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_StrNowTime;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
