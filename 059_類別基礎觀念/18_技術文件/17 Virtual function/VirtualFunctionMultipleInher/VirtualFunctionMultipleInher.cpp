// VirtualFunctionMultipleInher.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Sortable
{
public:
	int data;

	Sortable()		//«Øºc¤l
	{
		data=123;
	}
	~Sortable()   // virtual
	{
		data=0;
	}
};
class Person:public Sortable, public Sortable
{
public:
		int id;
	   Person():Sortable()
	   {
		   id=567;
	   }
	   ~Person()
	   {
		data=1;
	   }
};
int main(int argc, char* argv[])
{
	printf("Hello World!\n");
	return 0;
}

