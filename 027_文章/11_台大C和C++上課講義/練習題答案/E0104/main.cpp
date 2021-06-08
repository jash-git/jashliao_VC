#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1
int main()
{
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout.setf(ios::fixed,ios::floatfield);  //定點表示法
        cout<<"試寫程式印出  129263 + 54628  的結果=\t"<<setprecision(0)<<(129263 + 54628)<<endl;
        //cout.setf(ios::scientific,ios::floatfield);  //科學記號表示法
        //cout<<"試寫程式印出  129263  *  54628  的結果=\t"<<(129263.0*54628.0)<<endl;
    #else
        printf("C mode:\n");
        printf("試寫程式印出  129263 + 54628  的結果=\t%11.0f\n",(129263 + 54628));
    #endif
    return 0;
}
