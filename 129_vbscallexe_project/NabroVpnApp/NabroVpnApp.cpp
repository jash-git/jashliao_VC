// NabroVpnApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "NabroVpnApp.h"
#include <afxinet.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define BUFFER_SIZE 2048
/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
bool GetWebFile(CString theUrl, CString Filename);
bool GetWebFile(CString theUrl, CString Filename)
{
    CInternetSession session;
    CInternetFile* file = NULL;
    try
    {
        // Try to connect with the URL
        file = (CInternetFile*)session.OpenURL(theUrl); 
    }
    catch (CInternetException* m_pException)
    {
        // if some error occurs, set the file with NULL
        file = NULL; 
        m_pException->Delete();
        return FALSE;
    }

    BOOL bRet = FALSE;
    // use dataStore to save the file content
    CStdioFile dataStore;
    if(dataStore.Open(Filename, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeBinary))
    {
        if (file)
        {
            UINT somelen = 0;
            BYTE somecode[BUFFER_SIZE];
            while((somelen = file->Read(somecode, BUFFER_SIZE)) > 0)
            {
                dataStore.Write(somecode, somelen);
            }
            bRet = TRUE;
        }
        dataStore.Close();
    }
    if(file)
    {
        file->Close();
        delete file;
    }
    return bRet;
}
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
		/*
		FILE *pfGUID;
		CString StrGUID;
		char chrData[500];
		m_StrSTBSTBGUID="\\\\";
		m_StrSTBSTBGUID+=m_StrNowIP;
		m_StrSTBSTBGUID+="\\D$\\NabroClient\\Setting\\Registry\\HKEY_LOCAL_MACHINE\\SOFTWARE\\COMTREND\\NABRO\\Client\\GUID";
		pfGUID=fopen(m_StrSTBSTBGUID.GetBuffer(0),"r"); 
		while(fscanf(pfGUID,"%s",chrData)!=EOF)
		{
			StrGUID=chrData;
		}
		fclose(pfGUID);
		*/
		CString m_URL,m_Name;
		m_URL="http://61.67.120.51:8080/wReport.aspx?OP=SetSTBIP&STBuid=XXXXXXX";
		m_Name="XXX.txt";
		bool blnDownload=false;
		blnDownload=GetWebFile(m_URL,m_Name);
	}

	return nRetCode;
}


