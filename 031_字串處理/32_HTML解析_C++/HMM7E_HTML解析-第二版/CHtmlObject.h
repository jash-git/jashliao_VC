//////////////////////////////////////////////////////////////////////////////////////////CHtmlObject.h//////////////////////////////////////////////////////////////////////////

#pragma once

/*****************************************************************************************************************
created: 2011/12/03
author: hmm7e (hmm7e_z@126.com)

*****************************************************************************************************************/

class CHtmlObject
{
public:
//
static BOOL IsSpace(TCHAR tcLetter);
protected:
struct tagNode
{
LPCTSTR s_pszKey;
LPCTSTR s_pszValue;
struct tagNode * s_pstRight; //attribute of tag
struct tagNode * s_pstNext; //next tag
};
public:
CHtmlObject(void);
virtual ~CHtmlObject(void);
//
enum {CHARSET_UTF8,CHARSET_UNICODE,CHARSET_MULTIBYTE}TextCharset;
protected:
//
tagNode * InnerAllocNode();
void InnerFreeNode(tagNode * lpstNode);
void InnerLinkNextNode(tagNode * lpstNode);
void InnerLinkRightNode(tagNode * lpstTagNode,tagNode * lpstNode);
void InnerCleanupNode();
void InnerCleanupRightNode(tagNode * lpstNode);
public:
//
void AutoTakeSnapshot(PBYTE lpszString,UINT nStringLen);
void TakeSnapshot(PBYTE lpszString,UINT nStringLen,UINT nFromCharset );
void DeleteSnapshot();
//
void Parse();
private:
//
void InnerParse();
LPTSTR InnerSplitComment(tagNode * lpstNode,LPTSTR lpszTagString);
LPTSTR InnerSplitTag(tagNode * lpstNode,LPTSTR lpszTagString);
LPTSTR InnerSplitContent(tagNode * lpstNode,LPTSTR lpszTagString);
LPTSTR InnerSplitText(tagNode * lpstNode,LPTSTR lpszTagString);
LPTSTR InnerSplitScript(tagNode * lpstNode,LPTSTR lpszTagString);
LPTSTR InnerSplitStyle(tagNode * lpstNode,LPTSTR lpszTagString);

protected:
//
LPTSTR m_pszSnapshotBuffer;
UINT m_nSnapshotBufferLen;
UINT m_nSnapshotStringLen;
//
tagNode * m_pstHead;
tagNode * m_pstTail;

};

//////////////////////////////////////////////////////////////////////////////////////////CHtmlObject.h//////////////////////////////////////////////////////////////////////////