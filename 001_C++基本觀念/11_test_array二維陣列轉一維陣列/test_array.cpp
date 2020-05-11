#include <stdio.h>
void main(void)
{
   //¤Gºû°}¦CÂà¤@ºû°}¦C
	int array[3][3], *ptr;
	int i,j,k;
	k=1;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			array[i][j]=k;
			k++;
			printf("array[%d][%d]=%d\t",i,j,array[i][j]);
		}
		printf("\n");
	}
	//////////////////////////////////////////
	ptr=(int *)array;
	j=0;
	for(i=0;i<9;i++)
	{
		printf("ptr[%d]=%d\t",i,ptr[i]);
		j++;
		if(!(j%3))
			printf("\n");
	}

}