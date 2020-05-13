
  #include "math.h"
  #include "stdio.h"
/*
利用高斯演算法求解帶型線性聯立方程
*/
  int band(double *b,double *d,int n,int l,int il,int m)
  //int n,l,il,m;
  //double b[],d[];
  { int ls,k,i,j,is,u,v;
    double p,t;
    if (il!=(2*l+1))
      { printf("fail\n"); return(-2);}
    ls=l;
    for (k=0;k<=n-2;k++)
      { p=0.0;
        for (i=k;i<=ls;i++)
          { t=fabs(b[i*il]);
            if (t>p) {p=t; is=i;}
          }
        if (p+1.0==1.0)
          { printf("fail\n"); return(0);}
        for (j=0;j<=m-1;j++)
          { u=k*m+j; v=is*m+j;
            t=d[u]; d[u]=d[v]; d[v]=t;
          }
        for (j=0;j<=il-1;j++)
          { u=k*il+j; v=is*il+j;
            t=b[u]; b[u]=b[v]; b[v]=t;
          }
        for (j=0;j<=m-1;j++)
          { u=k*m+j; d[u]=d[u]/b[k*il];}
        for (j=1;j<=il-1;j++)
          { u=k*il+j; b[u]=b[u]/b[k*il];}
        for (i=k+1;i<=ls;i++)
          { t=b[i*il];
            for (j=0;j<=m-1;j++)
              { u=i*m+j; v=k*m+j;
                d[u]=d[u]-t*d[v];
              }
            for (j=1;j<=il-1;j++)
              { u=i*il+j; v=k*il+j;
                b[u-1]=b[u]-t*b[v];
              }
            u=i*il+il-1; b[u]=0.0;
          }
        if (ls!=(n-1)) ls=ls+1;
      }
    p=b[(n-1)*il];
    if (fabs(p)+1.0==1.0)
      { printf("fail\n"); return(0);}
    for (j=0;j<=m-1;j++)
      { u=(n-1)*m+j; d[u]=d[u]/p;}
    ls=1;
    for (i=n-2;i>=0;i--)
      { for (k=0;k<=m-1;k++)
          { u=i*m+k;
            for (j=1;j<=ls;j++)
              { v=i*il+j; is=(i+j)*m+k;
                d[u]=d[u]-b[v]*d[is];
              }
          }
        if (ls!=(il-1)) ls=ls+1;
      }
    return(2);
  }

  void main(void)
  { int i;
    static double b[8][5]={ {3.0,-4.0,1.0,0.0,0.0},
    {-2.0,-5.0,6.0,1.0,0.0},{1.0,3.0,-1.0,2.0,-3.0},
    {2.0,5.0,-5.0,6.0,-1.0},{-3.0,1.0,-1.0,2.0,-5.0},
    {6.0,1.0,-3.0,2.0,-9.0},{-4.0,1.0,-1.0,2.0,0.0},
    {5.0,1.0,-7.0,0.0,0.0}};
    static double d[8][3]={ {13.0,29.0,-13.0},
    {-6.0,17.0,-21.0},{-31.0,-6.0,4.0},{64.0,3.0,16.0},
    {-20.0,1.0,-5.0},{-22.0,-41.0,56.0},{-29.0,10.0,-21.0},
    {7.0,-24.0,20.0}};
	double *pb,*pd;
	pd=(double *)d;
	pb=(double *)b;
    if (band(pb,pd,8,2,5,3)>0)
      for (i=0;i<=7;i++)
      printf("x(%d)=%13.7e,  %13.7e,  %13.7e\n",
            i,d[i][0],d[i][1],d[i][2]);
  }