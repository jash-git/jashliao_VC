// SDIShowDoc.h : interface of the CSDIShowDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDISHOWDOC_H__220D9F56_AE32_48EC_8299_FD193C155A44__INCLUDED_)
#define AFX_SDISHOWDOC_H__220D9F56_AE32_48EC_8299_FD193C155A44__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSDIShowDoc : public CDocument
{
protected: // create from serialization only
	CSDIShowDoc();
	DECLARE_DYNCREATE(CSDIShowDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDIShowDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSDIShowDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSDIShowDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDISHOWDOC_H__220D9F56_AE32_48EC_8299_FD193C155A44__INCLUDED_)
