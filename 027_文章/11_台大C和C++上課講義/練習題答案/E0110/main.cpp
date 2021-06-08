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

        cout<<"BMI計算\n"<<"請輸入身高（m）＝\t";
        cin >>dblHeight;

        cout<<"請輸入體重（kg）＝\t";
        cin >>dblWeight;

        cout.setf(ios::fixed,ios::floatfield);  //定點表示法

        dblBMI=dblWeight/(dblHeight*dblHeight);
        cout<<"BMI=\t"<<setprecision(2)<<dblBMI<<endl;

     #else
        printf("C mode:\n");

        printf("BMI計算\n請輸入身高（m）＝\t");
        scanf("%lf",&dblHeight);

        printf("請輸入體重（kg）＝\t");
        scanf("%lf",&dblWeight);

        dblBMI=dblWeight/(dblHeight*dblHeight);
        printf("BMI=\t%11.2lf\n",dblBMI);

    #endif
    return 0;
}
