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
        cout<<"�P�_��ƪ����t��\n";
        cout<<"�п�J�n�P�_�����: \t";
        cin >>intvalue;
        if(intvalue>=0)
        {
            cout<<"�ӼƬ������\n";
        }
        else
        {
           cout<<"�ӼƬ��t���\n";
        }
    #else
        printf("C mode:\n");

        printf("�P�_��ƪ����t��\n");
        printf("�п�J�n�P�_�����: \t");
        scanf("%d",&intvalue);
         if(intvalue>=0)
        {
            printf("�ӼƬ������\n");
        }
        else
        {
            printf("�ӼƬ��t���\n");
        }
    #endif
    return 0;
}
