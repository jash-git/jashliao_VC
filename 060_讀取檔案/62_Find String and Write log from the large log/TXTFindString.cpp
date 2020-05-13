#include<stdio.h>
#include<fstream.h>
#include <stdlib.h>
#include <string.h>
void main(void)
{
	fstream a;
	char fg[700];
	char filename[80];
	char check[700];
	char *loc;
	bool blnfind=false;
	int intcount=0;
	cout<<"input a File Name ="<<"\t";
	cin.getline(filename,80);
	cout<<"input a check string ="<<"\t";
	cin.getline(check, 700);	
	a.open(filename,ios::in);
	FILE *pf;
	pf=fopen("123.txt","a");
	while(!a.eof())
	{
		intcount++;
		a.getline(fg,700);
		loc = strstr(fg, check);
		if(loc != NULL)
		{
			fprintf(pf,"%s\n",fg);
		}
	}
	fclose(pf);
	a.close();
}