#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0
int main()
{
    double dblHeight,dblWeight;
    double dblBMI;
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"BMI�p��\n"<<"�п�J�����]m�^��\t";
        cin >>dblHeight;

        cout<<"�п�J�魫�]kg�^��\t";
        cin >>dblWeight;

        cout.setf(ios::fixed,ios::floatfield);  //�w�I��ܪk

        dblBMI=dblWeight/(dblHeight*dblHeight);
        cout<<"BMI=\t"<<setprecision(2)<<dblBMI<<endl;

     #else
        printf("C mode:\n");

        printf("BMI�p��\n�п�J�����]m�^��\t");
        scanf("%lf",&dblHeight);

        printf("�п�J�魫�]kg�^��\t");
        scanf("%lf",&dblWeight);

        dblBMI=dblWeight/(dblHeight*dblHeight);
        printf("BMI=\t%11.2lf\n",dblBMI);

    #endif
    return 0;
}
