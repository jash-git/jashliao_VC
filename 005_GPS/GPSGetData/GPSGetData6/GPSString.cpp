// GPSString.cpp: implementation of the CGPSString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GPSGetData.h"
#include "GPSString.h"
#include <string.h>
#include <stdlib.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CGPSString::CGPSString()//建構子函數
{
	m_lngType=-1;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
	m_strInData="";
	m_strHead="";//檔頭變數
	m_strTime="";//時間變數
	m_strLongitude="";//經度變數
	m_strLatitude="";//緯度變數
	m_strS_N="";//南北半球變數
	m_strE_W="";//東西半球變數
	m_DataOK=-1;//資料正確性初始狀態-1，0為錯誤，1為正確
	m_fltRate=0.0f;//目前速度
}
CGPSString::CGPSString(const CString &databuf)//建構子函數
{
	m_lngType=-1;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
	m_strInData=databuf;
	m_strHead="";//檔頭變數
	m_strTime="";//時間變數
	m_strLongitude="";//經度變數
	m_strLatitude="";//緯度變數
	m_strS_N="";//南北半球變數
	m_strE_W="";//東西半球變數
	m_DataOK=-1;//資料正確性初始狀態-1，0為錯誤，1為正確
	m_fltRate=0.0f;//目前速度
}
CGPSString::CGPSString(const char *databuf)//建構子函數
{
	m_lngType=-1;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
	m_strInData=databuf;
	m_strHead="";//檔頭變數
	m_strTime="";//時間變數
	m_strLongitude="";//經度變數
	m_strLatitude="";//緯度變數
	m_strS_N="";//南北半球變數
	m_strE_W="";//東西半球變數
	m_DataOK=-1;//資料正確性初始狀態-1，0為錯誤，1為正確
	m_fltRate=0.0f;//目前速度
}
void CGPSString::SetData(const CString &databuf)//輸入資料函數
{
	m_lngType=-1;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
	m_strInData=databuf;
	m_strHead="";//檔頭變數
	m_strTime="";//時間變數
	m_strLongitude="";//經度變數
	m_strLatitude="";//緯度變數
	m_strS_N="";//南北半球變數
	m_strE_W="";//東西半球變數
	m_DataOK=-1;//資料正確性初始狀態-1，0為錯誤，1為正確
	m_fltRate=0.0f;//目前速度
}
void CGPSString::SetData(const char *databuf)//輸入資料函數
{
	m_lngType=-1;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
	m_strInData=databuf;
	m_strHead="";//檔頭變數
	m_strTime="";//時間變數
	m_strLongitude="";//經度變數
	m_strLatitude="";//緯度變數
	m_strS_N="";//南北半球變數
	m_strE_W="";//東西半球變數
	m_DataOK=-1;//資料正確性初始狀態-1，0為錯誤，1為正確
	m_fltRate=0.0f;//目前速度
}
void CGPSString::Operation()//分解資料運算函數
{
	char *chrInBuf;//建立暫存輸入資料指標
	char *chrOutBuf;//建立暫存輸出分割資料指標
	long lngLen=0;//建立長度暫存變數
	long lngGetLen1=0;//提取資料長度
	long lngGetLen2=0;//剩餘資料長度
	CString strInData="";//m_strInData分身
	CString strRemain="";//剩餘資料
	long lngIndex=0;//取資料旗標
	CString strbuf="";//建立比對檔頭資料暫存器
	char chrSeps[]=",";//建立分割符號
	m_strHead="";//檔頭變數
	m_strTime="";//時間變數
	m_strLongitude="";//經度變數
	m_strLatitude="";//緯度變數
	m_strS_N="";//南北半球變數
	m_strE_W="";//東西半球變數
	/////////////////////////////////////
	chrInBuf=new char('\0');//指標初始化
	chrOutBuf=new char('\0');//指標初始化
	strInData=m_strInData;
	chrInBuf=strInData.GetBuffer(0);//賦予資料
	////////////////////////////////////
	chrOutBuf=strtok(chrInBuf,chrSeps);//擷取檔頭
	m_strHead=chrOutBuf;//輸出至成員變數
	strbuf="$GPGGA";
	if(m_strHead==strbuf)
	{
		m_lngType=0;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
	}
	else
	{
		strbuf="$GPGLL";
		if(m_strHead==strbuf)
		{
			m_lngType=1;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
		}
		else
		{
			strbuf="$GPRMC";
			if(m_strHead==strbuf)
			{
				m_lngType=2;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
			}
			else
			{
				m_lngType=-1;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
			}
		}
	}
	if(m_lngType>=0)
	{
		strInData=m_strInData;//取出原來資料
		chrInBuf=strInData.GetBuffer(0);//賦予資料
		lngLen=strlen(chrInBuf);
		chrOutBuf=strtok(chrInBuf,chrSeps);//擷取檔頭
		lngGetLen1=strlen(chrOutBuf);//提取資料長度
		lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
		strRemain=m_strInData.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
		lngIndex++;
		while(chrOutBuf!=NULL)
		{
			lngIndex++;
			strInData=strRemain;//取出原來資料
			chrInBuf=strInData.GetBuffer(0);//賦予資料
			lngLen=strlen(chrInBuf);
			chrOutBuf=strtok(chrInBuf,chrSeps);//擷取
			lngGetLen1=strlen(chrOutBuf);//提取資料長度
			lngGetLen2=lngLen-lngGetLen1;//剩餘資料長度
			if(lngGetLen2!=0)
			{
				strRemain=strRemain.Mid(lngGetLen1+1,lngGetLen2);//剩餘資料
			}
			switch(m_lngType)//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
			{
				case 0://GPGAA=0
					switch(lngIndex)
					{
						case 2:
							m_strTime=chrOutBuf;//輸出至成員變數
							break;
						case 3:
							m_strLatitude=chrOutBuf;//輸出至成員變數
							break;
						case 4:
							m_strS_N=chrOutBuf;
							break;
						case 5:
							m_strLongitude=chrOutBuf;
							break;
						case 6:
							m_strE_W=chrOutBuf;
							break;
						case 7:
							int buf;
							buf=atoi(chrOutBuf);
							if(buf!=0)
								m_DataOK=1;//資料正確性初始狀態-1，0為錯誤，1為正確
							else
								m_DataOK=0;//資料正確性初始狀態-1，0為錯誤，1為正確
							break;
					}
					break;
				case 1://GPGLL=1
					switch(lngIndex)
					{
						case 2:
							m_strLatitude=chrOutBuf;//輸出至成員變數
							break;
						case 3:
							m_strS_N=chrOutBuf;//輸出至成員變數
							break;
						case 4:
							m_strLongitude=chrOutBuf;
							break;
						case 5:
							m_strE_W=chrOutBuf;
							break;
						case 6:
							m_strTime=chrOutBuf;
							break;
						case 7:
							int buf;
							buf=*(chrOutBuf+0);
							if(buf==65)
								m_DataOK=1;//資料正確性初始狀態-1，0為錯誤，1為正確
							else
								m_DataOK=0;//資料正確性初始狀態-1，0為錯誤，1為正確
							break;
					}				
					break;
				case 2://GPRMC=2
					switch(lngIndex)
					{
						case 2:
							m_strTime=chrOutBuf;//輸出至成員變數
							break;
						case 3:
							int buf;
							buf=*(chrOutBuf+0);
							if(buf==65)
								m_DataOK=1;//資料正確性初始狀態-1，0為錯誤，1為正確
							else
								m_DataOK=0;//資料正確性初始狀態-1，0為錯誤，1為正確
							break;
						case 4:
							m_strLatitude=chrOutBuf;//輸出至成員變數
							break;
						case 5:
							m_strS_N=chrOutBuf;
							break;
						case 6:
							m_strLongitude=chrOutBuf;
							break;
						case 7:
							m_strE_W=chrOutBuf;
							break;
						case 8:
							m_fltRate=(float)atof(chrOutBuf);
					}			
					break;
			}
			if(lngGetLen2==0)
			{
				break;
			}
		}
	}
	////////////////////////////////////
//	delete []chrInBuf;
//	delete []chrOutBuf;
	////////////////////////////////////
	if(m_DataOK!=1)
	{
		m_strLongitude="";
		m_strLatitude="";
	}
}
CString CGPSString::GetHead()//取得檔頭函數
{
	return m_strHead;
}
CString CGPSString::GetTime()//取得時間函數
{
	return m_strTime;
}
CString CGPSString::GetLongitude()//取得經度函數
{
	return m_strLongitude;
}
CString CGPSString::GetLatitude()//取得緯度函數
{
	return m_strLatitude;
}
CString CGPSString::GetDirection()//取得方向函數
{
	CString buf;
	buf=m_strS_N;
	buf=buf+"_";
	buf=buf+m_strE_W;
	return buf;
}
float CGPSString::GetRate()//取得目前速度函數
{
	return m_fltRate;
}
int CGPSString::GetDataOK()//取得資料正確性
{
	return m_DataOK;
}
CGPSString::~CGPSString()//解構子函數
{

}
