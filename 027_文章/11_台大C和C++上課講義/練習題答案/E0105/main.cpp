#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0
int main()
{
    double dblLength,dblWidth;
    double dblArea,dblPerimeter;
    #if (CPP_mode)
        cout<<"CPP mode:\n";

        cout<<"長方形計算\n"<<"請輸入長方形的長＝\t";
        cin >>dblLength;

        cout<<"請輸入長方形的寬＝\t";
        cin >>dblWidth;

        cout.setf(ios::fixed,ios::floatfield);  //定點表示法

        dblArea=dblLength*dblWidth;
        cout<<"長方形面積=\t"<<setprecision(2)<<dblArea<<endl;

        dblPerimeter=(dblLength+dblWidth)*2;
        cout<<"長方形週長=\t"<<setprecision(2)<<dblPerimeter<<endl;
    #else
        printf("C mode:\n");

        printf("長方形計算\n請輸入長方形的長＝\t");
        scanf("%lf",&dblLength);

        printf("請輸入長方形的寬＝\t");
        scanf("%lf",&dblWidth);

        dblArea=dblLength*dblWidth;
        printf("長方形面積=\t%11.2lf\n",dblArea);

        dblPerimeter=(dblLength+dblWidth)*2;
        printf("長方形週長=\t%11.2lf\n",dblPerimeter);
    #endif
    return 0;
}
