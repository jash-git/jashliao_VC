#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define   MAXPATS       100
#define   MAXNEURONSIN  10
#define   MAXNEURONSX   15
#define   MAXNEURONSY   15

#define   MAXEPOCHS    2000
#define   ETAMIN       .005

unsigned int Random(int N) {
  unsigned int j;
j= (N*rand())/RAND_MAX;
if (j>=N) j=N;
return j;
}

class PATTERN {
  friend class SOFM;
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


struct iPair {
  int x,y;
};


class SOFM {
private:
  double  W[MAXNEURONSIN][MAXNEURONSX][MAXNEURONSY];  // The weight matrix
  double  Yout[MAXNEURONSX][MAXNEURONSY];   // The output layer neurons
  double  Yin[MAXNEURONSIN];            //The input layer neurons
  int     Lattice;                      //Square Vs triangular lattice
  int     YinSize;                      //input layer dimensions
  iPair   YoutSize;                     //outlayer dimensions

  int     R;                            //update neighborhood radius
  int     MaxEpoch;
  int     epoch;
  double  eta;                          //The learning rate
  double  delta_eta;                    //Amount to change l.r. each epoch
  double  Erosion;                      //Urban decay metric..Neighborhoods shrink
  int     StochFlg;                     //Present vectors in rand order if 1
  PATTERN *Pattern;

  int     LoadInLayer(int);             //pattern->input layer
  double  EucNorm(int, int);            //Calc Euclidean distance
  iPair   FindWinner();                 //get coords of winning neuron
  void    Train(iPair);
  void    AdaptParms();
public:
  SOFM();
  void SetPattern(PATTERN *);
  void SetParms(int, int, double);
  void PrintWeights();
  void PrintWinner();
  void RunTrn();
  void Run();
};

SOFM::SOFM(){
StochFlg=1;
Erosion=0;
}

void SOFM::SetPattern(PATTERN *p) {
   Pattern=p;
   YinSize=p->SizeVector;
}


void SOFM::SetParms(int X, int Y, double LR){
  int ix,iy,k;
YoutSize.x=X;
YoutSize.y=Y;
R=3;             
eta=LR;
delta_eta=0.005;
for (ix=0; ix<X; ix++) {
   for (iy=0; iy<Y; iy++) {
      for (k=0; k<YinSize; k++) {
         W[k][ix][iy]= (double)rand()/(10.0 * (double)RAND_MAX);
         } /* endfor */
      } /* endfor */
   } /* endfor */
}

int SOFM::LoadInLayer(int P){
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


void SOFM::AdaptParms(){
Erosion += .01;
if (Erosion>=1.0) {
   Erosion=0.0;
   if (R>0)
      R--;
   printf("New neighborhood.  Radius=%d", R);
   } /* endif */
if (epoch<500) {             //Reduce learning rate more slowly over 1st 1k epochs
   eta=eta-delta_eta/10.0;
   } 
 else {
   eta=eta-delta_eta;
   } /* endif */
if (eta<ETAMIN)
   eta=ETAMIN;
}

void  SOFM::PrintWeights() {
   int ix,iy,k;
for (ix=0; ix<YoutSize.x; ix++) {
   for (iy=0; iy<YoutSize.y; iy++) {
      for (k=0; k<YinSize; k++) {
         printf("W[%d][%d][%d]=%f  ",k,ix,iy,W[k][ix][iy]);
         } /* endfor */
         printf("\n");
      } /* endfor */
   } /* endfor */
}

void SOFM::RunTrn(){
int i,np;
iPair Winner;
epoch=0;
np=Pattern->NumPatterns;
while (epoch<=MAXEPOCHS){
   for (i=0; i<np; i++){
     LoadInLayer(i);
     Winner=FindWinner();
     Train(Winner);
     }
   if(20*(epoch/20)==epoch) {
     printf("\nEpoch=%d\n",epoch);
     PrintWeights();
     }
   epoch++;
   if (StochFlg)
     Pattern->ReShuffle(np);
   AdaptParms();
   }
}

void SOFM::Train(struct iPair Winner){
  int ix,iy,k;
for (ix=Winner.x-R; ix<=Winner.x+R; ix++){
  if ((ix>=0) && (ix<YoutSize.x)){
     for (iy=Winner.y-R; iy<=Winner.y+R; iy++){
       if ((iy>=0) && iy<YoutSize.y) {
          for (k=0; k<YinSize; k++){
            W[k][ix][iy]=W[k][ix][iy]+eta*(Yin[k]-W[k][ix][iy]);
            } /*endfor*/
          } /*endif*/
       } /*endfor*/
     } /*endif*/
  } /*endfor*/
}

iPair  SOFM::FindWinner(){
  int ix,iy;
  double d,best;
  iPair Winner;
best=1.0e99;
Winner.x=-1;
Winner.y=-1;
for (ix=0; ix<YoutSize.x; ix++){
  for (iy=0; iy<YoutSize.y; iy++){
    d=EucNorm(ix,iy);
    if (d<best) {
       best=d;
       Winner.x=ix;
       Winner.y=iy;
       } // endif
    } // endfor
  } // endfor
return Winner;
}

double SOFM::EucNorm(int x, int y){   // Calc Euclidean norm of vector dif
int i;
double dist;
dist=0;
for (i=0; i< YinSize;i++){
   dist += (W[i][x][y]-Yin[i]) * (W[i][x][y]-Yin[i]);
   } /* endfor */
dist=sqrt(dist);
return dist;
}

//=================================================================
// GLOBAL OBJECTS
//=================================================================

PATTERN InPat;
SOFM    FMap;

main(int argc, char *argv[]) {
if (argc>1) {
   InPat.GetPatterns(argv[1]);   //Establish pattern
   FMap.SetPattern(&InPat);      //Inform the feature map about the pattern
   FMap.SetParms(5,5,0.900);     //Init fm parms
   FMap.RunTrn();                //Run the FM w/ training enabled
   }
 else {
   printf("USAGE: SOFM PATTERN_FILE");
   }
}
