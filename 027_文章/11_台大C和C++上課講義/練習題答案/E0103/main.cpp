#include <iostream>
#include <cstdio>
using namespace std;
# define CPP_mode 0
int main()
{
    int intvalue;//宣告一個變數
    intvalue=0;//變數初始化
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"請輸入一個整數:\t";
        cin >>intvalue;
        cout<<"您輸入的整數為："<<intvalue<<" 該整數加 7＝ "<<(intvalue+7)<<endl;
    #else
        printf("C mode:\n");
        printf("請輸入一個整數:\t");
        scanf("%d",&intvalue);
        printf("您輸入的整數為：%d 該整數加 7＝ %d",intvalue,(intvalue+7));
    #endif


    return 0;
}
