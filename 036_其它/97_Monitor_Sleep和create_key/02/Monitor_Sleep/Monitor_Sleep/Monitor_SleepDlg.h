
// Monitor_SleepDlg.h : 標頭檔
//

#pragma once
#include "afxwin.h"


// CMonitor_SleepDlg 對話方塊
class CMonitor_SleepDlg : public CDialogEx
{
// 建構
public:
	CMonitor_SleepDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_MONITOR_SLEEP_DIALOG };

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
	CString m_StrSetTime;
	CString m_StrPassword;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg LRESULT onShowTask(WPARAM wParam,LPARAM lParam); //Step 4
	afx_msg void OnBnClickedButton2();
	CButton m_b1;
	CButton m_b2;
};
