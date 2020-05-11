#include "stdafx.h"
//#include "SDIShow.h"
#include "Tool.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

CTool::CTool(void):CCircle()
{
	m_gouge=false;
	m_Depth=-1.0;
}
CTool::CTool(CPoint3D Center,double R,double Depth) : CCircle(Center,R)
{
	m_gouge=false;
	m_Depth=Depth;
}
CTool::CTool(double Center_x,double Center_y,double Center_z,double R,double Depth)
: CCircle(Center_x,Center_y,Center_z,R)
{
	m_gouge=false;
	m_Depth=Depth;
}
CTool::~CTool(void)
{

}
