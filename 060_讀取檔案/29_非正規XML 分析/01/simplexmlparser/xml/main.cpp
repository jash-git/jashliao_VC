#include <iostream.h>
#include <afx.h>
#include "Function.h"

#define FILENAME "web.xml"//³õÊ¼xmlÎÄ¼þ

xmlnode node[1000]; 
int count=0;

void main()
{
	CString context=openfile(FILENAME);
	str2array(context);

	for(int i=0;i<count;i++)
		cout<<node[i].name<<"    "<<node[i].value<<"    "<<node[i].id<<endl;
}