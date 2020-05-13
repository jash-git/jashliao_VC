// virtualConcept1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
class Animal {
public:
	int weight;
	Animal() {weight=0;}
	virtual void eat(){}
	virtual void setWeight(){}
};

class Cat:public Animal {
public:
	void eat(){
		// eat something
		int kk=0;
	}
	void setWeight() { weight=100;}
};
int main(int argc, char* argv[])
{
    Cat *MyCat=new Cat;
    Animal *Obj=MyCat;

	Obj->eat();
	
	return 0;
}

