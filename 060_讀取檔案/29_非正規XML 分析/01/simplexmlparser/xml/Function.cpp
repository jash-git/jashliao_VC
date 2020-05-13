#include <afx.h>
#include <stdio.h>
#include <iostream.h>

#include "Function.h"

extern xmlnode node[1000];
extern count;

CString openfile(CString file)
{
	CString context;
	char ch;
	FILE *of;
	of=fopen(file,"r");
	ch=fgetc(of);
	while(ch!=EOF)
	{
		context+=ch;
		ch=fgetc(of);
	}
	return context;
}

CString getcontext(CString context,int i,int j)
{
	CString str;
	for(int k=i+1;k<j;k++)
	{
		str+=context[k];
	}
	return str;
}

void str2array(CString context)
{
	CString firstname;
	CString nextname;
	CString tempname;
	CString tempvalue;
	CStringArray stack;
	stack.Add("");
	int max=0;
	int nid=1;
	int k=0;
	int i1,i2,j1,j2,k1,k2;
	while((k<context.GetLength())&&(context[k]!='<'))
	{
		k++;
	}
	i1=k;

	while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
	{
		k++;
	}
	k1=k;

	while((k<context.GetLength())&&(context[k]!='>'))
	{
		k++;
	}
	j1=k;

	firstname=getcontext(context,i1,k1);

	while((k<context.GetLength())&&(context[k]!='<'))
	{
		k++;
	}
	i2=k;

	while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
	{
		k++;
	}
	k2=k;

	while((k<context.GetLength())&&(context[k]!='>'))
	{
		k++;
	}
	j2=k;

	nextname=getcontext(context,i2,k2);
	tempname='/'+firstname;

	

	while(k<context.GetLength())
	{
		if(tempname.Compare(nextname)==0)
		{
			node[count].name=firstname;
			tempvalue=getcontext(context,j1,i2);
			tempvalue.TrimLeft();
			tempvalue.TrimRight();
			node[count].value=tempvalue;
			node[count].id=nid;
			count++;
			do
			{
				while((k<context.GetLength())&&(context[k]!='<'))
				{
					k++;
				}
				i2=k;

				while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
				{
					k++;
				}
				k2=k;

				while((k<context.GetLength())&&(context[k]!='>'))
				{
					k++;
				}
				j2=k;

				nextname=getcontext(context,i2,k2);
				if(nextname.Compare(stack.GetAt(max))==0)
				{
					stack.RemoveAt(max);
					nid--;
					max--;
				}
			}while((nextname.GetLength()>0)&&(nextname[0]=='/'));
			//same
		}
		else
		{
			tempname='/'+firstname;
			max++;
			stack.Add(tempname);
			node[count].name=firstname;
			node[count].value="";
			node[count].id=nid;
			count++;
			nid++;
			//different
		}

		firstname=nextname;
		i1=i2;
		k1=k2;
		j1=j2;

		while((k<context.GetLength())&&(context[k]!='<'))
		{
			k++;
		}
		i2=k;

		while((k<context.GetLength())&&(context[k]!=' ')&&(context[k]!='>'))
		{
			k++;
		}
		k2=k;

		while((k<context.GetLength())&&(context[k]!='>'))
		{
			k++;
		}
		j2=k;

		nextname=getcontext(context,i2,k2);
		tempname='/'+firstname;
	}
}