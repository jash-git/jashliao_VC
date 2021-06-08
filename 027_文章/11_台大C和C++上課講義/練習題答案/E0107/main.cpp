#include <iostream>
#include <cstdio>
using namespace std;
# define CPP_mode 1
int main()
{
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"Hello world !\n";


    #else
        printf("C mode:\n");

        printf("Hello world !\n");
    #endif
    return 0;
}
