// testRectDoc.h : interface of the CTestRectDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTRECTDOC_H__7D320C40_3FFD_47E0_B3F7_6901459C7DE4__INCLUDED_)
#define AFX_TESTRECTDOC_H__7D320C40_3FFD_47E0_B3F7_6901459C7DE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestRectDoc : public CDocument
{
protected: // create from serialization only
	CTestRectDoc();
	DECLARE_DYNCREATE(CTestRectDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestRectDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestRectDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestRectDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTRECTDOC_H__7D320C40_3FFD_47E0_B3F7_6901459C7DE4__INCLUDED_)
