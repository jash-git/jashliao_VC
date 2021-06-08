#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1

int main()
{
    int intvalue00,intvalue01;
    intvalue00=0;
    intvalue01=0;
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"兩數排序\n";
        cout<<"請輸入兩個整數: \t";
        cin >>intvalue00>>intvalue01;
        cout<<"排序後的結果: \t";
        if(intvalue00>intvalue01)
        {
            cout<<intvalue01<<"\t"<<intvalue00<<endl;
        }
        else
        {
            cout<<intvalue00<<"\t"<<intvalue01<<endl;
        }

    #else
        printf("C mode:\n");

        printf("兩數排序\n");
        printf("請輸入兩個整數: \t");
        scanf("%d %d",&intvalue00,&intvalue01);
        printf("排序後的結果: \t");
        if(intvalue00>intvalue01)
        {
            printf("%d\t%d\n",intvalue01,intvalue00);
        }
        else
        {
            printf("%d\t%d\n",intvalue00,intvalue01);
        }

    #endif
    return 0;
}
