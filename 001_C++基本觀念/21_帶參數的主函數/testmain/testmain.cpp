#include <iostream.h>
void main(int argc, char *argv[])
{
	int i;
	for(i=0;i<argc;i++)
	cout <<"argv["<<i<<"]"<<argv[i]<<"\t";
}