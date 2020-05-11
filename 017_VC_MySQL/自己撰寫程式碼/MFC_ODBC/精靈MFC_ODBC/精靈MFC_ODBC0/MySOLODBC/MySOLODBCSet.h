// MySOLODBCSet.h : interface of the CMySOLODBCSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSOLODBCSET_H__E9F54194_54D0_4416_8214_33735851442F__INCLUDED_)
#define AFX_MYSOLODBCSET_H__E9F54194_54D0_4416_8214_33735851442F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMySOLODBCSet : public CRecordset
{
public:
	CMySOLODBCSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CMySOLODBCSet)

// Field/Param Data
	//{{AFX_FIELD(CMySOLODBCSet, CRecordset)
	long	m_id;
	CString	m_data1;
	double	m_data2;
	double	m_data3;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySOLODBCSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSOLODBCSET_H__E9F54194_54D0_4416_8214_33735851442F__INCLUDED_)

