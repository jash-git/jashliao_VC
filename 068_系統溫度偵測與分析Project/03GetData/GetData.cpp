#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
using namespace std;
void main(void)
{
	char tex[250];
	char data[250];
	char CPU[3]={"\n"},HD[3]={"\n"};
	int i=1,j=0;
	ifstream ifile("C:\\123.txt",ios::in);
	ifstream ifile1;
	FILE *pf,*pf1;
	pf=fopen("cpu_hd.txt","w");
	while(!ifile.eof())
	{
		ifile.getline(tex,250);  
		//ifile1.open(tex,ios::in);
		pf1=fopen(tex,"r");
		i=1;
		while(fgets(data,250,pf1)!=NULL)
		{
			//ifile1.getline(data,250);
			if(i==42||i==76)
			{
				if(i==42)
				{
					CPU[0]=data[21];
					CPU[1]=data[22];
					CPU[2]='\0';
				}
				if(i==76)
				{
					HD[0]=data[21];
					HD[1]=data[22];
					HD[2]='\0';
				}
			}
			i++;
		}
		j++;
		cout<<"²Ä"<<j<<"ÀÉ\n";
		fprintf(pf,"%s,%s\n",CPU,HD);
		fclose(pf1); 
	}
	ifile.close(); 
	fclose(pf);
}