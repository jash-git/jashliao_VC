#pragma once
#include "Circle.h"

class CTool :
	public CCircle
{
public:
	bool m_gouge;//判斷是否要挑角，true是要挑角，false是不要挑角
	double m_Depth;
	CTool(void);
	CTool(CPoint3D Center,double R,double Depth);
	CTool(double Center_x,double Center_y,double Center_z,double R,double Depth);
	void SetData(CPoint3D Center,double R,bool gouge);
public:
	~CTool(void);
};
