
#include "stdafx.h"
class Base 
{
public:
	int BaseData;
	Base()
	{
		BaseData=0;
	}
	virtual ~Base()
	{
		BaseData=1;
	}
	
};
class Derived:public Base
{

public:
	int DerivedData;
	Derived():Base()
	{
		DerivedData=0;
	}
	~Derived()
	{
		DerivedData=1;
	}
};

int main(int argc, char* argv[])
{
	/*
	Delete Derived 會呼叫 Derived虛擬解構式,
	但是程式會繼續呼叫 Base 的解構式嗎?

    <sol> 是的. 
		解構的順序為 
			~Derived() -> ~Base()
    */

	Derived *Dobj=new Derived();
	Base *Bobj;

	Bobj=Dobj;
	
	delete Bobj;
	return 0;
}

