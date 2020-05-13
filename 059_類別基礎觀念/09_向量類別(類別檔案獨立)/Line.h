// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__1843BA3B_B250_445F_A8EF_20AEE6F0BDC2__INCLUDED_)
#define AFX_LINE_H__1843BA3B_B250_445F_A8EF_20AEE6F0BDC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Point3D.h"
#define PI 3.141596f
class CLine
{
public:
	CPoint3D m_StartPoint,m_EndPoint;
	CLine(float x1,float y1,float z1,float x2,float y2,float z2);
	CLine(CPoint3D point1,CPoint3D point2);
	CLine();
	~CLine();
	void Calculate();
	void SetData(float x1,float y1,float z1,float x2,float y2,float z2);
	void SetData(CPoint3D point1,CPoint3D point2);
	float GetDistance();
private:
	float m_SquareX,m_SquareY,m_SquareZ;
protected:
	float m_LessX,m_LessY,m_LessZ;//當用public繼承時會變成private
	float m_Distance;
};


#endif // !defined(AFX_LINE_H__1843BA3B_B250_445F_A8EF_20AEE6F0BDC2__INCLUDED_)
