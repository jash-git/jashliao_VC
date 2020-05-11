#include <iostream>
#define setArray(a) \
{                   \
    *(a+0)='j';     \
    *(a+1)='a';     \
    *(a+2)='s';     \
    *(a+3)='h';     \
    *(a+4)='\0';     \
}
using namespace std;

int main()
{
    char data[5];
    cout << data << endl;
    setArray(data);
    cout << data << endl;
    cout << "Hello world!" << endl;
    return 0;
}
