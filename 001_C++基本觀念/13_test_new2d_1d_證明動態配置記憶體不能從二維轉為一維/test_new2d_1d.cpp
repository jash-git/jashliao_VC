#include <stdio.h>
/*
證明動態配置記憶體不能從二維轉為一維
*/
main()
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
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		 {
			printf("intarray[%d][%d]=%d\t",i,j,intarray[i][j]);
		 }
		printf("\n");
	 }
	 printf("////////////////////////////\n");
	 pintarray=(int *)intarray;
	 k=0;
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		 {
			k=j*3+i;
			printf("intarray[%d][%d]=%d\t",i,j,pintarray[k]);
		 }
		printf("\n");
	 }
	 printf("////////////////////////////\n");
	 printf("////////////////////////////\n");
	 int **image_in;
	 image_in = new int*[3];
	 for(i=0;i<3;i++)
		 image_in[i] = new int[3];
	 k=0;
	 for(i=0;i<3;i++)
		 for(j=0;j<3;j++)
		 {
			 k++;
			*(*(image_in+i)+j) = k;
		 }
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		 {
			printf("image_in[%d][%d]=%d\t",i,j,*(*(image_in+i)+j));
		 }
		printf("\n");
	 }
	 printf("////////////////////////////\n");
	 pintarray=(int *)image_in;
	 k=0;
	 for(j=0;j<3;j++)
	 {
		 for(i=0;i<3;i++)
		 {
			//k=j*3+i;//大陸書的寫法
			 k=j+i*(j+1);//傳統寫法
			printf("image_in[%d][%d]=%d\t",i,j,pintarray[k]);
		 }
		printf("\n");
	 }
}