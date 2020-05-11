#include "CSerchAllFile.h"

static CSerchAllFile* instance;

CSerchAllFile::CSerchAllFile(void)
{

}




CSerchAllFile::~CSerchAllFile(void)
{

}




CSerchAllFile* CSerchAllFile::getInstance()
{
    if (instance == NULL)
    {
        instance = new CSerchAllFile();
    }
    return instance;

}




//遍歷檔夾下的檔案名列表(包括嵌套檔夾)

void CSerchAllFile::get_filelist(char *foldname,vector<string> &filelist)
{

    HANDLE hFind;

    WIN32_FIND_DATA fileData;

    string line;

    char fn[MAX_PATH];

    char tmpfn[MAX_PATH];

    strcpy(fn,foldname);

    //需要對檔夾名的字元串進行處理

    if(fn[strlen(fn) -1] != '\\' )
    {
        strcat(fn, "\\");
    }
    //留意順序，此時fn已加入"\\"

    strcpy(tmpfn,fn);

    //不加*會出錯！

    strcat(fn, "*");

    hFind = FindFirstFile(fn, &fileData);

    FindNextFile(hFind, &fileData);

    while(FindNextFile(hFind, &fileData))

    {

        //如果掃描到的當前為檔夾

        if (fileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)

        {
            if(fileData.cFileName[0]!='.')
            {

                char szFile[MAX_PATH];

                strcpy(szFile,tmpfn);

                strcat(szFile,fileData.cFileName);

                get_filelist(szFile,filelist);

            }

        }

        //掃描到文件

        else
        {

            line = (string)tmpfn;

            line+=fileData.cFileName;

            /*if (line.find(".h",0)!=string::npos)

            {

            filelist.push_back(line);

            }

            else

            {

            continue;

            }*/

            filelist.push_back(line);

        }

//cout<<line<<endl;

    }

}
