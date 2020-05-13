// initial.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

template <class Type,int size=1024>
	class Buffer;


template <class Type=double,int size>
	class Buffer;

template <class Type,int size>
	class Buffer
	{	
	public:
		Type kk;
		int _size;
		int A[size];
		Buffer()
		{
		
			kk=5;
			_size=size;
		}

	};


int main(int argc, char* argv[])
{
	Buffer<int> buf;
	Buffer<> buf2;
//	Buffer<123> buf4;

	Buffer<int> *buf3=new Buffer<int>();
	printf("Hello World!\n");
	return 0;
}


