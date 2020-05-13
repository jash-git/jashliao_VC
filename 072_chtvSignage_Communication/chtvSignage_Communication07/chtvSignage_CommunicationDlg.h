// chtvSignage_CommunicationDlg.h : header file
//

#if !defined(AFX_CHTVSIGNAGE_COMMUNICATIONDLG_H__D9635E59_3484_4A50_BC38_1FCDB4B3FB3A__INCLUDED_)
#define AFX_CHTVSIGNAGE_COMMUNICATIONDLG_H__D9635E59_3484_4A50_BC38_1FCDB4B3FB3A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChtvSignage_CommunicationDlg dialog

class CChtvSignage_CommunicationDlg : public CDialog
{
// Construction
public:
	CChtvSignage_CommunicationDlg(CWnd* pParent = NULL);	// standard constructor
	//////////////////////////////////////////////////////
	void InitialVariable();//讀取XML設定檔並初始化相對映成員變數
	void CreateNetDir();//呼叫BAT建立網路信任
	bool DownLoadXML();//下載播放清單和跑馬資料
	void ReadXmlPlayList();//讀取Xml內PlayList資料
	bool SearchFile(CString strDir,CString strFile);//搜尋檔案
	void ListingDownLoadFile();//產生實際要下載清單
	void DownLoadMovieFile();//下載影片檔
	void UpLoadLogFile();//上傳LOG檔
	//////////////////////////////////////////////////////
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CArray <CString,CString&> m_ArrPlayListData;//存放播放清單的所有檔名
	CArray <CString,CString&> m_ArrDownLoadFileData;//存放要下載檔名
	CString m_StrGet_Data;//目前沒用到->多久抓一次資料
	CString m_StrRunText_XML;//存放下跑碼檔案路徑
	CString m_StrCheckPlayList_XML;//存放確認比對影片播放清單路徑
	CString m_StrPlayList_XML;//存放影片播放清單路徑
	CString m_StrMovie_path;//存放影片存放路徑
	CString m_StrCreateNet_Bat;//存放BAT檔路徑
	CString m_StrDownLoad_Path;//存放XML下載路徑
	CString m_StrUpLoad_Path;//存放XML上傳路徑
	CString m_StrUpLoad_FilePath;//存放上傳完整檔案路徑
	CString m_StrMAC;//存放機器本身MAC
// Dialog Data
	//{{AFX_DATA(CChtvSignage_CommunicationDlg)
	enum { IDD = IDD_CHTVSIGNAGE_COMMUNICATION_DIALOG };
	CString	m_Edit1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChtvSignage_CommunicationDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChtvSignage_CommunicationDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHTVSIGNAGE_COMMUNICATIONDLG_H__D9635E59_3484_4A50_BC38_1FCDB4B3FB3A__INCLUDED_)
