#include <iostream>
#include <stdio.h>
using namespace std;
void swapint(int *a,int *b)
{
    int temp;//變數交換暫存空間
    temp=*a;
    *a=*b;
    *b=temp;  /* x[i]與x[i+1]互換 */
}
int main()
{
    int x[6]={25,10,39,40,33,12};
    int spec=11;
    int k;//儲存倆倆變數交換的索引值最大限制[=陣列大小-2]
    int times;//確認氣泡排序是否全部完成
    int i;//迴圈變數索引值

    int j;
    int value00=0;
    int value01=0;
    int array01=0;
    k=6-1;
    printf("未排序:");
    for(j=0;j<6;j++)
    {
        printf("%d\t",x[j]);
    }
    printf("\n");
    while(k!=0)
    {
        times=0;
        for(i=0;i<=k-1;i++)//K-1是因為運算不要超出陣列範圍
        {
            if(x[i]>x[i+1])
            {
                value00=i;
                value01=x[i];
                array01=(int)(&x[i]);
                swapint(&x[i],&x[i+1]);
                times=i;
            }
        }
        k=times;

        for(j=0;j<6;j++)
        {
            printf("%d\t",x[j]);
        }
        printf("\n");
    }

    for(i=0;i<6;i++)
    {
        printf("%d\t",x[i]);
    }

    printf("\n特別號\t%d\n",spec);
    /*system("pause");*/
    cout << "Hello world!" << endl;
    return 0;
}
