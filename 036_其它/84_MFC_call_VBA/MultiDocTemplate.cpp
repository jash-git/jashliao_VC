// MultiDocTemplate.cpp : implementation of the CScriptControlMacroMultiDocTemplate class
//

#include "stdafx.h"
#include "ScriptControlMacro.h"

#include "MultiDocTemplate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroMultiDocTemplate

IMPLEMENT_DYNAMIC(CScriptControlMacroMultiDocTemplate, CMultiDocTemplate)

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroMultiDocTemplate construction/destruction

CScriptControlMacroMultiDocTemplate::CScriptControlMacroMultiDocTemplate(UINT nIDResource,
	CRuntimeClass *pDocClass, CRuntimeClass *pFrameClass, CRuntimeClass *pViewClass)
		:CMultiDocTemplate(nIDResource, pDocClass, pFrameClass, pViewClass)
{
}

/*void CScriptControlMacroMultiDocTemplate::LoadTemplate()
{
	// Dummy virtual method to prevent loading template second time
	// from CWinApp::AddDocTemplate method.
}*/

/////////////////////////////////////////////////////////////////////////////
// Default frame creation

void CScriptControlMacroMultiDocTemplate::InitialUpdateFrame(CFrameWnd *pFrame,
	 CDocument *pDoc, BOOL bMakeVisible)
{
	// Restore child frame characteristics from registry or use
	// default size and center it, if the are no settings.

	if(m_docList.GetCount() == 1)
	{
		WINDOWPLACEMENT *pwp;
		UINT cbBytes;

		if(theApp.GetProfileBinary(_T("Settings"), _T("ChildWndPos"), (BYTE**) &pwp, &cbBytes) && (cbBytes == sizeof *pwp))
		{
			pFrame->SetWindowPlacement(pwp);

			delete [] pwp;
		}
		else pFrame->CenterWindow();
	}

	CMultiDocTemplate::InitialUpdateFrame(pFrame, pDoc, bMakeVisible);
}

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroMultiDocTemplate commands

void CScriptControlMacroMultiDocTemplate::RemoveDocument(CDocument *pDoc)
{
	CMultiDocTemplate::RemoveDocument(pDoc);

	// Reset newly created (untitled) documents counter.

	if(m_docList.IsEmpty()) m_nUntitledCount = 0;
}