/*
**	File:	hmmrand.cpp
**	���ܣ������������������ʹ�����ಿ�ֵĴ����Ϊƽ̨�޹صġ�
*/

#include "StdAfx.h"
#include <stdlib.h>
#include <math.h>

/*
** �õ�һ����������ӣ����Ը����Լ�������޸ĸú���
*/
int  hmmgetseed(void) 
{
	return (17*rand());
}

/* 
** �������������
*/
void hmmsetseed(int seed) 
{
	srand(seed);
}

/*
**  �õ�0��1֮���һ��˫���������
*/

double hmmgetrand(void)
{
	return (double) rand()/RAND_MAX;
}

