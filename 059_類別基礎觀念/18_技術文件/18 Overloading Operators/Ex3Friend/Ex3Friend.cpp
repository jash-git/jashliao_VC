// Ex3Friend.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Complex
{
		//宣告 operator+ 是 Complex的好朋友
	friend Complex operator+(Complex &a,Complex &b);
private:
	double re,im;
public:
	Complex(double argre,double argim)
	{
		re=argre;im=argim;
	}

	// --的範例
	Complex& operator--()  // 傳回 reference type
	{
		re=re-1;
		im=im-1;
		return *this;
	}
	Complex()
	{
		re=0;im=0;
	}


};
//定義 operator+的內容
Complex operator+(Complex &a,Complex &b)
{
	return Complex(a.re+b.re,a.im+b.im);
}
int main(int argc, char* argv[])
{
	Complex a(2,3),b(3,4);

	Complex c=a+b;
	a--;

	return 0;
}

