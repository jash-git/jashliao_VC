// test_HideDoc.h : interface of the CTest_HideDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST_HIDEDOC_H__59344FC4_4D72_4BB3_A869_CBE761C9E7FD__INCLUDED_)
#define AFX_TEST_HIDEDOC_H__59344FC4_4D72_4BB3_A869_CBE761C9E7FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest_HideDoc : public CDocument
{
protected: // create from serialization only
	CTest_HideDoc();
	DECLARE_DYNCREATE(CTest_HideDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest_HideDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest_HideDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest_HideDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST_HIDEDOC_H__59344FC4_4D72_4BB3_A869_CBE761C9E7FD__INCLUDED_)
