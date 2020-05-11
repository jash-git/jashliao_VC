#include <stdio.h>

int main ()
{
/*
  char sentence []="Rudolph is 12 years old";
  char str [20];
  int i;

  sscanf (sentence,"%s %*s %d",str,&i);
  printf ("%s -> %d\n",str,i);
*/
/*
sscanf函數的高級用法
 
轉載時請注明出處：http://blog.csdn.net/absurd/
 
大家都知道sscanf是一個很好用的函數，利用它可以從字串中取出整數、浮點數和字串等等。它的使用方法簡單，特別對於整數和浮點數來說。但新手可能並不知道處理字串時的一些高級用法，這裏做個簡要說明吧。
 
1.         常見用法。
char str[512] = {0};
	sscanf("123456 ", "%s", str);
    printf("str=%s\n", str);
 
2.         取指定長度的字串。如在下例中，取最大長度為4位元組的字串。
    sscanf("123456 ", "%4s", str);
    printf("str=%s\n", str);
 
3.         取到指定字元為止的字串。如在下例中，取遇到空格為止字串。
    sscanf("123456 abcdedf", "%[^ ]", str);
    printf("str=%s\n", str);
 
4.         取僅包含指定字元集的字串。如在下例中，取僅包含1到9和小寫字母的字串。
    sscanf("123456abcdedfBCDEF", "%[1-9a-z]", str);
    printf("str=%s\n", str);
 
5.         取到指定字元集為止的字串。如在下例中，取遇到大寫字母為止的字串。
    sscanf("123456abcdedfBCDEF", "%[^A-Z]", str);
    printf("str=%s\n", str);
*/
 char sentence []="Rudolph is||12||years old";	
  char str [20];
  char str1 [20];
  int i;

  sscanf (sentence,"%[^||]||%d||%[^||]",str,&i,str1);
  printf ("%s -> %d %s\n",str,i,str1);
  return 0;
}
