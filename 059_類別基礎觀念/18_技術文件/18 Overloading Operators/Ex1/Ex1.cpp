// Ex1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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
	Complex add(Complex &b)
	{
		return Complex(re+b.re,im+b.im);
	}
};

int main(int argc, char* argv[])
{
	Complex a(1,2),b(2,3);

	Complex c=a.add(b);

	return 0;
}

