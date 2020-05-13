// TypeidDemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;
#include <typeinfo.h>
class Base
    {
        public:
            virtual ~Base(){};		// 一定要加入 virturla 解構子, typeid才會正常working
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
	Base *pb=&d;
	int kk=12;

	
	
		cout<< typeid(kk).name() << endl;   // 印出 變數 kk 的型態名稱: int
		cout<< typeid(br).name() << endl;   // 印出 br 所reference 物件的型態名稱: Derived
		cout<< typeid(pb).name() << endl;   // 印出 bp 的資料型態:Base* 
		cout<< typeid(*pb).name() << endl;  // 印出 bp 所指向的物件型態名稱:Derived
	return 0;
}

