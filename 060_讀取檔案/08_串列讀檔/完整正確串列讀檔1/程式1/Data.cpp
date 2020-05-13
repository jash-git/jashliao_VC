// Data.cpp: implementation of the CData class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FileWork.h"
#include "Data.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CData,CObject,1)
CData::CData()
{

}

CData::~CData()
{

}
void CData::Serialize(CArchive& ar)
{
	CObject::Serialize(ar); 
	if (ar.IsStoring())
	{	// storing code
		ar<<strData;
	}
	else
	{	// loading code
		ar>>strData;
	}
}