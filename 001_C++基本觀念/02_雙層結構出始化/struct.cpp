#include <stdio.h>
struct child
{
	int a;
	float b;
};
struct father
{
	int a;
	float b;
	child ch1;
};//fa1={10,20.0f,{30,40.0}};
main()
{
	father fa1={10,20.0f,{30,40.0}};
	printf("%d\t%f\n",fa1.ch1.a,fa1.ch1.b);
	printf("%d\t%f\n",fa1.a,fa1.b);
}

