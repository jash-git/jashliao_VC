#include<iostream>
using namespace std;
void main()
{
	char *p=new char[5];
	strcpy(p,"Hello");
	cout<<p<<"\n";
	p=NULL;
	delete []p;
	/*
	重點網路上是說要先delete []p;之後再p=NULL;
	但這樣在VC會出現錯誤訊息
	*/
	int *int1;
	int1=new int[3];
	int1[0]=2;
	int1[1]=4;
	int1[2]=6;
	cout<< 5*int1[0]<<"\t"<< 5*int1[1]<<"\t"<< 5*int1[2]<<"\n";
	int1='\0';
	delete []int1;
	//int1='\0';
	/*
	重點數值型態int1='\0'沒有差別
	*/

}