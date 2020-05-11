#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* C_1Byte_to_2Hex0F(int data)
{
    char chrOp[2];
    int i,intH,intL,intVal[2];
    intH=data/16;
    intL=data%16;
    intVal[1]=intH;
    intVal[0]=intL;
    for(i=0;i<2;i++)
    {
       if(intVal[i]<10)
       {
           intVal[i]+=48;
       }
       else
       {
           intVal[i]+=(97-10);
       }
       chrOp[i]=intVal[i];
    }
    return chrOp;
}
int C_2Hex0F_to_1Byte(char *data)
{
    //14,15
    //12,13
    //10,11
    //8,9
    //6,7
    //4,5
    //2,3
    //0,1
    int intData=0;
    char chrOp='\0';
    int i=0;
    int j=0;
    for(i=(2-1);i>=0;i--)//低到高進行運算
    {
        chrOp=data[i];
        if( (chrOp>=48) && (chrOp<=57) )//'0'~'9'
        {
            intData+=(chrOp-48)* pow(16, j);
        }
        else if( (chrOp>=65) && (chrOp<=70) )//'A'~'F'
        {
            intData+=(chrOp-65+10)* pow(16, j);
        }
        else if( (chrOp>=97) && (chrOp<=102) )//'a'~'f'
        {
            intData+=(chrOp-97+10)* pow(16, j);
        }
        j++;
    }

    return intData;
}
int main()
{
    char data[16]={'5','7','1','3','1','1','3','D','6','9','3','4','D','3','E','0'};//高->低的表示法，和計算機相反
    int i=0;
    int intD=0;
    char *p;
    for(i=(16-1);i>=0;i-=2)//i=15,13,11,9,7,5,3,1[因為表示和計算機相反，所以倒著取值]
    {
        intD=0;
        intD=C_2Hex0F_to_1Byte(&data[i-1]);
        printf("%c%c->%d\t\t\t",data[i-1],data[i],intD);//傳高位的指標
        p=C_1Byte_to_2Hex0F(intD);
        printf("%d->%c%c\n",intD,*(p+1),*(p+0));
    }
    return 0;
}
