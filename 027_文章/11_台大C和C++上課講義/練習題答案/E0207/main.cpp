#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1

int main()
{
    char chrValue;
    chrValue='\0';
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"�P�_�r������\n";
        cout<<"�п�J�n�P�_���r��: \t";
        cin>>chrValue;
        if((chrValue>=48)&&(chrValue<=57))
        {
            cout<<"�r������=�Ʀr\n";
        }
        else if((chrValue>=97)&&(chrValue<=122))
        {
            cout<<"�r������=�p�g�^��\n";
        }
        else if((chrValue>=65)&&(chrValue<=90))
        {
            cout<<"�r������=�j�g�^��\n";
        }
        else
        {
            cout<<"�r������=�䥦\n";
        }
    #else
        printf("C mode:\n");
        printf("�P�_�r������\t");
        scanf("%c",&chrValue);
        if((chrValue>=48)&&(chrValue<=57))
        {
            printf("�r������=�Ʀr\n");
        }
        else if((chrValue>=97)&&(chrValue<=122))
        {
            printf("�r������=�p�g�^��\n");
        }
        else if((chrValue>=65)&&(chrValue<=90))
        {
            printf("�r������=�j�g�^��\n");
        }
        else
        {
            printf("�r������=�䥦\n");
        }
    #endif
    return 0;
}
