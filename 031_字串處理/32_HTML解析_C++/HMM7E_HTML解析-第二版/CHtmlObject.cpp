//////////////////////////////////////////////////////////////////////////////////////////CHtmlObject.cpp//////////////////////////////////////////////////////////////////////////

#pragma once

/*****************************************************************************************************************
created: 2011/12/03
author: hmm7e (hmm7e_z@126.com)

*****************************************************************************************************************/


#include "HtmlObject.h"

//
BOOL CHtmlObject::IsSpace(TCHAR tcLetter)
{
	//以下字元在HTML標記裏都算是空格。
	return (tcLetter == _T(' ') || tcLetter == _T('\r') ||tcLetter == _T('\n') ||tcLetter == _T('\t') );
}

CHtmlObject::CHtmlObject(void)
{
	m_pszSnapshotBuffer = NULL;
	m_nSnapshotBufferLen = 0;
	m_nSnapshotStringLen = 0;
	m_pstHead = NULL;
	m_pstTail = NULL;
}

CHtmlObject::~CHtmlObject(void)
{
	DeleteSnapshot();
}
//
CHtmlObject::tagNode * CHtmlObject::InnerAllocNode()
{
	CHtmlObject::tagNode * pstResult = new CHtmlObject::tagNode;
	if( pstResult )
	{
		::ZeroMemory((LPVOID)pstResult,sizeof(CHtmlObject::tagNode));
	}
	return pstResult;
}
void CHtmlObject::InnerFreeNode(CHtmlObject::tagNode * lpstNode)
{
	if( lpstNode )
		delete lpstNode;
}
void CHtmlObject::InnerLinkNextNode(tagNode * lpstNode)
{
	//鏈結到“尾”結點。
	//1：如果沒有“頭”節點，那麼表示鏈表是“空”的。
	//2：如果已經存“頭”節點，那麼就鏈結新節點到“尾”節點，並重新記錄“尾”節點指標。
	if( m_pstHead == NULL )
	{
		m_pstHead = lpstNode;
		m_pstTail = lpstNode;
	}
	else
	{
		m_pstTail->s_pstNext = lpstNode;
		m_pstTail = lpstNode;
	}


#ifdef _DEBUG

	if( lpstNode->s_pszKey )
	{
		::OutputDebugString(_T("--"));
		::OutputDebugString(lpstNode->s_pszKey);
		::OutputDebugString(_T("--\r\n"));
	}
	if( lpstNode->s_pszValue )
	{
		::OutputDebugString(_T("--"));
		::OutputDebugString(lpstNode->s_pszValue);
		::OutputDebugString(_T("--\r\n"));
	}

#endif //_DEBUG

}
void CHtmlObject::InnerLinkRightNode(tagNode * lpstTagNode,tagNode * lpstNode)
{
	//鏈結到“屬性”的“頭”節點。
	//1：把現有的“屬性”鏈表，鏈結到當前新節點的下。
	//2：把當前節點做為“頭”節點保存。
	lpstNode->s_pstRight = lpstTagNode->s_pstRight;
	lpstTagNode->s_pstRight = lpstNode;

#ifdef _DEBUG
	if( lpstNode->s_pszKey )
	{
		::OutputDebugString(_T("-->"));
		::OutputDebugString(lpstNode->s_pszKey);
		::OutputDebugString(_T("<--\r\n"));
	}
	if( lpstNode->s_pszValue )
	{
		::OutputDebugString(_T("-->"));
		::OutputDebugString(lpstNode->s_pszValue);
		::OutputDebugString(_T("<--\r\n"));
	}
#endif //_DEBUG
}
void CHtmlObject::InnerCleanupNode()
{
	//迴圈清除所有節點。如果存在“屬性”節點一併清除。
	CHtmlObject::tagNode * pstPrev = NULL;
	while( m_pstHead )
	{
		pstPrev = m_pstHead;
		m_pstHead = m_pstHead->s_pstNext;
		//first
		InnerCleanupRightNode(pstPrev);
		//second
		InnerFreeNode(pstPrev);
	}
	m_pstHead = NULL;
	m_pstTail = NULL;
}
void CHtmlObject::InnerCleanupRightNode(CHtmlObject::tagNode * lpstNode)
{
	//迴圈清除所有“屬性”節點。
	CHtmlObject::tagNode * pstHead = lpstNode->s_pstRight;
	CHtmlObject::tagNode * pstPrev = NULL;
	while( pstHead )
	{
		pstPrev = pstHead;
		pstHead = pstHead->s_pstRight;
		InnerFreeNode(pstPrev);
	}
	pstHead = NULL;
	pstPrev = NULL;
}
//
void CHtmlObject::AutoTakeSnapshot(PBYTE lpszString,UINT nStringLen)
{
	
	if( lpszString && nStringLen > 0)
	{
		//根據資料頭自動判斷是否需要轉換資料到當前應程所使用的編碼。
		if( nStringLen >= 2 )
		{
			if( lpszString[0] == 0xFF && lpszString[1] == 0xFE ) // skip 0xFF,0xFE
			{
				TakeSnapshot(lpszString+2,nStringLen-2,CHtmlObject::CHARSET_UNICODE);
			}
			else if( lpszString[0] == 0xEF && lpszString[1] == 0xBB && lpszString[2] == 0xBF )// skip 0xEF,0xBB,0xBF
			{
				TakeSnapshot(lpszString+3,nStringLen-3,CHtmlObject::CHARSET_UTF8);
			}
			else
			{
				TakeSnapshot(lpszString,nStringLen,CHtmlObject::CHARSET_MULTIBYTE);
			}
		}
		else
		{
			TakeSnapshot(lpszString,nStringLen,CHtmlObject::CHARSET_MULTIBYTE);
		}
	}
}
void CHtmlObject::TakeSnapshot(PBYTE lpszString,UINT nStringLen,UINT nFromCharset )
{
	//delete old snapshot
	DeleteSnapshot();

	if( lpszString && nStringLen > 0 )
	{

		//transform to TCHAR

		if( CHtmlHelper::CHARSET_UTF8 == nFromCharset )
		{

#ifdef _UNICODE 

			m_nSnapshotBufferLen = nStringLen;
			m_pszSnapshotBuffer = new TCHAR[m_nSnapshotBufferLen];

			::memset((LPVOID)m_pszSnapshotBuffer,0,m_nSnapshotBufferLen*sizeof(TCHAR));
			m_nSnapshotStringLen = ::MultiByteToWideChar(CP_UTF8,0,(LPCSTR)lpszString,nStringLen,m_pszSnapshotBuffer,m_nSnapshotBufferLen);
#else
			::OutputDebugString(_T("no support"));

#endif //_UNICODE

		}
		else if( CHtmlHelper::CHARSET_UNICODE == nFromCharset )
		{

#ifdef _UNICODE 

			m_nSnapshotBufferLen = nStringLen;
			m_pszSnapshotBuffer = new TCHAR[m_nSnapshotBufferLen];

			::memset((LPVOID)m_pszSnapshotBuffer,0,m_nSnapshotBufferLen*sizeof(TCHAR));
			::memcpy((LPVOID)m_pszSnapshotBuffer,lpszString,nStringLen);

#else

			m_nSnapshotBufferLen = nStringLen/2+1;
			m_pszSnapshotBuffer = new TCHAR[m_nSnapshotBufferLen];

			::memset((LPVOID)m_pszSnapshotBuffer,0,m_nSnapshotBufferLen*sizeof(TCHAR));
			m_nSnapshotStringLen = ::WideCharToMultiByte(CP_ACP,0,(LPWSTR)lpszString,nStringLen,(LPSTR)m_pszSnapshotBuffer,m_nSnapshotBufferLen,NULL,NULL);

#endif //_UNICODE

		}
		else
		{

#ifdef _UNICODE 

			m_nSnapshotBufferLen = nStringLen;
			m_pszSnapshotBuffer = new TCHAR[m_nSnapshotBufferLen];

			::memset(m_pszSnapshotBuffer,0,m_nSnapshotBufferLen*sizeof(TCHAR));
			m_nSnapshotStringLen = ::MultiByteToWideChar(CP_ACP,0,(LPCSTR)lpszString,nStringLen,m_pszSnapshotBuffer,m_nSnapshotBufferLen);
#else

			m_nSnapshotBufferLen = nStringLen;
			m_pszSnapshotBuffer = new TCHAR[m_nSnapshotBufferLen];

			::memset((LPVOID)m_pszSnapshotBuffer,0,m_nSnapshotBufferLen*sizeof(TCHAR));
			::memcpy((LPVOID)m_pszSnapshotBuffer,lpszString,nStringLen);

#endif //_UNICODE

		}
	}
}
void CHtmlObject::DeleteSnapshot()
{
	//先清除樹型表。
	InnerCleanupNode();

	if( m_pszSnapshotBuffer )
		delete []m_pszSnapshotBuffer;

	m_pszSnapshotBuffer = NULL;
	m_nSnapshotBufferLen = 0;
	m_nSnapshotStringLen = 0;
}
//
void CHtmlObject::Parse()
{
#ifdef _AFX
	CString strTrace;
	strTrace.Format(_T("CHtmlObject::Parse() --begin-->(%d)\r\n"),::GetTickCount());
	::OutputDebugString(strTrace);
#endif //_AFX

	InnerParse();

#ifdef _AFX
	strTrace.Format(_T("CHtmlObject::Parse() --end-->(%d)\r\n"),::GetTickCount());
	::OutputDebugString(strTrace);
#endif //_AFX
}
//
void CHtmlObject::InnerParse()
{
	LPTSTR pszFind = m_pszSnapshotBuffer;

	//跳過所有“空格”
	while( *pszFind != _T('\0') && CHtmlObject::IsSpace(*pszFind) )
	{
		//下一個字元
		pszFind++;
	}
	//直到碰到'\0'就退出
	do
	{
		// 不是“\0”，並且第一個字元為“<”則置換為“\0”，否則什麼也不做。
		//這麼寫的原因就在於InnerSplitContent()返回後 “<”可能已經被置換成“\0”。
		if( *pszFind != _T('\0') && *pszFind == _T('<') )
		{
			//把“<”置換為“\0”,做為結尾。
			*pszFind = _T('\0');
			//下一個字元。
			pszFind++;
		}

		// 不是“\0”
		if( *pszFind != _T('\0') )
		{
			//是否為注釋
			if( *pszFind == _T('!') )
			{
				//申請一個點節。
				tagNode *pstNode = InnerAllocNode();
				//解析注釋，返回的是注釋後面的內容。
				pszFind = InnerSplitComment(pstNode,pszFind);
				//鏈結到“鏈表”。（下）
				InnerLinkNextNode(pstNode);
			}
			else
			{
				//申請一個點節。
				tagNode *pstNode = InnerAllocNode();
				//解析tag，返回的是tag後面的內容。
				pszFind = InnerSplitTag(pstNode,pszFind);
				//解析content返回的是content後面的內容。
				pszFind = InnerSplitContent(pstNode,pszFind);
				//鏈結到“鏈表”。（下）
				InnerLinkNextNode(pstNode);
			}
		}

	}while( *pszFind!= _T('\0') );
}
LPTSTR CHtmlObject::InnerSplitComment(CHtmlObject::tagNode * lpstNode,LPTSTR lpszTagString)
{
	LPTSTR pszFind = lpszTagString;
	//指向注釋開頭(已經跳過“<”字元)
	lpstNode->s_pszKey = pszFind;
	//如果為 <!-- *** -->
	if( ::_tcsnicmp(pszFind+1,_T("--"),2) == 0 )
	{
		//跳過注釋標記“頭”，開始查找。
		pszFind += 3;
		//查找到注釋結尾，並給結尾加“\0”。
		while( ::_tcsnicmp(pszFind,_T("-->"),3) != 0 )
		{
			//下一個字元
			pszFind++;
		}
		//不是“\0”
		if( *pszFind != _T('\0') )
		{
			//把“>”置換為“\0”,做為注釋結尾
			*(pszFind+2) = _T('\0');
			//指向新的節點或內容。
			pszFind += 3;
		}

	}
	//否則為 <! *** >
	else
	{
		//查找到注釋結尾，並給結尾加“\0”。
		while( *pszFind != _T('\0') && *pszFind != _T('>') )
		{
			//下一個字元
			pszFind++;
		}
		//不能是“\0”
		if( *pszFind != _T('\0') )
		{
			//把“>”置換為“\0”,做為注釋結尾。
			*pszFind = _T('\0');
			//指向新的節點或內容。
			pszFind++;
		}
	}

	//找到一個“<”
	while( *pszFind != _T('\0') && *pszFind != _T('<') )
	{
		//下一個字元
		pszFind++;
	}

	return pszFind;
}
LPTSTR CHtmlObject::InnerSplitTag(CHtmlObject::tagNode * lpstNode,LPTSTR lpszTagString)
{
	LPTSTR pszFind = lpszTagString;

	//指向開頭(已經跳過“<”字元)
	lpstNode->s_pszKey = pszFind;
	//查找tag結尾，並給結尾加“\0”。
	while( *pszFind != _T('\0') && *pszFind != _T('>') && !CHtmlObject::IsSpace(*pszFind) )
	{
		//下一個字元
		pszFind++;
	}

	//不是“\0”
	if( *pszFind != _T('\0') )
	{
		if( *pszFind == _T('>') )
		{
			//把“>”置換為“\0”,做為注釋結尾。
			*pszFind = _T('\0');
			//指向新的節點或內容。
			pszFind++;
			//此tag沒有屬性,什麼也不做了。
				
		}
		else
		{
			//把“space,\r,\n,\t ”置換為“\0”,做為注釋結尾。
			*pszFind = _T('\0');
			//指向新的節點或內容。
			pszFind++;

			//如果不是結束標記，表示此tag有“屬性”還需要解析“屬性”。
			if( *lpstNode->s_pszKey != _T('/') )
			{
				//跳過所有“空格”,找到第一個屬性。
				while( *pszFind != _T('\0') && CHtmlObject::IsSpace(*pszFind) )
				{
					//下一個字元
					pszFind++;
				}
				//迴圈分析“屬性”。
				while( *pszFind != _T('\0') && *pszFind != _T('<') && *pszFind != _T('>') )
				{
					//例：
					// key="value" key=value
					//跳過空格
					while( *pszFind != _T('\0') && CHtmlObject::IsSpace(*pszFind) )
					{
						//下一個字元
						pszFind++;
					}

					//不是“\0”
					if( *pszFind != _T('\0') )
					{
						//申請一個點節。
						tagNode *pstAttributeNode = InnerAllocNode();
						//指向“屬性”Key。
						pstAttributeNode->s_pszKey = pszFind;

						//查找key的末尾.
						while( *pszFind != _T('\0') && *pszFind != _T('=') && *pszFind != _T('>') )
						{
							//下一個字元
							pszFind++;
						}
						//不是“\0”
						if( *pszFind != _T('\0') )
						{
							if( *pszFind == _T('>') )
							{
								//把“>”置換為“\0”,做為結尾。
								*pszFind = _T('\0');
								//指向新的節點或內容。
								pszFind++;
								//鏈結到“鏈表”（右）。
								InnerLinkRightNode(lpstNode,pstAttributeNode);
								//已經碰到“>”,需要跳出。
								break;
							}
							else
							{
								//把“=”置換為“\0”,做為結尾。
								*pszFind = _T('\0');
								//指向新的節點或內容。
								pszFind++;
								
								//不是“\0”
								if( *pszFind != _T('\0') )
								{
									if( *pszFind == _T('"') )
									{
										//跳過“"”
										pszFind++;
										//指向“屬性”key的Value。
										pstAttributeNode->s_pszValue = pszFind;

										//查找Value的末尾.
										while( *pszFind != _T('\0') && *pszFind != _T('\"') && *pszFind != _T('>') )
										{
											//下一個字元
											pszFind++;
										}
										//不是“\0”
										if( *pszFind != _T('\0') )
										{
											//把“",> ”置換為“\0”,做為結尾。
											*pszFind = _T('\0');
											//指向新的節點或內容。
											pszFind++;
										}
									}
									else if( *pszFind == _T('\'') )
									{
										//跳過“'”
										pszFind++;
										//指向“屬性”key的Value。
										pstAttributeNode->s_pszValue = pszFind;

										//查找Value的末尾.
										while( *pszFind != _T('\0') && *pszFind != _T('\'') && *pszFind != _T('>') )
										{
											//下一個字元
											pszFind++;
										}
										//不是“\0”
										if( *pszFind != _T('\0') )
										{
											//把“",<space> ”置換為“\0”,做為結尾。
											*pszFind = _T('\0');
											//指向新的節點或內容。
											pszFind++;
										}
									}
									else
									{
										//指向“屬性”key的Value。
										pstAttributeNode->s_pszValue = pszFind;
										//查找Value的末尾.
										while( *pszFind != _T('\0') && *pszFind != _T(' ') && *pszFind != _T('>') )
										{
											//下一個字元
											pszFind++;
										}
										//不是“\0”
										if( *pszFind != _T('\0') )
										{
											//把“ ”置換為“\0”,做為結尾。
											*pszFind = _T('\0');
											//指向新的節點或內容。
											pszFind++;
										}
									}
									
								}
							}
							
						}
					
						//鏈結到“鏈表”（右）。
						InnerLinkRightNode(lpstNode,pstAttributeNode);
					}
				} 
				
				//跳過這個無用的字元。
				if( *pszFind == _T('>') )
				{
					//指向新的節點或內容。
					pszFind++;
				}
			}
		}
	}

	return pszFind;
}
LPTSTR CHtmlObject::InnerSplitContent(CHtmlObject::tagNode * lpstNode,LPTSTR lpszTagString)
{
	LPTSTR pszFind = lpszTagString;
	
	if( ::_tcsnicmp(lpstNode->s_pszKey,_T("script"),6) == 0 )
	{
		pszFind = InnerSplitScript(lpstNode,pszFind);
	}
	else if( ::_tcsnicmp(lpstNode->s_pszKey,_T("style"),5) == 0 )
	{
		pszFind = InnerSplitStyle(lpstNode,pszFind);
	}
	else
	{
		pszFind = InnerSplitText(lpstNode,pszFind);
	}

	return pszFind;
}
LPTSTR CHtmlObject::InnerSplitText(CHtmlObject::tagNode * lpstNode,LPTSTR lpszTagString)
{
	LPTSTR pszFind = lpszTagString;
		
	//跳過所有“空格”
	while( *pszFind != _T('\0') && CHtmlObject::IsSpace(*pszFind) )
	{
		//下一個字元
		pszFind++;
	}
	
	//如果 _T('<') 表示沒有文本。
	if( *pszFind != _T('<') )
	{
		//指向可見文本。
		lpstNode->s_pszValue = pszFind;
		//查找文本結尾。
		while( *pszFind != _T('\0') && *pszFind != _T('<') && !CHtmlObject::IsSpace(*pszFind) )
		{
			//下一個字元
			pszFind++;
		}
		//不是“\0”
		if( *pszFind != _T('\0') )
		{
			if( *pszFind == _T('<') )
			{
				//把“<”置換為“\0”,做為結尾。
				*pszFind = _T('\0');
				//指向新的節點或內容。
				pszFind++;
			}
			else
			{
				//把“space,\r,\n,\t,”置換為“\0”,做為結尾。
				*pszFind = _T('\0');
				//指向新的節點或內容。
				pszFind++;

				//找到一個“<”
				while( *pszFind != _T('\0') && *pszFind != _T('<') )
				{
					//下一個字元
					pszFind++;
				}
			}
		}
	}

	return pszFind;
}
LPTSTR CHtmlObject::InnerSplitScript(tagNode * lpstNode,LPTSTR lpszTagString)
{
	LPTSTR pszFind = lpszTagString;


#define  SCRIPT_MARK_MAX			1024
	UINT nMarkIndex = 0;
	TCHAR szMark[SCRIPT_MARK_MAX] = {_T('\0')}; //max 1024

	//跳過所有“空格”
	while( *pszFind != _T('\0') && CHtmlObject::IsSpace(*pszFind) )
	{
		//下一個字元
		pszFind++;
	}

	if( *pszFind != _T('\0') && *pszFind != _T('<') )
	{
		//指向可見文本。
		lpstNode->s_pszValue = pszFind;

		while( *pszFind != _T('\0') )
		{
			//如果字元被“'，"”包圍則為字串，這期間不計算注釋。
			if( szMark[nMarkIndex] != _T('\'') && szMark[nMarkIndex] != _T('\"') )
			{
				//如果是// abc 則跳過。
				if( ::_tcsnicmp(pszFind,_T("//"),2) == 0   )
				{
					//跳過注釋“頭”。
					pszFind +=2;
					//查找注釋“尾”。
					while( *pszFind != _T('\0') && *pszFind != _T('\n') )
					{
						pszFind++;
					}
					//跳過注釋“尾”。
					if( *pszFind != _T('\0')  )
						pszFind++;

				}
				//如果是/* abc */則跳過。
				else if( ::_tcsnicmp(pszFind,_T("/*"),2) == 0   )
				{
					//跳過注釋“頭”。
					pszFind +=2;
					//查找注釋“尾”。
					while( ::_tcsnicmp(pszFind,_T("*/"),2) != 0 )
					{
						pszFind++;
					}
					//跳過注釋“尾”。
					if( *pszFind != _T('\0')  )
						pszFind +=2;
				}

			}

			if( *pszFind == _T('\\') && 
				( *(pszFind+1) == _T('\\') || 
				*(pszFind+1) == _T('(') || *(pszFind+1) == _T(')') || 
				*(pszFind+1) == _T('[') || *(pszFind+1) == _T(']') || 
				*(pszFind+1) == _T('{') || *(pszFind+1) == _T('}') || 
				*(pszFind+1) == _T('\'') || 
				*(pszFind+1) == _T('\"') ) )
			{
				//轉意字元
				pszFind+=2;

			}
			else if( *pszFind == _T('{') || *pszFind == _T('(') || *pszFind == _T('[') ||  (*pszFind == _T('\'') || *pszFind == _T('\"')) )
			{
				if( szMark[nMarkIndex] != _T('\'') && szMark[nMarkIndex] != _T('\"') )
				{
					if( nMarkIndex < SCRIPT_MARK_MAX )
					{
						if( nMarkIndex == 0 && szMark[nMarkIndex] == _T('\0')  )
							szMark[nMarkIndex] = *pszFind;
						else
							szMark[++nMarkIndex] = *pszFind;
					}
				}
				else if( szMark[nMarkIndex] == *pszFind )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;

			}
			else if( *pszFind == _T('}') ) 
			{
				if( szMark[nMarkIndex] == _T('{') )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;
			}
			else if( *pszFind == _T(')') )
			{
				if( szMark[nMarkIndex] == _T('(') )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;
			}
			else if( *pszFind == _T(']') ) 
			{
				if( szMark[nMarkIndex] == _T('[') )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;
			}
			else if( *pszFind == _T('<') && szMark[0] == _T('\0') )  //nMarkIndex == 0 &&
			{
				//把“<”置換為“\0”,做為結尾。
				*pszFind = _T('\0');
				//指向新的節點或內容。
				pszFind++;
				break;
			}
			else
			{
				pszFind++;
			}
		}
	}

	return pszFind;
}
LPTSTR CHtmlObject::InnerSplitStyle(CHtmlObject::tagNode * lpstNode,LPTSTR lpszTagString)
{
	LPTSTR pszFind = lpszTagString;

#define  STYLE_MARK_MAX			1024
	UINT nMarkIndex = 0;
	TCHAR szMark[STYLE_MARK_MAX] = {_T('\0')}; //max 1024

	//跳過所有“空格”
	while( *pszFind != _T('\0') && CHtmlObject::IsSpace(*pszFind) )
	{
		//下一個字元
		pszFind++;
	}

	if( *pszFind != _T('\0') && *pszFind != _T('<') )
	{
		//指向可見文本。
		lpstNode->s_pszValue = pszFind;

		while( *pszFind != _T('\0') )
		{
			//如果字元被“(，'，"”包圍則為字串，這期間不計算注釋。
			if( szMark[nMarkIndex] != _T('(') && szMark[nMarkIndex] != _T('\'') && szMark[nMarkIndex] != _T('\"') )
			{
				//如果是/* abc */則跳過。
				if( ::_tcsnicmp(pszFind,_T("/*"),2) == 0   )
				{
					//跳過注釋“頭”，查找注釋“尾”。
					pszFind +=2;
					while( ::_tcsnicmp(pszFind,_T("*/"),2) != 0 )
					{
						pszFind++;
					}
					//跳過注釋“尾”。
					if( *pszFind != _T('\0')  )
						pszFind +=2;
				}
			}


			if( *pszFind == _T('{') || *pszFind == _T('(') || *pszFind == _T('[') ||  (*pszFind == _T('\'') || *pszFind == _T('\"')) )
			{
				if( szMark[nMarkIndex] != _T('\'') && szMark[nMarkIndex] != _T('\"') )
				{
					if( nMarkIndex < STYLE_MARK_MAX )
					{
						if( nMarkIndex == 0 && szMark[nMarkIndex] == _T('\0')  )
							szMark[nMarkIndex] = *pszFind;
						else
							szMark[++nMarkIndex] = *pszFind;
					}
				}
				else if( szMark[nMarkIndex] == *pszFind )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;

			}
			else if( *pszFind == _T('}') ) 
			{
				if( szMark[nMarkIndex] == _T('{') )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;
			}
			else if( *pszFind == _T(')') )
			{
				if( szMark[nMarkIndex] == _T('(') )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;
			}
			else if( *pszFind == _T(']') ) 
			{
				if( szMark[nMarkIndex] == _T('[') )
				{
					if( nMarkIndex >0  )
						szMark[nMarkIndex--] = _T('\0');
					else
						szMark[nMarkIndex] = _T('\0');
				}
				pszFind++;
			}
			else if( *pszFind == _T('<') && szMark[0] == _T('\0') )  //nMarkIndex == 0 &&
			{
				//把“<”置換為“\0”,做為結尾。
				*pszFind = _T('\0');
				//指向新的節點或內容。
				pszFind++;
				break;
			}
			else
			{
				pszFind++;
			}
		}

	}

	return pszFind;
}

//////////////////////////////////////////////////////////////////////////////////////////CHtmlObject.cpp//////////////////////////////////////////////////////////////////////////
