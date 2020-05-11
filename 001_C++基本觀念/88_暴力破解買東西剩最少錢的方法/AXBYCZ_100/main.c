#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;//求出美一種最多可以買幾個
    int x,y,z;//要找的答案
    int i,j,k;//迴圈變數

    int Now_D,Ans_D;//本次運算結果和最終答案
    int findAns;//找到完全符合的旗標變數
    a=100/7;
    b=100/9;
    c=100/11;
    Now_D=Ans_D=0;
    findAns=-1;
    printf("7X+9Y+11Z≦100\t求X，Y，Z \n");//有n組整數解
    for(i=0;i<=a;i++)//利用三層迴圈嘗試每種組合
    {
        for(j=0;j<=b;j++)
        {
            for(k=0;k<=c;k++)
            {
               Now_D=i*7+j*9+k*11;
               if((Ans_D<Now_D)&&(Now_D<=100)&&(i>0&&j>0&&k>0))//每種至少要買一個
               {
                   Ans_D=Now_D;
                   x=i;
                   y=j;
                   z=k;
                   if(Ans_D==100)//找到完全符合就停止所有運算
                   {
                       findAns=1;
                       break;
                   }
               }
            }
            if(findAns==1)//找到完全符合就停止所有運算
                break;
        }
        if(findAns==1)//找到完全符合就停止所有運算
            break;
    }
    printf("7*%d+9*%d+11*%d=%d\n",x,y,z,Ans_D);

    return 0;
}
