// FTPUpLoad.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "FTPUpLoad.h"
#include <afxinet.h>//FTP_1
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
CInternetSession *m_pInetSession; //FTP_2
CFtpConnection *m_pFtpConnection; 
//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CFTPUpLoadApp

BEGIN_MESSAGE_MAP(CFTPUpLoadApp, CWinApp)
	//{{AFX_MSG_MAP(CFTPUpLoadApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFTPUpLoadApp construction
bool EXPORTED_DLL_FUNCTION ConnectFTP (char *chrFTPServer,char *chruser,char *chrpws,int intport)
{
	bool blncheck;
	CString StrFTPServer,Struser,Strpws;
	StrFTPServer=chrFTPServer;
	Struser=chruser;
	Strpws=chrpws;
	m_pInetSession=new CInternetSession (AfxGetAppName(),1, PRE_CONFIG_INTERNET_ACCESS); 
	try 
	{ 
		//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
		m_pFtpConnection=m_pInetSession->GetFtpConnection(StrFTPServer,Struser,Strpws,intport);
		blncheck=true;
	} 
	catch(CInternetException *pEx) 
	{ 
		blncheck=false;
		m_pFtpConnection=NULL;
	}
	return blncheck;
}
void EXPORTED_DLL_FUNCTION ClosetFTP ()
{
	m_pFtpConnection->Close();
	delete m_pInetSession;
}
bool EXPORTED_DLL_FUNCTION UpLoadFTP (char *LocalFile,char *RemoteFile)
{
	bool blncheck;
	CString StrRemoteFile;
	CString StrLocalFile;
	StrRemoteFile=RemoteFile;
	StrLocalFile=LocalFile;
	blncheck=m_pFtpConnection->PutFile(StrLocalFile,RemoteFile);
	DeleteFile(LocalFile);
	return blncheck;
}
bool EXPORTED_DLL_FUNCTION DownLoadFTP (char *RemoteFile,char *LocalFile)
{
	bool blncheck;
	CString StrRemoteFile;
	CString StrLocalFile;
	StrRemoteFile=RemoteFile;
	StrLocalFile=LocalFile;
	blncheck=m_pFtpConnection->GetFile(StrRemoteFile,StrLocalFile,true,FILE_ATTRIBUTE_NORMAL,FTP_TRANSFER_TYPE_BINARY,1);
	return blncheck;
}
CFTPUpLoadApp::CFTPUpLoadApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CFTPUpLoadApp object

CFTPUpLoadApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CFTPUpLoadApp initialization

BOOL CFTPUpLoadApp::InitInstance()
{
	if (!AfxSocketInit())
	{
		AfxMessageBox(IDP_SOCKETS_INIT_FAILED);
		return FALSE;
	}

	return TRUE;
}
