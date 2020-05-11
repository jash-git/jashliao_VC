#include "stdafx.h"
#include "SDIShow.h"
#include "InputData.h"

CInputData::CInputData(void)
{
	m_lngBlock=-1;//用來儲存屬於哪個Block
	m_lngEntity=-1;//用來儲存屬於哪個Entity
	m_lngLineArc=-1;//用來儲存型態0->Line；1->Arc
	CCW=-1;//紀錄方向，0->右；1->左
	Direction=-1;//紀錄順逆，0->順；1->逆
	CPoint3D Point3D(0.0f,0.0f,0.0f); 
	m_Line.SetData(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f) ;
	m_Arc.SetData(Point3D,0.0f,0.0f,0.0f);
}

CInputData::~CInputData(void)
{
}
void CInputData::Reset(void)
{
	m_lngBlock=-1;//用來儲存屬於哪個Block
	m_lngEntity=-1;//用來儲存屬於哪個Entity
	m_lngLineArc=-1;//用來儲存型態0->Line；1->Arc
	CCW=-1;//紀錄方向，0->右；1->左
	Direction=-1;//紀錄順逆，0->順；1->逆
	CPoint3D Point3D(0.0f,0.0f,0.0f); 
	m_Line.SetData(0.0f,0.0f,0.0f,0.0f,0.0f,0.0f) ;
	m_Arc.SetData(Point3D,0.0f,0.0f,0.0f);
}
