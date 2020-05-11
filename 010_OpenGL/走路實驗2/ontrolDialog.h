#if !defined(AFX_ONTROLDIALOG_H__AAF6E30B_96F7_42EC_8EA1_B5587BA1E69C__INCLUDED_)
#define AFX_ONTROLDIALOG_H__AAF6E30B_96F7_42EC_8EA1_B5587BA1E69C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ontrolDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// ControlDialog dialog

class ControlDialog : public CDialog
{
// Construction
public:
	ControlDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ControlDialog)
	enum { IDD = IDD_DIALOG1 };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ControlDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ControlDialog)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONTROLDIALOG_H__AAF6E30B_96F7_42EC_8EA1_B5587BA1E69C__INCLUDED_)
