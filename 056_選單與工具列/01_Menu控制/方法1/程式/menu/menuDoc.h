// menuDoc.h : interface of the CMenuDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUDOC_H__A9E4DEEA_2150_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_MENUDOC_H__A9E4DEEA_2150_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenuDoc : public CDocument
{
protected: // create from serialization only
	CMenuDoc();
	DECLARE_DYNCREATE(CMenuDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMenuDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenuDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUDOC_H__A9E4DEEA_2150_11DA_B776_0040F43A9B72__INCLUDED_)
