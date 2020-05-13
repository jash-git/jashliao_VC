// ProjSerializeDoc.h : interface of the CProjSerializeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROJSERIALIZEDOC_H__DD88484A_195D_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_PROJSERIALIZEDOC_H__DD88484A_195D_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CProjSerializeDoc : public CDocument
{
protected: // create from serialization only
	CProjSerializeDoc();
	DECLARE_DYNCREATE(CProjSerializeDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProjSerializeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CProjSerializeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CProjSerializeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROJSERIALIZEDOC_H__DD88484A_195D_11DA_B776_0040F43A9B72__INCLUDED_)
