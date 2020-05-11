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
#include<algorithm>
using namespace std;
/*
Algorithm
    sort:排序
    reverse:反轉
    find:搜尋
本範例額外紀錄
    ▲ 陣列 轉存 vector
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
    int arr[] = {3, 1, 4, 2, 5};
    vector<int> vec(arr, arr+5);    // vec = [3, 1, 4, 2, 5]


    // 排序前三個 -> [1, 3, 4, 2, 5]
    sort(vec.begin(), vec.begin() + 3);


    // 全部排序 -> [1, 2, 3, 4, 5]
    sort(vec.begin(), vec.end());


    // 反轉 -> [5, 4, 3, 2, 1]
    reverse(vec.begin(), vec.end());


    // 找找看 3 有沒有在裡面
    // 找不到就會回傳 vec.end()
    vector<int>::iterator it;
    it = find(vec.begin(), vec.end(), 3);

    if(it != vec.end()){
        cout << "3 find" << endl;
    } else {
        cout << "3 not find" << endl;
    }
    //*/

    string arr01[] = {"03-three", "01-one", "04-four", "02-two", "05-five"};
    vector<string> vec01(arr01, arr01+5);//陣列 轉存 vector
    int length = vec01.size();
    for(int i=0 ; i<length ; i++){
        cout << vec01[i] << endl;
    }
    cout << "--------------"<< endl;

    // 排序前三個 -> [1, 3, 4, 2, 5]
    sort(vec01.begin(), vec01.begin() + 3);
    length = vec01.size();
    for(int i=0 ; i<length ; i++){
        cout << vec01[i] << endl;
    }
    cout << "--------------"<< endl;

    // 全部排序 -> [1, 2, 3, 4, 5]
    sort(vec01.begin(), vec01.end());
    length = vec01.size();
    for(int i=0 ; i<length ; i++){
        cout << vec01[i] << endl;
    }
    cout << "--------------"<< endl;

    // 反轉 -> [5, 4, 3, 2, 1]
    reverse(vec01.begin(), vec01.end());
    length = vec01.size();
    for(int i=0 ; i<length ; i++){
        cout << vec01[i] << endl;
    }
    cout << "--------------"<< endl;

    // 找找看 3 有沒有在裡面
    // 找不到就會回傳 vec.end()
    vector<string>::iterator it01;
    string strbuf = "03-three";
    it01 = find(vec01.begin(), vec01.end(), strbuf);

    if(it01 != vec01.end()){
        cout << "3 find" << endl;
    } else {
        cout << "3 not find" << endl;
    }
    Pause();
    return 0;
}
