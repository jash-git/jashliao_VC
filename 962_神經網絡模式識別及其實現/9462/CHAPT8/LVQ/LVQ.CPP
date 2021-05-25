#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define   MAXPATS       100
#define   MAXNEURONSIN  50
#define   MAXNEURONS    15

#define   MAXEPOCHS     1500
#define   ETAMIN       .001

unsigned int Random(int N) {
  unsigned int j;
j= (N*rand())/RAND_MAX;
if (j>=N) j=N;
return j;
}

class TPATTERN {
  friend class LVQ;
private:
  double          P[MAXPATS][MAXNEURONSIN];
  int             PClass[MAXPATS];
  int             NumPatterns;
  int             NumClasses;
  int             Shuffle[MAXPATS];
  int             SizeVector;
public:
  TPATTERN();
  int GetPatterns(char *);  //load pattern form file
  int GetRandPats(int,int); //random patterns arg1=# of patterns, arg2=dimension
  double Query(int,int);    //returns P[arg1][arg2]
  double QueryR(int,int);   //returns P[Shuffle[arg1]][arg2]
  int    QueryClass(int);
  void ReShuffle(int N);
};

TPATTERN::TPATTERN(){
int i;
for (i=0; i<MAXPATS; i++)
   Shuffle[i]=i;
}

int TPATTERN::GetPatterns(char *fname) {
  FILE *fp;
  int i,j,k;
  double x;
fp=fopen(fname,"r");
if (fp==NULL) return 0;  // Test for failure.
fscanf(fp,"%d",&NumPatterns);
fscanf(fp,"%d",&SizeVector);
fscanf(fp,"%d",&NumClasses);
for (i=0; i<NumPatterns; i++) {         // For each vector
   for (j=0; j<SizeVector; j++) {       // create a pattern
      fscanf(fp,"%lg",&x);              // consisting of all elements
      P[i][j]=x;
      } /* endfor */
   fscanf(fp,"%d",&k);
   PClass[i]=k;
   } /* endfor */
fclose(fp);
return 1;
}

