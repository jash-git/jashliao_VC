// ScriptControlMacroDispatch.h : interface of the CScriptControlMacroDispatch class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCRIPTCONTROLMACRODISPATCH_H__FB55B5AF_00E5_47F5_B176_214B2C7BF19A__INCLUDED_)
#define AFX_SCRIPTCONTROLMACRODISPATCH_H__FB55B5AF_00E5_47F5_B176_214B2C7BF19A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroDispatch command target

class CScriptControlMacroDispatch : public CCmdTarget
{
	DECLARE_DYNCREATE(CScriptControlMacroDispatch)

	CScriptControlMacroDispatch();           // protected constructor used by dynamic creation

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptControlMacroDispatch)
	//}}AFX_VIRTUAL

// Implementation

protected:
	//friend class CScriptControlMacroView;
	// Generated message map functions
	//{{AFX_MSG(CScriptControlMacroDispatch)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CScriptControlMacroDispatch)
	afx_msg void Test1();
	afx_msg void Test2();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

// Note: we add support for IID_IScriptControlMacroDispatch to support typesafe binding
// from VBA.  This IID must match the GUID that is attached to the 
// dispinterface in the .ODL file.

// {69AA5686-41AF-4CD9-AEAE-9DB88130E7C1}
static const IID IID_IScriptControlMacroDispatch =
{0x69AA5686, 0x41AF, 0x4CD9, {0xAE, 0xAE, 0x9D, 0xB8, 0x81, 0x30, 0xE7, 0xC1}};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTCONTROLMACRODISPATCH_H__FB55B5AF_00E5_47F5_B176_214B2C7BF19A__INCLUDED_)
