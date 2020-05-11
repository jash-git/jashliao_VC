// ScriptControlMacroView.cpp : implementation of the CScriptControlMacroView class
//

#include "stdafx.h"
#include "ScriptControlMacro.h"

#include "ScriptControlMacroDoc.h"
#include "ScriptControlMacroView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroView

IMPLEMENT_DYNCREATE(CScriptControlMacroView, CEditView)

BEGIN_MESSAGE_MAP(CScriptControlMacroView, CEditView)
	//{{AFX_MSG_MAP(CScriptControlMacroView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_UPDATE_COMMAND_UI(ID_EDIT_SELECT_ALL, OnUpdateEditSelectAll)
	ON_UPDATE_COMMAND_UI(ID_DEBUG_RUN, OnUpdateDebugRun)
	ON_COMMAND(ID_CHOOSE_FONT, OnChooseFont)
	ON_COMMAND(ID_DEBUG_RUN, OnDebugRun)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroView message handlers

BOOL CScriptControlMacroView::PreCreateWindow(CREATESTRUCT& cs) 
{
	// TODO: Add your specialized code here and/or call the base class

	if(!CEditView::PreCreateWindow(cs)) return FALSE;

	// This will add the sunken border to the view and
	// remove the thin border around the edit control

	cs.dwExStyle |= WS_EX_DLGMODALFRAME;

	return TRUE;
}

int CScriptControlMacroView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if(CEditView::OnCreate(lpCreateStruct) == -1) return -1;
	
	// TODO: Add your specialized creation code here

	SetTabStops(16);

	// Restore font characteristics from registry or try to use
	// Courier New 10 points size or shell (MS Sans Serif/Tahoma)
	// font, if the are no settings.

	LOGFONT *plf;
	UINT cbBytes;

	if(theApp.GetProfileBinary(_T("Settings"), _T("Font"), (BYTE**) &plf, &cbBytes) && (cbBytes == sizeof *plf))
	{
		m_Font.CreateFontIndirect(plf);

		delete [] plf;

		m_fFontChanged = FALSE;
	}
	else
	{
		if(!m_Font.CreatePointFont(100, _T("Courier New"))) m_Font.CreateStockObject(DEFAULT_GUI_FONT);

		m_fFontChanged = TRUE;
	}

	SetFont(&m_Font);

	return 0;
}

void CScriptControlMacroView::OnDestroy() 
{
	// TODO: Add your message handler code here

	// Save font characteristics in the registry.

	if(m_fFontChanged)
	{
		LOGFONT lf;

		m_Font.GetLogFont(&lf);

		theApp.WriteProfileBinary(_T("Settings"), _T("Font"), (BYTE*) &lf, sizeof lf);
	}

	CEditView::OnDestroy();
}

void CScriptControlMacroView::OnUpdateEditSelectAll(CCmdUI *pCmdUI) 
{
	// TODO: Add your command update UI handler code here

	// Enable Select all item of the Edit menu, if all text is not
	// selected, otherwise disable.

	UINT nLen = GetWindowTextLength();

	int nStartChar, nEndChar;

	GetEditCtrl().GetSel(nStartChar, nEndChar);

	pCmdUI->Enable((nLen && (nLen - nEndChar + nStartChar)));
}

void CScriptControlMacroView::OnUpdateDebugRun(CCmdUI *pCmdUI) 
{
	// TODO: Add your command update UI handler code here

	// Enable Run item of the Debug menu, if there is any text,
	// otherwise disable.

	pCmdUI->Enable(GetWindowTextLength());
}

void CScriptControlMacroView::OnChooseFont() 
{
	// TODO: Add your command handler code here

	LOGFONT lf;

	m_Font.GetLogFont(&lf);

	CFontDialog dlg(&lf, CF_BOTH);

	if(dlg.DoModal() == IDOK)
	{
		HFONT hFont = ::CreateFontIndirect(&lf);

		if(hFont != NULL)
		{
			m_Font.DeleteObject();
			m_Font.m_hObject = hFont;

			SetFont(&m_Font);

			m_fFontChanged = TRUE;
		}
	}
}

void CScriptControlMacroView::OnDebugRun() 
{
	// TODO: Add your command handler code here

	if(m_IScriptCtl.CreateDispatch(CLSID_ScriptControl))
	{
		CScriptControlMacroDispatch ScriptControlMacroDispatch;

		/*const AFX_DISPMAP *pDispMap = ScriptControlMacroDispatch.GetDispatchMap();
		UINT nDispEntries = ScriptControlMacroDispatch.GetEntryCount(pDispMap);

		CString str(_T("Built-in methods:\n"));

		for(UINT i = 0; i < nDispEntries; i++)
		{
			str += "\n";
			str += pDispMap->lpEntries[i].lpszName;
		}

		AfxMessageBox(str, MB_ICONASTERISK);*/

		try
		{
			m_IScriptCtl.SetSitehWnd(theApp.m_pMainWnd->m_hWnd);

			m_IScriptCtl.SetLanguage(_T("VBScript"));

			m_IScriptCtl.AddObject(_T("ScriptControlMacro"), ScriptControlMacroDispatch.GetIDispatch(FALSE), TRUE);

			CString str;

			GetWindowText(str);

			m_IScriptCtl.AddCode(str);
		}
		catch(CException *pe)
		{
			ReportRunError(pe);
		}

		m_IScriptCtl.ReleaseDispatch();
	}
	else AfxMessageBox(IDP_SC_CREATE_FAILED, MB_ICONERROR);
}

void CScriptControlMacroView::ReportRunError(CException *pException)
{
	COleDispatchException *pe;

	if(pException->IsKindOf(RUNTIME_CLASS(COleDispatchException))) pe = (COleDispatchException*) pException;
	else
	{
		pe = new COleDispatchException(NULL, 0, 0);

		pe->m_scError = COleException::Process(pException);

		TCHAR sz[256];

		pException->GetErrorMessage(sz, sizeof sz);

		pe->m_strDescription = sz;

		pException->Delete();
	}

	CString strMsg;

	strMsg.Format(IDP_SC_ERROR_INFO1, SCODE_CODE(pe->m_scError), pe->m_strSource.IsEmpty() ? theApp.m_pszAppName : pe->m_strSource, pe->m_strDescription);

	IDispatch *pIDispatch = m_IScriptCtl.GetError();

	if(pIDispatch != NULL)
	{
		IScriptError IScriptErr;

		IScriptErr.AttachDispatch(pIDispatch);

		long ErrNum;

		if(ErrNum = IScriptErr.GetNumber())
		{
			CString str;

			str.Format(IDP_SC_ERROR_INFO2, IScriptErr.GetLine(), IScriptErr.GetColumn());

			strMsg += str;

			CString strCode(IScriptErr.GetText());

			if(!strCode.IsEmpty())
			{
				str.Format(IDP_SC_ERROR_INFO3, strCode);

				strMsg += str;
			}
		}
	}

	AfxMessageBox(strMsg, MB_ICONERROR);

	pe->Delete();
}
