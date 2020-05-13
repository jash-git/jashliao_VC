// GetNowNewsAVDlg.h : header file
//

#if !defined(AFX_GETNOWNEWSAVDLG_H__B723F447_2053_40F3_A005_E071457117BD__INCLUDED_)
#define AFX_GETNOWNEWSAVDLG_H__B723F447_2053_40F3_A005_E071457117BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CGetNowNewsAVDlgAutoProxy;

/////////////////////////////////////////////////////////////////////////////
// CGetNowNewsAVDlg dialog

class CGetNowNewsAVDlg : public CDialog
{
	DECLARE_DYNAMIC(CGetNowNewsAVDlg);
	friend class CGetNowNewsAVDlgAutoProxy;

// Construction
public:
	CGetNowNewsAVDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CGetNowNewsAVDlg();
	bool GetWebFile(CString theUrl, CString Filename);//Step 2:Http
// Dialog Data
	//{{AFX_DATA(CGetNowNewsAVDlg)
	enum { IDD = IDD_GETNOWNEWSAV_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetNowNewsAVDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CGetNowNewsAVDlgAutoProxy* m_pAutoProxy;
	HICON m_hIcon;

	BOOL CanExit();

	// Generated message map functions
	//{{AFX_MSG(CGetNowNewsAVDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETNOWNEWSAVDLG_H__B723F447_2053_40F3_A005_E071457117BD__INCLUDED_)
