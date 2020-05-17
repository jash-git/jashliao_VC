
// MFC_UAC_Execution_LevelDlg.h : 標頭檔
//

#pragma once


// CMFC_UAC_Execution_LevelDlg 對話方塊
class CMFC_UAC_Execution_LevelDlg : public CDialog
{
// 建構
public:
	CMFC_UAC_Execution_LevelDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_MFC_UAC_EXECUTION_LEVEL_DIALOG };

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
