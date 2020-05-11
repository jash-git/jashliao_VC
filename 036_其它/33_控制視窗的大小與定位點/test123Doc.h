// test123Doc.h : interface of the CTest123Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST123DOC_H__73C94858_BBA8_4B86_BBFA_CA9FF7FF4B29__INCLUDED_)
#define AFX_TEST123DOC_H__73C94858_BBA8_4B86_BBFA_CA9FF7FF4B29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest123Doc : public CDocument
{
protected: // create from serialization only
	CTest123Doc();
	DECLARE_DYNCREATE(CTest123Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest123Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest123Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest123Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST123DOC_H__73C94858_BBA8_4B86_BBFA_CA9FF7FF4B29__INCLUDED_)
