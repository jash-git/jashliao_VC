/*
#include <stdio.h>
#include <malloc.h>
//*/
///*
#include<iostream>
using namespace std;
//*/
void main(void)
{
	int i=0,j=0;
	int *p='\0';
	int **p2='\0';
	/*
	p=(int *)malloc(6*sizeof(int));
	p2=(int **)malloc(3 * sizeof(int *));
	for(i = 0; i < 3; i++)
		p2[i] = (int *)malloc(2 * sizeof(int));
	*(p+0)=0;
	*(p+1)=1;
	*(p+2)=2;
	*(p+3)=3;
	*(p+4)=4;
	*(p+5)=5;
	*(*(p2+0)+0)=0;
	*(*(p2+0)+1)=1;
	*(*(p2+1)+0)=2;
	*(*(p2+1)+1)=3;
	*(*(p2+2)+0)=4;
	*(*(p2+2)+1)=5;
	for(i=0;i<6;i++)
	{
		printf("%d\t",*(p+i));
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
			printf("%d\t",*(*(p2+i)+j));
	}
	free(p);
	free(p2);
	//*/
	///*
	p=new int[6];
	p2=new int *[3];
	for(i = 0; i < 3; i++)
		p2[i] =new int[2];;
	*(p+0)=0;
	*(p+1)=1;
	*(p+2)=2;
	*(p+3)=3;
	*(p+4)=4;
	*(p+5)=5;
	*(*(p2+0)+0)=0;
	*(*(p2+0)+1)=1;
	*(*(p2+1)+0)=2;
	*(*(p2+1)+1)=3;
	*(*(p2+2)+0)=4;
	*(*(p2+2)+1)=5;
	for(i=0;i<6;i++)
	{
		cout<<*(p+i)<<"\t";
	}
	cout<<"\n";
	for(i=0;i<3;i++)
	{
		for(j=0;j<2;j++)
			cout<<*(*(p2+i)+j)<<"\t";
	}
	delete p;
	delete p2;
	//*/
}