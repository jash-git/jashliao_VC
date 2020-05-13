// MySQL_Info.h: interface for the CMySQL_Info class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSQL_INFO_H__BE98ADD6_6C1C_4606_8C1D_E5414C6EF3AB__INCLUDED_)
#define AFX_MYSQL_INFO_H__BE98ADD6_6C1C_4606_8C1D_E5414C6EF3AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMySQL_Info  
{
public:
	CMySQL_Info();
	virtual ~CMySQL_Info();
	void SetInfoData(int,char *);
	char m_chrHostName[50];//1
	char m_chrUserName[50];//2
	char m_chrPassWord[50];//3
	char m_chrDBName[50];//4
	char m_chrInputDir[50];//5
	char m_chrOutputDir[50];//6
};

#endif // !defined(AFX_MYSQL_INFO_H__BE98ADD6_6C1C_4606_8C1D_E5414C6EF3AB__INCLUDED_)
