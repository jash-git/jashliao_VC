#include <iostream>
using namespace std;
class CCC
{
public:
   //CCC(){};
   CCC();	
   CCC(int);
   CCC(int, double);
   int ii;
   double dd;
};
CCC::CCC()
{
	ii=0;
}
CCC::CCC(int _ii)
    : ii(_ii)
{
}

CCC::CCC(int _ii, double _dd)
    : ii(_ii), dd(_dd)
{
}
   
void main()
{
   CCC *cc1 = new CCC(4, 5.5);   // Pointer. Contructor called.
   //CCC *cc2 = new CCC[5];        // Pointer to an array of objects.
   CCC &cc3 = *new CCC;          // Reference
   CCC *cc2;
   cc2= new CCC[5];
   cc1->ii=5;
   cc2[3].ii=6;
   cc3.ii=7;

   cout << cc1->ii   << endl;
   cout << cc2[3].ii << endl;
   cout << cc3.ii    << endl;

   delete cc1;
   delete [] cc2;
   delete & cc3;
}

