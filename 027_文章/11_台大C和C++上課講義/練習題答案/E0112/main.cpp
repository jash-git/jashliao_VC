#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1
int main()
{
    int intA,intB;
    int intMean;
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"�p���ƪ�������\n"<<"�п�J�Ĥ@�Ӽƭȡ�\t";
        cin >>intA;

        cout<<"�п�J�ĤG�Ӽƭȡ�\t";
        cin >>intB;

        cout.setf(ios::fixed,ios::floatfield);  //�w�I��ܪk

        intMean=(intA+intB)/2;
        cout<<"��ƪ�������=\t"<<intMean<<endl;

     #else
        printf("C mode:\n");

        printf("�p���ƪ�������\n�п�J�Ĥ@�Ӽƭȡ�\t");
        scanf("%d",&intA);

        printf("�п�J�ĤG�Ӽƭȡ�\t");
        scanf("%d",&intB);

        intMean=(intA+intB)/2;
        printf("��ƪ�������=\t%d\n",intMean);

    #endif
    return 0;
}
