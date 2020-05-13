// Ex4ErrorDemo.cpp : Defines the entry point for the console application.
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
	
	int operator-(int i)
	{
		return re-i;
	}
	
//	friend int operator+(int i);   // 錯誤: 至少要有一個 class 物件
	friend int operator+(Complex &a,int i);
};
friend int operator+(Complex &a,int i)
{
    return i+1;
}
/*
int operator+(int i)
{
	return i;
}
*/
int main(int argc, char* argv[])
{
	Complex a(2,3),b(3,4);

	
	int sub=a-1;

	int add=a+2;
	return 0;
}

