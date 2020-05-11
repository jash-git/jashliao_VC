#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrXorEncoder.h"
void main()
{
	char chrtest[]="http://www.google.com";
	int i=0;
	int intlenS=0;
	int data=-1;
	int j;
	printf("str1= %s\n",chrtest);
	CStrXorEncoder CSXE;
	intlenS=CSXE.XorEncoder(chrtest);
	printf("in=%d\n",intlenS);
	printf("str1 xor= ");
	FILE *pf='\0';
	pf=fopen("url.txt","w");
	for(i=0;i<intlenS;i++)
	{
		fprintf(pf,"%d,",CSXE.intEncoder[i]);
		printf("%d,",CSXE.intEncoder[i]);
	}
	fclose(pf);
	printf("\n");
	pf='\0';
	pf=fopen("url.txt","r");
	j=0;
	printf("str2= ");
	while(fscanf(pf,"%d,",&data)!=EOF)
	{
		printf("%d,",data);
		CSXE.intDecoder[j]=data;
		j++;
	}
	fclose(pf);
	printf("\n");
	CSXE.XorDecoder(j);
	printf("str2 xor= %s\n",CSXE.chrDecoder);
	system("pause");
}