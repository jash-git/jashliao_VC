// RotateVector.cpp: implementation of the CRotateVector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
///////////#include "SDIShow.h"
#include "RotateVector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRotateVector::CRotateVector()
{
	m_lngAxle=-1;
	m_dblAngle=0.0;
}
CRotateVector::CRotateVector(const CVector &Vector1)
{
	m_lngAxle=-1;
	m_dblAngle=0.0;
	m_VectorBase=Vector1;
}
void CRotateVector::SetData(const CVector &Vector1)
{
	m_lngAxle=-1;
	m_dblAngle=0.0;
	m_VectorBase=Vector1;
}
CVector CRotateVector::Rotate(long axle,double angle)//0->X,1->Y,2->Z
{
	m_lngAxle=axle;
	m_dblAngle=angle/180*PI;
	switch(m_lngAxle)
	{
		case 0://0->X
			// |							|
			// |	1		0		0		|
			// |	0		cosQ	-sinQ	|
			// |	0		sinQ	cosQ	|
			// |							|
			m_P3DStart.m_x=m_VectorBase.m_StartPoint.m_x; 
			m_P3DStart.m_y=m_VectorBase.m_StartPoint.m_y*cos(m_dblAngle)-
						   m_VectorBase.m_StartPoint.m_z*sin(m_dblAngle); 
			m_P3DStart.m_z=m_VectorBase.m_StartPoint.m_y*sin(m_dblAngle)+
				           m_VectorBase.m_StartPoint.m_z*cos(m_dblAngle);
			m_P3DSEnd.m_x=m_VectorBase.m_EndPoint.m_x;  
			m_P3DSEnd.m_y=m_VectorBase.m_EndPoint.m_y*cos(m_dblAngle)-
						  m_VectorBase.m_EndPoint.m_z*sin(m_dblAngle);  
			m_P3DSEnd.m_z=m_VectorBase.m_EndPoint.m_y*sin(m_dblAngle)+
				          m_VectorBase.m_EndPoint.m_z*cos(m_dblAngle); 
			break;
		case 1://1->Y
			// |							|
			// |	cosQ	0		sinQ	|
			// |	0		1		0		|
			// |	-sinQ	0		cosQ	|
			// |							|
			m_P3DStart.m_x=m_VectorBase.m_StartPoint.m_x*cos(m_dblAngle)+
				           m_VectorBase.m_StartPoint.m_z*sin(m_dblAngle);
			m_P3DStart.m_y=m_VectorBase.m_StartPoint.m_y;
			m_P3DStart.m_z=m_VectorBase.m_StartPoint.m_x*sin(m_dblAngle)*-1+
				           m_VectorBase.m_StartPoint.m_z*cos(m_dblAngle);
			m_P3DSEnd.m_x=m_VectorBase.m_EndPoint.m_x*cos(m_dblAngle)+
				          m_VectorBase.m_EndPoint.m_z*sin(m_dblAngle); 
			m_P3DSEnd.m_y=m_VectorBase.m_EndPoint.m_y; 
			m_P3DSEnd.m_z=m_VectorBase.m_EndPoint.m_x*sin(m_dblAngle)*-1+
				          m_VectorBase.m_EndPoint.m_z*cos(m_dblAngle);
			break;
		case 2://2->Z
			// |							|
			// |	cosQ	-sinQ		0	|
			// |	sinQ	cosQ		0	|
			// |	0		0			1	|
			// |							|
			m_P3DStart.m_x=m_VectorBase.m_StartPoint.m_x*cos(m_dblAngle)-
						   m_VectorBase.m_StartPoint.m_y*sin(m_dblAngle); 
			m_P3DStart.m_y=m_VectorBase.m_StartPoint.m_x*sin(m_dblAngle)+
						   m_VectorBase.m_StartPoint.m_y*cos(m_dblAngle);
			m_P3DStart.m_z=m_VectorBase.m_StartPoint.m_z;  
			m_P3DSEnd.m_x=m_VectorBase.m_EndPoint.m_x*cos(m_dblAngle)-
						  m_VectorBase.m_EndPoint.m_y*sin(m_dblAngle);  
			m_P3DSEnd.m_y=m_VectorBase.m_EndPoint.m_x*sin(m_dblAngle)+
						  m_VectorBase.m_EndPoint.m_y*cos(m_dblAngle);
			m_P3DSEnd.m_z=m_VectorBase.m_EndPoint.m_z;
			break;
	}
	m_VectorAns.SetData(m_P3DStart,m_P3DSEnd); 
	return m_VectorAns;
}
CRotateVector::~CRotateVector()
{

}
