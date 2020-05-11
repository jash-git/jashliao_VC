
// USB_FramView.h : CUSB_FramView 類別的介面
//


#pragma once
#include <mshtml.h>
#include <comdef.h>
#include <atlbase.h>
#include <mshtmhst.h>

class CUSB_FramView : public CHtmlView
{
protected: // 僅從序列化建立
	CUSB_FramView();
	DECLARE_DYNCREATE(CUSB_FramView)

// 屬性
public:
	CUSB_FramDoc* GetDocument() const;

// 作業
public:
	BOOL CheckInternet(LPCTSTR URL);//判斷網路是否正常
	void DisDriver();//判斷磁碟機代號
// 覆寫
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 建構後第一次呼叫
	virtual HRESULT OnGetHostInfo(DOCHOSTUIINFO *pInfo);
// 程式碼實作
public:
	virtual ~CUSB_FramView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // USB_FramView.cpp 中的偵錯版本
inline CUSB_FramDoc* CUSB_FramView::GetDocument() const
   { return reinterpret_cast<CUSB_FramDoc*>(m_pDocument); }
#endif

