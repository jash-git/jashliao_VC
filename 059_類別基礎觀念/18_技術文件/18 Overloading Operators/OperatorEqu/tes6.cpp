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
	bool operator == (Complex& obj)
	{
		// 若實部與虛部相同才相同
		if(re==obj.re && im == obj.im)
			return true;
		else
			return false;

	}
};
int main(int argc, char* argv[])
{
	Complex a(1,2),b(3,4),c(1,2);
	if(a==b)
	{
		printf(" a !=b \n");
	}
	if(a==c)
	{
		printf("a==c \n");
	}
	return 0;
}

