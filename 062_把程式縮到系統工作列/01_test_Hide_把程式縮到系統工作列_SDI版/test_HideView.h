// test_HideView.h : interface of the CTest_HideView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST_HIDEVIEW_H__40C6FA6D_DDD3_4A38_B557_5161049275D3__INCLUDED_)
#define AFX_TEST_HIDEVIEW_H__40C6FA6D_DDD3_4A38_B557_5161049275D3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest_HideView : public CFormView
{
protected: // create from serialization only
	CTest_HideView();
	DECLARE_DYNCREATE(CTest_HideView)

public:
	//{{AFX_DATA(CTest_HideView)
	enum{ IDD = IDD_TEST_HIDE_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CTest_HideDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_HideView)
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
	virtual ~CTest_HideView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest_HideView)
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in test_HideView.cpp
inline CTest_HideDoc* CTest_HideView::GetDocument()
   { return (CTest_HideDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_HIDEVIEW_H__40C6FA6D_DDD3_4A38_B557_5161049275D3__INCLUDED_)
