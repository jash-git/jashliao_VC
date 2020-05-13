#include <stdio.h>
class A
{
public :
	int i;
	void k();
};
void A::k()
{
	printf("A\n");
}
class B : public A
{
public:
	void k();
};
void B::k()
{
	printf("B\n");
}
void main()
{
	B b1;
	b1.k(); 
	b1.A::k(); 
}