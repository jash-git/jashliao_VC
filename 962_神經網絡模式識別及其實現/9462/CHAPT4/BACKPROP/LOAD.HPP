void LoadTrainingSet(char *Fname) {
FILE *PFILE;
int PGindx;
int x,mask;
int pat,i,j;
double inVal;
int NumPatBytes;   

PFILE = fopen(Fname,"r");    // batch
if (PFILE==NULL){
   printf("\nUnable to open file \n");
   exit(0);
   }
fscanf(PFILE,"%d",&NumPatterns);
NumPatBytes= LayerSize[0] / 8; // # of Input lyr neurons must be divisible by 8

for (pat=0; pat<NumPatterns; pat++) {
   PGindx=0;
   for (i=0; i<NumPatBytes; i++) {
      fscanf(PFILE,"%x",&x);
      mask = 0x80;
      for (j=0; j<8; j++) {
         if ((mask & x) > 0) {
            InPattern[pat][PGindx]=1.0;
            }
          else {
            InPattern[pat][PGindx]=0.0;
            } /* endif */
         mask=mask/2; //printf("{%x}",mask);
         PGindx++;
         } /* endfor */
      } /* endfor */
   // Now get desired / expected values
   for (i=0; i<LayerSize[OutLayerIndx]; i++) {
      fscanf(PFILE,"%lf",&inVal);
      Desired[pat][i]=inVal;
      } /* endfor */
   } /* endfor */
fclose(PFILE);
}
