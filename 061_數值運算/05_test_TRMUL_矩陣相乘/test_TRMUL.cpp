  /*
  ¨DM*N¶¥¯x°}A»PN*K¶¥¯x°}B­¼¿n¯x°}C
  */
  #include <stdio.h>
  void trmul(double *a,double *b,int m,int n,int k,double *c)
  //int m,n,k;
  //double a[],b[],c[];
  { 
	int i,j,l,u;
    for (i=0; i<=m-1; i++)
    for (j=0; j<=k-1; j++)
      { u=i*k+j; c[u]=0.0;
        for (l=0; l<=n-1; l++)
          c[u]=c[u]+a[i*n+l]*b[l*k+j];
      }
    return;
  }
  main()
  { int i,j;
    static double a[4][5]={ {1.0,3.0,-2.0,0.0,4.0},
                            {-2.0,-1.0,5.0,-7.0,2.0},
                            {0.0,8.0,4.0,1.0,-5.0},
                            {3.0,-3.0,2.0,-4.0,1.0}};
    static double c[4][3],b[5][3]={ {4.0,5.0,-1.0},
                      {2.0,-2.0,6.0},{7.0,8.0,1.0},
                      {0.0,3.0,-5.0},{9.0,8.0,-6.0}};
	double *ptra,*ptrb,*ptrc;
	ptra=(double *)a;
	ptrb=(double *)b;
	ptrc=(double *)c;
    trmul(ptra,ptrb,4,5,3,ptrc);
    for (i=0; i<=3; i++)
      { for (j=0; j<=2; j++)
          printf("%13.7e  ",c[i][j]);
        printf("\n");
      }
    printf("\n");
  }