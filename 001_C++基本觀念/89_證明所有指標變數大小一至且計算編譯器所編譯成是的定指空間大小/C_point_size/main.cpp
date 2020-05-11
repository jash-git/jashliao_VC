#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    char *chr_pA;
    int *int_pB;
    double *dbl_pC;
    int intD=0;
    intD=sizeof(chr_pA);
    cout << "char point size=" << intD << endl;
    intD=sizeof(int_pB);
    cout << "int point size=" << intD << endl;
    intD=sizeof(dbl_pC);
    cout << "double point size=" << intD <<endl;
    cout << "The C++ compiler is " << (8*intD) << " Bits"<<endl;
    cout << "The APP can use max of main memory size that is " <<pow((float)2,(float)(8*intD)) << " Bytes"  <<endl;
    return 0;
}
