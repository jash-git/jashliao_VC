#include <stdio.h>
main()
{
 int aa[3][3],bb[3][3],cc[3][3];
 int i,j,k;
 int x=0;
 int l=1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			x++;
			aa[i][j]=1;
			bb[i][j]=x;
			cc[i][j]=0;
			//printf("%d\t",aa[i][j]);
			printf("%d\t",bb[i][j]);
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				cc[i][j]+=aa[i][k]*bb[k][j];
				printf("\n");
				printf("aa[%d][%d]=%d*bb[%d][%d]=%d=c[%d][%d]=%d\n",i,k,aa[i][k],k,i,bb[k][j],i,j,cc[i][j]);
			}
		}
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",cc[i][j]);
		}
		printf("\n");
	}
}