// Demo.h: interface for the Demo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMO_H__1DD1CC3C_1A18_4486_95F1_1A74ED8E5AF1__INCLUDED_)
#define AFX_DEMO_H__1DD1CC3C_1A18_4486_95F1_1A74ED8E5AF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"

class Demo : public Base  
{
public:
	void Print();
	void Set(int na);
	Demo(int na);
	virtual ~Demo();

};

#endif // !defined(AFX_DEMO_H__1DD1CC3C_1A18_4486_95F1_1A74ED8E5AF1__INCLUDED_)
