#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PI 3.141596f
class CPoint2D
{
public:
	float m_x,m_y;
	CPoint2D();
	CPoint2D(float x,float y);
	~CPoint2D();
	CPoint2D operator+(CPoint2D data);
	CPoint2D operator-(CPoint2D data);
	CPoint2D operator*(float data);
	CPoint2D operator/(float data);
	void SetData(float x,float y);
private:
protected:
};
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
class CPoint3D : public CPoint2D
{
public:
	float m_z;
	CPoint3D();
	CPoint3D(float x,float y,float z);
	~CPoint3D();
	CPoint3D operator+(CPoint3D data);
	CPoint3D operator-(CPoint3D data);
	CPoint3D operator*(float data);
	CPoint3D operator/(float data);
	void SetData(float x,float y,float z);
private:
protected:
};
CPoint3D::CPoint3D() : CPoint2D()
{
	m_z=0.0f;
}
CPoint3D::CPoint3D(float x,float y,float z) : CPoint2D(x,y)
{
	m_z=z;
}
void CPoint3D::SetData(float x,float y,float z) 
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
CPoint3D CPoint3D::operator*(float data)
{
	CPoint3D temp;
	temp.m_x=m_x*data;  
	temp.m_y=m_y*data;
	temp.m_z=m_z*data;  
	return temp;
}
CPoint3D CPoint3D::operator/(float data)
{
	CPoint3D temp;
	temp.m_x=m_x/data;  
	temp.m_y=m_y/data;
	temp.m_z=m_z/data;  
	return temp;
}
class CLine
{
public:
	CPoint3D m_StartPoint,m_EndPoint;
	CLine(float x1,float y1,float z1,float x2,float y2,float z2);
	CLine(CPoint3D point1,CPoint3D point2);
	CLine();
	~CLine();
	void Calculate();
	void SetData(float x1,float y1,float z1,float x2,float y2,float z2);
	void SetData(CPoint3D point1,CPoint3D point2);
	float GetDistance();
private:
	float m_SquareX,m_SquareY,m_SquareZ;
protected:
	float m_LessX,m_LessY,m_LessZ;//當用public繼承時會變成private
	float m_Distance;
};
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
class CVector : public CLine
{
	public:
	CVector(float x1,float y1,float z1,float x2,float y2,float z2);
	CVector(CPoint3D point1,CPoint3D point2);
	CVector(CPoint3D point1);
	CVector();
	~CVector();
	CPoint3D GetVector();
	CPoint3D GetUnitVector();
	CPoint3D operator+(CVector data);
	CPoint3D operator-(CVector data);
	CPoint3D operator*(CVector data);
	float dot(CVector data1,CVector data2,float *ang);
	private:
	protected:
	CPoint3D Vector;
	CPoint3D UnitVector;
	void Calculate();
};
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
void main()
{
/*
//測試CVector
CVector V1,V2,V3(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f);
CPoint3D P1(0.0f,0.0f,0.0f),P2(2.0f,0.0f,0.0f);
V1.SetData(P1,P2);
V2.SetData(0.0f,0.0f,0.0f,2.0f,2.0f,0.0f);
CPoint3D Vector1;
Vector1=V1.GetVector();
Vector1=V1.GetUnitVector(); 
Vector1=V2.GetVector();
Vector1=V2.GetUnitVector(); 
float fltD1,fltD2,fltD3;
fltD1=V1.GetDistance(); 
fltD2=V2.GetDistance();
fltD3=V3.GetDistance();
Vector1=V1+V2;
Vector1=V1-V2;
Vector1=V2-V1;
Vector1=V1*V2;//4
Vector1=V2*V1;//-4
float ang,Ans;
Ans=V3.dot(V1,V2,&ang);
*/ 
/*
//測試CLine
float fltD1,fltD2,fltD3;
CLine A;
CLine B(0.0f,0.0f,0.0f,4.0f,3.0f,0.0f);
CPoint3D P1(0.0f,0.0f,0.0f),P2(4.0f,3.0f,0.0f);
CLine C(P1,P2);
A.Calculate();
B.Calculate();
C.Calculate();
fltD1=A.GetDistance(); 
fltD2=B.GetDistance(); 
fltD3=C.GetDistance(); 
*/   
/*
//測試CPoint2D程式碼
	CPoint2D A,B;
	CPoint2D C(10.0f,20.0f);
	float k=2.0f;
	A.m_x=1.0;
	A.m_y=1.0;
	B.m_x=2.0;
	B.m_y=2.0;
	C=A+B;
	C=A-B;
	C=B*k;
	C=B/k;
*/
/*
//測試CPoint3D程式碼
	CPoint3D A,B;
	CPoint3D C(10.0f,20.0f,30.0f);
	float k=2.0f;
	A.m_x=1.0;
	A.m_y=1.0;
	A.m_z=1.0f; 
	B.m_x=2.0;
	B.m_y=2.0;
	B.m_z=2.0f; 
	C=A+B;
	C=A-B;
	C=B*k;
	C=B/k;
*/
}