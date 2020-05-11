#include <iostream>
#include <cstdio>
#include <cstdlib>/* malloc, free, rand */
#include <cstring>/*strncpy .....*/
#include <string>/*c++ string class*/

using namespace std;

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    //---
    //C++字串範例
    string s1="";//初始化字符串，空字符串
    s1 = "My name is jash.liao";
    cout << "s1=" << s1 << endl;

    string s2 = s1; //拷贝初始化，深拷贝字符串
    s2[0]='m';//修改字串內的單一字元
    cout << "s2=" << s2 << endl;

    string s3 = "I am Yasuo"; //直接初始化，s3存了字符串
    cout << "s3=" << s3 << endl;

    string s4(10, 'a'); //s4存的字符串是aaaaaaaaaa
    cout << "s4=" << s4 << endl;

    string s5(s4); //拷贝初始化，深拷贝字符串
    cout << "s5=" << s5 << endl;

    string s6("I am Ali"); //直接初始化
    cout << "s6=" << s6 << endl;

    string s7 = string(6, 'c'); //拷贝初始化，cccccc
    cout << "s7=" << s7 << endl;

    string s8 = s4 + s7;//将两个字符串合并成一个
    cout << "s8 size=" << s8.size() << endl;//計算字串長度
    printf("S8:%s\n",s8.c_str());//抓出C的字串指標並用C函數輸出

    string str ("http://127.0.0.1:9999/888.mp4");
    string str2 (".mp4");
    size_t found;
    found=str.find(str2);//C++字串搜尋
    cout << found <<endl;

    string str3=str;
    cout << str3 << endl;
    str3.replace(found,4,"");//C++字串取代
    cout << str3 <<endl;

    char *data = (char*)malloc(str3.size()+1);//純C動態配置字串記憶體
    for(int i=0;i<(str3.size()+1);i++)//純C動態配置字串記憶體初始化
    {
        *(data+i)='\0';
    }
    strncpy(data,str3.c_str(),str3.size());//C++字串拷貝至C字串中
    printf("data=%s\n",data);
    free(data);
    //---C++字串範例

    Pause();
    return 0;
}
