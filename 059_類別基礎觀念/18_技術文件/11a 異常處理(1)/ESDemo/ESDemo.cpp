#include<iostream>
#include<string>
using namespace std;

void func() throw(string);
void func1() throw();

void main()
{
	try
	{
		func();
		func1();
		
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

	
}
void func1() throw()                      // 不會丟出任何例外
{
	                                      
	// throw "char *type error";          // 丟出 char* 型態的例外
	// throw 1.0;                         // 丟出 float type的例外, 
	                                      // 因為catch 中沒有 float type 的例外
	                                      // 沒有正確的catch住,則會發生 unexpected()例外
}
void func() throw(string)                 // 只會丟出 string 例外
{
	//throw string("abcdef");
	throw 1;                              // 雖然丟出的是int,但是還是可以執行!
}
