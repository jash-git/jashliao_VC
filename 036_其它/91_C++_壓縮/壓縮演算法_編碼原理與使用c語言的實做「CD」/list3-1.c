#include <stdio.h>

#define BUFFER_SIZE 102400
#define FALSE 0
#define TRUE 1

typedef unsigned char byte;

unsigned char buffer[BUFFER_SIZE];

int encode(FILE *fp,byte *img,int mx);

int main(int ac,char *av[])
{
	FILE *fp_i,*fp_o;
	int i,c;

	if(ac<3) {
		exit(8);
	}
	fp_i=fopen(av[1],"rb");
	if(fp_i==NULL) {
		fprintf(stderr,"Input File cannot open\n");
		exit(8);
	}
	i=0;
	while(i<BUFFER_SIZE && (c=fgetc(fp_i))!=EOF) {
		buffer[i]=c;
		i++;
	}
	fclose(fp_i);
	fp_o=fopen(av[2],"wb");
	if(fp_o==NULL) {
		fprintf(stderr,"Output File cannot open\n");
		exit(8);
	}
	encode(fp_o,buffer,i);
	fclose(fp_o);
}


int fputLong(long num,FILE *fp)
{
	fputc((num>>24) & 0xff,fp);
	fputc((num>>16) & 0xff,fp);
	fputc((num>>8)  & 0xff,fp);
	fputc((num)     & 0xff,fp);
}

static int bits=0;
static int bdata=0;

int fputBitInit()
{
	bits=0;
	bdata=0;
}

// 輸出1位元
int fputBit(int bit,FILE *fp)
{
	bdata=(bdata<<1)|bit;
	bits++;
	if(bits>=8) {
		fputc(bdata,fp);
		bits=0;
		bdata=0;
	}
}

// 將多餘的位元輸出
int flushBit(FILE *fp)
{
	int i;

	for(i=0;i<7;i++) {
		fputBit(0,fp);
	}
}

int sgni(int x)
{
	if(x<0) return 0;
	return 1;
}

int absi(int x)
{
	if(x<0) return -x;
	return x;
}

int getLength(int x)
{
	if(x<  8) return 1;
	if(x< 16) return 2;
	if(x< 32) return 3;
	if(x< 64) return 4;
	if(x<128) return 5;
	if(x<256) return 6;
	return 7;
}

// 輸出威爾編碼
int outputEncode(int val,FILE *fp)
{
	int s,a,len;
	int i;

	s=sgni(val);
	a=absi(val);
	len=getLength(a);
	for(i=0;i<len;i++) fputBit(s,fp);
	fputBit(1-s,fp);
	len+=2;
	for(i=0;i<len;i++) {
		fputBit(a&1,fp);
		a>>=1;
	}
	return TRUE;
}

int encode(FILE *fp,byte *img,int mx)
{
	int i;
	int x,y;
	int dx,x2;
	int dr,dg,db;
	int at_first;
	int prev,now;

	dx=1;
	x2=0;

	fputLong(mx,fp);
	fputBitInit();
	at_first=TRUE;
	for(x=0;x<mx;x++) {
		now=img[x];
		if(at_first) {
			fputc(now,fp);
			at_first=FALSE;
		}
		else {
			dr=now - prev;
			outputEncode(dr,fp);
		}
		prev=now;
	}
	flushBit(fp);
}
