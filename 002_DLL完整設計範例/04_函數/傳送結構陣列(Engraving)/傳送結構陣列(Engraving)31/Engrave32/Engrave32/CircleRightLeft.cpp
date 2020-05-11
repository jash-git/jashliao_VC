// CircleRightLeft.cpp: implementation of the CCircleRightLeft class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
//#include "SDIShow.h"
#include "CircleRightLeft.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CCircleRightLeft::CCircleRightLeft()
{
	m_CCW=-1;//紀錄方向，0->右；1->左
	m_Direction=-1;//紀錄順逆，0->順；1->逆
	m_lngLineArc=-1;//用來儲存型態0->Line；1->Arc
	m_blnAns=false;//紀錄運算結果
}
bool CCircleRightLeft::Check()//輸出函數
{
	calculate();
	return m_blnAns;
}
void CCircleRightLeft::SetData(const CInputData &ID,const CCircle &CC)//初始化函數
{
	m_CCW=-1;//紀錄方向，0->右；1->左
	m_Direction=-1;//紀錄順逆，0->順；1->逆
	m_lngLineArc=-1;//用來儲存型態0->Line；1->Arc
	m_blnAns=false;//紀錄運算結果
	m_InputData.Reset();
	m_InputData=ID;
	m_Circle=CC;
}
void CCircleRightLeft::calculate()
{
	m_blnAns=false;//紀錄運算結果
	m_CCW=m_InputData.CCW;//紀錄方向，0->右；1->左
	m_Direction=m_InputData.Direction;//紀錄順逆，0->順；1->逆
	m_lngLineArc=m_InputData.m_lngLineArc;//用來儲存型態0->Line；1->Arc
	////////////////////////////////////////////////
	CLine LineBuf;
	CArc ArcBuf;
	if(m_lngLineArc==0)//0->Line
	{
		double angle1,angle2;
		CPoint3D Point3D1,Point3D2;
		CVector V1,V2;
		CPoint3D V3;
		LineBuf=m_InputData.m_Line;
		V1.SetData(LineBuf.m_StartPoint,LineBuf.m_EndPoint);//from LineBuf
		long lng1=m_Circle.CircleLine(LineBuf,&angle1,&angle2,&Point3D1,&Point3D2);
		///*
		if(lng1==0)
		{
			CPoint3D Centerbuf;//接收圓心的暫存器
			CVector VectorCenterbuf,Vectordot;
			Centerbuf=m_Circle.m_Point3DCenter;
			VectorCenterbuf.SetData(LineBuf.m_StartPoint,Centerbuf);//建立圓心與線段起始點的連線
			angle2=Vectordot.dot(V1,VectorCenterbuf,&angle1);//求兩條線的夾角，此時的angle2儲存dot實數部分
			angle2=VectorCenterbuf.GetDistance()*cos(angle1/180.0*PI);
			Point3D2=V1.GetUnitVector();
			Point3D1.m_x=LineBuf.m_StartPoint.m_x+Point3D2.m_x*angle2;  
			Point3D1.m_y=LineBuf.m_StartPoint.m_y+Point3D2.m_y*angle2; 
			Point3D1.m_z=LineBuf.m_StartPoint.m_z+Point3D2.m_z*angle2; 
		}
		//*/
		V2.SetData(Point3D1,m_Circle.m_Point3DCenter);//from m_Circle；法向量 
		V3=V1*V2;//向量*法向量；大於0表示在左側，小於等於0表示在右側
		if(V3.m_z>0)//法向量在向量左邊，圓在線的左邊
		{
			if(m_CCW==1)//紀錄方向，0->右；1->左
			{
				m_blnAns=true;//都為左
			}
			else
			{
				m_blnAns=false;//一左一右
			}
		}
		else//法向量在向量右邊，圓在線的右邊
		{
			if(m_CCW==1)//紀錄方向，0->右；1->左
			{
				m_blnAns=false;//一右一左
			}
			else
			{
				m_blnAns=true;//都為右
			}
		}
	}
	else//1->Arc
	{
		long lng2,lng3;
		double R1,R2;
		CPoint3D Point3D1,Point3D2;
		ArcBuf=m_InputData.m_Arc;
		Point3D1=ArcBuf.m_Point3DCenter;//Xbar,Ybar
		R1=ArcBuf.m_fltR; 
		Point3D2=m_Circle.m_Point3DCenter;//Xc,Yc
		R2=m_Circle.m_fltR;
		////////////////////////判斷圓在弧外還是弧內
		if( ( pow((Point3D2.m_x-Point3D1.m_x),2) + pow((Point3D2.m_y-Point3D1.m_y),2) ) > (pow((R2-R1),2)) )//弧外  
		{
			lng2=1;//弧外
		}
		else//弧內
		{
			lng2=0;//弧內
		}
		///////////////////////////////////
		///判斷目前切圓實際所在位置
		if(m_Direction==0)//0->順
		{
			if(lng2==1)//弧外
			{
				lng3=1;//左側
			}
			else//弧內
			{
				lng3=0;//右側
			}
		}
		else//1->逆
		{
			if(lng2==1)//弧外
			{
				lng3=0;//右側
			}
			else//弧內
			{
				lng3=1;//左側
			}
		}
		/////////////////////////////
		if((lng3-m_CCW)==0)
		{
			m_blnAns=true;
		}
		else
		{
			m_blnAns=false;
		}
	}
}
CCircleRightLeft::~CCircleRightLeft()
{

}
