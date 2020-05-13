// ShowHospitalDlg.h : header file
//

#if !defined(AFX_SHOWHOSPITALDLG_H__B4BAB42B_683C_4A6B_BDCA_5EB51BAE0D0B__INCLUDED_)
#define AFX_SHOWHOSPITALDLG_H__B4BAB42B_683C_4A6B_BDCA_5EB51BAE0D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowHospitalDlg dialog
struct Reset_Time
{
	long lngHours;
	long lngMinute;
	long lngShowImageTime;//秀圖時間
};
class CShowHospitalDlg : public CDialog
{
// Construction
public:
	CShowHospitalDlg(CWnd* pParent = NULL);	// standard constructor
////////////////////////////////////////////////////////////////////
//Jash.Liao add member function
	void InitialVariable(void);//讀取XML設定檔並初始化相對映成員變數
	void SetWindowPositionSize(void);//呼叫視窗裁剪(切)
	void GetPlayData(void);//抓取播放值ALL
	void NetGetData(void);//抓取網路資料
	void ShowData(void);//顯示播放資料
	void ChangeShowData(void);//改變顯示資料
	void ClearMessageData(void);//清空顯示資料
	CString NormalData(CString StrSource);//正規劃資料
	void BrowseDir(CString strDir,CString strtype);//Step 2:列出檔案清單
////////////////////////////////////////////////////////////////////
//Jash.Liao add member variable
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CString m_StrSettingFileName;//存放設定檔實際路徑
	long m_lngTop,m_lngLeft,m_lngWidth,m_lngHeight;//設定視窗大小位置變數
	long m_lngImageTop,m_lngImageLeft,m_lngImageWidth,m_lngImageHeight;//設定視窗大小位置變數
	CRgn m_rgn;//裁減(切)視窗相關物件
	long m_lngResetTimeCount;//Reset Time 的數量
	struct Reset_Time *m_RT;//Reset Time 的結構體
	bool m_blnRest_Flag;
	long m_lngGet_Data;//抓取資料時間
	long m_lngChange_Page;//頁面切換時間
	long m_lngData_Count;//XML定義的資料比數
	CString m_StrPlayDataFileName;
	CArray <CString,CString&> m_ArrPlayData;
	CString m_StrShowDataBuff[11];//儲存要顯示資料
	long m_lngPageVariable;//頁面控制變數
	long m_lngArryDataCount;//實際資料比數
	bool m_bnlInitialPage;//頁數判斷旗標
	long m_lngTimerCount;//因為TIMER為10秒，因此要有一個Count來輔助
	CString m_StrNetPath;
	bool m_blnArrayed_Data;//資料就緒旗標
	CString m_StrNormalData;//正規劃資料
	bool m_blnAttributes;//透明度
	long m_lngShowImageTime;//秀圖時間
	long m_lngChangeImage;//秀圖中圖與圖的切換時間
	CArray <CString,CString&> m_Array;//Step 2:CArray
////////////////////////////////////////////////////////////////////
// Dialog Data
	//{{AFX_DATA(CShowHospitalDlg)
	enum { IDD = IDD_SHOWHOSPITAL_DIALOG };
	CString	m_ShowData00;
	CString	m_ShowData01;
	CString	m_ShowData02;
	CString	m_ShowData03;
	CString	m_ShowData04;
	CString	m_ShowData05;
	CString	m_ShowData06;
	CString	m_ShowData07;
	CString	m_ShowData08;
	CString	m_ShowData09;
	CString	m_ShowData10;
	CString	m_ShowData11;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowHospitalDlg)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShowHospitalDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWHOSPITALDLG_H__B4BAB42B_683C_4A6B_BDCA_5EB51BAE0D0B__INCLUDED_)
