/****************************************************************************
*                                                                           *
*  ALOPEX                                                                   *
*                                                                           *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

// FUNCTION PROTOTYPES

void   ShowResults(int, long int,double temp, double alpha, double eta);

// DEFINES

#define MAXLAYERS    4         // MAX NUMBER OF LAYERS IN NET (IN OUT & HIDDEN)
#define MAXNEURONS  30         // MAX NUMBER OF NEURONS PER LAYER
#define MAXPATTERNS 20         // MAX NUMBER OF PATTERNS IN A TRAINING SET
#define MAXPREV      3         // NUMBER OF PREV EPOCH FOR WHICH WEIGHTS ARE MAINTAINED
#define ARCGRAN    250         // ARCHIVE GRANULARITY
#define NONE         0         // DO NOT ARCHIVE ERROR DATA
#define ALL          1         // ARCHIVE ALL ERROR DATA FOR EACH ITERATION
#define AVERAGE      2         // ARCHIVE AVERAGE ERROR DATA FOR EACH EPOCH
#define TRUE         1
#define FALSE        0

// ------------------------------------------------------------------------


class ALOPEX
{
private:
  double W[MAXLAYERS][MAXNEURONS][MAXNEURONS];      // WEIGHTS MATRIX
  double Wprev1[MAXLAYERS][MAXNEURONS][MAXNEURONS]; // previous WEIGHTS for correlation
  double Neuron[MAXLAYERS][MAXNEURONS];             // Output of all net neurons
  double ERROR[MAXPATTERNS][MAXNEURONS];            // Stored error over epoch/outlayer
  double AvgErr;

// Alopex specific data
  double delta;               // The Alopex step size
  double T;                   // Temperature for Alopex probability fn
  double Ep1;                 // Sum error over iteration n-1
  int AnnealCount;
  double SumDELTAc;

// Topology
  int NumLayers;              // Number of layers
  int OutLayerIndx;           // array index of last layer
  int LayerSize[MAXLAYERS];   // Number of neurons in the each layer
  int NumWeights;             // Tot number of weights

// Pattern data
  double InPattern[MAXPATTERNS][MAXNEURONS]; // Input values for each pattern
  double Desired[MAXPATTERNS][MAXNEURONS];   // desired value for each
                                             //   pattern/output
  unsigned long int CurrIter;                // Current  iterations number.
  long int Epoch;                            // Counts number of epochs
  int EpochFlag;                             // True at end of each epoch
  int NumPatterns;                           // Total patterns in training set
  int CurrPat;                               // Current pattern used in training
  int ConvCount;                             // The number of consecutive
                                             // patterns within tolerance
  int ConvergeFlg;                           // Flag indicates convergance has
                                             // occurred

// PARMS
  double Qzero;              // For Neuron activation function
  double ERRTOL;             // min Error tolerance required for convergence
  double ETA;                // ALOPEX Version of learning rate
  unsigned long int MAXITER; // Max iterations to do before stopping

// PRIVATE METHODS
  double ErrFunc(double Target, double Actual);  // Calc the log error
  double CalcSumErr();       // Calc tot err over all patterns/outlayer neurons
  void   RecordErrors();     // At each iter, record error results
  void   ArchivePut();       // Keep a record on disk of net progress

public:
  ALOPEX(void);
  void   GetTrnSet(char *Fname);  // Load training set from file
  void NextPat();
  void   GetInputs(void);         // Load input layer w/ curr pattern
  void   RunNet(void);            // Run the networks forward pass
  void   GetParms(char *);        // Load parameters from parm file
  double Sigmoid(double Net, double Tempr); // The non-linear squashing function
  void   SetRandomWeights(void);  // Init weights to random values
  int    IsConverged(void);       // Check for convergence
  void   AdaptWeights(void);      // Modify weights by ALOPEX method
  void   SaveWeights(char *);     // Save trained weights to file
  int    train(char *, char *);   // Top level control of training the net
  long int QueryEpoch(){return Epoch;}
  double QueryQzero(){return Qzero;}
};



// MISC FLAGS
int ArchOn  = AVERAGE;      // Set to 1= ALL, NONE, AVERAGE or WORST to control
                            //   data sent to ARCHIVE file for graphical
                            //   analysis
FILE *ARCHIVE;              // Archive Training sequence



// ------------------------------------------------------------------------


// METHOD DEFINITIONS


ALOPEX::ALOPEX() {
  AvgErr   = 0.0;
  CurrIter=0;
  Epoch=0;
  AnnealCount=0;
  CurrPat = 0;                          // Current pattern used in training
  ConvCount=0;
  ConvergeFlg=FALSE;                     // Flag indicates convergance
  SumDELTAc=0.0;
  ETA=2.0;
  EpochFlag=FALSE; 
}

/**************************************************************************
* Function GetTrnSet                                                      *
*     Load training set                                                   *
**************************************************************************/

