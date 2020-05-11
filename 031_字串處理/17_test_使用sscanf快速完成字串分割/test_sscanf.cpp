/* The following sample illustrates the use of brackets and the
   caret (^) with sscanf().
   Compile options needed: none
下列範例顯示如何使用 sscanf () C Run - Time 函式， 從欄位具有逗號 (，) 分隔的內部緩衝區讀取。
金鑰是， 以下列格式的 sscanf () 函式使用括弧內。 格式將會是 %， ] '、 ' ^ [ 告知函式， 直到到達逗號 (，) 讀取自資料緩衝區來
*/ 

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

char *tokenstring = "first,25.5,second,15";
int result, i;
double fp;
char o[10], f[10], s[10], t[10];

void main()
{
   result = sscanf(tokenstring, "%[^','],%[^','],%[^','],%s", o, s, t, f);
   fp = atof(s);
   i  = atoi(f);
   printf("%s\n %lf\n %s\n %d\n", o, fp, t, i);
}