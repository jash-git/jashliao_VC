// test6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Error1{
public:
	int data;
	Error1()
	{
		data=123;
	}
};

int main(int argc, char* argv[])
{
	try{
		throw Error1();

	}
	catch ( Error1 &obj)
		{
		printf("error=%d",obj.data);
	}
	return 0;
}

