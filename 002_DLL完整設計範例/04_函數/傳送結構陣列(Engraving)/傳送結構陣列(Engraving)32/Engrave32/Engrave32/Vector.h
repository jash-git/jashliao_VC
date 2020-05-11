// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__686AA549_1661_4AA7_8177_4053F7655E7D__INCLUDED_)
#define AFX_VECTOR_H__686AA549_1661_4AA7_8177_4053F7655E7D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
class CVector : public CLine
{
	public:
	CVector(double x1,double y1,double z1,double x2,double y2,double z2);
	CVector(CPoint3D point1,CPoint3D point2);
	CVector(CPoint3D point1);
	CVector();
	~CVector();
	CPoint3D GetVector();
	CPoint3D GetUnitVector();
	CPoint3D operator+(CVector data);
	CPoint3D operator-(CVector data);
	CPoint3D operator*(CVector data);
	double dot(CVector data1,CVector data2,double *ang);
	private:
	protected:
	CPoint3D Vector;
	CPoint3D UnitVector;
	void Calculate();
};
#endif // !defined(AFX_VECTOR_H__686AA549_1661_4AA7_8177_4053F7655E7D__INCLUDED_)
