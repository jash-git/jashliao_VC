#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void main()
{
	int number,number1;
	char *p;
	p=new char('\0');
	cout<<"keyin a string.";
	cin >>p;
	number=sizeof(*p)/sizeof(char);
	cout<<p<<"\n";
	number1=strlen(p);
	cout<<number<<" "<<number1;
}