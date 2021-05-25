/* ============================================= *\
 * File:		OnrDlg.h						 *
 * Description: ���Ի���ͷ�ļ�                   *
 *				�������еĺ���                   *
\* ============================================= */

#ifndef _ONRDLG_H_
#define _ONRDLG_H_

#if _MSC_VER >= 1000
#pragma once
#endif

#define NN_NUMBERS	9	//���������ĸ���
#define NN_RESX		5	//X����ĳ���
#define NN_RESY		7	//Y����ĳ���
#define NN_NOISY	25	//�������ݵ���Ŀ
#define NN_MAXITER	500	//���ѭ������

class COnrDlg : public CDialog {
public:
	COnrDlg(CWnd* pParent = NULL);

	//{{AFX_DATA(COnrDlg)
	enum { IDD = IDD_ONR_DIALOG };
	CSpinButtonCtrl	m_Trainspin;
	CSpinButtonCtrl	m_Testspin;
	CStatic		m_TrainInfo;
	CListBox	m_cInfoBox;
	CStatic		m_TestWindow;
	//}}AFX_DATA

	//{{AFX_VIRTUAL(COnrDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);
	//}}AFX_VIRTUAL

protected:
	//�����������
	int		m_bTestData[NN_NUMBERS][NN_RESX * NN_RESY];
	//�����׼ѵ������
	int		m_bNumbers[NN_NUMBERS][NN_RESX * NN_RESY];
	//�����ڱ�׼ѵ�����ݼ��������������
	int		m_iNoisy[NN_NUMBERS * NN_NOISY][NN_RESX * NN_RESY];
	//Ҫ��������
	int		*m_ipDrawNum;
	//Ҫ��ʾ���ַ���
	bool	m_bDisplayString;
	//�����Ȩֵ����
	float	m_fWeights[NN_NUMBERS][NN_RESX * NN_RESY];

	HICON	m_hIcon;
	CString m_Str;

	void	InvalidateNumber();
	void	GetText(CString &, int);
	void	RunNet(bool training);
	void	DrawNumber(CDC *, int *, CRect *);

	// Generated message map functions
	//{{AFX_MSG(COnrDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTrain();
	afx_msg void OnClassify();
	afx_msg void OnDeltaposTrainspin(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposTestspin(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}

#endif
