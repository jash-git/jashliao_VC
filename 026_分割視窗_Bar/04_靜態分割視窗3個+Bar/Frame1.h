#if !defined(AFX_FRAME1_H__99578C03_7468_4F0D_850A_F37AB15EBF2F__INCLUDED_)
#define AFX_FRAME1_H__99578C03_7468_4F0D_850A_F37AB15EBF2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Frame1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFrame1 frame

class CFrame1 : public CFrameWnd
{
	DECLARE_DYNCREATE(CFrame1)
protected:
	CFrame1();           // protected constructor used by dynamic creation

// Attributes
public:
CSplitterWnd StaticSplit;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrame1)
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFrame1();

	// Generated message map functions
	//{{AFX_MSG(CFrame1)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAME1_H__99578C03_7468_4F0D_850A_F37AB15EBF2F__INCLUDED_)
