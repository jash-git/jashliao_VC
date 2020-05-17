#ifndef CMYCAB_H
#define CMYCAB_H

#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <memory.h>

#include <string.h>

//#include <error.h>

#include <direct.h>

using namespace std;




//最多打包文件個數

#define MAX_FILE_COUNT 1024

//最大路徑字元長度

#define MAX_PATH 260




//文件頭

struct FileHead

{

    unsigned int FileCount;//文件個數

    unsigned int FileLen[MAX_FILE_COUNT];//文件大小

    char FileName[MAX_FILE_COUNT][MAX_PATH];//檔案名

};

class CMyCab
{

private:

    FileHead fh;//文件頭

    char ObjectFilePathName[MAX_PATH];//生成打包檔位置及名稱

public:

    CMyCab(void);

    ~CMyCab(void);




    //添加文件到包內

    void AddFile(const char * FilePathName);

    //設置打包輸出文件

    void SetOutPutFile(char * OutFile);

    //獲取檔大小(傳入以二進制方式打開的檔指針)

    long GetFileSize(FILE *pf);

    //製作打包文件

    void DoMakeCAB();

    //解包(為了節省時間不寫錯誤處理了,可以根據上面自己添加)

    void DoUnCAB(char *CabFilePathName);

private:

    //顯示打包內檔資訊

    void printCAB();

    //創建文件夾

    void CheckTargetPath(string targetPath);

};


#endif // CMYCAB_H
