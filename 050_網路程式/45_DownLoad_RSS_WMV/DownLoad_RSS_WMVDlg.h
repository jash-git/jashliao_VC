// DownLoad_RSS_WMVDlg.h : header file
//

#if !defined(AFX_DOWNLOAD_RSS_WMVDLG_H__72BEC66C_B899_4C9E_A624_68958EC76476__INCLUDED_)
#define AFX_DOWNLOAD_RSS_WMVDLG_H__72BEC66C_B899_4C9E_A624_68958EC76476__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDownLoad_RSS_WMVDlg dialog

class CDownLoad_RSS_WMVDlg : public CDialog
{
// Construction
public:
	CDownLoad_RSS_WMVDlg(CWnd* pParent = NULL);	// standard constructor
	bool GetWebFile(CString theUrl, CString Filename);//step 02_DownLoad Http File
	void ReadRSSXML(CString Filename);
// Dialog Data
	//{{AFX_DATA(CDownLoad_RSS_WMVDlg)
	enum { IDD = IDD_DOWNLOAD_RSS_WMV_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDownLoad_RSS_WMVDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDownLoad_RSS_WMVDlg)
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

#endif // !defined(AFX_DOWNLOAD_RSS_WMVDLG_H__72BEC66C_B899_4C9E_A624_68958EC76476__INCLUDED_)
