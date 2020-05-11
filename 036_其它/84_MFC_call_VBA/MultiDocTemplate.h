// MultiDocTemplate.h : interface of the CScriptControlMacroMultiDocTemplate class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MULTIDOCTEMPLATE_H__D817573F_D2C4_4FC9_9367_A64E64660077__INCLUDED_)
#define AFX_MULTIDOCTEMPLATE_H__D817573F_D2C4_4FC9_9367_A64E64660077__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CScriptControlMacroMultiDocTemplate : public CMultiDocTemplate
{
	DECLARE_DYNAMIC(CScriptControlMacroMultiDocTemplate)

// Constructors
public:
	CScriptControlMacroMultiDocTemplate(UINT nIDResource, CRuntimeClass *pDocClass,
		CRuntimeClass *pFrameClass, CRuntimeClass *pViewClass);

// Implementation
public:
	//void LoadTemplate();
	void InitialUpdateFrame(CFrameWnd *pFrame, CDocument *pDoc,
		BOOL bMakeVisible = TRUE);
	void RemoveDocument(CDocument *pDoc);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIDOCTEMPLATE_H__D817573F_D2C4_4FC9_9367_A64E64660077__INCLUDED_)
