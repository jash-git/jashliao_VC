#include <iostream.h>
#include "StackUseException.h"
// 1. push 可能會send 出 例外
// 2. see push
void main()
{
	int v[11]={100,101,102,103,104,105,106,107,108,109,110};
	cout<<"push 11個整數到Stack...";
	int i;
	try
	{
		for(i=0;i<11;i++)
		{
			push(v[i]);
			cout<<"push "<<v[i]<<" ok.\n";
		}
	}
	catch(char* mes)
	{
		cerr<<mes;
	}
	cout<<"\n\n從Stack pop出11個整數...";
	try{
		for(i=0;i<11;i++)
		{
			pop(v[i]);
			cout<<"pop "<<v[i]<<".\n";
		}
	}
	catch(char* mes)
	{
		cerr<<mes;
	}
	cout<<endl;
}

