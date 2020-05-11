#include <stdio.h>
#include <stdlib.h>

unsigned char C_Byte_setBit(unsigned char data,int num)
{//移動次數(1,2,3,4,5,6,7,8)對應的值=1,2,4,8,16,32,64,128
    unsigned char d=1;//2^0
    if(num>0)
    {
        d=d<<(num-1);
    }
    else
    {
        d=0;
    }

    data=data|d;
    return data;
}
int main()
{
    unsigned char d='\0';
    d=C_Byte_setBit(d,8);
    printf("%d\n", d);
    d=C_Byte_setBit(d,1);//out->1
    printf("%d\n", d);
    d=C_Byte_setBit(d,2);//out->3
    printf("%d\n", d);
    return 0;
}
