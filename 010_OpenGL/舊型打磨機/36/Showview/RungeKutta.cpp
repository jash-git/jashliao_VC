// RungeKutta.cpp: implementation of the RungeKutta class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RungeKutta.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
//RungeKutta RK;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
RungeKutta::RungeKutta()
{
/*	delT=t;
	////////////////////////////
	A=a;B=b;C=c;D=d;
	E=e;F=f;G=g;H=h;
	I=i;J=j;K=k;L=l;M=m;
*/	////////////////////////////
	Y=0.0;Yp1=0.0;Yp2=0.0;Yp3=0.0;Yp4=0.0;Yp5=0.0;
	//////////////////////////// 
	U=0.0;Up1=0.0;Up2=0.0;Up3=0.0;Up4=0.0;Up5=0.0;
	////////////////////////////
	K1X1p=0.0;K1X2p=0.0;K1X3p=0.0;K1X4p=0.0;K1X5p=0.0;K1X6p=0.0;
	K2X1p=0.0;K2X2p=0.0;K2X3p=0.0;K2X4p=0.0;K2X5p=0.0;K2X6p=0.0;
	K3X1p=0.0;K3X2p=0.0;K3X3p=0.0;K3X4p=0.0;K3X5p=0.0;K3X6p=0.0;
	K4X1p=0.0;K4X2p=0.0;K4X3p=0.0;K4X4p=0.0;K4X5p=0.0;K4X6p=0.0;
	////////////////////////////
	XX1p=0.0;XX2p=0.0;XX3p=0.0;XX4p=0.0;XX5p=0.0;XX6p=0.0;
	////////////////////////////
	x1=0.0;x2=0.0;x3=0.0;x4=0.0;x5=0.0;x6=0.0;
	////////////////////////////////////
}

RungeKutta::SetPara(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double m, double t)
{

	////////////////////////////////////////
	delT = t;
	A = a; B = b; C = c; D = d; E = e; F = f; G = g;
	H = h; I = i; J = j; K = k; L = l; M = m;
	
	////////////////////////////////////////
/*
	Y   = 0.0; 
	Yp1 = 0.0; 
	Yp2 = 0.0; 
	Yp3 = 0.0; 
	Yp4 = 0.0; 
	Yp5 = 0.0;

	////////////////////////////////////////
	U   = 0.0; 
	Up1 = 0.0; 
	Up2 = 0.0; 
	Up3 = 0.0; 
	Up4 = 0.0; 
	Up5 = 0.0;

	////////////////////////////////////////
	K1X1p = 0.0; K1X2p = 0.0; K1X3p = 0.0; K1X4p = 0.0; K1X5p = 0.0; K1X6p = 0.0;
	K2X1p = 0.0; K2X2p = 0.0; K2X3p = 0.0; K2X4p = 0.0; K2X5p = 0.0; K2X6p = 0.0;
	K3X1p = 0.0; K3X2p = 0.0; K3X3p = 0.0; K3X4p = 0.0; K3X5p = 0.0; K3X6p = 0.0;
	K4X1p = 0.0; K4X2p = 0.0; K4X3p = 0.0; K4X4p = 0.0; K4X5p = 0.0; K4X6p = 0.0;

	////////////////////////////////////////
	XX1p = 0.0; XX2p = 0.0; XX3p = 0.0; XX4p = 0.0; XX5p = 0.0; XX6p = 0.0;

	////////////////////////////////////////
	x1 = 0.0; x2 = 0.0; x3 = 0.0; x4 = 0.0; x5 = 0.0; x6 = 0.0;
*/
}

