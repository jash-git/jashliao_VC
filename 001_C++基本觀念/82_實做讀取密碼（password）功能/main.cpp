#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & (~ENABLE_ECHO_INPUT));

    string s;
    getline(cin, s);
    cout<<s <<endl;

    SetConsoleMode(hStdin, mode | ENABLE_ECHO_INPUT);
    getline(cin, s);
    cout<<s <<endl;
    return 0;
}//main
