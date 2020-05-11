
// MainFrm.h : CMainFrame 類別的介面
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // 僅從序列化建立
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 屬性
public:

// 作業
public:
// 覆寫
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	
// 程式碼實作
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg LRESULT On_click0(WPARAM wparam,LPARAM lparam);//HOOK回應事件
};


