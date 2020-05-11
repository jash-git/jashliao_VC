// RS232.cpp: implementation of the CRS232 class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RS232.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRS232::CRS232()
{

}
bool CRS232::OpenCom(long com,long BaudRate,long ByteSize,long Parity,float StopBits)//Parity：無同位元 0；EVEN 1；ODD 2
{
	switch(com)
	{
		case 1:
				hCom1=CreateFile("COM1", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 2:
				hCom1=CreateFile("COM2", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 3:
				hCom1=CreateFile("COM3", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 4:
				hCom1=CreateFile("COM4", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 5:
				hCom1=CreateFile("COM5", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 6:
				hCom1=CreateFile("COM6", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 7:
				hCom1=CreateFile("COM7", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 8:
				hCom1=CreateFile("COM8", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 9:
				hCom1=CreateFile("COM9", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 10:
				hCom1=CreateFile("\\.\COM10", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 11:
				hCom1=CreateFile("\\.\COM11", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 12:
				hCom1=CreateFile("\\.\COM12", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 13:
				hCom1=CreateFile("\\.\COM13", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 14:
				hCom1=CreateFile("\\.\COM14", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 15:
				hCom1=CreateFile("\\.\COM15", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 16:
				hCom1=CreateFile("\\.\COM16", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 17:
				hCom1=CreateFile("\\.\COM17", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
		case 18:
				hCom1=CreateFile("\\.\COM18", //串口號 
								GENERIC_READ|GENERIC_WRITE, //允許讀寫 
								0, //通訊設備必須以獨佔方式打開 
								NULL, //無安全屬性 
								OPEN_EXISTING, //通訊設備已存在 
								FILE_FLAG_OVERLAPPED, //非同步I/O 
								0); //通訊設備不能用模板打開
			break;
	}
	if (hCom1 != INVALID_HANDLE_VALUE)
	{
		/////////////////////////////////////
		SetupComm(hCom1,1024,1024);
		/////////////////////////////////////
		TimeOuts.ReadIntervalTimeout=500;
		TimeOuts.ReadTotalTimeoutMultiplier=5000; 
		TimeOuts.ReadTotalTimeoutConstant=5000;
		TimeOuts.WriteTotalTimeoutMultiplier=0;
		TimeOuts.WriteTotalTimeoutConstant=0; 
		SetCommTimeouts(hCom1,&TimeOuts);
		///////////////////////////////////////
		GetCommState(hCom1,&dcb);
		dcb.BaudRate=BaudRate;
		dcb.ByteSize=(unsigned char)ByteSize;
		switch(Parity)
		{
			//：無同位元 0；EVEN 1；ODD 2
			case 0:
				dcb.Parity=NOPARITY;
				break;
			case 1:
				dcb.Parity=ODDPARITY;
				break;
			case 2:
				dcb.Parity=EVENPARITY;
				break;
		}
		if(StopBits==1.0f)
			dcb.StopBits=ONESTOPBIT;
		else if(StopBits==1.5f)
			dcb.StopBits=ONE5STOPBITS;
		else if(StopBits==2.0f)
			dcb.StopBits=TWOSTOPBITS;
		dcb.fOutX=TRUE;
		dcb.fInX=TRUE;  
		SetCommState(hCom1,&dcb);
		return 1;
	}
	return 0;
}
void CRS232::Write(unsigned char str[],long number)
{
	OVERLAPPED ol;
	DWORD nBytesWrite;
	BOOL fState;
	unsigned char *pBuf;
	pBuf=str;
	ol.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL); 
	ol.Offset=0;        
	ol.OffsetHigh=0; 
	ol.hEvent=NULL;        ///標識事件，資料傳送完成時，將它設定信號狀態 
	fState=WriteFile(hCom1,pBuf,number,&nBytesWrite,&ol) ;
	if(!fState)
	{
		if(GetLastError()==ERROR_IO_PENDING)
		{
			GetOverlappedResult(hCom1,&ol,&nBytesWrite,TRUE);// 等待
		}
	}
}
void CRS232::Read(unsigned char *str,long *number)
{
	OVERLAPPED ol;
	DWORD nBytesRead;
	BOOL fState;
	unsigned char *pBuf;
	bool data=false;
	long lngDataBit=0;
	ol.hEvent=CreateEvent(NULL,TRUE,FALSE,NULL); 
	ol.Offset=0;        
	ol.OffsetHigh=0; 
	ol.hEvent=NULL;        ///標識事件，資料傳送完成時，將它設定信號狀態
	COMSTAT ComStat;
	DWORD dwErrorFlags;
	ClearCommError(hCom1,&dwErrorFlags,&ComStat);
	lngDataBit=ComStat.cbInQue;
	pBuf=new unsigned char[lngDataBit];
	fState=ReadFile(hCom1,pBuf,ComStat.cbInQue,&nBytesRead,&ol) ;
	if(!fState)
	{
		if(GetLastError()==ERROR_IO_PENDING)
		{
			GetOverlappedResult(hCom1,&ol,&nBytesRead,TRUE);// 等待
		}
	}
	if(lngDataBit>0)
	{
		if(lngDataBit>1024)
			lngDataBit=1024;
		for(int i=0;i<lngDataBit;i++)
			*(str+i)=*(pBuf+i);
		*number=lngDataBit;
		data=true;
	}
	if(data)
		delete []pBuf;
}
void CRS232::Close(void)
{
	CloseHandle(hCom1);
}
CRS232::~CRS232()
{
	CloseHandle(hCom1);
}
