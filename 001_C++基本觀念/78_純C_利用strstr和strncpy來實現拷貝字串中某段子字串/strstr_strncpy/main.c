#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    /*
    利用strstr搜尋字串中特定字元的位置
    利用strncpy拷貝字串中某段子字串
    */
    char data[70];
    char chrson[10];
    char *pchrhead='\0';
    strcpy(data,"{\"account\":\"011330107\",\"service_tel\":\"04-2329-3567\",\"status\":0}");
    pchrhead=strstr(data,":");
    strncpy(chrson,(pchrhead+2),9);//strncpy(chrson,(data+12),9);
    chrson[9]='\0';
    printf("%s\n",chrson);//011330107
    return 0;
}
