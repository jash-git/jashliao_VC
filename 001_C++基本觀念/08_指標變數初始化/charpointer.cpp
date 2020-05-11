#include <iostream.h>
void main()
{
	char *p;
	int *i;
	i=new int(10);
	p=new char('\0');
	*i=*i+1;
	cin >>p;
	cout<<p<<"\n";
	cout<<i<<"\n";
	cout<<i+1<<"\n";
	cout<<i+2<<"\n";
	cout<<*i<<"\n";
}