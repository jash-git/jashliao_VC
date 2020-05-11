#if !defined(AFX_LISTENERSOCKET_H__619314AE_2EBB_46D9_B0D6_8CB60EE36C32__INCLUDED_)
#define AFX_LISTENERSOCKET_H__619314AE_2EBB_46D9_B0D6_8CB60EE36C32__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListenerSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CListenerSocket command target

class CListenerSocket : public CSocket
{
// Attributes
public:

// Operations
public:
	CListenerSocket();
	virtual ~CListenerSocket();

// Overrides
public:
	void SetParent(CDialog* pWnd);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListenerSocket)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CListenerSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
private:
	CDialog* m_pWnd;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTENERSOCKET_H__619314AE_2EBB_46D9_B0D6_8CB60EE36C32__INCLUDED_)
