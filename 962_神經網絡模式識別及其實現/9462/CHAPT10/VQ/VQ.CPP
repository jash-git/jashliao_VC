/****************************************************************************
*                                                                           *
*  VECTOR QUANTIZATION                                                      *
*                                                                           *
*****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

// FUNCTION PROTOTYPES


// DEFINES
#define         SUCCESS         1
#define         FAILURE         0
#define         TRUE            1
#define         FALSE           0
#define         MAXVECTDIM      20
#define         MAXPATTERN      20
#define         MAXCLUSTER      10

// ***** Defined structures & classes *****
struct aCluster {
   double       Center[MAXVECTDIM];
   int          Member[MAXPATTERN];  //Index of Vectors belonging to this cluster
   int          NumMembers;
};

struct aVector {
   double       Center[MAXVECTDIM];
   int          Size;
};

class VQsyst {
private:
   double       Pattern[MAXPATTERN][MAXVECTDIM+1];
   aCluster     Cluster[MAXCLUSTER];
   int          NumPatterns;          // Number of patterns
   int          SizeVector;           // Number of dimensions in vector
   int          NumClusters;          // Curr number of clusters
   double       Threshold;
   void         Attach(int,int);      // Add spec'd pattern to spec'd
                                      // Clusters membership list.
   int          AllocateCluster();    //
   void         CalcNewClustCenter(int);// find cluster center for modified
                                         // clusters
   double       EucNorm(int, int);   // Calc Euclidean norm vector
   int          FindClosestCluster(int); //ret indx of clust closest to pattern
                                         //whose index is arg
   FILE *OutFile;
public:
   VQsyst();
   int InitOutput(char *fname);
   int LoadPatterns(char *fname);      // Get pattern data to be clustered
   void RunVQ();                   // Overall control Vector Quant process
   void ShowClusters();                // Show results on screen
   void SaveClusters(char *fname);     // Save results to file
   ~VQsyst(){fclose(OutFile);}
};


//=================IMPLENTATION OF VQ METHODS================================



//***************************************************************************
// Constructor
//***************************************************************************

VQsyst::VQsyst(){
   NumClusters=0;
   }


//***************************************************************************
// InitOutput
//***************************************************************************

int VQsyst::InitOutput(char *fname) {
if((OutFile = fopen(fname, "w")) == NULL){
    printf("Unable to open file %s for output",fname);
    return FAILURE;
    }
return SUCCESS;
}

//***************************************************************************
// LoadPatterns                                                             *
//   Loads pattern information from disk.                                   *
//       1) Number of patterns to be processed                              *
//       2) Size of the vectors to be processed                             *
//       3) Max dist permitted between cluster centers                      *
//       4) Pattern definitions                                             *
//***************************************************************************

int VQsyst::LoadPatterns(char *fname){
   FILE *InFilePtr;
   int    i,j;
   double x;
if((InFilePtr = fopen(fname, "r")) == NULL)
    return FAILURE;
fscanf(InFilePtr, "%d", &NumPatterns);  // Read # of patterns
fscanf(InFilePtr, "%d", &SizeVector);   // Read dimension of vector
fscanf(InFilePtr, "%lg", &Threshold);   // Read Euc dist Threshold.
printf("The input patterns are:\n");
fprintf(OutFile,"The input patterns are:\n");
for (i=0; i<NumPatterns; i++) {         // For each vector
   for (j=0; j<SizeVector; j++) {       // create a pattern
      fscanf(InFilePtr,"%lg",&x);       // consisting of all elements
      Pattern[i][j]=x;
      printf("Pattern[%d][%d]=%f\n",i,j,Pattern[i][j]);
      fprintf(OutFile,"Pattern[%d][%d]=%f\n",i,j,Pattern[i][j]);
      } /* endfor */
   } /* endfor */
printf("\n");
fprintf(OutFile,"\n");
return SUCCESS;
}

