// VS2008test02.h : PROJECT_NAME 應用程式的主要標頭檔
//

#pragma once

#ifndef __AFXWIN_H__
	#error "對 PCH 包含此檔案前先包含 'stdafx.h'"
#endif

#include "resource.h"		// 主要符號


// CVS2008test02App:
// 請參閱實作此類別的 VS2008test02.cpp
//

class CVS2008test02App : public CWinApp
{
public:
	CVS2008test02App();

// 覆寫
	public:
	virtual BOOL InitInstance();

// 程式碼實作

	DECLARE_MESSAGE_MAP()
};

extern CVS2008test02App theApp;