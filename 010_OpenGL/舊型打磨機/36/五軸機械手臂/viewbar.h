#if !defined(AFX_VIEWBAR_H__4A680B20_43AF_11D8_A2FB_0050BA006823__INCLUDED_)
#define AFX_VIEWBAR_H__4A680B20_43AF_11D8_A2FB_0050BA006823__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// viewbar.h : header file

/////////////////////////////////////////////////////////////////////////////
// viewbar dialog

class viewbar : public CDialogBar
{
// Construction
public:
//	viewbar(CWnd* pParent = NULL);   // standard constructor
void Show(void);

// Dialog Data
	//{{AFX_DATA(viewbar)
	enum { IDD = IDD_DIALOGBAR };
	int		m_setvalue;
	int		m_trackingvalue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(viewbar)
	public:
	/*virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);*/
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(viewbar)
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWBAR_H__4A680B20_43AF_11D8_A2FB_0050BA006823__INCLUDED_)