//***************************************************************************
// RunVQ                                                                    *
//   Provides overall control of VQ algorithm.  K clusters                  *
//   We choose the first K vectors to do this                               *
//***************************************************************************

void VQsyst::RunVQ(){
  int pat,Winner;
  double dist;

for (pat=0; pat<NumPatterns; pat++) {
   printf("\n\nPATTERN %d:\n",pat);
   fprintf(OutFile,"\n\nPATTERN %d:\n",pat);
   Winner = FindClosestCluster(pat);   // Attach the curr input to closest
                                       // cluster
   if (Winner == -1) {
      Winner=AllocateCluster();
      printf(" so allocate a new cluster %d\n",Winner);
      fprintf(OutFile," so allocate a new cluster %d\n",Winner);
      }
    else {
      printf("The closest cluster is: %d\n",Winner);
      fprintf(OutFile,"The closest cluster is: %d\n",Winner);
      dist= EucNorm(pat,Winner);
      dist= sqrt(dist);                // because eucnorm doesn't do this
      if (dist>Threshold) {
         printf("distance %f > %f", dist,Threshold);
         printf("\nTherefore cluster %d failed the distance test.\n",Winner);
         fprintf(OutFile,"distance %f > %f", dist,Threshold);
         fprintf(OutFile,"\nTherefore cluster %d failed the distance test.\n",Winner);
         Winner=AllocateCluster();     // Above threshold so allocate new
         printf("so create NEW cluster number:%d\n",Winner);
         fprintf(OutFile,"so create NEW cluster number:%d\n",Winner);
         }
       else {
         printf("Distance %f < %f", dist,Threshold);
         printf("\nTherefore cluster %d passed the distance test.\n",Winner);
         fprintf(OutFile,"Distance %f < %f", dist,Threshold);
         fprintf(OutFile,"\nTherefore cluster %d passed the distance test.\n",Winner);
         } /* endif */                 // cluster
      } /* endif */
   printf("patern %d assigned to cluster %d\n",pat,Winner);
   fprintf(OutFile,"patern %d assigned to cluster %d\n",pat,Winner);
   Attach(Winner,pat);                 // Attach pattern to winner
   CalcNewClustCenter(Winner);         // Adapt clust center
   ShowClusters(); 
   } /* endfor */
}


//***************************************************************************
// AllocateCluster                                                          *
//    Designate the next free cluster as active                             *
//***************************************************************************

int VQsyst::AllocateCluster(){
   int n;
n=NumClusters;
NumClusters++;
return n;
}

//***************************************************************************
// EucNorm                                                                  *
//   Returns the Euclidian norm between a pattern, p, and a cluster         *
//   center,c-1 he first K vectors to do this                               *
//***************************************************************************

double VQsyst::EucNorm(int p, int c){   // Calc Euclidean norm of vector difference
double dist;                            // between pattern vector, p, and cluster
int i;                                  // center, c.
dist=0;
for (i=0; i<SizeVector ;i++){
   dist += (Cluster[c].Center[i]-Pattern[p][i])*(Cluster[c].Center[i]-Pattern[p][i]);
   } /* endfor */
return dist;
}


//***************************************************************************
// Find ClosestCluster                                                      *
//   Returns the index of the cluster to which the pattern, pat, has the    *
//   closest Euclidean distance.                                            *
//***************************************************************************

int VQsyst::FindClosestCluster(int pat){
   int i, ClustID;
   double MinDist, d;
MinDist =9.9e+99;
ClustID=-1;
for (i=0; i<NumClusters; i++) {
   d=EucNorm(pat,i);
   if (d<MinDist) {
      MinDist=d;
      ClustID=i;
      } /* endif */
   } /* endfor */
if (ClustID<0) {
   printf("No Clusters exist ");
   fprintf(OutFile,"No Clusters exist ");
   } /* endif */
return ClustID;
}


//***************************************************************************
// Attach                                                                   *
//   Adds the pattern (whose index is p) to the cluster center whose index  *
//   is p.                                                                  *
//***************************************************************************

