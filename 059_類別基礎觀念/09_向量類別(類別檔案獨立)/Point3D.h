// Point3D.h: interface for the CPoint3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT3D_H__198D68B9_733E_43A2_89B9_4C434613F4EC__INCLUDED_)
#define AFX_POINT3D_H__198D68B9_733E_43A2_89B9_4C434613F4EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Point2D.h"
class CPoint3D : public CPoint2D
{
public:
	float m_z;
	CPoint3D();
	CPoint3D(float x,float y,float z);
	~CPoint3D();
	CPoint3D operator+(CPoint3D data);
	CPoint3D operator-(CPoint3D data);
	CPoint3D operator*(float data);
	CPoint3D operator/(float data);
	void SetData(float x,float y,float z);
private:
protected:
};


#endif // !defined(AFX_POINT3D_H__198D68B9_733E_43A2_89B9_4C434613F4EC__INCLUDED_)
