// STBMMSConnectDlg.h : 標頭檔
//

#pragma once
#include "afxwin.h"


// CSTBMMSConnectDlg 對話方塊
class CSTBMMSConnectDlg : public CDialog
{
// 建構
public:
	CSTBMMSConnectDlg(CWnd* pParent = NULL);	// 標準建構函式
	CArray <CString,CString&> m_ArrayARPIP;//CArray Step_02
	CArray <CString,CString&> m_ArrayCheckIP;//CArray Step_02
	CArray <CString,CString&> m_ArrayMessageIP;//CArray Step_02
	void GetARPTable();
	void InitVariable();
	void ShowARPIP();
	void GetIPList();
	void ShowCheckIP();
	void CompareIP();
	void ShowMSGIP();
	void SendMSG();
	bool ConnectSTB(CString StrIP);
// 對話方塊資料
	enum { IDD = IDD_STBMMSCONNECT_DIALOG };

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
	CListBox ARPListBox;
	CListBox STBListBox;
	afx_msg void OnBnClickedButtrun();
	CListBox MSGListBox;
	afx_msg void OnBnClickedButtshowmms();
	afx_msg void OnBnClickedButtshowstb();
	long m_V1;
	CString m_V2;
	CString m_V3;
};
