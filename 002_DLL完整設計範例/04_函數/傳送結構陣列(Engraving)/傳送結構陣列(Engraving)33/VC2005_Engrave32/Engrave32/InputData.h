#pragma once
#include "Arc.h"
#include "Line.h"
class CInputData//用來接收vb結構體轉換成物件
{
public:
	long m_lngBlock;//用來儲存屬於哪個Block
	long m_lngEntity;//用來儲存屬於哪個Entity
	long m_lngLineArc;//用來儲存型態0->Line；1->Arc
	long CCW;//紀錄方向，0->右；1->左
	long Direction;//紀錄順逆，0->順；1->逆
	CLine m_Line;
	CArc m_Arc;
	CInputData(void);
	void Reset(void);
public:
	~CInputData(void);
};
