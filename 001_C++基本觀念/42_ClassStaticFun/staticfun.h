// staticfun.h: interface for the Cstaticfun class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATICFUN_H__F7F60DB1_80EB_4D52_8816_3D04E2F84642__INCLUDED_)
#define AFX_STATICFUN_H__F7F60DB1_80EB_4D52_8816_3D04E2F84642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class Cstaticfun  
{
public:
	Cstaticfun();
	virtual ~Cstaticfun();
	static int add(int a,int b);
	double dot(double a,double b);

};

#endif // !defined(AFX_STATICFUN_H__F7F60DB1_80EB_4D52_8816_3D04E2F84642__INCLUDED_)
