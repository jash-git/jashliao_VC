/////////////////////////////////////////////////////////////////////////
//ar.c
//Last update: 2001.10.3

#include "ar.h"
#include "malloc.h"
#include "math.h"

//////////////////////////////////////////////////////////////////////////
// �Իع����
// ������inputseries ���� ��������
//       length ���� �������г���
//       degree ���� �ع�ģ�͵Ľ���
//       coefficients ���� ���õķ�����
int AutoRegression(
   double   *inputseries,
   int      length,
   int      degree,
   double   *coefficients,
   int      method)
{
	double mean;
	int i, t;            
	double *w=NULL;      /* Input series - mean                            */
	double *ss=NULL;      /* Unused here, relates to sum of squares         */
	double *h=NULL; 
	double *g=NULL;      /* Used by mempar()                              */
	double *per=NULL; 
	double *pef=NULL;      /* Used by mempar()                              */
	double **ar=NULL;      /* AR coefficients, all degrees                  */
	int success = TRUE;

	/* Allocate space for working variables */
	if ((w = (double *)malloc(length*sizeof(double))) == NULL) 
	{
		success = FALSE;
		goto skip;
	}

	if ((h = (double *)malloc((degree+1)*sizeof(double))) == NULL) 
	{
		success = FALSE;
		goto skip;
	}

	if ((g = (double *)malloc((degree+2)*sizeof(double))) == NULL) 
	{
		success = FALSE;
		goto skip;
	}
   
	if ((per = (double *)malloc((length+1)*sizeof(double))) == NULL) 
	{
		success = FALSE;
		goto skip;
	}
   
	if ((pef = (double *)malloc((length+1)*sizeof(double))) == NULL) 
	{
		success = FALSE;
		goto skip;
	}

	if ((ar = (double **)malloc((degree+1)*sizeof(double*))) == NULL) 
	{
		success = FALSE;
		goto skip;
	}
   
	for (i=0;i<degree+1;i++)
		ar[i] = NULL;
	for (i=0;i<degree+1;i++) 
	{
		if ((ar[i] = (double *)malloc((degree+1)*sizeof(double))) == NULL) 
		{
			success = FALSE;
			goto skip;
		}
	}

	/* Determine and subtract the mean from the input series */
	mean = 0.0;
	for (t=0;t<length;t++) 
		mean += inputseries[t];
	mean /= (double)length;
	for (t=0;t<length;t++)
		w[t] = inputseries[t] - mean;

	/* Perform the appropriate AR calculation */
	if (method == MAXENTROPY) 
	{
		success = ARMaxEntropy(w,length,degree,ar,per,pef,h,g);
		for (i=1;i<=degree;i++)
			coefficients[i-1] = -ar[degree][i];

	} 
	else if (method == LEASTSQUARES) 
	{
		success = ARLeastSquare(w,length,degree,coefficients);

	} 
	else 
	{
		success = FALSE;
	}

	skip:
	if (w != NULL)
		free(w);
	if (h != NULL)
		free(h);
	if (g != NULL)
		free(g);
	if (per != NULL)
		free(per);
	if (pef != NULL)
		free(pef);
	if (ar != NULL) 
	{
		for (i=0;i<degree+1;i++)
			if (ar[i] != NULL)
				free(ar[i]);
		free(ar);
	}
      
	return(success);
}

