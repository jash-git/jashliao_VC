#include <iostream>
#include <cstdio>
#include <cstdlib>/* malloc, free, rand */
#include <cstring>/*strncpy .....*/
#include <string>/*c++ string class*/
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;
/*
Set 就是集合
只能拿走最上面的，或是繼續往上疊[先進後出]
基本功能有:
    ▲ insert: 把一個數字放進集合
    ▲ erase: 把某個數字從集合中移除
    ▲ count: 檢查某個數是否有在集合中
    ▲ size: 取個數
Set 的優點
    ▲ 操作很簡單
    ▲ 可以快速檢查裡面有沒有某個元素
Set 的缺點
    ▲ 當 Set 裡面東西太多時會拖慢速度
本範例額外紀錄
    ▲
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}

int main()
{
    set<int> mySet;
    mySet.insert(20);   // mySet = {20}
    mySet.insert(10);   // mySet = {10, 20}
    mySet.insert(30);   // mySet = {10, 20, 30}
    cout<< mySet.size() << endl;
    cout<< "--------------------" << endl;

    cout << mySet.count(20) << endl;    // 存在 -> 1
    cout << mySet.count(100) << endl;   // 不存在 -> 0
    cout<< "--------------------" << endl;

    mySet.erase(20);                    // mySet = {10, 30}
    cout << mySet.count(20) << endl;    // 0
    cout<< mySet.size() << endl;
    cout<< "--------------------" << endl;
    mySet.clear();
    cout<< mySet.size() << endl;

    Pause();
    return 0;
}
