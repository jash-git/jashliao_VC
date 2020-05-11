// GPSString.h: interface for the CGPSString class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GPSSTRING_H__89A6E39B_9D84_4197_862B_D1A7AC0901FB__INCLUDED_)
#define AFX_GPSSTRING_H__89A6E39B_9D84_4197_862B_D1A7AC0901FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//測試資料
//$GPGGA,161229.487,3723.2475,N,12158.3416,W,1,07,1.0,9.0,M, , , ,0000*18
//$GPGLL,3723.2475,N,12158.3416,W,161229.487,A*2C
//$GPRMC,161229.487,A,3723.2475,N,12158.3416,W,0.13,309.62,120598, ,*10
class CGPSString  
{
public:
	CString m_strInData;//輸入資料變數
	CGPSString();//建構子函數
	CGPSString(const CString &databuf);//建構子函數
	CGPSString(const char *databuf);//建構子函數
	void SetData(const CString &databuf);//輸入資料函數
	void SetData(const char *databuf);//輸入資料函數
	void Operation();//分解資料運算函數
	CString GetHead();//取得檔頭函數
	CString GetTime();//取得時間函數
	CString GetLongitude();//取得經度函數
	CString GetLatitude();//取得緯度函數
	CString GetDirection();//取得方向函數
	virtual ~CGPSString();//解構子函數
private:
	long m_lngType;//通訊格式分類變數GPGAA=0,GPGLL=1,GPRMC=2,啟動時為-1
protected:
	CString m_strHead;//檔頭變數
	CString m_strTime;//時間變數
	CString m_strLongitude;//經度變數
	CString m_strLatitude;//緯度變數
	CString m_strS_N;//南北半球變數
	CString m_strE_W;//東西半球變數
};

#endif // !defined(AFX_GPSSTRING_H__89A6E39B_9D84_4197_862B_D1A7AC0901FB__INCLUDED_)
