// LineData.cpp: implementation of the LineData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TestGL.h"
#include "LineData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

LineData::LineData()
{
    SelectFlag=false;
}

LineData::~LineData()
{

}


void LineData::SetData(double x1, double y1, double z1, double x2, double y2, double z2)
{
    X1=x1;Y1=y1;Z1=z1;
	X2=x2;Y2=y2;Z2=z2;
}

void LineData::SetSelect(bool flag)
{
    SelectFlag=flag;
}

bool LineData::GetSelect()
{
    return SelectFlag;
} 

void LineData::Draw()
{
	if (SelectFlag==false)
	   glColor3f(1.,0.5,0.); //¾ï¦â
	else
       glColor3f(1.,1.,1.); //¥Õ¦â
    glBegin(GL_LINES);
      glVertex3d(X1,Y1,Z1);
      glVertex3d(X2,Y2,Z2);
	glEnd();
}
