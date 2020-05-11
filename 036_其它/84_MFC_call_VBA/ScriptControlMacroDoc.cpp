// ScriptControlMacroDoc.cpp : implementation of the CScriptControlMacroDoc class
//

#include "stdafx.h"
#include "ScriptControlMacro.h"

#include "ScriptControlMacroDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroDoc

IMPLEMENT_DYNCREATE(CScriptControlMacroDoc, CDocument)

BEGIN_MESSAGE_MAP(CScriptControlMacroDoc, CDocument)
	//{{AFX_MSG_MAP(CScriptControlMacroDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroDoc serialization

void CScriptControlMacroDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroDoc diagnostics

#ifdef _DEBUG
void CScriptControlMacroDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CScriptControlMacroDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG