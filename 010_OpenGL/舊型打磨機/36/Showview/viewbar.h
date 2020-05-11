#if !defined(AFX_VIEWBAR_H__1C64AB00_3563_4319_A3FD_1BE0C1F9473E__INCLUDED_)
#define AFX_VIEWBAR_H__1C64AB00_3563_4319_A3FD_1BE0C1F9473E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// viewbar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// viewbar dialog

class viewbar : public CDialogBar
{
// Construction
public:
	viewbar(CWnd* pParent = NULL);   // standard constructor
	void Show(void);
	void SetValue(double pid[9], double theta);
	void map_value(double x,double y,double z,double n);
// Dialog Data
	//{{AFX_DATA(viewbar)
	enum { IDD = IDD_DIALOGBAR };
	double	m_Kdc;
	double	m_Kdx;
	double	m_Kdy;
	double	m_Kic;
	double	m_Kix;
	double	m_Kiy;
	double	m_Kpc;
	double	m_Kpx;
	double	m_Kpy;
	double	m_Slope;
	double	m_LifeX;
	double	m_LifeY;
	double	m_LifeZ;
	double	m_WorkN;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(viewbar)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(viewbar)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWBAR_H__1C64AB00_3563_4319_A3FD_1BE0C1F9473E__INCLUDED_)
