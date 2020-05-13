#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstdio>
/*
利用牛頓法求解非線性方程式 
*/
using namespace std; 
  int newt(double *x,double eps,int js,void (*f)(double, double*))
  //int js;
  //double *x,eps;
  //void (*f)();
  { int k,l;
    double y[2],d,p,x0,x1;
    l=js; k=1; x0=*x;
    (*f)(x0,y);
    d=eps+1.0;
    while ((d>=eps)&&(l!=0))
      { if (fabs(y[1])+1.0==1.0)
          { printf("err\n"); return(-1);}
        x1=x0-y[0]/y[1];
        (*f)(x1,y);
        d=fabs(x1-x0); p=fabs(y[0]);
        if (p>d) d=p;
        x0=x1; l=l-1;
      }
    *x=x1;
    k=js-l;
    return(k);
  }
  void newtf(double x,double *y)
  //double x,y[2];
  { y[0]=x*x*(x-1.0)-10.0;
    y[1]=3.0*x*x-2.0*x;
    return;
  }
int main(int argc, char *argv[])
{
    int js,k;
    double x,eps;
    void newtf(double,double []);
    eps=0.000001; js=60; x=140.0;
    k=newt(&x,eps,js,newtf);
    if (k>=0)
      printf("k=%d  x=%13.7e\n",k,x);
    printf("\n");
    system("PAUSE");
    return EXIT_SUCCESS;
}
