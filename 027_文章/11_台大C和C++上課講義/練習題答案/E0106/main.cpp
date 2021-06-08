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

        cout<<"計算3*x^2+4*x-1\n請輸入x的變數直=\t";
        cin >>dblx;

        cout.setf(ios::fixed,ios::floatfield);  //定點表示法
        dbly=(3*dblx*dblx)+(4*dblx)-1;
        cout<<"計算3*x^2+4*x-1=\t"<<dbly<<endl;

    #else
        printf("C mode:\n");

        printf("計算3*x^2+4*x-1\n請輸入x的變數直=\t");
        scanf("%lf",&dblx);

        dbly=(3*dblx*dblx)+(4*dblx)-1;
        printf("計算3*x^2+4*x-1=\t%11.2lf",dbly);

    #endif
    return 0;
}
