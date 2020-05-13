  #include <stdio.h>
  #include <stdlib.h>
/*
複數矩陣求逆(反)矩陣
並透過C=B*A=I來驗證
*/
  void tcmul(double *ar,double *ai,double *br,double *bi,int m,int n,int k,double *cr,double *ci)
  //int m,n,k;
  //double ar[],ai[],br[],bi[],cr[],ci[];
  { int i,j,l,u,v,w;
    double p,q,s;
    for (i=0; i<=m-1; i++)
    for (j=0; j<=k-1; j++)
      { u=i*k+j;
        cr[u]=0.0; ci[u]=0.0;
        for (l=0; l<=n-1; l++)
          { v=i*n+l; w=l*k+j;
            p=ar[v]*br[w];
            q=ai[v]*bi[w];
            s=(ar[v]+ai[v])*(br[w]+bi[w]);
            cr[u]=cr[u]+p-q;
            ci[u]=ci[u]+s-p-q;
          }
      }
  } 
  int cinv(double *ar,double *ai,int n)
  //int n;
  //double ar[],ai[];
  { int *is,*js,i,j,k,l,u,v,w;
    double p,q,s,t,d,b;
    is=(int *)malloc(n*sizeof(int));
    js=(int *)malloc(n*sizeof(int));
    for (k=0; k<=n-1; k++)
      { d=0.0;
        for (i=k; i<=n-1; i++)
        for (j=k; j<=n-1; j++)
          { u=i*n+j;
            p=ar[u]*ar[u]+ai[u]*ai[u];
            if (p>d) { d=p; is[k]=i; js[k]=j;}
          }
        if (d+1.0==1.0)
          { free(is); free(js); printf("err**not inv\n");
            return(0);
          }
        if (is[k]!=k)
          for (j=0; j<=n-1; j++)
            { u=k*n+j; v=is[k]*n+j;
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
        if (js[k]!=k)
          for (i=0; i<=n-1; i++)
            { u=i*n+k; v=i*n+js[k];
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
        l=k*n+k;
        ar[l]=ar[l]/d; ai[l]=-ai[l]/d;
        for (j=0; j<=n-1; j++)
          if (j!=k)
            { u=k*n+j;
              p=ar[u]*ar[l]; q=ai[u]*ai[l];
              s=(ar[u]+ai[u])*(ar[l]+ai[l]);
              ar[u]=p-q; ai[u]=s-p-q;
            }
        for (i=0; i<=n-1; i++)
          if (i!=k)
            { v=i*n+k;
              for (j=0; j<=n-1; j++)
                if (j!=k)
                  { u=k*n+j;  w=i*n+j;
                    p=ar[u]*ar[v]; q=ai[u]*ai[v];
                    s=(ar[u]+ai[u])*(ar[v]+ai[v]);
                    t=p-q; b=s-p-q;
                    ar[w]=ar[w]-t;
                    ai[w]=ai[w]-b;
                  }
            }
        for (i=0; i<=n-1; i++)
          if (i!=k)
            { u=i*n+k;
              p=ar[u]*ar[l]; q=ai[u]*ai[l];
              s=(ar[u]+ai[u])*(ar[l]+ai[l]);
              ar[u]=q-p; ai[u]=p+q-s;
            }
      }
    for (k=n-1; k>=0; k--)
      { if (js[k]!=k)
          for (j=0; j<=n-1; j++)
            { u=k*n+j; v=js[k]*n+j;
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
        if (is[k]!=k)
          for (i=0; i<=n-1; i++)
            { u=i*n+k; v=i*n+is[k];
              t=ar[u]; ar[u]=ar[v]; ar[v]=t;
              t=ai[u]; ai[u]=ai[v]; ai[v]=t;
            }
      }
    free(is); free(js);
    return(1);
  }
  void main(void)
  { int i,j;
	double *par,*pai,*pbr,*pbi,*pcr,*pci;
    static double br[4][4],bi[4][4],cr[4][4],ci[4][4];
    static double ar[4][4]={ {0.2368,0.2471,0.2568,1.2671},
                             {1.1161,0.1254,0.1397,0.1490},
                             {0.1582,1.1675,0.1768,0.1871},
                             {0.1968,0.2071,1.2168,0.2271}};
    static double ai[4][4]={ {0.1345,0.1678,0.1875,1.1161},
                             {1.2671,0.2017,0.7024,0.2721},
                             {-0.2836,-1.1967,0.3558,-0.2078},
                             {0.3576,-1.2345,2.1185,0.4773}};
	par=(double *)ar;
	pai=(double *)ai;
	pbr=(double *)br;
	pbi=(double *)bi;
	pcr=(double *)cr;
	pci=(double *)ci;
    for (i=0; i<=3; i++)
    for (j=0; j<=3; j++)
      { br[i][j]=ar[i][j]; bi[i][j]=ai[i][j];}
    i=cinv(par,pai,4);
    if (i!=0)
      { printf("MAT AR IS:\n");
	for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",br[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT AI IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",bi[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT AR- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",ar[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT AI- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",ai[i][j]);
            printf("\n");
          }
        tcmul(pbr,pbi,par,pai,4,4,4,pcr,pci);
        printf("\n");
        printf("MAT CR=AA- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",cr[i][j]);
            printf("\n");
          }
        printf("\n");
        printf("MAT CI=AA- IS:\n");
        for (i=0; i<=3; i++)
          { for (j=0; j<=3; j++)
              printf("%13.7e ",ci[i][j]);
            printf("\n");
          }
      }
  }

