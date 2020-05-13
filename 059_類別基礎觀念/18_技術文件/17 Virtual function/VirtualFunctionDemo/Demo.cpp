// Demo.cpp: implementation of the Demo class.
//
//////////////////////////////////////////////////////////////////////
#include<iostream.h>
#include "Demo.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Demo::Demo()
{

}

Demo::~Demo()
{

}

void main()
{
	Base *b=new Base;
	b->Print();
	delete b;

	Demo *d=new Demo;
	d->Print();
	delete d;

	Base *db=new Demo;
	db->Print();
	delete db;
}

void Demo::Print()
{
	cout<<"Demo\n";
}