void ALOPEX::GetTrnSet(char *Fname) {     // for small training sets
FILE  *PFILE;
int    x;
int    pat,i,j;
double inVal;

PFILE = fopen(Fname,"r");    // batch
if (PFILE==NULL){
   printf("\nUnable to open file \n");
   exit(0);
   }
fscanf(PFILE,"%d",&NumPatterns);

for (pat=0; pat<NumPatterns; pat++) {
   for (i=0; i<LayerSize[0]; i++) {
      fscanf(PFILE,"%lf",&inVal);
      InPattern[pat][i]=inVal;
      } /* endfor */

   // Now get desired / expected values
   for (i=0; i<LayerSize[OutLayerIndx]; i++) {
      fscanf(PFILE,"%lf",&inVal);
      Desired[pat][i]=inVal;
      } /* endfor */
   } /* endfor */
fclose(PFILE);
}


/******************************************************************************
*                                                                             *
* Function GetParms                                                           *
*     Loads topology from file spec'd file if avail.                          *
*     otherwise tries DEFAULT.PRM                                             *
*                                                                             *
******************************************************************************/


void ALOPEX::GetParms(char *PrmFileName){
FILE *PRMFILE;
PRMFILE = fopen(PrmFileName,"r");    // batch
if (PRMFILE==NULL){
   printf("\nUnable to open Parameter file: %s \n",PrmFileName);
   printf("\nAttempting to open default file: PARMS1");
   PRMFILE = fopen("PARMS1","r");
   if (PRMFILE==NULL){
      printf("\nUnable to open Parameter file\n");
      exit(0);
      }
   }
printf("\nLoading Parameters from file: %s\n",PrmFileName);
fscanf(PRMFILE,"%lf",&Qzero);
fscanf(PRMFILE,"%lf",&ETA);
fscanf(PRMFILE,"%lf",&delta);
fscanf(PRMFILE,"%lf",&T);
fscanf(PRMFILE,"%ld",&MAXITER);
fscanf(PRMFILE,"%lf",&ERRTOL);
fscanf(PRMFILE,"%d",&NumLayers);

printf("&Qzero=%lf",Qzero);
printf("&delta=%lf",delta);
printf("T=%lf",T);
printf("MAXITER=%ld",MAXITER);
printf("ERRTOL=%lf",ERRTOL);

printf("\nNumber of layers=%d\n",NumLayers);
for (int i=0; i<NumLayers; i++) {
   fscanf(PRMFILE,"%d",&LayerSize[i]);
   printf("Number of neurons in layer %d = %d\n",i,LayerSize[i]);
   }
OutLayerIndx = NumLayers-1;         // accomodate 0 org'd arrays
fclose(PRMFILE);
                    
NumWeights=0;
for (int lyr=OutLayerIndx; lyr>0; lyr--)                //Visit each layer
   NumWeights += LayerSize[lyr] *  LayerSize[lyr-1];
printf("\n%d\n",NumWeights);
}


void ALOPEX::SetRandomWeights(){
int i,j,k;
double zWT;
double x;
   //srand(6);
   srand(5);
   for (i=1; i<NumLayers; i++) {
      for (k=0; k<LayerSize[i]; k++) {
         for (j=0; j<=LayerSize[i-1]; j++) {   //  One extra for bias neuron
            zWT=(double)rand();
            zWT=zWT/16.0;       
            x=(double)rand();
            x=x/32767;
            if (x>0.5) {
               zWT=-zWT;
            } else {
            } /* endif */
            W[i][j][k] =zWT/32767.0;
            printf("\nW(%d,%d,%d)%lf\n",i,j,k,W[i][j][k]);
            }
         }
      }
}

void ALOPEX::NextPat(){
EpochFlag=FALSE;
CurrIter++;
CurrPat++;                                // Update the current pattern
if (CurrPat>=NumPatterns){
   EpochFlag=TRUE;
   CurrPat=0;
   Epoch++;
   }
}


/******************************************************************************
* FUNCTION GetInputs                                                          *
*                                                                             *
*     Loads input layer neurons with current pattern                          *
******************************************************************************/

void ALOPEX::GetInputs(){
int i,j,k;

for (i=0; i<LayerSize[0]; i++) {
    Neuron[0][i]=InPattern[CurrPat][i];   // Show it to the neurons
    }
}


/******************************************************************************
* FUNCTION RunNet                                                             *
*                                                                             *
*     Calculates outputs for all network neurons                              *
******************************************************************************/

