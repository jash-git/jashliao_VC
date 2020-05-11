// test.cpp: implementation of the test class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mfcdll.h"
#include "test.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

test::test()
{
	flta=0;
	fltb=0;
	fltc=0;
}

test::~test()
{

}
float test::add(float a,float b)
{
	flta=a;
	fltb=b;
	fltc=flta+fltb;
	return fltc;
}
