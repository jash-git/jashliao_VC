#include <stdio.h>
/*
由程式可以發現由二維轉一維就可以不用指定陣列維度，程式更靈活
但缺點是要有轉換公式
*/
void ShowArray(int *a)
{
	int i,j,k;
	int x=3;
	int y=3;
	 for(i=0;i<x;i++)
	 {
		 for(j=0;j<y;j++)
		 {
			//k=j+i*(j+1);//二維轉一維公式：column + row*「實際行數」---->錯誤公式
			 k=i*y+j;//外*內限+內
			printf("intarray[%d][%d]=%d\t",i,j,a[k]);
		 }
		printf("\n");
	 }
}
void ShowArray(int a[][3])//傳送二維陣列時必須請楚說明『行數』
{
	int i,j;
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		 {
			printf("intarray[%d][%d]=%d\t",i,j,a[i][j]);
		 }
		printf("\n");
	 }
}
void main(void)
{
	int i,j,k;
	int *pintarray;
	int intarray[3][3];
	 k=0;
	 for(i=0;i<3;i++)
		 for(j=0;j<3;j++)
		 {
			 k++;
			intarray[i][j]=k;
		 }
	ShowArray(intarray);
	pintarray=(int*)intarray;
	printf("二維轉一維列印\n");
	ShowArray(pintarray);
}