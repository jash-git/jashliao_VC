// Vector.cpp: implementation of the CVector class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SDIShow.h"
#include "Vector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVector::CVector(double x1,double y1,double z1,double x2,double y2,double z2) 
: CLine(x1,y1,z1,x2,y2,z2)
{
	//Calculate();
}
CVector::CVector(CPoint3D point1,CPoint3D point2)
: CLine(point1,point2)
{
	//Calculate();
}
CVector::CVector(CPoint3D point1)
{
	CPoint3D P3Dtemp(0.0f,0.0f,0.0f);
	m_StartPoint=P3Dtemp;
	m_EndPoint=point1;
	//Calculate();
}
CVector::CVector() : CLine()
{
}
CVector::~CVector()
{
	CLine::~CLine();
}
void CVector::Calculate()
{
	double fltBuffer1,fltBuffer2,fltBuffer3;
	CLine::Calculate();
	Vector.SetData(m_LessX,m_LessY,m_LessZ);
	//////////////////////////////////////////////
	fltBuffer1=Vector.m_x/m_Distance;
	fltBuffer2=Vector.m_y/m_Distance;
	fltBuffer3=Vector.m_z/m_Distance;
	UnitVector.SetData(fltBuffer1,fltBuffer2,fltBuffer3); 
}
CPoint3D CVector::GetVector()
{
	Calculate();
	return Vector;
}
CPoint3D CVector::GetUnitVector()
{
	Calculate();
	return UnitVector;
}
CPoint3D CVector::operator+(CVector data)
{
	CPoint3D temp;
	Calculate();
	data.Calculate();
	temp=Vector+data.Vector;
	return temp; 	
}
CPoint3D CVector::operator-(CVector data)
{
	CPoint3D temp;
	Calculate();
	data.Calculate();
	temp=Vector-data.Vector;
	return temp; 	
}
CPoint3D CVector::operator*(CVector data)
{
	CPoint3D temp;
	double fltBufferX,fltBufferY,fltBufferZ;
	Calculate();
	data.Calculate(); 
	fltBufferX=(Vector.m_y*data.Vector.m_z)-(data.Vector.m_y*Vector.m_z);
	fltBufferY=(data.Vector.m_x*Vector.m_z)-(Vector.m_x*data.Vector.m_z);
	fltBufferZ=(Vector.m_x*data.Vector.m_y)-(data.Vector.m_x*Vector.m_y);
	temp.SetData(fltBufferX,fltBufferY,fltBufferZ);
	return temp; 
}
double CVector::dot(CVector data1,CVector data2,double *ang)
{
	double temp;
	double fltBuffer1,fltBuffer2,fltBuffer3,fltBuffer4;
	CPoint3D P3DBuffer1,P3DBuffer2; 
	///////////////////////////////////
	data1.Calculate();
	fltBuffer1=data1.GetDistance(); 
	data2.Calculate(); 
	fltBuffer2=data2.GetDistance();
	fltBuffer3=fltBuffer1*fltBuffer2;
	///////////////////////////////////
	P3DBuffer1=data1.GetVector();
	P3DBuffer2=data2.GetVector();
	fltBuffer4=(P3DBuffer1.m_x*P3DBuffer2.m_x)+(P3DBuffer1.m_y*P3DBuffer2.m_y)
			  +(P3DBuffer1.m_z*P3DBuffer2.m_z);
	temp=fltBuffer4;
	*ang=((double)acos(temp/fltBuffer3)*180.f/PI);//0~180«×
	return temp; 
}
