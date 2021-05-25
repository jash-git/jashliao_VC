#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include "utility.hpp"

// FUNCTION PROTOTYPES
void   GetInputs(void);
void   RunNet(void);
void   ShowResults(void);
void   GetParms(int, char *);
int    respondYN(void);
int    UserQueryYN(char *msg);
double ActivationFn(double Net, double Tempr);
double Sigmoid(double Net, double Tempr);
double StepFn(double Net);
void   SetRandomWeights(void);
void   LoadTrainingSet(char *Fname);
double HCalcDelta(int lyr,int j,double dNETj);
void   CalcErrors(void);
void   AdaptWeights(void);
void   SaveWeights(char *);


// DEFINES

#define MAXLAYERS    4         // MAX NUMBER OF LAYERS IN NET (IN OUT & HIDDEN)
#define MAXNEURONS 120         // MAX NUMBER OF NEURONS PER LAYER
#define MAXPATTERNS 80         // MAX NUMBER OF PATTERNS IN A TRAINING SET
#define SIGMOID      0         // Choose Squashing fn
#define STEPFN       1         // Choose Squashing fn
#define ARCGRAN      1         // ARCHIVE GRANULARITY
#define NONE         0         // DO NOT ARCHIVE ERROR DATA
#define ALL          1         // ARCHIVE ALL ERROR DATA FOR EACH ITERATION
#define AVERAGE      2         // ARCHIVE AVERAGE ERROR DATA FOR EACH EPOCH
#define WORST        3         // ARCHIVE WORST ERROR FOR EACH EPOCH
#define TRUE         1
#define FALSE        0
// ------------------------------------------------------------------------

// GLOBAL VARS

double W[MAXLAYERS][MAXNEURONS][MAXNEURONS];  // WEIGHTS MATRIX
double Wprev[MAXLAYERS][MAXNEURONS][MAXNEURONS];  // previous WEIGHTS for momentum
double Neuron[MAXLAYERS][MAXNEURONS];
double DELTAj[MAXLAYERS][MAXNEURONS];
double DELTA_Wij[MAXLAYERS][MAXNEURONS][MAXNEURONS];
double ERROR[MAXNEURONS];

double WorstErr = 0.0;
double AvgErr   = 0.0;
long int Epoch=0;

// Topology
int NumLayers;              // Number of layers
int OutLayerIndx;           // array index of last layer
int LayerSize[MAXLAYERS];   // Number of neurons in the each layer
int SelcActFn =SIGMOID;     // Activation fn selector
//int SelcActFn =STEPFN;

// Pattern data
double InPattern[MAXPATTERNS][MAXNEURONS];  // Input values for each pattern
double Desired[MAXPATTERNS][MAXNEURONS];    // desired value for each
                                            //   pattern/output
unsigned long int CurrIter;                 // Current  iterations number.
int NumPatterns;                            // Total patterns in training set
int CurrPat = -1;                           // Current pattern used in training
int ConvCount=0;                            // The number of consecutive
                                            // patterns within tolerance
int ConvergeFlg=FALSE;                      // Flag indicates convergance has
                                            // occurred


// PARMS
double Temperature;         // For sigmoid
double ETA;                 // Learning rate
double ALPHA;               // Momentum
double ERRTOL;              // min Error tolerance required for convergence
unsigned long int MAXITER;  // Max iterations to do before stopping


// MISC
//char prnCharRet = 0x0d;
int PrinterEcho =1;         // Set to 1= echo output to printer 0= no echo
int DebugOn =0;             // Set to 1= debug outputs on 0= no debug outputs
int ArchOn  = AVERAGE;      // Set to 1= ALL, NONE, AVERAGE or WORST to control
                            // data sent to ARCHIVE file for  analysis
FILE *FPRN;                 // Terminal echo subset
FILE *ARCHIVE;              // Archive Training sequence



// ------------------------------------------------------------------------


// FUNCTION DEFINITIONS


#include "load.hpp"


