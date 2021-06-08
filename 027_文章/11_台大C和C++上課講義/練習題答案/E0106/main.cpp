#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0
int main()
{
    double dblx;
    double dbly;
    //y=3*x^2+4*x-1
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"�p��3*x^2+4*x-1\n�п�Jx���ܼƪ�=\t";
        cin >>dblx;

        cout.setf(ios::fixed,ios::floatfield);  //�w�I��ܪk
        dbly=(3*dblx*dblx)+(4*dblx)-1;
        cout<<"�p��3*x^2+4*x-1=\t"<<dbly<<endl;

    #else
        printf("C mode:\n");

        printf("�p��3*x^2+4*x-1\n�п�Jx���ܼƪ�=\t");
        scanf("%lf",&dblx);

        dbly=(3*dblx*dblx)+(4*dblx)-1;
        printf("�p��3*x^2+4*x-1=\t%11.2lf",dbly);

    #endif
    return 0;
}
