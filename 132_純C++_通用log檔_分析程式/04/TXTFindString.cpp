#include<stdio.h>
#include<fstream.h>
#include <stdlib.h>
#include <string.h>
struct check_struct
{
	char chrfindstring[100];
	char chrlogname[100];
	char chrmessage[100];
	int intcount;
};
void main(int argc, char *argv[])
{
	fstream a;//用來讀取log檔
	fstream checkfile;//用來讀取分析設定檔
	char fg[700];//存放每一行log
	char filename[80];//存放log檔的檔名
	char check[700];//存放每一行分析設定檔資料,比對字串
	char *loc;//存放比較字串後的結果
	int intcount=0;//用來計算筆數
	if(argc<2)
	{
		/////////////////////////////////////////
		cout<<"input a File Name ="<<"\t";
		cin.getline(filename,80);
		/////////////////////////////////////////
	}
	else
	{
		strcpy(filename,argv[1]);
	}
	//計算分析設定檔的筆數
	checkfile.open("check.txt",ios::in);
	while(!checkfile.eof())
	{
		checkfile.getline(check,500);
		if(strlen(check)>0)
			intcount++;
	}
	checkfile.close();
	//====
	//配置記憶體並將分析設定檔載入記憶體
	char buf0[100],buf1[100],buf2[100];
	struct check_struct *cs;
	cs=new struct check_struct[intcount];
	checkfile.open("check.txt",ios::in);
	intcount=0;
	while(!checkfile.eof())
	{
		checkfile.getline(check,500);
		if(strlen(check)>0)
		{
			sscanf(check,"%[^','],%[^','],%[^','],",buf0,buf1,buf2);
			strcpy((cs+intcount)->chrfindstring,buf0);
			strcpy((cs+intcount)->chrlogname,buf1);
			strcpy((cs+intcount)->chrmessage,buf2);
			(cs+intcount)->intcount=0;
			intcount++;
		}
	}
	checkfile.close();
	///////////////////////////////////////
	//進行檔案分析
	int i;
	a.open(filename,ios::in);
	FILE *pf;
	FILE *pfdata;
	while(!a.eof())
	{
		a.getline(fg,700);
		for(i=0;i<intcount;i++)
		{
			strcpy(check,(cs+i)->chrfindstring);
			loc = strstr(fg, check);
			if(loc!='\0')
			{
				pfdata='\0';
				pfdata=fopen((cs+i)->chrlogname,"a");
				fprintf(pfdata,"%s\n",fg);
				fclose(pfdata);
				pfdata='\0';
				(cs+i)->intcount++;
			}
		}
	}
	pf=fopen("log.txt","w");
	for(i=0;i<intcount;i++)
	{
		fprintf(pf,"%s,%d\n",(cs+i)->chrmessage,(cs+i)->intcount);
	}
	fclose(pf);
	a.close();
	delete []cs;
}