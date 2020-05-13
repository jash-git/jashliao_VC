#include <iostream.h>
#include "StackUseBool.h"

void push_value(int);
void pop_value();

void main()
{
	int v[11]={100,101,102,103,104,105,106,107,108,109,110};
	cout<<"push 11個整數到Stack...";
	int i;
	for(i=0;i<11;i++)
		push_value(v[i]);
	cout<<"\n\n從Stack pop出11個整數...";
	for(i=0;i<11;i++)
		pop_value();
	cout<<endl;
}

void push_value(int data)
{
	if(push(data))
		cout<<"push "<<data<<" ok.\n";
	else
		cout<<"push "<<data<<" error.";
}

void pop_value()
{
	int data;
	if(pop(data))
		cout<<"pop "<<data<<'.'<<endl;
	else
		cout<<"pop error.";
}