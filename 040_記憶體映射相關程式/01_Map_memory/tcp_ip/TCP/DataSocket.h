#if !defined(AFX_DATASOCKET_H__86FEC07B_30E2_48AD_B45B_387AE7D6CB1F__INCLUDED_)
#define AFX_DATASOCKET_H__86FEC07B_30E2_48AD_B45B_387AE7D6CB1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DataSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// DataSocket command target

class DataSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	DataSocket();
	virtual ~DataSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DataSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(DataSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASOCKET_H__86FEC07B_30E2_48AD_B45B_387AE7D6CB1F__INCLUDED_)
