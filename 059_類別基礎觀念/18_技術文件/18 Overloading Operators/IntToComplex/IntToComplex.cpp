// IntToComplex.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Complex {
private:
	int re,im;
public:
	Complex()
	{
		re=0;im=0;
	}
	// 整數轉換成Complex的定義
	Complex(int i)
	{
		re=1;
		im=0;
	}
};
int main(int argc, char* argv[])
{
	Complex a=3;                   // 會呼叫建構子 Complex(int i)
	return 0;
}

