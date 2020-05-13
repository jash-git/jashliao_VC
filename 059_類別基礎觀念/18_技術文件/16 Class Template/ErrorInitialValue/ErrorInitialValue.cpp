// ErrorInitialValue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
/*
	宣告一個不合法的預設值
*/
template <class Type=int,int size>
	class Buffer;
/*
	class Buffer的定義
*/
template <class Type,int size>
	class Buffer
	{	
	public:
		Type kk;
		int _size;
		Buffer()
		{
			unsigned char BB[800*600*3];
			kk=5;
			_size=size;
		}

	};


int main(int argc, char* argv[])
{
	Buffer<int> buf;
	//Buffer<> buf2;
	//Buffer<123> buf4;   // <<------ 錯誤

	Buffer<int> *buf3=new Buffer<int>();
	printf("Hello World!\n");
	return 0;
}