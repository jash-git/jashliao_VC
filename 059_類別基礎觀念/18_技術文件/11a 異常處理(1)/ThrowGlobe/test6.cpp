// test6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
void fun();
class Error1
{
public: 
	int data;
	Error1()
	{
		data=123;
	}
};

Error1 obj;                     // 定義全區域物件 
int main(int argc, char* argv[])
{
	try{
		fun();
	}
	catch(Error1 &errobj)
	{
		errobj.data=567;
	}
	return 0;                   // ok! 現在全區域物件變數 obj.data 為何?
}
void fun()
{
	throw obj;                  // throw 會建立新的物件. 
}
