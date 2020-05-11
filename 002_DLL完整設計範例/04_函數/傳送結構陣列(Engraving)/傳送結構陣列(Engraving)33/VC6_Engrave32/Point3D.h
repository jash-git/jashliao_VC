// Point3D.h: interface for the CPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT3D_H__F2177E40_F893_4B1A_A55E_93525AD9CBD6__INCLUDED_)
#define AFX_POINT3D_H__F2177E40_F893_4B1A_A55E_93525AD9CBD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Point2D.h"
class CPoint3D : public CPoint2D
{
public:
	double m_z;
	CPoint3D();
	CPoint3D(double x,double y,double z);
	~CPoint3D();
	CPoint3D operator+(CPoint3D data);
	CPoint3D operator-(CPoint3D data);
	CPoint3D operator*(double data);
	CPoint3D operator/(double data);
	void SetData(double x,double y,double z);
private:
protected:
};

#endif // !defined(AFX_POINT3D_H__F2177E40_F893_4B1A_A55E_93525AD9CBD6__INCLUDED_)
