
// SearchFile2SQLiteDlg.h : 標頭檔
//

#pragma once


// CSearchFile2SQLiteDlg 對話方塊
class CSearchFile2SQLiteDlg : public CDialog
{
// 建構
public:
	CSearchFile2SQLiteDlg(CWnd* pParent = NULL);	// 標準建構函式
	void GetandSetParameter();//step 3:讀取XML
	CString m_StrDir;
	CString m_StrSearch;
	void BrowseDir(CString strDir);
	void SQLiteCreate();
	void SQLiteInsert(CString StrData);
	void SQLite2File();
	void RunSearch();
	static UINT ThreadRun(LPVOID lpram);
// 對話方塊資料
	enum { IDD = IDD_SEARCHFILE2SQLITE_DIALOG };

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
	afx_msg void OnBnClickedButsearch();
};
