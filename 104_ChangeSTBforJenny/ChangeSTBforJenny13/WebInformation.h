#if !defined(AFX_WEBINFORMATION_H__475BA61B_CDAD_45A2_87DB_8C40228ED233__INCLUDED_)
#define AFX_WEBINFORMATION_H__475BA61B_CDAD_45A2_87DB_8C40228ED233__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WebInformation.h : header file
//
#include "SuperLabel.h"
/////////////////////////////////////////////////////////////////////////////
// CWebInformation dialog

class CWebInformation : public CDialog
{
// Construction
public:
	CWebInformation(CWnd* pParent = NULL);   // standard constructor
	void SetInformation(CString StrUrl,CString StrName,CString StrPassWord);
	CSuperLabel m_SLabel;
	CString m_StrUrl;
	CString m_StrName;
	CString m_StrPassWord;
// Dialog Data
	//{{AFX_DATA(CWebInformation)
	enum { IDD = IDD_WebInfor };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebInformation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWebInformation)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WEBINFORMATION_H__475BA61B_CDAD_45A2_87DB_8C40228ED233__INCLUDED_)
