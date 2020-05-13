#include <stdio.h>
int main ()
{
	FILE *fp;
	int intvalue;
	printf("set a value =  ");
	scanf("%d",&intvalue);
	if(intvalue>=1)
	{
		fp=fopen("myfile.txt","w");
	}
	else
	{
		remove("myfile.txt");
	}
}
