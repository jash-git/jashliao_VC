
// USB_FramDoc.cpp : CUSB_FramDoc 類別的實作
//

#include "stdafx.h"
#include "USB_Fram.h"

#include "USB_FramDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUSB_FramDoc

IMPLEMENT_DYNCREATE(CUSB_FramDoc, CDocument)

BEGIN_MESSAGE_MAP(CUSB_FramDoc, CDocument)
END_MESSAGE_MAP()


// CUSB_FramDoc 建構/解構

CUSB_FramDoc::CUSB_FramDoc()
{
	// TODO: 在此加入一次建構程式碼

}

CUSB_FramDoc::~CUSB_FramDoc()
{
}

BOOL CUSB_FramDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此加入重新初始化程式碼
	// (SDI 文件會重用此文件)

	return TRUE;
}




// CUSB_FramDoc 序列化

void CUSB_FramDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此加入儲存程式碼
	}
	else
	{
		// TODO: 在此加入載入程式碼
	}
}


// CUSB_FramDoc 診斷

#ifdef _DEBUG
void CUSB_FramDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CUSB_FramDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CUSB_FramDoc 命令
