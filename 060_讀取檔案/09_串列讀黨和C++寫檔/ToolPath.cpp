// ToolPath.cpp: implementation of the CToolPath class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ToolPath.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_SERIAL(CToolPath,CObject,1)
CToolPath::CToolPath()
{
	this->m_State=0;
	this->m_CPStart.x=0;
	this->m_CPStart.y=0;
	this->m_CPEnd.x=0;
	this->m_CPEnd.y=0;  
}

CToolPath::~CToolPath()
{

}
void CToolPath::SetState(int state)
{
	this->m_State=state;
}
int CToolPath::GetState()
{
	return this->m_State; 
}
void CToolPath::Serialize(CArchive& ar)
{
	CObject::Serialize(ar); 
	if (ar.IsStoring())
	{	// storing code
		ar<<m_State<<m_CPStart<<m_CPEnd;
	}
	else
	{	// loading code
		ar>>m_State>>m_CPStart>>m_CPEnd;
	}
}