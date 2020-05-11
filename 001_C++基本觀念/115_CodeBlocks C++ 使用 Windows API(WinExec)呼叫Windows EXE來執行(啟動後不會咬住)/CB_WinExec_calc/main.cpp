#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

int main()
{

    WinExec("calc.exe",SW_HIDE);//cout << "Hello world!" << endl;
    Sleep( 3000 );
    WinExec("C:\\Windows\\explorer.exe /n ,/root, C:\\Keil\\", SW_SHOWNORMAL);
    return 0;
}
