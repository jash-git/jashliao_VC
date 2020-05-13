// CmdPluginLog.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CmdPluginLog.h"
#include <fstream>
#include <afxtempl.h>//CArray Step_01 
#include "NetUsebat.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
CAnalysisPluginDlg(CWnd* pParent = NULL);	// standard constructor
CString HttpFullPath2FileName(CString StrPath);//從全路徑取得檔名
CArray <CString,CString&> m_ArrayStart;//Step 2:CArray//存放來源檔案資料
CArray <CString,CString&> m_ArrayEnd;//Step 2:CArray//存放目的檔案資料
CArray <CString,CString&> m_ArrayStartT;//Step 2:CArray//存放來源檔案資料
CArray <CString,CString&> m_ArrayEndT;//Step 2:CArray//存放目的檔案資料
CArray <CString,CString&> m_ArrayMediaId;//Step 2:CArray//存放目的檔案資料
TCHAR gstrCurDrt[500];//存放目其目錄字串
CString HttpFullPath2FileName(CString StrPath)//從全路徑取得檔名
{
    char   seps[]   =   "/"   ;  
    char   *token   =   NULL; 
    CString StrReturn;
    char exeName[256];

    memset(exeName,'\0',sizeof(exeName));

    token=strtok(StrPath.GetBuffer(0),seps);  
    while(token!=NULL)  
    {  
        sprintf(exeName,"%s",token);
		token=strtok(NULL, seps);              
    }

	StrReturn=exeName;
	return StrReturn;
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;
	AfxSocketInit();//IP_2
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
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		strHello="";
		strHello="Read File...";
		cout << (LPCTSTR)strHello << endl;

		fstream a;
		CString Strfg;
		CString StrfgMid;
		char fg[700];
		//CFileDialog fdlg(true,NULL,"openfile",NULL,"文字|*.txt");
		CString Strfilename;
		CString Strfilelog;
		CString StrCheckBuf;
		CString StrDataBuf;

		////////////////////////////////////////////////////////////
		CString StrEventOpen="WMS_EVENT_OPEN,";
		CString StrRequestName="RequestName=";
		CString StrEventClose="WMS_EVENT_CLOSE,";
		CString StrOpenHttp="Open Http Post Return =";
		CString StrCloseHttp="Close Http Post Return =";

		////////////////////////////////////////////////////////////
		FILE *pfEventOpen=NULL;
		FILE *pfEventClose=NULL;
		FILE *pfOpenHttp=NULL;
		FILE *pfCloseHttp=NULL;

		CTime   cYestodayOnceMore=CTime::GetCurrentTime()-CTimeSpan(1,0,0,0);
		CString StrYestoday=cYestodayOnceMore.Format( "%Y-%m-%d" );
		////////////////////////////////////////////////////////////
		//if(fdlg.DoModal()==IDOK)
		//{
		//DeleteFile("AnalysisPlugin.log");
		//Strfilepath=fdlg.GetPathName();
		//Strfilename=fdlg.GetFileTitle();
		Strfilename=StrYestoday+".txt";
		Strfilelog=StrYestoday+".log";
		CFileFind fFind;
		if(!fFind.FindFile(Strfilename))
		{
			strHello="Not find the log File...";
			cout << (LPCTSTR)strHello << endl;
			Sleep(5000);
			return nRetCode;
		}
		else
		{
			strHello="start Load Data...";
			cout << (LPCTSTR)strHello << endl;
		}
		a.open(Strfilename.GetBuffer(0),ios::in);
		while(!a.eof())
		{
			a.getline(fg,500);
			Strfg=fg;
			/////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrEventOpen.GetLength());
			if(StrEventOpen==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500],Schrd03[500],Schrd04[500],Schrd05[500],Schrd06[500],Schrd07[500],Schrd08[500],Schrd09[500],Schrd10[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd01,Schrd02,Schrd03,Schrd04,Schrd05);
				sscanf (Schrd05 ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd06,Schrd07,Schrd08,Schrd09,Schrd10);
				char Dchrd01[500],Dchrd02[500],Dchrd03[500],Dchrd04[500],Dchrd05[500],Dchrd06[500],Dchrd07[500],Dchrd08[500],Dchrd09[500],Dchrd10[500];
				sscanf (Schrd02,"%[^'=']=%s",Dchrd01,Dchrd02);//抓取路徑
				StrDataBuf=Dchrd02;
				StrDataBuf+=",";
				sscanf (Schrd06,"%[^'=']=%s",Dchrd01,Dchrd05);//協定
				StrDataBuf+=Dchrd05;
				StrDataBuf+=",";
				sscanf (Schrd08,"%[^'=']=%s",Dchrd01,Dchrd07);//IP
				StrDataBuf+=Dchrd07;
				sscanf (Schrd10,"%[^'='],%s",Dchrd10,Dchrd10);//time
				StrDataBuf+=Dchrd10;
				pfEventOpen=fopen("EventOpen.txt","a");
				fprintf(pfEventOpen,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfEventOpen);
			}

			//////////////////////////////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrEventClose.GetLength());
			if(StrEventClose==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500],Schrd03[500],Schrd04[500],Schrd05[500],Schrd06[500],Schrd07[500],Schrd08[500],Schrd09[500],Schrd10[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd01,Schrd02,Schrd03,Schrd04,Schrd05);
				sscanf (Schrd05 ,"%[^','],%[^','],%[^','],%[^','],%s",Schrd06,Schrd07,Schrd08,Schrd09,Schrd10);
				char Dchrd01[500],Dchrd02[500],Dchrd03[500],Dchrd04[500],Dchrd05[500],Dchrd06[500],Dchrd07[500],Dchrd08[500],Dchrd09[500],Dchrd10[500];
				sscanf (Schrd02,"%[^'=']=%s",Dchrd01,Dchrd02);//抓取路徑
				StrDataBuf=Dchrd02;
				StrDataBuf+=",";
				sscanf (Schrd06,"%[^'=']=%s",Dchrd01,Dchrd05);//協定
				StrDataBuf+=Dchrd05;
				StrDataBuf+=",";
				sscanf (Schrd08,"%[^'=']=%s",Dchrd01,Dchrd07);//IP
				StrDataBuf+=Dchrd07;
				sscanf (Schrd10,"%[^'='],%s",Dchrd10,Dchrd10);//time
				StrDataBuf+=Dchrd10;
				pfEventClose=fopen("EventClose.txt","a");
				fprintf(pfEventClose,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfEventClose);
			}

			//////////////////////////////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrOpenHttp.GetLength());
			if(StrOpenHttp==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^'=']=%s",Schrd01,Schrd02);
				StrDataBuf=Schrd02;
				pfOpenHttp=fopen("OpenHttp.txt","a");
				fprintf(pfOpenHttp,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfOpenHttp);
			}

			//////////////////////////////////////////////////////////////////////////
			StrCheckBuf="";
			StrCheckBuf=Strfg.Mid(0,StrCloseHttp.GetLength());
			if(StrCloseHttp==StrCheckBuf)
			{
				char Schrd01[500],Schrd02[500];
				sscanf (Strfg.GetBuffer(0) ,"%[^'=']=%s",Schrd01,Schrd02);
				StrDataBuf=Schrd02;
				pfCloseHttp=fopen("CloseHttp.txt","a");
				fprintf(pfCloseHttp,"%s\n",StrDataBuf.GetBuffer(0));
				fclose(pfCloseHttp);
			}

		}//while(!a.eof())
		a.close();
		//MessageBox("write log01 finish");

		/////////////////////////////////////////////////////////////
		fstream b,c;
		CString StrCompare01,StrCompare02;
		CString StrStartTime,StrEndTime;
		CString StrMediaId;
		m_ArrayStart.RemoveAll();
		m_ArrayEnd.RemoveAll();
		m_ArrayStartT.RemoveAll();
		m_ArrayEndT.RemoveAll();
		m_ArrayMediaId.RemoveAll();
		FILE *pfAnalysisPlugin=NULL;
		bool blnfind=false;
		b.open("EventOpen.txt",ios::in);
		char   *token   =   NULL; 
		char   seps[]   =   ".?"   ;  
		while(!b.eof())
		{
			b.getline(fg,500);
			Strfg=fg;
			StrCompare01=Strfg.Mid(0,(Strfg.GetLength()-20));
			m_ArrayStart.Add(StrCompare01);
			StrStartTime=Strfg.Mid((Strfg.GetLength()-20));
			m_ArrayStartT.Add(StrStartTime);
			StrMediaId=HttpFullPath2FileName(StrCompare01);
			token=strtok(StrMediaId.GetBuffer(0),seps);
			StrMediaId=","+StrMediaId;
			StrMediaId=StrMediaId.Mid(0,(StrMediaId.GetLength()-2));
			m_ArrayMediaId.Add(StrMediaId);

		}//while(!b.eof())
		b.close();

		c.open("EventClose.txt",ios::in);
		while(!c.eof())
		{
			c.getline(fg,500);
			Strfg=fg;
			StrCompare02=Strfg.Mid(0,(Strfg.GetLength()-20));
			m_ArrayEnd.Add(StrCompare02);
			StrEndTime=Strfg.Mid((Strfg.GetLength()-20));
			m_ArrayEndT.Add(StrEndTime);
		}
		c.close();

		int i,j;
		int k,l;
		j=m_ArrayStart.GetSize();
		l=m_ArrayEnd.GetSize();

		for(i=0;i<j;i++)
		{
			blnfind=false;
			StrCompare01=m_ArrayStart.GetAt(i);
			StrStartTime=m_ArrayStartT.GetAt(i);
			StrMediaId=m_ArrayMediaId.GetAt(i);

			for(k=0;k<l;k++)
			{
				StrCompare02=m_ArrayEnd.GetAt(k);
				StrEndTime=m_ArrayEndT.GetAt(k);

				if(StrCompare01==StrCompare02)
				{
					Strfg=StrCompare01+StrStartTime+StrEndTime;
					Strfg+=StrMediaId;
					pfAnalysisPlugin=fopen(Strfilelog.GetBuffer(0),"a");
					fprintf(pfAnalysisPlugin,"%s\n",Strfg.GetBuffer(0));
					fclose(pfAnalysisPlugin);
					blnfind=true;
					break;
				}//if(StrCompare01==StrCompare02)

			}//for(k=0;k<l;k++)

			if(!blnfind)
			{
				blnfind=false;
				Strfg=StrCompare01+StrStartTime;
				Strfg+=",fail";
				Strfg+=StrMediaId;
				pfAnalysisPlugin=fopen(Strfilelog.GetBuffer(0),"a");
				fprintf(pfAnalysisPlugin,"%s\n",Strfg.GetBuffer(0));
				fclose(pfAnalysisPlugin);
			}//if(!blnfind)

			cout << (LPCTSTR)StrMediaId << endl;

		}//for(i=0;i<j;i++)

		//***********************************
		//GetIP
		char szhostname[128];
		CString str;
		int intIP;

		if( gethostname(szhostname, 128) == 0 )
		{

			CString addr;
			struct hostent * phost;
			int i;
			phost = gethostbyname(szhostname);
			i=0;
			int j;
			int h_length=4;
			for( j = 0; j<h_length; j++ )
			{
				
				if( j > 0 )
					str += "_";
				
				addr.Format("%u", (unsigned int)((unsigned
					char*)phost->h_addr_list[i])[j]);

				intIP=(unsigned int)((unsigned char*)phost->h_addr_list[i])[j];
				
				str += addr;
			}
  
		}

		//******************************************************************
		//create & run net use bat
		CString StrNetPath;
		int count;
		StrNetPath="\\\\192.168.0.130\\log\\MMS\\CS_plug_log";
		switch(intIP)
		{
		case 98:
			count=0;
			StrNetPath+="\\TC-MMS01";
			break;
		case 82:
			count=1;
			StrNetPath+="\\TC-MMS02";
			break;
		case 83:
			count=2;
			StrNetPath+="\\TC-MMS03";
			break;
		case 84:
			count=3;
			StrNetPath+="\\TC-MMS04";
			break;
		case 86:
			count=4;
			StrNetPath+="\\TC-MMS05";
			break;
		case 85:
			count=5;
			StrNetPath+="\\TC-MMS06";
			break;
		}
		CNetUsebat NUB;
		NUB.Createbat("mmsuser","iptv-*))(#*#)",StrNetPath,count);
		if(NUB.CreateShareDir())
		{
			StrNetPath+="\\";
			StrNetPath+=Strfilelog;
			int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
			if( gstrCurDrt[nLen]!='\\' )
			{
				gstrCurDrt[nLen++] = '\\';
				gstrCurDrt[nLen] = '\0';
			}
			CString strFileName1 = gstrCurDrt;
			strFileName1 +=Strfilelog;//建立XML檔案路徑
			CopyFile(strFileName1,StrNetPath,false);
		}
		//MessageBox("write log02 finish");
	}//if(fdlg.DoModal()==IDOK)

	DeleteFile("CloseHttp.txt");
	DeleteFile("EventClose.txt");
	DeleteFile("EventOpen.txt");
	DeleteFile("OpenHttp.txt");

	//MessageBox("finish");
	//}//if(fdlg.DoModal()==IDOK)

	return nRetCode;
}