int TPATTERN::GetRandPats(int n1,int n2) { 
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

void TPATTERN::ReShuffle(int N) {
int i,a1,a2,tmp;
for (i=0; i<N ;i++) {
   a1=Random(NumPatterns);
   a2=Random(NumPatterns);
   tmp=Shuffle[a1];
   Shuffle[a1]=Shuffle[a2];
   Shuffle[a2]=tmp;
   }
}

double TPATTERN::Query(int pat,int j) {
return P[pat][j];
}

double TPATTERN::QueryR(int pat,int j) {
return P[Shuffle[pat]][j];
}

int TPATTERN::QueryClass(int pat) {
return PClass[pat];
}

class LVQ {
private:
  double  W[MAXNEURONSIN][MAXNEURONS];  //The weight matrix
  int     zClass[MAXNEURONS];           //Class assinment for each neuron
  double  Yout[MAXNEURONS];             //The output layer neurons
  double  Yin[MAXNEURONSIN];            //The input layer neurons
  int     YinSize;                      //input layer dimensions
  int     YoutSize;                     //outlayer dimensions (Must match NumClasses)

  int     epoch;
  double  eta;                          //The learning rate
  double  delta_eta;                    //Amount to change l.r. each epoch
  int     StochFlg;                     //Present vectors in rand order if 1
  TPATTERN *Pattern;

  int     LoadInLayer(int);             //pattern->input layer
  double  EucNorm(int);                 //Calc Euclidean distance
  int     FindWinner();                 //get coords of winning neuron
  void    Train(int,int);
  void    AdaptParms();
public:
  LVQ();
  void SetPattern(TPATTERN *);
  void SetParms(int, double);
  void PrintWeights();
  void PrintWinner();
  void RunTrn();
  void Run();
};

LVQ::LVQ(){
StochFlg=0;
}

void LVQ::SetPattern(TPATTERN *p) {
   Pattern=p;
   YinSize=p->SizeVector;
}


void LVQ::SetParms(int X, double LR){
  int i,k,m;
YoutSize=X;
eta=LR;
delta_eta=0.002;
for (i=0; i<YoutSize; i++) {
   for (k=0; k<YinSize; k++) {
      W[k][i]= (double)rand()/(10.0 * (double)RAND_MAX);
      } /* endfor */
   m=YoutSize/Pattern->NumClasses;
   zClass[i]= i/m;
   } /* endfor */
}

int LVQ::LoadInLayer(int P){
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


void LVQ::AdaptParms(){
eta=eta-delta_eta;
if (eta<ETAMIN)
   eta=ETAMIN;
}

void  LVQ::PrintWeights() {
   int i,k;
for (i=0; i<YoutSize; i++) {
    printf("W[%d]=",i);
    for (k=0; k<YinSize; k++) {
       printf("%f ",W[k][i]);
       } /* endfor */
    printf("\n");
    } /* endfor */
}

void LVQ::RunTrn(){
int pat,np;
int k,z;
int Winner;
epoch=0;
np=Pattern->NumPatterns;
while (epoch<=MAXEPOCHS){
   if( (epoch<=50) || (25*(epoch/25)==epoch) ) {        //output control
      printf("EPOCH=%d\n",epoch);
      printf("eta=%f\n",eta);
      }
   for (pat=0; pat<np; pat++){     //Traverse all patterns
     LoadInLayer(pat);
     Winner=FindWinner();
     if( (epoch<=50) || (25*(epoch/25)==epoch) ) {        //output control
        printf("winner=%d/pat=%d\n",Winner,pat);
        printf("winner class=%d/pat class=%d\n",zClass[Winner],Pattern->QueryClass(pat));
        }
     Train(Winner,pat);
     if( (epoch<=50) || (25*(epoch/25)==epoch) ) {        //output control
        printf("W[%d]=",Winner);
        z=1;
        for (k=0; k<YinSize; k++) {
           printf("%f ",W[k][Winner]);
           if (z>4){
              printf("\n     ");
              z=1;
              }
            else
              z++;
           } /* endfor */
        printf("\n\n");
        }
     }
   epoch++;                       //keep track of epochs
   if (StochFlg)                  // if desired
     Pattern->ReShuffle(np);      //   reorder training patterns
   AdaptParms();                  //Adjust the learning rate
   }
}

void LVQ::Run(){
  int pat,np,i;
  int Winner;
printf("\n");
np=Pattern->NumPatterns;
for (pat=0; pat<np; pat++){     //Traverse all patterns
   LoadInLayer(pat);
   Winner=FindWinner();
   printf("Responding neuron %d is of class %d \n",Winner,zClass[Winner]);
   printf("The desired class for pattern %d is: %d\n",pat,Pattern->QueryClass(pat));
   printf("The distances to each of the output layer neurons are:\n");
   for (i=0;i<YoutSize ; i++) {
      printf("distance from pattern %d to neuron %d is: %f\n",pat,i,EucNorm(i));
      } /* endfor */
   printf("\n");
   }
}


void LVQ::Train(int Winner, int pat){
  int c,k;
c=Pattern->QueryClass(pat);
if (c==zClass[Winner]) {
   for (k=0; k<YinSize; k++){
      W[k][Winner]=W[k][Winner]+eta*(Yin[k]-W[k][Winner]);
      } /*endfor*/
   } 
 else {
   for (k=0; k<YinSize; k++){
      W[k][Winner]=W[k][Winner]-eta*(Yin[k]-W[k][Winner]);
      } /*endfor*/
   } /* endif */
}



int  LVQ::FindWinner(){
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

double LVQ::EucNorm(int x){   // Calc Euclidean norm of vector dif
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

TPATTERN InPat;
TPATTERN InPat2;
LVQ    net;


//=================================================================
// Main()
//=================================================================

main(int argc, char *argv[]) {
   int rc;
if (argc>1) {
   InPat.GetPatterns(argv[1]);    //Establish training pattern
   net.SetPattern(&InPat);        //Inform the net about the pattern
   net.SetParms(4, 0.2500);       //Init fm parms
   // net.SetParms(4, 0.3000);    //Init fm parms
   net.RunTrn();                  //Run the FM w/ training enabled
   if (argc>2) {
      rc=InPat2.GetPatterns(argv[2]);   //Establish test pattern
      if (rc) {
         net.SetPattern(&InPat2);          //Inform the net about the new pattern
         net.Run();
         }
       else {
         printf("\nUnable to open test file: %s\n", argv[2]);
         } /* endif */
      } /* endif */
   }
 else {
   printf("USAGE: LVQ TRAIN_PATTERN_FILE [TEST_PATTERN_FILE]");
   }
}
