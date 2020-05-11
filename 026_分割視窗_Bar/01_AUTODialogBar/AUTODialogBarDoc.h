// AUTODialogBarDoc.h : interface of the CAUTODialogBarDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_AUTODIALOGBARDOC_H__70C4723C_D5E4_4D22_90F4_A04211A373B8__INCLUDED_)
#define AFX_AUTODIALOGBARDOC_H__70C4723C_D5E4_4D22_90F4_A04211A373B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CAUTODialogBarDoc : public CDocument
{
protected: // create from serialization only
	CAUTODialogBarDoc();
	DECLARE_DYNCREATE(CAUTODialogBarDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAUTODialogBarDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAUTODialogBarDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAUTODialogBarDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTODIALOGBARDOC_H__70C4723C_D5E4_4D22_90F4_A04211A373B8__INCLUDED_)
