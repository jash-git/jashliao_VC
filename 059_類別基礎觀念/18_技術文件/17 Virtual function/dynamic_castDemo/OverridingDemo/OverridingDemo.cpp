// OverridingDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>

class Base
{
public:
		show(int x,int y)
		{
			cout<<x<<y;
		}
		show(int x)
		{
			cout<<x;
		}
};
class derived: public Base
{
public:
		show()
		{
			
			cout<<1;
		}
};
int main(int argc, char* argv[])
{
	derived dd;

	dd.show();
	//dd.show(1,2);	// error
	dd.Base::show(1,2);
	printf("Hello World!\n");
	return 0;
}

