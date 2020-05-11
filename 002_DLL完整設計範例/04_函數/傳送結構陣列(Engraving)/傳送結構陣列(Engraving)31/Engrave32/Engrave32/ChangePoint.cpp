// ChangePoint.cpp: implementation of the CChangePoint class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
//#include "SDIShow.h"
#include "ChangePoint.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CChangePoint::CChangePoint()
{

}
CChangePoint::CChangePoint(CPoint3D start,CPoint3D end,CPoint3D p)
{
	m_Point3Dstart=start;
	m_Point3DEnd=end;
	m_Point3DP=p;
}
void CChangePoint::SetData(CPoint3D start,CPoint3D end,CPoint3D p)
{
	m_Point3Dstart=start;
	m_Point3DEnd=end;
	m_Point3DP=p;
}
void CChangePoint::Calculate()
{
	double fltDistance1,fltDistance2;
	m_LineL1.SetData(m_Point3Dstart,m_Point3DP);
	m_LineL2.SetData(m_Point3DEnd,m_Point3DP);
	fltDistance1=m_LineL1.GetDistance();
	fltDistance2=m_LineL2.GetDistance();
	if(fltDistance1>fltDistance2)
	{
		m_Point3DOutStart=m_Point3DP;
		m_Point3DOutEnd=m_Point3Dstart;
	}
	else
	{
		m_Point3DOutStart=m_Point3DP;
		m_Point3DOutEnd=m_Point3DEnd;
	}
	//m_Point3DOut1,m_Point3DOut2
}
void CChangePoint::GetData(CPoint3D *start,CPoint3D *end)
{
	Calculate();
	*start=m_Point3DOutStart;
	*end=m_Point3DOutEnd;
}
CChangePoint::~CChangePoint()
{

}
