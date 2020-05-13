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
	int operator [](int index)
	{
		if (index==0)
			return re;
		else 
			return im;

	}
};
int main(int argc, char* argv[])
{
	Complex a(1,2);
	int data=a[1];
	return 0;
}

