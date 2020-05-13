// Point2D.h: interface for the CPoint2D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT2D_H__20E95B47_61DD_44C4_AD42_7402760E0BF2__INCLUDED_)
#define AFX_POINT2D_H__20E95B47_61DD_44C4_AD42_7402760E0BF2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PI 3.141596f
class CPoint2D
{
public:
	float m_x,m_y;
	CPoint2D();
	CPoint2D(float x,float y);
	~CPoint2D();
	CPoint2D operator+(CPoint2D data);
	CPoint2D operator-(CPoint2D data);
	CPoint2D operator*(float data);
	CPoint2D operator/(float data);
	void SetData(float x,float y);
private:
protected:
};

#endif // !defined(AFX_POINT2D_H__20E95B47_61DD_44C4_AD42_7402760E0BF2__INCLUDED_)
