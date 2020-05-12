// Image1Doc.h : interface of the CImage1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGE1DOC_H__A5AA2297_DF8F_49A2_A9DD_FFEF75A36DD8__INCLUDED_)
#define AFX_IMAGE1DOC_H__A5AA2297_DF8F_49A2_A9DD_FFEF75A36DD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CImage1Doc : public CDocument
{
protected: // create from serialization only
	CImage1Doc();
	DECLARE_DYNCREATE(CImage1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImage1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImage1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CImage1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGE1DOC_H__A5AA2297_DF8F_49A2_A9DD_FFEF75A36DD8__INCLUDED_)
