// Math.cpp: implementation of the CMath class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "mfcdll.h"
#include "Math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMath::CMath()
{
	this->m_dblData1=0.0;
	this->m_dblData2=0.0;
}

CMath::~CMath()
{

}
void CMath::add(double a,double b)
{
	this->m_dblData1=a;
	this->m_dblData2=b;
	this->m_dblData3=this->m_dblData1+this->m_dblData2;
}