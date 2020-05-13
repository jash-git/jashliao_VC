// TransFormat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string>
using namespace std;

void int2String(int argNum,string *s)
{
	char buffer[100];
	sprintf(buffer,"%d",argNum);	
	
	*s=buffer;

}
int main(int argc, char* argv[])
{
	string s;
	int2String(10,&s);
	return 0;
}

