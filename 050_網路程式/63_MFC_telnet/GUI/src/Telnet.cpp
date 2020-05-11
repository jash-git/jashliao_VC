// Telnet.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Telnet.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "ClientDoc.h"
#include "ClientView.h"
#include "ServerDoc.h"
#include "ServerView.h"
#include ".\telnet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTelnetApp

BEGIN_MESSAGE_MAP(CTelnetApp, CWinApp)
        ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
        // Standard file based document commands
        //ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
        //ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
        ON_COMMAND(ID_CLNT_NEW, OnClntNew)
        ON_COMMAND(ID_SERV_NEW, OnServNew)
END_MESSAGE_MAP()


// CTelnetApp construction

CTelnetApp::CTelnetApp() : wsaStarted(false)
{
        // TODO: add construction code here,
        // Place all significant initialization in InitInstance
}


// The one and only CTelnetApp object

CTelnetApp theApp;

// CTelnetApp initialization

BOOL CTelnetApp::InitInstance()
{
        int res = WSAStartup(0x202, &wsaData);
        if (res) {
                AfxMessageBox("WSAStartup filed. [CTelnetApp::InitInstance()]", 0);
                return false;
        }
        wsaStarted = true;

        char dir[1024];
        if (GetCurrentDirectory(1024, dir)) {
                strcat(dir, "\\hosts");
                FILE *fp = fopen(dir, "rt");
                if (fp) {
                        int res;
                        while ((res = fscanf(fp, "%s", dir)) && res != EOF)
                                m_addrList.AddHead(dir);

                        fclose(fp);
                }
        }


        // InitCommonControls() is required on Windows XP if an application
        // manifest specifies use of ComCtl32.dll version 6 or later to enable
        // visual styles.  Otherwise, any window creation will fail.
        InitCommonControls();

        CWinApp::InitInstance();

        // Standard initialization
        // If you are not using these features and wish to reduce the size
        // of your final executable, you should remove from the following
        // the specific initialization routines you do not need
        // Change the registry key under which our settings are stored
        // TODO: You should modify this string to be something appropriate
        // such as the name of your company or organization
        SetRegistryKey(_T("Local AppWizard-Generated Applications"));
        LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)
        // Register the application's document templates.  Document templates
        //  serve as the connection between documents, frame windows and views


        pClientDocTemplate = new CMultiDocTemplate(IDR_ClientTYPE,
                        RUNTIME_CLASS(CClientDoc),
                        RUNTIME_CLASS(CChildFrame), // custom MDI child frame
                        RUNTIME_CLASS(CClientView));
        if (!pClientDocTemplate)
                return FALSE;
        pServerDocTemplate = new CMultiDocTemplate(IDR_ServerTYPE,
                        RUNTIME_CLASS(CServerDoc),
                        RUNTIME_CLASS(CChildFrame), // custom MDI child frame
                        RUNTIME_CLASS(CServerView));
        if (!pServerDocTemplate)
                return FALSE;

        AddDocTemplate(pClientDocTemplate);
        AddDocTemplate(pServerDocTemplate);


        // create main MDI Frame window
        CMainFrame* pMainFrame = new CMainFrame;
        if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
                return FALSE;
        m_pMainWnd = pMainFrame;
        // call DragAcceptFiles only if there's a suffix
        //  In an MDI app, this should occur immediately after setting m_pMainWnd
        // Parse command line for standard shell commands, DDE, file open
        /*CCommandLineInfo cmdInfo;
        ParseCommandLine(cmdInfo);
        // Dispatch commands specified on the command line.  Will return FALSE if
        // app was launched with /RegServer, /Register, /Unregserver or /Unregister.
        if (!ProcessShellCommand(cmdInfo))
        	return FALSE;
        // The main window has been initialized, so show and update it*/
        pMainFrame->ShowWindow(m_nCmdShow);
        pMainFrame->UpdateWindow();
        return TRUE;
}

int CTelnetApp::ExitInstance()
{
        if (wsaStarted)
                WSACleanup();

        return CWinApp::ExitInstance();
}


void CTelnetApp::OnClntNew()
{
        CClientDoc *pDoc = STATIC_DOWNCAST(CClientDoc, pClientDocTemplate->CreateNewDocument());
        CFrameWnd *pWnd = pClientDocTemplate->CreateNewFrame(pDoc, 0);
        if (pDoc->OnNewDocument())
                pClientDocTemplate->InitialUpdateFrame(pWnd, pDoc);
        else
                pDoc->OnCloseDocument();

}

void CTelnetApp::OnServNew()
{
        CServerDoc *pDoc = STATIC_DOWNCAST(CServerDoc, pServerDocTemplate->CreateNewDocument());
        CFrameWnd *pWnd = pServerDocTemplate->CreateNewFrame(pDoc, 0);
        if (pDoc->OnNewDocument())
                pServerDocTemplate->InitialUpdateFrame(pWnd, pDoc);
        else
                pDoc->OnCloseDocument();
}










// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
        CAboutDlg();

// Dialog Data
        enum { IDD = IDD_ABOUTBOX };

protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
        DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
        CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// App command to run the dialog
void CTelnetApp::OnAppAbout()
{
        CAboutDlg aboutDlg;
        aboutDlg.DoModal();
}




