// framviewView.h : interface of the CFramviewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMVIEWVIEW_H__6821CE2F_7E8B_463E_9BB5_046563075DA8__INCLUDED_)
#define AFX_FRAMVIEWVIEW_H__6821CE2F_7E8B_463E_9BB5_046563075DA8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFramviewView : public CFormView
{
protected: // create from serialization only
	CFramviewView();
	DECLARE_DYNCREATE(CFramviewView)

public:
	//{{AFX_DATA(CFramviewView)
	enum { IDD = IDD_FRAMVIEW_FORM };
	float	m_v1;
	float	m_v2;
	double	m_v3;
	//}}AFX_DATA

// Attributes
public:
	CFramviewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFramviewView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFramviewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFramviewView)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in framviewView.cpp
inline CFramviewDoc* CFramviewView::GetDocument()
   { return (CFramviewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMVIEWVIEW_H__6821CE2F_7E8B_463E_9BB5_046563075DA8__INCLUDED_)
