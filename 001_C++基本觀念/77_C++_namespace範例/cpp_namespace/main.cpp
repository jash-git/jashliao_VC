#include <iostream>
#include "cppnamespace.h"
//using namespace N_A;
//using namespace N_A::N_B;
//using namespace N_A::N_B::N_C;

using namespace std;

int main()
{
    N_A::A objA;//A objA;
    N_A::N_B::B objB;//B objB;
    N_A::N_B::N_C::C objC;//C objC;
    cout<<"objA.a="<<objA.a<< endl;
    cout<<"objB.b="<<objB.b<< endl;
    cout<<"objC.c="<<objC.c<< endl;
    objA.a=10;
    objB.b=20;
    objC.c=30;
    cout<<"objA.a="<<objA.a<< endl;
    cout<<"objB.b="<<objB.b<< endl;
    cout<<"objC.c="<<objC.c<< endl;
    cout << "Hello world!" << endl;
    return 0;
}
