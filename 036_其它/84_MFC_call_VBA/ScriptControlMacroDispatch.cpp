// ScriptControlMacroDispatch.cpp : implementation of the CScriptControlMacroDispatch class
//

#include "stdafx.h"
#include "ScriptControlMacroDispatch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroDispatch

IMPLEMENT_DYNCREATE(CScriptControlMacroDispatch, CCmdTarget)

CScriptControlMacroDispatch::CScriptControlMacroDispatch()
{
	EnableAutomation();
}

BEGIN_MESSAGE_MAP(CScriptControlMacroDispatch, CCmdTarget)
	//{{AFX_MSG_MAP(CScriptControlMacroDispatch)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CScriptControlMacroDispatch, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CScriptControlMacroDispatch)
	DISP_FUNCTION(CScriptControlMacroDispatch, "Test1", Test1, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CScriptControlMacroDispatch, "Test2", Test2, VT_EMPTY, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

BEGIN_INTERFACE_MAP(CScriptControlMacroDispatch, CCmdTarget)
	INTERFACE_PART(CScriptControlMacroDispatch, IID_IScriptControlMacroDispatch, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroDispatch message handlers

void CScriptControlMacroDispatch::Test1()
{
	// TODO: Add your dispatch handler code here

	AfxMessageBox(CString(_T("\"")) + GetDispatchMap()->lpEntries->lpszName + _T("\" method call of the \"") + RUNTIME_CLASS(CScriptControlMacroDispatch)->m_lpszClassName + _T("\" class"), MB_ICONASTERISK);
	//AfxMessageBox(_T("CScriptControlMacroDispatch::Test1()"), MB_ICONASTERISK);
}

void CScriptControlMacroDispatch::Test2()
{
	// TODO: Add your dispatch handler code here

	AfxMessageBox(CString(_T("\"")) + GetDispatchMap()->lpEntries[1].lpszName + _T("\" method call of the \"") + RUNTIME_CLASS(CScriptControlMacroDispatch)->m_lpszClassName + _T("\" class"), MB_ICONASTERISK);
	//AfxMessageBox(_T("CScriptControlMacroDispatch::Test2()"), MB_ICONASTERISK);
}