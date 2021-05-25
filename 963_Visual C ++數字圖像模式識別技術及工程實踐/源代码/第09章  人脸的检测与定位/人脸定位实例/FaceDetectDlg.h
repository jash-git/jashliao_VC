// FaceDetectDlg.h : header file
//

#ifndef __FACEDETECTDLG_H
#define __FACEDETECTDLG_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Dib.h"
#include "LikelyHood.h"
#include "HairFace.h"
#include <afxtempl.h>
#include <math.h>

/////////////////////////////////////////////////////////////////////////////
// CFaceDetectDlg dialog

class CFaceDetectDlg : public CDialog
{
// Construction
public:
	CFaceDetectDlg(CWnd* pParent = NULL);	// standard constructor

	//��������
public:
	void MyDraw();
	void DoLOG(int left,int right,int top,int bottom,RGBQUAD** source,RGBQUAD** target);
	void SetPixelArray(RGBQUAD** target,int Val);
	void LoadOriPixel(CDib* pDib);
	void MakeBitMap();
	bool CopyBitMap(RGBQUAD** dest,RGBQUAD** source);
	void DrawCross(CDC* pDC,CPoint point,COLORREF crColor);

	CDC *pDCShow;//������ͼ������
	CDib *m_pMainDib;//λͼ
	RGBQUAD** m_tOriPixelArray;//ԭʼλͼ����
	RGBQUAD** m_tResPixelArray;//�ο�λͼ����

	CBitmap* 	m_pResMap;

	int m_nWndWidth;//ͼ����
	int m_nWndHeight;//ͼ��߶�
	CString m_sFileName;//λͼ����

	bool m_bFaceOK;//�����Ѿ�ȷ����־λ
	bool m_bShowFace;
	CRect m_rFaceRegion;//��������

	bool m_bSelectByMan;
	bool m_bLBottonDown;
	int m_ManLeft;
	int m_ManRight;
	int m_ManTop;
	int m_ManBottom;

	//������һЩ��־λ
	bool m_bManualMarkFacial;
	bool m_bLeftEyeOK;//����ȷ����־λ
	bool m_bRightEyeOK;//����ȷ����־λ
	bool m_bLeftEyeLeftCornerOK;//�������
	bool m_bLeftEyeRightCornerOK;//�����ҽ�
	bool m_bRightEyeLeftCornerOK;//�������
	bool m_bRightEyeRightCornerOK;//�����ҽ�
	bool m_bLeftNostrilOK;//��ǽ�
	bool m_bRightNostrilOK;//�ұǽ�
	bool m_bLeftMouthCornerOK;//�����
	bool m_bRightMouthCornerOK;//�����
	bool m_bMidMouthOK;//���в�
	bool m_bMidNoseOK;//�Ǽ�
	//����������Щ�������λ��
	CPoint m_LeftEye;
	CPoint m_LeftEyeLeftCorner;
	CPoint m_LeftEyeRightCorner;
	CPoint m_RightEye;
	CPoint m_RightEyeLeftCorner;
	CPoint m_RightEyeRightCorner;
	CPoint m_LeftNostril;
	CPoint m_RightNostril;
	CPoint m_LeftMouthCorner;
	CPoint m_RightMouthCorner;
	CPoint m_MidMouth;
	CPoint m_MidNose;

	//���ַ���
	CLikelyHood	*method1;
	CHairFace   *method2;

// Dialog Data
	//{{AFX_DATA(CFaceDetectDlg)
	enum { IDD = IDD_FACEDETECT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceDetectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFaceDetectDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnBinary();
	afx_msg void OnBtnEdge();
	afx_msg void OnBtnFacehair();
	afx_msg void OnBtnHistogramFace();
	afx_msg void OnBtnHistogramH();
	afx_msg void OnBtnHistogramHair();
	afx_msg void OnBtnHistogramV();
	afx_msg void OnBtnLikehood();
	afx_msg void OnBtnMarkEye();
	afx_msg void OnBtnMarkFace1();
	afx_msg void OnBtnMarkFace2();
	afx_msg void OnBtnMarkMouse();
	afx_msg void OnBtnMarkNose();
	afx_msg void OnBtnOpenfile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // #ifndef __FACEDETECTDLG_H
