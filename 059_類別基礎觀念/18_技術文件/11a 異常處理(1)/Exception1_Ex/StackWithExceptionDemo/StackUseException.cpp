// StackUseException.cpp

#include "StackUseException.h"

int stackData[STACK_SIZE];
int position=-1;

void push(int data)
{
	if(position>=STACK_SIZE-1)
		throw "Stack is full!";
		
	position++;
	stackData[position]=data;
}

void pop(int& data)
{
	if(position<0)
		throw "Stack is empty!";
		
	data=stackData[position--];
}