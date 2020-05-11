#include <stdio.h>
#include <string.h>
void strget(const char *data)
{
	int i;
	char buf[4];
	for(i=0;i<3;i++)
		buf[i]=*(data+3+i);
	buf[3]='\0';
	printf("%s\n",buf);
}
void main()
{
	char chrinput[]="127.0.0.1:6000";
	strget(chrinput);
}
