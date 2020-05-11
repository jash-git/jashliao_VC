// RipAngle2Vector.h: interface for the CRipAngle2Vector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RIPANGLE2VECTOR_H__2801EA0B_B975_42E3_A1C6_F227339D70F3__INCLUDED_)
#define AFX_RIPANGLE2VECTOR_H__2801EA0B_B975_42E3_A1C6_F227339D70F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Vector.h"
class CRipAngle2Vector  
{
public:
	CRipAngle2Vector();
	CRipAngle2Vector(const CVector &V1,const CVector &V2);
	//void Calculate();
	void SetData(const CVector &V1,const CVector &V2);
	double GetNumber();
	double GetUnitAngle();
	CVector m_Vector1,m_Vector2;
	virtual ~CRipAngle2Vector();
private:
protected:
	void Calculate();
	double m_dblAngle;
	double m_dblUnitAngle;
	long m_lngNumber;
};

#endif // !defined(AFX_RIPANGLE2VECTOR_H__2801EA0B_B975_42E3_A1C6_F227339D70F3__INCLUDED_)
