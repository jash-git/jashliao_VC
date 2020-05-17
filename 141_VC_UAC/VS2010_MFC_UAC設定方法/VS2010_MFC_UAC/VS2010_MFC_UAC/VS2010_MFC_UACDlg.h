
// VS2010_MFC_UACDlg.h : 標頭檔
//

#pragma once


// CVS2010_MFC_UACDlg 對話方塊
class CVS2010_MFC_UACDlg : public CDialogEx
{
// 建構
public:
	CVS2010_MFC_UACDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_VS2010_MFC_UAC_DIALOG };

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
};
