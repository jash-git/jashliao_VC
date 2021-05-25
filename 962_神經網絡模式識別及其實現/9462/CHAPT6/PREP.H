class cRawData {
private:
  FILE *input;
  short iobuf[25];
  unsigned char pelchr [384];    // Pel vector 24x16
  int M[16][24];                 // Pel Matrix
  int RecID;                     // Record number
  char c;                        // expected character
  char fname[80];
public:
  cRawData();
  int Open(char *);
  int Read(int RecID);
  int QueryXY(int x,int y) {return M[x][y];}
  char QueryChar(){return c;}
  ~cRawData(){fclose(input);}
};

cRawData::cRawData(){
   RecID=-1;
}

int cRawData::Open(char *ifile){
strcpy(fname,ifile);
input = fopen(fname, "rb");
if (input == 0) {printf ("open error.\n"); return 0;}
}

int cRawData::Read(int ID){
   int j,k,r;
   int mask,rowdata;
   unsigned short shiftl, shiftr;

RecID=ID;
r=fseek (input, (long int) (RecID)*sizeof(iobuf), 0);
if (r!=0) 
   return 0;
fread (iobuf, 1, sizeof(iobuf), input);
c=iobuf[0]>>8;
for (j=0; j<24; j++) {
   mask=0x8000;
   shiftr= (iobuf[j+1]>>8)&0xff;
   shiftl= iobuf[j+1]<<8;
   rowdata=  shiftr | shiftl;
   for (k=0; k<16; k++) {
      if (rowdata & mask)
         pelchr[16*j+k]=0x01;
       else
         pelchr[16*j+k]=0x00;
      mask = mask>>1;
      } // endfor
   }

/* Matrix Setup */
for (j=0; j<24; j++){
  for (k=0; k<16; k++){
     M[k][23-j]= pelchr[16*j+k];
     }
  }
return 1;
}

