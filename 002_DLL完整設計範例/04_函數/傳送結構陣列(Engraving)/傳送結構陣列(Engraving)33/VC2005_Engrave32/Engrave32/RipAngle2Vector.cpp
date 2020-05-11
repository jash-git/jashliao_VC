// RipAngle2Vector.cpp: implementation of the CRipAngle2Vector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
////#include "SDIShow.h"
#include "RipAngle2Vector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRipAngle2Vector::CRipAngle2Vector()
{

}
CRipAngle2Vector::CRipAngle2Vector(const CVector &V1,const CVector &V2)
{
	m_Vector1=V1;
	m_Vector2=V2;
	Calculate();
}
void CRipAngle2Vector::SetData(const CVector &V1,const CVector &V2)
{
	m_Vector1=V1;
	m_Vector2=V2;
	Calculate();
}
void CRipAngle2Vector::Calculate()
{
	CVector VectBuf;
	double dblBuf;
	CPoint3D P3DBuf;
	////////////////////////////////////////////////////
	dblBuf=VectBuf.dot(m_Vector1,m_Vector2,&m_dblAngle);
	///////////////////////////////
	m_lngNumber=m_dblAngle/1.0;
	///////////////////////////////
	P3DBuf=m_Vector1*m_Vector2;
	if(P3DBuf.m_z<0)
		m_dblUnitAngle=-1.0;
	else
		m_dblUnitAngle=1.0;
	///////////////////////////////
}
double CRipAngle2Vector::GetNumber()
{
	return m_lngNumber;
}
double CRipAngle2Vector::GetUnitAngle()
{
	return m_dblUnitAngle;
}
CRipAngle2Vector::~CRipAngle2Vector()
{

}
