#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0

int main()
{
    double x = 3000000000000000.5;//2.225e-308~1.7976e308
    //long double x = 3000000000000000.5;
    x=x+0.05;
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout.setf(ios::fixed,ios::floatfield);  //定點表示法
        cout<<"long double\t"<<sizeof(long double)<<endl;
        cout<<"double x ="<<setprecision(2)<<x<<endl;
    #else
        printf("C mode:\n");
        //printf("long double\t%d\n", sizeof(long double));
        printf("double x =%20.2lf\n",x);
        printf("double x =%e\n",x);
    #endif
    return 0;
}
