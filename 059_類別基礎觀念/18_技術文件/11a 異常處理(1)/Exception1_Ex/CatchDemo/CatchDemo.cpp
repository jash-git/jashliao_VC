#include<iostream.h>
#define DEMO_1 1
#define DEMO_2 0
#define DEMO_3 0
#define DEMO_4 1

enum ExceptionCode
{
	ecError,ecOk
};

void func1();
void func2();

void main()
{
	try
	{
		func1();
#if DEMO_3
		throw ecError;
#endif
#if DEMO_4
		throw 123.123;
#endif
	}
	catch(char* mes)
	{
		cout<<"This char* exception : "<<mes<<endl;
	}
	catch(int mes)
	{
		cout<<"This int exception : "<<mes<<endl;
	}
	catch(ExceptionCode mes)
	{
		cout<<"This ExceptionCode eception : "<<(mes ? "ecOk" : "ecError")<<endl;
	}
}

void func1()
{
#if DEMO_1
	func2();
#endif
#if DEMO_2
	throw 10000;
#endif
}

void func2()
{
	throw "Function 2 Exception!";
}