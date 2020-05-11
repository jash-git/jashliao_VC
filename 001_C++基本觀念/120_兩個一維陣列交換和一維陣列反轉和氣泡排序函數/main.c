//兩個一維陣列交換和一維陣列反轉和氣泡排序函數收藏
//http://codepad.org/JkiV3hYP
#include <stdio.h>
#include <stdlib.h>
void SwapArray(int *nx,int *ny,int intArraySize);
void ReverseArray(int *pintArray,int intArraySize);
void BubbleSort(int *pintArray,int intArraySize,int intSW);//sw=1:small->big
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    int nx[5]={1,3,2,4,1};
    int ny[5]={10,8,7,9,10};
    int i;
    printf("原始資料\n");
    for(i=0;i<(sizeof(nx)/sizeof(int));i++)
    {
        printf("%d,",nx[i]);
    }
    printf("\n");
    for(i=0;i<(sizeof(ny)/sizeof(int));i++)
    {
        printf("%d,",ny[i]);
    }
    printf("\n------------------\n");
    printf("將兩陣列反轉\n");
    ReverseArray(nx,(sizeof(nx)/sizeof(int)));
    ReverseArray(ny,(sizeof(ny)/sizeof(int)));
    for(i=0;i<(sizeof(nx)/sizeof(int));i++)
    {
        printf("%d,",nx[i]);
    }
    printf("\n");
    for(i=0;i<(sizeof(ny)/sizeof(int));i++)
    {
        printf("%d,",ny[i]);
    }
    printf("\n------------------\n");
    printf("將兩陣列交換\n");
    SwapArray(nx,ny,sizeof(nx)/sizeof(int));
    for(i=0;i<(sizeof(nx)/sizeof(int));i++)
    {
        printf("%d,",nx[i]);
    }
    printf("\n");
    for(i=0;i<(sizeof(ny)/sizeof(int));i++)
    {
        printf("%d,",ny[i]);
    }
    printf("\n------------------\n");
    printf("將兩陣small->big\n");
    BubbleSort(ny,sizeof(ny)/sizeof(int),1);//small->big
    BubbleSort(nx,sizeof(nx)/sizeof(int),1);//small->big
    for(i=0;i<(sizeof(nx)/sizeof(int));i++)
    {
        printf("%d,",nx[i]);
    }
    printf("\n");
    for(i=0;i<(sizeof(ny)/sizeof(int));i++)
    {
        printf("%d,",ny[i]);
    }
    printf("\n------------------\n");
    printf("將兩陣big->small\n");
    BubbleSort(nx,sizeof(nx)/sizeof(int),0);//big->small
    BubbleSort(ny,sizeof(ny)/sizeof(int),0);//big->small
    for(i=0;i<(sizeof(nx)/sizeof(int));i++)
    {
        printf("%d,",nx[i]);
    }
    printf("\n");
    for(i=0;i<(sizeof(ny)/sizeof(int));i++)
    {
        printf("%d,",ny[i]);
    }
    printf("\n");
    Pause();
    return 0;
}
void SwapArray(int *nx,int *ny,int intArraySize)
{
    int i;
    int intBuf;
    for(i=0;i<intArraySize;i++)
    {
        intBuf=*(nx+i);
        *(nx+i)=*(ny+i);
        *(ny+i)=intBuf;
    }
}
void ReverseArray(int *pintArray,int intArraySize)
{
    int intBuf;
    int i;
    for(i=(intArraySize-1);i>(intArraySize-1)/2;i--)
    {
        if(i!=(intArraySize-1-i))
        {
            intBuf=*(pintArray+i);
            *(pintArray+i)=*(pintArray+(intArraySize-1-i));
            *(pintArray+(intArraySize-1-i))=intBuf;
        }
        else
        {
            break;
        }
    }
}
void BubbleSort(int *pintArray,int intArraySize,int intSW)//sw=1:small->big
{
    int i,j;
    int intBuf;
 	for(i=0;i<intArraySize;i++)//做幾次
	{
		for(j=0;j<(intArraySize-i-1);j++)
		{
			if((intSW==1) && (*(pintArray+j)>*(pintArray+j+1)))
			{//small->big
				intBuf=*(pintArray+j);
				*(pintArray+j)=*(pintArray+j+1);
				*(pintArray+j+1)=intBuf;
			}

			if((intSW!=1) && (*(pintArray+j)<*(pintArray+j+1)))
			{//big->small
				intBuf=*(pintArray+j+1);
				*(pintArray+j+1)=*(pintArray+j);
				*(pintArray+j)=intBuf;
			}
		}
	}
}
