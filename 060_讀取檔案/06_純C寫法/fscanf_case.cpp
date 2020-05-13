#include <stdio.h>
main()
{
	FILE *p;
	int a=0;
	p=fopen("text.txt","w");
	scanf("%d",&a);
	for(int i=0;i<a;i++)
		fprintf(p,"%d\n",i);
	fclose(p);
	p=fopen("text.txt","r");
	while(fscanf(p,"%d",&a)!=EOF)
		printf("%d\n",a);
	fclose(p);
}