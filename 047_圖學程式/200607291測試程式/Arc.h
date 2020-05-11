// Arc.h: interface for the CArc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARC_H__E75A3D7B_0780_4E18_B2CA_12703332E06A__INCLUDED_)
#define AFX_ARC_H__E75A3D7B_0780_4E18_B2CA_12703332E06A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Circle.h"
class CArc : public CCircle   
{
public:
	double m_fltStartAngle,m_fltEndAngle;//起始與結束弧度
	CArc();
	CArc(CPoint3D Center,double R,double StartAngle,double EndAngle);
	CArc(double Center_x,double Center_y,double Center_z,double R,double StartAngle,double EndAngle);
	void SetData(CPoint3D Center,double R,double StartAngle,double EndAngle);
	double GetCircumference();//取得周長
	double GetArea();
	int ArcCircle(CCircle Circle);
	virtual ~CArc();
private:
protected:
	CPoint3D m_Point3DCross[5];//儲存交點,其中m_x儲存弧度，m_z儲存狀態
	int intCross;
	bool IsInArc(double angle);
	void Calculate();

};
#endif // !defined(AFX_ARC_H__E75A3D7B_0780_4E18_B2CA_12703332E06A__INCLUDED_)
