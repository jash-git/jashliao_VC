// PointArc.h: interface for the CPointArc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINTARC_H__CC8FB041_1A11_422C_942B_B143193300CA__INCLUDED_)
#define AFX_POINTARC_H__CC8FB041_1A11_422C_942B_B143193300CA__INCLUDED_

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
#include "Circle.h"
#include "Arc.h"
#define PI 3.1415926f
class CPointArc  
{
public:
	CArc m_ArcAim;
	CLine m_LineBegin;
	CPoint3D m_Point3DBegin;
	CArc m_ArcBegin;
	CPointArc();
	CPointArc(CArc arc1,CLine line1,CPoint3D point1);
	CPointArc(CArc arc1,CArc arc2,CPoint3D point1);
	bool GetCircle(CCircle *circle1);
	virtual ~CPointArc();
private:
	CVector m_Vectorn;
	CVector m_Vectord;
	double m_fltSiTa;
	int m_intType[2];//第0個：為0時是線，為1時是圓弧；
					//第1個：為0時是圓弧外，為1時是圓弧內。
	double m_fltDistance;
	double m_fltA[2],m_fltB[2],m_fltC[2];
	double m_fltR[2];//存放解出來的半徑資料
	CPoint3D m_Point3DCenter[2];//存放解出來的圓心資料
protected:
	void Calculate();
	bool m_bolSolution;//紀錄求解情況，true是找到解，false是無解
	CCircle m_CircleAnswer[2];//紀錄解
};

#endif // !defined(AFX_POINTARC_H__CC8FB041_1A11_422C_942B_B143193300CA__INCLUDED_)