double QueryUserFloat(char *msg){
double rv;
printf("Enter %s ==> \n",msg);
scanf("%lf",&rv);
return rv;
}

unsigned long int QueryUserLong(char *msg){
unsigned long int rv;
printf("Enter %s ==> \n",msg);
scanf("%ld",&rv);
return rv;
}

void pause(){
printf("PAUSING\n");
for (int i=0; i<32000; i++) {
   } /* endfor */
}


/******************************************************************************
* Function GetParms                                                           *
*     Asks if network topology  will be provided from file or keyboard        *
*     Loads topology from file DEFAULT.PRM                                    *
*       - OR -                                                                *
*     Prompts for all parameters                                              *
******************************************************************************/

void GetParms2(){
char PrmFileName[30];
FILE *PRMFILE;
int i;
int rv=-1;
int rv2=-1;

PRMFILE = fopen("PARMS1","r");  // open the default file
      if (PRMFILE==NULL){
         printf("\nUnable to open Parameter file\n"); //warn but no exit
         }
       else {
         fscanf(PRMFILE,"%lf",&Temperature);
         fscanf(PRMFILE,"%lf",&ETA);
         fscanf(PRMFILE,"%lf",&ALPHA);
         fscanf(PRMFILE,"%ld",&MAXITER);
         fscanf(PRMFILE,"%lf",&ERRTOL);
         fscanf(PRMFILE,"%d",&NumLayers);
         printf("\nNumber of layers=%d\n",NumLayers);
         for (i=0; i<NumLayers; i++) {
            fscanf(PRMFILE,"%d",&LayerSize[i]);
            printf("Number of neurons in layer %d = %d\n",i,LayerSize[i]);
            }
         fclose(PRMFILE);
         }
while (rv!=8) {
   switch (rv=menu(0)) {
      case 1:
         printf("\nCurrent Temperature is: %lf\n",Temperature);
         Temperature=QueryUserFloat("New Temperature");
         printf("\nNew Temperature is: %lf\n",Temperature);
         pause();
         break;
      case 2:
         printf("\nCurrent ETA is: %lf\n",ETA);
         ETA=QueryUserFloat("New ETA");
         printf("\nNew ETA is: %lf\n",ETA);
         pause();
         break;
      case 3:
         printf("\nCurrent ALPHA is: %lf\n",ALPHA);
         ALPHA=QueryUserFloat("New ALPHA");
         printf("\nNew ALPHA is: %lf\n",ALPHA);
         pause();
         break;
      case 4:
         printf("\nCurrent Iteration limit is: %ld\n",MAXITER);
         MAXITER=QueryUserLong("New Iteration limit");
         printf("\nNew Iteration limit is: %ld\n",MAXITER);
         pause();
         break;
      case 5:                //ERRTOL
         printf("\nCurrent Error tolerance is: %lf\n",ERRTOL);
         ERRTOL=QueryUserFloat("New Iteration limit");
         printf("\nNew Error tolerance is: %lf\n",ERRTOL);
         pause();
         break;
      case 6:
         printf("\nParameter file Name: \n");
         scanf("%s",PrmFileName);
         PRMFILE = fopen(PrmFileName,"r");
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
         fscanf(PRMFILE,"%lf",&Temperature);
         fscanf(PRMFILE,"%lf",&ETA);
         fscanf(PRMFILE,"%lf",&ALPHA);
         fscanf(PRMFILE,"%ld",&MAXITER);
         fscanf(PRMFILE,"%lf",&ERRTOL);
         fscanf(PRMFILE,"%d",&NumLayers);
         printf("\nNumber of layers=%d\n",NumLayers);
         for (i=0; i<NumLayers; i++) {
            fscanf(PRMFILE,"%d",&LayerSize[i]);
            printf("Number of neurons in layer %d = %d\n",i,LayerSize[i]);
            }
         fclose(PRMFILE);
         pause();
         break;
      case 7:  // topology
         rv2=-1;
         while (rv2 != 3) {
            switch (rv2=menu(1)) {
               case 1:
                  printf("\nEnter number of layers ==>\n");
                  scanf("%d",&NumLayers);
                  printf("Number of layers=%d\n",NumLayers);
                  pause();
                  break;
               case 2:
                  if ((NumLayers>0) && (NumLayers<MAXLAYERS)) {
                     for (i=0; i<NumLayers; i++) {
                        printf("\nEnter number neurons in layers %d ==>\n",i);
                        scanf("%d",&LayerSize[i]);
                        }
                     }
                   else {
                     printf("ERROR: Number of layers (%d) invalid\n",NumLayers);
                     }
                  pause();
                  break;
               default:;
               } /* endswitch */
            }
         break;
      case 8:
         if (PrinterEcho) {
            fprintf(FPRN,"USER MENU SELECTIONS:\n\n");
            fprintf(FPRN,"Temperature = %lf\n",Temperature);
            fprintf(FPRN,"ETA         = %lf\n",ETA        );
            fprintf(FPRN,"ALPHA       = %lf\n",ALPHA      );
            fprintf(FPRN,"MAXITER     = %ld\n",MAXITER    );
            fprintf(FPRN,"ERRTOL      = %lf\n",ERRTOL     );
            fprintf(FPRN,"Number of layers=%d\n\n",NumLayers);
            for (i=0; i<NumLayers; i++) {
               fprintf(FPRN,"Number of neurons in layer %d = %d\n",
                                                                i,LayerSize[i]);
               }
            fprintf(FPRN,"\n");
            }
         //pause();
         break;
      default:;
      } /* endswitch */
   }
OutLayerIndx = NumLayers-1;         // accomodate 0 org'd arrays
system("cls");
if (PrinterEcho) fprintf(FPRN,"\n\n");
}


