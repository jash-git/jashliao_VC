// asdDoc.h : interface of the CAsdDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASDDOC_H__5C01465B_B90B_4BE1_AA86_A601FB7C6427__INCLUDED_)
#define AFX_ASDDOC_H__5C01465B_B90B_4BE1_AA86_A601FB7C6427__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAsdDoc : public CDocument
{
protected: // create from serialization only
	CAsdDoc();
	DECLARE_DYNCREATE(CAsdDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAsdDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAsdDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAsdDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASDDOC_H__5C01465B_B90B_4BE1_AA86_A601FB7C6427__INCLUDED_)
