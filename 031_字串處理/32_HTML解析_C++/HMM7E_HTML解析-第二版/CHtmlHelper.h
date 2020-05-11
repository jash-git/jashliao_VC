//////////////////////////////////////////////////////////////////////////////////////////CHtmlHelper.h//////////////////////////////////////////////////////////////////////////

#pragma once

/*****************************************************************************************************************
created: 2011/12/03
author: hmm7e (hmm7e_z@126.com)

*****************************************************************************************************************/

#include "HtmlObject.h"

class CHtmlHelper:public CHtmlObject
{
public:
	CHtmlHelper(void);
	virtual ~CHtmlHelper(void);
public:
	//
	LPCTSTR GetFirstLink();
	LPCTSTR GetNextLink();
	LPCTSTR GetFirstContent();
	LPCTSTR GetNextContent();
	LPCTSTR	SearchText(LPCTSTR lpszText);
protected:
	//
	CHtmlObject::tagNode * m_pstCur;
};



//////////////////////////////////////////////////////////////////////////////////////////CHtmlHelper.h//////////////////////////////////////////////////////////////////////////
