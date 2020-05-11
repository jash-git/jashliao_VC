// PointCircle.cpp: implementation of the CPointCircle class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SDIShow.h"
#include "PointCircle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CPointCircle::CPointCircle()
{
	m_fltR=0.0f;
	//m_Point3DCenter;
	//m_VectorOQ;
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	//m_Point3DQ;
	//m_VectorOA;
}
CPointCircle::CPointCircle(double O_x,double O_y,double A_x,double A_y,double Q_x,double Q_y)
{
	m_fltR=0.0f;
	//m_Point3DCenter;
	m_VectorOQ.SetData(O_x,O_y,0.0f,Q_x,Q_y,0.0f);
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	m_Point3DQ.SetData(Q_x,Q_y,0.0f);
	m_VectorOA.SetData(O_x,O_y,0.0f,A_x,A_y,0.0f);
}
CPointCircle::CPointCircle(CPoint3D O,CPoint3D A,CPoint3D Q)
{
	m_fltR=0.0f;
	//m_Point3DCenter;
	m_VectorOQ.SetData(O,Q);
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	m_Point3DQ.SetData(Q.m_x,Q.m_y,Q.m_z);
	m_VectorOA.SetData(O,A) ;
}
CPointCircle::CPointCircle(CVector OA,CPoint3D Q)
{
	m_fltR=0.0f;
	//m_Point3DCenter;
	m_VectorOQ.SetData(OA.m_StartPoint,Q);
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	m_Point3DQ.SetData(Q.m_x,Q.m_y,Q.m_z);
	m_VectorOA=OA;
}
void CPointCircle::Calculate()
{
	CPoint3D  Point3DBuffer1;
	double fltDistanceBuffer3,fltDistanceBuffer4;
	CPoint3D Point3DBuffer5,Point3DBuffer6,Point3DBuffer7;
	double fltBuffer8;
	Point3DBuffer1=m_VectorOQ*m_VectorOA;//OQxOA
	CVector VectorBuffer2(Point3DBuffer1); 
	fltDistanceBuffer3=VectorBuffer2.GetDistance();//|OQxOA|
	fltDistanceBuffer4=m_VectorOA.GetDistance();//|OA|
	m_fltL=fltDistanceBuffer3/fltDistanceBuffer4;//求到L
	Point3DBuffer5=m_VectorOQ*m_VectorOA;
	Point3DBuffer6=m_VectorOQ.GetUnitVector();//取出單位向量
	Point3DBuffer7.m_y=Point3DBuffer6.m_x;//產生單位法向量 
	Point3DBuffer7.m_x=Point3DBuffer6.m_y*-1.0f;
	fltBuffer8=(Point3DBuffer7.m_x*Point3DBuffer6.m_y)-
			   (Point3DBuffer7.m_y*Point3DBuffer6.m_x);
	////////////////////////////////////////////////////////
	if(Point3DBuffer5.m_z <0)
	{
		if(fltBuffer8<0)
		{
			Point3DBuffer7=Point3DBuffer7*-1.0f;
		}

	}
	else
	{
		if(fltBuffer8>=0)
		{
			Point3DBuffer7=Point3DBuffer7*-1.0f;
		}
	}
	m_Point3Dd=Point3DBuffer7;//求到d
	m_fltSita=(double)(asin((m_fltL/m_VectorOQ.GetDistance()))*180.f/PI);//sin-1(L/|OQ|),求到Sita
	//////////////////////
	m_fltR=m_fltL/(1.0f+(double)cos((m_fltSita/180*PI)));//求到R
	/////////////////////////////////////////////////////
	//求到圓心
	m_Point3DCenter.m_x=m_Point3DQ.m_x+(m_fltR*Point3DBuffer7.m_x);
	m_Point3DCenter.m_y=m_Point3DQ.m_y+(m_fltR*Point3DBuffer7.m_y);
	m_Point3DCenter.m_z=m_Point3DQ.m_z+(m_fltR*Point3DBuffer7.m_z);
	////////////////////////////////////////////////////


}
CPoint3D CPointCircle::GetCenter()
{
	CPoint3D temp;
	Calculate();
	temp=m_Point3DCenter;
	return temp;
}
double CPointCircle::GetR()
{
	double temp;
	Calculate();
	temp=m_fltR;
	return temp;
}
double CPointCircle::GetSita()
{
	double temp;
	Calculate();
	temp=m_fltSita;
	return temp;
}
double CPointCircle::GetL()
{
	double temp;
	Calculate();
	temp=m_fltL;
	return temp;
}
CPoint3D CPointCircle::Getd()
{
	CPoint3D temp;
	Calculate();
	temp=m_Point3Dd;
	return temp;
}
CPointCircle::~CPointCircle()
{

}
