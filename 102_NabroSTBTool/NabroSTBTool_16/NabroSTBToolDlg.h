// NabroSTBToolDlg.h : header file
//

#if !defined(AFX_NABROSTBTOOLDLG_H__C9387B64_8F76_4987_A6BD_3198782B8F5B__INCLUDED_)
#define AFX_NABROSTBTOOLDLG_H__C9387B64_8F76_4987_A6BD_3198782B8F5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CNabroSTBToolDlg dialog
#include <afxtempl.h>//CArray Step_01 
class CNabroSTBToolDlg : public CDialog
{
// Construction
public:
	CNabroSTBToolDlg(CWnd* pParent = NULL);	// standard constructor
	void GetConfigParameter();//step 3:Åª¨úXML
	void GetSTBInformation();
	void GetSTBMovieInformation(CString StrSTBuid);
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	void ReadAVListXML(CString Struid);
	bool ConnectSTB(CString StrIP);
	void ReadSTBAVList(CString StrIP);
	void STBAddAVFile(CString Struid,CString StrIP);
	void STBDelAVFile(CString Struid,CString StrIP);
	CString GetFilePath2FileName(CString Strdata);
	CString CreatInfoFileHead(CString StrStart,CString StrEnd);
	bool iniFunction();
	static UINT ThreadFun(LPVOID lpram);//Step 1:°õ¦æºü
	static UINT Thread50Fun(LPVOID lpram);
	////////////////////////////////////////////////
	CString m_StrEnableSTBUrl;
	CString m_StrEnableuidUrl;
	CString m_StrNetDir;
	CArray <CString,CString&> m_ArraySTBuid;//CArray Step
	CArray <CString,CString&> m_ArraySTBIP;//CArray Step
	CArray <CString,CString&> m_ArrayFileSourcePath;
	CArray <CString,CString&> m_ArrayFileDestPath;
	CArray <CString,CString&> m_ArrayFileStartDate;
	CArray <CString,CString&> m_ArrayFileEndDate;
	CArray <CString,CString&> m_ArrayBrowseData;
// Dialog Data
	//{{AFX_DATA(CNabroSTBToolDlg)
	enum { IDD = IDD_NABROSTBTOOL_DIALOG };
	CIPAddressCtrl	m_IP;
	CButton	m_testButton;
	CString	m_Uid;
	CString	m_State;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNabroSTBToolDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CNabroSTBToolDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Ontest();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NABROSTBTOOLDLG_H__C9387B64_8F76_4987_A6BD_3198782B8F5B__INCLUDED_)
