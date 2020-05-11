#include<stdio.h>
void main(void)
{
	int inInputNumber,*inInputValue,i,j;
	printf("輸入排序個數\t");
	scanf("%d",&inInputNumber);
	inInputValue=new int [inInputNumber];
	for(i=0;i<inInputNumber; i++)
	{
		printf("輸入第 %d 個數字",i+1);
		scanf("%d",(inInputValue+i));
	}
	printf("/////////////////////////////////\n");
	printf("未排序前的資料\n");
	for(i=0;i<inInputNumber; i++)
	{
		printf("%d\t",*(inInputValue+i));
	}
	printf("\n");
	printf("/////////////////////////////////\n");
	printf("排序後的資料\n");
	for(i=1;i<inInputNumber; i++)
	{
		for(j=0;j<(inInputNumber-1);j++)
			if(*(inInputValue+j)>*(inInputValue+(j+1)))
			{
				int v;
				v=*(inInputValue+j);
				*(inInputValue+j)=*(inInputValue+(j+1));
				*(inInputValue+(j+1))=v;
			}
	}
	for(i=0;i<inInputNumber; i++)
	{
		printf("%d\t",*(inInputValue+i));
	}
	printf("\n");
}