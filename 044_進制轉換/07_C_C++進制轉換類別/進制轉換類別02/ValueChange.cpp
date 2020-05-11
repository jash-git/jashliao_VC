// ValueChange.cpp: implementation of the CValueChange class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "test.h"
#include "ValueChange.h"
/*
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
//*/
///*
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
//*/
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CValueChange::CValueChange()
{
	m_lngInputLen=0;
	m_lngOutputLen=0;
	m_strOutputData='\0';
	m_bnlActive=false;
}

CValueChange::~CValueChange()
{
	if(m_bnlActive)
	{
		m_strOutputData='\0';
		//delete[]m_strOutputData;
		free(m_strOutputData);
	}
}
char * CValueChange::Chang2to10(char *data)
{
	double dblBufValue=0.0;//存放這組二進制可能的最大數字
	int intmultiple=0;//次方
	long lngOutPutBuf=0;//整數型態的輸出變數
	char chrBuf;//暫存單一字元變數
	int i=0;//迴圈變數
	ldiv_t ldivBuf;//計算此二進位為10的幾倍數
	m_strInputData=data;//把輸入資料存入成員變數之中
	m_lngInputLen=strlen(m_strInputData);//計算輸入資料長度
	dblBufValue=pow(2.0,double(m_lngInputLen))-1;//計算這組二進制可能的最大數字
	////////////////////////////////////////////////////////////////////////////
	//計算轉換成十進位的位數start
	do
	{
		intmultiple++;
		ldivBuf=ldiv(long(dblBufValue),long(pow(10.0,double(intmultiple))));
	}
	while(ldivBuf.quot!=0);
	m_lngOutputLen=intmultiple;
	//計算轉換成十進位的位數end
	///////////////////////////////
	if(m_bnlActive)
	{
		m_strOutputData='\0';
		//delete[]m_strOutputData;
		free(m_strOutputData);
	}
	/////////////////////////////////////////
	//m_strOutputData=new char[m_lngOutputLen+1];
	m_strOutputData=(char *)malloc((m_lngOutputLen+1)*sizeof(char));
	/////////////////////////////////////////
	for(i=0;i<m_lngInputLen;i++)
	{
		chrBuf=*(m_strInputData+i);
		if(chrBuf=='1')
		{
			lngOutPutBuf+=long(pow(2.0,double(m_lngInputLen-1-i)));
		}
	}
	ltoa(lngOutPutBuf,m_strOutputData,10);
	*(m_strOutputData+m_lngOutputLen)='\0';
	//////////////////////////////////////
	m_bnlActive=true;
	return m_strOutputData;
}
char * CValueChange::Chang10to2(char *data)
{
	int intmultiple=0;//次方
	int i=0;//迴圈變數
	long lngAnsBuf;//存放2的次方結果
	ldiv_t ldivBuf;//計算十進未除以2的結果
	long lngNowquot=-1;//存放目前商
	long lngNowrem=-1;//存放目前餘數 	
	m_strInputData=data;
	m_lngInputLen=atol(m_strInputData);
	do
	{
		intmultiple++;
		lngAnsBuf=long(pow(2.0,intmultiple));
	}
	while(m_lngInputLen>=lngAnsBuf);
	m_lngOutputLen=intmultiple;
	///////////////////////////////
	if(m_bnlActive)
	{
		m_strOutputData='\0';
		//delete[]m_strOutputData;
		free(m_strOutputData);
	}
	/////////////////////////////////////////
	//m_strOutputData=new char[m_lngOutputLen+1];
	m_strOutputData=(char *)malloc((m_lngOutputLen+1)*sizeof(char));
	for(i=0;i<m_lngOutputLen;i++)
	{
		*(m_strOutputData+i)='0';
	}
	/////////////////////////////////////////
	i=-1;
	do
	{
		
		i++;
		if(i==0)
		{
			ldivBuf=ldiv(m_lngInputLen,2);//計算十進未除以2的結果
			lngNowquot=ldivBuf.quot;//存放目前商
			lngNowrem=ldivBuf.rem;//存放目前餘數
		}
		else
		{
			ldivBuf=ldiv(lngNowquot,2);//計算十進未除以2的結果
			lngNowquot=ldivBuf.quot;//存放目前商
			lngNowrem=ldivBuf.rem;//存放目前餘數
		}
		if(lngNowrem==0)
		{
			*(m_strOutputData+m_lngOutputLen-i-1)='0';
		}
		else
		{
			*(m_strOutputData+m_lngOutputLen-i-1)='1';
		}
		
	}
	while(lngNowquot!=0);
	*(m_strOutputData+m_lngOutputLen)='\0';
	m_bnlActive=true;
	return m_strOutputData;
}
char * CValueChange::Chang2to8(char *data)
{
	int intmultiple=0;//次方
	int i=0;//迴圈變數
	long lngAnsBuf;//存放2的次方結果
	ldiv_t ldivBuf;//計算十進未除以2的結果
	long lngNowquot=-1;//存放目前商
	long lngNowrem=-1;//存放目前餘數 	
	m_strInputData=Chang2to10(data);
	m_lngInputLen=atol(m_strInputData);
	do
	{
		intmultiple++;
		lngAnsBuf=long(pow(8.0,intmultiple));
	}
	while(m_lngInputLen>=lngAnsBuf);
	m_lngOutputLen=intmultiple;
	///////////////////////////////
	if(m_bnlActive)
	{
		m_strOutputData='\0';
		//delete[]m_strOutputData;
		free(m_strOutputData);
	}
	/////////////////////////////////////////
	//m_strOutputData=new char[m_lngOutputLen+1];
	m_strOutputData=(char *)malloc((m_lngOutputLen+1)*sizeof(char));
	for(i=0;i<m_lngOutputLen;i++)
	{
		*(m_strOutputData+i)='0';
	}
	/////////////////////////////////////////
	i=-1;
	do
	{
		
		i++;
		if(i==0)
		{
			ldivBuf=ldiv(m_lngInputLen,8);//計算十進未除以2的結果
			lngNowquot=ldivBuf.quot;//存放目前商
			lngNowrem=ldivBuf.rem;//存放目前餘數
		}
		else
		{
			ldivBuf=ldiv(lngNowquot,8);//計算十進未除以2的結果
			lngNowquot=ldivBuf.quot;//存放目前商
			lngNowrem=ldivBuf.rem;//存放目前餘數
		}
		switch(lngNowrem)
		{
			case 0:
				*(m_strOutputData+m_lngOutputLen-i-1)='0';
				break;
			case 1:
				*(m_strOutputData+m_lngOutputLen-i-1)='1';
				break;
			case 2:
				*(m_strOutputData+m_lngOutputLen-i-1)='2';
				break;
			case 3:
				*(m_strOutputData+m_lngOutputLen-i-1)='3';
				break;
			case 4:
				*(m_strOutputData+m_lngOutputLen-i-1)='4';
				break;
			case 5:
				*(m_strOutputData+m_lngOutputLen-i-1)='5';
				break;
			case 6:
				*(m_strOutputData+m_lngOutputLen-i-1)='6';
				break;
			case 7:
				*(m_strOutputData+m_lngOutputLen-i-1)='7';
				break;
		}
	}
	while(lngNowquot!=0);
	*(m_strOutputData+m_lngOutputLen)='\0';
	m_bnlActive=true;
	return m_strOutputData;
}
char * CValueChange::Chang8to2(char *data)
{
	int i=0;//迴圈變數
	char chrDataBuf;
	char *strBuf;
	m_strInputData=data;
	m_lngInputLen=strlen(m_strInputData);
	m_lngOutputLen=m_lngInputLen*3;
	///////////////////////////////
	if(m_bnlActive)
	{
		m_strOutputData='\0';
		//delete[]m_strOutputData;
		free(m_strOutputData);
	}
	/////////////////////////////////////////
	//m_strOutputData=new char[m_lngOutputLen+1];
	m_strOutputData=(char *)malloc((m_lngOutputLen+1)*sizeof(char));
	for(i=0;i<m_lngOutputLen;i++)
	{
		*(m_strOutputData+i)='0';
	}
	/////////////////////////////////////////
	//strBuf=new char[3];
	strBuf=(char *)malloc((3)*sizeof(char));
	for(i=0;i<m_lngInputLen;i++)
	{
		chrDataBuf=*(m_strInputData+i);
		switch(chrDataBuf)
		{
			case 48:
				strBuf="000";
				break;
			case 49:
				strBuf="001";
				break;
			case 50:
				strBuf="010";
				break;
			case 51:
				strBuf="011";
				break;
			case 52:
				strBuf="100";
				break;
			case 53:
				strBuf="101";
				break;
			case 54:
				strBuf="110";
				break;
			case 55:
				strBuf="111";
				break;
		}
		strcpy((m_strOutputData+i*3),strBuf);
	}
	*(m_strOutputData+m_lngOutputLen)='\0';
	m_bnlActive=true;
	strBuf='\0';
	//delete[]strBuf;
	free(strBuf);
	return m_strOutputData;
}
char * CValueChange::Chang2to16(char *data)
{
	int intmultiple=0;//次方
	int intCheckLen=0;//要輸出的長度日否按計算長度一至
	int i=0;//迴圈變數
	long lngAnsBuf;//存放2的次方結果
	ldiv_t ldivBuf;//計算十進未除以2的結果
	long lngNowquot=-1;//存放目前商
	long lngNowrem=-1;//存放目前餘數 	
	m_strInputData=Chang2to10(data);
	m_lngInputLen=atol(m_strInputData);
	do
	{
		intmultiple++;
		lngAnsBuf=long(pow(16.0,intmultiple));
	}
	while(m_lngInputLen>=lngAnsBuf);
	m_lngOutputLen=intmultiple;
	///////////////////////////////
	if(m_bnlActive)
	{
		m_strOutputData='\0';
		//delete[]m_strOutputData;
		free(m_strOutputData);
	}
	//m_strOutputData=new char[m_lngOutputLen+1];
	m_strOutputData=(char *)malloc((m_lngOutputLen+1)*sizeof(char));
	for(i=0;i<m_lngOutputLen;i++)
	{
		*(m_strOutputData+i)='0';
	}
	/////////////////////////////////////////
	i=-1;
	do
	{
		
		i++;
		if(i==0)
		{
			ldivBuf=ldiv(m_lngInputLen,16);//計算十進未除以2的結果
			lngNowquot=ldivBuf.quot;//存放目前商
			lngNowrem=ldivBuf.rem;//存放目前餘數
		}
		else
		{
			ldivBuf=ldiv(lngNowquot,16);//計算十進未除以2的結果
			lngNowquot=ldivBuf.quot;//存放目前商
			lngNowrem=ldivBuf.rem;//存放目前餘數
		}
		switch(lngNowrem)
		{
			case 0:
				*(m_strOutputData+m_lngOutputLen-i-1)='0';
				break;
			case 1:
				*(m_strOutputData+m_lngOutputLen-i-1)='1';
				break;
			case 2:
				*(m_strOutputData+m_lngOutputLen-i-1)='2';
				break;
			case 3:
				*(m_strOutputData+m_lngOutputLen-i-1)='3';
				break;
			case 4:
				*(m_strOutputData+m_lngOutputLen-i-1)='4';
				break;
			case 5:
				*(m_strOutputData+m_lngOutputLen-i-1)='5';
				break;
			case 6:
				*(m_strOutputData+m_lngOutputLen-i-1)='6';
				break;
			case 7:
				*(m_strOutputData+m_lngOutputLen-i-1)='7';
				break;
			case 8:
				*(m_strOutputData+m_lngOutputLen-i-1)='8';
				break;
			case 9:
				*(m_strOutputData+m_lngOutputLen-i-1)='9';
				break;
			case 10:
				*(m_strOutputData+m_lngOutputLen-i-1)='A';
				break;
			case 11:
				*(m_strOutputData+m_lngOutputLen-i-1)='B';
				break;
			case 12:
				*(m_strOutputData+m_lngOutputLen-i-1)='C';
				break;
			case 13:
				*(m_strOutputData+m_lngOutputLen-i-1)='D';
				break;
			case 14:
				*(m_strOutputData+m_lngOutputLen-i-1)='E';
				break;
			case 15:
				*(m_strOutputData+m_lngOutputLen-i-1)='F';
				break;
		}
	}
	while(lngNowquot!=0);
	*(m_strOutputData+m_lngOutputLen)='\0';
	m_bnlActive=true;
	return m_strOutputData;
}
char * CValueChange::Chang16to2(char *data)
{
	int i=0;//迴圈變數
	char chrDataBuf;
	char *strBuf;
	m_strInputData=data;
	m_lngInputLen=strlen(m_strInputData);
	m_lngOutputLen=m_lngInputLen*4;
	///////////////////////////////
	if(m_bnlActive)
	{
		m_strOutputData='\0';
		//delete[]m_strOutputData;
		free(m_strOutputData);
	}
	/////////////////////////////////////////
	//m_strOutputData=new char[m_lngOutputLen+1];
	m_strOutputData=(char *)malloc((m_lngOutputLen+1)*sizeof(char));
	for(i=0;i<m_lngOutputLen;i++)
	{
		*(m_strOutputData+i)='0';
	}
	/////////////////////////////////////////
	//strBuf=new char[4];
	strBuf=(char *)malloc((4)*sizeof(char));
	for(i=0;i<m_lngInputLen;i++)
	{
		chrDataBuf=*(m_strInputData+i);
		switch(chrDataBuf)
		{
			case 48:
				strBuf="0000";
				break;
			case 49:
				strBuf="0001";
				break;
			case 50:
				strBuf="0010";
				break;
			case 51:
				strBuf="0011";
				break;
			case 52:
				strBuf="0100";
				break;
			case 53:
				strBuf="0101";
				break;
			case 54:
				strBuf="0110";
				break;
			case 55:
				strBuf="0111";
				break;
			case 56:
				strBuf="1000";
				break;
			case 57:
				strBuf="1001";
				break;
			case 65:
				strBuf="1010";
				break;
			case 97:
				strBuf="1010";
				break;
			case 66:
				strBuf="1011";
				break;
			case 98:
				strBuf="1011";
				break;
			case 67:
				strBuf="1100";
				break;
			case 99:
				strBuf="1100";
				break;
			case 68:
				strBuf="1101";
				break;
			case 100:
				strBuf="1101";
				break;
			case 69:
				strBuf="1110";
				break;
			case 101:
				strBuf="1110";
				break;
			case 70:
				strBuf="1111";
				break;
			case 102:
				strBuf="1111";
				break;
		}
		strcpy((m_strOutputData+i*4),strBuf);
	}
	*(m_strOutputData+m_lngOutputLen)='\0';
	m_bnlActive=true;
	strBuf='\0';
	//delete[]strBuf;
	free(strBuf);
	return m_strOutputData;
}
long CValueChange::GetOutputLen()
{
	return m_lngOutputLen;
}

