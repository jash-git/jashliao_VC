// asdfasdfas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "asdfasdfas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
#define PORT 34000

void GetFile(LPCTSTR strFilename)
{
	AfxSocketInit(NULL);
	CFile destFile(strFilename, CFile::modeCreate | CFile::modeWrite);
	CSocket sockClient;
	sockClient.Create();
	sockClient.Connect("127.0.0.1", PORT); // "127.0.0.1" is the IP to your server, same port	
    DWORD dwTemp = 0; 
    sockClient.AsyncSelect(0); 
    sockClient.IOCtl( FIONBIO, &dwTemp);//變?阻塞方式 
	UINT dataLength;
	sockClient.Receive(&dataLength, 4); //Now we get the File Size first
    int iBufSize = 1024 * 5; 
    int iSize = iBufSize; 
    LPBYTE pBuf = new BYTE[iBufSize]; 
    int iNumByte; 
    UINT uiTotal = 0; 		
//////////////////////////////
  while(uiTotal < dataLength) 
   { 
     if((int)(dataLength - uiTotal) < iBufSize) 
       iSize = dataLength - uiTotal; 
     int iCount=0; 
     //讀取定長資料 
     while(iCount<iSize) 
     { 
       iNumByte =sockClient.Receive(pBuf, iSize-iCount); 
       if(iNumByte == SOCKET_ERROR) 
       { 
          AfxMessageBox("接收錯誤！"); 
          goto ExitLable2; 
       } 
       iCount+=iNumByte; 
       destFile.Write(pBuf, iNumByte); 
     } 
     uiTotal += iCount;//以實際接收位元組?准 
   } 
  AfxMessageBox("接收文件成功！"); 
//////////////////////////////
ExitLable2: 
	delete[] pBuf; 
	destFile.Close();
	sockClient.Close();
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
		GetFile("C:\\temp\\28647.zip");
	return nRetCode;
}


