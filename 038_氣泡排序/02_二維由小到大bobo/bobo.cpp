#include <iostream>
#include <stdio.h>
using namespace std;
void bobo(double **p,long n);
void main()
{
	int i,j,temp,n,k,key;
	i=0;
	j=0;
	n=0;
	temp=0;
	key=0;
	double **Data;//={{0,1,2,3,4,5,6,7,8,9},{10,78,45,89,01,05,23,54,20,32}};
	/////////////////////////////
	Data=new double *[10]; 
	for(i=0;i<10;i++)
		Data[i]=new double [2];
	////////////////////////////
	for(i=0;i<10;i++)
		Data[i][0]=i;
	Data[0][1]=10;
	Data[1][1]=78;
	Data[2][1]=45;
	Data[3][1]=89;
	Data[4][1]=01;
	Data[5][1]=05;
	Data[6][1]=23;
	Data[7][1]=54;
	Data[8][1]=20;
	Data[9][1]=32;

	//int Data[10]={10,78,45,89,01,05,23,54,20,32};
	n=10;
for(k=0;k<10;k++)
		cout <<Data[k][0]<<"\t";
cout<<"\n";
for(k=0;k<10;k++)
		cout <<Data[k][1]<<"\t";
cout<<"\n";
	bobo(Data,n);
for(k=0;k<10;k++)
		cout <<Data[k][0]<<"\t";
cout<<"\n";
for(k=0;k<10;k++)
		cout <<Data[k][1]<<"\t";
/*
	for(i=0;i<10;i++)
	{
		key=0;
		for(j=0;j<(n-i-1);j++)
		{
			if(Data[j]<Data[j+1])
			{
				temp=Data[j];
				Data[j]=Data[j+1];
				Data[j+1]=temp;
				key=1;
			}
		}
		if(key==0)
			break;
	}
		for(k=0;k<10;k++)
			cout <<Data[k]<<"\t";
		cout <<"\n";
*/

}
void bobo(double **p,long n)
{
	long i,j,key;
	double temp,temp1;
	for(i=0;i<n;i++)
	{
		key=0;
		for(j=0;j<(n-i-1);j++)
		{
			if(p[j][1]>p[j+1][1])
			{
				temp1=p[j][1];
				p[j][1]=p[j+1][1];
				p[j+1][1]=temp1;
				///////////////////////////////
				temp=p[j][0];
				p[j][0]=p[j+1][0];
				p[j+1][0]=temp;
				key=1;
			}
		}
		if(key==0)
			break;
	}
}
