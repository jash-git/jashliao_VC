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
    int a=0;
    FILE *pf;
    strcpy(chrkey, "Xor_Encoder_Decoder_Key");

    pf='\0';
    pf=fopen("world_channel.url","r");
    j=0;
    while(fscanf(pf,"%d",&a)!=EOF)
    {
        if(a>0)
        {
             //printf("%d\n",a);
             src[j]=a;
             //printf("en=%d\n",en[j]);
             j++;
        }
    }
	fclose(pf);
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
            j=-1;
        }
        src[i]=src[i]^chrkey[j];
    }
    printf("url => %s\n", src);
    return 0;
}
