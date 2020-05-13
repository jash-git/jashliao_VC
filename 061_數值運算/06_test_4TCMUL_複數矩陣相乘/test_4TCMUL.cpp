  #include <stdio.h>
/*
  求解兩複數矩陣相乘C=A*B
  其中
	ar->A的實部
	ai->A的虛部
	br->B的實部
	bi->B的虛部
	cr->C的實部
	ci->C的虛部
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
  void main(void)
  {  int i,j;
	 double *par,*pai,*pbr,*pbi,*pcr,*pci;
     static double cr[3][4],ci[3][4];
     static double ar[3][4]={ {1.0,2.0,3.0,-2.0},
            {1.0,5.0,1.0,3.0},{0.0,4.0,2.0,-1.0}};
     static double ai[3][4]={ {1.0,-1.0,2.0,1.0},
            {-1.0,-1.0,2.0,0.0},{-3.0,-1.0,2.0,2.0}};
     static double br[4][4]={ {1.0,4.0,5.0,-2.0},
            {3.0,0.0,2.0,-1.0},{6.0,3.0,1.0,2.0},
            {2.0,-3.0,-2.0,1.0}};
     static double bi[4][4]={ {-1.0,-1.0,1.0,1.0},
            {2.0,1.0,0.0,5.0},{-3.0,2.0,1.0,-1.0},
            {-1.0,-2.0,1.0,-2.0}};
	 par=(double *)ar;
	 pai=(double *)ai;
	 pbr=(double *)br;
	 pbi=(double *)bi;
	 pcr=(double *)cr;
	 pci=(double *)ci;
     tcmul(par,pai,pbr,pbi,3,4,4,pcr,pci);
     for (i=0; i<=2; i++)
       { for (j=0; j<=3; j++)
           printf("%13.7e ",cr[i][j]);
         printf("\n");
       }
     printf("\n");
     for (i=0; i<=2; i++)
       { for (j=0; j<=3; j++)
           printf("%13.7e ",ci[i][j]);
         printf("\n");
       }
  }