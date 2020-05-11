// RungeKutta.h: interface for the RungeKutta class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUNGEKUTTA_H__5B25ABE9_F3E4_4E7E_92DA_8A7C9363EDD6__INCLUDED_)
#define AFX_RUNGEKUTTA_H__5B25ABE9_F3E4_4E7E_92DA_8A7C9363EDD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class RungeKutta  
{
public:
	//
	//		Hs^5+Is^4+Js^3+Ks^2+Ls^1+M
	//---------------------------------------
	//	As^6+Bs^5+Cs^4+Ds^3+Es^2+Fs^1+G
	//
	double A, B, C, D, E, F, G, H, I, J, K, L, M;
	
	////////////////////////////////////////
	//x1 =     Y(s)
	//x2 = s^1*Y(s) = s^1*x1
	//x3 = s^2*Y(s) = s^2*x2
	//x4 = s^3*Y(s) = s^3*x3
	//x5 = s^4*Y(s) = s^4*x4
	//x6 = s^5*Y(s) = s^5*x5
	double x1, x2, x3, x4, x5, x6;

	////////////////////////////////////////
	//XX1p 下一次的x1
	//XX2p 下一次的x2
	//XX3p 下一次的x3
	//XX4p 下一次的x4
	//XX5p 下一次的x5
	//XX6p 下一次的x6
	double XX1p, XX2p, XX3p, XX4p, XX5p, XX6p;

	////////////////////////////////////////
	//K1, K2, K3, K4分別代表RungeKutta四個參數
	//X1p, X2p, X3p, X4p, X5p, X6p分別代表x1~x6之微分項
	double K1X1p, K1X2p, K1X3p, K1X4p, K1X5p, K1X6p;
	double K2X1p, K2X2p, K2X3p, K2X4p, K2X5p, K2X6p; 
	double K3X1p, K3X2p, K3X3p, K3X4p, K3X5p, K3X6p; 
	double K4X1p, K4X2p, K4X3p, K4X4p, K4X5p, K4X6p; 

	////////////////////////////////////////
	double delT;	//取樣時間
	
public:
	////////////////////////////////////////
	//輸入
	//U   =     U(s)
	//Up1 = s^1*U(s)
	//Up2 = s^2*U(s)
	//Up3 = s^3*U(s)
	//Up4 = s^4*U(s)
	//Up5 = s^5*U(s)
	double U, Up1, Up2, Up3, Up4, Up5;
	
	////////////////////////////////////////
	//輸出
	//
	//Yp1 = s^1*Y(t)
	//Yp2 = s^2*Y(t)
	//Yp3 = s^3*Y(t)
	//Yp4 = s^4*Y(t)
	//Yp5 = s^5*Y(t)
	double Y, Yp1, Yp2, Yp3, Yp4, Yp5;

public:
	RungeKutta();
	RungeKutta(double, double , double, double, double, double, double, double, double, double, double, double, double, double);
	void Compute(double, double, double, double, double, double);
	virtual ~RungeKutta();
	////////////////////////////////////////
};

#endif // !defined(AFX_RUNGEKUTTA_H__5B25ABE9_F3E4_4E7E_92DA_8A7C9363EDD6__INCLUDED_)
