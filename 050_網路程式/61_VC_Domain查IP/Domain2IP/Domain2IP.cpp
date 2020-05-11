// Domain2IP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Domain2IP.h"
#include <afxsock.h>	 // MFC socket extensions
#include <stdlib.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		WSADATA	wsaData;
		WSAStartup( 0x101, &wsaData );
		
		hostent* theHost;
		char *the_Ip;

		CString str_domain_name = "tw.yahoo.com";
		theHost = gethostbyname(str_domain_name);
		the_Ip = inet_ntoa (*(struct in_addr *)*theHost->h_addr_list);
		TRACE("");

		WSACleanup();
		cout<<str_domain_name.GetBuffer(0)<<endl;
		cout<<the_Ip<<endl;
		system("pause");
	}

	return nRetCode;
}


