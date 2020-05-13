// kkkkDoc.h : interface of the CKkkkDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KKKKDOC_H__479CE3B1_7030_47F6_BFF5_090182233DFC__INCLUDED_)
#define AFX_KKKKDOC_H__479CE3B1_7030_47F6_BFF5_090182233DFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKkkkDoc : public CDocument
{
protected: // create from serialization only
	CKkkkDoc();
	DECLARE_DYNCREATE(CKkkkDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKkkkDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKkkkDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKkkkDoc)
	afx_msg void Ontest();
	afx_msg void Ont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KKKKDOC_H__479CE3B1_7030_47F6_BFF5_090182233DFC__INCLUDED_)
