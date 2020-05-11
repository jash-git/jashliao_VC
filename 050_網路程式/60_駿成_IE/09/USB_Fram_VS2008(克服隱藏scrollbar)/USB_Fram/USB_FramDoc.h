
// USB_FramDoc.h : CUSB_FramDoc 類別的介面
//


#pragma once


class CUSB_FramDoc : public CDocument
{
protected: // 僅從序列化建立
	CUSB_FramDoc();
	DECLARE_DYNCREATE(CUSB_FramDoc)

// 屬性
public:

// 作業
public:

// 覆寫
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 程式碼實作
public:
	virtual ~CUSB_FramDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 產生的訊息對應函式
protected:
	DECLARE_MESSAGE_MAP()
};


