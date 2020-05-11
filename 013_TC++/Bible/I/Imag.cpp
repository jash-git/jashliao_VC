
/*                        */
/* Program Name: imag.cpp */
/*                        */
#include <iostream.h>
#include <complex.h>

int main(void)
{
 double x = 3.1, y = 4.2;
 complex z = complex(x,y);
 cout << "z = " << z << "\n";
 cout << "  has real part = " << real(z) << "\n";
 cout << "  and imaginary real part = " << imag(z) << "\n";
 cout << "z has complex conjugate = " << conj(z) << "\n";
 return 0;
}
