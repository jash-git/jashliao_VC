#include <iostream>
#include "CSerchAllFile.h"
#include "CMyCab.h"
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    vector<string> vec_file;
    vector<string>::iterator itemFileName;
    char filePacketPath[MAX_PATH] = "C:\\CPP_CAB_Sources";//"D:\\sqliteadmin";
    char filePutPath[MAX_PATH] = "D:\\my.cab";
    CSerchAllFile::getInstance()->get_filelist(filePacketPath, vec_file);
    //--------------------打包過程--------------------
    //聲明對象
    CMyCab mc;
    //設置輸出文件
    mc.SetOutPutFile(filePutPath);
    //添加要打包的文件
    for(itemFileName=vec_file.begin(); itemFileName<vec_file.end(); itemFileName++)
    {
        mc.AddFile((*itemFileName).c_str());
    }
    //執行打包
    mc.DoMakeCAB();

    //--------------------解過程--------------------
    //聲明對象
    CMyCab umc;
    //執行解包
    umc.DoUnCAB("D:\\my.cab");

    return 0;
}
