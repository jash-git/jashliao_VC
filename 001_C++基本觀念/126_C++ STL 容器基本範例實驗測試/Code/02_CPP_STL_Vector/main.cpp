#include <iostream>
#include <cstdio>
#include <cstdlib>/* malloc, free, rand */
#include <cstring>/*strncpy .....*/
#include <string>/*c++ string class*/
#include <vector>

using namespace std;
/*
Vector 可以看成是一個動態陣列
用法跟陣列很像，基本功能有 :
    ▲ push_back: 把一個值加到尾巴
    ▲ pop_back: 把尾巴的值移除掉
    ▲ size: 得到目前長度(元素個數)
    ▲ []: 得到某一個位置的值
    ▲ clear: 把元素清空
Vector 的優點
    ▲ 宣告時可以不用確定大小
    ▲ 可以 Random Access
Vector 的缺點
    ▲ 在內部進行刪除時效率很低
本範例額外紀錄
    ▲ 純C數值(整數/浮點數)轉字串
    ▲ C++字串相加
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}

int main()
{
    vector<int> vec;    // 宣告一個裝 int 的 vector
                        // 現在 vec 是空的
    vec.push_back(10);
    vec.push_back(20);  // 經過三次 push_back
    vec.push_back(30);  // vec 是 [10, 20, 30]

    int length = vec.size();        // length = 3
    for(int i=0 ; i<length ; i++){
        cout << vec[i] << endl;     // 輸出 10, 20, 30
    }
    vec.clear();// 現在 vec 是空的


    for(int i=0 ; i<5 ; i++){
       vec.push_back(i * 10);       // [0, 10, 20, 30, 40]
    }

    for(int i=0 ; i<vec.size() ; i++){
        cout << vec[i] << endl;     // 輸出 0, 10, 20, 30, 40
    }
    vec.clear();// 現在 vec 是空的

    for(int i=0 ; i<5 ; i++){
       vec.push_back(i * 10);       // [0, 10, 20, 30, 40]
    }

    vec.pop_back();     // 移除 40
    vec.pop_back();     // 移除 30

    for(int i=0 ; i<vec.size() ; i++){  // vec.size() = 3
        cout << vec[i] << endl;         // 輸出 0, 10, 20
    }
    vec.clear();// 現在 vec 是空的

    vector<string> vecStr;
    string strbase = "value = ";
    for(int i=0 ; i<5 ; i++){
       strbase = "value = ";
       char buf[30];
       sprintf(buf,"%d",(i * 10));//純C數值(整數/浮點數)轉字串
       strbase = strbase + buf;//C++字串相加
       vecStr.push_back(strbase);       // [0, 10, 20, 30, 40]
    }
    for(int i=0 ; i<vecStr.size() ; i++){  // vec.size() = 3
        cout << vecStr[i] << endl;         // 輸出 0, 10, 20
    }
    vecStr.clear();
    Pause();
    return 0;
}
