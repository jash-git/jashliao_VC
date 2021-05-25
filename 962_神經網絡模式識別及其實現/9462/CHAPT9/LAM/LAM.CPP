/****************************************************************************
*                                                                           *
*  LAM                                                                      *
*                                                                           *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>


// DEFINES
#define MAXNEURONS 100          // MAX NUMBER OF NEURONS PER LAYER
#define MAXPATTERNS 80          // MAX NUMBER OF PATTERNS IN A TRAINING SET


class LAME
{
private:
  int W[MAXNEURONS][MAXNEURONS];      // WEIGHTS MATRIX
  int Thresh[MAXNEURONS];
  int TrnSet[MAXPATTERNS][MAXNEURONS];  //TRAINING SET
  int TstSet[MAXPATTERNS][MAXNEURONS];  //TEST SET
  int inVect[MAXNEURONS];
  int outVect[MAXNEURONS];
  int    Neurons;
  int    TrnPatterns;                 // # of training set patterns
  int    TstPatterns;                 // # of test set patterns
public:
  LAME(void);
  void   GetTrnSet(char *Fname);
  int    GetTstSet(char *Fname);
  void   Train();
  void   Run(int i);
  void   ShowWeights();
  void   ShowThresholds();
  void   ShowInVect();
  void   ShowOutVect();
};
 
// ------------------------------------------------------------------------


// METHOD DEFINITIONS

LAME::LAME(){
Neurons=0;
TrnPatterns=0;
TstPatterns=0;
}

void LAME::GetTrnSet(char *Fname){
FILE  *PFILE;
int   i,j,k;

PFILE = fopen(Fname,"r");    
if (PFILE==NULL){
   printf("\nUnable to open file %s\n",Fname);
   exit(0);
   }
fscanf(PFILE,"%d",&TrnPatterns);
fscanf(PFILE,"%d",&Neurons);
for (i=0; i<TrnPatterns; i++) {
   for (j=0; j<Neurons; j++) {
      fscanf(PFILE,"%d",&k);
      TrnSet[i][j]=k;
      } /* endfor */
   } /* endfor */

}

int  LAME::GetTstSet(char *Fname){
   FILE  *PFILE;
   int i,j,k;
PFILE = fopen(Fname,"r");    
if (PFILE==NULL){
   printf("\nUnable to open file %s\n",Fname);
   exit(0);
   }
fscanf(PFILE,"%d",&TstPatterns);
for (i=0; i<TstPatterns; i++) {
   for (j=0; j<Neurons; j++) {
      fscanf(PFILE,"%d",&k);
      TstSet[i][j]=k;
      } /* endfor */
   } /* endfor */
return(TstPatterns);
}

void LAME::Train(){
   int i,j,p;
//Calc weight matrix

for (i=0; i<Neurons; i++) {
   for (j=0; j<Neurons; j++) {
      W[i][j]=0;
      printf("W[%d,%d]=",i,j);
      for (p=0; p<TrnPatterns; p++) {
         W[i][j] += (2*TrnSet[p][i]-1) *(2*TrnSet[p][j]-1);
         printf("%d*%d",2*TrnSet[p][i]-1,2*TrnSet[p][j]-1);
         if (p<TrnPatterns-1) printf("+");
         } /* endfor */
      printf("=%d\n",W[i][j]);
      } /* endfor */
   } /* endfor */

//Calc Thresholds
for (i=0; i<Neurons; i++) {
   for (j=0; j<Neurons; j++) {
      Thresh[i] += W[i][j];
      } /* endfor */
   Thresh[i]=Thresh[i]/2;
   } /* endfor */
}

void LAME::Run(int tp){
   int i,j;
   int RawOutVect[MAXNEURONS];
for (i=0; i<Neurons; i++) {
   inVect[i]=TstSet[tp][i];
   } /* endfor */
for (i=0; i<Neurons; i++) {
   RawOutVect[i] = 0;
   for (j=0; j<Neurons; j++) {
      RawOutVect[i]+=W[i][j] * inVect[j];  //Calc Raw output vect
      } /* endfor */
   } /* endfor */
//apply threshold
for (i=0; i<Neurons; i++) {
   if (RawOutVect[i]>Thresh[i]) {
      outVect[i]=1;
   } else {
      outVect[i]=0;
   } /* endif */
   } /* endfor */

}

void LAME::ShowWeights(){
   int i,j;
for (i=0; i<Neurons; i++) {
   for (j=0; j<Neurons; j++) {
      printf("%2d ",W[i][j]);
      } /* endfor */
   printf("\n");
   } /* endfor */
}

void LAME::ShowThresholds(){
   int i;
printf("Threshold = [");
for (i=0; i<Neurons; i++) {
   printf("%d ",Thresh[i]);
   if (i<Neurons-1) printf(",");
   } /* endfor */
printf("]\n");
}

void LAME::ShowInVect(){
   int i;
printf("IN:  ");
for (i=0; i<Neurons; i++) {
   printf("%d ",inVect[i]);
   } /* endfor */
printf("\n");
}

void LAME::ShowOutVect(){
   int i;
printf("OUT: ");
for (i=0; i<Neurons; i++) {
   printf("%d ",outVect[i]);
   } /* endfor */
printf("\n");
}

// ------------------------------------------------------------------------
LAME    LAM;

/******************************************************************************
*  MAIN                                                                       *
******************************************************************************/


int main(int argc, char *argv[])
{
   int TstSetSize;
   int i;
if (argc>2) {
   LAM.GetTrnSet(argv[1]);
   TstSetSize=LAM.GetTstSet(argv[2]);
   LAM.Train();
   LAM.ShowWeights();
   LAM.ShowThresholds();
   for (i=0; i<TstSetSize; i++) {
      LAM.Run(i);                  //Evaluate ith test pattern
      printf("\n");
      LAM.ShowInVect();
      LAM.ShowOutVect();
   } /* endfor */
   }
 else {
   printf("USAGE: LAM TRAINING_FILE TEST_FILE\n");
   exit(0);
   }


return 0;
}
