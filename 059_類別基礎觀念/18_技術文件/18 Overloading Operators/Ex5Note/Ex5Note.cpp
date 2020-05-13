// Ex5Note.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>
class B
{
public:
	void show()
	{
		cout << " I am B"<<endl;
	}

};
class Complex
{
private:
	double re,im;
	B k;
public:
	Complex(double argre,double argim)
	{
		re=argre;im=argim;
	}
	Complex()
	{
		re=0;im=0;
	}
		// function call example
	void operator()()
	{
		cout << " Hi";
	}

	// 指標運算子 example
	B *operator->()
	{
		return &k;
	}
	
	Complex operator+(Complex &b)
	{
		return Complex(re+b.re,im+b.im);
	}
	/* // function overloading 
	   //            只有函式的傳回值型別,不足以區分兩個多載化函式.
	Complex& operator+(Complex &b)
	{
		re=re+b.re;
		im=im+b.im;
		return *this;
	}
*/

	friend Complex& operator/(Complex &a,Complex &b);

};
	Complex& operator/(Complex &a,Complex &b)
	{
		Complex *bb=new Complex(a.re,b.im);
		return *bb;
	}

int main(int argc, char* argv[])
{

	Complex a(2,3),b(3,4);
	Complex c=a+b;
	Complex d;
	a();                      // 呼叫 a() 
	a->show();                // 重新定義 ->
	return 0;
}

