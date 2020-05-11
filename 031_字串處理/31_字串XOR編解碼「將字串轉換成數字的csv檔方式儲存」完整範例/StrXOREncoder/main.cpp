#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char gchrxor[]="what is a c/p programmer?";
int intEncoder[1000]={-1};
int intDecoder[1000]={-1};
char chrDecoder[1000];
int XorEncoder(char *chrS)
{
	int i,j;
	int intlenxor=0;
	int intlenS=0;
	intlenxor=strlen(gchrxor);
	intlenS=strlen(chrS);
	char chrinput=0;
	char chrxor=0;
	j=0;
	for(i=0;i<intlenS;i++)
	{
		chrinput=*(chrS+i);
		if(j<intlenxor)
		{
			chrxor=*(gchrxor+j);
			j++;
		}
		else
		{
			j=0;
			chrxor=*(gchrxor+j);
		}
		intEncoder[i]=chrinput^chrxor;
	}
	return intlenS;
}
void XorDecoder(int len)
{
	int i,j;
	int intlenxor=0;
	int intlenS=len;
	intlenxor=strlen(gchrxor);
	char chrinput=0;
	char chrxor=0;
	j=0;
	for(i=0;i<intlenS;i++)
	{
		chrinput=intDecoder[i];
		if(j<intlenxor)
		{
			chrxor=*(gchrxor+j);
			j++;
		}
		else
		{
			j=0;
			chrxor=*(gchrxor+j);
		}
		chrDecoder[i]=chrinput^chrxor;
	}
}
void main()
{
	char chrtest[]="http://www.google.com";
	int i=0;
	int intlenS=0;
	int data=-1;
	int j;
	intlenS=XorEncoder(chrtest);
	printf("in=%d\n",intlenS);
	FILE *pf='\0';
	pf=fopen("url.txt","w");
	for(i=0;i<intlenS;i++)
	{
		fprintf(pf,"%d,",intEncoder[i]);
		printf("%d,",intEncoder[i]);
	}
	fclose(pf);
	printf("\n");
	pf='\0';
	pf=fopen("url.txt","r");
	j=0;
	while(fscanf(pf,"%d,",&data)!=EOF)
	{
		printf("%d,",data);
		intDecoder[j]=data;
		j++;
	}
	fclose(pf);
	printf("\n");
	XorDecoder(j);
	printf("%s\n",chrDecoder);
	system("pause");
}
