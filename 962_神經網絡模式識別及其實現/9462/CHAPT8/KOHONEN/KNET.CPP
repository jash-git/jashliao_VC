#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define   MAXPATS       100
#define   MAXNEURONSIN  10
#define   MAXNEURONS    15

#define   MAXEPOCHS     1000
#define   ETAMIN       .001

unsigned int Random(int N) {
  unsigned int j;
j= (N*rand())/RAND_MAX;
if (j>=N) j=N;
return j;
}

class PATTERN {
  friend class KNET;
private:
  double          P[MAXPATS][MAXNEURONSIN];
  int             NumPatterns;
  int             Shuffle[MAXPATS];
  int             SizeVector;
public:
  PATTERN();
  int GetPatterns(char *);  //load pattern form file
  int GetRandPats(int,int); //random patterns arg1=# of patterns, arg2=dimension
  double Query(int,int);    //returns P[arg1][arg2]
  double QueryR(int,int);   //returns P[Shuffle[arg1]][arg2]
  void ReShuffle(int N);
};

PATTERN::PATTERN(){
int i;
for (i=0; i<MAXPATS; i++)
   Shuffle[i]=i;
}

int PATTERN::GetPatterns(char *fname) {
  FILE *fp;
  int i,j;
  double x;
fp=fopen(fname,"r");
if (fp==NULL) return 0;  // Test for failure.
fscanf(fp,"%d",&NumPatterns);
fscanf(fp,"%d",&SizeVector);
for (i=0; i<NumPatterns; i++) {         // For each vector
   for (j=0; j<SizeVector; j++) {       // create a pattern
      fscanf(fp,"%lg",&x);              // consisting of all elements
      P[i][j]=x;
      } /* endfor */
   } /* endfor */
fclose(fp);
return 1;
}

int PATTERN::GetRandPats(int n1,int n2) { 
   int i,j;
   double x;
NumPatterns=n1;
SizeVector=n2;
for (i=0; i<NumPatterns; i++) {         // For each vector
   for (j=0; j<SizeVector; j++) {       // create a pattern
      x=(double)rand()/RAND_MAX;        // consisting of random elements
      P[i][j]=x;                        // between 0 and 1
      } /* endfor */
   } /* endfor */
return 1;
}

void PATTERN::ReShuffle(int N) {
int i,a1,a2,tmp;
for (i=0; i<N ;i++) {
   a1=Random(NumPatterns);
   a2=Random(NumPatterns);
   tmp=Shuffle[a1];
   Shuffle[a1]=Shuffle[a2];
   Shuffle[a2]=tmp;
   }
}

double PATTERN::Query(int pat,int j) {
return P[pat][j];
}

double PATTERN::QueryR(int pat,int j) {
return P[Shuffle[pat]][j];
}


class KNET {
private:
  double  W[MAXNEURONSIN][MAXNEURONS];  // The weight matrix
  double  Yout[MAXNEURONS];             // The output layer neurons
  double  Yin[MAXNEURONSIN];            //The input layer neurons
  int     YinSize;                      //input layer dimensions
  int     YoutSize;                     //outlayer dimensions

  int     epoch;
  double  eta;                          //The learning rate
  double  delta_eta;                    //Amount to change l.r. each epoch
  int     StochFlg;                     //Present vectors in rand order if 1
  PATTERN *Pattern;

  int     LoadInLayer(int);             //pattern->input layer
  double  EucNorm(int);                 //Calc Euclidean distance
  int     FindWinner();                 //get coords of winning neuron
  void    Train(int);
  void    AdaptParms();
public:
  KNET();
  void SetPattern(PATTERN *);
  void SetParms(int, double);
  void PrintWeights();
  void PrintWinner();
  void RunTrn();
  void Run();
};

KNET::KNET(){
StochFlg=0;
}

void KNET::SetPattern(PATTERN *p) {
   Pattern=p;
   YinSize=p->SizeVector;
}


void KNET::SetParms(int X, double LR){
  int i,k;
YoutSize=X;
eta=LR;
delta_eta=0.005;
for (i=0; i<YoutSize; i++) {
   for (k=0; k<YinSize; k++) {
      W[k][i]= (double)rand()/(10.0 * (double)RAND_MAX);
      } /* endfor */
   } /* endfor */
}

int KNET::LoadInLayer(int P){
  int i;
for (i=0; i<YinSize; i++){
   if (StochFlg){
      Yin[i]=Pattern->QueryR(P,i);
      }
    else {
      Yin[i]=Pattern->Query(P,i);
      }
   }
return 1;
}


void KNET::AdaptParms(){
eta=eta-delta_eta;
if (eta<ETAMIN)
   eta=ETAMIN;
printf("  New eta=%f\n",eta);
}

void  KNET::PrintWeights() {
   int i,k;
for (i=0; i<YoutSize; i++) {
      for (k=0; k<YinSize; k++) {
         printf("W[%d][%d]=%f  ",k,i,W[k][i]);
         } /* endfor */
      printf("\n");
   } /* endfor */
}

void KNET::RunTrn(){
int i,np;
int Winner;
epoch=0;
np=Pattern->NumPatterns;
while (epoch<=MAXEPOCHS){
   for (i=0; i<np; i++){
     LoadInLayer(i);
     Winner=FindWinner();
     Train(Winner);
     }
   if(5*(epoch/5)==epoch) {
     printf("Epoch=%d\n",epoch);
     PrintWeights();
     }
   epoch++;
   if (StochFlg)
     Pattern->ReShuffle(np);
   AdaptParms();
   }
}


void KNET::Train(int Winner){
  int k;
for (k=0; k<YinSize; k++){
   W[k][Winner]=W[k][Winner]+eta*(Yin[k]-W[k][Winner]);
   } /*endfor*/
}



int  KNET::FindWinner(){
  int i;
  double d,best;
  int Winner;
best=1.0e99;
Winner=-1;
for (i=0; i<YoutSize; i++){
  d=EucNorm(i);
  if (d<best) {
     best=d;
     Winner=i;
     } // endif
  } // endfor
return Winner;
}

double KNET::EucNorm(int x){   // Calc Euclidean norm of vector dif
int i;
double dist;
dist=0;
for (i=0; i< YinSize;i++){
   dist += (W[i][x]-Yin[i]) * (W[i][x]-Yin[i]);
   } /* endfor */
dist=sqrt(dist);
return dist;
}


//=================================================================
// GLOBAL OBJECTS
//=================================================================

PATTERN InPat;
KNET    net;


//=================================================================
// Main()
//=================================================================

main(int argc, char *argv[]) {
if (argc>1) {
   InPat.GetPatterns(argv[1]);   //Establish pattern
   net.SetPattern(&InPat);       //Inform the feature map about the pattern
   net.SetParms(3, 0.500);       //Init fm parms
   net.RunTrn();                 //Run the FM w/ training enabled
   }
 else {
   printf("USAGE: KNET PATTERN_FILE");
   }
}
