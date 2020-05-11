// GLbaseDoc.h : interface of the CGLbaseDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLBASEDOC_H__CA6432EA_29B3_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_GLBASEDOC_H__CA6432EA_29B3_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGLbaseDoc : public CDocument
{
protected: // create from serialization only
	CGLbaseDoc();
	DECLARE_DYNCREATE(CGLbaseDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLbaseDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGLbaseDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGLbaseDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLBASEDOC_H__CA6432EA_29B3_11DA_B776_0040F43A9B72__INCLUDED_)
