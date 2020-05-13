//////////////////////////////////////////////////////////////
//
//透過分析FFMPEG的資訊，取得影片長度
//
/////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *pf;
    int i=0;
    char chrfind[]="Duration:";
    char *pchrget='\0';
    char buf[513];
    char buf0[50],buf1[50],buf2[50],buf3[50],buf4[50],buf5[50];
    int intHr,intMin,intSec,intmSec;
    int intAllSec;
    int intHalfSec;
    //----------------------------
    //__純C一行一行讀取檔案內容_start
    pf=fopen("info1.txt","r");
    while(fgets(buf,512,pf) != NULL)
    //__純C一行一行讀取檔案內容_end
    //----------------------------
    {
        buf[strlen(buf)-1]='\0';//刪除換行
        //printf("%s\n",buf);//直接印出每一行資訊
        //----------------------------
        //__搜尋檔案內有Duration字串_start
        pchrget='\0';
        pchrget=strstr(buf,chrfind);
        if(pchrget!='\0')
        {
            printf("%s\n",buf);
            break;
        }
        //__搜尋檔案內有Duration字串_end
        //----------------------------
    }
    //----------------------------
    //__搜尋檔案內有Duration字串_start
    //----------------------------
    //__計算影片長度的一半_start
    sscanf (buf ,"%[^:]:%[^:]:%[^:]:%[^.].%[^,],%s",buf0,buf1,buf2,buf3,buf4,buf5);
    //printf("%s\n%s\n%s\n%s\n",buf1,buf2,buf3,buf4);
    intHr=atoi(buf1);
    intMin=atoi(buf2);
    intSec=atoi(buf3);
    intmSec=atoi(buf4);
    //printf("%d\n%d\n%d\n%d\n",intHr,intMin,intSec,intmSec);
    intAllSec=intHr*60*60+intMin*60+intSec;
    printf("AllSec=%d\n",intAllSec);
    intHalfSec=intAllSec/2;
    printf("HalfSec=%d\n",intHalfSec);
    intHr=intHalfSec/(60*60);
    intMin=(intHalfSec-(intHr*(60*60)))/60;
    intSec=(intHalfSec-(intHr*(60*60))-(intMin*60));
    printf("%d:%d:%d",intHr,intMin,intSec);
    //__計算影片長度的一半_end
    return 0;
}
