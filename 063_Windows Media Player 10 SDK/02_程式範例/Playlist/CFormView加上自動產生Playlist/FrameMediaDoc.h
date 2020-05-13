// FrameMediaDoc.h : interface of the CFrameMediaDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FRAMEMEDIADOC_H__17FE609B_1BA5_4A2D_BCCA_FE9A73E6CE73__INCLUDED_)
#define AFX_FRAMEMEDIADOC_H__17FE609B_1BA5_4A2D_BCCA_FE9A73E6CE73__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFrameMediaDoc : public CDocument
{
protected: // create from serialization only
	CFrameMediaDoc();
	DECLARE_DYNCREATE(CFrameMediaDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFrameMediaDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CFrameMediaDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFrameMediaDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FRAMEMEDIADOC_H__17FE609B_1BA5_4A2D_BCCA_FE9A73E6CE73__INCLUDED_)
