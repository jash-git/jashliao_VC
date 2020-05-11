#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char source[80];
    char search[80];
    char *loc;
	
    printf("輸入字串：");
    gets(source);
	
    printf("搜尋子字串：");
    gets(search);
	
    loc = strstr(source, search);
	
    if(loc == NULL) {
        printf("找不到符合的子字串\n");
    }
    else {
        printf("在索引位置 %d 處找到子字串\n", loc - source);
    }
	
    return 0; 
}