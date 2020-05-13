#include<iostream>
#include<string>
using namespace std;

void func() throw(string);
void func1() throw();

void main()
{
	try
	{
		func1();
		func();
	}
	catch(string mes)
	{
		cerr<<mes.c_str()<<endl;
	}
	catch(char *mes)
	{
		cerr<<mes<<endl;
	}
	catch(int msg)
	{
		cerr << "throw int\n";
	}
	catch(...)
	{
		cerr<< " default";
	}
	
}
void func1() throw()
{
	//throw "char *type error";
	throw 1.0;
}
void func() throw(string)
{
//	throw string("abcdef");
}
