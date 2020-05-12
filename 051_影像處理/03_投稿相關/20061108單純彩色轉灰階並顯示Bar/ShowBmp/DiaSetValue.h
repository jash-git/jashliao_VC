#if !defined(AFX_DIASETVALUE_H__B537C4CD_89EE_4FFC_A6FB_D0A3E573B076__INCLUDED_)
#define AFX_DIASETVALUE_H__B537C4CD_89EE_4FFC_A6FB_D0A3E573B076__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DiaSetValue.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDiaSetValue dialog

class CDiaSetValue : public CDialogBar
{
// Construction
public:
	CDiaSetValue(CWnd* pParent = NULL);   // standard constructor
	void show();
// Dialog Data
	//{{AFX_DATA(CDiaSetValue)
	enum { IDD = IDD_DIALOGBAR };
	CSliderCtrl	m_slider;
	long	m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDiaSetValue)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDiaSetValue)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIASETVALUE_H__B537C4CD_89EE_4FFC_A6FB_D0A3E573B076__INCLUDED_)
