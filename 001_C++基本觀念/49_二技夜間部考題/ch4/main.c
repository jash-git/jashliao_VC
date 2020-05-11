#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int i,j;
  int intinput=0;
  printf("請輸入1~16的整數\t");
  scanf("%d",&intinput);
  if((intinput<=16)&&(intinput>0))
  {
      printf("您輸入的數字=%d\n",intinput);
      printf("/");
      for(i=0;i<intinput;i++)
      {
        if(intinput<10)
         printf("-");
        else
         printf("--");
        
      }
      printf("\\");
      printf("\n");
      ////////////////////////////////////////
      for(i=0;i<intinput;i++)
      {
        printf("|");
        if((i==0)||(i==(intinput-1)))
        {
          for(j=0;j<intinput;j++)
          {
            printf("%d",intinput);
          }
        }
        else
        {
          for(j=0;j<intinput;j++)
          {
            if((j==0)||(j==(intinput-1)))
            {            
              printf("%d",intinput);
            }
            else
            {
              if(intinput<10)
              {
                printf(" ");
              }
              else
              {
                printf("  "); 
              } 
            }
          }
        }
        printf("|");
        printf("\n");     
      }  
      ////////////////////////////////////////      
      printf("\\");
      for(i=0;i<intinput;i++)
      {
        if(intinput<10)
         printf("-");
        else
         printf("--");
      }
      printf("/");
      printf("\n");                       
  }
  else
  {
      printf("您輸入的數字錯誤不在範圍內,程式將關閉\n");
  }
                  
  system("PAUSE");	
  return 0;
}
