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

        cout<<"����έp��\n"<<"�п�J����Ϊ�����\t";
        cin >>dblLength;

        cout<<"�п�J����Ϊ��e��\t";
        cin >>dblWidth;

        cout.setf(ios::fixed,ios::floatfield);  //�w�I��ܪk

        dblArea=dblLength*dblWidth;
        cout<<"����έ��n=\t"<<setprecision(2)<<dblArea<<endl;

        dblPerimeter=(dblLength+dblWidth)*2;
        cout<<"����ζg��=\t"<<setprecision(2)<<dblPerimeter<<endl;
    #else
        printf("C mode:\n");

        printf("����έp��\n�п�J����Ϊ�����\t");
        scanf("%lf",&dblLength);

        printf("�п�J����Ϊ��e��\t");
        scanf("%lf",&dblWidth);

        dblArea=dblLength*dblWidth;
        printf("����έ��n=\t%11.2lf\n",dblArea);

        dblPerimeter=(dblLength+dblWidth)*2;
        printf("����ζg��=\t%11.2lf\n",dblPerimeter);
    #endif
    return 0;
}
