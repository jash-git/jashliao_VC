#include<stdio.h>
class RungeKutta_SixOder
{
private:
	//
	//			Hs^5+Is^4+Js^3+Ks^2+Ls^1+M
	//------------------------------------------------
	//		As^6+Bs^5+Cs^4+Ds^3+Es^2+Fs^1+G
	//
	double A,B,C,D,E,F,G,H,I,J,K,L,M;
//////////////////////////////////////////////////////
	//x1=Y(s)
	//x2=S^1Y(s)
	//x3=S^2Y(s)
	//x4=S^3Y(s)
	//x5=S^4Y(s)
	//x6=S^5Y(s)
	double x1,x2,x3,x4,x5,x6;
///////////////////////////////////////////////////////
	//XX1p下一次的x1
	//XX2p下一次的x2
	//XX3p下一次的x3
	//XX4p下一次的x4
	//XX5p下一次的x5
	//XX6p下一次的x6
	double XX1p,XX2p,XX3p,XX4p,XX5p,XX6p;
////////////////////////////////////////////////////////
	//K1,K2,K3,K4分別代表RungeKutta四各參數
	//X1p,X2p,X3p,X4p,X5p,X6p分別代表x1~x6之微分項
	double K1X1p,K1X2p,K1X3p,K1X4p,K1X5p,K1X6p;
	double K2X1p,K2X2p,K2X3p,K2X4p,K2X5p,K2X6p;
	double K3X1p,K3X2p,K3X3p,K3X4p,K3X5p,K3X6p;
	double K4X1p,K4X2p,K4X3p,K4X4p,K4X5p,K4X6p;
/////////////////////////////////////////////////////////
	double delT;//取樣時間
public:
////////////////////////////////////////////////////////
	//輸入
	//U=U(S)
	//Up1=S^1U(S)
	//Up2=S^2U(S)
	//Up3=S^3U(S)
	//Up4=S^4U(S)
	//Up5=S^5U(S)
	double U,Up1,Up2,Up3,Up4,Up5;
///////////////////////////////////////////////////////
	//輸出
	//Y=Y(t)
	//Yp1=S^1Y(t)
	//Yp2=S^2Y(t)
	//Yp3=S^3Y(t)
	//Yp4=S^4Y(t)
	//Yp5=S^5Y(t)
	double Y,Yp1,Yp2,Yp3,Yp4,Yp5;
//////////////////////////////////////////////////////
	RungeKutta_SixOder(double,double,double,double,double,double,double,double,double,double,double,double,double,double);//初始化成員變數
	void RungeKutta_SixOder_compute(double,double,double,double,double,double);
};