void GetParms(int i,char *PrmFileName){
FILE *PRMFILE;
if (i==0) {
   GetParms2();                         // interactive
   }
  else {
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
   fscanf(PRMFILE,"%lf",&Temperature);
   fscanf(PRMFILE,"%lf",&ETA);
   fscanf(PRMFILE,"%lf",&ALPHA);
   fscanf(PRMFILE,"%ld",&MAXITER);
   fscanf(PRMFILE,"%lf",&ERRTOL);
   fscanf(PRMFILE,"%d",&NumLayers);
   printf("\nNumber of layers=%d\n",NumLayers);
   for (i=0; i<NumLayers; i++) {
      fscanf(PRMFILE,"%d",&LayerSize[i]);
      printf("Number of neurons in layer %d = %d\n",i,LayerSize[i]);
      }
   OutLayerIndx = NumLayers-1;         // accomodate 0 org'd arrays
   fclose(PRMFILE);
   pause();
   } /* endif */
}

/******************************************************************************
* FUNCTION SetRandomWeights                                                   *
*                                                                             *
*     Initializes weigght matrix to small random values                       *
*                                                                             *
******************************************************************************/

void SetRandomWeights(){
int i,j,k;
double zWT;
   //randomize();
   srand(6);
   printf("Initial Randomized weights:\n\n");
   for (i=1; i<NumLayers; i++) {
      for (k=0; k<LayerSize[i]; k++) {
         for (j=0; j<=LayerSize[i-1]; j++) {   //  One extra for bias neuron
            zWT=(double)rand();
            zWT=zWT/2.0;
            W[i][j][k] =zWT/65536.0;  // random weight normalized to [0,0.2]
            Wprev[i][j][k]=0;;
            printf("W(%d,%d,%d)=%lf ",i,j,k,W[i][j][k]);
            if (PrinterEcho)
              fprintf(FPRN,"W(%d,%d,%d)=%lf\n",i,j,k,W[i][j][k]);
            }
         printf("\n");
         if (PrinterEcho) fprintf(FPRN,"\n");
         }
      }
}


int respondYN(){
char c;

c=getch();
if ((c=='y') || (c=='Y')) {
   printf("Y\n");
   return 1;   // return true for yes
   }
 else {
   printf("N\n");
   return 0;   // return false for no
   }
}

