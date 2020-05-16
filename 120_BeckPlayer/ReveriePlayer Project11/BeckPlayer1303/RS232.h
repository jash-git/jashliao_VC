// RS232.h: interface for the CRS232 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RS232_H__E7B3461C_8004_45BC_9A32_7E0E1CB6AEDC__INCLUDED_)
#define AFX_RS232_H__E7B3461C_8004_45BC_9A32_7E0E1CB6AEDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <windows.h>
class CRS232  
{
public:
	CRS232();
	bool OpenCom(long com,long BaudRate,long ByteSize,long Parity,float StopBits);//Parity：無同位元 0；EVEN 1；ODD 2
	void Write(char str[],long number);
	void Read(char *str,long *number);
	void Close(void);
	virtual ~CRS232();
private:
	HANDLE hCom1;
	DCB dcb;
	COMMTIMEOUTS TimeOuts;
protected:
};

#endif // !defined(AFX_RS232_H__E7B3461C_8004_45BC_9A32_7E0E1CB6AEDC__INCLUDED_)
