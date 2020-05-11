#include <iostream>
#include <cstdio>
#include <cstdlib>/* malloc, free, rand */
#include <cstring>/*strncpy .....*/
#include <string>/*c++ string class*/
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;
/*
Map 就像是一個對應表
只能拿走最上面的，或是繼續往上疊[先進後出]
基本功能有:
    ▲ []: 得到對應的值
    ▲ count: 檢查某個值是否有對應值
    ▲ size: 取個數
Map 的優點
    ▲ 設定對應值很簡單
    ▲ 用很高的效率找到對應值
Map 的缺點
    ▲ 對應值越多會越慢
本範例額外紀錄
    ▲ string 對應到 string 當沒有值會顯示空白
    ▲ string 對應到 int 當沒有值會顯示 0
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}

int main()
{
    /*
    //原始範例
    map<string, int> m;     // 從 string 對應到 int

    m["one"] = 1;       // "one" -> 1
    m["two"] = 2;       // "two" -> 2
    m["three"] = 3;     // "three" -> 3

    cout << m["one"] << endl;       // 1
    cout << m["three"] << endl;     // 3
    cout << m["ten"] << endl;       // 0 (無對應值)
    //*/

    //*
    map<string, string> m1;     // 從 string 對應到 string

    m1["one"] = "01";       // "one" -> 1
    m1["two"] = "02";       // "two" -> 2
    m1["three"] = "03";     // "three" -> 3
    cout<< m1.size() << endl;
    cout<< "----------"<<endl;

    cout << m1["one"] << endl;       // 1
    cout << m1["three"] << endl;     // 3
    cout << m1["ten"] << endl;       // 空白字元
    cout<< "----------"<<endl;
    m1.clear();
    cout<< m1.size() << endl;
    cout<< "----------"<<endl;
    //*/
    Pause();
    return 0;
}
