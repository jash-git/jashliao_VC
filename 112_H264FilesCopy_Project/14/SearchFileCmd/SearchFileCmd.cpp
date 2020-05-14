// SearchFileCmd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SearchFileCmd.h"
#include <afxtempl.h>//CArray Step_01 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
CArray <CString,CString&> m_ArrayStrFileName;
CArray <CString,CString&> m_ArrayStrSortBase;
void SearchFile(CString strDir,CString strFile);
void InitSortBase(CString strFile);
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
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		cout << (LPCTSTR)strHello << endl;
		*/
		CString StrPath,StrName;
		CString StrBuffer;
		CString StrSmilPath;
		CString StrBase;
		CString StrData;
		CString StrSmil;
		int intcheck=0;
		FILE *pf;
		int i,j,k;
		if(argc>2)
		{
			StrPath=argv[1];
			StrName=argv[2];
			StrSmilPath=StrPath.Mid(0,StrPath.Find("videos\\"));
			m_ArrayStrFileName.RemoveAll();
			cout << "搜尋路徑=\t"<<(LPCTSTR)StrPath << endl;
			cout << "搜尋Smil路徑=\t"<<(LPCTSTR)StrSmilPath << endl;
			cout << "搜尋檔名=\t"<<(LPCTSTR)StrName << endl;
			InitSortBase(StrName);
			SearchFile(StrPath,StrName);
			k=m_ArrayStrFileName.GetSize();
			StrBuffer=StrName+"_tv_all.smil";

			pf=fopen((LPCTSTR)StrBuffer,"w");
			fprintf(pf,"<smil>\n\t\t<head>\n\t\t</head>\n\t\t<body>\n\t\t\t<switch>\n");
			for(i=0;i<20;i++)
			{
				intcheck=0;
				StrBase=m_ArrayStrSortBase.GetAt(i);
				for(j=0;j<k;j++)
				{
					StrData=m_ArrayStrFileName.GetAt(j);
					if(StrBase==StrData)
					{
						intcheck=1;
						break;
					}
				}
				if(intcheck==1)
				{
					//fprintf(pf,"%s\n",(LPCTSTR)StrData);
					StrSmil="\t\t\t\t<video src=\"mp4:videos/";
					switch(i)
					{
					case 0://150K
					case 1:
						//StrSmil+=StrData;
						//StrSmil+="\" system-bitrate=\"150000\" wowza-audio-only=\"true\"/>";
						//fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						StrSmil="\t\t\t\t<video src=\"mp4:videos/";
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"150000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					case 2://240K
					case 3:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"240000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					case 4://440K
					case 5:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"440000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					//case 6://640K
					//case 7:
					case 8:
					case 9:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"640000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					case 10://840K
					case 11:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"840000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					case 12://1240K
					case 13:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"1240000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					case 14://1840K
					case 15:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"1840000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					case 16://2540K
					case 17:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"2540000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					case 18://4540K
					case 19:
						StrSmil+=StrData;
						StrSmil+="\" system-bitrate=\"4540000\" />";
						fprintf(pf,"%s\n",(LPCTSTR)StrSmil);
						break;
					}
				}
			}
			fprintf(pf,"\t\t\t</switch>\n\t\t</body>\n</smil>\n");
			fclose(pf);

			StrBuffer=StrName+"_tv_all.smil";
			StrSmilPath+=StrBuffer;
			
			::CopyFile(StrBuffer,StrSmilPath,false);
			::DeleteFile(StrBuffer);
		}
		else
		{
			StrPath=StrName="參數不足";
			cout << (LPCTSTR)StrPath << endl;
		}
	}

	return nRetCode;
}
void InitSortBase(CString strFile)
{
	CString StrBuf;
	m_ArrayStrSortBase.RemoveAll();
	//========00
	StrBuf=strFile;
	StrBuf+="_150k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========01
	StrBuf=strFile;
	StrBuf+="_w150k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========02
	StrBuf=strFile;
	StrBuf+="_240k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========03
	StrBuf=strFile;
	StrBuf+="_w240k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========04
	StrBuf=strFile;
	StrBuf+="_440k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========05
	StrBuf=strFile;
	StrBuf+="_w440k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========06
	StrBuf=strFile;
	StrBuf+="_640k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========07
	StrBuf=strFile;
	StrBuf+="_w640k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========08
	StrBuf=strFile;
	StrBuf+="_h640k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========09
	StrBuf=strFile;
	StrBuf+="_wh640k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========10
	StrBuf=strFile;
	StrBuf+="_840k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========11
	StrBuf=strFile;
	StrBuf+="_w840k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========12
	StrBuf=strFile;
	StrBuf+="_1240k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========13
	StrBuf=strFile;
	StrBuf+="_w1240k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========14
	StrBuf=strFile;
	StrBuf+="_1840k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========15
	StrBuf=strFile;
	StrBuf+="_w1840k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========16
	StrBuf=strFile;
	StrBuf+="_2540k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========17
	StrBuf=strFile;
	StrBuf+="_w2540k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========18
	StrBuf=strFile;
	StrBuf+="_4540k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);
	//========19
	StrBuf=strFile;
	StrBuf+="_w4540k.mp4";
	m_ArrayStrSortBase.Add(StrBuf);

}
void SearchFile(CString strDir,CString strFile)
{
	CFileFind ff;
	CString szDir = strDir;

	strFile.MakeLower();
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += "*.*";
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		CString StrFileName=ff.GetFileName();
		StrFileName.MakeLower();
		int intf=StrFileName.Find(strFile.GetBuffer(0));
		if(intf>=0)
		{
			m_ArrayStrFileName.Add(StrFileName);
		}
		if(ff.IsDirectory() && !ff.IsDots())
		{

			SearchFile(ff.GetFilePath(),strFile);
		}
	}
	ff.Close();

}

