// PointLine.cpp: implementation of the CPointLine class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
////////#include "SDIShow.h"
#include "PointLine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
/*
	CPointLine(double O_x,double O_y,double A_x,double A_y,double Q_x,double Q_y,double L_x1,double L_y1,double L_x2,double L_y2);
	CPointLine(CPoint3D O,CPoint3D A,CPoint3D Q,CPoint3D LP1,CPoint3D LP2);
	CPointLine(CVector OA,CPoint3D Q,CVector Line1);
*/
CPointLine::CPointLine()
{
	m_fltR[0]=0.0f;
	m_fltR[1]=0.0f;
	//m_Point3DCenter;
	//m_VectorOQ;
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	//m_Point3DQ;
	//m_VectorOA;
}
CPointLine::CPointLine(double O_x,double O_y,double A_x,double A_y,double Q_x,double Q_y,double L_x1,double L_y1,double L_x2,double L_y2)
{
	m_fltR[0]=0.0f;
	m_fltR[1]=0.0f;
	//m_Point3DCenter;
	m_VectorOQ.SetData(O_x,O_y,0.0f,Q_x,Q_y,0.0f);
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	m_Point3DQ.SetData(Q_x,Q_y,0.0f);
	m_VectorOA.SetData(O_x,O_y,0.0f,A_x,A_y,0.0f);
	m_Obuf=m_VectorOA.m_StartPoint; 
	m_Abuf=m_VectorOA.m_EndPoint; 
	m_VectorLine1.SetData(L_x1,L_y1,0.0f,L_x2,L_y2,0.0f);
	m_Linebuf1=m_VectorLine1.m_StartPoint;
	m_Linebuf2=m_VectorLine1.m_EndPoint;
}
CPointLine::CPointLine(CPoint3D O,CPoint3D A,CPoint3D Q,CPoint3D L1,CPoint3D L2)
{
	m_fltR[0]=0.0f;
	m_fltR[1]=0.0f;
	//m_Point3DCenter;
	m_VectorOQ.SetData(O,Q);
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	m_Point3DQ.SetData(Q.m_x,Q.m_y,Q.m_z);
	m_VectorOA.SetData(O,A);
	m_Obuf=O; 
	m_Abuf=A; 
	m_VectorLine1.SetData(L1,L2);
	m_Linebuf1=m_VectorLine1.m_StartPoint;
	m_Linebuf2=m_VectorLine1.m_EndPoint;
}
CPointLine::CPointLine(CVector OA,CPoint3D Q,CVector Line1)
{
	m_fltR[0]=0.0f;
	m_fltR[1]=0.0f;
	//m_Point3DCenter;
	m_VectorOQ.SetData(OA.m_StartPoint,Q);
	m_fltL=0.0f;
	m_fltSita=0.0f;
	//m_Vectord;
	//m_Vectorn;
	m_Point3DQ.SetData(Q.m_x,Q.m_y,Q.m_z);
	m_VectorOA=OA;
	m_Obuf=OA.m_StartPoint; 
	m_Abuf=OA.m_EndPoint; 
	m_VectorLine1=Line1;
	m_Linebuf1=m_VectorLine1.m_StartPoint;
	m_Linebuf2=m_VectorLine1.m_EndPoint;
}
void CPointLine::Calculate(int n)
{
	CPoint3D  Point3DBuffer1;
	double fltDistanceBuffer3,fltDistanceBuffer4;
	CPoint3D Point3DBuffer5,Point3DBuffer6,Point3DBuffer7;
	double fltBuffer8;
	CPoint3D Point3DBuffer9,Point3DBuffer10;
	CLine L1,L2;
	CVector Vectordot;
	double dotvalue;
	//L1.SetData(m_VectorOA.m_StartPoint,m_VectorOA.m_EndPoint);
	L1.SetData(m_Obuf,m_Abuf);
	L2.SetData(m_Linebuf1,m_Linebuf2); 
	LL1.SetValue(L1,L2);
	m_bolLL1Check=LL1.GetAns(&m_Point3DLL1Ans);//兩條線求交點
	if(m_bolLL1Check==true)
	{
		/////////////////////////////////////////////
		//m_ChangePoint1.SetData(m_VectorOA.m_StartPoint,m_VectorOA.m_EndPoint,m_Point3DLL1Ans);
		//m_ChangePoint1.GetData(&Point3DBuffer9,&Point3DBuffer10);
		//m_VectorOA.m_StartPoint=Point3DBuffer9;
		//m_VectorOA.m_EndPoint=Point3DBuffer10;
		if(n==0)
		{
			m_VectorOA.m_StartPoint=m_Point3DLL1Ans;
			m_VectorOA.m_EndPoint=m_Abuf;			
		}
		else
		{
			m_VectorOA.m_StartPoint=m_Point3DLL1Ans;
			m_VectorOA.m_EndPoint=m_Obuf;
		}
		////////////////////////////////////////////
		m_ChangePoint1.SetData(m_VectorLine1.m_StartPoint,m_VectorLine1.m_EndPoint,m_Point3DLL1Ans);
		m_ChangePoint1.GetData(&Point3DBuffer9,&Point3DBuffer10);
		m_VectorLine1.m_StartPoint=Point3DBuffer9;
		//m_VectorLine1.m_EndPoint=Point3DBuffer10;
		m_VectorLine1.m_EndPoint=m_Point3DQ;
		////////////////////////////////////////////
		Point3DBuffer1=m_VectorLine1*m_VectorOA;//OQxOA
//		int testx1=m_VectorLine1.m_EndPoint.m_x-m_VectorLine1.m_StartPoint.m_x;//用來判斷角度是否超過90
//		int testx2=m_VectorOA.m_EndPoint.m_x-m_VectorOA.m_StartPoint.m_x;//用來判斷角度是否超過90 
		CVector VectorBuffer2(Point3DBuffer1); 
		fltDistanceBuffer3=VectorBuffer2.GetDistance();//|OQxOA|
		fltDistanceBuffer4=m_VectorOA.GetDistance();//|OA|
		m_fltL=fltDistanceBuffer3/fltDistanceBuffer4;//求到L
		Point3DBuffer5=m_VectorLine1*m_VectorOA;
		Point3DBuffer6=m_VectorLine1.GetUnitVector();//取出單位向量
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

		dotvalue=Vectordot.dot(m_VectorOA,m_VectorLine1,&m_fltSita);
		m_fltR[n]=m_fltL/(1.0f+(float)cos((m_fltSita/180*PI)));//求到R
/*
		m_fltSita=(double)(asin((m_fltL/m_VectorLine1.GetDistance()))*180.f/PI);//sin-1(L/|OQ|),求到Sita
		//////////////////////
		if((testx1>=0 && testx2>=0)||(testx1<=0 && testx2<=0))
		{
			m_fltR=m_fltL/(1.0f+(float)cos((m_fltSita/180*PI)));//求到R
		}
		else
		{
			m_fltR=m_fltL/(1.0f+(float)cos(PI-(m_fltSita/180*PI)));//求到R
			m_fltSita=180.0-m_fltSita;
		}
*/
		/////////////////////////////////////////////////////
		//求到圓心
		m_Point3DCenter[n].m_x=m_Point3DQ.m_x+(m_fltR[n]*Point3DBuffer7.m_x);
		m_Point3DCenter[n].m_y=m_Point3DQ.m_y+(m_fltR[n]*Point3DBuffer7.m_y);
		m_Point3DCenter[n].m_z=m_Point3DQ.m_z+(m_fltR[n]*Point3DBuffer7.m_z);
		////////////////////////////////////////////////////
	}
	else//沒有交點，表示平行
	{
		if(fabs(m_VectorOA.m_StartPoint.m_x-m_VectorOA.m_EndPoint.m_x)<=0.001)
		{
			//兩條平行線，y=變數
			m_fltL=fabs(m_VectorOA.m_StartPoint.m_x-m_VectorLine1.m_StartPoint.m_x); 
			m_fltR[n]=m_fltL/2.0;
			if((m_VectorOA.m_StartPoint.m_x-m_VectorLine1.m_StartPoint.m_x)>0)
			{
				m_Point3DCenter[n].m_x=m_Point3DQ.m_x+(m_fltR[n]*1.0);
			}
			else if((m_VectorOA.m_StartPoint.m_x-m_VectorLine1.m_StartPoint.m_x)<0)
			{
				m_Point3DCenter[n].m_x=m_Point3DQ.m_x+(m_fltR[n]*-1.0);
			}
			else
			{
				m_Point3DCenter[n].m_x=m_Point3DQ.m_x;
			}
			m_Point3DCenter[n].m_y=m_Point3DQ.m_y;
			m_Point3DCenter[n].m_z=m_Point3DQ.m_z;				
		}
		else if(fabs(m_VectorLine1.m_StartPoint.m_y-m_VectorLine1.m_EndPoint.m_y)<=0.001)
		{
			//兩條平行線，x=變數
			m_fltL=fabs(m_VectorOA.m_StartPoint.m_y-m_VectorLine1.m_StartPoint.m_y);
			m_fltR[n]=m_fltL/2.0;
			if((m_VectorOA.m_StartPoint.m_y-m_VectorLine1.m_StartPoint.m_y)>0)
			{
				m_Point3DCenter[n].m_y=m_Point3DQ.m_y+(m_fltR[n]*1.0);
			}
			else if((m_VectorOA.m_StartPoint.m_y-m_VectorLine1.m_StartPoint.m_y)<0)
			{
				m_Point3DCenter[n].m_y=m_Point3DQ.m_y+(m_fltR[n]*-1.0);
			}
			else
			{
				m_Point3DCenter[n].m_y=m_Point3DQ.m_y;
			}
			m_Point3DCenter[n].m_x=m_Point3DQ.m_x;
			m_Point3DCenter[n].m_z=m_Point3DQ.m_z;
		}
		else
		{
			//有斜率的平行線
			CVector Rip2Base,Rip2Base1,dotRipBase;
			double AngleRipBase,dotLine;
			CPoint3D Point3DBase,BaseUnitVector,Rip2BaseUnitVector;
			////////
			Rip2Base.SetData(m_VectorOA.m_StartPoint,m_Point3DQ);//建立分段點到基準線起點的向量
			dotLine=dotRipBase.dot(Rip2Base,m_VectorOA,&AngleRipBase);//求兩向量夾角
			dotLine=Rip2Base.GetDistance()*sin((AngleRipBase/180*PI));//求Rip2Base投影到基準線的長度 
			BaseUnitVector=m_VectorOA.GetUnitVector();//取出基準線的單位向量 
			Point3DBase.m_x=m_VectorOA.m_StartPoint.m_x+dotLine*BaseUnitVector.m_x;//求Rip2Base投影到基準線的點  
			Point3DBase.m_y=m_VectorOA.m_StartPoint.m_y+dotLine*BaseUnitVector.m_y;  
			Point3DBase.m_z=m_VectorOA.m_StartPoint.m_z+dotLine*BaseUnitVector.m_z; 
			Rip2Base1.SetData(Point3DBase,m_Point3DQ);
			Rip2BaseUnitVector=Rip2Base1.GetUnitVector();
			m_fltR[n]=Rip2Base1.GetDistance()/2.0; 
			m_Point3DCenter[n].m_x=Point3DBase.m_x+(m_fltR[n]*Rip2BaseUnitVector.m_x);
			m_Point3DCenter[n].m_y=Point3DBase.m_y+(m_fltR[n]*Rip2BaseUnitVector.m_y);
			m_Point3DCenter[n].m_z=Point3DBase.m_z+(m_fltR[n]*Rip2BaseUnitVector.m_z);
		}
		m_fltSita=180.0;
	}
}
CPoint3D CPointLine::GetCenter(int n)
{
	CPoint3D temp;
	Calculate(n);
	temp=m_Point3DCenter[n];
	return temp;
}
double CPointLine::GetR(int n)
{
	double temp;
	Calculate(n);
	temp=m_fltR[n];
	return temp;
}
double CPointLine::GetSita(int n)
{
	double temp;
	Calculate(n);
	temp=m_fltSita;
	return temp;
}
double CPointLine::GetL(int n)
{
	double temp;
	Calculate(n);
	temp=m_fltL;
	return temp;
}
CPoint3D CPointLine::Getd(int n)
{
	CPoint3D temp;
	Calculate(n);
	temp=m_Point3Dd;
	return temp;
}
CPointLine::~CPointLine()
{

}
