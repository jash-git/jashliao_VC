#if !defined(AFX_SHOWGPSDATA_H__08BA8B7F_0566_457E_AA41_99DD9CB1B251__INCLUDED_)
#define AFX_SHOWGPSDATA_H__08BA8B7F_0566_457E_AA41_99DD9CB1B251__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowGPSData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowGPSData dialog

class CShowGPSData : public CDialogBar
{
// Construction
public:
	CShowGPSData(CWnd* pParent = NULL);   // standard constructor
	void show(void);
	void showdata(long a,long b,double c,CString &strlength);
	void showdata(long a1,long b1);
// Dialog Data
	//{{AFX_DATA(CShowGPSData)
	enum { IDD = IDD_DIALOGBAR };
	long	m_X;
	double	m_Rate;
	long	m_Y;
	CString	m_length;
	long	m_v1;
	long	m_v2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowGPSData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowGPSData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWGPSDATA_H__08BA8B7F_0566_457E_AA41_99DD9CB1B251__INCLUDED_)
