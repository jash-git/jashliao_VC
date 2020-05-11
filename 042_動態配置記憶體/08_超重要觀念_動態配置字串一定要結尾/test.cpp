#include <iostream>
#include <string>
using namespace std;
void main(void)
{
	char *p;
	char *p1;
	string str1;
	long lnglen;
	int i=0;
	//lnglen=5;
	lnglen=4;//會出現不可預期的錯誤
	p="jash";
	p1='\0';
	p1=new char[lnglen];
	*(p1+0)='j';
	*(p1+1)='a';
	*(p1+2)='s';
	*(p1+3)='h';
	//*(p1+4)='\0';
	str1=p1;
	cout<<p<<"\n";
	cout<<p1<<"\n";
	cout<<str1<<"\n";
}