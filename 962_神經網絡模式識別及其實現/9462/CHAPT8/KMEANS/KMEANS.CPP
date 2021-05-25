/****************************************************************************
*                                                                           *
*  KMEANS                                                                   *
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





char *f2a(double x, int width){
   char cbuf[255];
   char *cp;
   int i,k;
   int d,s;
cp=fcvt(x,width,&d,&s);
if (s) {
   strcpy(cbuf,"-");
   }
 else {
   strcpy(cbuf," ");
   } /* endif */
if (d>0) {
   for (i=0; i<d; i++) {
      cbuf[i+1]=cp[i];
      } /* endfor */
   cbuf[d+1]=0;
   cp+=d;
   strcat(cbuf,".");
   strcat(cbuf,cp);
   } else {
      if (d==0) {
         strcat(cbuf,".");
         strcat(cbuf,cp);
         } 
       else {
         k=-d;
         strcat(cbuf,".");
         for (i=0; i<k; i++) {
            strcat(cbuf,"0");
            } /* endfor */
         strcat(cbuf,cp);
         } /* endif */
   } /* endif */
cp=&cbuf[0];
return cp;
}




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

class System {
private:
   double       Pattern[MAXPATTERN][MAXVECTDIM+1];
   aCluster     Cluster[MAXCLUSTER];
   int          NumPatterns;          // Number of patterns
   int          SizeVector;           // Number of dimensions in vector
   int          NumClusters;          // Number of clusters
   void         DistributeSamples();  // Step 2 of K-means algorithm
   int          CalcNewClustCenters();// Step 3 of K-means algorithm
   double       EucNorm(int, int);   // Calc Euclidean norm vector
   int          FindClosestCluster(int); //ret indx of clust closest to pattern
                                         //whose index is arg
public:
   system();
   int LoadPatterns(char *fname);      // Get pattern data to be clustered
   void InitClusters();                // Step 1 of K-means algorithm
   void RunKMeans();                   // Overall control K-means process
   void ShowClusters();                // Show results on screen
   void SaveClusters(char *fname);     // Save results to file
   void ShowCenters();
};

void System::ShowCenters(){
int i,j;
printf("Cluster centers:\n");
for (i=0; i<NumClusters; i++) {
   Cluster[i].Member[0]=i;
   printf("ClusterCenter[%d]=(%f,%f)\n",i,Cluster[i].Center[0],Cluster[i].Center[1]);
   } /* endfor */
printf("\n");
}

int System::LoadPatterns(char *fname){
   FILE *InFilePtr;
   int    i,j;
   double x;
if((InFilePtr = fopen(fname, "r")) == NULL)
    return FAILURE;
fscanf(InFilePtr, "%d", &NumPatterns);  // Read # of patterns
fscanf(InFilePtr, "%d", &SizeVector);   // Read dimension of vector
fscanf(InFilePtr, "%d", &NumClusters);  // Read # of clusters for K-Means
for (i=0; i<NumPatterns; i++) {         // For each vector
   for (j=0; j<SizeVector; j++) {       // create a pattern
      fscanf(InFilePtr,"%lg",&x);       // consisting of all elements
      Pattern[i][j]=x;
      } /* endfor */
   } /* endfor */
printf("Input patterns:\n");
for (i=0; i<NumPatterns; i++) {
   printf("Pattern[%d]=(%2.3f,%2.3f)\n",i,Pattern[i][0],Pattern[i][1]);
   } /* endfor */
printf("\n--------------------\n");
return SUCCESS;
}
//***************************************************************************
// InitClusters                                                             *
//   Arbitrarily assign a vector to each of the K clusters                  *
//   We choose the first K vectors to do this                               *
//***************************************************************************
void System::InitClusters(){
int i,j;
printf("Initial cluster centers:\n");
for (i=0; i<NumClusters; i++) {
   Cluster[i].Member[0]=i;
   for (j=0; j<SizeVector; j++) {
      Cluster[i].Center[j]=Pattern[i][j];
      } /* endfor */
   } /* endfor */
for (i=0; i<NumClusters; i++) {
   printf("ClusterCenter[%d]=(%f,%f)\n",i,Cluster[i].Center[0],Cluster[i].Center[1]);
   } /* endfor */
printf("\n");
}

void System::RunKMeans(){
  int converged;
  int pass;
pass=1;
converged=FALSE;
while (converged==FALSE) {
   printf("PASS=%d\n",pass++);
   DistributeSamples();
   converged=CalcNewClustCenters();
   ShowCenters();
   } /* endwhile */
}

