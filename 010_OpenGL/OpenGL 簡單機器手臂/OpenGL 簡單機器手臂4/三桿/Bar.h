#if !defined(AFX_BAR_H__39C29208_D4C1_4096_A0A0_C2AB62184F52__INCLUDED_)
#define AFX_BAR_H__39C29208_D4C1_4096_A0A0_C2AB62184F52__INCLUDED_

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
	void show(void);
	void GetData(float *data);
	void SentData(int index,float data);
// Dialog Data
	//{{AFX_DATA(CBar)
	enum { IDD = IDD_DIALOGBAR };
	CButton	m_Down3;
	CButton	m_Down2;
	CButton	m_Down1;
	CButton	m_UP3;
	CButton	m_UP2;
	CButton	m_UP1;
	CString	m_str1;
	CString	m_str2;
	CString	m_str3;
	float	m_v1;
	float	m_v2;
	float	m_v3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBar)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BAR_H__39C29208_D4C1_4096_A0A0_C2AB62184F52__INCLUDED_)
