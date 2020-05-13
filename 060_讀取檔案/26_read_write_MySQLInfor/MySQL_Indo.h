// MySQL_Indo.h: interface for the MySQL_Indo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSQL_INDO_H__FF21D57E_4644_481E_9981_9A469F424268__INCLUDED_)
#define AFX_MYSQL_INDO_H__FF21D57E_4644_481E_9981_9A469F424268__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class MySQL_Indo  
{
public:
	MySQL_Indo();
	virtual ~MySQL_Indo();
	void SetInfoData(int,char *);
	char m_chrHostName[50];
	char m_chrUserName[50];
	char m_chrPassWord[50];
	char m_chrDBName[50];
	char m_chrInputDir[50];
	char m_chrOutputDir[50];
};

#endif // !defined(AFX_MYSQL_INDO_H__FF21D57E_4644_481E_9981_9A469F424268__INCLUDED_)
