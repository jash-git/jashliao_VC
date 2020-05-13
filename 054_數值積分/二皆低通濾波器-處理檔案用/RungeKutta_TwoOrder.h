// RungeKutta_TwoOrder.h: interface for the RungeKutta_TwoOrder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RUNGEKUTTA_TWOORDER_H__DE569D02_0ACB_4F16_9D7D_2AF6130BE76F__INCLUDED_)
#define AFX_RUNGEKUTTA_TWOORDER_H__DE569D02_0ACB_4F16_9D7D_2AF6130BE76F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class RungeKutta_TwoOrder  
{
private:
	float K1X1p,K1X2p,K2X1p,K2X2p,K3X1p,K3X2p,K4X1p,K4X2p;
	float XX1p,XX2p;
	float A,B,C,D,E;
	float delT;
public:
	float dU,U;
	float X1,X2,X3;
	float Y,Y1;
	RungeKutta_TwoOrder();
	void calculate(void);
	void initial(float x1,float x2,float x3,float x4,float x5,float x6);
	virtual ~RungeKutta_TwoOrder();

};

RungeKutta_TwoOrder::RungeKutta_TwoOrder()
{
	K1X1p=0.0f;
	K1X2p=0.0f;
	K2X1p=0.0f;
	K2X2p=0.0f;
	K3X1p=0.0f;
	K3X2p=0.0f;
	K4X1p=0.0f;
	K4X2p=0.0f;
	XX1p=0.0f;
	XX2p=0.0f;
	dU=0.0f;U=0.0f;
	X1=0.0f;
	X2=0.0f;
	X3=0.0f;
	A=0.0f;
	B=0.0f;
	C=0.0f;
	D=0.0f;
	E=0.0f;
	delT=0.0f;
	Y=0.0f;
	Y1=0.0f;
}

RungeKutta_TwoOrder::~RungeKutta_TwoOrder()
{

}
void RungeKutta_TwoOrder::calculate(void)
{
	//k1
	K1X1p=0.0f;
	K1X2p=0.0f;
	K2X1p=0.0f;
	K2X2p=0.0f;
	K3X1p=0.0f;
	K3X2p=0.0f;
	K4X1p=0.0f;
	K4X2p=0.0f;
	XX1p=0.0f;
	XX2p=0.0f;
	/////////////////////////////////
	K1X1p=X2;
	K1X2p=(D/A*dU)+(E/A*U)-(B/A*X2)-(C/A*X1);
	XX1p=X1+(delT/2.0f*K1X1p);
	XX2p=X2+(delT/2.0f*K1X2p);
	////////////////////////////////////////////////////
	//k2
	K2X1p=XX2p;
	K2X2p=(D/A*dU)+(E/A*U)-(B/A*XX2p)-(C/A*XX1p);
	XX1p=X1+(delT/2.0f*K2X1p);
	XX2p=X2+(delT/2.0f*K2X2p);
	//////////////////////////////////////////////////////
	//k3
	K3X1p=XX2p;
	K3X2p=(D/A*dU)+(E/A*U)-(B/A*XX2p)-(C/A*XX1p);
	XX1p=X1+(delT/2.0f*K3X1p);
	XX2p=X2+(delT/2.0f*K3X2p);
	/////////////////////////////////////////////////////
	//k4
	K4X1p=XX2p;
	K4X2p=(D/A*dU)+(E/A*U)-(B/A*XX2p)-(C/A*XX1p);
	X1=X1+(delT*(K1X1p+(2.0f*(K2X1p+K3X1p))+K4X1p)/6.0f);
	X2=X2+(delT*(K1X2p+(2.0f*(K2X2p+K3X2p))+K4X2p)/6.0f);	
	/////////////////////////////////////////////////////
	Y=X1;
	Y1=X2;
}
void RungeKutta_TwoOrder::initial(float x1,float x2,float x3,float x4,float x5,float x6)
{
	A=x1;
	B=x2;
	C=x3;
	D=x4;
	E=x5;
	delT=x6;
}

#endif // !defined(AFX_RUNGEKUTTA_TWOORDER_H__DE569D02_0ACB_4F16_9D7D_2AF6130BE76F__INCLUDED_)
