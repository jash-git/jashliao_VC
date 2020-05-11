#include<stdio.h>

#define FALSE 0
#define TRUE 1

typedef unsigned char byte;

int readData(unsigned char *data,int len,FILE *fp)
{
   return fread(data,len,sizeof(char),fp);
}

int getLong(FILE *fp)
{
	unsigned char buf[16];

	readData(buf,4,fp);
	return (buf[0]<<24) |(buf[1]<<16) | (buf[2]<<8) | buf[3];
}

// -------------------------------------------------------

static int bits=0;
static int bdata=0;

int fgetBitInit()
{
	bits=0;
	bdata=0;
}

// ¿é¥X1¦ì¤¸
int fgetBit(FILE *fp)
{
	unsigned char bbuf;
	unsigned char buf[16];
	int val;

	if(bits==0) {
		readData(&bbuf,1,fp);
		bdata=bbuf;
	}
	val=(bdata>>7)&1;
	bdata=(bdata<<1) & 0xff;
	bits++;
	if(bits>=8) {
		bits=0;
		bdata=0;
	}
	return val;
}

int getValue(FILE *fp)
{
	int sbit,bit;
	int i,cnt;
	int val;

	sbit=fgetBit(fp);

	cnt=0;
	while(fgetBit(fp)==sbit) {
		cnt++;
	}
	cnt+=3;
	val=0;
	for(i=0;i<cnt;i++) {
		bit=fgetBit(fp)<<i;
		val|=bit;
	}
	if(sbit==0) val=-val;
	return val;
}

long decode(FILE *fp,int mx)
{
	int x,y;
	int dx,x2;
	int dr,dg,db;
	int at_first;
	int now;

	dx=1;
	x2=0;
	at_first=TRUE;
	for(x=0;x<mx;x++) {
		if(at_first) {
			now=fgetc(fp);
			at_first=FALSE;
		}
		else {
			dr=getValue(fp);
			(now)+=dr;
		}
		printf("%c",now);
	}
}

int main(int ac,char *av[])
{
	FILE *fp;
	byte *image;
	int c,size;

	if ((fp = fopen(av[1],"rb"))==NULL)
		return 6;
	size=getLong(fp);
	decode(fp,size);
}
