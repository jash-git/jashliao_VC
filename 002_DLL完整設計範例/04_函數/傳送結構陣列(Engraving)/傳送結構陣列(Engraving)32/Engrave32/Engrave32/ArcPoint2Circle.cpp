// ArcPoint2Circle.cpp: implementation of the CArcPoint2Circle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
////////#include "SDIShow.h"
#include "ArcPoint2Circle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CArcPoint2Circle::CArcPoint2Circle()
{
	m_R=0.0f;
}
CArcPoint2Circle::CArcPoint2Circle(const CArc &RipArc,const CPoint3D &RipPoint3D,const CPoint3D &BasePoint3D)
{
	m_ArcRip=RipArc;
	m_Point3DRip=RipPoint3D;
	m_Point3DBase=BasePoint3D; 
	m_R=0.0f;
	Calculate();
}
void CArcPoint2Circle::SetData(const CArc &RipArc,const CPoint3D &RipPoint3D,const CPoint3D &BasePoint3D)
{
	m_ArcRip=RipArc;
	m_Point3DRip=RipPoint3D;
	m_Point3DBase=BasePoint3D; 
	m_R=0.0f;
	Calculate();
}
void CArcPoint2Circle::Calculate()
{
	double data=0.0f,l=0.0f,afa=0.0f;
	CPoint3D Unit,Normal,Point3DCenter;
	CVector V3;
	m_VectorRip.SetData(m_ArcRip.m_Point3DCenter,m_Point3DRip);
	m_VectorBase.SetData(m_Point3DRip,m_Point3DBase);
	data=V3.dot(m_VectorRip,m_VectorBase,&afa);
	if(afa>90.0)
		afa=180-afa;
	l=(m_VectorBase.GetDistance()/2.0)/cos(afa/180.0*PI);
	Unit=m_VectorRip.GetUnitVector();
	Normal=Unit;
	Point3DCenter.m_x=m_Point3DRip.m_x+l*Normal.m_x; 
	Point3DCenter.m_y=m_Point3DRip.m_y+l*Normal.m_y; 
	Point3DCenter.m_z=m_Point3DRip.m_z+l*Normal.m_z;
	V3.SetData(Point3DCenter,m_Point3DBase);
	if(fabs(V3.GetDistance()-l)>0.001)
	{
		Normal.m_x=Unit.m_x*-1.0; 
		Normal.m_y=Unit.m_y*-1.0; 
		Normal.m_z=Unit.m_z*-1.0;
		Point3DCenter.m_x=m_Point3DRip.m_x+l*Normal.m_x; 
		Point3DCenter.m_y=m_Point3DRip.m_y+l*Normal.m_y; 
		Point3DCenter.m_z=m_Point3DRip.m_z+l*Normal.m_z;
	}
	m_R=l;
	m_Point3DCenter=Point3DCenter;
}
CPoint3D CArcPoint2Circle::GetCenter()
{
	//Calculate();
	return m_Point3DCenter;
}
double CArcPoint2Circle::GetR()
{
	//Calculate();
	return m_R;
}
CArcPoint2Circle::~CArcPoint2Circle()
{

}
