#include "CMyCab.h"

CMyCab::CMyCab(void)

{
    memset(&fh,0x0,sizeof(fh));

    memset(ObjectFilePathName,0x0,sizeof(ObjectFilePathName));
}

CMyCab::~CMyCab(void)
{

}

//添加文件到包內
void CMyCab::AddFile(const char * FilePathName)
{
    if ( fh.FileCount >= MAX_FILE_COUNT - 1 )
    {
        cout<<"最多支援"<<MAX_FILE_COUNT<<"個檔"<<endl;
        return;
    }
    strcpy(fh.FileName[fh.FileCount],FilePathName);
    fh.FileCount++;
}

//設置打包輸出文件
void CMyCab::SetOutPutFile(char * OutFile)
{
    memset(ObjectFilePathName,0x0,sizeof(ObjectFilePathName));
    strcpy(ObjectFilePathName,OutFile);
}

//獲取檔大小(傳入以二進制方式打開的檔指針)
long CMyCab::GetFileSize(FILE *pf)
{
    //指針移到檔案結尾
    fseek(pf,0,/*SEEK_END*/ 2);
    return ftell(pf);
}

//製作打包文件
void CMyCab::DoMakeCAB()
{
    if ( fh.FileCount < 1 )
    {
        cout<<"沒有文件添加到打包"<<endl;
        return;
    }

    if ( strlen(ObjectFilePathName) < 1 )
    {
        cout<<"沒有指定打包檔輸出位置"<<endl;
        return;
    }

    FILE *pOutFile = NULL;
    FILE *pWorkFile = NULL;

    //獲取所有檔大小
    for ( int i = 0 ; i < fh.FileCount ; i++ )
    {
        pWorkFile = fopen(fh.FileName[i],"rb");
        if ( NULL == pWorkFile )
        {
            cout<<"文件:"<<fh.FileName[i]<<"無法讀取["<<strerror(errno)<<"]"<<endl;
            return;
        }
        fh.FileLen[i] = GetFileSize(pWorkFile);
        fclose(pWorkFile);
    }

    //檢查是否有對應的檔夾
    CheckTargetPath(ObjectFilePathName);
    //開始合併寫檔
    pOutFile = fopen(ObjectFilePathName,"wb");
    if ( NULL == pOutFile )
    {
        cout<<"輸出文件創建失敗["<<strerror(errno)<<"]"<<endl;
        return;
    }

    //寫入文件頭
    fwrite(&fh,sizeof(fh),1,pOutFile);

    //寫入各文件
    for ( int i = 0 ; i < fh.FileCount ; i++ )
    {
        unsigned char *pTmpData = NULL;

        pWorkFile = fopen(fh.FileName[i],"rb");

        if ( NULL == pWorkFile )
        {
            cout<<"文件:"<<fh.FileName[i]<<"無法讀取["<<strerror(errno)<<"]"<<endl;

            fclose(pWorkFile);

            fclose(pOutFile);

            return;
        }

        pTmpData = new unsigned char[fh.FileLen[i]];

        fread(pTmpData,fh.FileLen[i],1,pWorkFile);

        if ( ferror(pWorkFile) )
        {
            cout<<"文件:"<<fh.FileName[i]<<"無法讀取["<<strerror(errno)<<"]"<<endl;

            fclose(pWorkFile);

            fclose(pOutFile);

            return;
        }

        fwrite(pTmpData,fh.FileLen[i],1,pOutFile);

        if ( ferror(pOutFile) )
        {
            cout<<"文件:"<<ObjectFilePathName<<"無法寫入["<<strerror(errno)<<"]"<<endl;

            fclose(pWorkFile);

            fclose(pOutFile);

            return;
        }

        delete [] pTmpData;

        fclose(pWorkFile);
    }

    fclose(pOutFile);

    cout<<"打包完成"<<endl;
}

//解包(為了節省時間不寫錯誤處理了,可以根據上面自己添加)
void CMyCab::DoUnCAB(char *CabFilePathName)
{

    FILE *pCAB = NULL;

    FILE *pWork = NULL;

    pCAB = fopen(CabFilePathName,"rb");

    //讀文件頭
    memset(&fh,0x0,sizeof(fh));
    fread(&fh,sizeof(fh),1,pCAB);

    printCAB();

    //解包的所有檔放到當前目錄下
    for ( int i = 0 ; i < fh.FileCount ; i++ )
    {
        unsigned char *pTmpData = NULL;

        pTmpData = new unsigned char[fh.FileLen[i]];

        fread(pTmpData,fh.FileLen[i],1,pCAB);

        //只取檔案名,不要生成檔的路徑名

        char tmpFileName[MAX_PATH];

        string str="d:\\";

        string aaa;

        aaa.assign(fh.FileName[i] ,strlen(fh.FileName[i]) );

        const char *chaaaaa = aaa.replace(0, str.length(), "\\").c_str();
        //printf("%s\n",chaaaaa);
        char ptmpC[MAX_PATH];

        strcpy(ptmpC, chaaaaa);

        memset(tmpFileName,0x0,sizeof(tmpFileName));

        strcpy(tmpFileName,ptmpC+1);

        //取CAB文件路徑

        char tmpPathName[MAX_PATH];

        memset(tmpPathName,0x0,sizeof(tmpPathName));

        strcpy(tmpPathName,CabFilePathName);

        char* tmpC = tmpPathName + strlen(tmpPathName);

        while('\\' != *tmpC)
        {
            tmpC--;
        }

        tmpC++;

        *tmpC = '\0';

        strcat(tmpPathName,tmpFileName);

        pWork = fopen(tmpPathName,"wb");

        if (pWork == NULL)
        {
            CheckTargetPath(tmpPathName);

            pWork = fopen(tmpPathName,"wb");
        }

        fwrite(pTmpData,fh.FileLen[i],1,pWork);

        fclose(pWork);

        delete [] pTmpData;
    }

    fclose(pCAB);
}

//顯示打包內檔資訊
void CMyCab::printCAB()
{
    cout<<"檔內資訊如下:"<<endl;
    cout<<"文件總數:"<<fh.FileCount<<endl;
    for ( int i = 0 ; i < fh.FileCount ; i++ )
    {
        cout<<fh.FileName[i]<<"\t\t\t\t"<<fh.FileLen[i]<<"位元組"<<endl;
    }
}

//創建文件夾
void CMyCab::CheckTargetPath(string targetPath)
{
    //Log &log = Log::getLog("main", "CheckTargetPath");

    int e_pos = targetPath.length();

    int f_pos = targetPath.find("\\",0);

    string subdir;

    do
    {
        e_pos = targetPath.find("\\",f_pos+2);

        if(e_pos != -1)
        {

            subdir = targetPath.substr(0,e_pos);

            if(_mkdir(subdir.c_str())==0)
            {
                printf( "creat success %s",subdir.c_str());
            }
            else
            {
                printf("creat fail %s",subdir.c_str());
            }
        }

        f_pos = e_pos;
    }while(f_pos!=-1);
}
