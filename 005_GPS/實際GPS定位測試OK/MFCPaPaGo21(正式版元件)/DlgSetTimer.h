#if !defined(AFX_DLGSETTIMER_H__C0C65944_E162_4AC6_84AA_586D230D553C__INCLUDED_)
#define AFX_DLGSETTIMER_H__C0C65944_E162_4AC6_84AA_586D230D553C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSetTimer.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSetTimer dialog

class CDlgSetTimer : public CDialog
{
// Construction
public:
	CDlgSetTimer(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgSetTimer)
	enum { IDD = IDD_DIALOG1 };
	float	m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSetTimer)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSetTimer)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSETTIMER_H__C0C65944_E162_4AC6_84AA_586D230D553C__INCLUDED_)
