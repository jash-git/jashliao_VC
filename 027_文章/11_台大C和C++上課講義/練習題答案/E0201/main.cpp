#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0

int main()
{
    double x = 3000000000000000.5;
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout.setf(ios::fixed,ios::floatfield);  //定點表示法
        cout<<"double x ="<<setprecision(1)<<x<<endl;
    #else
        printf("C mode:\n");
        printf("double x =%18.1lf\n",x);
    #endif
    return 0;
}
