//nrutil.cpp
#include "StdAfx.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

//�������
void nrerror(char *error_text)
{
	printf("Numerical Recipes run-time error...\n");
	printf("%s\n",error_text);
	printf("...now exiting to system...\n");
	exit(1);
}

/*****************************************************************************
 * �������ƣ�vector
 * ���ܣ�����һ��ʵ������
 * ������nl�����������±�
 *       nh�����������±�
 * ���أ������ַ
 */
float *vector(long nl,long nh)
{
	float *v;

	v=(float *)calloc((unsigned) (nh-nl+1),sizeof(float));
	if (!v) nrerror("allocation failure in vector()");
	return v-nl;
}

/*****************************************************************************
 * �������ƣ�ivector
 * ���ܣ�����һ����������
 * ������nl�����������±�
 *       nh�����������±�
 * ���أ������ַ
 */
int *ivector(long nl,long nh)
{
	int *v;

	v=(int *)calloc((unsigned) (nh-nl+1),sizeof(int));
	if (!v) nrerror("allocation failure in ivector()");
	return v-nl;
}

/*****************************************************************************
 * �������ƣ�cvector
 * ���ܣ�����һ���޷����ַ�����
 * ������nl�����������±�
 *       nh�����������±�
 * ���أ������ַ
 */
unsigned char *cvector(long nl,long nh)
{
	unsigned char *v;

	v=(unsigned char *)calloc((unsigned) (nh-nl+1),sizeof(unsigned char));
	if (!v) nrerror("allocation failure in cvector()");
	return v-nl;
}

/*****************************************************************************
 * �������ƣ�lvector
 * ���ܣ�����һ��������������
 * ������nl�����������±�
 *       nh�����������±�
 * ���أ������ַ
 */
unsigned long *lvector(long nl,long nh)
{
	unsigned long *v;

	v=(unsigned long *)calloc((unsigned) (nh-nl+1),sizeof(unsigned long));
	if (!v) nrerror("allocation failure in lvector()");
	return v-nl;
}

/*****************************************************************************
 * �������ƣ�dvector
 * ���ܣ�����һ��˫����ʵ������
 * ������nl�����������±�
 *       nh�����������±�
 * ���أ������ַ
 */
double *dvector(long nl,long nh)
{
	double *v;

	v=(double *)calloc((unsigned) (nh-nl+1),sizeof(double));
	if (!v) nrerror("allocation failure in dvector()");
	return v-nl;
}

/*****************************************************************************
 * �������ƣ�matrix
 * ���ܣ�����һ��ʵ����ά���飨����
 * ������nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * ���أ������ַ
 */
float **matrix(long nrl,long nrh,long ncl,long nch)
{
	int i;
	float **m;

	m=(float **) calloc((unsigned) (nrh-nrl+1),sizeof(float*));
	if (!m) nrerror("allocation failure 1 in matrix()");
	m -= nrl;

	for(i=nrl;i<=nrh;i++) {
		m[i]=(float *) calloc((unsigned) (nch-ncl+1),sizeof(float));
		if (!m[i]) nrerror("allocation failure 2 in matrix()");
		m[i] -= ncl;
	}
	return m;
}

/*****************************************************************************
 * �������ƣ�dmatrix
 * ���ܣ�����һ��˫����ʵ����ά���飨����
 * ������nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * ���أ������ַ
 */
double **dmatrix(long nrl,long nrh,long ncl,long nch)
{
	int i;
	double **m;

	m=(double **) calloc((unsigned) (nrh-nrl+1),sizeof(double*));
	if (!m) nrerror("allocation failure 1 in dmatrix()");
	m -= nrl;

	for(i=nrl;i<=nrh;i++) {
		m[i]=(double *) calloc((unsigned) (nch-ncl+1),sizeof(double));
		if (!m[i]) nrerror("allocation failure 2 in dmatrix()");
		m[i] -= ncl;
	}
	return m;
}

/*****************************************************************************
 * �������ƣ�imatrix
 * ���ܣ�����һ��������ά���飨����
 * ������nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * ���أ������ַ
 */
int **imatrix(long nrl,long nrh,long ncl,long nch)
{
	int i,**m;

	m=(int **)calloc((unsigned) (nrh-nrl+1),sizeof(int*));
	if (!m) nrerror("allocation failure 1 in imatrix()");
	m -= nrl;

	for(i=nrl;i<=nrh;i++) {
		m[i]=(int *)calloc((unsigned) (nch-ncl+1),sizeof(int));
		if (!m[i]) nrerror("allocation failure 2 in imatrix()");
		m[i] -= ncl;
	}
	return m;
}

/*****************************************************************************
 * �������ƣ�cmatrix
 * ���ܣ�����һ���޷����ַ��Ͷ�ά���飨����
 * ������nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * ���أ������ַ
 */
unsigned char **cmatrix(long nrl,long nrh,long ncl,long nch)
{
	int i;
	unsigned char **m;

	m=(unsigned char **) calloc((unsigned) (nrh-nrl+1),sizeof(unsigned char*));
	if (!m) nrerror("allocation failure 1 in dmatrix()");
	m -= nrl;

	for(i=nrl;i<=nrh;i++) {
		m[i]=(unsigned char *) calloc((unsigned) (nch-ncl+1),sizeof(unsigned char));
		if (!m[i]) nrerror("allocation failure 2 in dmatrix()");
		m[i] -= ncl;
	}
	return m;
}

