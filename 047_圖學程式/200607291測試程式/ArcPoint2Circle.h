// ArcPoint2Circle.h: interface for the CArcPoint2Circle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARCPOINT2CIRCLE_H__F28FD212_249A_485D_891F_E7D21B7EB491__INCLUDED_)
#define AFX_ARCPOINT2CIRCLE_H__F28FD212_249A_485D_891F_E7D21B7EB491__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Arc.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Vector.h"
#define PI 3.1415926f
class CArcPoint2Circle  
{
public:
	CArc m_ArcRip;
	CPoint3D m_Point3DRip,m_Point3DBase; 
	CArcPoint2Circle();
	CArcPoint2Circle(const CArc &RipArc,const CPoint3D &RipPoint3D,const CPoint3D &BasePoint3D);
	void SetData(const CArc &RipArc,const CPoint3D &RipPoint3D,const CPoint3D &BasePoint3D);
	CPoint3D GetCenter();
	double GetR();
	virtual ~CArcPoint2Circle();
private:
	CVector m_VectorRip,m_VectorBase;
protected:
	void Calculate();
	CPoint3D m_Point3DCenter;
	double m_R;
};

#endif // !defined(AFX_ARCPOINT2CIRCLE_H__F28FD212_249A_485D_891F_E7D21B7EB491__INCLUDED_)
