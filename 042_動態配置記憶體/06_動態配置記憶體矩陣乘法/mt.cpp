#include<stdio.h>
void fun1(int *,int *);
//矩陣相乘使用動態配置記憶體
void main(void)
{
	//int aa[3][3],bb[3][3],cc[3][3];
	int i,j,k;
	int x=0;
	int l=1;
	int **p,**q,**r;
	p=new int *[3];
	q=new int *[3];
	r=new int *[3];
	for(k=0;k<3;k++)
	{
		p[k]=new int[3];
		q[k]=new int[3];
		r[k]=new int[3];
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			x++;
			*(*(p+i)+j)=1;
			*(*(q+i)+j)=x;
			*(*(r+i)+j)=0;
			//printf("%d\t",*(*(p+i)+j));
			printf("%d\t",*(*(q+i)+j));
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				*(*(r+i)+j)+=*(*(p+i)+k)**(*(q+k)+j);
				printf("\n");
				printf("aa[%d][%d]=%d*bb[%d][%d]=%d=c[%d][%d]=%d\n",i,k,*(*(p+i)+k),k,i,*(*(q+k)+j),i,j,*(*(r+i)+j));
			}
		}
	}
	printf("\n");
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",*(*(r+i)+j));
		}
		printf("\n");
	}
}
