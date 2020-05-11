// Point3D.cpp: implementation of the CPoint3D class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SDIShow.h"
#include "Point3D.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPoint3D::CPoint3D() : CPoint2D()
{
	m_z=0.0f;
}
CPoint3D::CPoint3D(double x,double y,double z) : CPoint2D(x,y)
{
	m_z=z;
}
void CPoint3D::SetData(double x,double y,double z) 
{
	CPoint2D::SetData(x,y);
	m_z=z;
}
CPoint3D::~CPoint3D()
{
	CPoint2D::~CPoint2D(); 
}
CPoint3D CPoint3D::operator+(CPoint3D data)
{
	CPoint3D temp;
	temp.m_x=m_x+data.m_x;  
	temp.m_y=m_y+data.m_y;
	temp.m_z=m_z+data.m_z;
	return temp;
}
CPoint3D CPoint3D::operator-(CPoint3D data)
{
	CPoint3D temp;
	temp.m_x=m_x-data.m_x;  
	temp.m_y=m_y-data.m_y;
	temp.m_z=m_z-data.m_z;
	return temp;
}
CPoint3D CPoint3D::operator*(double data)
{
	CPoint3D temp;
	temp.m_x=m_x*data;  
	temp.m_y=m_y*data;
	temp.m_z=m_z*data;  
	return temp;
}
CPoint3D CPoint3D::operator/(double data)
{
	CPoint3D temp;
	temp.m_x=m_x/data;  
	temp.m_y=m_y/data;
	temp.m_z=m_z/data;  
	return temp;
}
