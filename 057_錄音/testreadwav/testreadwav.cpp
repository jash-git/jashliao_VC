#include <stdio.h>
void main(void)
{
	FILE *pf,*pf1;
	int a=0;
	int b=0;
	pf=fopen("openfile.wav","rb");
	pf1=fopen("123.txt","w");
	while(fscanf(pf,"%c",&a)!=EOF)
	{
		b++;
		if(b>=16)
		{
			fprintf(pf1,"\n");
			b=1;
		}
		fprintf(pf1,"%x\t",a);
	}
	fclose(pf);
	fclose(pf1);
}