/*
	二維多項式求值
	重點在於二維震裂變成一維陣列
*/
  #include <stdio.h>
  double bply(double *a,int m,int n,double x,double y)
  //int m,n;
  //double a[],x,y;
  { int i,j;
    double u,s,xx;
    u=0.0; xx=1.0;
    for (i=0; i<=m-1; i++)
      { s=a[i*n+n-1]*xx;
        for (j=n-2; j>=0; j--)
          s=s*y+a[i*n+j]*xx;
        u=u+s; xx=xx*x;
      }
    return(u);
  }
  void main(void)
  { double z;
	double *aa;
    static double a[4][5]={{1.0,2.0,3.0,4.0,5.0},
                         {6.0,7.0,8.0,9.0,10.0},
                     {11.0,12.0,13.0,14.0,15.0},
                    {16.0,17.0,18.0,19.0,20.0}};
    printf("\n");
	aa=(double*)a;
    z=bply(aa,4,5,0.6,-1.3);
    printf(" p(0.60,-1.30)=%13.7e\n",z);
    printf("\n");
  }