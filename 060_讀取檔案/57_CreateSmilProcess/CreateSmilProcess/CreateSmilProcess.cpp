// CreateSmilProcess.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "CreateSmilProcess.h"
#include <iostream>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 僅有的一個應用程式物件
using namespace std;
CWinApp theApp;

using namespace std;
void Create_ipad_all(CString StrId)
{
 CString StrFileName;
 StrFileName=StrId+"_ipad_all.smil";
 FILE *pf;
 pf=fopen(StrFileName.GetBuffer(0),"w");
 fprintf(pf,"<smil>\n");
 fprintf(pf,"\t<head>\n");
 fprintf(pf,"\t</head>\n");
 fprintf(pf,"\t<body>\n");
 fprintf(pf,"\t\t<switch>\n");
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_64k.mp4\" system-bitrate=\"64000\"  wowza-audio-only=\"true\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_150k.mp4\" system-bitrate=\"150000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_240k.mp4\" system-bitrate=\"240000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_440k.mp4\" system-bitrate=\"440000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_h640k.mp4\" system-bitrate=\"664000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_840k.mp4\" system-bitrate=\"864000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_1240k.mp4\" system-bitrate=\"1264000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t</switch>\n");
 fprintf(pf,"\t</body>\n");
 fprintf(pf,"</smil>\n");
 fclose(pf);
}
void Create_ipad_cell(CString StrId)
{
 CString StrFileName;
 StrFileName=StrId+"_ipad_cell.smil";
 FILE *pf;
 pf=fopen(StrFileName.GetBuffer(0),"w");
 fprintf(pf,"<smil>\n");
 fprintf(pf,"\t<head>\n");
 fprintf(pf,"\t</head>\n");
 fprintf(pf,"\t<body>\n");
 fprintf(pf,"\t\t<switch>\n");
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_64k.mp4\" system-bitrate=\"64000\"  wowza-audio-only=\"true\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_150k.mp4\" system-bitrate=\"150000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_240k.mp4\" system-bitrate=\"240000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_440k.mp4\" system-bitrate=\"440000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t</switch>\n");
 fprintf(pf,"\t</body>\n");
 fprintf(pf,"</smil>\n");
 fclose(pf);
}
void Create_ipad_wifi(CString StrId)
{
 CString StrFileName;
 StrFileName=StrId+"_ipad_wifi.smil";
 FILE *pf;
 pf=fopen(StrFileName.GetBuffer(0),"w");
 fprintf(pf,"<smil>\n");
 fprintf(pf,"\t<head>\n");
 fprintf(pf,"\t</head>\n");
 fprintf(pf,"\t<body>\n");
 fprintf(pf,"\t\t<switch>\n");
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_h640k.mp4\" system-bitrate=\"664000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_840k.mp4\" system-bitrate=\"864000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_1240k.mp4\" system-bitrate=\"1264000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t</switch>\n");
 fprintf(pf,"\t</body>\n");
 fprintf(pf,"</smil>\n");
 fclose(pf);
}
void Create_iphone_all(CString StrId)
{
 CString StrFileName;
 StrFileName=StrId+"_iphone_all.smil";
 FILE *pf;
 pf=fopen(StrFileName.GetBuffer(0),"w");
 fprintf(pf,"<smil>\n");
 fprintf(pf,"\t<head>\n");
 fprintf(pf,"\t</head>\n");
 fprintf(pf,"\t<body>\n");
 fprintf(pf,"\t\t<switch>\n");
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_64k.mp4\" system-bitrate=\"64000\"  wowza-audio-only=\"true\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_150k.mp4\" system-bitrate=\"150000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_240k.mp4\" system-bitrate=\"240000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_440k.mp4\" system-bitrate=\"440000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_640k.mp4\" system-bitrate=\"640000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t</switch>\n");
 fprintf(pf,"\t</body>\n");
 fprintf(pf,"</smil>\n");
 fclose(pf);
}
void Create_iphone_cell(CString StrId)
{
 CString StrFileName;
 StrFileName=StrId+"_iphone_cell.smil";
 FILE *pf;
 pf=fopen(StrFileName.GetBuffer(0),"w");
 fprintf(pf,"<smil>\n");
 fprintf(pf,"\t<head>\n");
 fprintf(pf,"\t</head>\n");
 fprintf(pf,"\t<body>\n");
 fprintf(pf,"\t\t<switch>\n");
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_64k.mp4\" system-bitrate=\"64000\"  wowza-audio-only=\"true\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_150k.mp4\" system-bitrate=\"150000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_240k.mp4\" system-bitrate=\"240000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t</switch>\n");
 fprintf(pf,"\t</body>\n");
 fprintf(pf,"</smil>\n");
 fclose(pf);
}
void Create_iphone_wifi(CString StrId)
{
 CString StrFileName;
 StrFileName=StrId+"_iphone_wifi.smil";
 FILE *pf;
 pf=fopen(StrFileName.GetBuffer(0),"w");
 fprintf(pf,"<smil>\n");
 fprintf(pf,"\t<head>\n");
 fprintf(pf,"\t</head>\n");
 fprintf(pf,"\t<body>\n");
 fprintf(pf,"\t\t<switch>\n");
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_440k.mp4\" system-bitrate=\"440000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t\t<video src=\"mp4:../videos/%s_640k.mp4\" system-bitrate=\"640000\"/>\n",StrId.GetBuffer(0));
 fprintf(pf,"\t\t</switch>\n");
 fprintf(pf,"\t</body>\n");
 fprintf(pf,"</smil>\n");
 fclose(pf);
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// 初始化 MFC 並於失敗時列印錯誤
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 配合您的需要變更錯誤碼
		_tprintf(_T("嚴重錯誤: MFC 初始化失敗\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: 在此撰寫應用程式行為的程式碼。
		int intswitch;
		char strFileName[100];
		cout <<"Input Media ID\t";
		cin >> strFileName;
		cout << "Media ID = " <<strFileName <<"\n";
		cout <<"Select Smils (0)ipad_all\t(1)ipad_cell\t(2)ipad_wifi\n\t\t(3)iphone_all\t(4)iphone_cell\t(5)iphone_wifi\t";;
		cin >>intswitch;
		switch(intswitch)
		{
		case 0://ipad_all
			Create_ipad_all(strFileName);
			break;
		case 1://ipad_cell
			Create_ipad_cell(strFileName);
			break;
		case 2://ipad_wifi
			Create_ipad_wifi(strFileName);
			break;
		case 3://iphone_all
			Create_iphone_all(strFileName);
			break;
		case 4://iphone_cell
			Create_iphone_cell(strFileName);
			break;
		case 5://iphone_wifi
			Create_iphone_wifi(strFileName);
			break;
		default:
			Create_ipad_all(strFileName);
			Create_ipad_cell(strFileName);
			Create_ipad_wifi(strFileName);
			Create_iphone_all(strFileName);
			Create_iphone_cell(strFileName);
			Create_iphone_wifi(strFileName);
		}
	}

	return nRetCode;
}
