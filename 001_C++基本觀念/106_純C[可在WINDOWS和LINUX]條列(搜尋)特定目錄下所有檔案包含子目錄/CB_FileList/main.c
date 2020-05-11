#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <dirent.h>

//http://jax-work-archive.blogspot.tw/2009/04/c_7783.html

/* dir_recursive [遞迴掃瞄目錄下所有文件]
 * 掃瞄 path 下所有的文件，並輸出至 output 的文件中
 * output 必須為可寫入的文件
 * */
int dir_recursive(char *path, FILE *output){
    char glue='\\'; // Windows 的分隔符號
    //char glue='/'; // Linux 的分隔符號

    // 嘗試開啟目錄
    DIR * dp = opendir(path);

    if (!dp){
        // 不是目錄，輸出至檔案
           fprintf(output,"%s\n",path);
           return 1;
    }

    struct dirent *filename;
    while((filename=readdir(dp))){
        // 跳過當前及母目錄
        if(!strcmp(filename->d_name,"..") || !strcmp(filename->d_name,".")){
            continue;
        }

        // 計算新的路徑字串所需的長度
        int pathLength=strlen(path)+strlen(filename->d_name)+2;
        // 產生新的陣列空間
        char *pathStr = (char*)malloc(sizeof(char) * pathLength);
        // 複製當前目錄路徑至新的陣列空間
        strcpy(pathStr, path);

        // 檢查目錄分隔符號
        int i=strlen(pathStr);
        if(pathStr[i-1]!=glue){
            pathStr[i]=glue;
            pathStr[i+1]='\0';
        }

        // 串接次目錄名稱或檔案名稱至新的陣列空間
        strcat(pathStr, filename->d_name);

        // 遞迴呼叫目錄掃瞄
        dir_recursive(pathStr,output);

    }

    // 關閉目錄
    closedir(dp);

    return 1;
}



int main(){
    // 建立輸出的文件檔
    FILE *fileOut = fopen("output.txt", "w");

    // 掃瞄 E:\test 下所有的文件
    dir_recursive("D:\\sqliteadmin",fileOut);

    return 0;
}

