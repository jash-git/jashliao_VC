#include<stdio.h>
main()
{
	int i,j;
	bool k=true;
	scanf("%d",&i);
	for(j=2;j<i;j++)
	{
		if(i%j==0)
		{
			k=false;
			break;
		}
	}
	if(k==true)
	{
		printf("質數\n");
	}
	else
	{
		printf("非質數\n");
	}

}