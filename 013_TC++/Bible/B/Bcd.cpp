
/*                       */
/* Program Name: bcd.cpp */
/*                       */
#include <iostream.h>
#include <bcd.h>

double x = 10000.0;         // ten thousand dollars
bcd a = bcd(x/3,2);         // a third, rounded to nearest penny

int main(void)
{
   cout << "share of fortune = $" << a << "\n";
   return 0;
}
