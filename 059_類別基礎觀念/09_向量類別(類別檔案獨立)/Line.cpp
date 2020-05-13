// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "Line.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine(float x1,float y1,float z1,float x2,float y2,float z2)
{
	m_StartPoint.SetData(x1,y1,z1); 
	m_EndPoint.SetData(x2,y2,z2);
}
CLine::CLine(CPoint3D point1,CPoint3D point2)
{
	m_StartPoint=point1;
	m_EndPoint=point2;
}
void CLine::SetData(float x1,float y1,float z1,float x2,float y2,float z2)
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
	float fltSumBuffer;
	m_LessX=m_EndPoint.m_x-m_StartPoint.m_x; 
	m_LessY=m_EndPoint.m_y-m_StartPoint.m_y; 
	m_LessZ=m_EndPoint.m_z-m_StartPoint.m_z;
	m_SquareX=(float)pow(m_LessX,2);
	m_SquareY=(float)pow(m_LessY,2);
	m_SquareZ=(float)pow(m_LessZ,2);
	fltSumBuffer=m_SquareX+m_SquareY+m_SquareZ;
	m_Distance=(float)sqrt(fltSumBuffer);
}
float CLine::GetDistance()
{
	return m_Distance;
}
