// kk1Doc.h : interface of the CKk1Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KK1DOC_H__C1C2EC99_E035_40A4_8FC9_CFED045572FB__INCLUDED_)
#define AFX_KK1DOC_H__C1C2EC99_E035_40A4_8FC9_CFED045572FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKk1Doc : public CDocument
{
protected: // create from serialization only
	CKk1Doc();
	DECLARE_DYNCREATE(CKk1Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKk1Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKk1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKk1Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KK1DOC_H__C1C2EC99_E035_40A4_8FC9_CFED045572FB__INCLUDED_)
