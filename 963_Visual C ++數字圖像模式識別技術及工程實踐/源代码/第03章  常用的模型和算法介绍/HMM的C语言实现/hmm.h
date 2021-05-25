/************************************************************************
**      File:   hmm.h
**      ���ܣ��ṩHMM�����ݽṹ�Ͷ���
*/
#include "StdAfx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	int N;		/* ״̬�ĸ�����  Q={1,2,...,N} */
	int M; 		/* �۲�ֵ�ø���; V={1,2,...,M}*/
	double	**A;	/* A[1..N][1..N]. a[i][j] �Ǵ�tʱ�̵�״̬iת�Ƶ�t+1ʱ��
					��״̬j��ת�Ƹ���*/
	double	**B;	/* B[1..N][1..M]. b[j][k] ����״̬j�۲쵽�۲�ֵk�ĸ��� */
	double	*pi;	/* pi[1..N] pi[i] �ǽ���Markov����״̬�ֲ� */
} HMM;

//����HMM���ļ���ȡ����ʼ������������
void ReadHMM(FILE *fp, HMM *phmm);
void PrintHMM(FILE *fp, HMM *phmm);
void InitHMM(HMM *phmm, int N, int M, int seed);
void CopyHMM(HMM *phmm1, HMM *phmm2);
void FreeHMM(HMM *phmm);

//�������еĴ�ȡ��״̬�ļ���ȵ�
void ReadSequence(FILE *fp, int *pT, int **pO);
void PrintSequence(FILE *fp, int T, int *O);
void GenSequenceArray(HMM *phmm, int seed, int T, int *O, int *q);
int GenInitalState(HMM *phmm);
int GenNextState(HMM *phmm, int q_t);
int GenSymbol(HMM *phmm, int q_t);

//ǰ������㷨��BaumWelch�㷨
void Forward(HMM *phmm, int T, int *O, double **alpha, double *pprob);
void ForwardWithScale(HMM *phmm, int T, int *O, double **alpha,
        double *scale, double *pprob);
void Backward(HMM *phmm, int T, int *O, double **beta, double *pprob);
void BackwardWithScale(HMM *phmm, int T, int *O, double **beta,
        double *scale, double *pprob);
void BaumWelch(HMM *phmm, int T, int *O, double **alpha, double **beta,
        double **gamma, int *niter, 
	double *plogprobinit, double *plogprobfinal);

//Viterbi�㷨
double *** AllocXi(int T, int N);
void FreeXi(double *** xi, int T, int N);
void ComputeGamma(HMM *phmm, int T, double **alpha, double **beta,
        double **gamma);
void ComputeXi(HMM* phmm, int T, int *O, double **alpha, double **beta,
        double ***xi);
void Viterbi(HMM *phmm, int T, int *O, double **delta, int **psi,
        int *q, double *pprob);
void ViterbiLog(HMM *phmm, int T, int *O, double **delta, int **psi,
        int *q, double *pprob);

//�������غ���

int hmmgetseed(void);
void hmmsetseed(int seed);
double hmmgetrand(void);
 
#define MAX(x,y)        ((x) > (y) ? (x) : (y))
#define MIN(x,y)        ((x) < (y) ? (x) : (y))
 

