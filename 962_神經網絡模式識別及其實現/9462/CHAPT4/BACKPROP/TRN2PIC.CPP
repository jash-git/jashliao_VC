#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

//---------------------------------------------------------------------------
// Graphical representation of training set
//---------------------------------------------------------------------------

void PictureTrainingSet(char *Tname, char *Pname) {
FILE *TFILE;
FILE *PFILE;
int PGindx;
int x,mask;
int pat,i,j;
double inVal;
int NumPatBytes;   
int NumPatterns;

TFILE = fopen(Tname,"r");    // batch
if (TFILE==NULL){
   printf("\nUnable to open file %s \n",Tname);
   exit(0);
   }
PFILE = fopen(Pname,"w");    // batch
if (PFILE==NULL){
   printf("\nUnable to open file %s \n",Tname);
   exit(0);
   }
fscanf(TFILE,"%d",&NumPatterns);
NumPatBytes=12;                  // Specific to this project

for (pat=0; pat<NumPatterns; pat++) {
   PGindx=0;
   for (i=0; i<NumPatBytes; i++) {
      fscanf(TFILE,"%x",&x);
      mask = 0x80;
      for (j=0; j<8; j++) {
         if ((mask & x) > 0) {
            printf("X");
            fprintf(PFILE,"X");
            }
          else {
            printf(".");
            fprintf(PFILE,".");
            } /* endif */
         mask=mask/2; //printf("{%x}",mask);
         PGindx++;
         } /* endfor */
      printf("\n");
      fprintf(PFILE,"\n");
      } /* endfor */
   // Now get desired / expected values
   fscanf(TFILE,"%lf",&inVal);
   printf("Desired = %lf\n",inVal);
   fprintf(PFILE,"Desired = %lf\n",inVal);
   } /* endfor */
fclose(TFILE);
fclose(PFILE);
}

main(int argc, char *argv[])
{
if (argc>2) {
   PictureTrainingSet(argv[1],argv[2]);
   }
 else {
   printf("USAGE: TRN2PIC TRAININGSET_FNAME PICTURE_FNAME\n");
   exit(0);
   }

}
