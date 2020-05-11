#include <iostream>
using namespace std;
/*
另類表示的九九乘法表
*/
void main(void)
{
	int data[9]={1,2,3,4,5,6,7,8,9};
	int i=1,j=0;
	for(j=0;j<9;j++)
		cout<<data[j]<<"\t";
	cout<<"\n"<<"-----------------------------------------------------------------------------"<<"\n";
	for(i=1;i<=9;i++)
	{
		cout<<i<<"|"<<"\t";
		for(j=0;j<9;j++)
		{
			cout<<(i*data[j])<<"\t";	
		}
		cout<<"\n";
	}
}