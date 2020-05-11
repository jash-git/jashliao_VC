// ShowHospitalDlg.h : header file
//

#if !defined(AFX_SHOWHOSPITALDLG_H__B4BAB42B_683C_4A6B_BDCA_5EB51BAE0D0B__INCLUDED_)
#define AFX_SHOWHOSPITALDLG_H__B4BAB42B_683C_4A6B_BDCA_5EB51BAE0D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowHospitalDlg dialog

class CShowHospitalDlg : public CDialog
{
// Construction
public:
	CShowHospitalDlg(CWnd* pParent = NULL);	// standard constructor
////////////////////////////////////////////////////////////////////
//Jash.Liao add member function
	void InitialVariable(void);//讀取XML設定檔並初始化相對映成員變數
	void SetindowPositionSize(void);//呼叫視窗裁剪(切)
////////////////////////////////////////////////////////////////////
//Jash.Liao add member variable
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CString m_StrSettingFileName;//存放設定檔實際路徑
	long m_lngTop,m_lngLeft,m_lngWidth,m_lngHeight;//設定視窗大小位置變數
	CRgn m_rgn;//裁減(切)視窗相關物件
////////////////////////////////////////////////////////////////////
// Dialog Data
	//{{AFX_DATA(CShowHospitalDlg)
	enum { IDD = IDD_SHOWHOSPITAL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowHospitalDlg)
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
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWHOSPITALDLG_H__B4BAB42B_683C_4A6B_BDCA_5EB51BAE0D0B__INCLUDED_)
