#include "msflexgrid.h"
#include "WBButton.h"


#include "Matrix.h"
#include "AFXDB.H"
#include "ODBCINST.H"
#include "float.h"//运用atof
#include "Afxdlgs.h"//控制打开保存对话框
//#include "CSpreadSheet.h"//控制Excel数据读写
#include "ResultDlg.h"
#include "Factor.h"
#include "MainFactor.h"
#include "QR_analysis.h"
// Added by ClassView// ProGram2Dlg.h : header file
//
//{{AFX_INCLUDES()

//}}AFX_INCLUDES

#if !defined(AFX_PROGRAM2DLG_H__542051E2_687F_4393_8665_4CCE04724282__INCLUDED_)
#define AFX_PROGRAM2DLG_H__542051E2_687F_4393_8665_4CCE04724282__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CProGram2Dlg dialog

class CProGram2Dlg : public CDialog
{
// Construction
public:
	bool IsNumber(CString str);
	CProGram2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CProGram2Dlg)
	enum { IDD = IDD_PROGRAM2_DIALOG };
	CEdit	m_Change;
	CMSFlexGrid	m_FlexGrid;
	int		m_MeanRows;///有效列数
	int		m_MeanCols;///有效的数据行数
	CString	m_sChange;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProGram2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CProGram2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnMenu1Exit();
	afx_msg void OnClickMsflexgrid1();
	afx_msg void OnMenu3About();
	afx_msg void OnMenu1Clearn();
	afx_msg void OnMenu1New();
	afx_msg void OnBuntonRowDown();
	afx_msg void OnButtonColDown();
	afx_msg void OnButtonColUp();
	afx_msg void OnButtonRowUp();
	afx_msg void OnMenu3Help();
	afx_msg void OnMenu2Main();
	afx_msg void OnMENU2ONorIN();
	afx_msg void OnMenu2Factors();
	afx_msg void OnKillfocusEditChange();
	afx_msg void OnMENU1GetIn();
	afx_msg void OnMENU1PutOut();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CMatrix ReadDataToMatrix(int Rows,int Cols);
	void showMatrix(CMatrix a);
	bool m_IsDataHasTabelOnCol;//标记数据是否有标题列
	bool m_IsDataHasTabel;//标记数据是否有标题行
	int m_lCol;//记录FlexGrid中最后点击的列
	int m_lRow;//记录FlexGrid中最后点击的行
	int m_NumCols;//指定FlexGrid控件的行列数
	int m_NumRows;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRAM2DLG_H__542051E2_687F_4393_8665_4CCE04724282__INCLUDED_)
