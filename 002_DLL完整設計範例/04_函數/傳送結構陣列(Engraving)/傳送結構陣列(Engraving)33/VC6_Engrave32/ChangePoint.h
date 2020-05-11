// ChangePoint.h: interface for the CChangePoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHANGEPOINT_H__35438A29_6617_488A_813E_1F270F5AAF2C__INCLUDED_)
#define AFX_CHANGEPOINT_H__35438A29_6617_488A_813E_1F270F5AAF2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Vector.h"
#include "LineLine.h"
#include <math.h>
class CChangePoint  
{
public:
	CPoint3D m_Point3Dstart;
	CPoint3D m_Point3DEnd;
	CPoint3D m_Point3DP;
	void SetData(CPoint3D start,CPoint3D end,CPoint3D p);
	void GetData(CPoint3D *start,CPoint3D *end);
	CChangePoint();
	CChangePoint(CPoint3D start,CPoint3D end,CPoint3D p);
	virtual ~CChangePoint();
private:
	CLine m_LineL1,m_LineL2;
protected:
	void Calculate();
	CPoint3D m_Point3DOutStart,m_Point3DOutEnd;

};

#endif // !defined(AFX_CHANGEPOINT_H__35438A29_6617_488A_813E_1F270F5AAF2C__INCLUDED_)
