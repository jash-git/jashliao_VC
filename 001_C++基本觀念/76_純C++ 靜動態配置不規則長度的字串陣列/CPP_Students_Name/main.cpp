#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;
/*
    純C++ 靜/動態配置不規則長度的字串陣列
    目的節省記憶體的用量
*/
int main()
{
    /*
    //靜態宣告2個長度不同的字串（字元陣列）
    char *pchrStudentName[2]={"Tom lin","Jash liao"};
    cout << pchrStudentName[0] << endl;
    cout << pchrStudentName[1] << endl;
    //*/

    //*
    //動態態宣告N個長度不同的字串（字元陣列）
    char **pchrStudentName;
    char buf[100];
    int num=0,i=0,j=0;
    cout<<"輸入個數:"<< "\t";
    cin>>num;
    pchrStudentName= new char*[i];
    for(i=0;i<num;i++)
    {
        buf[0]='\0';
        cout<<"輸入第"<<i<<"個人名:"<< "\t";

        cin>>buf;
        j=strlen(buf);
        pchrStudentName[i] = new char[j];
        strcpy(pchrStudentName[i],buf);
    }
    for(i=0;i<num;i++)
    {

        cout<<"輸入第"<<i<<"個人名:"<< "\t";
        cout<<pchrStudentName[i]<< endl;
    }
    //*/
    return 0;
}
