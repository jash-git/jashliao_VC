// MySOLODBCView.h : interface of the CMySOLODBCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSOLODBCVIEW_H__A7EA40F2_F4F6_4882_A3AD_C7293B7F0BB5__INCLUDED_)
#define AFX_MYSOLODBCVIEW_H__A7EA40F2_F4F6_4882_A3AD_C7293B7F0BB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMySOLODBCSet;

class CMySOLODBCView : public CRecordView
{
protected: // create from serialization only
	CMySOLODBCView();
	DECLARE_DYNCREATE(CMySOLODBCView)

public:
	//{{AFX_DATA(CMySOLODBCView)
	enum{ IDD = IDD_MYSOLODBC_FORM };
	CMySOLODBCSet* m_pSet;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CMySOLODBCDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySOLODBCView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMySOLODBCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMySOLODBCView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MySOLODBCView.cpp
inline CMySOLODBCDoc* CMySOLODBCView::GetDocument()
   { return (CMySOLODBCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOLODBCVIEW_H__A7EA40F2_F4F6_4882_A3AD_C7293B7F0BB5__INCLUDED_)
