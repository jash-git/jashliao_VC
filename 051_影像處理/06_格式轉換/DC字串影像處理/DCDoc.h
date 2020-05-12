// DCDoc.h : interface of the CDCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCDOC_H__E0CCF1FC_7FDA_4D60_934A_A0EBCAB69642__INCLUDED_)
#define AFX_DCDOC_H__E0CCF1FC_7FDA_4D60_934A_A0EBCAB69642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDCDoc : public CDocument
{
protected: // create from serialization only
	CDCDoc();
	DECLARE_DYNCREATE(CDCDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCDOC_H__E0CCF1FC_7FDA_4D60_934A_A0EBCAB69642__INCLUDED_)
