
/* 那一個 的解構式會被呼叫 ? (Person or Sortable)*/

#include "stdafx.h"

class Sortable
{
public:
	int data;

	Sortable()		//建構子
	{
		data=123;
	}
	 ~Sortable()   // virtual   Sortable解構子
	{
		data=0;
	}
};
class Person:public Sortable
{
public:
		int id;
	   Person():Sortable()
	   {
		   id=567;
	   }
	   ~Person()
	   {
		data=1;              // Person 的解構子
	   }
};
int main(int argc, char* argv[])
{
	
	Sortable *b;
	Person *p=new Person;	
	b=p;
	delete b;// 那一個 的解構式會被呼叫 ?
	return 0;
}

