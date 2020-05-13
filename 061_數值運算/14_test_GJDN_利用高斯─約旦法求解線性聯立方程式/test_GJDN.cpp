
  #include <stdlib.h>
  #include <math.h>
  #include <stdio.h>
/*
利用高斯─約旦法求解線性聯立方程式
	┌2X+2Y=8
	│
┌	└3X-2Y=-3
│
└	┌2X+2Y=8
	│
	└3X-2Y=7
*/
  int gjdn(double *a,double *b,int n,int m)
  //int n,m;
  //double a[],b[];
  { int *js,l,k,i,j,is,p,q;
    double d,t;
    js=(int *)malloc(n*sizeof(int));
    l=1;
    for (k=0;k<=n-1;k++)
      { d=0.0;
        for (i=k;i<=n-1;i++)
          for (j=k;j<=n-1;j++)
            { t=fabs(a[i*n+j]);
              if (t>d) { d=t; js[k]=j; is=i;}
            }
        if (d+1.0==1.0) l=0;
        else
          { if (js[k]!=k)
              for (i=0;i<=n-1;i++)
                { p=i*n+k; q=i*n+js[k];
                  t=a[p]; a[p]=a[q]; a[q]=t;
                }
            if (is!=k)
              { for (j=k;j<=n-1;j++)
                  { p=k*n+j; q=is*n+j;
                    t=a[p]; a[p]=a[q]; a[q]=t;
                  }
                for (j=0;j<=m-1;j++)
                  { p=k*m+j; q=is*m+j;
                    t=b[p]; b[p]=b[q]; b[q]=t;
                  }
              }
          }
        if (l==0)
          { free(js); printf("fail\n");
            return(0);
          }
        d=a[k*n+k];
        for (j=k+1;j<=n-1;j++)
          { p=k*n+j; a[p]=a[p]/d;}
        for (j=0;j<=m-1;j++)
          { p=k*m+j; b[p]=b[p]/d;}
        for (j=k+1;j<=n-1;j++)
          for (i=0;i<=n-1;i++)
            { p=i*n+j;
              if (i!=k)
                a[p]=a[p]-a[i*n+k]*a[k*n+j];
            }
        for (j=0;j<=m-1;j++)
        for (i=0;i<=n-1;i++)
          { p=i*m+j;
            if (i!=k)
              b[p]=b[p]-a[i*n+k]*b[k*m+j];
          }
      }
    for (k=n-1;k>=0;k--)
      if (js[k]!=k)
        for (j=0;j<=m-1;j++)
          { p=k*m+j; q=js[k]*m+j;
            t=b[p]; b[p]=b[q]; b[q]=t;
          }
    free(js);
    return(1);
  }
  main()
  { int i;
  /*
    static double a[4][4]={ {1.0,3.0,2.0,13.0},
                            {7.0,2.0,1.0,-2.0},
                            {9.0,15.0,3.0,-2.0},
                            {-2.0,-2.0,11.0,5.0}};
    static double b[4][2]={ {9.0,0.0},{6.0,4.0},
                            {11.0,7.0},{-2.0,-1.0}};
    */
    static double a[2][2]={
		{2,2},
		{3,-2}
		   };
	static double b[2][2]={
		{8,8},
		{-3,7}
			};
	double *pa,*pb;
	pa=(double *)a;
	pb=(double *)b;
	/*
	if (gjdn(pa,pb,4,2)!=0)
      for (i=0;i<=3;i++)
        printf("x(%d)=%13.7e,  %13.7e\n",i,b[i][0],b[i][1]);
	*/
	if (gjdn(pa,pb,2,2)!=0)
      for (i=0;i<=1;i++)
        printf("x(%d)=%13.7e,  %13.7e\n",i,b[i][0],b[i][1]);
  }

