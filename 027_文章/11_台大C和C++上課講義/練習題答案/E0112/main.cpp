#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1
int main()
{
    int intA,intB;
    int intMean;
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"計算兩數的平均值\n"<<"請輸入第一個數值＝\t";
        cin >>intA;

        cout<<"請輸入第二個數值＝\t";
        cin >>intB;

        cout.setf(ios::fixed,ios::floatfield);  //定點表示法

        intMean=(intA+intB)/2;
        cout<<"兩數的平均值=\t"<<intMean<<endl;

     #else
        printf("C mode:\n");

        printf("計算兩數的平均值\n請輸入第一個數值＝\t");
        scanf("%d",&intA);

        printf("請輸入第二個數值＝\t");
        scanf("%d",&intB);

        intMean=(intA+intB)/2;
        printf("兩數的平均值=\t%d\n",intMean);

    #endif
    return 0;
}
