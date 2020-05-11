// Show2Dlg.h : header file
//

#if !defined(AFX_SHOW2DLG_H__5B1D8593_45A5_466F_92CF_180C9347661A__INCLUDED_)
#define AFX_SHOW2DLG_H__5B1D8593_45A5_466F_92CF_180C9347661A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShow2Dlg dialog

class CShow2Dlg : public CDialog
{
// Construction
public:
	CShow2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShow2Dlg)
	enum { IDD = IDD_SHOW2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShow2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShow2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOW2DLG_H__5B1D8593_45A5_466F_92CF_180C9347661A__INCLUDED_)
