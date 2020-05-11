#include <stdio.h>
#include <stdlib.h>
/*
有用參考資料:https://hellolynn.hpd.io/2017/05/15/c%E8%AA%9E%E8%A8%80-%E8%B6%85%E5%A5%BD%E6%87%82%E7%9A%84%E6%8C%87%E6%A8%99%EF%BC%8C%E5%88%9D%E5%AD%B8%E8%80%85%E8%AB%8B%E9%80%B2%EF%BD%9E/
C/C++ 一維陣列和二維陣列在記憶體的配置情形教學
    01.印出記憶體位址-證明陣列是一塊連續的記憶體
    02.印出記憶體位址-了解二維陣列的記憶體配置情況

線上執行結果: http://www.tutorialspoint.com/compile_c_online.php
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    int i,j;
    unsigned long addressdata=0;
    int a[10];
    int b[2][3];
    for(i=0;i<10;i++)
    {
        a[i]=i;
        addressdata=&a[i];
        printf("a[%d]-address=%p,a[%d]=%d\n",i,addressdata,i,a[i]);
    }
    printf("\n\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            b[i][j]=i+j;
            addressdata=&b[i][j];
            printf("b[%d][%d]-address=%p,b[%d][%d]=%d\n",i,j,addressdata,i,j,b[i][j]);
        }
    }
    Pause();
    return 0;
}
