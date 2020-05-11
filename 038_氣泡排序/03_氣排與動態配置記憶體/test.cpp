#include <iostream.h>
#include <stdio.h>
void main()
{
	int **p;
	int *a;
	int n,r,c;
	int i,j;
	int tmp;
	scanf("%d",&n);
	cin >> r;
	cin >> c;
	a=new int[n];
	p=new int*[r];
	for(i=0;i<r;i++)
		p[i]=new int[c];

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			*(*(p+i)+j)=i+j;
			cout<<"p["<<i<<"]"<<"["<<j<<"]="<<*(*(p+i)+j)<<"\n";
		}
	}
	for(i=0;i<n;i++)
	{
		*(a+i)=n-i;
		printf("%d\t",*(a+i));
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(*(a+j)>*(a+j+1))
			{
				tmp=*(a+j);
				*(a+j)=*(a+j+1);
				*(a+j+1)=tmp;
			}
		}
	}
	printf("\n");
	for(i=0;i<n;i++)
		printf("%d\t",*(a+i));
	printf("\n");
}