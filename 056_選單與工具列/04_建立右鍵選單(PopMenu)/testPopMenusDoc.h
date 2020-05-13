// testPopMenusDoc.h : interface of the CTestPopMenusDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTPOPMENUSDOC_H__3E5830D8_22B8_47A0_B271_5662CB646D57__INCLUDED_)
#define AFX_TESTPOPMENUSDOC_H__3E5830D8_22B8_47A0_B271_5662CB646D57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestPopMenusDoc : public CDocument
{
protected: // create from serialization only
	CTestPopMenusDoc();
	DECLARE_DYNCREATE(CTestPopMenusDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestPopMenusDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestPopMenusDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestPopMenusDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPOPMENUSDOC_H__3E5830D8_22B8_47A0_B271_5662CB646D57__INCLUDED_)
