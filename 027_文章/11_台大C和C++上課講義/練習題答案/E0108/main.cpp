#include <iostream>
#include <cstdio>
using namespace std;
# define CPP_mode 0
int main()
{
    int intyear;
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"����~�� = �褸�~�� - 1911";

        cout<<"�п�J�褸�~���G\t";
        cin>>intyear;

        cout<<"����~�� =\t"<<(intyear - 1911);
    #else
        printf("C mode:\n");

        printf("����~�� = �褸�~�� - 1911");

        printf("�п�J�褸�~���G\t");
        scanf("%d",&intyear);

        printf("����~�� =\t%d",(intyear - 1911));

    #endif
    return 0;
}
