#include<stdio.h>
#include<string.h>
void main()
{
	char a[11]="0123456789";
	char b[11];
	char *pa,*pb;
	int i=0,j=11;
	int k;
	pa=a;pb=b;
	*pb='\0';
	////////////////////////
	printf("a=%s\n",a);
	printf("pa=%s\n",pa);
	printf("b=%s\n",b);
	printf("pb=%s\n",pb);
	printf("\n");
	////////////////////////
	pa+=1;
	strcat(pb,pa);
	printf("a=%s\n",a);
	printf("(pa+1)=%s\n",pa);
	printf("b=%s\n",b);
	printf("(pb)=%s\n",pb);
	printf("\n");
	///////////////////////////
	pa-=1;
	*pb='\0';
	strcat(pb,pa);
	printf("a=%s\n",a);
	printf("(pa-1)=%s\n",pa);
	printf("b=%s\n",b);
	printf("(pb)=%s\n",pb);
	printf("\n");
	//////////////////////////
	pa=a;pb=b;
	*pb='\0';
	pa=pa+7;
	strcat(pb,pa);
	printf("(pb)=%s\n",pb);
	for(i=0;i<j;i++)
	{
		pa=a;
		pa=pa+i;
		printf("pa+%d=%s\n",i,pa);
		k=strcmp(pa,pb);
		if(k==0)
		{
			printf("check ok....\n");
			break;
		}
	}
}