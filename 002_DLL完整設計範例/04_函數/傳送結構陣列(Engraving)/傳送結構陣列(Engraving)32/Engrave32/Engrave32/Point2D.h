// Point2D.h: interface for the CPoint2D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT2D_H__4605B3D8_8D5A_400D_85DE_F4B78D05FEB0__INCLUDED_)
#define AFX_POINT2D_H__4605B3D8_8D5A_400D_85DE_F4B78D05FEB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define PI 3.1415926f
using namespace std;
class CPoint2D
{
public:
	double m_x,m_y;
	CPoint2D();
	CPoint2D(double x,double y);
	~CPoint2D();
	CPoint2D operator+(CPoint2D data);
	CPoint2D operator-(CPoint2D data);
	CPoint2D operator*(double data);
	CPoint2D operator/(double data);
	void SetData(double x,double y);
private:
protected:
};
#endif // !defined(AFX_POINT2D_H__4605B3D8_8D5A_400D_85DE_F4B78D05FEB0__INCLUDED_)
