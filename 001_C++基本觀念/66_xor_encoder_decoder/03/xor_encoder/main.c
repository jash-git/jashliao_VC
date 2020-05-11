#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char src[1000] = {0};
    //char en[1000] = {0},de[1000] = {0};
    char chrkey[100] = {0};
    int intdatalen,intkeylen;
    int i,j;
    int intA,intB,intC;
    //int a=0;
    FILE *pf;
    strcpy(chrkey, "Xor_Encoder_Decoder_Key");

    strcpy(src, "http://login.liveapk.info/auth.aspx?Account=test&Password=pwd");

    pf=fopen("world_channel.url","w");

    intdatalen=strlen(src);
    intkeylen=strlen(chrkey)-1;//C語言特性，不然會抓到節尾符號
    j=-1;
    for(i=0;i<intdatalen;i++)
    {
        if(j<intkeylen)
        {
            j++;
        }
        else
        {
            j=0;
        }
        intA=src[i];
        intB=chrkey[j];
        intC=intA^intB;
        //src[i]=src[i]^chrkey[j];
        printf("data=%d\n",intC);
        fprintf(pf,"%d\n",intC);
    }
    fclose(pf);
    return 0;
}
