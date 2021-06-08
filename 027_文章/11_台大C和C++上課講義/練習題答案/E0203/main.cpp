#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1

int main()
{
    double dblkm,dblMile;
    dblkm=0.0;
    dblMile=0.0;
    //建議輸入2.3看結果
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"公里 = 英哩 * 1.6:\n";
        cout<<"請輸入英哩: \t";
        cin>>dblMile;
        dblkm=dblMile*1.6;
        cout.setf(ios::fixed,ios::floatfield);  //定點表示法
        cout<<"公里= "<<setprecision(1)<<dblkm<<endl;
        cout<<"公里= "<<setprecision(2)<<dblkm<<endl;
    #else
        printf("C mode:\n");
        printf("公里 = 英哩 * 1.6:\n");
        printf("請輸入英哩: \t");
        scanf("%lf",&dblMile);
        dblkm=dblMile*1.6;
        printf("公里= %20.1lf\n",dblkm);
        printf("公里= %20.2lf\n",dblkm);
    #endif
    return 0;
}
