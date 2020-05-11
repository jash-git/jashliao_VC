#if !defined(AFX_DIA_H__1D3928E8_6E0A_42F1_9473_2C1B147C99CF__INCLUDED_)
#define AFX_DIA_H__1D3928E8_6E0A_42F1_9473_2C1B147C99CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dia.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDia dialog

class CDia : public CDialog
{
// Construction
public:
	CDia(CWnd* pParent = NULL);   // standard constructor
	void show(void);
// Dialog Data
	//{{AFX_DATA(CDia)
	enum { IDD = IDD_DIALOG1 };
	int		m_v1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDia)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDia)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIA_H__1D3928E8_6E0A_42F1_9473_2C1B147C99CF__INCLUDED_)
