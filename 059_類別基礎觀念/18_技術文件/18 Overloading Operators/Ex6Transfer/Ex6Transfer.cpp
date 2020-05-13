// Ex6Transfer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class B
{
	double value;
public:
	B()
	{
		value=0;
	}
	B(double i)
	{
		value=i;
	}
};
class Complex
{
private:
	double re,im;
	
public:
	Complex(double argre,double argim)
	{
		re=argre;im=argim;
	}
	Complex()
	{
		re=0;im=0;
	}
	// 俱计锣传Complex絛ㄒ
	Complex(int i)
	{
		re=i;
		im=0;
	}
    // Complex锣传 double 絛ㄒ
	operator double()
	{
		return re;
	}
	
	// Complex锣传  object絛ㄒ
	operator B()
	{
		return B(re);
		/* ┪
			return re;
		*/

	}
};
int main(int argc, char* argv[])
{
	Complex a=3;      // 俱计锣传Complex絛ㄒ
	
	double dValue=a;  // Complex锣传 double 絛ㄒ
	

	B b=a;             // Complex锣传  object絛ㄒ
	return 0;
}

