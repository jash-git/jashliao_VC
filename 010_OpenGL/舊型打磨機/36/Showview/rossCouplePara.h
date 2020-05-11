// rossCouplePara.h: interface for the CrossCouplePara class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROSSCOUPLEPARA_H__2DA84D05_0347_4B51_BCF1_1915FC11E169__INCLUDED_)
#define AFX_ROSSCOUPLEPARA_H__2DA84D05_0347_4B51_BCF1_1915FC11E169__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdio.h>
#include <math.h>

#define PI 3.141592654

class CrossCouplePara
{
private:
	double d2r;
	double kpx, kix, kdx;
	//	     Kdxs^2+Kpxs^1+Kix
	//Gcx =	-------------------
	//		    	s
	double kpy, kiy, kdy;
	//	     Kdys^2+Kpys^1+Kiy
	//Gcy =	-------------------
	//		    	s
	double kpc, kic, kdc;
	//	     Kdcs^2+Kpcs^1+Kic
	//Gcc =	-------------------
	//		    	s
	double Theta;
	double Cx;
	double Cy;
	double ax, bx;
	//		    Bx
	//Gpx = ---------------
	//		 s^2+Ax*s^1
	double ay, by;
	//		    By
	//Gpy = ---------------
	//		 s^2+Ay*s^1
	double K11[6], K12[6], K21[6], K22[6];
	double Delta[7];

public:
	CrossCouplePara();	//建構子

	void SetPara(double Parameter[14]);	//設定參數
	void GetPara(double delta[7], double k11[6], double k12[6], double k21[6], double k22[6]);
	Compute(void);	//計算
	~CrossCouplePara();	//解構子
};

#endif // !defined(AFX_ROSSCOUPLEPARA_H__2DA84D05_0347_4B51_BCF1_1915FC11E169__INCLUDED_)
