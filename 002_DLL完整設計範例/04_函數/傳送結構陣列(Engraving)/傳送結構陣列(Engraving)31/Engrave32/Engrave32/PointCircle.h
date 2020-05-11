// PointCircle.h: interface for the CPointCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINTCIRCLE_H__9454EDF7_4CB4_4AE4_B1FF_2DC9D7D3B1CD__INCLUDED_)
#define AFX_POINTCIRCLE_H__9454EDF7_4CB4_4AE4_B1FF_2DC9D7D3B1CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Vector.h"
#include <math.h>
class CPointCircle  
{
public:
	CPoint3D m_Point3DQ;
	CVector m_VectorOA;
	CPointCircle();
	CPointCircle(double O_x,double O_y,double A_x,double A_y,double Q_x,double Q_y);
	CPointCircle(CPoint3D O,CPoint3D A,CPoint3D Q);
	CPointCircle(CVector OA,CPoint3D Q);
	CPoint3D GetCenter();
	double GetR();
	double GetSita();
	double GetL();
	CPoint3D Getd();
	virtual ~CPointCircle();
private:
	double m_fltL;
	double m_fltSita;
	CPoint3D m_Point3Dd;
protected:
	double m_fltR;
	CPoint3D m_Point3DCenter;
	CVector m_VectorOQ;
	void Calculate();
};
#endif // !defined(AFX_POINTCIRCLE_H__9454EDF7_4CB4_4AE4_B1FF_2DC9D7D3B1CD__INCLUDED_)
