#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0

int main()
{
    int intvalue;
    intvalue=0;
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"判斷整數的正負號\n";
        cout<<"請輸入要判斷的整數: \t";
        cin >>intvalue;
        if(intvalue>=0)
        {
            cout<<"該數為正整數\n";
        }
        else
        {
           cout<<"該數為負整數\n";
        }
    #else
        printf("C mode:\n");

        printf("判斷整數的正負號\n");
        printf("請輸入要判斷的整數: \t");
        scanf("%d",&intvalue);
         if(intvalue>=0)
        {
            printf("該數為正整數\n");
        }
        else
        {
            printf("該數為負整數\n");
        }
    #endif
    return 0;
}
