
  #include <math.h>
  #include <stdio.h>
/*
求解M*N矩陣A的QR分解
其中Q的結果放到q[4][4]變數中，至於R的結果放回a[4][3]的變數
*/
  int maqr(double *a,int m,int n,double *q)
  //int m,n;
  //double a[],q[];
  { int i,j,k,l,nn,p,jj;
    double u,alpha,w,t;
    if (m<n)
      { printf("fail\n"); return(0);}
    for (i=0; i<=m-1; i++)
    for (j=0; j<=m-1; j++)
      { l=i*m+j; q[l]=0.0;
        if (i==j) q[l]=1.0;
      }
    nn=n;
    if (m==n) nn=m-1;
    for (k=0; k<=nn-1; k++)
      { u=0.0; l=k*n+k;
        for (i=k; i<=m-1; i++)
          { w=fabs(a[i*n+k]);
            if (w>u) u=w;
          }
        alpha=0.0;
        for (i=k; i<=m-1; i++)
          { t=a[i*n+k]/u; alpha=alpha+t*t;}
        if (a[l]>0.0) u=-u;
        alpha=u*sqrt(alpha);
        if (fabs(alpha)+1.0==1.0)
          { printf("fail\n"); return(0);}
        u=sqrt(2.0*alpha*(alpha-a[l]));
        if ((u+1.0)!=1.0)
          { a[l]=(a[l]-alpha)/u;
            for (i=k+1; i<=m-1; i++)
              { p=i*n+k; a[p]=a[p]/u;}
            for (j=0; j<=m-1; j++)
              { t=0.0;
                for (jj=k; jj<=m-1; jj++)
                  t=t+a[jj*n+k]*q[jj*m+j];
                for (i=k; i<=m-1; i++)
                  { p=i*m+j; q[p]=q[p]-2.0*t*a[i*n+k];}
              }
            for (j=k+1; j<=n-1; j++)
              { t=0.0;
                for (jj=k; jj<=m-1; jj++)
                  t=t+a[jj*n+k]*a[jj*n+j];
                for (i=k; i<=m-1; i++)
                  { p=i*n+j; a[p]=a[p]-2.0*t*a[i*n+k];}
              }
            a[l]=alpha;
            for (i=k+1; i<=m-1; i++)
              a[i*n+k]=0.0;
          }
      }
    for (i=0; i<=m-2; i++)
    for (j=i+1; j<=m-1;j++)
      { p=i*m+j; l=j*m+i;
        t=q[p]; q[p]=q[l]; q[l]=t;
      }
    return(1);
  }

  main()
  { int i,j;
    static double q[4][4],a[4][3]={ {1.0,1.0,-1.0},
       {2.0,1.0,0.0},{1.0,-1.0,0.0},{-1.0,2.0,1.0}};
	double *pq,*pa;
	pq=(double *)q;
    pa=(double *)a;
    i=maqr(pa,4,3,pq);
    if (i!=0)
      { printf("MAT Q IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",q[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT R IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=2; j++)
              printf("%13.7e ",a[i][j]);
            printf("\n");
          }
        printf("\n");
      }
  }