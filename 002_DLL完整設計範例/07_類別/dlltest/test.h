// test.h: interface for the test class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST_H__ED150D7E_97C7_459C_964B_6D67A60F7C8B__INCLUDED_)
#define AFX_TEST_H__ED150D7E_97C7_459C_964B_6D67A60F7C8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class _declspec(dllexport) test  
{
private:
	float flta,fltb;
public:
	float fltc;
	test();
	float add(float,float);
	virtual ~test();

};

#endif // !defined(AFX_TEST_H__ED150D7E_97C7_459C_964B_6D67A60F7C8B__INCLUDED_)
