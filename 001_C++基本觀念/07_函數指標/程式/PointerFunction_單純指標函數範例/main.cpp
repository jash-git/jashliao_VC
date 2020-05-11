#include <cstdlib>
#include <iostream>
/*
單純指標函數範例 
*/
using namespace std;
double add(double a,double b)
{
       return (a+b);
}
double dec(double a,double b)
{
       return (a-b);
}
double fun( double a,double b,double (*f)(double ,double ))
{
       return f(a,b);
}
int main(int argc, char *argv[])
{
    double a,b,c;
    a=10.0;
    b=5.0;
    c=fun(a,b,add);
    cout<<a<<"+"<<b<<"="<<c<<"\n";
    c=fun(a,b,dec);
    cout<<a<<"-"<<b<<"="<<c<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
