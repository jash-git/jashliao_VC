// DaAi_Bodhi.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DaAi_Bodhi.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;
CInternetSession *m_pInetSession; //FTP_2
CFtpConnection *m_pFtpConnection; 
CString m_StrServerName,m_StrUserName,m_StrPassWord;
bool gblnConnet=false;
CStringArray m_Dir; 
TCHAR gstrCurDrt[500];//存放目其目錄字串
int gintcallback02count=0;
int gintRowNumber=0;
using namespace std;
CString m_Strid,m_StrFileName,m_StrIsGet;
static int _sql_callback02(void * notused, int argc, char ** argv, char ** szColName);
CString StrSPath_1000k,StrDPath_1000k;
CString StrSPath_500k,StrDPath_500k;
CString StrDelMov,StrDelMpg,StrDel1000K,StrDel500K;
CString StrMediaID;
void printTitleInformation()
{
	CTime t = CTime::GetCurrentTime();
	cout<<"====================================="<<endl;
	cout<<endl;
	cout<<"大愛 人間菩提 影片下載/轉檔/歸檔 系統"<<endl;
	cout<<endl;
	cout<<"目前時間: ";
	cout << (LPCTSTR)(t.Format( "%Y/%m/%d %H:%M:%S"))<< endl;
	cout<<endl;
	cout<<"======================================"<<endl;
}
void CreateBat()
{
	CString StrFTPBat;
	CString Strecho00="echo 0 > BatState.txt";
	CString Strecho01="echo 1 > BatState.txt";
	CString StrFFmpeg;
	CString Strecho02="echo 2 > BatState.txt";
	CString StrWME1000K;
	CString StrWME500K;
	CString Strecho03="echo 3 > BatState.txt";
	CTime t = CTime::GetCurrentTime();
	FILE *pf=NULL;
	StrFTPBat="wget -c ftp://skylink:skylink2008@60.248.192.140/%%E4%%BA%%BA%%E9%%96%%93%%E8%%8F%%A9%%E6%%8F%%90/";
	StrFTPBat+=m_StrFileName;
	pf=fopen("DaAi.bat","w");
	fprintf(pf,"%s\n",Strecho00.GetBuffer(0));
	fprintf(pf,"%s\n",StrFTPBat.GetBuffer(0));
	fprintf(pf,"%s\n",Strecho01.GetBuffer(0));

	StrFFmpeg="ffmpeg.exe -i ";
	StrFFmpeg+=m_StrFileName;
	StrFFmpeg+=" -deinterlace -target ntsc-dvd -ab 128k -aspect 4:3 -s 720x480 ";
	StrFFmpeg+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrFFmpeg+=".mpg";
	fprintf(pf,"%s\n",StrFFmpeg.GetBuffer(0));
	fprintf(pf,"%s\n",Strecho02.GetBuffer(0));

	StrWME1000K="cscript.exe wmcmd.vbs -input ";
	StrWME1000K+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrWME1000K+=".mpg";
	StrWME1000K+=" -output ";
	StrWME1000K+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrWME1000K+="_1000K.wmv -loadprofile 1000k.prx";
	fprintf(pf,"%s\n",StrWME1000K.GetBuffer(0));
	//**
	StrSPath_1000k=gstrCurDrt;
	StrSPath_1000k+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrSPath_1000k+="_1000K.wmv";
	StrDPath_1000k="\\\\192.168.0.66\\puti\\";
	StrDPath_1000k+="daai_";
	StrDPath_1000k+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrDPath_1000k+="01.wmv";

	
	StrWME500K="cscript.exe wmcmd.vbs -input ";
	StrWME500K+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrWME500K+=".mpg";
	StrWME500K+=" -output ";
	StrWME500K+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrWME500K+="_500K.wmv -loadprofile 500k.prx";
	fprintf(pf,"%s\n",StrWME500K.GetBuffer(0));
	//**
	StrSPath_500k=gstrCurDrt;
	StrSPath_500k+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrSPath_500k+="_500K.wmv";
	StrDPath_500k="\\\\192.168.0.66\\puti\\500k\\";
	StrDPath_500k+="daai_";
	StrDPath_500k+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrDPath_500k+="01.wmv";

	StrMediaID="daai_";
	StrMediaID+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrMediaID+="01";

	StrDelMov=gstrCurDrt;
	StrDelMpg=gstrCurDrt;
	StrDel1000K=gstrCurDrt;
	StrDel500K=gstrCurDrt;
	StrDelMov+=m_StrFileName;
	StrDelMpg+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrDel1000K+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrDel500K+=m_StrFileName.Mid(0,m_StrFileName.Find(".mov"));
	StrDelMpg+=".mpg";
	StrDel1000K+="_1000K.wmv";
	StrDel500K+="_500K.wmv";

	fprintf(pf,"%s\n",Strecho03.GetBuffer(0));
	fclose(pf);
}
int ReadState()
{
	FILE *pf=NULL;
	int intstate=-1;
	pf=fopen("BatState.txt","r");
	if(pf)
	{
		fscanf(pf,"%d",&intstate);
	}
	fclose(pf);
	return intstate;
}
void GetSettingData()
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMNodePtr   pNode;
	_variant_t vtStr;
	bool blnRead=false;
	CString StrValue;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="FTPSetting.dat";
	blnRead=pDoc->load((_bstr_t)strFileName1); 
	if(blnRead)//第11.0版的功能
	{
		pNode=pDoc->selectSingleNode("//SERVERNAME");
		pNode->get_nodeTypedValue(&vtStr);  
		StrValue=vtStr.bstrVal;
		m_StrServerName=StrValue;
		//************************************************
		pNode=pDoc->selectSingleNode("//USERNAME");
		pNode->get_nodeTypedValue(&vtStr);  
		StrValue=vtStr.bstrVal;
		m_StrUserName=StrValue;
		//************************************************
		pNode=pDoc->selectSingleNode("//PassWord");
		pNode->get_nodeTypedValue(&vtStr);  
		StrValue=vtStr.bstrVal;
		m_StrPassWord=StrValue;
		//************************************************
	}
}
BOOL GetFTPList()
{
	GetSettingData();//Get FTP Server Information
	m_pInetSession=new CInternetSession (AfxGetAppName(),1, PRE_CONFIG_INTERNET_ACCESS);
	CString StrDownLoadFileName,StrBuf;
	FILE *pf1=NULL;
	CTime t1=CTime::GetCurrentTime();
	StrDownLoadFileName=t1.Format( "%Y%m%d" );
	StrDownLoadFileName="Log\\FTP_"+StrDownLoadFileName;
	StrDownLoadFileName+=".txt";
	pf1=fopen(StrDownLoadFileName.GetBuffer(0),"w");
	try 
	{ 
		m_pFtpConnection=m_pInetSession->GetFtpConnection(m_StrServerName,m_StrUserName,m_StrPassWord);
		///////////////////////////////////////////////////////////
		t1=t1.GetCurrentTime();
		StrBuf=t1.Format("%Y%m%d%H%M%S");
		StrBuf+=";;Connect success;;";
		fprintf(pf1,"%s\n",StrBuf.GetBuffer(0)); 
		///////////////////////////////////////////////////////////
		//MessageBox("OK_01");
		gblnConnet=true;
	} 
	catch(CInternetException *pEx) 
	{ 
		TCHAR szError[1024]; 
		pEx->GetErrorMessage(szError,1024); 
		pEx->Delete(); 
		m_pFtpConnection=NULL;
		///////////////////////////////////////////////
		t1=t1.GetCurrentTime();
		StrBuf=t1.Format("%Y%m%d%H%M%S");
		StrBuf+=";;Connect faill;;";
		fprintf(pf1,"%s\n",StrBuf.GetBuffer(0));
		//////////////////////////////////////////////
		delete m_pFtpConnection; 
		fclose(pf1);
		delete m_pInetSession;
		gblnConnet=false;
		return FALSE;
	}		
	
	//big5->unicode
	char *sendbuf="人間菩提";
	wchar_t *sendwbuf;
	char *sendbuf_utf8;
	int len;
	len=MultiByteToWideChar (CP_ACP, 0, sendbuf, -1, NULL,0) ;
	sendwbuf=new wchar_t[len+1];
	MultiByteToWideChar(CP_ACP, 0, sendbuf, -1, sendwbuf, len);
	//unicode->UTF-8
	len=WideCharToMultiByte (CP_UTF8, 0, sendwbuf, -1, NULL,0 ,NULL, NULL);
	sendbuf_utf8=new char[len+1];
	WideCharToMultiByte (CP_UTF8, 0, sendwbuf, -1, sendbuf_utf8,len, NULL, NULL);
	bool blncd=m_pFtpConnection->SetCurrentDirectory(sendbuf_utf8);
	
	CFtpFileFind finder(m_pFtpConnection); 
	BOOL bWorking=finder.FindFile("*");
	while(bWorking) 
	{ 
		bWorking=finder.FindNextFile(); 
      	if(finder.IsDots()) 
			continue; 
		if(finder.IsHidden())
			continue; 
		if(!finder.IsDirectory()) 
		{
			StrBuf=finder.GetFileName();
			if((StrBuf.Find(".mov")>0))
    			m_Dir.Add(StrBuf); 
		} 
	}
	finder.Close(); 
	for(int i=0;i<m_Dir.GetSize();i++) 
	{
		StrBuf=m_Dir.GetAt(i);
		fprintf(pf1,"%s\n",StrBuf.GetBuffer(0));
	}
	if(m_pFtpConnection!=NULL) 
	{ 
		m_pFtpConnection->Close();
		///////////////////////////////////////////////
		t1=t1.GetCurrentTime();
		StrBuf=t1.Format("%Y%m%d%H%M%S");
		StrBuf+=";;DisConnect success;;";
		fprintf(pf1,"%s\n",StrBuf.GetBuffer(0));
		//////////////////////////////////////////////		
		delete m_pFtpConnection; 
		fclose(pf1);
		delete m_pInetSession;
	} 
	delete [] sendwbuf;
	delete [] sendbuf_utf8;
	return TRUE;
}
int _sql_callback02(void * notused01, int argc01, char ** argv01, char ** szColName01)
{
	gintcallback02count=0;
	gintcallback02count=argc01;
	return 0;
}
BOOL WriteSQLite()
{
	const char * sSQL1 = "create table Bodhi(id INTEGER PRIMARY KEY,FileName varchar(500),IsGet INTEGER);";
	CString StrSQL02;
	CString StrSQL03;
	sqlite3 * db = 0;
	char * pErrMsg = 0;
	int ret = 0;    
	// 連結資料庫
	CFileFind fFind;
	if(!fFind.FindFile("DaAi_Bodhi.db"))
	{
		ret = sqlite3_open("./DaAi_Bodhi.db", &db);
		if ( ret != SQLITE_OK )
		{
			return FALSE;
		}
		sqlite3_exec( db, sSQL1, 0, 0, &pErrMsg );
		if ( ret != SQLITE_OK )
		{
			sqlite3_free(pErrMsg);
			return FALSE;
		}
		sqlite3_close(db);
		db = 0;
	}

	ret = sqlite3_open("./DaAi_Bodhi.db", &db);
	if ( ret != SQLITE_OK )
	{
		return FALSE;
	}
	for(int i=0;i<m_Dir.GetSize();i++) 
	{
		StrSQL02.Format("insert into Bodhi values(null,'%s',0);",m_Dir.GetAt(i));
		StrSQL03.Format("select * from Bodhi WHERE FileName = '%s';",m_Dir.GetAt(i));
		gintcallback02count=0;
		sqlite3_exec( db, StrSQL03.GetBuffer(0), _sql_callback02, 0, &pErrMsg);
		if(gintcallback02count<=0)
			sqlite3_exec( db, StrSQL02.GetBuffer(0), 0, 0, &pErrMsg);
	}
	sqlite3_close(db);
	db = 0;
	return TRUE;
}
static int _sql_callback(void * notused, int argc, char ** argv, char ** szColName)
{
	//m_Strid,m_StrFileName,m_StrIsGet
	gintcallback02count=0;
	if(argc>0)
	{
		gintcallback02count=argc;
		m_Strid=argv[0];
		m_StrFileName=argv[1];
		m_StrIsGet=argv[2];
	}
	else
	{
		m_Strid="";
		m_StrFileName="";
		m_StrIsGet="";
	}
    return 0;
}
BOOL ReadSQLite()
{
	//select * from Bodhi where IsGet=0 ORDER BY FileName DESC;
	sqlite3 * db = 0;
	char * pErrMsg = 0;
	int ret = 0;
    const char * sSQL1 = "select * from Bodhi where IsGet=0 ORDER BY FileName;";
	gintcallback02count=0;
	ret = sqlite3_open("./DaAi_Bodhi.db", &db);
	m_Strid="";
	m_StrFileName="";
	m_StrIsGet="";
	if ( ret != SQLITE_OK )
	{
		return FALSE;
	}
	gintRowNumber=3;
	sqlite3_exec( db, sSQL1, _sql_callback, 0, &pErrMsg);
	sqlite3_close(db);
	db = 0;
	return TRUE;
}
void UpdateSQLite()
{
	sqlite3 * db = 0;
	char * pErrMsg = 0;
	int ret = 0;
	ret = sqlite3_open("./DaAi_Bodhi.db", &db);
	//update Bodhi set IsGet=1 where id=60;
	CString StrSQL;
	StrSQL.Format("update Bodhi set IsGet=1 where id=%s;",m_Strid);
	sqlite3_exec( db, StrSQL.GetBuffer(0), 0, 0, &pErrMsg);
	sqlite3_close(db);
	db = 0;
	m_Strid="";
}
BOOL OnlyOneCheck()
{
	FILE *pf=NULL;
	int intstate=4;
	pf=fopen("BatState.txt","r");
	if(pf)
	{
		fscanf(pf,"%d",&intstate);
		fclose(pf);
	}
	else
	{
		intstate=4;
	}
	if(intstate<4)
	{
		return TRUE;//RUN
	}
	else
	{
		return FALSE;//Not RUN
	}
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	bool blncheckcopy01,blncheckcopy02;
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
		//CString strHello;
		//strHello.LoadString(IDS_HELLO);
		//cout << (LPCTSTR)strHello << endl;
		//////////////////////////////////////////////////
		
		if (!AfxSocketInit())
		{
			return FALSE;
		}
		::CoInitialize(NULL); //step 讀取XML2
		//////////////////////////////////////////////
		if(OnlyOneCheck())
		{
			return FALSE;		
		}
		///*
		bool blnfinish=false;
		int intstate=0;
		DWORD dwFlags;
		CString StrUpDB;
		CString StrCallWeb;
		CTime ts=CTime::GetCurrentTime();
		do
		{
			system("cls");
			printTitleInformation();
			switch(intstate)
			{
				case 0:// create/run bat
					cout<<"準備開始工作 ..."<<endl;
					//InternetCheckConnection("http://noc.tw-airnet.net/monitor/wService.aspx?OP=KeepaLive&ServiceID=330",FLAG_ICC_FORCE_CONNECTION,dwFlags);
					ShellExecute(NULL,"open","KeepaLive.bat",NULL,NULL,SW_MINIMIZE); 
					if(!GetFTPList())
					{
						return FALSE;
					}
					if(!WriteSQLite())
					{
						return FALSE;
					}
					if(!ReadSQLite())
					{
						return FALSE;
					}
					if(m_Strid!="")
					{
						CreateBat();
						ShellExecute(NULL,"open","DaAi.bat",NULL,NULL,SW_MINIMIZE); 
						intstate=1;
					}
					else
					{
						intstate=6;//無資料
					}
					break;
				case 1://download
					//InternetCheckConnection("http://noc.tw-airnet.net/monitor/wService.aspx?OP=KeepaLive&ServiceID=330",FLAG_ICC_FORCE_CONNECTION,dwFlags);
					ShellExecute(NULL,"open","KeepaLive.bat",NULL,NULL,SW_MINIMIZE);  					
					if(ReadState()==0)
					{
						cout<<"檔案下載中 ..."<<endl;
					}
					else
					{
						cout<<"準備ffmpeg轉檔..."<<endl;
						intstate=2;
					}
					break;
				case 2://ffmpeg
					//InternetCheckConnection("http://noc.tw-airnet.net/monitor/wService.aspx?OP=KeepaLive&ServiceID=330",FLAG_ICC_FORCE_CONNECTION,dwFlags);
					ShellExecute(NULL,"open","KeepaLive.bat",NULL,NULL,SW_MINIMIZE);  					
					if(ReadState()==1)
					{
						cout<<"ffmpeg轉檔中..."<<endl;
					}
					else
					{
						cout<<"準備WME轉檔..."<<endl;
						intstate=3;
					}
					break;
				case 3://wme
					//InternetCheckConnection("http://noc.tw-airnet.net/monitor/wService.aspx?OP=KeepaLive&ServiceID=330",FLAG_ICC_FORCE_CONNECTION,dwFlags);
					ShellExecute(NULL,"open","KeepaLive.bat",NULL,NULL,SW_MINIMIZE);  
					if(ReadState()==2)
					{
						cout<<"WME轉檔中..."<<endl;
					}
					else
					{
						cout<<"準備複製檔案..."<<endl;
						intstate=4;
					}
					break;
				case 4:// copy file
					blncheckcopy01=false;
					blncheckcopy02=false;
					//InternetCheckConnection("http://noc.tw-airnet.net/monitor/wService.aspx?OP=KeepaLive&ServiceID=330",FLAG_ICC_FORCE_CONNECTION,dwFlags);
					ShellExecute(NULL,"open","KeepaLive.bat",NULL,NULL,SW_MINIMIZE);  
					blncheckcopy01=CopyFile(StrSPath_1000k,StrDPath_1000k,FALSE);
					blncheckcopy02=CopyFile(StrSPath_500k,StrDPath_500k,FALSE);
					if(blncheckcopy01 && blncheckcopy02)
					{
						DeleteFile(StrDelMov);
						DeleteFile(StrDelMpg);
						DeleteFile(StrDel1000K);
						DeleteFile(StrDel500K);
						ShellExecute(NULL,"open","updatevalue.bat",NULL,NULL,SW_MINIMIZE);  
						//InternetCheckConnection("http://noc.tw-airnet.net/monitor/wService.aspx?OP=SetServiceStatusByID&ServiceID=330&Status=0&Value=1",FLAG_ICC_FORCE_CONNECTION,dwFlags);
					}
					cout<<"WME複製檔案中..."<<endl;
					intstate=5;
					break;
				case 5:// update DB
					//CString StrUpDB="http://noc.tw-airnet.net/monitor/wService.aspx?OP=ScanMediaByID&MediaID=20120229&DirName=daai&Year=2012";
					StrUpDB="http://encSrv.5tv.pri/wService.aspx?OP=ScanMediaByID&MediaID=";
					StrUpDB+=StrMediaID;
					StrUpDB+="&DirName=daai_movie&Year=";
					StrUpDB+=ts.Format("%Y");
					StrUpDB+="\"";
					//InternetCheckConnection(StrUpDB,FLAG_ICC_FORCE_CONNECTION,dwFlags);
					StrCallWeb="wget \"";
					StrCallWeb+=StrUpDB;
					FILE *pf01;
					pf01=fopen("updb.bat","w");
					fprintf(pf01,"%s",StrCallWeb.GetBuffer(0));
					fclose(pf01);
					ShellExecute(NULL,"open","updb.bat",NULL,NULL,SW_MINIMIZE); 
					UpdateSQLite();
					cout<<"更薪資料庫..."<<endl;
					intstate=6;
					break;
				case 6:// close
					blnfinish=true;
					cout<<"所有步驟完成，準備關閉..."<<endl;
					FILE *pf=NULL;
					int intstate=4;
					pf=fopen("BatState.txt","w");
					if(pf)
					{
						fprintf(pf,"%d",intstate);
						fclose(pf);
					}
					break;
			}
			Sleep(60000);
		}while(!blnfinish);
		//*/
	}
	return nRetCode;
}


