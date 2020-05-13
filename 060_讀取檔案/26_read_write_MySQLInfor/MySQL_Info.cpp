// MySQL_Info.cpp: implementation of the CMySQL_Info class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "read_write_MySQLInfor.h"
#include "MySQL_Info.h"
#include <string.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMySQL_Info::CMySQL_Info()
{
	strcpy(m_chrHostName,"\0");//1
	strcpy(m_chrUserName,"\0");//2
	strcpy(m_chrPassWord,"\0");//3
	strcpy(m_chrDBName,"\0");//4
	strcpy(m_chrInputDir,"\0");//5
	strcpy(m_chrOutputDir,"\0");//6
}

CMySQL_Info::~CMySQL_Info()
{

}
void CMySQL_Info::SetInfoData(int number,char *data)
{
	switch(number)
	{
		case 1:
			strcpy(m_chrHostName,data);//1
			break;
		case 2:
			strcpy(m_chrUserName,data);//2
			break;
		case 3:
			strcpy(m_chrPassWord,data);//3
			break;
		case 4:
			strcpy(m_chrDBName,data);//4
			break;
		case 5:
			strcpy(m_chrInputDir,data);//5
			break;
		case 6:
			strcpy(m_chrOutputDir,data);//6
			break;
	}
}