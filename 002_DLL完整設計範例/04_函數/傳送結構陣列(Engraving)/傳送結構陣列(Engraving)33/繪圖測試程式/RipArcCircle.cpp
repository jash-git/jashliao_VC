// RipArcCircle.cpp: implementation of the CRipArcCircle class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SDIShow.h"
#include "RipArcCircle.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRipArcCircle::CRipArcCircle()
{
	m_dblSita=0.0;//與LineBase有交點之連心線的夾角
	m_r=0.0;//L=r+a
	m_a=0.0;
	m_bolSolution=false;
}
CRipArcCircle::CRipArcCircle(CLine LineBase,CArc ArcRip,CPoint3D Point3DRip)
{
	m_dblSita=0.0;//與LineBase有交點之連心線的夾角
	m_r=0.0;//L=r+a，r的長度
	m_a=0.0;//L=r+a，a的長度
	m_LineBase=LineBase;
	m_ArcRip=ArcRip;
	m_Point3DRip=Point3DRip;
	m_bolSolution=false;
}
void CRipArcCircle::Calculate()
{
	bool blnCheckCross=false;
	double dblL=0.0,dotData=0.0;
	CVector VectorSolAng,VectorL,VectorBase;
	CPoint3D Point3DVector; 
	m_L.SetData(m_ArcRip.m_Point3DCenter,m_Point3DRip);//產生圓弧連心線
	m_LL1.SetValue(m_L,m_LineBase);//求LineBase與連心線的交點
	blnCheckCross=m_LL1.GetAns(&m_Point3DCross);//求LineBase與連心線的交點
	if(blnCheckCross==true)
	{
		m_L.SetData(m_Point3DCross,m_Point3DRip);//圓弧上一點到LineBase
		dblL=m_L.GetDistance();//取出圓弧上一點到LineBase的長度 
		VectorL.SetData(m_Point3DCross,m_Point3DRip);//產生L向量 
		VectorBase.SetData(m_Point3DCross,m_LineBase.m_EndPoint);//產生Base向量
		dotData=VectorSolAng.dot(VectorL,VectorBase,&m_dblSita);//求L和Base的夾角
		if(m_dblSita>90.0)
			m_dblSita=180.0-m_dblSita;//使角度介於0到90
		m_a=dblL/(1.0+sin(m_dblSita/180.0*PI));
		m_r=dblL-m_a;//L=a+r
		VectorL.SetData(m_Point3DRip,m_Point3DCross);//重新計算L的單位向量
		Point3DVector=VectorL.GetUnitVector();//重新計算L的單位向量
		m_CircleAnswer.m_fltR=m_r;//設定結果
		m_CircleAnswer.m_Point3DCenter.m_x=m_Point3DRip.m_x+m_r*Point3DVector.m_x;//設定結果  
		m_CircleAnswer.m_Point3DCenter.m_y=m_Point3DRip.m_y+m_r*Point3DVector.m_y;//設定結果  
		m_CircleAnswer.m_Point3DCenter.m_z=m_Point3DRip.m_z+m_r*Point3DVector.m_z;//設定結果  
		m_bolSolution=true;
	}
	else
	{
		m_bolSolution=false;
	}

}
bool CRipArcCircle::GetCircle(CCircle *circle1)
{
	Calculate();
	*circle1=m_CircleAnswer;
	return m_bolSolution;
}
CRipArcCircle::~CRipArcCircle()
{

}
