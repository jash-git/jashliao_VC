//ExternalVar.h
#include "stdafx.h"
#include <afxtempl.h>
#include <stdlib.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Arc.h"
#include "ChangePoint.h"
#include "Circle.h"
#include "CircleRightLeft.h"
#include "InputData.h"
#include "Line.h"
#include "LineLine.h"
#include "NoSolution.h"
#include "Point2D.h"
#include "Point3D.h"
#include "PointArc.h"
#include "PointCircle.h"
#include "PointLine.h"
#include "RipArcCircle.h"
#include "Tool.h"
#include "TwoPointCircle.h"
#include "Vector.h"
typedef struct EngarveElement{
	long Type;//1 :Line  2:Arc  3:Circle
	long CCW;//CW:0      CCW:1
	double X1;//XO
	double Y1;//YO
	double Z1;//ZO
	double X2;//R
	double Y2;//A1
	double Z2;//A2
}EngarveElement;
///////////////////////////////////////
extern EngarveElement *gEE;//抓取結構資料
extern CArray <CInputData,CInputData> gArray;//儲存輸入的所有物件
extern CArray <CCircle,CCircle> gArrayBuffer;//暫存一個分段點的所有解
extern CArray <CCircle,CCircle> gArrayAns;
extern  CInputData gInputData;//儲存由結構轉成物件的資料
extern  long lngBlockNumber,*lngBlockData;//儲存紀錄block數，和每一個block內的Entity數目
extern  CPoint3D *Point3DAns;//用來儲存產生的分段點資料
extern  double dblTolerance;//存放公差
extern  long  lngDirection;//存放一個block的順逆轉，0->順；1->逆
extern  CPoint3D *Point3DCross;//存放每一個entity的終點
//////////////////////////////////////