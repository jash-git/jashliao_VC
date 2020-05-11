// CStringArray_Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CStringArray_Sort.h"
/////////////////////////////////
#include "SortableStringArray.h"
/////////////////////////////////
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
		CSortableStringArray SASA;
		SASA.Add(CString("test_840K"));
		SASA.Add(CString("test_64K"));
		SASA.Add(CString("test_640K"));
		SASA.Add(CString("test_1240K"));
		for (int i = 0; i <= SASA.GetUpperBound(); i++)
			cout << SASA[i].GetBuffer(0) << endl;
		
		SASA.Sort();
		cout <<"/////////////////////////////////"<< endl;

		for (int j = 0; j <= SASA.GetUpperBound(); j++)
			cout << SASA[j].GetBuffer(0) << endl;

	}

	return nRetCode;
}


