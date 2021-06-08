#include <iostream>
#include <cstdio>
#include <iomanip>// using setprecision function
using namespace std;
# define CPP_mode 0

int main()
{
    unsigned long lngvalue00;
    unsigned long Quotient,Remainder;
    unsigned long long Divisor;
    int i,j;
    i=0;
    j=0;
    #if (CPP_mode)
        cout<<"CPP mode:\n";
        cout<<"請輸入要運算的整數=\t";
        cin >>lngvalue00;
        Divisor=1;
        do
        {
            Divisor*=10;
            Quotient=lngvalue00/Divisor;
            j++;
        }while(Quotient>0);
        cout<<"您輸入的數字位數=\t"<<j<<endl;
        Divisor/=10;
        for(i=0;i<j;i++)
        {
            Quotient=lngvalue00/Divisor;
            cout<<Quotient<<endl;
            Remainder=lngvalue00%Divisor;
            lngvalue00=Remainder;
            Divisor/=10;
        }
    #else
        printf("C mode:\n");

        printf("請輸入要運算的整數=\t");
        scanf("%ld",&lngvalue00);
        Divisor=1;
        do
        {
            Divisor*=10;
            Quotient=lngvalue00/Divisor;
            j++;
        }while(Quotient>0);
        printf("您輸入的數字位數=\t%d\n",j);
        Divisor/=10;
        for(i=0;i<j;i++)
        {
            Quotient=lngvalue00/Divisor;
            printf("%ld\n",Quotient);
            Remainder=lngvalue00%Divisor;
            lngvalue00=Remainder;
            Divisor/=10;
        }

    #endif
    return 0;
}
