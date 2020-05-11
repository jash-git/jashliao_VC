#include <iostream>
using namespace std;
//////////////////////////////////
//實現動態配二維陣列和傳遞動態的二維陣列
void showarray(int **array)
{
	int i,j,k=0;
	 for(i=0;i<3;i++)
	 {
		 for(j=0;j<3;j++)
		 {
			printf("array[%d][%d]=%d\t",i,j,*(*(array+i)+j));
		 }
		printf("\n");
	 }
}
void main()
{
	int **array;
	int i,j,k=0;
	/////////////////////////////////
	//動態配二維陣列
	array = new int*[3];
	for(i=0;i<3;i++)
		array[i] = new int[3];
	////////////////////////////////
	//填值
	 for(i=0;i<3;i++)
		 for(j=0;j<3;j++)
		 {
			 k++;
			*(*(array+i)+j) = k;
		 }
	//////////////////////////////
	//傳遞動態的二維陣列
	showarray(array);
	delete [] array;
}