#if !defined(AFX_SETCOORDINATE_H__2F485A03_0784_4E70_A9B4_1A63D0D0559F__INCLUDED_)
#define AFX_SETCOORDINATE_H__2F485A03_0784_4E70_A9B4_1A63D0D0559F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetCoordinate.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// SetCoordinate dialog

class SetCoordinate : public CDialog
{
// Construction
public:
	SetCoordinate(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(SetCoordinate)
	enum { IDD = IDD_DIALOG2 };
	int		m_set;
	int		m_x;
	int		m_y;
	int		m_z;
	int		m_x1;
	int		m_y1;
	int		m_z1;
	int		m_x2;
	int		m_y2;
	int		m_z2;
	int		m_set1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(SetCoordinate)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(SetCoordinate)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCOORDINATE_H__2F485A03_0784_4E70_A9B4_1A63D0D0559F__INCLUDED_)
