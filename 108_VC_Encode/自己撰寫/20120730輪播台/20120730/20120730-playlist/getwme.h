//{{AFX_INCLUDES()
#include "webbrowser2.h"
//}}AFX_INCLUDES
#if !defined(AFX_GETWME_H__55A3DC9C_6EAD_483D_9012_2CD883D027CD__INCLUDED_)
#define AFX_GETWME_H__55A3DC9C_6EAD_483D_9012_2CD883D027CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// getwme.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// getwme dialog

class getwme : public CDialog
{
// Construction
public:
	getwme(CWnd* pParent = NULL);   // standard constructor
	bool DownLoadList();
	void WriteLogFile(int intindex,CString StrMessage);
	CString GetMediaLen(CString StrSouFileName);
	bool CreateDefaultList();
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	bool XMLList2TXTList();//step 3:Åª¨úXML
	void EmailError(CString StrWriteMessage);
	void getwme1(void);
	void getlist(bool redo);
	void run(void);
	void Add2Group(int num,int next,char *filename,int in,int out);
	BOOL SearchFile(CString StrFileName);
// Dialog Data
	//{{AFX_DATA(getwme)
	enum { IDD = IDD_GETWME };
	CListBox	m_list;
	CWebBrowser2	m_Web;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(getwme)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:

	// Generated message map functions
	//{{AFX_MSG(getwme)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETWME_H__55A3DC9C_6EAD_483D_9012_2CD883D027CD__INCLUDED_)
