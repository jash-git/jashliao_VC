// tes6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Complex{
public:
	int re,im;
	Complex(int re,int im)
	{
		this->re=re;
		this->im=im;
	}
	Complex operator +(Complex& obj)
	{
		return Complex(re+obj.re,im+obj.im);
	}
};
int main(int argc, char* argv[])
{
	Complex a(1,2),b(3,4);
	Complex c=a+b;                    // 第一種呼叫方式
	Complex d=a.operator +(b);        // 第二種呼叫方式
	return 0;
}

