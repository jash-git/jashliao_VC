#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int g_intWaitAndPrintIndex=0;
void WaitAndPrint(int bReset)//1 就代表等待結束，0 就是繼續等待
  {
    char strTickCharacter[] = "|/-\\";

    if(bReset)
      {
        g_intWaitAndPrintIndex = (-1);

        fprintf(stdout, "\n");//等待結束

        return;
      }

    g_intWaitAndPrintIndex ++;
    g_intWaitAndPrintIndex %= strlen(strTickCharacter);//計算要顯示的字母


    if(g_intWaitAndPrintIndex == 0)
    {
        fprintf(stdout, ".");
    }

    fprintf(stdout, "%c\b", strTickCharacter[g_intWaitAndPrintIndex]);//透過\b讓印出來的字元取代前一個字元,造成文字版的等待動畫效果
  }
int main()
{
    int i;
    for(i=0;i<10;i++)
    {
        WaitAndPrint(0);
        _sleep(1000/5);
    }
    WaitAndPrint(1);
    return 0;
}
