#include <iostream>
#include <cstdio>
#include <cstdlib>/* malloc, free, rand */
#include <cstring>/*strncpy .....*/
#include <string>/*c++ string class*/
#include <vector>
#include <queue>

using namespace std;
/*
Queue 就像是排隊買東西
只能往尾巴排，然後從頭出來[先進先出 FIFO]
基本功能有:
    ▲ push: 把一個值加到尾巴
    ▲ pop: 把第一個值移除掉
    ▲ back: 得到尾巴的值
    ▲ front: 得到頭的值
    ▲ size: 取個數
Queue 的優點
    ▲ 可以快速的把頭的值拿掉
Queue 的缺點
    ▲ 只能操作頭跟尾
本範例額外紀錄
    ▲ 自製清空queue函數
    ▲
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
void queue_clear( std::queue<int> &q )//清空queue
{
   //https://stackoverflow.com/questions/709146/how-do-i-clear-the-stdqueue-efficiently
   std::queue<int> empty;
   std::swap( q, empty );
}
int main()
{
    queue<int> q;   // 一個空的 queue
    q.push(10);
    q.push(20);
    q.push(30);     // [10, 20, 30]

    cout << q.front() << endl;  // 10
    cout << q.back() << endl;   // 30

    q.pop();                    // 剩下[20, 30]
    cout << q.size() << endl;   // 2
    queue_clear(q);
    cout << q.size() << endl;

    for(int i=0 ; i<5 ; i++){
        q.push(i * 10);
    }                   // 依序存入[0, 10, 20, 30, 40]
    cout << q.size() << endl;//顯示放入數量

    while(q.size() != 0){
        cout << q.front() << endl;
        q.pop();
    }                   // 依序取出 0 10 20 30 40
    cout << q.size() << endl;//顯示最後數量

    Pause();
    return 0;
}
