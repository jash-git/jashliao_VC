#include <stdio.h>
#include <iostream.h>
struct hhh
{
	int *p;
};
void main()
{
	int *k;
	int i,j;
	k=new int[10];
	hhh jjj,*lll;
	jjj.p=new int [10];
	lll=new hhh[3];
	lll[0].p=new int [3];
	lll[1].p=new int [3];
	lll[2].p=new int [3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			lll[i].p[j]=i+j;
			cout<<"lll["<<i<<"].p["<<j<<"]="<<lll[i].p[j]<<"\t";
		}
		cout<<"\n";
	}
}