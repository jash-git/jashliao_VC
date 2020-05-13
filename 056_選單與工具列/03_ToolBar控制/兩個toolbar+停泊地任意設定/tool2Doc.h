// tool2Doc.h : interface of the CTool2Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TOOL2DOC_H__5EA4A3EA_211C_11DA_B776_0040F43A9B72__INCLUDED_)
#define AFX_TOOL2DOC_H__5EA4A3EA_211C_11DA_B776_0040F43A9B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTool2Doc : public CDocument
{
protected: // create from serialization only
	CTool2Doc();
	DECLARE_DYNCREATE(CTool2Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTool2Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTool2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTool2Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOOL2DOC_H__5EA4A3EA_211C_11DA_B776_0040F43A9B72__INCLUDED_)
