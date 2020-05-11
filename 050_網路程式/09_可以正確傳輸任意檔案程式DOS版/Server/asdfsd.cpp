// asdfsd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "asdfsd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;

#define PORT 34000 /// Select any free port you wish

void SendFile(LPCTSTR strFilename)
{
	///////////////////////////////////////
	AfxSocketInit(NULL);
	CSocket sockSrvr; 
	sockSrvr.Create(PORT); // Creates our server socket
	sockSrvr.Listen(1); // Start listening for the client at PORT
	CSocket sockRecv;
	sockSrvr.Accept(sockRecv); // Use another CSocket to accept the connection
	////////////////////////////////////////
	CFile myFile;
	if(!myFile.Open(strFilename, CFile::modeRead))
		return;
   UINT myFileLength = myFile.GetLength(); // Going to send the correct File Size
   int iBufSize = 1024 * 5;  
   int iSize = iBufSize; 
   LPBYTE pBuf = new BYTE[iBufSize];
   DWORD dwTemp = 0;
   /////////////////////////////////////////
   BOOL bTest = sockRecv.AsyncSelect(0);//由於CSocket實際是非同步，將它變?同步（阻塞）方式。 
   sockRecv.IOCtl( FIONBIO, &dwTemp);//用IOCtl要將AsyncSelect的第一個參數?0，參看MSDN
   sockRecv.Send(&myFileLength, 4); // 4 bytes long
   int iNumByte; 
   UINT uiTotal = 0;
   ////////////////////////////////
   while(uiTotal < myFileLength ) 
   { 
     //讀取文件內容 
     if((int)(myFileLength  - uiTotal) < iBufSize) 
       iSize = myFileLength  - uiTotal;//當小於緩衝區iTEST時的處理 
     iSize=myFile.Read(pBuf , iSize);//得到讀取的位元組數 
     int iCount=0; 
     //發送定長文件資料 
     while(iCount<iSize) 
     { 
       iNumByte = sockRecv.Send(pBuf, iSize-iCount);//注意iNumByte?實際的發送位元組數，不要以iSize?准 
       if(iNumByte == SOCKET_ERROR) 
       { 
          AfxMessageBox("發送錯誤！"); 
          goto ExitLable1; 
       } 
       iCount+=iNumByte; 
       if(iCount<iSize) 
       { 
          myFile.Seek(iSize-iCount,CFile::current); 
       } 
     } 
     uiTotal += iCount; 
   }
 AfxMessageBox("發送文件成功！"); 
ExitLable1: 
	delete[] pBuf; 
	myFile.Close();
	sockRecv.Close();
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
		SendFile("C:\\WINDOWS\\Desktop\\28647.zip");
	return nRetCode;
}


