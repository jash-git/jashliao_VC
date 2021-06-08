#include <iostream>
#include <cstdio>
using namespace std;
# define CPP_mode 0
int main()
{
    int intyear;
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"民國年份 = 西元年份 - 1911";

        cout<<"請輸入西元年份：\t";
        cin>>intyear;

        cout<<"民國年份 =\t"<<(intyear - 1911);
    #else
        printf("C mode:\n");

        printf("民國年份 = 西元年份 - 1911");

        printf("請輸入西元年份：\t");
        scanf("%d",&intyear);

        printf("民國年份 =\t%d",(intyear - 1911));

    #endif
    return 0;
}
