#include<iostream.h>

void func();

void main()
{
	try
	{
		func();
	}
	catch(int& code)
	{
		cerr<<code<<endl;
		throw;   //加入此行則呼叫C++ Standard Library的 Terminate().
	}
}

void func()
{
	try
	{
		throw -1;
	}
	catch(int& code)
	{
		cerr<<code<<endl;
		code=100;
		throw;
	}
}