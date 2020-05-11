
// test_VS2008_MFC_NETDlg.h : 標頭檔
//

#pragma once


// Ctest_VS2008_MFC_NETDlg 對話方塊
class Ctest_VS2008_MFC_NETDlg : public CDialog
{
// 建構
public:
	Ctest_VS2008_MFC_NETDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_TEST_VS2008_MFC_NET_DIALOG };

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
	afx_msg void OnBnClickedButton1();
};
