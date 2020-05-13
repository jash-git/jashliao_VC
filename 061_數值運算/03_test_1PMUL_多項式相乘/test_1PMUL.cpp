  #include <stdio.h>
  void pmul(double *p,int m,double *q,int n,double *s,int k)
  //int m,n,k;
  //double p[],q[],s[];
  { int i,j;
    for (i=0; i<=k-1; i++)
		s[i]=0.0;
    for (i=0; i<=m-1; i++)
		for (j=0; j<=n-1; j++)
			s[i+j]=s[i+j]+p[i]*q[j];
    return;
  }

  void main(void)
  { int i;
    static double p[6]={4.0,-6.0,5.0,2.0,-1.0,3.0};
    static double q[4]={2.0,3.0,-6.0,2.0};
    double s[9];
    pmul(p,6,q,4,s,9);
    printf("\n");
    for (i=0; i<=8; i++)
      printf(" s(%d)=%13.7e\n",i,s[i]);
    printf("\n");
  }