// ScriptControlMacro.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "ScriptControlMacro.h"
#include <locale.h>

#include "MultiDocTemplate.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "ScriptControlMacroDoc.h"
#include "ScriptControlMacroView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroApp

BEGIN_MESSAGE_MAP(CScriptControlMacroApp, CWinApp)
	//{{AFX_MSG_MAP(CScriptControlMacroApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// The one and only CScriptControlMacroApp object

CScriptControlMacroApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroApp initialization

BOOL CScriptControlMacroApp::InitInstance()
{
	// Try to find first application instance and show it's main window.

	m_hFileMap = ::CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0,
		sizeof(HWND), AfxStringFromCLSID(IID_IScriptControlMacroDispatch));

	if(!m_hFileMap) return FALSE;

	DWORD dwError = ::GetLastError();

	HWND* phWnd = (HWND*) ::MapViewOfFile(m_hFileMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);

	if(!phWnd) return FALSE;

	BOOL bResult = FALSE;

	if(dwError == ERROR_ALREADY_EXISTS)
	{
		HWND hWndActive = ::GetLastActivePopup(*phWnd);
		if(::IsIconic(*phWnd)) ::ShowWindow(*phWnd, SW_RESTORE);
		::SetForegroundWindow(hWndActive);
	}
	else
	{
		// Initialize locale to system default.

		_tsetlocale(LC_ALL, _T(""));

		// We will use OLE Automation.

		if(!AfxOleInit()) AfxMessageBox(IDP_OLE_INIT_FAILED, MB_ICONERROR | MB_SETFOREGROUND);
		else
		{
			// This will force to use English MFC resources.

#ifdef _DEBUG

			m_appLangDLL = AfxLoadLibrary(_T("MFC42D"));

#else

			m_appLangDLL = AfxLoadLibrary(_T("MFC42"));

#endif

			if(m_appLangDLL)
			{
				AFX_MODULE_STATE *pState = AfxGetModuleState();

				pState->m_appLangDLL = m_appLangDLL;
			}

			// Change the registry key under which our settings are stored.
			// TODO: You should modify this string to be something appropriate
			// such as the name of your company or organization.

			SetRegistryKey(_T("Mosc"));

			LoadStdProfileSettings();

			// Register the application's document templates.  Document templates
			// serve as the connection between documents, frame windows and views.

			CScriptControlMacroMultiDocTemplate *pDocTemplate =
				new CScriptControlMacroMultiDocTemplate(IDR_MACROTYPE,
				RUNTIME_CLASS(CScriptControlMacroDoc), RUNTIME_CLASS(CChildFrame),
				RUNTIME_CLASS(CScriptControlMacroView));

			// BUG: AddDocTemplate function will call CMultiDocTemplate::LoadTemplate
			// second time (the first time it is called from CMultiDocTemplate constructor),
			// CMultiDocTemplate::LoadTemplate will call CDocTemplate::LoadTemplate
			// third time (the first time it is called from CDocTemplate constructor,
			// the second time it is called from CMultiDocTemplate::LoadTemplate in
			// CMultiDocTemplate constructor), to partially prevent it use dummy virtual
			// method CScriptControlMacroMultiDocTemplate::LoadTemplate,
			// CDocTemplate::LoadTemplate still will be called twice.

			AddDocTemplate(pDocTemplate);

			// Create main MDI Frame window

			CMainFrame *pMainFrame = new CMainFrame;

			if(pMainFrame->LoadFrame(IDR_MAINFRAME))
			{
				m_pMainWnd = pMainFrame;

				// Enable drag/drop Macro file open.

				m_pMainWnd->DragAcceptFiles();

				UpdateMRUMenu();

				// The main window has been initialized, so show and update it,
				// using characteristics from registry or using default
				// size and center it, if the are no settings.

				WINDOWPLACEMENT *pwp;
				UINT cbBytes;

				if(GetProfileBinary(_T("Settings"), _T("MainWndPos"), (BYTE**) &pwp, &cbBytes)
					&& (cbBytes == sizeof *pwp))
				{
					if(m_nCmdShow != SW_SHOWNORMAL && m_nCmdShow != SW_SHOWDEFAULT)
						pwp->showCmd = m_nCmdShow;

					pMainFrame->SetWindowPlacement(pwp);
					pMainFrame->ShowWindow(pwp->showCmd);

					delete [] pwp;
				}
				else
				{
					pMainFrame->CenterWindow();
					pMainFrame->ShowWindow(m_nCmdShow);
				}

				pMainFrame->UpdateWindow();
				*phWnd = m_pMainWnd->m_hWnd;

				bResult = TRUE;
			}
		}
	}

	::UnmapViewOfFile(phWnd);

	return bResult;
}

// App command to run the dialog.

void CScriptControlMacroApp::OnAppAbout()
{
	CDialog dlg(IDD_ABOUTBOX);
	dlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CScriptControlMacroApp message handlers

int CScriptControlMacroApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class

	// Decrement reference count to MFC42.DLL, which we have used for English resources.

	if(m_appLangDLL) AfxFreeLibrary(m_appLangDLL);

	// Close the file mapping object.

	if(m_hFileMap) ::CloseHandle(m_hFileMap);

	return CWinApp::ExitInstance();
}

void CScriptControlMacroApp::AddToRecentFileList(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class

	CWinApp::AddToRecentFileList(lpszPathName);

	if(!m_fMRUMenuVisible) UpdateMRUMenu();
}

BOOL CScriptControlMacroApp::UpdateMRUMenu()
{
	// Check the recent files list and if it is not empty add
	// corresponding items and separator to the File menu.

	if(!m_pRecentFileList->m_arrNames[0].IsEmpty())
	{
		CMenu *pMenu = m_pMainWnd->GetMenu()->GetSubMenu(0);
		
		if(pMenu != NULL)
		{
			pMenu->InsertMenu(ID_APP_EXIT, MF_STRING, ID_FILE_MRU_FILE1, _T(""));
			pMenu->InsertMenu(ID_APP_EXIT, MF_SEPARATOR);

			m_fMRUMenuVisible = TRUE;

			return TRUE;
		}
	}

	return FALSE;
}