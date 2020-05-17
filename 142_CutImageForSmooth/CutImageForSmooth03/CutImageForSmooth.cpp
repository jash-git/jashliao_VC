// CutImageForSmooth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CutImageForSmooth.h"
//========================
#include <windows.h>

#include <iostream>
#include<fstream>//7
#include <stdlib.h> //srand() ,rand() ,system()
#include <time.h>   //time()
#include <atlbase.h>
#include <afxtempl.h>//CArray Step_01 
using namespace std;
//========================
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
//===============
extern "C" WINBASEAPI HWND WINAPI GetConsoleWindow ();//取得視窗API宣告
void CALLBACK TimeProc( HWND hwnd, UINT message, UINT idTimer, DWORD dwTime);//TIMER函數宣告

TCHAR gstrCurDrt[500];//存放目其目錄字串
/////////////////////////////////////////////////////////////////////////////
// The one and only application object
// 判斷目錄是否存在   
BOOL FolderExists(CString s)   
{  
	DWORD attr;    
	attr = GetFileAttributes(s);    
    return (attr != (DWORD)(-1) ) && ( attr & FILE_ATTRIBUTE_DIRECTORY);    
} 

BOOL CreateMuliteDirectory(CString P)   
{   
	int len=P.GetLength();   
	if ( len <2 ) return false;    
	if('\\'==P[len-1])  
	{  
		P=P.Left(len-1);  
		len=P.GetLength();  
    }  
    if ( len <=0 )
		return false;  
	if (len <=3)   
	{  
		if (FolderExists(P))
			return true;  
		else 
			return false;   
    }  
	if (FolderExists(P))
		return true;

	CString Parent;  
	Parent=P.Left(P.ReverseFind('\\'));
	if(Parent.GetLength()<=0)
		return false;

	BOOL Ret=CreateMuliteDirectory(Parent);    
    if(Ret)    
	{   
		SECURITY_ATTRIBUTES sa;   
		sa.nLength=sizeof(SECURITY_ATTRIBUTES);   
		sa.lpSecurityDescriptor=NULL;   
		sa.bInheritHandle=0;   
		Ret=(CreateDirectory(P,&sa)==TRUE);   
		return Ret;   
	}  
    else  
		return FALSE;   
}
CString Parser_Movie_Duration()
{
	CString StrHalfSec;
    FILE *pf;
    int i=0;
    char chrfind[]="Duration:";
    char *pchrget='\0';
    char buf[513];
    char buf0[50],buf1[50],buf2[50],buf3[50],buf4[50],buf5[50];
    int intHr,intMin,intSec,intmSec;
    int intAllSec;
    int intHalfSec;
    //----------------------------
    //__純C一行一行讀取檔案內容_start
    pf=fopen("info1.txt","r");
    while(fgets(buf,512,pf) != NULL)
    //__純C一行一行讀取檔案內容_end
    //----------------------------
    {
        buf[strlen(buf)-1]='\0';//刪除換行
        //printf("%s\n",buf);//直接印出每一行資訊
        //----------------------------
        //__搜尋檔案內有Duration字串_start
        pchrget='\0';
        pchrget=strstr(buf,chrfind);
        if(pchrget!='\0')
        {
            printf("%s\n",buf);
            break;
        }
        //__搜尋檔案內有Duration字串_end
        //----------------------------
    }
	fclose(pf);
	pf='\0';
    //----------------------------
    //__搜尋檔案內有Duration字串_start
    //----------------------------
    //__計算影片長度的一半_start
    sscanf (buf ,"%[^:]:%[^:]:%[^:]:%[^.].%[^,],%s",buf0,buf1,buf2,buf3,buf4,buf5);
    //printf("%s\n%s\n%s\n%s\n",buf1,buf2,buf3,buf4);
    intHr=atoi(buf1);
    intMin=atoi(buf2);
    intSec=atoi(buf3);
    intmSec=atoi(buf4);
    //printf("%d\n%d\n%d\n%d\n",intHr,intMin,intSec,intmSec);
    intAllSec=intHr*60*60+intMin*60+intSec;
    printf("AllSec=%d\n",intAllSec);
    intHalfSec=intAllSec/2;
    printf("HalfSec=%d\n",intHalfSec);
    intHr=intHalfSec/(60*60);
    intMin=(intHalfSec-(intHr*(60*60)))/60;
    intSec=(intHalfSec-(intHr*(60*60))-(intMin*60));
    printf("%d:%d:%d",intHr,intMin,intSec);
    //__計算影片長度的一半_start
    StrHalfSec.Format("%d",intHalfSec);
	return StrHalfSec;
}
////////////////////////////
CWinApp theApp;

using namespace std;
UINT_PTR nTimer;
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
		CString strHello;
		strHello.LoadString(IDS_HELLO);
		int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
		if( gstrCurDrt[nLen]!='\\' )
		{
			gstrCurDrt[nLen++] = '\\';
			gstrCurDrt[nLen] = '\0';
		}
		//cout << (LPCTSTR)strHello << endl;
		//HWND hWnd = ::GetConsoleWindow();//取得視窗HAND
		//::ShowWindow( hWnd, SW_MINIMIZE );//縮小視窗
		nTimer = SetTimer(0, 0, 1000, &TimeProc);//SetTimer(NULL,1,3000,TimeProc);//啟動TIMER
		MSG   msg;
		while(GetMessage(&msg,NULL,0,0)) //事件回應區
		{   
			if(msg.message==WM_TIMER)   
			{   
				DispatchMessage(&msg);   
			}
		}
	}

	return nRetCode;
}

