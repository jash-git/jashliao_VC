// ServerGetDataDoc.h : interface of the CServerGetDataDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SERVERGETDATADOC_H__7783D88E_EC69_4A77_9AD8_7F06ABDD0C5D__INCLUDED_)
#define AFX_SERVERGETDATADOC_H__7783D88E_EC69_4A77_9AD8_7F06ABDD0C5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CServerGetDataDoc : public CDocument
{
protected: // create from serialization only
	CServerGetDataDoc();
	DECLARE_DYNCREATE(CServerGetDataDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerGetDataDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CServerGetDataDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CServerGetDataDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERGETDATADOC_H__7783D88E_EC69_4A77_9AD8_7F06ABDD0C5D__INCLUDED_)
