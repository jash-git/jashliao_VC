// TopShowDoc.h : interface of the CTopShowDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOPSHOWDOC_H__F607772A_2393_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TOPSHOWDOC_H__F607772A_2393_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTopShowDoc : public CDocument
{
protected: // create from serialization only
	CTopShowDoc();
	DECLARE_DYNCREATE(CTopShowDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopShowDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTopShowDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTopShowDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPSHOWDOC_H__F607772A_2393_11DA_B776_0040F43A9B72__INCLUDED_)
