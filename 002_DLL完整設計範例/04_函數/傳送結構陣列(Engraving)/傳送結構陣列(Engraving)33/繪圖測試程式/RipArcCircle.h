// RipArcCircle.h: interface for the CRipArcCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RIPARCCIRCLE_H__C94038A6_9F0C_4A19_983A_B5965D4C7E63__INCLUDED_)
#define AFX_RIPARCCIRCLE_H__C94038A6_9F0C_4A19_983A_B5965D4C7E63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Point2D.h"
#include "Point3D.h"
#include "Vector.h"
#include "Line.h"
#include "LineLine.h"
#include "Circle.h"
#include "Arc.h"
#define PI 3.1415926f
class CRipArcCircle  
{
public:
	CLine m_LineBase;
	CPoint3D m_Point3DRip;
	CArc m_ArcRip;
	CRipArcCircle();
	CRipArcCircle(CLine LineBase,CArc ArcRip,CPoint3D Point3DRip);
	bool GetCircle(CCircle *circle1);
	virtual ~CRipArcCircle();
private:
	CPoint3D m_Point3DCross;//LineBase與連心線的交點
	CLine m_L;//Line1的一部分，圓弧上一點到LineBase
	CLineLine m_LL1;//求LineBase與連心線的交點
	double m_dblSita;//與LineBase有交點之連心線的夾角
	double m_r;//L=r+a，r的長度
	double m_a;//L=r+a，a的長度
	//int m_intType;//0:圓弧外，1:圓弧內
protected:
	void Calculate();
	bool m_bolSolution;//紀錄求解情況，true是找到解，false是無解
	CCircle m_CircleAnswer;//紀錄解
};

#endif // !defined(AFX_RIPARCCIRCLE_H__C94038A6_9F0C_4A19_983A_B5965D4C7E63__INCLUDED_)