void CALLBACK TimeProc( HWND hwnd, UINT message, UINT idTimer, DWORD dwTime)   
{
		//=========================
		KillTimer(0, nTimer);
		FILE *pfList='\0';
		FILE *pfBat,*pfBat1;
		CString StrLast;
		CString StrBuf,StrBuf1,StrBuf2,StrBat,StrBat1;
		CString StrSec;
		char buf[513];

		CString StrCallExeName,StrCallExeName1;
		StrCallExeName=gstrCurDrt;
		StrCallExeName1=gstrCurDrt;
		StrCallExeName+="CutImage.bat";
		StrCallExeName1+="info1.bat";

		CTime timeNow=CTime::GetCurrentTime();
		CString StrTime;
		StrTime=timeNow.Format("%Y/%m/%d/ %H:%M:%S");

		system("cls");
		printf("%s\n",StrTime.GetBuffer(0));

		pfList=fopen("CutImageList.txt","r");
		if(pfList=='\0')
		{
			printf("目前沒有需要擷取的影面畫面:\n");
		}
		else
		{
			StrLast="";
			printf("準備解析資料...\n");

			pfBat=fopen("CutImage.bat","w");
			while(fgets(buf,512,pfList) != NULL)
			{
				//ffmpeg -i "c:\cQkKCwfLOTY.mp4" sample1.jpg -ss 10 -r 1 -vframes 1 -an -vcodec mjpeg
				StrBat="ffmpeg -i \"";
				StrBat1="ffmpeg -i \"";
				//printf("%s\n",StrBat.GetBuffer(0));

				StrBuf=buf;
				StrBuf=StrBuf.Mid(0,(StrBuf.GetLength()-1));
				StrBuf1=StrBuf;
				StrBuf2=StrBuf;

				//StrBuf.Replace("V:\\smooth", "Y:");
				//printf("%s\n",StrBuf.GetBuffer(0));

				StrBat+=StrBuf;
				pfBat1='\0';
				pfBat1=fopen("info1.bat","w");
				StrBat1+=StrBuf;
				StrBat1+="\" 2> info1.txt";
				fprintf(pfBat1,"%s\n",StrBat1.GetBuffer(0));
				fprintf(pfBat1,"%s\n","ping 127.0.0.1");
				fclose(pfBat1);
				printf("info1.bat create OK\n");

				StrBat+="\" ";
				//printf("%s\n",StrBat.GetBuffer(0));

				StrBuf1.Replace("V:\\smooth","W:");//目錄
				StrBuf1=StrBuf1.Mid(0,StrBuf1.ReverseFind('\\'));
				StrBuf1=StrBuf1.Mid(0,StrBuf1.ReverseFind('\\'));
				if(StrLast!=StrBuf1)
				{
					StrLast=StrBuf1;
					CreateMuliteDirectory(StrBuf1);
				}
				//printf("%s\n",StrBat.GetBuffer(0));

				
				PROCESS_INFORMATION pi1;
				STARTUPINFO si1;
				memset(&si1,0,sizeof(si1));
				si1.cb=sizeof(si1);
				si1.wShowWindow=SW_MINIMIZE;
				si1.dwFlags=STARTF_USESHOWWINDOW;
				BOOL fRet1=CreateProcess(NULL,
										StrCallExeName1.GetBuffer(0),
										NULL,
										NULL,
										FALSE,
										NORMAL_PRIORITY_CLASS|CREATE_NEW_CONSOLE,
										NULL,
										NULL,
										&si1,
										&pi1);
				if(fRet1)
				{
					WaitForSingleObject(pi1.hProcess,INFINITE);
				}

				//DeleteFile("info1.txt");

				//StrBat+="-y -f  image2  -ss 22 -vframes 1 -s 160X120";
				StrBat+="-y -f image2 -ss ";
				StrBat+=Parser_Movie_Duration();
				StrBat+=" -vframes 1 -s 160X120 \"";
				StrBat+=StrBuf1;
				StrBuf2=StrBuf2.Mid((StrBuf2.ReverseFind('\\')+1));
				StrBuf2=StrBuf2.Mid(0,StrBuf2.ReverseFind('.'));
				StrBuf2=StrBuf2.Mid(0,StrBuf2.ReverseFind('_'));
				StrBat+="\\";
				StrBat+=StrBuf2;
				StrBat+=".jpg\"";
				//printf("%s\n",StrBat.GetBuffer(0));

				printf("%s\n",StrBat.GetBuffer(0));
				fprintf(pfBat,"%s\n",StrBat.GetBuffer(0));
				fprintf(pfBat,"%s\n","ping 127.0.0.1");


			}
			fclose(pfList);
			fclose(pfBat);
			DeleteFile("CutImageList.txt");
			//*
			printf("%s\n","開始執行截圖...");
			PROCESS_INFORMATION pi;
			STARTUPINFO si;
			memset(&si,0,sizeof(si));
			si.cb=sizeof(si);
			si.wShowWindow=SW_MINIMIZE;
			si.dwFlags=STARTF_USESHOWWINDOW;
			BOOL fRet=CreateProcess(NULL,
									StrCallExeName.GetBuffer(0),
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
				WaitForSingleObject(pi.hProcess,INFINITE);
			}
			//DeleteFile("CutImage.bat");
			//*/
			printf("%s\n","截圖完成...");
		}
		nTimer = SetTimer(0, 0, 5000, &TimeProc);//SetTimer(NULL,1,3000,TimeProc);//啟動TIMER
}
