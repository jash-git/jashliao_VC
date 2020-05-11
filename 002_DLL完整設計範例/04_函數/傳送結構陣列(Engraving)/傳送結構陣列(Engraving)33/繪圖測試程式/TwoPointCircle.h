// TwoPointCircle.h: interface for the CTwoPointCircle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TWOPOINTCIRCLE_H__2D9ADA03_3415_4CFF_A150_F3918A018CAF__INCLUDED_)
#define AFX_TWOPOINTCIRCLE_H__2D9ADA03_3415_4CFF_A150_F3918A018CAF__INCLUDED_

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
class CTwoPointCircle  
{
public:
	CLine m_LineRip;
	CPoint3D m_Point3DBase,m_Point3DRip;
	CTwoPointCircle();
	CTwoPointCircle(const CLine &RipLine,const CPoint3D &RipPoint,const CPoint3D &BasePoint);
	void SetData(const CLine &RipLine,const CPoint3D &RipPoint,const CPoint3D &BasePoint);
	virtual ~CTwoPointCircle();
	CPoint3D GetCenter();
	double GetR();
private:
	CVector L1,L2,L3;
protected:
	CPoint3D m_Point3DCenter;
	double m_R;
	void Calculate();

};

#endif // !defined(AFX_TWOPOINTCIRCLE_H__2D9ADA03_3415_4CFF_A150_F3918A018CAF__INCLUDED_)
