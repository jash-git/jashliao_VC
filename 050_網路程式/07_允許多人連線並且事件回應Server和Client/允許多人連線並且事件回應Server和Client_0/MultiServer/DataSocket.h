#if !defined(AFX_DATASOCKET_H__BF971F4F_351B_457C_940F_ADFE32CA373E__INCLUDED_)
#define AFX_DATASOCKET_H__BF971F4F_351B_457C_940F_ADFE32CA373E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataSocket.h : header file
//
struct DataType
{
	long lngNumber;//用來判斷更新參數
	char chrFirstData[10];//掛號
	char chrSecondData[10];//單號
	char chrThirdData[10];//雙號
	char chrFourthData[10];//小兒科
};

/////////////////////////////////////////////////////////////////////////////
// CDataSocket command target

class CDataSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CDataSocket();
	virtual ~CDataSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CDataSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASOCKET_H__BF971F4F_351B_457C_940F_ADFE32CA373E__INCLUDED_)