void ALOPEX::RunNet(){
int lyr;     // layer to calculate
int dNeuron; // dest layer neuron
int sNeuron; // src layer neuron
double SumNet;
double out;

for (lyr=1; lyr<NumLayers; lyr++) {
   Neuron[lyr-1][LayerSize[lyr-1]]=1.0; //force bias neuron output to 1.0
   for (dNeuron=0; dNeuron<LayerSize[lyr]; dNeuron++) {
      SumNet=0.0;
      for (sNeuron=0; sNeuron <= LayerSize[lyr-1]; sNeuron++) {  //add 1 for bias
         SumNet += Neuron[lyr-1][sNeuron] * W[lyr][sNeuron][dNeuron];
         }
      out=Sigmoid(SumNet,Qzero);
      Neuron[lyr][dNeuron] = out;
      }
   }
}


/******************************************************************************
******************************************************************************/

void ALOPEX::RecordErrors(){
    int j;
    double x;
for (j=0; j<LayerSize[OutLayerIndx]; j++) {
   ERROR[CurrPat][j] = ErrFunc(Desired[CurrPat][j], Neuron[OutLayerIndx][j]);
   if ((ARCGRAN*(Epoch/ARCGRAN)) == Epoch) {
      x=ERROR[CurrPat][j];
      printf("Pattern: %d neuron[%d]=%lf / %lf ERROR= %lf\n",
              CurrPat,j, Neuron[OutLayerIndx][j],Desired[CurrPat][j],x);
      }

   } /* endfor */
}

/******************************************************************************
* IsConverged                                                                 *
*     Calculates error for each neuron and each pattern                       *
******************************************************************************/


int  ALOPEX::IsConverged(){
double dNETj;
double SumErr;             //Cumulative error
int  i, j;
int LocalConvFlg=TRUE;

SumErr=CalcSumErr();
if (SumErr>ERRTOL) {
     return FALSE;
  } else {
     return TRUE;
     } /* endif */
}


/******************************************************************************
******************************************************************************/

void  ALOPEX::ArchivePut(){
int  i, j;

//printf("\n");
AvgErr =CalcSumErr()/NumPatterns;

if (ArchOn==AVERAGE) {
   if ((ARCGRAN*(Epoch/ARCGRAN)) == Epoch) { // only save ARCGRANth epochs
      fprintf(ARCHIVE,"%ld %lf\n",Epoch,AvgErr );
      printf("\nEpoch:%d ",Epoch);
      printf("Avg=%lf\n",AvgErr);
      } /* endif */
   }
}


/******************************************************************************
******************************************************************************/

double ALOPEX::ErrFunc(double Target, double Actual) {
   double E;

//------------------------------------------------------------
// Uncomment  this section to use log error function
//if (Target>=.99) {
//    E=log(1/Actual);
//    }
//  else {
//    E=log(1/(1-Actual));
//    } /* endif */
//------------------------------------------------------------


// Absolute error function
E=sqrt((Target-Actual)*(Target-Actual));

//------------------------------------------------------------
// Uncomment  this section to use square error function
//E=(Target-Actual)*(Target-Actual);
//------------------------------------------------------------

return E;
}


/******************************************************************************
******************************************************************************/
double ALOPEX::CalcSumErr(){
   int j,Pat;
   double E,desire;
E=0.0;
for (Pat=0;Pat<NumPatterns ; Pat++) {
   for (j=0; j<LayerSize[OutLayerIndx]; j++) {
      E += ERROR[Pat][j];
      }
   } /* endfor */
return E;
}

void ALOPEX::AdaptWeights(){
double E,R,P, DELTAc;
double DELTAWEIGHT, DELTAERROR;
int lyr, i, j,k;

E=CalcSumErr();
DELTAERROR=E-Ep1;
Ep1=E;                              //Prev iter errors
for (lyr=OutLayerIndx; lyr>0; lyr--) {               // Visit each layer
   for (j=0; j<LayerSize[lyr]; j++) {                // Visit each neuron
      for (k=0; k<=LayerSize[lyr-1];k++ ) {          // Visit all Weights (incl. bias)
        DELTAWEIGHT= W[lyr][j][k]-Wprev1[lyr][j][k];
        DELTAc= DELTAWEIGHT*DELTAERROR;   //Calculate the correlation
        SumDELTAc+=fabs(DELTAc);                        //Running sum of correlation over all weights
        Wprev1[lyr][j][k]=W[lyr][j][k];
        if (Epoch > 1) {                          //Wait till system is primed
           P = 1/(1 + exp(ETA*DELTAc/T));                   //Probability fn once it is 
           }
         else
           P= 0.5;                                   //50% till then
        R=(double)rand();
        R=R/32767.0;
        if (R>P) {                                  
           W[lyr][j][k]=W[lyr][j][k] - delta;
           }
         else {
           W[lyr][j][k]=W[lyr][j][k] + delta;
           } /* endif */
        } /* endfor */
      } /* endfor */
   } /* endfor */

//Establish a new temp for the alopex probability fn base on avg correlation
if ((AnnealCount>= 1)&&(SumDELTAc>0.0)) {
   if (SumDELTAc==10) {
       printf("\nWarning SumDeltaC =0\n");
       }
   T=SumDELTAc/ AnnealCount;
   AnnealCount=0;
   SumDELTAc=0.0;
   } else {
   AnnealCount++;
   } /* endif */
}


