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

#endif // !defined(AFX_RUNGEKUTTA_TWOORDER_H__DE569D02_0ACB_4F16_9D7D_2AF6130BE76F__INCLUDED_)
