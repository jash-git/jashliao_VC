
// MFC_get_versionDlg.h : 標頭檔
//

#pragma once


// CMFC_get_versionDlg 對話方塊
class CMFC_get_versionDlg : public CDialogEx
{
// 建構
public:
	CMFC_get_versionDlg(CWnd* pParent = NULL);	// 標準建構函式
	

// 對話方塊資料
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_GET_VERSION_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援

public:
	CString getAppVersion();
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
