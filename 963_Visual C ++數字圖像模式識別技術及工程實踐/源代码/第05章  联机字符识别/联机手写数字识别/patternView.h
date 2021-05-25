// patternView.h : interface of the CPatternView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PATTERNVIEW_H__696AB6FA_20EF_46BB_B9DE_8654C84DC5DE__INCLUDED_)
#define AFX_PATTERNVIEW_H__696AB6FA_20EF_46BB_B9DE_8654C84DC5DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct tezheng{
	signed char value;//����ֵ
	signed char VHDerection[15];//ˮƽ��ֱ����
	//right--1  down--2 left--3  up-4
	signed char lenth1;//��һ���ʻ�����1��4 >4
	signed char lenth;//���һ������ĳ���1��4(1)  >4(2)
	signed char decon;//���޶ϵ� ����1�жϵ�
	signed char lenfirst;
	signed char lenend;
}TEZHENG;

class CPatternView : public CView
{
protected: // create from serialization only
	CPatternView();
	DECLARE_DYNCREATE(CPatternView)
//�Լ�����ı���
public:
	unsigned char bitgraph[16][16];//Ϊ���Ժ����չʱ��ɨ��ͼ������
	int mouseDown;
	CPoint mypoint[100],oldpoint;//ģ����д������
	int mytime;//��д�������ʱ������
	int curvalue;//��ǰ���������
	TEZHENG *mytezheng;
	CFile cf;//���ڱ����������ļ�

// Attributes
public:
	CPatternDoc* GetDocument();

// Operations
public:
	void GetTeZheng(void);
	void OnStudy(void);
	void OnRecognize(void);
	void OnClear(void);
	void OnMyHelp(void);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPatternView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPatternView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPatternView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in patternView.cpp
inline CPatternDoc* CPatternView::GetDocument()
   { return (CPatternDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATTERNVIEW_H__696AB6FA_20EF_46BB_B9DE_8654C84DC5DE__INCLUDED_)
