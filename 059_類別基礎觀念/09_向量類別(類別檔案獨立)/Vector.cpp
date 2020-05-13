// Vector.cpp: implementation of the CVector class.
//
//////////////////////////////////////////////////////////////////////

#include "Vector.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CVector::CVector(float x1,float y1,float z1,float x2,float y2,float z2) 
: CLine(x1,y1,z1,x2,y2,z2)
{
}
CVector::CVector(CPoint3D point1,CPoint3D point2)
: CLine(point1,point2)
{
}
CVector::CVector(CPoint3D point1)
{
	CPoint3D P3Dtemp(0.0f,0.0f,0.0f);
	m_StartPoint=P3Dtemp;
	m_EndPoint=point1;
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
	float fltBuffer1,fltBuffer2,fltBuffer3;
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
	float fltBufferX,fltBufferY,fltBufferZ;
	fltBufferX=(Vector.m_y*data.Vector.m_z)-(data.Vector.m_y*Vector.m_z);
	fltBufferY=(data.Vector.m_x*Vector.m_z)-(Vector.m_x*data.Vector.m_z);
	fltBufferZ=(Vector.m_x*data.Vector.m_y)-(data.Vector.m_x*Vector.m_y);
	temp.SetData(fltBufferX,fltBufferY,fltBufferZ);
	return temp; 
}
float CVector::dot(CVector data1,CVector data2,float *ang)
{
	float temp;
	float fltBuffer1,fltBuffer2,fltBuffer3,fltBuffer4;
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
	*ang=((float)acos(temp/fltBuffer3)*180.f/PI);
	return temp; 
}
