#if !defined(AFX_GL1_H__9988E224_6BF7_465D_A6F8_773F926CA996__INCLUDED_)
#define AFX_GL1_H__9988E224_6BF7_465D_A6F8_773F926CA996__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// gl1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// gl dialog

class gl : public CDialog
{
// Construction
public:
	gl(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(gl)
	enum { IDD = IDD_DIALOG1 };
	float	m_waist_x;
	float	m_waist_y;
	float	m_waist_z;
	float	m_left1;
	float	m_left2;
	float	m_left3;
	float	m_right1;
	float	m_right2;
	float	m_right3;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(gl)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(gl)
	afx_msg void waist_x();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GL1_H__9988E224_6BF7_465D_A6F8_773F926CA996__INCLUDED_)
