#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    //使用C語言方式把檔案內容讀進
    int i=0;
    FILE *pf='\0';
    char buf[513];
    string strbuf;
    memset(buf,0,sizeof(buf));
    pf=fopen("filelist.txt","r");
    vector<string> vec_file;
    vec_file.clear();
    while(fgets(buf,512,pf) != NULL)
    {
        buf[strlen(buf)-1]='\0';
        vec_file.push_back(buf);
    }
    for ( i = 0 ; i < vec_file.size() ; i++ )
    {
        strbuf=vec_file[i];
        strcpy(buf, strbuf.c_str());
        printf("%s\n",buf);
    }
    return 0;
}
