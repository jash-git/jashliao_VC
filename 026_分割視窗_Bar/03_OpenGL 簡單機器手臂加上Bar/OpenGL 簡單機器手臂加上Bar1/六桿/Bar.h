#if !defined(AFX_BAR_H__E32FB23D_4810_4A62_B6EA_CAD5642B1C15__INCLUDED_)
#define AFX_BAR_H__E32FB23D_4810_4A62_B6EA_CAD5642B1C15__INCLUDED_

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
// Dialog Data
	//{{AFX_DATA(CBar)
	enum { IDD = IDD_DIALOGBAR };
	CString	m_str1;
	CString	m_str2;
	CString	m_str3;
	CString	m_str4;
	CString	m_str5;
	CString	m_str6;
	float	m_v1;
	float	m_v2;
	float	m_v3;
	float	m_v4;
	float	m_v5;
	float	m_v6;
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

#endif // !defined(AFX_BAR_H__E32FB23D_4810_4A62_B6EA_CAD5642B1C15__INCLUDED_)
