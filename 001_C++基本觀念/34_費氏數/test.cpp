#include <iostream>
using namespace std;
void main()
{
	int data[10]={0,0,0,0,0,0,0,0,0,0};
	int i;
	data[0]=1;
	cout<<data[0]<<"\t";
	for(i=1;i<10;i++)
	{
		if(i==1)
		{
			data[i]=data[(i-1)];
		}
		else
		{
			data[i]=data[(i-1)]+data[(i-2)];
		}
		cout<<data[i]<<"\t";
	}
	cout<<"\n";
}