/*****************************************************************************
 * �������ƣ�submatrix
 * ���ܣ���һ����ά������Ӿ���
 * ������a����ά������׵�ַ
 *       oldrl�������������±�
 *       oldrh�������������±�
 *       oldcl�������������±�
 *       oldch�������������±�
 *       newrl���������������±�
 *       newcl���������������±�
 * ���أ������ַ
 */
float **submatrix(float **a,long oldrl,long oldrh,long oldcl,long oldch,long newrl,long newcl)
{
	int i,j;
	float **m;

	m=(float **) calloc((unsigned) (oldrh-oldrl+1),sizeof(float*));
	if (!m) nrerror("allocation failure in submatrix()");
	m -= newrl;

	for(i=oldrl,j=newrl;i<=oldrh;i++,j++) m[j]=a[i]+oldcl-newcl;

	return m;
}

/*****************************************************************************
 * �������ƣ�convert_matrix
 * ���ܣ���һ��ʵ��һά����ת��Ϊ��ά���飨����
 * ������a��ԭһά����
 *       nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * ���أ���ά�����ַ
 */
float **convert_matrix(float *a,long nrl,long nrh,long ncl,long nch)
{
	int i,j,nrow,ncol;
	float **m;

	nrow=nrh-nrl+1;
	ncol=nch-ncl+1;
	m = (float **) calloc((unsigned) (nrow),sizeof(float*));
	if (!m) nrerror("allocation failure in convert_matrix()");
	m -= nrl;
	for(i=0,j=nrl;i<=nrow-1;i++,j++) m[j]=a+ncol*i-ncl;
	return m;
}

/*****************************************************************************
 * �������ƣ�free_vector
 * ���ܣ��ͷ�һ��ʵ��һά����
 * ������nl�������������±�
 *       nh�������������±�
 * �޷���ֵ
 */
void free_vector(float *v,long nl,long nh)
{
	free((char*) (v+nl));
}

/*****************************************************************************
 * �������ƣ�free_dvector
 * ���ܣ��ͷ�һ������һά����
 * ������nl�������������±�
 *       nh�������������±�
 * �޷���ֵ
 */
void free_ivector(int *v,long nl,long nh)
{
	free((char*) (v+nl));
}

/*****************************************************************************
 * �������ƣ�free_vector
 * ���ܣ��ͷ�һ���޷����ַ���һά����
 * ������nl�������������±�
 *       nh�������������±�
 * �޷���ֵ
 */
void free_cvector(unsigned char *v,long nl,long nh)
{
	free((char*) (v+nl));
}

/*****************************************************************************
 * �������ƣ�free_vector
 * ���ܣ��ͷ�һ��������һά����
 * ������nl�������������±�
 *       nh�������������±�
 * �޷���ֵ
 */
void free_lvector(unsigned long *v,long nl,long nh)
{
	free((char*) (v+nl));
}

/*****************************************************************************
 * �������ƣ�free_vector
 * ���ܣ��ͷ�һ��˫����һά����
 * ������nl�������������±�
 *       nh�������������±�
 * �޷���ֵ
 */
void free_dvector(double *v,long nl,long nh)
{
	free((char*) (v+nl));
}

/*****************************************************************************
 * �������ƣ�free_matrix
 * ���ܣ��ͷ�һ��ʵ����ά���飨����
 * ������m��ԭ�����ַ
 *       nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * �޷���ֵ
 */
void free_matrix(float **m,long nrl,long nrh,long ncl,long nch)
{
	int i;

	for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
	free((char*) (m+nrl));
}

/*****************************************************************************
 * �������ƣ�free_dmatrix
 * ���ܣ��ͷ�һ��˫���ȶ�ά���飨����
 * ������m��ԭ�����ַ
 *       nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * �޷���ֵ
 */
void free_dmatrix(double **m,long nrl,long nrh,long ncl,long nch)
{
	int i;

	for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
	free((char*) (m+nrl));
}

/*****************************************************************************
 * �������ƣ�free_imatrix
 * ���ܣ��ͷ�һ�����Ͷ�ά���飨����
 * ������m��ԭ�����ַ
 *       nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * �޷���ֵ
 */
void free_imatrix(int **m,long nrl,long nrh,long ncl,long nch)
{
	int i;

	for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
	free((char*) (m+nrl));
}

/*****************************************************************************
 * �������ƣ�free_cmatrix
 * ���ܣ��ͷ�һ���޷����ַ���ά���飨����
 * ������m��ԭ�����ַ
 *       nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * �޷���ֵ
 */
void free_cmatrix(unsigned char **m,long nrl,long nrh,long ncl,long nch)
{
	int i;

	for(i=nrh;i>=nrl;i--) free((char*) (m[i]+ncl));
	free((char*) (m+nrl));
}

/*****************************************************************************
 * �������ƣ�free_submatrix
 * ���ܣ��ͷ�һ���Ӷ�ά���飨����
 * ������b��ԭ�����ַ
 *       nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * �޷���ֵ
 */
void free_submatrix(float **b,long nrl,long nrh,long ncl,long nch)
{
	free((char*) (b+nrl));
}
/*****************************************************************************
 * �������ƣ�free_convert_matrix
 * ���ܣ��ͷ�ת����Ķ�ά���飨����
 * ������b��ԭ�����ַ
 *       nrl�������������±�
 *       nrh�������������±�
 *       ncl�������������±�
 *       nch�������������±�
 * �޷���ֵ
 */
void free_convert_matrix(float **b,long nrl,long nrh,long ncl,long nch)
{
	free((char*) (b+nrl));
}
