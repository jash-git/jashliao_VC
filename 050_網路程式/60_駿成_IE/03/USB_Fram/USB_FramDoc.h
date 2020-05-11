// USB_FramDoc.h : interface of the CUSB_FramDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USB_FRAMDOC_H__4B231D87_D1BE_49C8_9611_DBB7F7104158__INCLUDED_)
#define AFX_USB_FRAMDOC_H__4B231D87_D1BE_49C8_9611_DBB7F7104158__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUSB_FramDoc : public CDocument
{
protected: // create from serialization only
	CUSB_FramDoc();
	DECLARE_DYNCREATE(CUSB_FramDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUSB_FramDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUSB_FramDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUSB_FramDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USB_FRAMDOC_H__4B231D87_D1BE_49C8_9611_DBB7F7104158__INCLUDED_)
