// SmoothSolution.cpp: implementation of the CSmoothSolution class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SDIShow.h"
#include "SmoothSolution.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSmoothSolution::CSmoothSolution()
{
	lngLineArc=-1;//0->Line,1->Arc
	m_L=0.0;
	m_R=0.0;
	m_Sita=0.0;
}
CSmoothSolution::CSmoothSolution(const CVector &Vector1,const CLine &Line1)
{
	lngLineArc=0;//0->Line,1->Arc
	m_L=0.0;
	m_R=0.0;
	m_Sita=0.0;
	m_VectorBase=Vector1;
	m_Line1=Line1;
}
CSmoothSolution::CSmoothSolution(const CVector &Vector1,const CArc &Arc1)
{
	lngLineArc=1;//0->Line,1->Arc
	m_L=0.0;
	m_R=0.0;
	m_Sita=0.0;
	m_VectorBase=Vector1;
	m_Arc1=Arc1;
}
void CSmoothSolution::SetData(const CVector &Vector1,const CLine &Line1)
{
	lngLineArc=0;//0->Line,1->Arc
	m_L=0.0;
	m_R=0.0;
	m_Sita=0.0;
	m_VectorBase=Vector1;
	m_Line1=Line1;
}
void CSmoothSolution::SetData(const CVector &Vector1,const CArc &Arc1)
{
	lngLineArc=1;//0->Line,1->Arc
	m_L=0.0;
	m_R=0.0;
	m_Sita=0.0;
	m_VectorBase=Vector1;
	m_Arc1=Arc1;
}
bool CSmoothSolution::GetAns(CCircle *CC1)
{
	bool blncheck=false;
	blncheck=Calculate();
	if(blncheck==true)
	{
		CC1->m_fltR=m_CircleAns.m_fltR; 
		CC1->m_Point3DCenter=m_CircleAns.m_Point3DCenter;  
	}
	return blncheck;
}
bool CSmoothSolution::Calculate()
{
	if(lngLineArc==0)
	{
		//Line
		double bata,buf;
		CVector Vbuf1,Vbuf2;
		CLine Linebuf1;
		CLineLine LLbuf1;
		CPoint3D P3Dbuf;
		/*
		Vbuf1.SetData(m_Line1.m_StartPoint,m_Line1.m_EndPoint);//把線段資料變成向量資料
		buf=Vbuf2.dot(m_VectorBase,Vbuf1,&bata);//求兩向量的夾角
		if(bata>90)
		{
			bata=180-bata;
		}
		m_Sita=90.0-bata;
		//*/
		Linebuf1.SetData(m_VectorBase.m_StartPoint,m_VectorBase.m_EndPoint);//把向量轉線
		LLbuf1.SetValue(Linebuf1,m_Line1);//產生求交點物件
		if(LLbuf1.GetAns(&P3Dbuf))//求兩線交點
		{
			bool blncheck1=true,blncheck2=true,blncheck3=true,blncheck4=true;
			/*
			blncheck1=(P3Dbuf.m_x>=m_Line1.m_StartPoint.m_x)&&(P3Dbuf.m_y>=m_Line1.m_StartPoint.m_y);
			blncheck2=(P3Dbuf.m_x<=m_Line1.m_EndPoint.m_x)&&(P3Dbuf.m_y<=m_Line1.m_EndPoint.m_y);
			blncheck3=(P3Dbuf.m_x<=m_Line1.m_StartPoint.m_x)&&(P3Dbuf.m_y<=m_Line1.m_StartPoint.m_y);
			blncheck4=(P3Dbuf.m_x>=m_Line1.m_EndPoint.m_x)&&(P3Dbuf.m_y>=m_Line1.m_EndPoint.m_y);
			//*/
			if((blncheck1 && blncheck2) || (blncheck3 && blncheck4))
			{
				Linebuf1.SetData(P3Dbuf,m_VectorBase.m_StartPoint);
				Vbuf1.SetData(P3Dbuf,m_Line1.m_StartPoint);//把線段資料變成向量資料
				buf=Vbuf2.dot(m_VectorBase,Vbuf1,&bata);//求兩向量的夾角
				if(bata>90)
				{
					Vbuf1.SetData(P3Dbuf,m_Line1.m_EndPoint);//把線段資料變成向量資料
					buf=Vbuf2.dot(m_VectorBase,Vbuf1,&bata);//求兩向量的夾角
				}
				m_Sita=90.0-bata;
				buf=Linebuf1.GetDistance();//計算線段長度
				m_L=buf*sin(bata*PI/180.0);
				m_R=m_L/(1+cos(m_Sita*PI/180.0));
				P3Dbuf=m_VectorBase.GetUnitVector();//求單位向量 
				m_P3DCenter.m_x=m_VectorBase.m_StartPoint.m_x+m_R*P3Dbuf.m_x;//求圓心位置  
				m_P3DCenter.m_y=m_VectorBase.m_StartPoint.m_y+m_R*P3Dbuf.m_y;  
				m_P3DCenter.m_z=m_VectorBase.m_StartPoint.m_z+m_R*P3Dbuf.m_z;
				if(m_R>0)
				{
					m_CircleAns.m_fltR=m_R;
					m_CircleAns.m_Point3DCenter=m_P3DCenter;
					return 1;
					/*
					if(m_CircleAns.CheckExcircle(m_Line1))
					{
						return 1;
					}
					else
					{
						return 0;
					}
					*/
				}
				else
				{
					return 0;
				}
			}
			else
			{
				return 0;
			}
		}
		return 0;

	}
	else if(lngLineArc==1)
	{
		//Arc
		CLine Linebuf1;
		double buf;
		double dblB,dblC;
		CPoint3D P3Dbuf;
		Linebuf1.SetData(m_VectorBase.m_StartPoint,m_Arc1.m_Point3DCenter);//連心線
		buf=Linebuf1.GetDistance();//連心線長度
		P3Dbuf=m_VectorBase.GetUnitVector();//取得dx,dy 
		if(buf<=m_Arc1.m_fltR)//點在圓弧內
		{
			dblB=(2*m_VectorBase.m_StartPoint.m_x*P3Dbuf.m_x+2*m_VectorBase.m_StartPoint.m_y*P3Dbuf.m_y-
				  2*m_Arc1.m_Point3DCenter.m_x*P3Dbuf.m_x-2*m_Arc1.m_Point3DCenter.m_y*P3Dbuf.m_y+2*m_Arc1.m_fltR);   
			dblC=(pow(m_VectorBase.m_StartPoint.m_x,2)+pow(m_VectorBase.m_StartPoint.m_y,2)+
				  pow(m_Arc1.m_Point3DCenter.m_x,2)+pow(m_Arc1.m_Point3DCenter.m_y,2)-
				  2*m_VectorBase.m_StartPoint.m_x*m_Arc1.m_Point3DCenter.m_x-
				  2*m_VectorBase.m_StartPoint.m_y*m_Arc1.m_Point3DCenter.m_y-pow(m_Arc1.m_fltR,2));
		}
		else//點在圓弧外
		{
			dblB=(2*m_VectorBase.m_StartPoint.m_x*P3Dbuf.m_x+2*m_VectorBase.m_StartPoint.m_y*P3Dbuf.m_y-
				  2*m_Arc1.m_Point3DCenter.m_x*P3Dbuf.m_x-2*m_Arc1.m_Point3DCenter.m_y*P3Dbuf.m_y-2*m_Arc1.m_fltR);
			dblC=(pow(m_VectorBase.m_StartPoint.m_x,2)+pow(m_VectorBase.m_StartPoint.m_y,2)+
				  pow(m_Arc1.m_Point3DCenter.m_x,2)+pow(m_Arc1.m_Point3DCenter.m_y,2)-
				  2*m_VectorBase.m_StartPoint.m_x*m_Arc1.m_Point3DCenter.m_x-
				  2*m_VectorBase.m_StartPoint.m_y*m_Arc1.m_Point3DCenter.m_y-pow(m_Arc1.m_fltR,2));
		}
		m_R=dblC*-1/dblB;
		if(m_R>0)
		{
			m_P3DCenter.m_x=m_VectorBase.m_StartPoint.m_x+m_R*P3Dbuf.m_x;//求圓心位置  
			m_P3DCenter.m_y=m_VectorBase.m_StartPoint.m_y+m_R*P3Dbuf.m_y;  
			m_P3DCenter.m_z=m_VectorBase.m_StartPoint.m_z+m_R*P3Dbuf.m_z;
			m_CircleAns.m_fltR=m_R;
			m_CircleAns.m_Point3DCenter=m_P3DCenter;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	return 0;
}
CSmoothSolution::~CSmoothSolution()
{
}