int UserQueryYN(char *msg){
int i;
printf("%s (y/n) ==> \n",msg);
i=respondYN();
return i;
}

void GetInputs(){
int i;
CurrIter++;
CurrPat++;                                // Update the current pattern
if (CurrPat>=NumPatterns){
   CurrPat=0;
   Epoch++;
   }
for (i=0; i<LayerSize[0]; i++) {
    Neuron[0][i]=InPattern[CurrPat][i];   // Show it to the neurons
    }
}


/******************************************************************************
* FUNCTION RunNet                                                             *
*                                                                             *
*     Calculates outputs for all network neurons                              *
******************************************************************************/

void RunNet(){
int lyr;     // layer to calculate
int dNeuron; // dest layer neuron
int sNeuron; // src layer neuron
double SumNet;
double out;

if (PrinterEcho && DebugOn){ fprintf(FPRN,"Iteration=%ld\n",CurrIter);}
for (lyr=1; lyr<NumLayers; lyr++) {
   Neuron[lyr-1][LayerSize[lyr-1]]=1.0; //force bias neuron output to 1.0
   for (dNeuron=0; dNeuron<LayerSize[lyr]; dNeuron++) {
      SumNet=0.0;
      for (sNeuron=0; sNeuron <= LayerSize[lyr-1]; sNeuron++) {  //add 1 for bias
         SumNet += Neuron[lyr-1][sNeuron] * W[lyr][sNeuron][dNeuron];
         if (PrinterEcho && DebugOn){
            fprintf(FPRN,"->Neuron[%d][%d]=%lf \n",
                       lyr-1, sNeuron,Neuron[lyr-1][sNeuron]);
            fprintf(FPRN,"->W[%d][%d][%d]=%lf \n",
                       lyr, sNeuron,dNeuron,W[lyr][sNeuron][dNeuron]);
            }
         }
      out=ActivationFn(SumNet,Temperature);
      Neuron[lyr][dNeuron] = out;
      if (PrinterEcho && DebugOn){
          fprintf(FPRN,"Neuron[%d][%d]=%lf   \n",
                                 lyr, dNeuron,Neuron[lyr][dNeuron]);
          }
      }
   }
if (PrinterEcho && DebugOn){ fprintf(FPRN,"\n");}
}

/******************************************************************************
* FUNCTION HCalcDelta
* Implementation of BP,s calc of delta
*
******************************************************************************/

double HCalcDelta(int lyr,int j,double dNETj){
int k;
double Delta, SUMk;
SUMk=0.0;
for (k=0; k<LayerSize[lyr+1]; k++) {
   SUMk += DELTAj[lyr+1][k] * W[lyr+1][j][k];
   } /* endfor */
Delta = dNETj * SUMk;
return Delta;
}

void CalcErrors(){
double dNETj;
double MOMENTUM;
int  i, j;
int LocalConvFlg=TRUE;
if (PrinterEcho)
  fprintf(FPRN,"\nCALCERRORS Pattern#=%d Iteration=%ld  ",CurrPat,CurrIter);

for (j=0; j<LayerSize[OutLayerIndx]; j++) {
   ERROR[j] = (Desired[CurrPat][j] - Neuron[OutLayerIndx][j]);
   if (fabs(ERROR[j])>=ERRTOL) LocalConvFlg=FALSE;  // Any Nonconverged error kills
   AvgErr +=fabs(ERROR[j]);
   if (fabs(ERROR[j])  > WorstErr) WorstErr= fabs(ERROR[j]);
   if (CurrPat==(NumPatterns-1)) {
      AvgErr=AvgErr/NumPatterns;
      printf("Epoch=%ld Eavg=%lf Eworst=%lf\n",Epoch,AvgErr, fabs(WorstErr) );
      if (ArchOn==AVERAGE) {
         if ((ARCGRAN*(Epoch/ARCGRAN)) == Epoch) { // only save ARCGRANth epochs
            fprintf(ARCHIVE,"%ld %lf %lf\n",Epoch,AvgErr, fabs(WorstErr) );
            } /* endif */
         }
      if (ArchOn==WORST) {
         if ((ARCGRAN*(Epoch/ARCGRAN)) == Epoch) { // only save alternate epochs
            fprintf(ARCHIVE,"%ld %lf\n",Epoch, fabs(WorstErr) );
            } /* endif */
         }
      AvgErr=0.0;
      WorstErr=0.0;
      } 
    else {
      } /* endif */
   if (PrinterEcho) fprintf(FPRN,"ERROR[%d]=%lf  ",j,ERROR[j]);
   if (ArchOn==ALL) fprintf(ARCHIVE,"%ld %lf\n",CurrIter,fabs(ERROR[j]) );
   } /* endfor */

if (LocalConvFlg) {
   ConvCount++;      //Record that another consec pattern is within ERRTOL
   if (ConvCount==NumPatterns) {
      ConvergeFlg=TRUE;
      } /* endif */
   }
  else {
   ConvCount=0; //Start over. This pattern had an error out of tolerance
   } /* endif */
}


