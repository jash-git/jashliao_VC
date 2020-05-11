#if !defined(AFX_VIEWBAR_H__1C3C22CC_F922_4F41_A651_8698E9434B0F__INCLUDED_)
#define AFX_VIEWBAR_H__1C3C22CC_F922_4F41_A651_8698E9434B0F__INCLUDED_

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
	void show();
	void showdata(float x,float y,float z,float r1,float r2, float Pxr3, float Pyr3, float Pzr3, float Theta);
// Dialog Data
	//{{AFX_DATA(viewbar)
	enum { IDD = IDD_DIALOGBAR };
	float	m_X;
	float	m_Y;
	float	m_Z;
	float	m_R1;
	float	m_R2;
	float	m_Pxr3;
	float	m_Pyr3;
	float	m_Pzr3;
	float	m_Theta;
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

#endif // !defined(AFX_VIEWBAR_H__1C3C22CC_F922_4F41_A651_8698E9434B0F__INCLUDED_)