/******************************************************************************
* FUNCTION SaveWeights                                                        *
*                                                                             *
*     Output weights to default file DFLT.WGT                                 *
******************************************************************************/

void   ALOPEX::SaveWeights(char *WgtName) {
int lyr,s,d;
double zWT;
FILE *WEIGHTFILE;

   WEIGHTFILE = fopen(WgtName,"w");
   if (WEIGHTFILE==NULL){
      printf("Unable to open weight file for output:%s\n",WgtName);
      exit(0);
      }
   printf("SAVING CALCULATED WEIGHTS:\n\n");
   fprintf(WEIGHTFILE,"0.00\n");                 // Threshold always 0
   fprintf(WEIGHTFILE,"%lf\n",Qzero);            // Temperature
   fprintf(WEIGHTFILE,"%d\n",NumLayers);         // Number of layers
   for (lyr=0; lyr<NumLayers; lyr++) {           // Save topology
      fprintf(WEIGHTFILE,"%d\n",LayerSize[lyr]); // Number of neurons/layer
      }
   for (lyr=1; lyr<NumLayers; lyr++) {           // Start at 1st hidden
      for (d=0; d<LayerSize[lyr]; d++) {
         for (s=0; s<=LayerSize[lyr-1]; s++) {   // One extra for bias
            zWT=W[lyr][s][d];
            fprintf(WEIGHTFILE,"%lf\n",zWT);
            }
         }
      }
   fclose(WEIGHTFILE);
}



/******************************************************************************
* FUNCTION Sigmoid                                                            *
*                                                                             *
*     Output non-linear squashing function                                    *
******************************************************************************/

double ALOPEX::Sigmoid(double Net, double Tempr){
   double x;
x = Net/Tempr;
if ( x >100.0)
   return 1.0;
if ( x < -100.0)
   return 0.0;
return 1.0/(1.0 + exp(-x));
}


/******************************************************************************
* FUNCTION train                                                              *
*     Trains the network                                                      *
*       Input: Training data file name and Parameter file name                *
*       Output:non-linear squashing function                                  *
******************************************************************************/

int    ALOPEX::train(char *TrnFname, char *ParmFname){
if (ArchOn) ARCHIVE=fopen("archive.lst","w");
GetParms(ParmFname);
GetTrnSet(TrnFname);
SetRandomWeights();
int Converged=0;
while ((!Converged) && (CurrIter < MAXITER) ) {
   GetInputs();
   RunNet();
   RecordErrors();
   if (CurrPat==(NumPatterns-1)) {           // Test for full epoch
      ArchivePut();
      Converged=IsConverged();
      AdaptWeights();
      }
   NextPat();
   }
if (ArchOn) fclose(ARCHIVE);
return Converged;
}


//-----------------------------------------------------------------------------


/******************************************************************************
* FUNCTION ShowResults                                                        *
*                                                                             *
*     Output Summary specific to the parity-3 problem                         *
******************************************************************************/

void ShowResults(int ConvergeFlg, long int CurrEpoch, double temp){
printf("\n----------------------------------------------------------\n");
if (ConvergeFlg) {
   printf("SUCCESS: Convergance has occured at iteration %ld\n",CurrEpoch);
   }
  else {
   printf("FAILURE: Convergance has NOT occured!!\n");
   } // endif
printf("Temperature = %lf\n",temp);
printf("\n----------------------------------------------------------\n");
}



ALOPEX  Alopex;

/******************************************************************************
*  MAIN                                                                       *
******************************************************************************/


int main(int argc, char *argv[])
{
int Converged ;

if (argc>3) {
   Converged = Alopex.train(argv[1],argv[2]);
   }
 else {
   printf("USAGE: ALOPEX TRAINING_FILE PARMS_FILE WEIGHT_FILE\n");
   exit(0);
   }

// Show how we did
ShowResults(Converged, Alopex.QueryEpoch(), Alopex.QueryQzero());
if (Converged)
   Alopex.SaveWeights(argv[3]);   // Save the weights for later use

return 0;
}
