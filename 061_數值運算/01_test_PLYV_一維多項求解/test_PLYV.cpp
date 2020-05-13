/*
一維多項求解
p(x)=2x^6-5x^5+3x^4+x^3-7x^2+7x-20
*/
  #include <stdio.h>
  double plyv(double a[],int n,double x)
  { int i;
    double u;
    u=a[n-1];
    for (i=n-2; i>=0; i--)
      u=u*x+a[i];
    return(u);
  }
  void main(void)
  { int i;
    static double a[7]={-20.0,7.0,-7.0,1.0,3.0,-5.0,2.0};
    static double x[6]={0.9,-0.9,1.1,-1.1,1.3,-1.3};
    printf("\n");
    for (i=0; i<=5; i++)
      printf("x(%d)=%5.2lf   p(%d)=%13.7e\n",
             i,x[i],i,plyv(a,7,x[i]));
    printf("\n");
  }
