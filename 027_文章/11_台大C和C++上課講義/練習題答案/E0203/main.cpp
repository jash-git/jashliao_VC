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
    //��ĳ��J2.3�ݵ��G
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"���� = �^�� * 1.6:\n";
        cout<<"�п�J�^��: \t";
        cin>>dblMile;
        dblkm=dblMile*1.6;
        cout.setf(ios::fixed,ios::floatfield);  //�w�I��ܪk
        cout<<"����= "<<setprecision(1)<<dblkm<<endl;
        cout<<"����= "<<setprecision(2)<<dblkm<<endl;
    #else
        printf("C mode:\n");
        printf("���� = �^�� * 1.6:\n");
        printf("�п�J�^��: \t");
        scanf("%lf",&dblMile);
        dblkm=dblMile*1.6;
        printf("����= %20.1lf\n",dblkm);
        printf("����= %20.2lf\n",dblkm);
    #endif
    return 0;
}
