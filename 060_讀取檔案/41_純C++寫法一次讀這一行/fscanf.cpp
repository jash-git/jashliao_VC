#include<stdio.h>
#include<fstream.h>
void main(void)
{
	fstream a;
	char fg[700];
	a.open("01.txt",ios::in);
	while(!a.eof())
	{
	a.getline(fg,500);
	cout<<fg<<"\n";
	}

}