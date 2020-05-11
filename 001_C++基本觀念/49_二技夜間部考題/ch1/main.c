#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int i,j;
    char chrfilename[100];
    char chrData[100];
    char chr1;
    FILE *pf;
    int check[9];
    printf("請輸入檔名\t");
    scanf("%s",chrfilename);
    pf=fopen(chrfilename,"r");
    while(!feof(pf))
    {
      for(i=0;i<9;i++)
        check[i]=0;
	  chrData[0]='\0';
      fgets( chrData ,100,pf );
      if(strlen(chrData)>9)
        chrData[strlen(chrData)-1]='\0'; //去除換行 
      if(strlen(chrData)>=8)
      {
		 printf("%s ->",chrData);
         for(i=0;i<9;i++)
         {
            chr1=chrData[i];
            j=chr1;
            if(j>48&&j<58)
            {
              check[(j-48-1)]=1;
            }
            else
            {
                printf("%c是",chr1);
            }//if(j>48&&j<58)
         }//for(i=0;i<8;i++)
         for(i=0;i<9;i++)
         {
            if(check[i]==0)
            {
              printf("%d\n",(i+1));
              break;
            }
         }//for(i=0;i<9;i++)
      }//if(strlen(chrData)>=8)
    }//while(!feof(pf)) 
  system("PAUSE");	
  return 0;
}
