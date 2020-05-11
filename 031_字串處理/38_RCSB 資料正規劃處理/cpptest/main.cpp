#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int size;
/*
使用C語言，RCSB 資料正規劃處理
*/
int main()
{
    char chbuf[]="ATOM      1  N   GLY A 161      20.869  24.517  11.732  1.00 48.51           N ";
    char chdat[255];
    char last_b=0,now_b=0;
    printf("%s\n",chbuf);
    size=sizeof(chbuf)/sizeof(char);
    printf("size=%d\n",size);
    int j=0;
    for(int i=0;i<size;i++)
    {
        now_b=chbuf[i];
        if(now_b!=32)
        {
            //save
            chdat[j]=now_b;
            j++;
        }
        else if(now_b==32&&last_b!=32)
        {
            chdat[j]=',';
            j++;

        }
        last_b=now_b;
    }
    printf("%s\n",chdat);
    return 0;
}
