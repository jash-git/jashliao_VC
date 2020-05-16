// VMR9PlayerContorlDlg.h : header file
//

#if !defined(AFX_VMR9PLAYERCONTORLDLG_H__A23A832C_06C7_43A2_BDFA_28E62D0B7751__INCLUDED_)
#define AFX_VMR9PLAYERCONTORLDLG_H__A23A832C_06C7_43A2_BDFA_28E62D0B7751__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVMR9PlayerContorlDlg dialog

class CVMR9PlayerContorlDlg : public CDialog
{
// Construction
public:
	CVMR9PlayerContorlDlg(CWnd* pParent = NULL);	// standard constructor
	void CallPlayer();//CreateProcess step02
	bool ReadXMLConfig();
	void EmailError(CString StrWriteMessage);
	void WriteLogFile(int intindex,CString StrMessage);
	bool CreateDefaultList();
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	bool XMLList2TXTList();//step 3:Åª¨úXML
	///////////////////////////////////////////////
	//CArray Step_02
	CArray <CString,CString&> m_ArraySource;
	void InitList2CArray();
	void List2CArray();
	int m_intArrayCount;
	int m_intArrayIndex;
	CString StrLastDay;
	CString StrLastTime;
	///////////////////////////////////////////////
	CString GetMediaLen(CString StrSouFileName);
	bool DownLoadList();
// Dialog Data
	//{{AFX_DATA(CVMR9PlayerContorlDlg)
	enum { IDD = IDD_VMR9PLAYERCONTORL_DIALOG };
	CString	m_V1;
	long	m_V2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVMR9PlayerContorlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVMR9PlayerContorlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VMR9PLAYERCONTORLDLG_H__A23A832C_06C7_43A2_BDFA_28E62D0B7751__INCLUDED_)
