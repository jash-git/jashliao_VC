#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0
int main()
{
    double dblFahrenheit,dblCelsius;
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"���ū� = 5��(�ؤ�ū�-32)/9\n"<<"�п�J�ؤ�ūס�\t";
        cin >>dblFahrenheit;

        cout.setf(ios::fixed,ios::floatfield);  //�w�I��ܪk

        dblCelsius = 5*(dblFahrenheit-32)/9;
        cout<<"���ū� =\t"<<setprecision(2)<<dblCelsius<<endl;
    #else
        printf("C mode:\n");

        printf("���ū� = 5��(�ؤ�ū�-32)/9\n�п�J�ؤ�ūס�\t");
        scanf("%lf",&dblFahrenheit);

        dblCelsius = 5*(dblFahrenheit-32)/9;
        printf("���ū� =\t%11.2lf\n",dblCelsius);

    #endif
    return 0;
}
