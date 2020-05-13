#include <iostream.h>
#include <stdio.h>
class grandfather
{
	public:
		virtual void f1()=0;

};
class father :public grandfather
{
public :
	void test();
	void f1();
};
void father::test()
{
	cout<<"it's father's test"<<"\n";
}
void father::f1()
{
	cout<<"it's father's virtual function"<<"\n";
}
class child:public father
{
public :
	void test();
	void f1();
};
void child::test()
{
	cout<<"it's child's test"<<"\n";
}
void child::f1()
{
	cout<<"it's child's virtual function"<<"\n";
}
void main()
{
	child c1;
	father f1;
	father *fp;
	/////////////
	c1.test();
	c1.f1(); 
	////////////
	f1.test();
	f1.f1(); 
	////////////
	c1.father::test();
	c1.father::f1();
	////////////
	fp=&c1;
	fp->test();
	fp->f1(); 
}