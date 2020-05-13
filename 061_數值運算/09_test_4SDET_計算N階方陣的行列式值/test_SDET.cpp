  #include <stdio.h>
  #include <math.h>
/*
利用高斯消去法，計算N階方陣的行列式值
*/
  double sdet(double *a,int n)
  //int n;
  //double a[];
  { int i,j,k,is,js,l,u,v;
    double f,det,q,d;
    f=1.0; det=1.0;
    for (k=0; k<=n-2; k++)
      { q=0.0;
        for (i=k; i<=n-1; i++)
        for (j=k; j<=n-1; j++)
          { l=i*n+j; d=fabs(a[l]);
	    if (d>q) { q=d; is=i; js=j;}
          }
        if (q+1.0==1.0)
          { det=0.0; return(det);}
        if (is!=k)
          { f=-f;
            for (j=k; j<=n-1; j++)
              { u=k*n+j; v=is*n+j;
                d=a[u]; a[u]=a[v]; a[v]=d;
              }
          }
        if (js!=k)
          { f=-f;
            for (i=k; i<=n-1; i++)
              { u=i*n+js; v=i*n+k;
                d=a[u]; a[u]=a[v]; a[v]=d;
              }
          }
        l=k*n+k;
        det=det*a[l];
        for (i=k+1; i<=n-1; i++)
          { d=a[i*n+k]/a[l];
            for (j=k+1; j<=n-1; j++)
              { u=i*n+j;
                a[u]=a[u]-d*a[k*n+j];
              }
          }
      }
    det=f*det*a[n*n-1];
    return(det);
  }

    
  void main(void)
  { static double a[4][4]={ {1.0,2.0,3.0,4.0},
                            {5.0,6.0,7.0,8.0},
                            {9.0,10.0,11.0,12.0},
                            {13.0,14.0,15.0,16.0}};
    static double b[4][4]={ {3.0,-3.0,-2.0,4.0},
                            {5.0,-5.0,1.0,8.0},
                            {11.0,8.0,5.0,-7.0},
                            {5.0,-1.0,-3.0,-1.0}};
    double *pa,*pb;
	double det;
	pa=(double *)a;
    det=sdet(pa,4);
    printf("det(A)=%13.7e\n",det);
    printf("\n");
	pb=(double *)b;
    det=sdet(pb,4);
    printf("det(B)=%13.7e\n",det);
    printf("\n");
  }

