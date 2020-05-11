#include <stdio.h>
#include <string.h>

//計算字串str中某字串substring出現的次數
int countNumOfSubstringInString(char *substring,char *str)
{
 int startIndex=-1;
 int endStartIndex = -1;
 int num=0;
 int soulen=0;
 char *loc;
 soulen=strlen(str);
 loc=strstr(str, substring);
 endStartIndex=(loc-str)+strlen(substring);
 while ( (endStartIndex>=0) && (endStartIndex<=soulen) )
 {
  num++;
  loc=strstr((str+endStartIndex), substring);
  endStartIndex=(loc-str)+strlen(substring);  

 }
 return num; 
}

int main(void)
{
	char *strData="my my your your 123456789 y";
	char *strsub="my";
	printf("strData= %s\n",strData);
	printf("strsub= %s\n",strsub);
	printf("countNumOfSubstringInString= %d",countNumOfSubstringInString(strsub,strData));
}