#include <iostream.h>
#include "Line.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Vector.h"
void main()
{
/*
//代刚CVector
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
//代刚CLine
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
//代刚CPoint2D祘Α絏
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
//代刚CPoint3D祘Α絏
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
