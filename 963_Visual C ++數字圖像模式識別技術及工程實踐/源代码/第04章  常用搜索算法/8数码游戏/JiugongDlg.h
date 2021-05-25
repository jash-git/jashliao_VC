// JiugongDlg.h : header file

#if !defined(AFX_JIUGONGDLG_H__D45D787F_FB0D_4560_9EED_23FA030D29E3__INCLUDED_)
#define AFX_JIUGONGDLG_H__D45D787F_FB0D_4560_9EED_23FA030D29E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "JiuG.h"

/////////////////////////////////////////////////////////////////////////////
// CJiugongDlg dialog

class CJiugongDlg : public CDialog
{
protected:
	CJiuG m_jiugong;//�Ź�״̬
// Construction
public:
	bool m_bobjdown;//ָʾ�Ƿ���Ŀ��״̬����
	bool m_binitdown;//ֻ���Ƿ��г�ʼ״̬����
	int m_nstep;//��ǰ����Ĳ���
	CJiugongDlg(CWnd* pParent = NULL);	// standard constructor
	void DrawJiuGong(CDC *pDC,int state[3][3]);//���Ź�
	bool CheckData(int state[3][3]);//������ݵ���Ч��

// Dialog Data
	//{{AFX_DATA(CJiugongDlg)
	enum { IDD = IDD_JIUGONG_DIALOG };
	CButton	m_bshow;
	CButton	m_bsearch;
	CButton	m_bup;
	CButton	m_bright;
	CButton	m_bleft;
	CButton	m_bdown;
	CString	m_stringState;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJiugongDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CDC *pDCInit,*pDCObj,*pDCCur;

	// Generated message map functions
	//{{AFX_MSG(CJiugongDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonDown();
	afx_msg void OnButtonInputInit();
	afx_msg void OnButtonInputObj();
	afx_msg void OnButtonLeft();
	afx_msg void OnButtonRight();
	afx_msg void OnButtonSearch();
	afx_msg void OnButtonShow();
	afx_msg void OnButtonUp();
	afx_msg void OnRadioMac();
	afx_msg void OnRadioMan();
	afx_msg void OnButtonAuto();
	afx_msg void OnButtonDepth();
	afx_msg void OnButtonHuifu();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JIUGONGDLG_H__D45D787F_FB0D_4560_9EED_23FA030D29E3__INCLUDED_)
