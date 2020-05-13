#include "StackUseBool.h"

int stackData[STACK_SIZE];
int position=-1;

bool push(int data)
{
	if(position>=STACK_SIZE-1)
		return false;

	position++;
	stackData[position]=data;
	return true;
}

bool pop(int& data)
{
	if(position<0)
		return false;

	data=stackData[position--];
	return true;
}