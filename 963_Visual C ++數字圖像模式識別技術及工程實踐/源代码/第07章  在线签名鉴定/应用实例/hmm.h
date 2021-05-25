//hmm.h --hidden markov model

#ifndef _hmm_h
#define _hmm_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
	int N;		/* number of states;  Q={1,2,...,N} */
	int M; 		/* number of observation symbols; V={1,2,...,M}*/
	double	**A;	/* A[1..N][1..N]. a[i][j] is the transition prob
			   of going from state i at time t to state j
			   at time t+1 */
	double	**B;	/* B[1..N][1..M]. b[j][k] is the probability of
			   of observing symbol k in state j */
	double	*pi;	/* pi[1..N] pi[i] is the initial state distribution. */
} HMM;
void ReadHMM(FILE *fp, HMM *phmm);
void PrintHMM(FILE *fp, HMM *phmm);
void InitHMM(HMM *phmm, int N, int M, int seed);
void CopyHMM(HMM *phmm1, HMM *phmm2);
void FreeHMM(HMM *phmm);

void ReadSequence(FILE *fp, int *pT, int **pO);
void PrintSequence(FILE *fp, int T, int *O);
void GenSequenceArray(HMM *phmm, int seed, int T, int *O, int *q);
int GenInitalState(HMM *phmm);
int GenNextState(HMM *phmm, int q_t);
int GenSymbol(HMM *phmm, int q_t);

 
void Forward(HMM *phmm, int T, int *O, double **alpha, double *pprob);
void ForwardWithScale(HMM *phmm, int T, int *O, double **alpha,
        double *scale, double *pprob);
void Backward(HMM *phmm, int T, int *O, double **beta, double *pprob);
void BackwardWithScale(HMM *phmm, int T, int *O, double **beta,
        double *scale, double *pprob);

//////////////////////////////////////////////////////////////////////////////
// ����������HMM������������phmm��
// �������Ϊ��������O������ΪT
// һ���ڵ���ǰ��Ҫ������alloc memory�Ĺ�������Ϊʾ���� 
//alpha = dmatrix(1, T, 1, hmm.N)
//	beta = dmatrix(1, T, 1, hmm.N)
//	gamma = dmatrix(1, T, 1, hmm.N)
//	BaumWelch(&hmm, T, O, alpha, beta, gamma, &niter, 
//		&logprobinit, &logprobfinal)
// �������ͷ��ڴ棬ʾ�����£�
// free_dmatrix(alpha, 1, T, 1, hmm.N)
//free_dmatrix(beta, 1, T, 1, hmm.N)
//	free_dmatrix(gamma, 1, T, 1, hmm.N)
void BaumWelch(HMM *phmm, int T, int *O, double **alpha, double **beta,
        double **gamma, int *niter, 
	double *plogprobinit, double *plogprobfinal);

double *** AllocXi(int T, int N);
void FreeXi(double *** xi, int T, int N);
void ComputeGamma(HMM *phmm, int T, double **alpha, double **beta,
        double **gamma);
void ComputeXi(HMM* phmm, int T, int *O, double **alpha, double **beta,
        double ***xi);

////////////////////////////////////////////////////////////////////////
// ��������������������Viterbi����������phmmģ�Ͳ����£���������
// ΪO�ĸ��ʣ�����TΪ���г��ȣ����������pprob��
// һ���ڵ���ǰ���������ڴ�
//	q = ivector(1,T);
//delta = dmatrix(1, T, 1, hmm.N)
//psi = imatrix(1, T, 1, hmm.N)
//��Ȼ�ˣ���Щ�ڴ滹��Ҫ�ͷŵģ�q����Ӧ��״̬�仯���У�����Ҳ��T
void Viterbi(HMM *phmm, int T, int *O, double **delta, int **psi,
        int *q, double *pprob);
void ViterbiLog(HMM *phmm, int T, int *O, double **delta, int **psi,
        int *q, double *pprob);

/* random number generator related functions*/

int hmmgetseed(void);
void hmmsetseed(int seed);
double hmmgetrand(void);
 
#ifndef MAX
#define MAX(x,y)        ((x) > (y) ? (x) : (y))
#endif

#ifndef MIN
#define MIN(x,y)        ((x) < (y) ? (x) : (y))
#endif

#endif 
 

