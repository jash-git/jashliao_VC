#include <stdio.h>
#include <stdlib.h>
//====================
//¨ç¼Æ «ü¼Ğ°}¦C
#define funarraysize 4
int (*fparray[funarraysize])(int,int);
//====================
int add(int a,int b)
{
	return (a+b);
}
int sub(int a,int b)
{
	return (a-b);
}
int mul(int a,int b)
{
	return (a*b);
}
int div1(int a,int b)
{
	return (a/b);
}
void main()
{
        fparray[0] = add;
        fparray[1] = sub;
        fparray[2] = mul;
        fparray[3] = div1;
		int a,b,c;
		a=10;
		b=2;
		c=0;
		c=(*(fparray+0))(a,b);//fparray[0](a,b);
		c=(*(fparray+1))(a,b);//fparray[1](a,b);
		c=(*(fparray+2))(a,b);//fparray[2](a,b);
		c=(*(fparray+3))(a,b);//fparray[3](a,b);
}