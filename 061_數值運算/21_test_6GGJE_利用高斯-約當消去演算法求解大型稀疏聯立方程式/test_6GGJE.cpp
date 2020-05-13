
  #include <stdlib.h>
  #include <math.h>
  #include <stdio.h>
/*
利用高斯-約當消去演算法求解大型稀疏聯立方程式
*/
  int ggje(double *a,int n,double *b)
  //int n;
  //double a[],b[];
  { int *js,i,j,k,is,u,v;
    double d,t;
    js=(int *)malloc(n*sizeof(int));
    for (k=0; k<=n-1; k++)
      { d=0.0;
        for (i=k; i<=n-1; i++)
        for (j=k; j<=n-1; j++)
          { t=fabs(a[i*n+j]);
            if (t>d) {d=t; js[k]=j; is=i;}
          }
        if (d+1.0==1.0)
          { free(js); printf("fail\n"); return(0);}
        if (is!=k)
          { for (j=k; j<=n-1; j++)
              { u=k*n+j; v=is*n+j;
                t=a[u]; a[u]=a[v]; a[v]=t;
              }
            t=b[k]; b[k]=b[is]; b[is]=t;
          }
        if (js[k]!=k)
          for (i=0; i<=n-1; i++)
            { u=i*n+k; v=i*n+js[k];
              t=a[u]; a[u]=a[v]; a[v]=t;
            }
        t=a[k*n+k];
        for (j=k+1; j<=n-1; j++)
          { u=k*n+j;
            if (a[u]!=0.0) a[u]=a[u]/t;
          }
        b[k]=b[k]/t;
        for (j=k+1; j<=n-1; j++)
          { u=k*n+j;
            if (a[u]!=0.0)
              { for (i=0; i<=n-1; i++)
                  { v=i*n+k;
                    if ((i!=k)&&(a[v]!=0.0))
                      { is=i*n+j;
                        a[is]=a[is]-a[v]*a[u];
                      }
                  }
              }
          }
        for (i=0; i<=n-1; i++)
          { u=i*n+k;
            if ((i!=k)&&(a[u]!=0.0))
              b[i]=b[i]-a[u]*b[k];
          }
      }
    for (k=n-1; k>=0; k--)
      if (k!=js[k])
        { t=b[k]; b[k]=b[js[k]]; b[js[k]]=t;}
    free(js);
    return(1);
  }

 void main()
  { int i;
    static double a[8][8]={ {0.0,0.0,-1.0,0.0,0.0,0.0,2.0,0.0},
                         {0.0,6.0,0.0,0.0,0.0,-6.0,0.0,0.0},
                         {0.0,0.0,0.0,2.0,0.0,0.0,0.0,-4.0},
                         {3.0,0.0,0.0,0.0,-2.0,0.0,1.0,0.0},
                         {0.0,0.0,6.0,0.0,0.0,0.0,5.0,0.0},
                         {1.0,0.0,0.0,0.0,-3.0,0.0,0.0,2.0},
                         {0.0,4.0,0.0,-1.0,0.0,0.0,0.0,0.0},
                         {0.0,0.0,1.0,0.0,-1.0,0.0,0.0,-2.0}};
    static double b[8]={4.0,6.0,-8.0,-2.0,27.0,-9.0,2.0,-4.0};
	double *pa;
	pa=(double *)a;
    if (ggje(pa,8,b)!=0)
      for (i=0; i<=7; i++)
        printf("x(%d)=%13.7e\n",i,b[i]);
  }