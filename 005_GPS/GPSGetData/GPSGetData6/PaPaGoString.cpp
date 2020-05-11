// PaPaGoString.cpp: implementation of the CPaPaGoString class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GPSGetData.h"
#include "PaPaGoString.h"
#include <math.h>
#include <stdlib.h>
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPaPaGoString::CPaPaGoString() : CGPSString()//篶ㄧ计
{
	 m_XCoordinate=-1;
	 m_YCoordinate=-1;
}

CPaPaGoString::~CPaPaGoString()
{
	 m_XCoordinate=-1;
	 m_YCoordinate=-1;
}
CPaPaGoString::CPaPaGoString(const CString &databuf) : CGPSString(databuf)//篶ㄧ计
{
	 m_XCoordinate=-1;
	 m_YCoordinate=-1;
}
CPaPaGoString::CPaPaGoString(const char *databuf) : CGPSString(databuf)//篶ㄧ计
{
	 m_XCoordinate=-1;
	 m_YCoordinate=-1;
}
void CPaPaGoString::CalculateXY()
{
	CString x1,y1;
	char *chrx1,*chry1;
	double dblx1,dbly1;
	double dblx1_int,dblx1_flt;
	double dbly1_int,dbly1_flt;
	int intx1_0,intx1_1,intx1_2;
	int inty1_0,inty1_1,inty1_2;
	div_t divx1,divy1;
	double dblx,dbly;
	Operation();//だ秆戈笲衡ㄧ计
	if(m_strLongitude!="" && m_strLatitude!="")
	{
		x1=m_strLongitude;//竒
		y1=m_strLatitude;//絥
		chrx1=x1.GetBuffer(0);
		chry1=y1.GetBuffer(0);;
		dblx1=atof(chrx1);
		dbly1=atof(chry1);
		dblx1_flt=modf(dblx1,&dblx1_int);
		dbly1_flt=modf(dbly1,&dbly1_int);
		intx1_0=(int)dblx1_int;
		inty1_0=(int)dbly1_int;
		divx1=div(intx1_0,100);
		divy1=div(inty1_0,100);
		intx1_1=divx1.quot; 
		intx1_2=divx1.rem; 
		inty1_1=divy1.quot; 
		inty1_2=divy1.rem;
		//(120+(40*60+(0.145*60))/3600.0)
		dblx=(divx1.quot+(divx1.rem*60+(dblx1_flt*60))/3600.0);
		dbly=(divy1.quot+(divy1.rem*60+(dbly1_flt*60))/3600.0);
		m_XCoordinate=dblx*1000000;
		m_YCoordinate=dbly*1000000;
	}
	else
	{
		m_XCoordinate=-1;
		m_YCoordinate=-1;
	}
}
long CPaPaGoString::GetXCoordinate(void)
{
	return m_XCoordinate;
}
long CPaPaGoString::GetYCoordinate(void)
{
	return m_YCoordinate;
}