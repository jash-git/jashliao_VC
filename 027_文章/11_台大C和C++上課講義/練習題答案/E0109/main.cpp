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

        cout<<"尼ん放 = 5⊙(地ん放-32)/9\n"<<"叫块地ん放∽\t";
        cin >>dblFahrenheit;

        cout.setf(ios::fixed,ios::floatfield);  //﹚翴ボ猭

        dblCelsius = 5*(dblFahrenheit-32)/9;
        cout<<"尼ん放 =\t"<<setprecision(2)<<dblCelsius<<endl;
    #else
        printf("C mode:\n");

        printf("尼ん放 = 5⊙(地ん放-32)/9\n叫块地ん放∽\t");
        scanf("%lf",&dblFahrenheit);

        dblCelsius = 5*(dblFahrenheit-32)/9;
        printf("尼ん放 =\t%11.2lf\n",dblCelsius);

    #endif
    return 0;
}
