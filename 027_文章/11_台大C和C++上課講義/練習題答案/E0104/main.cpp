#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 1
int main()
{
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout.setf(ios::fixed,ios::floatfield);  //�w�I��ܪk
        cout<<"�ռg�{���L�X  129263 + 54628  �����G=\t"<<setprecision(0)<<(129263 + 54628)<<endl;
        //cout.setf(ios::scientific,ios::floatfield);  //��ǰO����ܪk
        //cout<<"�ռg�{���L�X  129263  *  54628  �����G=\t"<<(129263.0*54628.0)<<endl;
    #else
        printf("C mode:\n");
        printf("�ռg�{���L�X  129263 + 54628  �����G=\t%11.0f\n",(129263 + 54628));
    #endif
    return 0;
}
