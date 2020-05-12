// Get_DrawDoc.h : interface of the CGet_DrawDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GET_DRAWDOC_H__5648D62B_E411_4422_B761_86295282C109__INCLUDED_)
#define AFX_GET_DRAWDOC_H__5648D62B_E411_4422_B761_86295282C109__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGet_DrawDoc : public CDocument
{
protected: // create from serialization only
	CGet_DrawDoc();
	DECLARE_DYNCREATE(CGet_DrawDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGet_DrawDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGet_DrawDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGet_DrawDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GET_DRAWDOC_H__5648D62B_E411_4422_B761_86295282C109__INCLUDED_)
