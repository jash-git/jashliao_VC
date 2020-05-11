// MySOLODBCDoc.h : interface of the CMySOLODBCDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSOLODBCDOC_H__20D3A13F_D07C_4452_B650_EF0F7B574D1C__INCLUDED_)
#define AFX_MYSOLODBCDOC_H__20D3A13F_D07C_4452_B650_EF0F7B574D1C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MySOLODBCSet.h"


class CMySOLODBCDoc : public CDocument
{
protected: // create from serialization only
	CMySOLODBCDoc();
	DECLARE_DYNCREATE(CMySOLODBCDoc)

// Attributes
public:
	CMySOLODBCSet m_mySOLODBCSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySOLODBCDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMySOLODBCDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMySOLODBCDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOLODBCDOC_H__20D3A13F_D07C_4452_B650_EF0F7B574D1C__INCLUDED_)
