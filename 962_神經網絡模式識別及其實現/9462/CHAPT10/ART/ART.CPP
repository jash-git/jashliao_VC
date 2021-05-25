
/****************************************************************************
*                                                                           *
*  ADAPTIVE RESONANCE THEORY (ART)  NETWORK                                 *
*                                                                           *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>


// DEFINES
#define MAXCNEURONS 75      // MAX COMPARISON LAYER NEURONS
#define MAXRNEURONS 30      // MAX RECOGNITION LAYER NEURONS
#define MAXPATTERNS 30      // MAX NUMBER OF PATTERNS IN A TRAINING SET
#define VERBOSE     1


class ARTNET
{
private:
  double Wb[MAXCNEURONS][MAXRNEURONS];    // Bottom up weight matrix
  int    Wt[MAXRNEURONS][MAXCNEURONS];    // Top down  weight matrix
  int    InData[MAXPATTERNS][MAXCNEURONS];// Array of input vectors to be
                                          // presented to the network
  int    NumPatterns;                     // Number of input patterns
  double VigilThresh;                     // Vigilence threshold value
  double L;                               // ART training const (see text)
  int    M;                               // # of neurons in C-layer
  int    N;                               // # of neurons in R-layer
  int    XVect[MAXCNEURONS];              // Current in vect at C-layer.
  int    CVect[MAXCNEURONS];              // Output vector from C-layer
  int    BestNeuron;                      // Current best R-layer Neuron
  int    Reset;                           // Active when vigilence has
                                          //      disabled someone
  int    RVect[MAXCNEURONS];              // Output vector from R-layer
  int    PVect[MAXCNEURONS];              // WeightedOutput vector from R-layer
  int    Disabled[MAXRNEURONS];           // Resets way of disqualifying neurons
  int    Trained[MAXRNEURONS];            // To identify allocated R-Neurons
  void   ClearPvect();
  void   ClearDisabled();
  void   RecoPhase();                     // Recognition phase
  void   CompPhase();                     // Comparison phase
  void   SearchPhase();                   // Search Phase
  void   RunCompLayer();                  // Calc comparison layer by 2/3 rule
  void   RunRecoLayer();                  // Calc recognition layers R-vect
  void   Rvect2Pvect(int);                // Distribute winners result
  int    Gain1();                         // Comp layer gain
  int    Gain2();                         // Reco layer gain
  double Vigilence();                     // Calc vigilence metric
  void   InitWeights();                   // Initialize weights
  void   Train();                         // Weight adjustment is done here
public:
  ARTNET(void);                           // Constructor/initializations
  int    LoadInVects(char *Fname);        // load all data vectors
  void   Run(int i);                      // Run net w/ ith pattern
  void   ShowWeights();                   // display top down and 
                                          //   bottom up weights
  void   ShowInVect();                    // Display current input pattern
  void   ShowOutVect();                   // P-vector from Reco layer(see text)
};
 
// ------------------------------------------------------------------------


// METHOD DEFINITIONS

ARTNET::ARTNET(){
int i;
L=2.0;
N=MAXRNEURONS;
for (i=0; i<N; i++) {        //Set all neurons to untrained and enabled
   Trained[i]=0;
   Disabled[i]=0;
   } /* endfor */
}


int  ARTNET::LoadInVects(char *Fname){
FILE  *PFILE;
int   i,j,k;

PFILE = fopen(Fname,"r");    
if (PFILE==NULL){
   printf("\nUnable to open file %s\n",Fname);
   exit(0);
   }
fscanf(PFILE,"%d",&NumPatterns);  //How many patterns
fscanf(PFILE,"%d",&M);            //get width of input vector
fscanf(PFILE,"%lf",&VigilThresh);
for (i=0; i<NumPatterns; i++) {
   for (j=0; j<M; j++) {
      fscanf(PFILE,"%d",&k);      //Read all the pattern data and...

      InData[i][j]=k;             //  ...save it for later.
      } /* endfor */
   } /* endfor */
InitWeights();
return NumPatterns;
}

int ARTNET::Gain2(){
   int i;
for (i=0; i<M; i++) {
   if (XVect[i]==1) 
      return 1;
   } /* endfor */
}


void ARTNET::Rvect2Pvect(int best){
   int i;
for (i=0; i<M; i++) {
   PVect[i]= Wt[best][i];                     
   } /* endfor */
}

int ARTNET::Gain1(){
   int i,G;
G=Gain2();
for (i=0; i<M; i++) {
   if (RVect[i]==1)
      return 0;
   } /* endfor */
return G;
}

void ARTNET::RunCompLayer(){
   int i,x;
for (i=0; i<M; i++) {
   x=XVect[i]+Gain1()+PVect[i];
   if (x>=2) {
      CVect[i]=1;
      }
    else {
      CVect[i]=0;
      } /* endif */
   } /* endfor */
}

double  ARTNET::Vigilence(){
   int i;
   double S,K,D;
// count # of 1's in p-vect & x-vect
K=0.0;
D=0.0;
for (i=0; i<M; i++) {
   K+=CVect[i];
   D+=XVect[i];
   } /* endfor */
S=K/D;
return S;
}

