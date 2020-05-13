// Demo.h: interface for the Demo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMO_H__8044F31A_383D_49CA_866F_CEF982D1BDBA__INCLUDED_)
#define AFX_DEMO_H__8044F31A_383D_49CA_866F_CEF982D1BDBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Base.h"

class Demo : public Base 
{
public:
	void Print();
	Demo();
	virtual ~Demo();

};

#endif // !defined(AFX_DEMO_H__8044F31A_383D_49CA_866F_CEF982D1BDBA__INCLUDED_)