/******************************************************************************
* FUNCTION AdaptWeights
*   Apply backprop to train the weights
******************************************************************************/

void AdaptWeights(){
double dNETj;
double MOMENTUM;
int lyr, i, j;
unsigned int cmd;
unsigned int esf;                       // epoch scale factor

// NOTE: The following annealing of eta is not really necessary
//       but it does speed things up.
esf = NumPatterns *1000;
cmd = (unsigned int)(CurrIter/esf);    // for cmd every 1000 epochs
if ( (esf*(CurrIter/esf)) ==CurrIter ) {
      switch (cmd) {
         case 1:
            ETA += 3.00;      // bump up learning rate at epoch 1,000
            printf("New ETA =%lf\n",ETA);
            break;            // was 2.0
         case 2:
            ETA += 5.00;      // bump up learning rate at epoch 2,000
            printf("New ETA =%lf\n",ETA);
            break;            // was 4.5
         case 3:
            ETA += 8.00;      // bump up learning rate at epoch 3,000
            printf("New ETA =%lf\n",ETA);
            break;            // was 7.0
         case 4:
            ETA += 8.00;      // bump up learning rate at epoch 4,000
            printf("New ETA =%lf\n",ETA);
            break;            // was 8.0
         case 5:
            ETA += 8.00;      // bump up learning rate at epoch 5,000
            printf("New ETA =%lf\n",ETA);
            break;
         default:;
      } 
   } 

// APPLY BACKPROP
 
for (lyr=OutLayerIndx; lyr>0; lyr--) {
   for (j=0; j<LayerSize[lyr]; j++) {
      dNETj=Neuron[lyr][j] * (1 - Neuron[lyr][j]);
      if (lyr==OutLayerIndx) {
         ERROR[j] = (Desired[CurrPat][j] - Neuron[lyr][j]);
         DELTAj[lyr][j] = ERROR[j] * dNETj;
         }
       else {
         DELTAj[lyr][j] = HCalcDelta(lyr,j,dNETj);
         }
      for (i=0; i<=LayerSize[lyr-1]; i++) {   // include bias
         DELTA_Wij[lyr][i][j] = ETA * DELTAj[lyr][j] * Neuron[lyr-1][i];
         MOMENTUM= ALPHA*(W[lyr][i][j] - Wprev[lyr][i][j]);
         Wprev[lyr][i][j]=W[lyr][i][j];
         W[lyr][i][j] = W[lyr][i][j]+ DELTA_Wij[lyr][i][j] + MOMENTUM;
         } /* endfor */
      } /* endfor */
   } /* endfor */

}


/******************************************************************************
* FUNCTION SaveWeights                                                        *
*                                                                             *
*     Output weights to user specified file.                                  *
******************************************************************************/

