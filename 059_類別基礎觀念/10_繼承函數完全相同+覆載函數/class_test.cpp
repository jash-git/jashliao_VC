#include <stdio.h>
class father
{
	public :
		int k;
		show();
		show(int);
};
father::show()
{
	printf("father's show\n");
}
father::show(int a)
{
	k=a;
	printf("father's show;%d\n",k);
}
class childish : public father
{
	public :
		show();
		test();
};
childish::show()
{
	printf("childish's show\n");
}
childish::test()
{
	father::show();
	show();	
}
void main(void)
{
	father f1;
	childish c1;
	f1.show();
	f1.show(3);
	c1.show();
	c1.test();
	c1.father::show(300); 
}