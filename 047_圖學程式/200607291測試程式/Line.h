// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__DF1CBAAF_25EC_4F16_8EAB_AC728F08D267__INCLUDED_)
#define AFX_LINE_H__DF1CBAAF_25EC_4F16_8EAB_AC728F08D267__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Point3D.h"
#define PI 3.1415926f
using namespace std;
class CLine
{
public:
	CPoint3D m_StartPoint,m_EndPoint;
	CLine(double x1,double y1,double z1,double x2,double y2,double z2);
	CLine(CPoint3D point1,CPoint3D point2);
	CLine();
	~CLine();
	void Calculate();
	void SetData(double x1,double y1,double z1,double x2,double y2,double z2);
	void SetData(CPoint3D point1,CPoint3D point2);
	double GetDistance();
private:
	double m_SquareX,m_SquareY,m_SquareZ;
protected:
	double m_LessX,m_LessY,m_LessZ;//當用public繼承時會變成private
	double m_Distance;
};

#endif // !defined(AFX_LINE_H__DF1CBAAF_25EC_4F16_8EAB_AC728F08D267__INCLUDED_)
