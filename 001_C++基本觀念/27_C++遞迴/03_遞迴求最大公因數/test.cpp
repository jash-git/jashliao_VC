/*
遞迴求最大公因數
*/
#include <stdio.h>
#include <stdlib.h>
int gcd(int a, int b);
int main(int argc, char *argv[])
{
  int x, y, gcdanswer;
  printf("Please enter 2 numbers.\n");
  scanf("%d%d", &x, &y);
  gcdanswer =  gcd(x, y);
  printf("The GCD is %d.\n", gcdanswer);
  system("PAUSE");
  return 0;
}
int gcd(int a, int b)
{
  int c;
  c = a % b;  
  if( c != 0 )
          return gcd(b, c);   
  else
          return b;
}