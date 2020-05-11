// MFCPaPaGoDoc.h : interface of the CMFCPaPaGoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCPAPAGODOC_H__AB6B0D40_200A_4244_9C21_CD3162F67F02__INCLUDED_)
#define AFX_MFCPAPAGODOC_H__AB6B0D40_200A_4244_9C21_CD3162F67F02__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMFCPaPaGoDoc : public CDocument
{
protected: // create from serialization only
	CMFCPaPaGoDoc();
	DECLARE_DYNCREATE(CMFCPaPaGoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCPaPaGoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMFCPaPaGoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMFCPaPaGoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCPAPAGODOC_H__AB6B0D40_200A_4244_9C21_CD3162F67F02__INCLUDED_)
