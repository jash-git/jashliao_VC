// NoRegularDlg.h : header file
//

#if !defined(AFX_NOREGULARDLG_H__3C297A91_AC9F_46F2_AF44_A33803203760__INCLUDED_)
#define AFX_NOREGULARDLG_H__3C297A91_AC9F_46F2_AF44_A33803203760__INCLUDED_

#define	GLOBAL_OVERLEN		20
#define	GLOBAL_OVERWIDTH	15

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNoRegularDlg dialog

class CNoRegularDlg : public CDialog
{
// Construction
public:
	CNoRegularDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CNoRegularDlg)
	enum { IDD = IDD_NOREGULAR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoRegularDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HRGN hRgn;

	// Generated message map functions
	//{{AFX_MSG(CNoRegularDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOREGULARDLG_H__3C297A91_AC9F_46F2_AF44_A33803203760__INCLUDED_)
