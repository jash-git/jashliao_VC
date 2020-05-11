// LineData.h: interface for the LineData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEDATA_H__EC00DC31_AE01_473A_B059_90C44F35A2B5__INCLUDED_)
#define AFX_LINEDATA_H__EC00DC31_AE01_473A_B059_90C44F35A2B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class LineData  
{
public:
	void Draw();
	bool GetSelect();
	void SetSelect(bool flag);
	void SetData(double x1,double y1,double z1,double x2,double y2,double z2);
	LineData();
	virtual ~LineData();

private:
	bool SelectFlag;
	double X1,Y1,Z1,X2,Y2,Z2;
};

#endif // !defined(AFX_LINEDATA_H__EC00DC31_AE01_473A_B059_90C44F35A2B5__INCLUDED_)
