#if !defined(AFX_LISTENSOCKET_H__FFA3E0A2_950F_4498_B1C2_B4234CF6BDC9__INCLUDED_)
#define AFX_LISTENSOCKET_H__FFA3E0A2_950F_4498_B1C2_B4234CF6BDC9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListenSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// ListenSocket command target

class ListenSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	ListenSocket();
	virtual ~ListenSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ListenSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(ListenSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTENSOCKET_H__FFA3E0A2_950F_4498_B1C2_B4234CF6BDC9__INCLUDED_)
