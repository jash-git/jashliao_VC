#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char gchrOutput[1024];
void m3u8_strstr()
{
    char chrm3u8[]=".m3u8";
    char chrColon[]="://";
    char chrData[1024];
    char *p='\0';
    char *p1='\0';
    p=strstr(gchrOutput,chrm3u8);
    printf("point=%d\n",(p-gchrOutput));

    printf("gchrOutput before=%s\n",gchrOutput);

    if((p-gchrOutput)>0)
    {
        p1=strstr(gchrOutput,chrColon);
        strcat(chrData,"http");
        strcat(chrData,p1);
        printf("Data=%s\n",chrData);

        strcpy(gchrOutput,chrData);

    }

    printf("gchrOutput after=%s\n",gchrOutput);
}
int main()
{
    printf("Hello world!\n");
    strcpy(gchrOutput,"rtsp://127.0.0.1/123.m3u8");
    m3u8_strstr();
    strcpy(gchrOutput,"rtsp://127.0.0.1/123.wmv");
    m3u8_strstr();
    return 0;
}
