
// Win7_VolumeDlg.h : 標頭檔
//

#pragma once


// CWin7_VolumeDlg 對話方塊
class CWin7_VolumeDlg : public CDialog
{
// 建構
public:
	CWin7_VolumeDlg(CWnd* pParent = NULL);	// 標準建構函式
	bool ChangeVolume(double nVolume,bool bScalar);
// 對話方塊資料
	enum { IDD = IDD_WIN7_VOLUME_DIALOG };

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
