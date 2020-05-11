#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void Decimal2Binary(long value,char *b,int len)
{
    if(value>0)
    {
        do
        {
            if(value==1)
            {
                *(b+len-1)='1';
                break;
            }
            else
            {
                *(b+len-1)=(value%2)+48;
                value=value/2;
                len--;
            }
        }while(1);
    }
}
long Binary2Decimal(char *b,int len)
{
    int i=0;
    int j=0;
    long value=0;
    for(i=(len-1);i>=0;i--)
    {
        if(*(b+i)==49)
        {
            value+=pow(2,j);
        }
        j++;
    }
    return value;
}
int main()
{
    char data[11];//最後一個BIT要拿來當字串結尾
    long value=1023;
    memset(data,'0',sizeof(data));
    data[10]='\0';//字串結尾
    Decimal2Binary(value,data,10);
    printf("%d->%s\n",value,data);
    value=Binary2Decimal(data,10);
    printf("%s->%d",data,value);
    return 0;
}
