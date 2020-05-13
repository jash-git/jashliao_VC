#include<stdio.h>
#include<fstream.h>
void main(void)
{
	fstream a;
	int fg;
	a.open("eight.txt",ios::in);
	while(!a.eof())
	{
	a>>fg;
	cout<<fg<<"\n";
	}

}