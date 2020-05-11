// StrXorEncoder.cpp: implementation of the CStrXorEncoder class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"//¨¾¤îfatal error C1010: unexpected end of file while looking for precompiled header directive
#include "StrXorEncoder.h"
#include <string.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CStrXorEncoder::CStrXorEncoder()
{
	int i;
	for(i=0;i<1000;i++)
	{
		intEncoder[i]=0;
		intDecoder[i]=0;
		chrDecoder[i]=0;
	}
}
int CStrXorEncoder::XorEncoder(char *chrS)
{
	int i,j;
	int intlenxor=0;
	int intlenS=0;
	char gchrxor[]="what is a c/p programmer?";
	intlenxor=strlen(gchrxor);
	intlenS=strlen(chrS);
	char chrinput=0;
	char chrxor=0;
	j=0;
	for(i=0;i<intlenS;i++)
	{
		chrinput=*(chrS+i);
		if(j<intlenxor)
		{
			chrxor=*(gchrxor+j);
			j++;
		}
		else
		{
			j=0;
			chrxor=*(gchrxor+j);
		}
		intEncoder[i]=chrinput^chrxor;
	}
	return intlenS;
}
void CStrXorEncoder::XorDecoder(int len)
{
	int i,j;
	int intlenxor=0;
	int intlenS=len;
	char gchrxor[]="what is a c/p programmer?";
	intlenxor=strlen(gchrxor);
	char chrinput=0;
	char chrxor=0;
	j=0;
	for(i=0;i<intlenS;i++)
	{
		chrinput=intDecoder[i];
		if(j<intlenxor)
		{
			chrxor=*(gchrxor+j);
			j++;
		}
		else
		{
			j=0;
			chrxor=*(gchrxor+j);
		}
		chrDecoder[i]=chrinput^chrxor;
	}
}
CStrXorEncoder::~CStrXorEncoder()
{

}
