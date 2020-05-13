#include<iostream.h>


enum ExceptionCode {ecError,ecOk};

void func1();
void func2();
void func3();

void main()
{
	try
	{
		func1();

	}
	catch(char* mes)
	{
		cout<<"This char* exception : "<<mes<<endl;
	}
}

void func1()
{
	func2();
}

void func2()
{
	func3();
}
void func3()
{
	throw "Function 3 Error";
}