/*
**      File:   backward.cpp
**      ���ܣ������۲�ֵ���к�HMMģ�ͣ�����ǰ������㷨
**            ��ȡ�����
*/

#include "StdAfx.h"
#include <stdio.h>
#include "hmm.h"

/***************************************************************************
** �������ƣ�Backward
** ���ܣ������㷨���Ʋ���
** ������phmm��ָ��HMM��ָ��
**       T���۲�ֵ���еĳ���
**       O���۲�ֵ����
**       beta���������õ�����ʱ����
**       pprob������ֵ����Ҫ��ĸ���
**/
void Backward(HMM *phmm, int T, int *O, double **beta, double *pprob)
{
	int     i, j;   /* ״̬ */
	int     t;      /* ʱ���±� */
	double sum;
 
 
	/* 1. ��ʼ�� */
 
	for (i = 1; i <= phmm->N; i++)
		beta[T][i] = 1.0;
 
	/* 2. �ݹ� */
 
	for (t = T - 1; t >= 1; t--) 
	{
		for (i = 1; i <= phmm->N; i++) 
		{
			sum = 0.0;
			for (j = 1; j <= phmm->N; j++)
				sum += phmm->A[i][j] * (phmm->B[j][O[t+1]])*beta[t+1][j];
			beta[t][i] = sum;
 
		}
	}
 
	/* 3. ��ֹ */
	*pprob = 0.0;
	for (i = 1; i <= phmm->N; i++)
		*pprob += beta[1][i];
}

/***************************************************************************
** �������ƣ�BackwardWithScale
** ���ܣ������㷨���Ʋ���������������������
** ������phmm��ָ��HMM��ָ��
**       T���۲�ֵ���еĳ���
**       O���۲�ֵ����
**       beta���������õ�����ʱ����
**       scale��������������
**       pprob������ֵ����Ҫ��ĸ���
**/
void BackwardWithScale(HMM *phmm, int T, int *O, double **beta, 
	double *scale, double *pprob)
{
	int     i, j;   /* ״ָ̬ʾ */
	int     t;      /* ʱ���±� */
	double sum;
 
 
	/* 1. ��ʼ�� */
	for (i = 1; i <= phmm->N; i++)
		beta[T][i] = 1.0/scale[T]; 
 
	/* 2. �ݹ� */
	for (t = T - 1; t >= 1; t--) 
	{
		for (i = 1; i <= phmm->N; i++) 
		{
			sum = 0.0;
			for (j = 1; j <= phmm->N; j++)
				sum += phmm->A[i][j] * (phmm->B[j][O[t+1]])*beta[t+1][j];
			beta[t][i] = sum/scale[t];
		}
	}
}
