// MySOLODBCSet.cpp : implementation of the CMySOLODBCSet class
//

#include "stdafx.h"
#include "MySOLODBC.h"
#include "MySOLODBCSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCSet implementation

IMPLEMENT_DYNAMIC(CMySOLODBCSet, CRecordset)

CMySOLODBCSet::CMySOLODBCSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CMySOLODBCSet)
	m_id = 0;
	m_data1 = _T("");
	m_data2 = 0.0;
	m_data3 = 0.0;
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}

CString CMySOLODBCSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=chtvdata");
}

CString CMySOLODBCSet::GetDefaultSQL()
{
	return _T("[chtvtable]");
}

void CMySOLODBCSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CMySOLODBCSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[data1]"), m_data1);
	RFX_Double(pFX, _T("[data2]"), m_data2);
	RFX_Double(pFX, _T("[data3]"), m_data3);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CMySOLODBCSet diagnostics

#ifdef _DEBUG
void CMySOLODBCSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void CMySOLODBCSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
