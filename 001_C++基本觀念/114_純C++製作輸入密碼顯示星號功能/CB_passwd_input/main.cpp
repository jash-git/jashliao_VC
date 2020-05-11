//https://yq.aliyun.com/articles/15243
#ifndef _WIN32 // 如果不是WIN32環境，則要自訂getch()函數
#include <termio.h>

int getch(void)
{
     struct termios tm, tm_old;
     int fd = 0, ch;

     if (tcgetattr(fd, &tm) < 0) {
          return -1;
     }

     tm_old = tm;
     cfmakeraw(&tm);
     if (tcsetattr(fd, TCSANOW, &tm) < 0) {
          return -1;
     }

     ch = fgetc(stdin);
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {
          return -1;
     }

     return ch;
}
#else
#include <conio.h>
#endif // _WIN32
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
/*
* 密碼輸入函數，參數 passwd 為密碼緩衝區，buff_len 為緩衝區長度
*/
char *passwd_input(char *passwd, int buff_len)
{
     char str;
     int i = 0;
     int enter_num = 13;
     int backspace_num;

     #ifndef _WIN32
     backspace_num = 127;
     #else
     backspace_num = 8;
     #endif

     if (passwd == NULL || buff_len <= 0) {
          return passwd;
     }
     while (1)
     {
          // 如果沒有按下倒退鍵
          if ((str = getch()) != (char)backspace_num) {
               if (i < buff_len - 1) {
                    passwd[i++] = str;
                    printf("*");
               }
          } else {
               if (i != 0) {
                    i--;
                    printf("\b \b");
               }
          }
          // 如果按下了回車鍵
          if (str == (char)enter_num) {
               passwd[--i] = '\0';

               if (i != buff_len - 1) {
                   printf("\b \b");
               }
               break;
          } else if (str == -1) {
               fprintf(stderr, "Error to set termio noecho.n");
          }
     }

     return passwd;
}

// 測試示例（請自行添加標頭檔）
int main(void)
{
    char pass[7];
    setlocale(LC_ALL,"Chinese_Taiwan.950");
    printf("輸入密碼（長度限制 6）：");
    passwd_input(pass, 8);// \0+enter(8-2=6)
    printf("\n%s\n", pass);
    Pause();
    return 0;
}


