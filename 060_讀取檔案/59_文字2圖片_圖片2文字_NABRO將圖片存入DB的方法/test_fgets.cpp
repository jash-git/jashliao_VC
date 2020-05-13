// test_fgets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int oct2dec(char *chrdata,int intlen)
{
	int i,j,k;//迴圈變數
	int sum;
	sum=0;
	k=0;
	for(i=(intlen-1);i>=0;i--)
	{
			j=*(chrdata+i);
			switch(j)
			{
				case  48:
					sum+=0*pow(8.0,k);
					break;
				case  49:
					sum+=1*pow(8.0,k);
					break;
				case  50:
					sum+=2*pow(8.0,k);
					break;
				case  51:
					sum+=3*pow(8.0,k);
					break;
				case  52:
					sum+=4*pow(8.0,k);
					break;
				case  53:
					sum+=5*pow(8.0,k);
					break;
				case  54:
					sum+=6*pow(8.0,k);
					break;
				case  55:
					sum+=7*pow(8.0,k);
					break;
			}
			k++;
	}
	return sum;
}

int main(int argc, char* argv[])
{
	FILE *fPtr;
    char s[4];
	int int_d;
	char chr_d;
	FILE *fPtw;
	fPtw= fopen("123.jpg","wb");
    fPtr = fopen("aa.txt","r");
    if (!fPtr) {
        printf("檔案開啟失敗...\n");
        exit(1);
    }
    while (fgets(s, 4, fPtr) != NULL) {
		chr_d=oct2dec(s,3);
		fwrite(&chr_d, sizeof(char), 1, fPtw);
        printf("%s\n",s);
    }

    fclose(fPtr);
	fclose(fPtw);
	FILE *file = fopen("123.jpg", "rb");
	FILE *file1 = fopen("bb.txt", "w");
	unsigned char unchr_d;
	while(!feof(file))
	{
		fread(&unchr_d, sizeof(unsigned char), 1, file);
		printf("%03o\n",unchr_d);
		char buffer01[3];
		sprintf(buffer01, "%03o",unchr_d);
		fprintf(file1,"%s",buffer01);
	}
    fclose(file1);
	fclose(file);
    return 0;
   
}

