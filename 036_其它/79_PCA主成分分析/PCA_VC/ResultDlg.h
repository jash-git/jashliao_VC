#include "Matrix.h"
#if !defined(AFX_RESULTDLG_H__5987D05B_6A12_441E_9C56_E324E172590B__INCLUDED_)
#define AFX_RESULTDLG_H__5987D05B_6A12_441E_9C56_E324E172590B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ResultDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CResultDlg dialog

class CResultDlg : public CDialog
{
// Construction
private:
	int m_resultkind;//结果类型
	int m_matrixNum;//矩阵数目
	CMatrix *m_Matrix;//矩阵数组
	int *m_J;//附加结果要求
public:
	void MatrixOut(CMatrix matrix,CString black,int matrixNum,bool isLastMatrix);
	void MatrixOut(CMatrix matrix,CString black);
	void TranMemberNumber(int resultkind,CMatrix Matrix[],int matrixNum,int J[]);
	CResultDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CResultDlg)
	enum { IDD = IDD_ResultDlg };
	CListBox	m_List1;
	//}}AFX_DATA
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CResultDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CResultDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESULTDLG_H__5987D05B_6A12_441E_9C56_E324E172590B__INCLUDED_)
