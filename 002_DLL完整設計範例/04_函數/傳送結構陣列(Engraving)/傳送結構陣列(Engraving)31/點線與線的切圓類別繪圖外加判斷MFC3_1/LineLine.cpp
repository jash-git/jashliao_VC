// LineLine.cpp: implementation of the CLineLine class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "SDIShow.h"
#include "LineLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CLineLine::CLineLine()
{
	m_intL1=4;
	m_intL2=4;
	m_flta1=0.0f;
	m_fltb1=0.0f;
	m_flta2=0.0f;
	m_fltb2=0.0f;
	m_bolCheck=true;
}
CLineLine::CLineLine(CLine L1,CLine L2)
{
	m_intL1=4;
	m_intL2=4;
	m_flta1=0.0f;
	m_fltb1=0.0f;
	m_flta2=0.0f;
	m_fltb2=0.0f;
	m_bolCheck=true;
	m_Line1=L1;
	m_Line2=L2;
}
void CLineLine::account1()
{
//m_Point3DStart1
//m_Point3DEnd1
	if(m_Point3DStart1.m_x==m_Point3DEnd1.m_x)
	{
		m_intL1=0;
		m_Point3DAns.m_x=m_Point3DStart1.m_x;
	}
	else if(m_Point3DStart1.m_y==m_Point3DEnd1.m_y)
	{
		m_intL1=1;
		m_Point3DAns.m_y=m_Point3DStart1.m_y;
	}
	else
	{
		m_flta1=(m_Point3DStart1.m_y-m_Point3DEnd1.m_y)/(m_Point3DStart1.m_x-m_Point3DEnd1.m_x);
		m_fltb1=(m_Point3DStart1.m_x*m_flta1*-1.0f)+m_Point3DStart1.m_y;
		m_intL1=2;
	}
}
void CLineLine::account2()
{
//m_Point3DStart2
//m_Point3DEnd2
	if(m_Point3DStart2.m_x==m_Point3DEnd2.m_x)
	{
		m_intL2=0;
		m_Point3DAns.m_x=m_Point3DStart2.m_x;
	}
	else if(m_Point3DStart2.m_y==m_Point3DEnd2.m_y)
	{
		m_intL2=1;
		m_Point3DAns.m_y=m_Point3DStart2.m_y;
	}
	else
	{
		m_flta2=(m_Point3DStart2.m_y-m_Point3DEnd2.m_y)/(m_Point3DStart2.m_x-m_Point3DEnd2.m_x);
		m_fltb2=(m_Point3DStart2.m_x*m_flta2*-1.0f)+m_Point3DStart2.m_y;
		m_intL2=2;
	}
}
void CLineLine::Calculate()
{
	m_Point3DStart1=m_Line1.m_StartPoint; 
	m_Point3DEnd1=m_Line1.m_EndPoint;
	m_Point3DStart2=m_Line2.m_StartPoint; 
	m_Point3DEnd2=m_Line2.m_EndPoint;	
	account1();
	account2();
	if((m_intL1==0 && m_intL2==1)||(m_intL1==1 && m_intL2==0))
	{
		m_bolCheck=true;
	}
	else if((m_intL1==0 && m_intL2==0)||(m_intL1==1 && m_intL2==1))
	{
		m_bolCheck=false;
	}
	else if((m_intL1==0 && m_intL2==2))
	{
		m_Point3DAns.m_y=m_flta2*m_Point3DAns.m_x+m_fltb2;
		m_bolCheck=true;
	}
	else if((m_intL1==2 && m_intL2==0))
	{
		m_Point3DAns.m_y=m_flta1*m_Point3DAns.m_x+m_fltb1;
		m_bolCheck=true;
	}
	else if((m_intL1==1 && m_intL2==2))
	{
		m_Point3DAns.m_x=(m_Point3DAns.m_y-m_fltb2)/m_flta2;
		m_bolCheck=true;
	}
	else if((m_intL1==2 && m_intL2==1))
	{
		m_Point3DAns.m_x=(m_Point3DAns.m_y-m_fltb1)/m_flta1;
		m_bolCheck=true;
	}
	else
	{
		if(fabs(m_flta1-m_flta2)<=0.001)
		{
			m_bolCheck=false;
		}
		else
		{
			m_Point3DAns.m_x=((m_fltb1-m_fltb2)*-1.0)/(m_flta1-m_flta2);
			m_Point3DAns.m_y=m_flta1*m_Point3DAns.m_x+m_fltb1;
			m_bolCheck=true;
		}
	}
}
bool CLineLine::GetAns(CPoint3D *Ans)
{
	Calculate();
	*Ans=m_Point3DAns;
	return m_bolCheck; 
}
void CLineLine::SetValue(CLine L1,CLine L2)
{
	m_Line1=L1;
	m_Line2=L2;
}
CLineLine::~CLineLine()
{

}
