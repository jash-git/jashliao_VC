#include<stdio.h>
#include<fstream.h>
#include <stdlib.h>
#include <string.h>
void main(void)
{
	fstream a;
	char fg[700];
	char check[700];
	char *loc;
	bool blnfind=false;
	int intcount=0;
	cout<<"input a check string ="<<"\t";
	cin.getline(check, 700);
	a.open("media.txt",ios::in);
	while(!a.eof())
	{
		intcount++;
		a.getline(fg,700);
		loc = strstr(fg, check);
		if(loc != NULL)
		{
			cout<< "檔案內容= " << fg <<"\n";
			cout<< "比較內容= " << check <<"\n";
			printf("行號%d處找到子字串\n",intcount);
			printf("在索引位置 %d 處找到子字串\n", loc - fg);
			blnfind=true;
			break;
		}
	}
	if(blnfind==false)
		printf("找不到符合的子字串\n");
	a.close();
}