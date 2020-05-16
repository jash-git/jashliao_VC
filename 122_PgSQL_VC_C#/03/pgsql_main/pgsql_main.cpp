// pgsql_main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "pgsql_main.h"

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
	//////////////////////////////////////////////////////第2步Start
	CDatabase *m_DB;
	CRecordset *m_RS;
	CDatabase *m_DBupdate;
	//////////////////////////////////////////////////////第2步end
	CInternetSession *m_pInetSession; //FTP_2
	CFtpConnection *m_pFtpConnection;
	///////////////////////////////////////////////////////
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
		// TODO: code your application's behavior here.
		//CString strHello;
		//strHello.LoadString(IDS_HELLO);
		//cout << (LPCTSTR)strHello << endl;
		//////////////////////////////////////////////////////第3步Start
		bool checkDB=false;
		int checkRS=false;
		CString d1,d2,d3;
		//CDatabase *m_DB;
		m_DB=new CDatabase();
		d1="NabroWEB";//ODBC名稱
		checkDB=m_DB->Open(d1);
		if(checkDB)
		{
			cout << "DB OK" << endl;
			//CRecordset *m_RS;
			m_RS=new CRecordset(m_DB);
			d2="select uid,filename from tuka where is_file=false and img IS NOT NULL order by uid asc";
			checkRS=m_RS->Open(CRecordset::forwardOnly,d2); 
			if(checkRS)
			{
				cout << "RS OK" << endl;
				int ti=0;
				CString var0,var1,var2;//var可以轉換為其他類型的值
				//CDBVariant var2;
				while (!m_RS->IsEOF())
				{
					//讀取Excel內部數值
					m_RS->GetFieldValue(_T("uid"),var0);
					m_RS->GetFieldValue(_T("filename"),var1);
					cout << (LPCTSTR)var0 << endl;
					cout << (LPCTSTR)var1 << endl;
					CString strBatPath;
					CString strBatCmd;
					FILE *pfBat=NULL;
					strBatPath="pg_sql.bat";
					strBatCmd="pgsql_cmd.exe ";
					strBatCmd+=var0+" ";
					strBatCmd+=var1;
					pfBat=fopen(strBatPath.GetBuffer(0),"w");
					PROCESS_INFORMATION pi;
					STARTUPINFO si;
					memset(&si,0,sizeof(si));
					si.cb=sizeof(si);
					si.wShowWindow=SW_SHOW;
					si.dwFlags=STARTF_USESHOWWINDOW;
					if(pfBat!=NULL)
					{
						fprintf(pfBat,"%s\n",strBatCmd.GetBuffer(0));
						fclose(pfBat);
						BOOL fRet=CreateProcess(NULL,
												strBatPath.GetBuffer(0),
												NULL,
												NULL,
												FALSE,
												NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
												NULL,
												NULL,
												&si,
												&pi);
						if(fRet)   
						{   
							::WaitForSingleObject(pi.hProcess, INFINITE);//等待執行完畢
							////////////////////////////////////////////////////////////////////
							bool blncheck1=false;
							bool blncp1=false;
							m_pInetSession=new CInternetSession (AfxGetAppName(),1, PRE_CONFIG_INTERNET_ACCESS); 
							try 
							{ 
								//m_pFtpConnection=m_pInetSession->GetFtpConnection("FTP.MICROSOFT.COM");
								m_pFtpConnection=m_pInetSession->GetFtpConnection("61.67.120.49","nabroweb","naBro232(",21);
								m_pFtpConnection->SetCurrentDirectory("/public_html/web_tuka/");
								blncheck1=true;
							} 
							catch(CInternetException *pEx) 
							{ 
								blncheck1=false;
								m_pFtpConnection=NULL;
							}
							if(blncheck1)
							{
								blncp1=m_pFtpConnection->PutFile(var1,var1);
								DeleteFile(var1);
								m_pFtpConnection->Close();
							}
							delete m_pInetSession;
							///////////////////////////////////////////////////////////////////////////////
							d3="update tuka set is_file=true where uid=";
							d3=d3+var0;
							m_DBupdate=new CDatabase();
							d1="NabroWEB";//ODBC名稱
							checkDB=m_DBupdate->Open(d1);
							if(checkDB)
							{
								m_DBupdate->ExecuteSQL(d3);
							}
							m_DBupdate->Close();
							delete m_DBupdate;
						}
					}
					ti++;
					m_RS->MoveNext();
				}
				m_RS->Close();
				m_DB->Close();
				delete m_DB;
				delete m_RS;
			}
		}
	}

	return nRetCode;
}


