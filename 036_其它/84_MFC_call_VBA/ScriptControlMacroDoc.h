// ScriptControlMacroDoc.h : interface of the CScriptControlMacroDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCRIPTCONTROLMACRODOC_H__15482B04_D73F_4DDE_85FB_192DD3BEB3BF__INCLUDED_)
#define AFX_SCRIPTCONTROLMACRODOC_H__15482B04_D73F_4DDE_85FB_192DD3BEB3BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CScriptControlMacroDoc : public CDocument
{
protected: // create from serialization only
	DECLARE_DYNCREATE(CScriptControlMacroDoc)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptControlMacroDoc)
	public:
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
#ifdef _DEBUG
	void AssertValid() const;
	void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CScriptControlMacroDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTCONTROLMACRODOC_H__15482B04_D73F_4DDE_85FB_192DD3BEB3BF__INCLUDED_)
