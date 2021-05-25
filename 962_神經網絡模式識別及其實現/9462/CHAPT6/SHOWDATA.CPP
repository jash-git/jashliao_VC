/* display 24x16 binary image onto text mode display  */
#include <stdio.h>
#include <string.h>


main (int argc, char *argv[])
{
  FILE *input;
  short iobuf[25];
  unsigned short shiftl, shiftr;
  unsigned char pelchr [384];	/* 24x16 */
  int reccnt, skip, i, j, k, l,r;
  int mask;
  int rowdata;
  char fname[80];
  /** initialize **/
  strcpy(fname,argv[1]);
  input = fopen(fname, "rb");
  if (input == 0) {printf ("open error.\n"); return 0;}
  reccnt = 10;
  skip   = 1;
  char c;

  /** main proc **/
  for (i=0; i<reccnt; i++){
    r=fseek (input, (long int) (skip*i)*sizeof(iobuf), 0);
    if (r!=0) {
       printf("\n********Seek Failed**********");
       break;
       }
    fread (iobuf, 1, sizeof(iobuf), input);
    c=iobuf[0]>>8;
    for (j=0; j<24; j++) {
       mask=0x8000;
       shiftr= (iobuf[j+1]>>8)&0xff;
       shiftl= iobuf[j+1]<<8;
       rowdata=  shiftr | shiftl;
       for (k=0; k<16; k++) {
          if (rowdata & mask)
             pelchr[16*j+k]=0x31;
           else
             pelchr[16*j+k]=0x20;
          mask = mask>>1;
          } /* endfor */
    }

    /** image print **/
    printf("\n   0 2 4 6 8 0 2 4   \n");
    printf("  +----------------+  \n");
    for (j=0; j<24; j++){
      printf ("%2d|", j);
      for (k=0; k<16; k++){
         printf("%c", pelchr[16*j+k]);
         }
      printf("|  \n");
    }

    /** boundary print **/
    printf("  +----------------+  \n");
    printf("%c\n", c);
  }
  fclose(input);
}
