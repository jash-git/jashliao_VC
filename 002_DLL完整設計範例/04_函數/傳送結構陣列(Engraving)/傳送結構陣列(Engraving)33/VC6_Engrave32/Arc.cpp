// Arc.cpp: implementation of the CArc class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
////////#include "SDIShow.h"
#include "Arc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CArc::CArc() : CCircle()
{
	m_fltStartAngle=0.0f;
	m_fltEndAngle=0.0f;
}
CArc::CArc(CPoint3D Center,double R,double StartAngle,double EndAngle)
 : CCircle(Center,R)
{
	m_fltStartAngle=StartAngle;
	m_fltEndAngle=EndAngle;
	Calculate();
}
CArc::CArc(double Center_x,double Center_y,double Center_z,double R,double StartAngle,double EndAngle)
: CCircle(Center_x,Center_y,Center_z,R)
{
	m_fltStartAngle=StartAngle;
	m_fltEndAngle=EndAngle;
	Calculate();
}
void CArc::SetData(CPoint3D Center,double R,double StartAngle,double EndAngle)
{
	CCircle::SetData(Center,R);
	m_fltStartAngle=StartAngle;
	m_fltEndAngle=EndAngle;
	Calculate();
}
void CArc::Calculate()
{
	double fltBufferAngle;
	fltBufferAngle=m_fltEndAngle;
	if(m_fltEndAngle < m_fltStartAngle)
		fltBufferAngle+=PI*2.0f;
	CCircle::Calculate();
	m_fltCircumference=m_fltCircumference*(fltBufferAngle- m_fltStartAngle)/(PI*2.0f);//周長
	m_fltArea=m_fltArea*(fltBufferAngle- m_fltStartAngle)/(PI*2.0f);
}
double CArc::GetCircumference()//取得周長
{
	double temp;
	//Calculate();
	temp=m_fltCircumference;
	return temp;
}
double CArc::GetArea()
{
	double temp;
	//Calculate();
	temp=m_fltArea;
	return temp;
}
bool CArc::IsInArc(double angle)
{
	if((m_fltStartAngle<m_fltEndAngle && angle<=m_fltEndAngle && angle>=m_fltStartAngle)
		||(m_fltStartAngle>m_fltEndAngle && angle<=m_fltStartAngle && angle>=m_fltEndAngle))
		return true;
	else
		return false;
}
int CArc::ArcCircle(CCircle Circle)
{
	//m_Point3DCross[5];//儲存交點,其中m_x儲存弧度，m_z儲存狀態
	//intCross;
	CPoint3D Point3DBuffer;
	CLine LineBuffer;
	double fltangle1=0.0,fltangle2=0.0,fltangle[5],fltx1=0.0,flty1=0.0,fltr1=0.0;
	int intpb=0,intnumber=0,i=0;
	intnumber=0;
	intpb=CircleCircle(Circle,&fltangle1,&fltangle2);
	if(fltangle1<0)
		fltangle1=fltangle1+PI*2.0;
	if(intpb==11||intpb==21||intpb==31)
	{
		if(IsInArc(fltangle1))
		{
			fltangle[intnumber++]=fltangle1;
			return 1;
		}
		return 0;
	}
	else
	{
		return 0;
	}
/*
	else if(intpb==2)
	{
		if(IsInArc(fltangle1))
			fltangle[intnumber++]=fltangle1;
		if(IsInArc(fltangle2))
			fltangle[intnumber++]=fltangle2;
	}
	fltangle[intnumber++]=m_fltEndAngle;
	if(m_fltStartAngle>m_fltEndAngle)
	{
		for(i=0;i<intnumber;i++)
		{
			if(fltangle[i]>=0 && fltangle[i]<=m_fltEndAngle)
				fltangle[i]=PI*2.0f+fltangle[i];
		}
	}
	intpb=0;
	for(i=0;i<=intnumber-1;i++)
	{
		m_Point3DCross[i].m_x=fltangle[i];
		fltangle1=(fltangle[i]+fltangle[i+1])/2.0f;
		fltx1=m_Point3DCenter.m_x+m_fltR*(double)cos(fltangle1); 
		flty1=m_Point3DCenter.m_y+m_fltR*(double)sin(fltangle1);
		Point3DBuffer.SetData(fltx1,flty1,0.0f); 
		LineBuffer.SetData(Point3DBuffer,Circle.m_Point3DCenter);   
		fltr1=LineBuffer.GetDistance();
		if(fltr1<=Circle.m_fltR)
			m_Point3DCross[i].m_z=1.0f;
		else
			m_Point3DCross[i].m_z=0.0f;
	}
	m_Point3DCross[intnumber-1].m_x=fltangle[intnumber-1];
	intCross=intnumber;
	if(intnumber==2)
	{
		if(m_Point3DCross[0].m_z==1.0f)
			return 1;//圓弧在圓外
		else
			return 0;//圓弧在圓內
	}
	else
		return 2;//有交點
*/
}
CArc::~CArc()
{
	CCircle::~CCircle();
}
