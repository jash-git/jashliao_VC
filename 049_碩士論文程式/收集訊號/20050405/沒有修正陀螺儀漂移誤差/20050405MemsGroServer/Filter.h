// Filter.h: interface for the CFilter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILTER_H__60D7AD1D_4A47_42A3_94AF_D5987F3CB655__INCLUDED_)
#define AFX_FILTER_H__60D7AD1D_4A47_42A3_94AF_D5987F3CB655__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
struct lowpass_secorder{

	float fa,fb,fc,fd,fe;

	float dut,ut,x1,x2;

};
class CFilter  
{
public:
	CFilter();
	float SecOrderLowPass(float u);
	lowpass_secorder secorder1;
	virtual ~CFilter();
private:
	float K1X1p_secorder1,K2X1p_secorder1,K3X1p_secorder1,K4X1p_secorder1;
	float K1X2p_secorder1,K2X2p_secorder1,K3X2p_secorder1,K4X2p_secorder1;
	float XX1p_secorder1,Y_secorder1;
	float XX2p_secorder1;
};

#endif // !defined(AFX_FILTER_H__60D7AD1D_4A47_42A3_94AF_D5987F3CB655__INCLUDED_)
