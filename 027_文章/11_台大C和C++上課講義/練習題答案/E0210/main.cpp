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
        cout<<"��ƱƧ�\n";
        cout<<"�п�J��Ӿ��: \t";
        cin >>intvalue00>>intvalue01;
        cout<<"�Ƨǫ᪺���G: \t";
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

        printf("��ƱƧ�\n");
        printf("�п�J��Ӿ��: \t");
        scanf("%d %d",&intvalue00,&intvalue01);
        printf("�Ƨǫ᪺���G: \t");
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
