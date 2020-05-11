// LineLine.h: interface for the CLineLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINELINE_H__46AA2CF4_6C22_4A88_9E3E_9574D634C974__INCLUDED_)
#define AFX_LINELINE_H__46AA2CF4_6C22_4A88_9E3E_9574D634C974__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Vector.h"
#include <math.h>
class CLineLine  
{
public:
	CLine m_Line1,m_Line2;
	bool GetAns(CPoint3D *Ans);
	void SetValue(const CLine &L1,const CLine &L2);
	CLineLine();
	CLineLine(const CLine &L1,const CLine &L2);
	virtual ~CLineLine();
private:
	int m_intL1,m_intL2;
	double m_flta1,m_fltb1;
	double m_flta2,m_fltb2;
	CPoint3D m_Point3DStart1,m_Point3DEnd1;
	CPoint3D m_Point3DStart2,m_Point3DEnd2;
protected:
	bool m_bolCheck;
	CPoint3D m_Point3DAns;
	void account1();
	void account2();
	void Calculate();
};

#endif // !defined(AFX_LINELINE_H__46AA2CF4_6C22_4A88_9E3E_9574D634C974__INCLUDED_)