/////////////////////////////////////////////////////////////////////////
//������ARMaxEntropy
//Ӧ��Max Entropy׼�����
//ǰ�ĸ���������һ������һ�������ĸ�����ʱ����
int ARMaxEntropy(
   double *inputseries,int length,int degree,double **ar,
   double *per,double *pef,double *h,double *g)
{
	int i,j,n,nn,jj;
	double sum=0,sn,sd;
	double t1,t2;

	for (j=1;j<=length;j++) 
	{
		pef[j] = 0;
		per[j] = 0;
	}
      
	for (nn=2;nn<=degree+1;nn++) 
	{
		n  = nn - 2;
		sn = 0.0;
		sd = 0.0;
		jj = length - n - 1;
		
		for (j=1;j<=jj;j++) 
		{
			t1 = inputseries[j+n] + pef[j];
			t2 = inputseries[j-1] + per[j];
			sn -= 2.0 * t1 * t2;
			sd += (t1 * t1) + (t2 * t2);
		}
      
		g[nn] = sn / sd;
		t1 = g[nn];
      
		if (n != 0) 
		{
			for (j=2;j<nn;j++) 
				h[j] = g[j] + (t1 * g[n - j + 3]);
			for (j=2;j<nn;j++)
				g[j] = h[j];
			jj--;
		}
		for (j=1;j<=jj;j++) 
		{
			per[j] += (t1 * pef[j]) + (t1 * inputseries[j+nn-2]);
			pef[j]  = pef[j+1] + (t1 * per[j+1]) + (t1 * inputseries[j]);
		}

		for (j=2;j<=nn;j++)
			ar[nn-1][j-1] = g[j];
	}
   
	return(TRUE);
}

/*
   Least squares method
*/
int ARLeastSquare(
   double   *inputseries,
   int      length,
   int      degree,
   double   *coefficients)
{
	int i,j,k,hj,hi;
	int success = TRUE;
	double **mat;

	mat = (double **)malloc(sizeof(double *)*degree);
	for (i=0;i<degree;i++)
		mat[i] = (double*)malloc(sizeof(double)*degree);

	for (i=0;i<degree;i++) 
	{
		coefficients[i] = 0.0;
		for (j=0;j<degree;j++)
		mat[i][j] = 0.0;
	}
   
	for (i=degree-1;i<length-1;i++) 
	{
		hi = i + 1;
		for (j=0;j<degree;j++) 
		{
			hj = i - j;
			coefficients[j] += (inputseries[hi] * inputseries[hj]);
			for (k=j;k<degree;k++)
				mat[j][k] += (inputseries[hj] * inputseries[i-k]);
		}
	}
   
	for (i=0;i<degree;i++) 
	{
		coefficients[i] /= (length - degree);
		for (j=i;j<degree;j++) 
		{
			mat[i][j] /= (length - degree);
			mat[j][i] = mat[i][j];
		}
	}

	/* Solve the linear equations */
	success = SolveLE(mat,coefficients,degree);
     
	skip:
	for (i=0;i<degree;i++)
		if (mat[i] != NULL)
			free(mat[i]);
   
	if (mat != NULL)
	free(mat);
	return(success);
}

/*
   Gaussian elimination solver
*/
int SolveLE(double **mat,double *vec,unsigned int n)
{
	int i,j,k,maxi;
	double vswap,*mswap,*hvec,max,h,pivot,q;
  
	for (i=0;i<n-1;i++) 
	{
		max = fabs(mat[i][i]);
		maxi = i;
		
		for (j=i+1;j<n;j++) 
		{
			if ((h = fabs(mat[j][i])) > max) 
			{
				max = h;
				maxi = j;
			}
		}
		
		if (maxi != i) 
		{
			mswap     = mat[i];
			mat[i]    = mat[maxi];
			mat[maxi] = mswap;
			vswap     = vec[i];
			vec[i]    = vec[maxi];
			vec[maxi] = vswap;
		}
    
		hvec = mat[i];
		pivot = hvec[i];
		if (fabs(pivot) == 0.0) 
		{
			return(FALSE);
		}
      
		for (j=i+1;j<n;j++) 
		{
			q = - mat[j][i] / pivot;
			mat[j][i] = 0.0;
			for (k=i+1;k<n;k++)
				mat[j][k] += q * hvec[k];
			vec[j] += (q * vec[i]);
		}
	}
   
	vec[n-1] /= mat[n-1][n-1];
	for (i=n-2;i>=0;i--) 
	{
		hvec = mat[i];
		for (j=n-1;j>i;j--)
			vec[i] -= (hvec[j] * vec[j]);
		vec[i] /= hvec[i];
	}
   
	return(TRUE);
}



