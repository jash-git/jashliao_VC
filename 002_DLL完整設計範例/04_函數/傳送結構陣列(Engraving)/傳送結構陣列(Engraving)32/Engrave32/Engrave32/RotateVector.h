// RotateVector.h: interface for the CRotateVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROTATEVECTOR_H__117A5C2E_A24B_4B5A_A593_8AD3E62ED288__INCLUDED_)
#define AFX_ROTATEVECTOR_H__117A5C2E_A24B_4B5A_A593_8AD3E62ED288__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Vector.h"
class CRotateVector  
{
public:
	CRotateVector();
	CRotateVector(const CVector &Vector1);
	void SetData(const CVector &Vector1);
	CVector Rotate(long axle,double angle);//0->X,1->Y,2->Z
	virtual ~CRotateVector();
	CVector m_VectorBase;
private:
	long m_lngAxle;
	double m_dblAngle;
	CPoint3D m_P3DStart,m_P3DSEnd;
protected:
	CVector m_VectorAns; 
};

#endif // !defined(AFX_ROTATEVECTOR_H__117A5C2E_A24B_4B5A_A593_8AD3E62ED288__INCLUDED_)
