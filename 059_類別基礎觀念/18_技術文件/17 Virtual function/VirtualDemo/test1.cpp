// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Based{
public:
	virtual int getData()
	{
		return 1;
	}
};
class Derived:public Based{
public:
	virtual int getData()
	{
		return 2;
	}

};
int main(int argc, char* argv[])
{
	Based mybase;
	Derived myderived;
	Based *vp;
	vp=&mybase;
	vp->getData();
	vp=&myderived;
	vp->getData();
	printf("Hello World!\n");
	return 0;
}

