#include <iostream>
using namespace std;
//C粂ēぃ肂糤跑计盢2跑计が传!
void main()
{	
    float a=9.004, b=-28.5;
	//国猭... for int or float
    _asm {
     push a
     push b
     pop a
     pop b}
    cout<< a <<"  "<<b<<"\n";
} 