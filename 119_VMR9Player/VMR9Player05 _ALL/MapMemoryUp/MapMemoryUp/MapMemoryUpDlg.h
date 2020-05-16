// MapMemoryUpDlg.h : 標頭檔
//

#pragma once


// CMapMemoryUpDlg 對話方塊
class CMapMemoryUpDlg : public CDialog
{
// 建構
public:
	CMapMemoryUpDlg(CWnd* pParent = NULL);	// 標準建構函式
	void CallPlayer();//CreateProcess step02
	bool ReadXMLConfig();
	void EmailError(CString StrWriteMessage);
	void WriteLogFile(int intindex,CString StrMessage);
	bool CreateDefaultList();
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	bool XMLList2TXTList();//step 3:讀取XML
	///////////////////////////////////////////////
	//CArray Step_02
	CArray <CString,CString&> m_ArraySource;
	void InitList2CArray();
	void List2CArray();
	int m_intArrayCount;
	int m_intArrayIndex;
	///////////////////////////////////////////////
	CString GetMediaLen(CString StrSouFileName);
	bool DownLoadList();
// 對話方塊資料
	enum { IDD = IDD_MAPMEMORYUP_DIALOG };

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
	CString m_V1;
	afx_msg void OnDestroy();
};
