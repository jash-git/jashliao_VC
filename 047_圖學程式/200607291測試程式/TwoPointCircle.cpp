// TwoPointCircle.cpp: implementation of the CTwoPointCircle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SDIShow.h"
#include "TwoPointCircle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTwoPointCircle::CTwoPointCircle()
{
	m_R=0.0f;
}
CTwoPointCircle::CTwoPointCircle(const CLine &RipLine,const CPoint3D &RipPoint,const CPoint3D &BasePoint)
{
	m_LineRip=RipLine;
	m_Point3DBase=BasePoint;
	m_Point3DRip=RipPoint;
	m_R=0.0f;
	Calculate();
}
void CTwoPointCircle::SetData(const CLine &RipLine,const CPoint3D &RipPoint,const CPoint3D &BasePoint)
{
	m_LineRip=RipLine;
	m_Point3DBase=BasePoint;
	m_Point3DRip=RipPoint;
	m_R=0.0f;
	Calculate();
}
void CTwoPointCircle::Calculate()
{
	double data=0.0f,sita=0.0f,l=0.0f,afa=0.0f;
	CPoint3D Unit,Normal;
	CPoint3D Point3DCenter;

	L1.SetData(m_LineRip.m_StartPoint,m_Point3DRip);
	L2.SetData(m_Point3DRip,m_Point3DBase);
	data=L3.dot(L1,L2,&sita);
	if(sita>90)
		sita=180.0-sita;
	afa=90.0-sita;
	l=(L2.GetDistance()/2.0)/cos(afa/180.0*PI);
	Unit=L1.GetUnitVector();
	Normal.m_x=Unit.m_y*-1.0; 
	Normal.m_y=Unit.m_x; 
	Normal.m_z=Unit.m_z;
	Point3DCenter.m_x=m_Point3DRip.m_x+l*Normal.m_x; 
	Point3DCenter.m_y=m_Point3DRip.m_y+l*Normal.m_y; 
	Point3DCenter.m_z=m_Point3DRip.m_z+l*Normal.m_z;
	L3.SetData(Point3DCenter,m_Point3DBase);
	if(fabs(L3.GetDistance()-l)>0.001)
	{
		Normal.m_x=Normal.m_x*-1.0; 
		Normal.m_y=Normal.m_y*-1.0; 
		Normal.m_z=Normal.m_z*-1.0;
		Point3DCenter.m_x=m_Point3DRip.m_x+l*Normal.m_x; 
		Point3DCenter.m_y=m_Point3DRip.m_y+l*Normal.m_y; 
		Point3DCenter.m_z=m_Point3DRip.m_z+l*Normal.m_z;
	}
	m_R=l;
	m_Point3DCenter=Point3DCenter;
}
CPoint3D CTwoPointCircle::GetCenter()
{
	//Calculate();
	return m_Point3DCenter;
}
double CTwoPointCircle::GetR()
{
	//Calculate();
	return m_R;
}
CTwoPointCircle::~CTwoPointCircle()
{

}
