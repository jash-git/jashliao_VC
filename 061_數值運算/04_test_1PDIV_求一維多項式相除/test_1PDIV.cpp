/*
求一維多項式相除
p[]被除數
q[]除數
s[]商
r[]餘數
*/
  #include <stdio.h>
  void pdiv(double *p,int m,double *q,int n,double *s,int k,double *r,int l)
  //int m,n,k,l;
  //double p[],q[],s[],r[];
  { int i,j,mm,ll;
    for (i=0; i<=k-1; i++) s[i]=0.0;
    if (q[n-1]+1.0==1.0) return;
    ll=m-1;
    for (i=k; i>=1; i--)
      { s[i-1]=p[ll]/q[n-1];
        mm=ll;
        for (j=1; j<=n-1; j++)
          { p[mm-1]=p[mm-1]-s[i-1]*q[n-j-1];
            mm=mm-1;
          }
        ll=ll-1;
      }
    for (i=0; i<=l-1; i++) r[i]=p[i];
    return;
  }
  void main(void)
  { int i;
    static double p[5]={8.0,-5.0,-3.0,6.0,3.0};
    static double q[3]={1.0,-1.0,2.0};
    double s[3],r[2];
    pdiv(p,5,q,3,s,3,r,2);
    printf("\n");
    for (i=0; i<=2; i++)
      printf(" s(%d)=%13.7e\n",i,s[i]);
    printf("\n");
    for (i=0; i<=1; i++)
      printf(" r(%d)=%13.7e\n",i,r[i]);
    printf("\n");
  }