double System::EucNorm(int p, int c){   // Calc Euclidean norm of vector difference
double dist,x;                          // between pattern vector, p, and cluster
int i;                                  // center, c.
char zout[128];
char znum[40];
char *pnum;

pnum=&znum[0];
strcpy(zout,"d=sqrt(");
printf("The distance from pattern %d to cluster %d is calculated as:\n",c,p);
dist=0;
for (i=0; i<SizeVector ;i++){
   x=(Cluster[c].Center[i]-Pattern[p][i])*(Cluster[c].Center[i]-Pattern[p][i]);
   strcat(zout,f2a(x,4));
   if (i==0)
      strcat(zout,"+");
   dist += (Cluster[c].Center[i]-Pattern[p][i])*(Cluster[c].Center[i]-Pattern[p][i]);
   } /* endfor */
printf("%s)\n",zout);
return dist;
}

int System::FindClosestCluster(int pat){
   int i, ClustID;
   double MinDist, d;
MinDist =9.9e+99;
ClustID=-1;
for (i=0; i<NumClusters; i++) {
   d=EucNorm(pat,i);
   printf("Distance from pattern %d to cluster %d is %f\n\n",pat,i,sqrt(d));
   if (d<MinDist) {
      MinDist=d;
      ClustID=i;
      } /* endif */
   } /* endfor */
if (ClustID<0) {
   printf("Aaargh");
   exit(0);
   } /* endif */
return ClustID;
}

void System::DistributeSamples(){
int i,pat,Clustid,MemberIndex;
//Clear membership list for all current clusters
for (i=0; i<NumClusters;i++){
   Cluster[i].NumMembers=0;
   }
for (pat=0; pat<NumPatterns; pat++) {
   //Find cluster center to which the pattern is closest
   Clustid= FindClosestCluster(pat);
   printf("patern %d assigned to cluster %d\n\n",pat,Clustid);
   //post this pattern to the cluster
   MemberIndex=Cluster[Clustid].NumMembers;
   Cluster[Clustid].Member[MemberIndex]=pat;
   Cluster[Clustid].NumMembers++;
   } /* endfor */
}

int  System::CalcNewClustCenters(){
   int ConvFlag,VectID,i,j,k;
   double tmp[MAXVECTDIM];
   char xs[255];
   char ys[255];
   char nc1[20];
   char nc2[20];
   char *pnc1;
   char *pnc2;
   char *fpv;

pnc1=&nc1[0];
pnc2=&nc2[0];
ConvFlag=TRUE;
printf("The new cluster centers are now calculated as:\n");
for (i=0; i<NumClusters; i++) {              //for each cluster
   pnc1=itoa(Cluster[i].NumMembers,nc1,10);
   pnc2=itoa(i,nc2,10);
   strcpy(xs,"Cluster Center");
   strcat(xs,nc2);
   strcat(xs,"(1/");
   strcpy(ys,"(1/");
   strcat(xs,nc1);
   strcat(ys,nc1);
   strcat(xs,")(");
   strcat(ys,")(");
   for (j=0; j<SizeVector; j++) {            // clear workspace
      tmp[j]=0.0;
      } /* endfor */
   for (j=0; j<Cluster[i].NumMembers; j++) { //traverse member vectors
      VectID=Cluster[i].Member[j];
      for (k=0; k<SizeVector; k++) {         //traverse elements of vector
         tmp[k] += Pattern[VectID][k];       // add (member) pattern elmnt into temp
         if (k==0) {
              strcat(xs,f2a(Pattern[VectID][k],3));
            } else {
              strcat(ys,f2a(Pattern[VectID][k],3));
              } /* endif */
         } /* endfor */
      if(j<Cluster[i].NumMembers-1){
         strcat(xs,"+");
         strcat(ys,"+");
         }
        else {
         strcat(xs,")");
         strcat(ys,")");
         }
      } /* endfor */
   for (k=0; k<SizeVector; k++) {            //traverse elements of vector
      tmp[k]=tmp[k]/Cluster[i].NumMembers;
      if (tmp[k] != Cluster[i].Center[k])
         ConvFlag=FALSE;
      Cluster[i].Center[k]=tmp[k];
      } /* endfor */
   printf("%s,\n",xs);
   printf("%s\n",ys);
   } /* endfor */
return ConvFlag;
}

void System::ShowClusters(){
   int cl;
for (cl=0; cl<NumClusters; cl++) {
   printf("\nCLUSTER %d ==>[%f,%f]\n", cl,Cluster[cl].Center[0],Cluster[cl].Center[1]);
   } /* endfor */
}

void System::SaveClusters(char *fname){
}


main(int argc, char *argv[]) {
   System kmeans;
if (argc<2) {
   printf("USAGE: KMEANS PATTERN_FILE\n");
   exit(0);
   }
if (kmeans.LoadPatterns(argv[1])==FAILURE ){
   printf("UNABLE TO READ PATTERN_FILE:%s\n",argv[1]);
   exit(0);
   }
kmeans.InitClusters();
kmeans.RunKMeans();
kmeans.ShowClusters();
}
