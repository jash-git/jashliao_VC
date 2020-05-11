// PointArc.cpp: implementation of the CPointArc class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
//#include "SDIShow.h"
#include "PointArc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPointArc::CPointArc()
{
	int i;
	m_fltSiTa=0.0f;
	for(i=0;i<2;i++)
	{
		m_intType[i]=0;//第0個：為0時是線，為1時是圓弧；
					  //第1個：為0時是圓弧外，為1時是圓弧內。
		m_fltR[i]=0.0f;
	}
	m_fltDistance=0.0f;
	for(i=0;i<2;i++)
	{
		m_fltA[i]=0.0f;
		m_fltB[i]=0.0f;
		m_fltC[i]=0.0f;
	}
	m_bolSolution=false;
}
CPointArc::CPointArc(CArc arc1,CLine line1,CPoint3D point1 )
{
	int i;
	m_fltSiTa=0.0f;
	for(i=0;i<2;i++)
	{
		m_intType[i]=0;//第0個：為0時是線，為1時是圓弧；
					  //第1個：為0時是圓弧外，為1時是圓弧內。
		m_fltR[i]=0.0f;
	}
	m_fltDistance=0.0f;

	m_ArcAim=arc1;
	m_LineBegin=line1;
	m_Point3DBegin=point1;
	m_intType[0]=0;//為0時是線
	for(i=0;i<2;i++)
	{
		m_fltA[i]=0.0f;
		m_fltB[i]=0.0f;
		m_fltC[i]=0.0f;
	}
	m_bolSolution=false;
	//CArc m_ArcBegin;
}
CPointArc::CPointArc(CArc arc1,CArc arc2,CPoint3D point1 )
{
	int i;
	m_fltSiTa=0.0f;
	for(i=0;i<2;i++)
	{
		m_intType[i]=0;//第0個：為0時是線，為1時是圓弧；
					  //第1個：為0時是圓弧外，為1時是圓弧內。
		m_fltR[i]=0.0f;
	}
	m_fltDistance=0.0f;
	
	m_ArcAim=arc1;
	//m_LineBegin=line1;
	m_Point3DBegin=point1;
	m_ArcBegin=arc2;
	m_intType[0]=1;//為1時是圓弧
	for(i=0;i<2;i++)
	{
		m_fltA[i]=0.0f;
		m_fltB[i]=0.0f;
		m_fltC[i]=0.0f;
	}
	m_bolSolution=false;
}
void CPointArc::Calculate()
{
	CLine LineBuffer1;
	CPoint3D Point3DBuffer2,Point3DBuffer5(0.0f,0.0f,0.0f),Point3DBuffer11;
	CPoint3D Point3DUnit[2];//存放兩個單位法向量
	CVector VectorBuffer3,VectorBuffer4,VectorBuffer6;
	//double fltBuffer7,fltBuffer8;
	CCircle CircleBuffer9,CircleBuffer10; 
	//bool bolBuffer[2];
	//int intBuffer11;
	if(m_intType[0]==0)//0->線
	{
		//////////////////////////計算弧外弧內
		LineBuffer1.SetData(m_Point3DBegin,m_ArcAim.m_Point3DCenter);//r+R的線 
		m_fltDistance=LineBuffer1.GetDistance(); 
		if(m_ArcAim.m_fltR < m_fltDistance)
			m_intType[1]=0;//為0時是圓弧外
		else
			m_intType[1]=1;//為1時是圓弧內
		//////////////////////////
		m_Vectorn.SetData(m_Point3DBegin,m_ArcAim.m_Point3DCenter);//計算向量n
		VectorBuffer3.SetData(m_LineBegin.m_StartPoint,m_LineBegin.m_EndPoint); //產生線向量
		Point3DBuffer2=VectorBuffer3.GetUnitVector(); //取得線的單位向量
		////////////////////////
		Point3DBuffer11=Point3DBuffer2;
		Point3DBuffer2.m_x=Point3DBuffer11.m_y*-1.0f;//計算線的單位法向量
		Point3DBuffer2.m_y=Point3DBuffer11.m_x;//計算線的單位法向量
		Point3DBuffer2.m_z=Point3DBuffer11.m_z;//計算線的單位法向量
		Point3DUnit[0]=Point3DBuffer2;
		VectorBuffer4.SetData(Point3DBuffer5,Point3DBuffer2);//計算線的單位法向量
		////////////////////////
/*		
		VectorBuffer6.dot(m_Vectorn,VectorBuffer4,&fltBuffer7);
		if(fltBuffer7>90.0f)
		{//修正單位法向量方向
			Point3DBuffer2.m_x=Point3DBuffer2.m_x*-1.0f;//單位法向量反轉
			Point3DBuffer2.m_y=Point3DBuffer2.m_y*-1.0f;//單位法向量反轉
			Point3DBuffer2.m_z=Point3DBuffer2.m_z;//單位法向量反轉
		}
*/
		if(m_intType[1]==0)//求A‧B‧C
		{//為0時是圓弧外
			//A=dx^2+dy^2-1
			m_fltA[0]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx-2*r
			m_fltB[0]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)-
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[0]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
			//////////////////////////////////////////////////////////////
			Point3DBuffer2.m_x=Point3DBuffer2.m_x*-1.0f;//單位法向量反轉
			Point3DBuffer2.m_y=Point3DBuffer2.m_y*-1.0f;//單位法向量反轉
			Point3DBuffer2.m_z=Point3DBuffer2.m_z;//單位法向量反轉
			Point3DUnit[1]=Point3DBuffer2;
			m_fltA[1]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx-2*r
			m_fltB[1]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)-
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[1]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
		}
		else
		{//為1時是圓弧內
			//A=dx^2+dy^2-1
			m_fltA[0]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx+2*r
			m_fltB[0]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[0]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
			///////////////////////////////////////////////////////////////
			Point3DBuffer2.m_x=Point3DBuffer2.m_x*-1.0f;//單位法向量反轉
			Point3DBuffer2.m_y=Point3DBuffer2.m_y*-1.0f;//單位法向量反轉
			Point3DBuffer2.m_z=Point3DBuffer2.m_z;//單位法向量反轉
			Point3DUnit[1]=Point3DBuffer2;
			//A=dx^2+dy^2-1
			m_fltA[1]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx+2*r
			m_fltB[1]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[1]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
		}
		if(m_fltB[0]!=0.0f||m_fltB[1]!=0.0f)//判斷是否為實數，若為虛數則無解
		{//保證為實數
			//計算圓心半徑
			m_CircleAnswer[0].m_fltR=(m_fltC[0]*-1.0f)/m_fltB[0];//計算半徑
			m_CircleAnswer[0].m_Point3DCenter.m_x=m_Point3DBegin.m_x+m_CircleAnswer[0].m_fltR* Point3DUnit[0].m_x;//計算圓心
			m_CircleAnswer[0].m_Point3DCenter.m_y=m_Point3DBegin.m_y+m_CircleAnswer[0].m_fltR* Point3DUnit[0].m_y;//計算圓心
			m_CircleAnswer[0].m_Point3DCenter.m_z=0.0f;
			m_CircleAnswer[1].m_fltR=(m_fltC[1]*-1.0f)/m_fltB[1];//計算半徑
			m_CircleAnswer[1].m_Point3DCenter.m_x=m_Point3DBegin.m_x+m_CircleAnswer[1].m_fltR* Point3DUnit[1].m_x;//計算圓心
			m_CircleAnswer[1].m_Point3DCenter.m_y=m_Point3DBegin.m_y+m_CircleAnswer[1].m_fltR* Point3DUnit[1].m_y;//計算圓心
			m_CircleAnswer[1].m_Point3DCenter.m_z=0.0f;
			m_bolSolution=true;
		}
		else
		{
			m_bolSolution=false;
		}
	}
	else//1->圓弧
	{
		LineBuffer1.SetData(m_Point3DBegin,m_ArcAim.m_Point3DCenter);//起點到圓心線
		m_fltDistance=LineBuffer1.GetDistance(); 
		if(m_ArcAim.m_fltR <= m_fltDistance)
			m_intType[1]=0;//為0時是圓弧外
		else
			m_intType[1]=1;//為1時是圓弧內
		VectorBuffer3.SetData(m_ArcBegin.m_Point3DCenter,m_Point3DBegin);
		Point3DBuffer2=VectorBuffer3.GetUnitVector(); //取得線的單位向量-->也是法向量d
		Point3DUnit[0]=Point3DBuffer2;
///////////////////////////////////////////////////////////////////////////////////////
		if(m_intType[1]==0)//求A‧B‧C
		{//為0時是圓弧外
			//A=dx^2+dy^2-1
			m_fltA[0]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx-2*r
			m_fltB[0]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)-
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[0]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
			/////////////////////////////////
			Point3DBuffer11=Point3DBuffer2;
			Point3DBuffer2.m_x=Point3DBuffer11.m_x*-1.0f;//計算線的單位法向量
			Point3DBuffer2.m_y=Point3DBuffer11.m_y*-1.0f;//計算線的單位法向量
			Point3DBuffer2.m_z=Point3DBuffer11.m_z;//計算線的單位法向量
			Point3DUnit[1]=Point3DBuffer2;
			m_fltA[1]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx-2*r
			m_fltB[1]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)-
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[1]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
		}
		else
		{//為1時是圓弧內
			//A=dx^2+dy^2-1
			m_fltA[0]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx+2*r
			m_fltB[0]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[0]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
			////////////////////////////////////
			Point3DBuffer11=Point3DBuffer2;
			Point3DBuffer2.m_x=Point3DBuffer11.m_x*-1.0f;//計算線的單位法向量
			Point3DBuffer2.m_y=Point3DBuffer11.m_y*-1.0f;//計算線的單位法向量
			Point3DBuffer2.m_z=Point3DBuffer11.m_z;//計算線的單位法向量
			Point3DUnit[1]=Point3DBuffer2;
			m_fltA[1]=double(pow(Point3DBuffer2.m_x,2)+pow(Point3DBuffer2.m_y,2)-1.0f);
			//B=2X0dx+2Y0dy-2Ydy-2Xdx+2*r
			m_fltB[1]=(double)((2.0f*m_Point3DBegin.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_Point3DBegin.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_y*Point3DBuffer2.m_y)-
				   (2.0f*m_ArcAim.m_Point3DCenter.m_x*Point3DBuffer2.m_x)+
				   (2.0f*m_ArcAim.m_fltR));
			//C=X0^2+Y0^2+X^2+Y^2-2X0X-2Y0Y-r^2
			m_fltC[1]=(double)(pow(m_Point3DBegin.m_x,2)+pow(m_Point3DBegin.m_y,2)+
				   pow(m_ArcAim.m_Point3DCenter.m_x,2)+pow(m_ArcAim.m_Point3DCenter.m_y,2)-
				   (2*m_Point3DBegin.m_x*m_ArcAim.m_Point3DCenter.m_x)-(2*m_Point3DBegin.m_y*m_ArcAim.m_Point3DCenter.m_y)-
				   pow(m_ArcAim.m_fltR,2));
		}
		if(m_fltB[0]!=0.0f)//判斷是否為實數，若為虛數則無解
		{//保證為實數
			//計算圓心半徑
			m_CircleAnswer[0].m_fltR=(m_fltC[0]*-1.0f)/m_fltB[0];//計算半徑
			m_CircleAnswer[0].m_Point3DCenter.m_x=m_Point3DBegin.m_x+m_CircleAnswer[0].m_fltR* Point3DUnit[0].m_x;//計算圓心
			m_CircleAnswer[0].m_Point3DCenter.m_y=m_Point3DBegin.m_y+m_CircleAnswer[0].m_fltR* Point3DUnit[0].m_y;//計算圓心
			m_CircleAnswer[0].m_Point3DCenter.m_z=0.0f;
			m_CircleAnswer[1].m_fltR=(m_fltC[1]*-1.0f)/m_fltB[1];//計算半徑
			m_CircleAnswer[1].m_Point3DCenter.m_x=m_Point3DBegin.m_x+m_CircleAnswer[1].m_fltR* Point3DUnit[1].m_x;//計算圓心
			m_CircleAnswer[1].m_Point3DCenter.m_y=m_Point3DBegin.m_y+m_CircleAnswer[1].m_fltR* Point3DUnit[1].m_y;//計算圓心
			m_CircleAnswer[1].m_Point3DCenter.m_z=0.0f;
			m_bolSolution=true;
		}
		else
		{
			m_bolSolution=false;
		}
///////////////////////////////////////////////////////////////////////////////////////
	}
}
bool CPointArc::GetCircle(CCircle *circle1)
{
	Calculate();
	*(circle1+0)=m_CircleAnswer[0];
	*(circle1+1)=m_CircleAnswer[1];
	return m_bolSolution;
}
CPointArc::~CPointArc()
{

}
