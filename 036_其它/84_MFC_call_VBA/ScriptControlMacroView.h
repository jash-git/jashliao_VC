// ScriptControlMacroView.h : interface of the CScriptControlMacroView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCRIPTCONTROLMACROVIEW_H__8501D01B_F194_49E4_84A9_BAB662F40ED4__INCLUDED_)
#define AFX_SCRIPTCONTROLMACROVIEW_H__8501D01B_F194_49E4_84A9_BAB662F40ED4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MSScriptControl.h"
#include "ScriptControlMacroDispatch.h"

class CScriptControlMacroView : public CEditView
{
	DECLARE_DYNCREATE(CScriptControlMacroView)

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScriptControlMacroView)
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Generated message map functions
protected:
	IScriptControl m_IScriptCtl;
	void ReportRunError(CException *pException);
	BOOL m_fFontChanged;
	CFont m_Font;
	//{{AFX_MSG(CScriptControlMacroView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnUpdateEditSelectAll(CCmdUI *pCmdUI);
	afx_msg void OnUpdateDebugRun(CCmdUI *pCmdUI);
	afx_msg void OnChooseFont();
	afx_msg void OnDebugRun();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPTCONTROLMACROVIEW_H__8501D01B_F194_49E4_84A9_BAB662F40ED4__INCLUDED_)
