#if !defined(AFX_YEDLG_H__CD4A8CFB_3010_43E6_B39F_0B604705412E__INCLUDED_)
#define AFX_YEDLG_H__CD4A8CFB_3010_43E6_B39F_0B604705412E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// yedlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Cyedlg dialog

class Cyedlg : public CDialog
{
// Construction
public:
	bool k;

	bool start;
	bool l;
	int big;
	int counter;
	int width;
	Cyedlg(CWnd* pParent = NULL);   // standard constructor
int x,y;
// Dialog Data
	//{{AFX_DATA(Cyedlg)
	enum { IDD = IDD_ye };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cyedlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cyedlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg UINT OnNcHitTest(CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_YEDLG_H__CD4A8CFB_3010_43E6_B39F_0B604705412E__INCLUDED_)
