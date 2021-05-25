
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//----------------------------------------------------------------------------

// DEFINES
#define MAXNEURONS      64
#define MAXPATTERNS     10
#define MAXITER         600000
#define TRUE            1
#define FALSE           0
//#undef  SIDESHOW
#define SIDESHOW
//----------------------------------------------------------------------------
// FUNCTION PROTOTYPES

// network fns
void InitNetRand(void);                 // Scramble net state
void LoadTrainingSet(char *Fname);      // Get training set from file
void TrainNet();                        // Train net to recognize patterns
void RunNet(void);                      // Update net til convergance or MAXITER
int UpdateNeuron(int j);                // Udate jTH neuron. 
                                        //       Return True if state changed
void LoadUserPattern(char *Fname);
int QueryAllClean(void);                // Return TRUE if all neurons were visited
void SetAllToDirty(void);               // Set all neurons to NOT visited
// utility fns
void Initialize(int cnt, char *Name);   // housekeeping
void DisplayPatVect(int V[MAXNEURONS]); // show Net/Pattern (human-eye view)
void SavePatVect(int V[MAXNEURONS],     // store Net/Pattern (human-eye view)
                     char *txt, int i); //   to the archive file
void DisplayWeights(void);              // show the weight matrix
void DisplayPatterns(void);             // Display all trained patterns
int  QueryUserInt(char *msg);
void KeyWait(void);
void KeyWait2(char *txt);
int  random(int N);
//----------------------------------------------------------------------------

// GLOBALS
int PatVec[MAXNEURONS];                 // Pattern Vector
int PatMatrix[MAXPATTERNS][MAXNEURONS]; // Pattern Vector
int NEURON[MAXNEURONS];                 // Network
int T[MAXNEURONS][MAXNEURONS];          // Weight matrix
int NumNeurons;                         // Actual size of net
int NumPatterns;                        // Actual number of patterns
int PatternX;                           // X-dimension for human viewing
int PatternY;                           // Y-dimension for human viewing
int Dirty[MAXNEURONS];                  // TRUE if neuron has not been updated
                                        // FALSE otherwise

FILE *ARCHIVE;

//----------------------------------------------------------------------------

int  random(int N){
int x;
x=N*rand();
return (x/RAND_MAX);
}

void DisplayPatVect(int V[MAXNEURONS]){
   int x,y,indx;
   indx=0;
   for (y=0; y<PatternY; y++) {
      for (x=0; x<PatternX; x++) {
         if (V[indx]==1) {
            printf("X");
         } else {
            printf(".");
         } /* endif */
         indx++;
         } /* endfor */
      printf("\n");
      } /* endfor */
   printf("\n");
}

void SavePatVect(int V[MAXNEURONS], char *txt, int i) {
   int x,y,indx;
   indx=0;
   fprintf(ARCHIVE,"\n");
   for (y=0; y<PatternY; y++) {
      for (x=0; x<PatternX; x++) {
         if (V[indx]==1) {
            fprintf(ARCHIVE,"X");
         } else {
            fprintf(ARCHIVE,".");
         } /* endif */
         indx++;
         } /* endfor */
      fprintf(ARCHIVE,"\n");
      } /* endfor */
   fprintf(ARCHIVE,"\n%s ",txt);
   if (i>=0) fprintf(ARCHIVE,"%d ",i);
   fprintf(ARCHIVE,"\n\n ");
}

void DisplayWeights(){
   int i,j;
fprintf(ARCHIVE,"WEIGHTS:\n");
for (i=0; i<NumNeurons; i++) {
   fprintf(ARCHIVE,"[");
   for (j=0; j<NumNeurons; j++) {
      fprintf(ARCHIVE, " %d",T[j][i]);
      } /* endfor */
   fprintf(ARCHIVE,"]\n");
   } /* endfor */
}

void DisplayPatterns() {
   int i,p;
for (p=0; p<NumPatterns; p++) {
   for (i=0; i<NumNeurons; i++) {
      PatVec[i] =PatMatrix[p][i];
      } /* endfor */
   DisplayPatVect(PatVec);                         // show 1st training pattern
   SavePatVect(PatVec, "Training Pattern", p+1);
   printf("\n\nTraining Pattern %d of %d\n\n",p+1,NumPatterns);
   KeyWait();
   } /* endfor */
}

int  QueryUserInt(char *msg){
int rv;
printf("Enter %s ==> ",msg);
scanf("%d",&rv);
return rv;
}

void KeyWait(void){
printf("Press any key to continue.\n");
while (!kbhit()) { } /* endwhile */
getch();
system("cls"); 
}

void KeyWait2(char *txt){
printf("\n\n%s\n",txt);
KeyWait();
}

void InitNetRand() {
   int i,r;

fprintf(ARCHIVE,"Creating test pattern\n");
srand(5);

for (i=0; i<NumNeurons; i++) {
   r=random(100);   
   if (r >= 50) {
      NEURON[i]=0;
      }
    else {
      NEURON[i]=1;
      } /* endif */
   } /* endfor */

}

