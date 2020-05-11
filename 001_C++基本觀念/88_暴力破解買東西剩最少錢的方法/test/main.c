#include <stdio.h>
#include <stdlib.h>
//AX+BY+CZ ≦Dividend
void BoBo(int p[][2],int n)
//============================================================
//
//函數說明:氣泡排序並紀錄原本位置
//
//============================================================
{
	long i,j,key;
	double temp,temp1;
	for(i=0;i<n;i++)
	{
		key=0;
		for(j=0;j<(n-i-1);j++)
		{
			if(p[j][1]<p[j+1][1])
			{
				temp1=p[j][1];
				p[j][1]=p[j+1][1];
				p[j+1][1]=temp1;
				///////////////////////////////
				temp=p[j][0];
				p[j][0]=p[j+1][0];
				p[j+1][0]=temp;
				key=1;
			}
		}
		if(key==0)
			break;
	}
}
int main()
{
    int A,B,C,D;
    int X=0,Y=0,Z=0;
    int Quotient=0,Remainder=0;
    //----------------------------
    //ABC 變數排序用
    //__bobo_start
    int i,bobo[3][2];
    for(i=0;i<3;i++)
        bobo[i][0]=i;
    //__bobo_end
    //----------------------------
    //----------------------------
    //讀取輸入的參數
    //__讀取輸入的參數_start
    printf("AX+BY+CZ ≦Dividend \n");
    printf("輸入採買金額(Dividend)=\t");
    scanf("%d",&D);
    printf("輸入採買A物的單價=\t");
    scanf("%d",&A);
    bobo[0][1]=A;
    printf("輸入採買B物的單價=\t");
    scanf("%d",&B);
    bobo[1][1]=B;
    printf("輸入採買C物的單價=\t");
    scanf("%d",&C);
    bobo[2][1]=C;
    printf("所以題目: %dX+%dY+%dZ ≦%d \n",A,B,C,D);
    //__讀取輸入的參數_end
    BoBo(bobo,3);//執行ABC排序
    /*
    printf("%d\t%d\n",bobo[0][0],bobo[0][1]);
    printf("%d\t%d\n",bobo[1][0],bobo[1][1]);
    printf("%d\t%d\n",bobo[2][0],bobo[2][1]);
    //*/
    //----------------------------
    //第一次計算三樣都買可以買幾個
    //__第一次計算三樣都買可以買幾個_start
    Quotient=D/(A+B+C);//計算三樣都買可以買幾個
    X=Y=Z=Quotient;
    Remainder=D-(Quotient*(A+B+C));//計算剩餘的錢
    //__第一次計算三樣都買可以買幾個_end
    //printf("first=%d\t%d\n",Quotient,Remainder);
    //----------------------------
    //依序(從高價開始)計算可買數量
    //__依序(從高價開始)計算可買數量_start
    while((Remainder>=C)||(Remainder>=B)||(Remainder>A))//把剩餘的錢花到都不能買為止
    {
        D=Remainder;//把剩餘的錢變商數
        Quotient=0;
        Remainder=0;
        if(D>=bobo[0][1])//拿來買最貴的物品
        {
            Quotient=D/bobo[0][1];//計算可以買幾個
            switch(bobo[0][0])//把買到的數量加到對應的變數
            {
                case 0:
                    X=X+Quotient;
                    break;
                case 1:
                    Y=Y+Quotient;
                    break;
                case 2:
                    Z=Z+Quotient;
                    break;
            }
            Remainder=D-Quotient*bobo[0][1];//計算剩餘的錢
            D=Remainder;//把剩餘的錢變商數
            Quotient=0;
            Remainder=0;
        }//if(D>=bobo[0][1])
        if(D>=bobo[1][1])//拿來買次貴的物品
        {
            Quotient=D/bobo[1][1];//計算可以買幾個
            switch(bobo[1][0])
            {
                case 0:
                    X=X+Quotient;
                    break;
                case 1:
                    Y=Y+Quotient;
                    break;
                case 2:
                    Z=Z+Quotient;
                    break;
            }
            Remainder=D-Quotient*bobo[1][1];//計算剩餘的錢
            D=Remainder;//把剩餘的錢變商數
            Quotient=0;
            Remainder=0;
        }//if(D>=bobo[1][1])
        if(D>=bobo[2][1])//拿來買最便宜的物品
        {
            Quotient=D/bobo[2][1];//計算可以買幾個
            switch(bobo[2][0])
            {
                case 0:
                    X=X+Quotient;
                    break;
                case 1:
                    Y=Y+Quotient;
                    break;
                case 2:
                    Z=Z+Quotient;
                    break;
            }
            Remainder=D-Quotient*bobo[2][1];//計算剩餘的錢
            D=Remainder;//把剩餘的錢變商數
            Quotient=0;
            Remainder=0;
        }//if(D>=bobo[2][1])
    }//while((Remainder>=C)||(Remainder>=B)||(Remainder>A))
    //__依序(從高價開始)計算可買數量_end
    printf("所以答案: %d*%d+%d*%d+%d*%d=%d\t Remainder=%d \n",A,X,B,Y,C,Z,(A*X+B*Y+C*Z),D);

    return 0;
}
