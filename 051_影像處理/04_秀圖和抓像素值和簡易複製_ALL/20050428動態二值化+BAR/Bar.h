#if !defined(AFX_BAR_H__7BD72BE4_ED8F_4F14_8345_64FD10BF8343__INCLUDED_)
#define AFX_BAR_H__7BD72BE4_ED8F_4F14_8345_64FD10BF8343__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Bar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBar dialog

class CBar : public CDialogBar
{
// Construction
public:
	CBar(CWnd* pParent = NULL);   // standard constructor
	void show();
// Dialog Data
	//{{AFX_DATA(CBar)
	enum { IDD = IDD_DIALOGBAR };
	CSliderCtrl	m_slider;
	int		m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBar)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBar)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL OnInitDialog();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAR_H__7BD72BE4_ED8F_4F14_8345_64FD10BF8343__INCLUDED_)
