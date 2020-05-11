
/*                       */
/* Program Name: arg.cpp */
/*                       */
#include <iostream.h>
#include <complex.h>

int main(void)
{
   double x = 3.1, y = 4.2;
   complex z = complex(x,y);
   cout << "z = " << z << "\n";
   cout << "  has real part = " << real(z) << "\n";
   cout << "  and imaginary part = " << imag(z) << "\n";
   cout << "z has complex conjugate = " << conj(z) << "\n";
   double mag = sqrt(norm(z));
   double ang = arg(z);
   cout << "The polar form of z is:\n";
   cout << "   magnitude = " << mag << "\n";
   cout << "   angle (in radians) = " << ang << "\n";
   cout << "Reconstructing z from its polar form gives:\n";
   cout << "   z = " << polar(mag,ang) << "\n";
   return 0;
}