void RungeKutta::Compute(double u1, double u2, double u3, double u4, double u5, double u6)
{	////////////////////////////////////////
	U=u1;Up1=u2;Up2=u3;Up3=u4;Up4=u5;Up5=u6;
	/////////////////////////////////////////
	//K1
	K1X1p=x2;
	K1X2p=x3;
	K1X3p=x4;
	K1X4p=x5;
	K1X5p=x6;
	K1X6p=-(B/A)*x6-(C/A)*x5-(D/A)*x4-(E/A)*x3-(F/A)*x2-(G/A)*x1+(H/A)*Up5+(I/A)*Up4+(J/A)*Up3+(K/A)*Up2+(L/A)*Up1+(M/A)*U;
	
	XX1p=x1+(delT/2.0)*K1X1p;
	XX2p=x2+(delT/2.0)*K1X2p;
	XX3p=x3+(delT/2.0)*K1X3p;
	XX4p=x4+(delT/2.0)*K1X4p;
	XX5p=x5+(delT/2.0)*K1X5p;
	XX6p=x6+(delT/2.0)*K1X6p;
	//K2
	K2X1p=XX2p;
	K2X2p=XX3p;
	K2X3p=XX4p;
	K2X4p=XX5p;
	K2X5p=XX6p;
	K2X6p=-(B/A)*XX6p-(C/A)*XX5p-(D/A)*XX4p-(E/A)*XX3p-(F/A)*XX2p-(G/A)*XX1p+(H/A)*Up5+(I/A)*Up4+(J/A)*Up3+(K/A)*Up2+(L/A)*Up1+(M/A)*U;
	
	XX1p=x1+(delT/2.0)*K2X1p;
	XX2p=x2+(delT/2.0)*K2X2p;
	XX3p=x3+(delT/2.0)*K2X3p;
	XX4p=x4+(delT/2.0)*K2X4p;
	XX5p=x5+(delT/2.0)*K2X5p;
	XX6p=x6+(delT/2.0)*K2X6p;
	//K3
	K3X1p=XX2p;
	K3X2p=XX3p;
	K3X3p=XX4p;
	K3X4p=XX5p;
	K3X5p=XX6p;
	K3X6p=-(B/A)*XX6p-(C/A)*XX5p-(D/A)*XX4p-(E/A)*XX3p-(F/A)*XX2p-(G/A)*XX1p+(H/A)*Up5+(I/A)*Up4+(J/A)*Up3+(K/A)*Up2+(L/A)*Up1+(M/A)*U;
	
	XX1p=x1+delT*K3X1p;
	XX2p=x2+delT*K3X2p;
	XX3p=x3+delT*K3X3p;
	XX4p=x4+delT*K3X4p;
	XX5p=x5+delT*K3X5p;
	XX6p=x6+delT*K3X6p;
	//K4
	K4X1p=XX2p;
	K4X2p=XX3p;
	K4X3p=XX4p;
	K4X4p=XX5p;
	K4X5p=XX6p;
	K4X6p=-(B/A)*XX6p-(C/A)*XX5p-(D/A)*XX4p-(E/A)*XX3p-(F/A)*XX2p-(G/A)*XX1p+(H/A)*Up5+(I/A)*Up4+(J/A)*Up3+(K/A)*Up2+(L/A)*Up1+(M/A)*U;
	//////////////////////////////////////////
	x1=x1+delT*(K1X1p+2.0*(K2X1p+K3X1p)+K4X1p)/6.0;
	x2=x2+delT*(K1X2p+2.0*(K2X2p+K3X2p)+K4X2p)/6.0;
	x3=x3+delT*(K1X3p+2.0*(K2X3p+K3X3p)+K4X3p)/6.0;
	x4=x4+delT*(K1X4p+2.0*(K2X4p+K3X4p)+K4X4p)/6.0;
	x5=x5+delT*(K1X5p+2.0*(K2X5p+K3X5p)+K4X5p)/6.0;
	x6=x6+delT*(K1X6p+2.0*(K2X6p+K3X6p)+K4X6p)/6.0;
	Y=x1;
	Yp1=x2;
	Yp2=x3;
	Yp3=x4;
	Yp4=x5;
	Yp5=x6;
}

RungeKutta::~RungeKutta()
{

}
