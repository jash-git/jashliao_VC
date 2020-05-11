// Circle.h: interface for the CCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CIRCLE_H__CF3AC530_AE41_4416_BD3D_37DBA6E883CB__INCLUDED_)
#define AFX_CIRCLE_H__CF3AC530_AE41_4416_BD3D_37DBA6E883CB__INCLUDED_

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
#define PI 3.1415926f
class CCircle  
{
public:
	CPoint3D m_Point3DCenter;
	double m_fltR;
	CCircle();
	CCircle(CPoint3D Center,double R);
	CCircle(double Center_x,double Center_y,double Center_z,double R);
	void SetData(CPoint3D Center,double R);
	double GetCircumference();//取得周長
	int CircleCircle(CCircle Circle1,double *ang1,double *ang2); 
	int CircleLine(CLine Line1,double *angle1,double *angle2,CPoint3D *Point3D1,CPoint3D *Point3D2);
	bool CheckExcircle(const CLine Line1);
	double GetArea();
	virtual ~CCircle();
private:
	
protected:
	double GetAngle(double fltBaseX,double fltBaseY,double fltX,double fltY);
	void Calculate();
	double m_fltCircumference;//周長
	double m_fltArea;
	CVector m_VectorBase;

};

#endif // !defined(AFX_CIRCLE_H__CF3AC530_AE41_4416_BD3D_37DBA6E883CB__INCLUDED_)
