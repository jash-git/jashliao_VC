// Vector.h: interface for the CVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VECTOR_H__0B4EB39C_FE45_4A22_A77F_FAEBB183DDCE__INCLUDED_)
#define AFX_VECTOR_H__0B4EB39C_FE45_4A22_A77F_FAEBB183DDCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
class CVector : public CLine
{
	public:
	CVector(float x1,float y1,float z1,float x2,float y2,float z2);
	CVector(CPoint3D point1,CPoint3D point2);
	CVector(CPoint3D point1);
	CVector();
	~CVector();
	CPoint3D GetVector();
	CPoint3D GetUnitVector();
	CPoint3D operator+(CVector data);
	CPoint3D operator-(CVector data);
	CPoint3D operator*(CVector data);
	float dot(CVector data1,CVector data2,float *ang);
	private:
	protected:
	CPoint3D Vector;
	CPoint3D UnitVector;
	void Calculate();
};

#endif // !defined(AFX_VECTOR_H__0B4EB39C_FE45_4A22_A77F_FAEBB183DDCE__INCLUDED_)
