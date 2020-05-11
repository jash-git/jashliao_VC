#include <stdio.h>
#include "Fuzzy.h"
void main()
{
	float k,j;
	CFuzzy fuzzy1,fuzzy2,outfuzzy;
	fuzzy1.InputFun(6.5f);
	fuzzy2.InputFun(-7.0f);
	printf("%f\t%f\t%f\t%f\t%f\n",fuzzy1.SwInputMem[0],fuzzy1.SwInputMem[1],fuzzy1.SwInputMem[2],fuzzy1.SwInputMem[3],fuzzy1.SwInputMem[4]); 
	printf("%f\t%f\t%f\t%f\t%f\n",fuzzy2.SwInputMem[0],fuzzy2.SwInputMem[1],fuzzy2.SwInputMem[2],fuzzy2.SwInputMem[3],fuzzy2.SwInputMem[4]);
	k=outfuzzy.FuzzyOutPut(&j,fuzzy1.SwInputMem,fuzzy2.SwInputMem);
	printf("%f\n",k);
}