void LoadTrainingSet(char *Fname) {
   int pat,j, InVal;
FILE *PATTERNFILE;

printf("Loading training set from file: %s\n",Fname);
fprintf(ARCHIVE,"Loading training set from file: %s\n",Fname);
PATTERNFILE = fopen(Fname,"r");
if (PATTERNFILE==NULL){
   printf("Unable to open training Set file: %s",Fname);
   exit(0);
   }

fscanf(PATTERNFILE,"%d",&NumNeurons);          // Get number of neurons
fscanf(PATTERNFILE,"%d",&NumPatterns);         // Get number of patterns
fscanf(PATTERNFILE,"%d",&PatternX);            // X-dimension for human viewing
fscanf(PATTERNFILE,"%d",&PatternY);            // Y-dimension for human viewing
printf("%d Patterns Loaded\n",NumPatterns);
fprintf(ARCHIVE,"%d Patterns Loaded\n",NumPatterns);
for (pat=0; pat<NumPatterns; pat++) {
   for (j=0; j<NumNeurons; j++) {
      fscanf(PATTERNFILE,"%d",&InVal);
      PatMatrix[pat][j] =InVal;
      } // endfor 
   } // endfor
fclose(PATTERNFILE);
}


void LoadUserPattern(char *Fname) {
   int j, InVal;
FILE *PATTERNFILE;

printf("Loading pattern from file: %s\n", Fname);
fprintf(ARCHIVE,"Loading pattern from file: %s\n", Fname);
PATTERNFILE = fopen(Fname,"r");
if (PATTERNFILE==NULL){
   printf("Unable to open file: %s",Fname);
   exit(0);
   }

printf("\n");
for (j=0; j<NumNeurons; j++) {
   fscanf(PATTERNFILE,"%d",&InVal);
   NEURON[j] =InVal;
   } // endfor 
fclose(PATTERNFILE);
}


void TrainNet(){
   int i,j,pat;
   int Sum;
for (i=0; i<NumNeurons; i++) {
   for (j=0; j<NumNeurons; j++) {
      Sum=0;
      for (pat=0; pat<NumPatterns; pat++) {
         Sum += (2*PatMatrix[pat][i]-1) *  (2*PatMatrix[pat][j]-1);
         } /* endfor */
      T[j][i] = T[i][j] = Sum;
      } /* endfor */
   } /* endfor */
for (i=0; i<NumNeurons; i++) {   // Get rid of the diagonal...
   T[i][i]=0;                    //   ...so it doesn't cause trouble later
   } /* endfor */
}


int QueryAllClean() {
   int i;
for (i=0; i<NumNeurons; i++) {
   if (Dirty[i]==TRUE) return FALSE;
   } // endfor 
return TRUE;
}


void SetAllToDirty() {
   int i;
for (i=0; i<NumNeurons; i++) {
   Dirty[i]=TRUE;
   } // endfor 
}


int UpdateNeuron(int j) {
   int i;
   int Sum = 0;
   int OldState = NEURON[j];
for (i=0; i<NumNeurons; i++) {  // accumulate all contributions
   Sum += T[j][i] * NEURON[i];  // remember we set diagnal of matrix T to 0 ..
                                //         .. so no need to test for i==j
   } /* endfor */

if (Sum < 0) {
   NEURON[j] = 0;
   } 
 else {
   if (Sum>0)
      NEURON[j] = 1;
   } /* endif */

if (NEURON[j] == OldState) {
   return 0;
   }
 else {
   return 1;
   } /* endif */
}


void RunNet(void) {
   int j;
   int Converged = FALSE;
   int ChngCount = 0;
   unsigned long int IterCount = 0;
   int ArchCnt=0;
SetAllToDirty();
while ( (!Converged) && (IterCount < MAXITER) ) {
   j = random(NumNeurons);
   ChngCount += UpdateNeuron(j);  // increment if neuron changed state
   DisplayPatVect(NEURON);
   printf("RUNNING...   Iteration=%d \n",IterCount);
   if (ArchCnt>=9) {
      SavePatVect(NEURON, "Net output at iteration =", IterCount+1);
      ArchCnt=0;
      } else {
      ArchCnt++;
      } /* endif */
   Dirty[j] = FALSE;              // Record that we've  covered this neuron


   if (QueryAllClean()) {         // Check if we hit all neurons at least once
      // here if we have hit all at least once
      if (ChngCount == 0) {       // Check if any neurons changed this pass
         // if we're here then weve converged
         Converged = TRUE;
         printf("\nCONVERGED");
         SavePatVect(NEURON, "Net after converance at iteration=", IterCount);
         } 
       else {
         // if here then NOT converged so reinit for another pass
         SetAllToDirty();
         ChngCount=0;
         } /* endif */
      } /* endif */
   IterCount++;                   // Increment iteration counter
   } /* endwhile */
}


void Initialize(char *Name1, char *Name2) {    // housekeeping
   char TrnName[50];
   char TstName[50];

ARCHIVE = fopen("ARCHIVE.LST","w");
if (ARCHIVE==NULL){
   printf("Unable to open default archive file: ARCHIVE.LST");
   exit(0);
   }
strcpy(TrnName,Name1);
strcpy(TstName,Name2);
LoadTrainingSet(TrnName);
if (strcmpi("RANDOM",TstName) )
   LoadUserPattern(TstName);
 else
   InitNetRand();            // randomize pattern on user request


KeyWait();
}

int main(int argc, char *argv[]) {

   int i;

if (argc<3) {
   printf("usage: hopnet TrainingFile [PatternFile]");
   return 1;
   } /* endif */

Initialize(argv[1], argv[2]);
DisplayPatVect(NEURON);  // show net is set to test pattern
SavePatVect(NEURON, "Test Pattern", -1);
KeyWait2("TEST PATTERN");
DisplayPatterns();
TrainNet();
DisplayWeights();
RunNet();
fclose(ARCHIVE);
return 0;
}
