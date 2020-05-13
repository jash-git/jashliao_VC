#include<iostream.h>

void main()
{
	try
	{
		cout<<"1. 123    2. String    3. 345.678\n您要丟出什麼exception?";
		int a;
		cin>>a;
		switch(a)
		{
		case 1: throw 123;
		case 2: throw "String";
		default: throw 345.678;
		}
	}
	catch(int mes)
	{
		cerr<<mes<<endl;
	}
	catch(char* mes)
	{
		cerr<<mes<<endl;
	}
	catch(...)  //必須在最後一個
	{
		cerr<<"其他的exception.\n";
	}
}