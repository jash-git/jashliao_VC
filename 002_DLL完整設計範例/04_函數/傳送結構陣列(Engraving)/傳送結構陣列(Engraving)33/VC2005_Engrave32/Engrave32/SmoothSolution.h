// SmoothSolution.h: interface for the CSmoothSolution class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SMOOTHSOLUTION_H__BD56F601_8B8B_4474_9635_67C404C01141__INCLUDED_)
#define AFX_SMOOTHSOLUTION_H__BD56F601_8B8B_4474_9635_67C404C01141__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
#include "Arc.h"
#include "Circle.h"
#include "Vector.h"
#include "LineLine.h"
class CSmoothSolution  
{
public:
	CSmoothSolution();
	CSmoothSolution(const CVector &Vector1,const CLine &Line1);
	CSmoothSolution(const CVector &Vector1,const CArc &Arc1);
	void SetData(const CVector &Vector1,const CLine &Line1);
	void SetData(const CVector &Vector1,const CArc &Arc1);
	bool GetAns(CCircle *CC1);
	CVector m_VectorBase;
	CLine m_Line1;
	CArc m_Arc1;
	virtual ~CSmoothSolution();
private:
	CPoint3D m_P3DCenter;
	//////////////////////////////////////
	double m_L,m_R,m_Sita;
	//////////////////////////////////////////////////
protected:
	bool Calculate();
	long lngLineArc;//0->Line,1->Arc
	CCircle m_CircleAns;//Output Data
};

#endif // !defined(AFX_SMOOTHSOLUTION_H__BD56F601_8B8B_4474_9635_67C404C01141__INCLUDED_)
