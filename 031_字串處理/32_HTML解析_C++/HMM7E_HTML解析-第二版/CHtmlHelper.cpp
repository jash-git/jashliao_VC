//////////////////////////////////////////////////////////////////////////////////////////CHtmlHelper.cpp//////////////////////////////////////////////////////////////////////////

#pragma once

/*****************************************************************************************************************
created: 2011/12/03
author: hmm7e (hmm7e_z@126.com)

*****************************************************************************************************************/


#include "HtmlHelper.h"

#pragma warning(disable: 4996) 

CHtmlHelper::CHtmlHelper()
{

}
CHtmlHelper::~CHtmlHelper()
{

}
//
LPCTSTR CHtmlHelper::GetFirstLink()
{
	LPCTSTR pszResult = NULL;

	m_pstCur = m_pstHead;

	while( m_pstCur && !pszResult )
	{
		if( 0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("script"),6) &&
			0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("style"),5) )
		{
			CHtmlObject::tagNode * pstAttributeCur = m_pstCur->s_pstRight;
			while( pstAttributeCur )
			{
				if( 0 == ::_tcsnicmp(pstAttributeCur->s_pszKey,_T("href"),4) ||
					0 == ::_tcsnicmp(pstAttributeCur->s_pszKey,_T("src"),3) )
				{
					//return
					pszResult = pstAttributeCur->s_pszValue;
					break ;
				}
				else
				{
					pstAttributeCur = pstAttributeCur->s_pstRight;
				}
			}
		}
		m_pstCur = m_pstCur->s_pstNext;
	}

	return pszResult;
}
LPCTSTR CHtmlHelper::GetNextLink()
{
	LPCTSTR pszResult = NULL;

	while( m_pstCur && !pszResult )
	{
		if( 0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("script"),6) &&
			0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("style"),5) )
		{
			CHtmlObject::tagNode * pstAttributeCur = m_pstCur->s_pstRight;
			while( pstAttributeCur )
			{
				if( 0 == ::_tcsnicmp(pstAttributeCur->s_pszKey,_T("href"),4) ||
					0 == ::_tcsnicmp(pstAttributeCur->s_pszKey,_T("src"),3) )
				{
					//return
					pszResult = pstAttributeCur->s_pszValue;
					break ;
				}
				else
				{
					pstAttributeCur = pstAttributeCur->s_pstRight;
				}
			}
		}

		m_pstCur = m_pstCur->s_pstNext;
	}

	return pszResult;
}
LPCTSTR CHtmlHelper::GetFirstContent()
{
	LPCTSTR pszResult = NULL;

	m_pstCur = m_pstHead;

	while( m_pstCur && !pszResult )
	{
		if( 0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("script"),6) &&
			0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("style"),5) )
		{
			if( m_pstCur->s_pszValue )
				pszResult = m_pstCur->s_pszValue;
		}

		m_pstCur = m_pstCur->s_pstNext;
	}

	return pszResult;
}
LPCTSTR CHtmlHelper::GetNextContent()
{
	LPCTSTR pszResult = NULL;

	while( m_pstCur && !pszResult )
	{
		if( 0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("script"),6) &&
			0 != ::_tcsnicmp(m_pstCur->s_pszKey,_T("style"),5) )
		{
			if( m_pstCur->s_pszValue )
				pszResult = m_pstCur->s_pszValue;
		}

		m_pstCur = m_pstCur->s_pstNext;
	}

	return pszResult;
}
//
LPCTSTR CHtmlHelper::SearchText(LPCTSTR lpszText)
{
	LPCTSTR pszResult = NULL;

	CHtmlObject::tagNode *pstCur = m_pstHead;

	while( pstCur && !pszResult)
	{
		if( 0 != ::_tcsnicmp(pstCur->s_pszKey,_T("script"),6) &&
			0 != ::_tcsnicmp(pstCur->s_pszKey,_T("style"),5) )
		{
			if( pstCur->s_pszValue )
			{
				if( (NULL != ::StrStrI(pstCur->s_pszValue,lpszText)) )
					pszResult = pstCur->s_pszValue;
			}
		}

		pstCur = pstCur->s_pstNext;
	}

	return pszResult;
}



#pragma warning(default: 4996) 



//////////////////////////////////////////////////////////////////////////////////////////CHtmlHelper.cpp//////////////////////////////////////////////////////////////////////////