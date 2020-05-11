#include <iostream>
#include <cstdio>
#include <cstdlib>/* malloc, free, rand */
#include <cstring>/*strncpy .....*/
#include <string>/*c++ string class*/
#include <vector>
#include <queue>
#include <stack>

using namespace std;
/*
Stack 就是一疊盤子
只能拿走最上面的，或是繼續往上疊[先進後出]
基本功能有:
    ▲ top: 得到最上面的值
    ▲ push: 再拿一個盤子往上疊
    ▲ pop: 拿掉最上面的盤子
    ▲ size: 取個數
Stack 的優點
    ▲ 操作很簡單(只有疊上去跟拿下來XD)
Stack 的缺點
    ▲ 只能操作最上面的那個值
本範例額外紀錄
    ▲ 自製清空stack函數
    ▲
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
void stack_clear( std::stack<int> &s )//清空stack
{
   //https://stackoverflow.com/questions/709146/how-do-i-clear-the-stdqueue-efficiently
   std::stack<int> empty;
   std::swap( s, empty );
}
int main()
{
    stack<int> s;

    s.push(10);     //  | 30 |
    s.push(20);     //  | 20 |   疊三個盤子
    s.push(30);     //  |_10_|   10 在最下面
    cout << s.size() << endl;//顯示放入數量

    int j=s.size();
    for(int i=0 ; i<j; i++){    // s.size() = 3
        cout << s.top() << endl;
        s.pop();
    }                                   // 依序輸出 30, 20, 10
    cout << "-----------------------------" << endl;

    for(int i=0 ; i<5 ; i++){
        s.push(i * 10);
    }                   // 依序存入[0, 10, 20, 30, 40]
    stack_clear( s );//清空stack
    cout << s.size() << endl;//顯示放入數量
    cout << "-----------------------------" << endl;

    for(int i=0 ; i<5 ; i++){
        s.push(i * 10);
    }                   // 依序存入[0, 10, 20, 30, 40]
    cout << s.size() << endl;//顯示放入數量
    cout << "-----------------------------" << endl;

    while(s.size() != 0){
        cout << s.top() << endl;
        s.pop();
    }                   // 依序取出 0 10 20 30 40
    cout << s.size() << endl;//顯示最後數量

    Pause();
    return 0;
}
