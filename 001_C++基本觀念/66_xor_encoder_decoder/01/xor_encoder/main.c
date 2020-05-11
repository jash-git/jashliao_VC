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
    //int a=0;
    FILE *pf;
    strcpy(chrkey, "Xor_Encoder_Decoder_Key");

    strcpy(src, "http://www.google.com");

    pf=fopen("world_channel.url","w");

    intdatalen=strlen(src);
    intkeylen=strlen(chrkey);
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
        src[i]=src[i]^chrkey[j];
        printf("data=%d\n",src[i]);
        fprintf(pf,"%d\n",src[i]);
    }
    fclose(pf);
    return 0;
}
