// test_sprintf.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
int main(int argc, char* argv[])
{
	char d=0;
	char d='A';
	char buffer01[50];
	char buffer02[50];
	char buffer03[50];
	sprintf(buffer01, "%o",d);
	sprintf(buffer02, "%02o",d);
	sprintf(buffer03, "%03o",d);
	////////////////////////////
	return 0;
}

