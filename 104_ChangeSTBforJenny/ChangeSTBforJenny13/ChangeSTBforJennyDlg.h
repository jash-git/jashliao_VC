// ChangeSTBforJennyDlg.h : header file
//

#if !defined(AFX_CHANGESTBFORJENNYDLG_H__F98B2190_BCCD_4A4F_AFC7_EF4F77B19CCD__INCLUDED_)
#define AFX_CHANGESTBFORJENNYDLG_H__F98B2190_BCCD_4A4F_AFC7_EF4F77B19CCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChangeSTBforJennyDlg dialog
#include <afxtempl.h>//CArray Step_01 
class CChangeSTBforJennyDlg : public CDialog
{
// Construction
public:
	CChangeSTBforJennyDlg(CWnd* pParent = NULL);	// standard constructor
	bool iniFunction();
	void GetConfigParameter();//step 3:Åª¨úXML
	bool GetWebFile(CString theUrl, CString Filename);//http_download
	void GetSTBInformation();
	void GetSTBMovieInformation(CString StrSTBuid);
	static UINT ThreadRegistration(LPVOID lpram);
	void RegistrationFunction();
	CString GetMac();
	static UINT ThreadMovie(LPVOID lpram);
	void Movie();
	void STBAddAVFile(CString Struid,CString StrIP);
	void STBDelAVFile(CString Struid,CString StrIP);
	void ReadAVListXML(CString Struid);
	bool ConnectSTB(CString StrIP);
	void ReadSTBAVList(CString StrIP);
	CString GetFilePath2FileName(CString Strdata);
	CString CreatInfoFileHead(CString StrStart,CString StrEnd);
	static UINT ThreadDownLoadMovieList(LPVOID lpram);
	void DownLoadMovieList();
	static UINT ThreadUpdateData(LPVOID lpram);
	void UpdateDataFun();
	static UINT ThreadALLAuto(LPVOID lpram);
	void ALLAuto();
	//////////////////////////////////////////////////////Step02_Start:ODBC
	CDatabase *m_DB;
	CRecordset *m_RS;
	CDatabase *m_WebDB;
	CRecordset *m_WebRS;
	CString m_StrSouODBC;
	CString m_StrSouWebODBC;
	//////////////////////////////////////////////////////Step02_end:ODBC
	CString m_StrEnableSTBUrl;
	CString m_StrEnableuidUrl;
	CString m_StrNetDir;
	CString m_StrNowIP;
	CString m_StrNowUID;
	CString m_StrSTBMAC;
	CString m_StrSTBSTBGUID;
	CArray <CString,CString&> m_ArraySTBuid;//CArray Step
	CArray <CString,CString&> m_ArraySTBIP;//CArray Step
	CArray <CString,CString&> m_ArrayFileSourcePath;
	CArray <CString,CString&> m_ArrayFileDestPath;
	CArray <CString,CString&> m_ArrayFileStartDate;
	CArray <CString,CString&> m_ArrayFileEndDate;
	CArray <CString,CString&> m_ArrayBrowseData;
// Dialog Data
	//{{AFX_DATA(CChangeSTBforJennyDlg)
	enum { IDD = IDD_CHANGESTBFORJENNY_DIALOG };
	CComboBox	m_ComboSTBCommand;
	CButton	m_ButtSTBCommand;
	CButton	m_ButtCompletionSerch;
	CButton	m_ButtEIPFlow;
	CButton	m_ButtTUKA;
	CButton	m_ButtDeleteMovie;
	CIPAddressCtrl	m_IP;
	CComboBox	m_ComboVolume;
	CButton	m_ButtVolume;
	CButton	m_ButtUpdateData;
	CButton	m_ButtSetIPandUID;
	CButton	m_ButtSelectLayout;
	CButton	m_ButtRemoteControl;
	CButton	m_ButtRegistration;
	CButton	m_ButtMovie;
	CButton	m_ButtLayout;
	CButton	m_ButtBootTime;
	CButton	m_ButtALLAuto;
	CString	m_ShowState;
	BOOL	m_blnLayout;
	BOOL	m_blnMovie;
	BOOL	m_blnRegist;
	BOOL	m_blnRemoteControl;
	BOOL	m_blnTime;
	BOOL	m_blnUpdateData;
	BOOL	m_blnVolume;
	CString	m_StrLayout;
	CString	m_StrTime;
	CString	m_StrUID;
	BOOL	m_blnDeleteMovie;
	BOOL	m_blnTUKA;
	BOOL	m_blnEIPFlow;
	BOOL	m_blnCompletionSerch;
	BOOL	m_blnSTBCommand;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChangeSTBforJennyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChangeSTBforJennyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnButtSetIPandUID();
	afx_msg void OnButtSelectLayout();
	afx_msg void OnButtRegistration();
	afx_msg void OnButtMovie();
	afx_msg void OnButtLayout();
	afx_msg void OnButtVolume();
	afx_msg void OnButtBootTime();
	afx_msg void OnFieldchangedIpaddress(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButtUpdateData();
	afx_msg void OnButtALLAuto();
	afx_msg void OnButtRemoteControl();
	afx_msg void OnButtDeleteMovie();
	afx_msg void OnButtTUKA();
	afx_msg void OnButtEIPFlow();
	afx_msg void OnButtCompletionSerch();
	afx_msg void OnButtSTBCommand();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHANGESTBFORJENNYDLG_H__F98B2190_BCCD_4A4F_AFC7_EF4F77B19CCD__INCLUDED_)
