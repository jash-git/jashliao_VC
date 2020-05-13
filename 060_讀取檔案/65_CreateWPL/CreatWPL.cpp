#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
const char *data01="<?wpl version=\"1.0\"?>";
const char *data02="<smil>";
const char *data03="<title>create wpl by jash</title>";
const char *data04="<seq>";
const char *data05="<media src=\"";
const char *data06="\"/>";
const char *data07="</seq>";
const char *data08="</smil>";
int main(void)
{
	FILE *pfwpl;
	pfwpl=fopen("test.wpl","w");
	fprintf(pfwpl,"%s\n",data01);
	fprintf(pfwpl,"%s\n",data02);
	fprintf(pfwpl,"%s\n",data03);
	fprintf(pfwpl,"%s\n",data04);
	fstream flistdata;
	char chrlistdata[700];
	flistdata.open("list.txt",ios::in);
	while(!flistdata.eof())
	{
		flistdata.getline(chrlistdata,700);
		int len=strlen(chrlistdata);
		if(len>0)
		{
			fprintf(pfwpl,"%s",data05);
			fprintf(pfwpl,"%s",chrlistdata);
			fprintf(pfwpl,"%s\n",data06);
		}
	}
	fprintf(pfwpl,"%s\n",data07);
	fprintf(pfwpl,"%s\n",data08);
	fclose(pfwpl);
	flistdata.close();
	return 0;
}
