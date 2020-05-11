#include <stdlib.h>
#include <stdio.h>
#include <string.h>
/*
支援集合操作：
　　%[a-z] 表示匹配a到z中任意字元，貪婪性(盡可能多的匹配)
　　%[aB'] 匹配a、B、'中一員，貪婪性
　　%[^a] 匹配非a的任意字元，貪婪性
*/
int main()
{
	char Info[]="Dec 12/25 School ClassRoom";
	char Data1[16];
	char Data2[16];
	char Data3[16];
        char Data4[16];
	sscanf(Info, "%s %s %s", Data1, Data2,Data3);
        printf("Data1:%s Data2:%s Data3:%s\n", Data1, Data2, Data3);
	sscanf(Info, "%[^ ] %[^ ] %[^ ]", Data1, Data2,Data3);
        printf("Data1:%s Data2:%s Data3:%s\n", Data1, Data2, Data3);
	sscanf(Info, "%s  %[^ ] %[a-z A-Z]", Data1, Data2,Data3);
    sscanf(Info, "%s  %[^ ] %[a-z A-Z]", Data1, Data4);
	printf("Data1:%s Data2:%s Data3:%s\n", Data1, Data4, Data3);

}