void ARTNET::RunRecoLayer(){
   int i,j,k;
   double Net[MAXRNEURONS];
   int BestNeruon=-1;
   double NetMax=-1;
for (i=0; i<N; i++) {       //Traverse all R-layer Neurons
   Net[i]=0;
   for (j=0; j<M; j++) {    // Do the product
      Net[i] +=Wb[i][j]*CVect[j];
      } /* endfor */
   if ((Net[i]>NetMax) && (Disabled[i]==0)) { //disabled neurons cant win!
      BestNeuron=i;
      NetMax=Net[i];
      }
   } /* endfor */
for (k=0; k<N; k++) {
   if (k==BestNeuron)
      RVect[k]=1;           // Winner gets 1
    else
      RVect[k]=0;           // lateral inhibition kills the rest
   } /* endfor */
}

void   ARTNET::RecoPhase(){
   int i;
//First force all R-layer outputs to zero
for (i=0; i<N; i++) {
   RVect[i]=0;
   } /* endfor */
for (i=0; i<M; i++) {
   PVect[i]=0;
   } /* endfor */
//Now Calculate C-layer outputs
RunCompLayer();       //C-vector now has the result
RunRecoLayer();       //Calc dot prod w/ bot up weight & C
Rvect2Pvect(BestNeuron);
}

void   ARTNET::CompPhase(){
   double S;
RunCompLayer();       //Cvector<-dif between  x & p
S=Vigilence();
if (S<VigilThresh){
   Reset=1;
   RVect[BestNeuron]=0;
   Disabled[BestNeuron]=1;
   }
 else
   Reset=0;
}

void   ARTNET::SearchPhase(){
   double S;
while (Reset) {
   ClearPvect();                                                  
   RunCompLayer();          //Xvect -> Cvect
   RunRecoLayer();          //Find a new winner with prev winners disabled
   Rvect2Pvect(BestNeuron); //new pvect based on new winner
   S=Vigilence();           //calc vigilence for the new guy
if (S<VigilThresh){         //check if he did ok
   Reset=1;                 //     if not disable him too
   RVect[BestNeuron]=0;
   Disabled[BestNeuron]=1;
   }
 else
   Reset=0;           //Current Best neuron is a good winner...Train him
   } /* endwhile */
if (BestNeuron!=-1) {
   Train();
   } 
 else {
   //Failed to allocate a neuron for current pattern.
   printf("Out of neurons in F2\n");
   } /* endif */
ClearDisabled();                                               
}

void ARTNET::ClearDisabled() {                                           
   int i;
for (i=0; i<M; i++) {
   Disabled[i]=0;
   } /* endfor */
}

void ARTNET::ClearPvect() {                                              
   int i;
for (i=0; i<M; i++) {
   PVect[i]=0;
   } /* endfor */
}

void ARTNET::Train(){
   int i,z=0;
for (i=0; i<M; i++) {
   z+=CVect[i];
   } /* endfor */
for (i=0; i<M; i++) {
   Wb[BestNeuron][i]=L*CVect[i]/(L-1+z);
   Wt[BestNeuron][i]=CVect[i];
   } /* endfor */
Trained[BestNeuron]=1;
}


void ARTNET::Run(int tp){
   int i,j;
  
ClearPvect();                                                  
for (i=0; i<M; i++) {
   XVect[i]=InData[tp][i];
   } /* endfor */
RecoPhase();
CompPhase();
SearchPhase();
}

void   ARTNET::InitWeights(){           // Initialize weights
   int i,j;                             
   double b;
for (i=0; i<N; i++) {                   // from R-neuron i
   for (j=0; j<M; j++) {                // to C-neuron j
      Wt[i][j]= 1;                      // All init'd to 1
      } /* endfor */
   } /* endfor */
b=L/(L-1+M);
for (i=0; i<N; i++) {                    // from C-neuron i
   for (j=0; j<M; j++) {                 // to R-neuron j
      Wb[i][j]= b;
      } /* endfor */
   } /* endfor */

}
void ARTNET::ShowWeights(){
   int i,j;
printf("\nTop Down weights:\n");
for (i=0; i<N; i++) {
   if(Trained[i]==1){
      for (j=0; j<M; j++) {
         printf("%d ",Wt[i][j]);
         } /* endfor */
      printf("\n");
      } /* endif */
   } /* endfor */
printf("\nBottom up weights:\n");
for (i=0; i<N; i++) {
   if(Trained[i]==1){
      for (j=0; j<M; j++) {
         printf("%f ",Wb[i][j]);
         } /* endfor */
      printf("\n");
      } /* endif */
   } /* endfor */
}

void ARTNET::ShowInVect(){
   int i;
printf("BEST NEURON:%d\nIN:  ",BestNeuron);
for (i=0; i<M; i++) {
   printf("%d ",XVect[i]);
   } /* endfor */
printf("\n");
}

void ARTNET::ShowOutVect(){
   int i;
printf("OUT: ");
for (i=0; i<M; i++) {
   printf("%d ",CVect[i]);
   } /* endfor */
printf("\n");
}

// ------------------------------------------------------------------------
ARTNET    ART;

/******************************************************************************
*  MAIN                                                                       *
******************************************************************************/


int main(int argc, char *argv[])
{
   int TstSetSize;
   int i;
if (argc>1) {
   TstSetSize=ART.LoadInVects(argv[1]);
   for (i=0; i<TstSetSize; i++) {
      ART.Run(i);                  //Evaluate ith test pattern
      printf("\n");
      ART.ShowInVect();
      ART.ShowOutVect();
      if (VERBOSE==1) ART.ShowWeights();
   } /* endfor */
   }
 else {
   printf("USAGE: ART PATTERN_FILE_NAME\n");
   exit(0);
   }


return 0;
}
