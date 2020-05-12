#include<stdlib.h>
#include <math.h>

void PFree(void *adr)
{
	if(adr==NULL) return;
	free(adr);
}

double lu(int n,double *a,int *ip)
{
	int i,j,k,ii,ik;
	double t,u,det;
	double *weight;

	weight=malloc(sizeof(double)*n);
	det=0;
	for(k=0;k<n;k++) {
		ip[k]=k;
		u=0;
		for(j=0;j<n;j++) {
			t=fabs(a[k*n+j]);
			if(t>u) u=t;
		}
		if(u==0) goto EXIT;
		weight[k]=1/u;
	}
	det=1;
	for(k=0;k<n;k++) {
		u=-1;
		for(i=k;i<n;i++) {
			ii=ip[i];
			t=fabs(a[ii*n+k])*weight[ii];
			if(t>u) {
				u=t;	j=i;
			}
		}
		ik=ip[j];
		if(j!=k) {
			ip[j]=ip[k];
			ip[k]=ik;
			det= -det;
		}
		u=a[ik*n+k];
		det*=u;
		if(u==0) goto EXIT;
		for(i=k+1;i<n;i++) {
			ii=ip[i];
			t=(a[ii*n+k]/=u);
			for(j=k+1;j<n;j++) {
				a[ii*n+j]-= t*a[ik*n+j];
			}
		}
	}
EXIT:
	PFree(weight);
	return det;
}

void solve(int n,double *a,double *b,int *ip,double *x)
{
	int i,j,ii;
	double t;

	for(i=0;i<n;i++) {
		ii=ip[i];	t=b[ii];
		for(j=0;j<i;j++) {
			t -= a[ii*n+j]*x[j];
		}
		x[i]=t;
	}
	for(i=n-1;i>=0;i--) {
		t=x[i];	ii=ip[i];
		for(j=i+1;j<n;j++) {
			t -= a[ii*n+j]*x[j];
		}
		x[i]=t/a[ii*n+i];
	}
}

int solveSystemOfLinearEquations(int n,double *mat,double *vec,double *ans)
{
	double det;
	double *mat2;
	int *ip;
	int i,j,nn;
	char bbb[256],sbuf[256];

	ip=malloc(sizeof(int)*n);
	if(ip==NULL) return -1;
	nn=n*n;
	mat2=malloc(sizeof(double)*nn);
	if(mat2==NULL) {
		PFree(ip);
		return -1;
	}
	for(i=0;i<nn;i++) mat2[i]=mat[i];
	det=lu(n,mat2,ip);
	if(det==0) return -2;
	solve(n,mat2,vec,ip,ans);
	PFree(ip);
	PFree(mat2);
	return 1;
}
