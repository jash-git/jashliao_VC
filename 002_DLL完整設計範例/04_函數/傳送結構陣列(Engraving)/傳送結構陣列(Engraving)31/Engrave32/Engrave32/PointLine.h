// PointLine.h: interface for the CPointLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINTLINE_H__69995A6B_EE3A_45FF_8A6E_1C63B822B13B__INCLUDED_)
#define AFX_POINTLINE_H__69995A6B_EE3A_45FF_8A6E_1C63B822B13B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Line.h"
#include "Point2D.h"
#include "Point3D.h"
#include "Vector.h"
#include "LineLine.h"
#include "ChangePoint.h"
#include <math.h>
class CPointLine  
{
public:
	CPoint3D m_Point3DQ;
	CVector m_VectorOA;
	CPoint3D m_Obuf,m_Abuf;
	CPoint3D m_Linebuf1,m_Linebuf2;
	CVector m_VectorLine1;
	CPointLine();
	CPointLine(double O_x,double O_y,double A_x,double A_y,double Q_x,double Q_y,double L_x1,double L_y1,double L_x2,double L_y2);
	CPointLine(CPoint3D O,CPoint3D A,CPoint3D Q,CPoint3D L1,CPoint3D L2);
	CPointLine(CVector OA,CPoint3D Q,CVector Line1);
	CPoint3D GetCenter(int n);
	double GetR(int n);
	double GetSita(int n);
	double GetL(int n);
	CPoint3D Getd(int n);
	virtual ~CPointLine();
private:
	double m_fltL;
	double m_fltSita;
	//////////////////////////////////
	CLineLine LL1;
	bool m_bolLL1Check;
	CPoint3D m_Point3DLL1Ans;
	/////////////////////////////////
	CPoint3D m_Point3Dd;
	CChangePoint m_ChangePoint1;
protected:
	double m_fltR[2];
	CPoint3D m_Point3DCenter[2];
	CVector m_VectorOQ;
	void Calculate(int n);

};

#endif // !defined(AFX_POINTLINE_H__69995A6B_EE3A_45FF_8A6E_1C63B822B13B__INCLUDED_)