void VQsyst::Attach(int c,int p){
int MemberIndex;

   MemberIndex=Cluster[c].NumMembers;
   Cluster[c].Member[MemberIndex]=p;
   Cluster[c].NumMembers++;
}


//***************************************************************************
// CalcNewClustCenter                                                       *
//   Calculate a new cluster center for the specified cluster,c             *
//                                                                          *
//***************************************************************************

void VQsyst::CalcNewClustCenter(int c){
   int VectID,j,k;
   double tmp[MAXVECTDIM];

   for (j=0; j<SizeVector; j++) {            // clear workspace
      tmp[j]=0.0;
      } /* endfor */
   for (j=0; j<Cluster[c].NumMembers; j++) { //traverse member vectors
      VectID=Cluster[c].Member[j];
      for (k=0; k<SizeVector; k++) {         //traverse elements of vector
         tmp[k] += Pattern[VectID][k];       // add (member) pattern elmnt into temp
         } /* endfor */
      } /* endfor */
   for (k=0; k<SizeVector; k++) {            //traverse elements of vector
      tmp[k]=tmp[k]/Cluster[c].NumMembers;
      Cluster[c].Center[k]=tmp[k];
      } /* endfor */
}


//***************************************************************************
// ShowClusters                                                             *
//   Display the cluster centers for each of the allocated clusters         *
//                                                                          *
//***************************************************************************

void VQsyst::ShowClusters(){
   int cl,i;
printf("\nThe new cluster centers are:");
fprintf(OutFile,"\nThe new cluster centers are:");
for (cl=0; cl<NumClusters; cl++) {
   printf("\nCLUSTER %d ==>[%f,%f]", cl,Cluster[cl].Center[0],Cluster[cl].Center[1]);
   fprintf(OutFile,"\nCLUSTER %d ==>[%f,%f]", cl,Cluster[cl].Center[0],Cluster[cl].Center[1]);
   } /* endfor */
printf("\nCLUSTER Membership");
fprintf(OutFile,"\nCLUSTER Membership");
for (cl=0; cl<NumClusters; cl++) {
   printf("\n  Cluster %d ==>{",cl);
   fprintf(OutFile,"\n  Cluster %d ==>{",cl);
   for (i=0; i<Cluster[cl].NumMembers; i++) {
      printf("%d ",Cluster[cl].Member[i]);
      fprintf(OutFile,"%d ",Cluster[cl].Member[i]);
      } /* endfor */
   printf("}\n");
   fprintf(OutFile,"}\n");
   } /* endfor */

}


//***************************************************************************
// SaveClusters                                                             *
//   Store the cluster centers for each of the allocated clusters           *
//   to the designated file                                                 *
//***************************************************************************

void VQsyst::SaveClusters(char *fname){
   FILE *OutFilePtr;
   int cl;
if((OutFilePtr = fopen(fname, "r")) == NULL){
    printf("Unable to open file %s for output",fname);
    }
  else {
   for (cl=0; cl<NumClusters; cl++) {
      fprintf(OutFilePtr,"\nCLUSTER %d ==>[%f,%f]\n",
              cl,Cluster[cl].Center[0],Cluster[cl].Center[1]);
      } /* endfor */
   fclose(OutFilePtr);
   }
}


//***************************************************************************
// Main                                                                     *
//                                                                          *
//                                                                          *
//***************************************************************************

main(int argc, char *argv[]) {
   VQsyst VQ;
if (argc<3) {
   printf("USAGE: VQ PATTERN_FILE(input) CLUSTER_FILE(output)\n");
   exit(0);
   }

if (VQ.InitOutput(argv[2])==FAILURE)
   exit (0);
if (VQ.LoadPatterns(argv[1])==FAILURE ){
   printf("UNABLE TO READ PATTERN_FILE:%s\n",argv[1]);
   exit(0);
   }
VQ.RunVQ();
}
