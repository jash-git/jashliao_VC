#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1

int main()
{
    long double x = 1292635428;
    //X^3=2159872744519190546127922752
    x=x*x*x;
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout.setf(ios::fixed,ios::floatfield);  //定點表示法
        cout<<"long double\t"<<sizeof(long double)<<endl;
        cout<<"double x^3 ="<<setprecision(2)<<x<<endl;
    #else
        printf("C mode:\n");
        //printf("long double\t%d\n", sizeof(long double));
        printf("double x^3 =%20.2lf\n",x);
        printf("double x^3 =%e\n",x);
    #endif
    return 0;
}
