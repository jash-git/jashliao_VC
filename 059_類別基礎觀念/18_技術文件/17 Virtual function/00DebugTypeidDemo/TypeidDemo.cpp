// TypeidDemo.cpp : Defines the entry point for the console application.
// 為何無法show 出class name?

#include "stdafx.h"

#include <iostream>

using namespace std;
#include <typeinfo.h>
class Base
    {
        public:
            virtual ~Base(){};
    };
class Derived: public Base
    {
        public:
            char const *toString()
            {
                return ("Derived object");
            }
	};

int main(int argc, char* argv[])
{
	Derived d;
	Base &br=d;
	int kk=12;

	
	
		cout<< typeid(kk).name<< endl;
	
	return 0;
}

