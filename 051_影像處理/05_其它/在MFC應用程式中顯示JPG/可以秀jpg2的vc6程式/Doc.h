/////////////////////////////////////////////////////////////////////////////
// Project：MYIMGAPP
// Author：NorthTibet
// Date：星期四, 九月 26, 2002
// Description：通过定制的C++类在MFC框架中轻松显示多种格式的图象
//
/////////////////////////////////////////////////////////////////////////////
// Doc.h : interface of the CPictureDoc class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "Picture.h"

/////////////////
// Typical MFC doc class. Holds the picture in CPicture.
//
class CPictureDoc : public CDocument {
public:
	virtual ~CPictureDoc();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnNewDocument();

	CPicture* GetPicture() {
		return &m_pict;
	}

protected:
	CPicture	m_pict; // the picture
	CPictureDoc();
	DECLARE_DYNCREATE(CPictureDoc)
	DECLARE_MESSAGE_MAP()
};
