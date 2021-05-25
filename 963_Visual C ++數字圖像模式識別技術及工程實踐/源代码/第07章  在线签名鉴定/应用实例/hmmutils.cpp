//hmmutils.cpp
//date:2001.10.11
//      Purpose: utilities for reading, writing HMM stuff. 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "nrutils.h"
#include "hmm.h"
static char rcsid[] = "Hidden Markov Model";

void ReadHMM(FILE *fp, HMM *phmm)
{
	int i, j, k;

	fscanf(fp, "M= %d\n", &(phmm->M)); 

	fscanf(fp, "N= %d\n", &(phmm->N)); 

	fscanf(fp, "A:\n");
	phmm->A = (double **) dmatrix(1, phmm->N, 1, phmm->N);
	for (i = 0; i < phmm->N; i++) { 
		for (j = 0; j < phmm->N; j++) {
			fscanf(fp, "%lf", &(phmm->A[i][j])); 
		}
		fscanf(fp,"\n");
	}

	fscanf(fp, "B:\n");
	phmm->B = (double **) dmatrix(1, phmm->N, 1, phmm->M);
	for (j = 0; j < phmm->N; j++) { 
		for (k = 0; k < phmm->M; k++) {
			fscanf(fp, "%lf", &(phmm->B[j][k])); 
		}
		fscanf(fp,"\n");
	}

	fscanf(fp, "pi:\n");
	phmm->pi = (double *) dvector(1, phmm->N);
	for (i = 0; i < phmm->N; i++) 
		fscanf(fp, "%lf", &(phmm->pi[i])); 

}

void FreeHMM(HMM *phmm)
{
	free_dmatrix(phmm->A, 1, phmm->N, 1, phmm->N);
	free_dmatrix(phmm->B, 1, phmm->N, 1, phmm->M);
	free_dvector(phmm->pi, 1, phmm->N);
}

/*
** InitHMM() This function initializes matrices A, B and vector pi with
**	random values. Not doing so can result in the BaumWelch behaving
**	quite weirdly.
*/ 

void InitHMM(HMM *phmm, int N, int M, int seed)
{
	int i, j, k;
	double sum;


	/* initialize random number generator */


	hmmsetseed(seed);	

       	phmm->M = M;
 
        phmm->N = N;
 
        phmm->A = (double **) dmatrix(1, phmm->N, 1, phmm->N);

        for (i = 0; i < phmm->N; i++) {
		sum = 0.0;
                for (j = 0; j < phmm->N; j++) {
                        phmm->A[i][j] = hmmgetrand(); 
			sum += phmm->A[i][j];
		}
                for (j = 0; j < phmm->N; j++) 
			 phmm->A[i][j] /= sum;
	}
 
        phmm->B = (double **) dmatrix(1, phmm->N, 1, phmm->M);

        for (j = 0; j < phmm->N; j++) {
		sum = 0.0;	
                for (k = 0; k < phmm->M; k++) {
                        phmm->B[j][k] = hmmgetrand();
			sum += phmm->B[j][k];
		}
                for (k = 0; k < phmm->M; k++) 
			phmm->B[j][k] /= sum;
	}
 
        phmm->pi = (double *) dvector(1, phmm->N);
	sum = 0.0;
        for (i = 0; i < phmm->N; i++) {
                phmm->pi[i] = hmmgetrand(); 
		sum += phmm->pi[i];
	}
        for (i = 0; i < phmm->N; i++) 
		phmm->pi[i] /= sum;
}

void CopyHMM(HMM *phmm1, HMM *phmm2)
{
        int i, j, k;
 
        phmm2->M = phmm1->M;

 
        phmm2->N = phmm1->N;
 
        phmm2->A = (double **) dmatrix(1, phmm2->N, 1, phmm2->N);
 
        for (i = 0; i < phmm2->N; i++)
                for (j = 0; j < phmm2->N; j++)
                        phmm2->A[i][j] = phmm1->A[i][j];
 
        phmm2->B = (double **) dmatrix(1, phmm2->N, 1, phmm2->M);
        for (j = 0; j < phmm2->N; j++)
                for (k = 0; k < phmm2->M; k++)
                        phmm2->B[j][k] = phmm1->B[j][k];
 
        phmm2->pi = (double *) dvector(1, phmm2->N);
        for (i = 0; i < phmm2->N; i++)
                phmm2->pi[i] = phmm1->pi[i]; 
 
}

void PrintHMM(FILE *fp, HMM *phmm)
{
        int i, j, k;

	fprintf(fp, "M= %d\n", phmm->M); 
	fprintf(fp, "N= %d\n", phmm->N); 
 
	fprintf(fp, "A:\n");
        for (i = 0; i < phmm->N; i++) {
                for (j = 0; j < phmm->N; j++) {
                        fprintf(fp, "%f ", phmm->A[i][j] );
		}
		fprintf(fp, "\n");
	}
 
	fprintf(fp, "B:\n");
        for (j = 0; j < phmm->N; j++) {
                for (k = 0; k < phmm->M; k++){
                        fprintf(fp, "%f ", phmm->B[j][k]);
		}
		fprintf(fp, "\n");
	}
 
	fprintf(fp, "pi:\n");
        for (i = 0; i < phmm->N; i++) {
		fprintf(fp, "%f ", phmm->pi[i]);
	}
	fprintf(fp, "\n\n");
}

