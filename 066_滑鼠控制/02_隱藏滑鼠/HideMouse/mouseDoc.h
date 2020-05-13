// mouseDoc.h : interface of the CMouseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOUSEDOC_H__D826C73C_2B8B_4C16_BEC6_D09F8DD02684__INCLUDED_)
#define AFX_MOUSEDOC_H__D826C73C_2B8B_4C16_BEC6_D09F8DD02684__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMouseDoc : public CDocument
{
protected: // create from serialization only
	CMouseDoc();
	DECLARE_DYNCREATE(CMouseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMouseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMouseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEDOC_H__D826C73C_2B8B_4C16_BEC6_D09F8DD02684__INCLUDED_)