void   SaveWeights(char *WgtName) {
int lyr,s,d;
double zWT;
FILE *WEIGHTFILE;

   WEIGHTFILE = fopen(WgtName,"w");
   if (WEIGHTFILE==NULL){
      printf("Unable to open weight file for output:%s\n",WgtName);
      exit(0);
      }
   printf("SAVING CALCULATED WEIGHTS:\n\n");
   fprintf(WEIGHTFILE,"0.00\n");                  // Threshold always 0
   fprintf(WEIGHTFILE,"%lf\n",Temperature);       // Temperature
   fprintf(WEIGHTFILE,"%d\n",NumLayers);         // Number of layers
   for (lyr=0; lyr<NumLayers; lyr++) {            // Save topology
      fprintf(WEIGHTFILE,"%d\n",LayerSize[lyr]); // Number of neurons/layer
      }
   for (lyr=1; lyr<NumLayers; lyr++) {         // Start at 1st hidden
      for (d=0; d<LayerSize[lyr]; d++) {
         for (s=0; s<=LayerSize[lyr-1]; s++) { // One extra for bias 
            zWT=W[lyr][s][d];
            fprintf(WEIGHTFILE,"%.25lf\n",zWT);
            if (PrinterEcho)
              fprintf(FPRN,"W(%d,%d,%d)=%lf\n",lyr,s,d,W[lyr][s][d]);
            }
         if (PrinterEcho) fprintf(FPRN,"\n");
         }
      }
   fclose(WEIGHTFILE);
}
/******************************************************************************
* FUNCTION ShowResults                                                        *
*                                                                             *
*     Output Summary specific to the parity-3 problem                         *
******************************************************************************/

void ShowResults(){
printf("\n----------------------------------------------------------\n");
if (ConvergeFlg) {
   printf("SUCCESS: Convergance has occured at iteration %ld\n",CurrIter);
   }
  else {
   printf("FAILURE: Convergance has NOT occured!!\n");
   } // endif
printf("Temperature = %lf\n",Temperature);
printf("ETA  = %lf\n",ETA);
printf("Alpha= %lf\n",ALPHA);
printf("\n----------------------------------------------------------\n");
}

double ActivationFn(double Net, double Tempr){
   double rv;
   switch (SelcActFn) {
      case SIGMOID:
         rv= Sigmoid(Net, Tempr);
         break;
      case STEPFN:
         rv= StepFn(Net);
         break;
      default:rv=-1.0;
      } /* endswitch */
   return rv;
}

double Sigmoid(double Net, double Tempr){
return 1.0/(1.0 + exp(-Net/Tempr));
}

double StepFn(double Net){
if (Net>0.0) {
   return 1;
   }
 else {
   return 0;
   }
}


void PrintHeader() {
system("cls");
PrinterEcho=0;

if (SelcActFn == SIGMOID) {
   printf("Activation is: SIGMOID\n");
   if (PrinterEcho) {
          fprintf(FPRN,"Activation is: SIGMOID\n\n");
          }
   }
 else {
   printf("Activation is: STEP\n");
   if (PrinterEcho) {
          fprintf(FPRN,"Activation is: STEP\n\n");
          }
   }
}


int main(int argc, char *argv[])
{
PrintHeader();
if (PrinterEcho) FPRN=fopen("prnfile.lst","w");
if (ArchOn) ARCHIVE=fopen("archive.lst","w");

if (argc>3) {
   GetParms(1,argv[2]);
   LoadTrainingSet(argv[1]);
   }
 else {
   printf("USAGE: BPROP TRAINING_FILE PARMS_FILE WEIGHT_FILE\n");
   exit(0);
   }
SetRandomWeights();
CurrIter=0;
while ((!ConvergeFlg) && (CurrIter<MAXITER)) {
   GetInputs();
   RunNet();
   CalcErrors();
   AdaptWeights();
   }
ShowResults();   // Show how we did
if (ConvergeFlg)
   SaveWeights(argv[3]);   // Save the weights for later use

if (PrinterEcho) fclose(FPRN);
if (ArchOn) fclose(ARCHIVE);
return 0;
}
