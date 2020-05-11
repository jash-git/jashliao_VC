// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SDIShow.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CLine::CLine(double x1,double y1,double z1,double x2,double y2,double z2)
{
	m_StartPoint.SetData(x1,y1,z1); 
	m_EndPoint.SetData(x2,y2,z2);
}
CLine::CLine(CPoint3D point1,CPoint3D point2)
{
	m_StartPoint=point1;
	m_EndPoint=point2;
}
void CLine::SetData(double x1,double y1,double z1,double x2,double y2,double z2)
{
	m_StartPoint.SetData(x1,y1,z1); 
	m_EndPoint.SetData(x2,y2,z2);
}
void CLine::SetData(CPoint3D point1,CPoint3D point2)
{
	m_StartPoint=point1;
	m_EndPoint=point2;
}
CLine::CLine()
{
	m_Distance=0.0f;
	m_LessX=0.0f;
	m_LessY=0.0f;
	m_LessZ=0.0f;
	m_SquareX=0.0f;
	m_SquareY=0.0f;
	m_SquareZ=0.0f;
}
CLine::~CLine()
{

}
void CLine::Calculate()
{
	double fltSumBuffer;
	m_LessX=m_EndPoint.m_x-m_StartPoint.m_x; 
	m_LessY=m_EndPoint.m_y-m_StartPoint.m_y; 
	m_LessZ=m_EndPoint.m_z-m_StartPoint.m_z;
	m_SquareX=(double)pow(m_LessX,2);
	m_SquareY=(double)pow(m_LessY,2);
	m_SquareZ=(double)pow(m_LessZ,2);
	fltSumBuffer=m_SquareX+m_SquareY+m_SquareZ;
	m_Distance=(double)sqrt(fltSumBuffer);
}
double CLine::GetDistance()
{
	Calculate();
	return m_Distance;
}
