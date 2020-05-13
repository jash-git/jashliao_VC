// Point2D.cpp: implementation of the CPoint2D class.
//
//////////////////////////////////////////////////////////////////////

#include "Point2D.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPoint2D::CPoint2D()
{
	m_x=0.0f;
	m_y=0.0f;
}
CPoint2D::CPoint2D(float x,float y)
{
	m_x=x;
	m_y=y;
}
void CPoint2D::SetData(float x,float y)
{
	m_x=x;
	m_y=y;
}
CPoint2D::~CPoint2D()
{
}
CPoint2D CPoint2D::operator +(CPoint2D data)
{
	CPoint2D temp;
	temp.m_x=m_x+data.m_x;  
	temp.m_y=m_y+data.m_y;  
	return temp;
}
CPoint2D CPoint2D::operator -(CPoint2D data)
{
	CPoint2D temp;
	temp.m_x=m_x-data.m_x;  
	temp.m_y=m_y-data.m_y;  
	return temp;
}
CPoint2D CPoint2D::operator *(float data)
{
	CPoint2D temp;
	temp.m_x=m_x*data;  
	temp.m_y=m_y*data;  
	return temp;
}
CPoint2D CPoint2D::operator /(float data)
{
	CPoint2D temp;
	temp.m_x=m_x/data;  
	temp.m_y=m_y/data;  
	return temp;
}

