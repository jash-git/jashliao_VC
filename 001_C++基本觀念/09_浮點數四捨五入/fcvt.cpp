#include <stdio.h>
#include <stdlib.h>
main()
{
	float a=-0.3336f;
	int dec,sign;
	char *buf;
	printf("%f\n",a);
	buf=fcvt(a,3,&dec,&sign);
	printf("%s\n",buf);
	a=atoi(buf);
	if(sign==0)
		a/=1000.0f;
	else
		a/=-1000.0f;
	printf("%f\n",a);


}