#if !defined(AFX_BAR_H__E78EC0B9_2E1C_4765_A903_40F85C337B45__INCLUDED_)
#define AFX_BAR_H__E78EC0B9_2E1C_4765_A903_40F85C337B45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// bar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// bar dialog

class bar : public CDialogBar
{
// Construction
public:
	bar(CWnd* pParent = NULL);   // standard constructor
	void show(void);
	void showdata(int a,int b);
// Dialog Data
	//{{AFX_DATA(bar)
	enum { IDD = IDD_DIALOGBAR };
	int		m_v1;
	int		m_v2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(bar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(bar)

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAR_H__E78EC0B9_2E1C_4765_A903_40F85C337B45__INCLUDED_)
