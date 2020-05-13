// MenuCtrlDoc.h : interface of the CMenuCtrlDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENUCTRLDOC_H__E278718A_2F34_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_MENUCTRLDOC_H__E278718A_2F34_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMenuCtrlDoc : public CDocument
{
protected: // create from serialization only
	CMenuCtrlDoc();
	DECLARE_DYNCREATE(CMenuCtrlDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuCtrlDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMenuCtrlDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenuCtrlDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENUCTRLDOC_H__E278718A_2F34_11DA_B776_0040F43A9B72__INCLUDED_)
