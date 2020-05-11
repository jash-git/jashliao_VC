#if !defined(AFX_DLG1_H__B9F0E1B7_69F0_4B9D_9E89_48A7FDF680C6__INCLUDED_)
#define AFX_DLG1_H__B9F0E1B7_69F0_4B9D_9E89_48A7FDF680C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlg1 dialog

class CDlg1 : public CDialog
{
// Construction
public:
	CDlg1(CWnd* pParent = NULL);   // standard constructor
	CPropertySheet *sheet;
	double m_v1,m_v2;
	void show();
// Dialog Data
	//{{AFX_DATA(CDlg1)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg1)
	public:
	virtual int DoModal();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg1)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG1_H__B9F0E1B7_69F0_4B9D_9E89_48A7FDF680C6__INCLUDED_)
