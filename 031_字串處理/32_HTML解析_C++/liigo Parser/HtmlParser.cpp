#include "HtmlParser.h"
//HtmlParser類，用於解析HTML文本
//by liigo, @2010
const WCHAR* wcsnchr(const WCHAR* pStr, int len, WCHAR c)
{
	const WCHAR *p = pStr;
	while(1)
	{
		if(*p == c) return p;
		p++;
		if((p - pStr) == len) break;
	}
	return NULL;
}
const WCHAR* getFirstUnquotedChar(const WCHAR* pStr, WCHAR endcahr)
{
	WCHAR c;
	const WCHAR* p = pStr;
	bool inQuote1 = false, inQuote2 = false; //'inQuote1', "inQuote2"
	while(c = *p)
	{
		if(c == L'/'')
		{
			inQuote1 = !inQuote1;
		}
		else if(c == L'/"')
		{
			inQuote2 = !inQuote2;
		}
		if(!inQuote1 && !inQuote2)
		{
			if(c == endcahr) return p;
		}
		p++;
	}
	return NULL;
}
//nDest and nChar can by -1
unsigned int copyStr(WCHAR* pDest, unsigned int nDest, const WCHAR* pSrc, unsigned int nChar)
{
	if(pDest == NULL || nDest == 0)
		return 0;
	if(pSrc == NULL)
	{
		pDest[0] = L'/0';
		return 0;
	}
	if(nChar == (unsigned int)-1)
		nChar = wcslen(pSrc);
	if(nChar > nDest)
		nChar = nDest;
	memcpy(pDest, pSrc, nChar * sizeof(WCHAR));
	pDest[nChar] = L'/0';
	return nChar;
}
int copyStrUtill(WCHAR* pDest, unsigned int nDest, const WCHAR* pSrc, WCHAR endchar, bool ignoreEndCharInQuoted)
{
	if(nDest == 0) return 0;
	pDest[0] = L'/0';
	const WCHAR* pSearched = (ignoreEndCharInQuoted ? getFirstUnquotedChar(pSrc,endchar) : wcschr(pSrc, endchar));
	if(pSearched <= pSrc) return 0;
	return copyStr(pDest, nDest, pSrc, pSearched - pSrc);
}
//nChar can be -1
WCHAR* duplicateStr(const WCHAR* pSrc, unsigned int nChar)
{
	if(nChar == (unsigned int)-1)
		nChar = wcslen(pSrc);
	WCHAR* pNew = (WCHAR*) malloc( (nChar+1) * sizeof(WCHAR) );
	copyStr(pNew, -1, pSrc, nChar);
	return pNew;
}
WCHAR* duplicateStrUtill(const WCHAR* pSrc, WCHAR endchar, bool ignoreEndCharInQuoted)
{
	const WCHAR* pSearched = (ignoreEndCharInQuoted ? getFirstUnquotedChar(pSrc,endchar) : wcschr(pSrc, endchar));;
	if(pSearched <= pSrc) return NULL;
	int n = pSearched - pSrc;
	return duplicateStr(pSrc, n);
}
void freeDuplicatedStr(WCHAR* p)
{
	if(p) free(p);
}
HtmlNode* HtmlParser::NewHtmlNode()
{
	static char staticHtmlNodeTemplate[sizeof(HtmlNode)] = {0};
	/*
	static HtmlNode staticHtmlNodeTemplate; //= {0};
	staticHtmlNodeTemplate.type = NODE_UNKNOWN;
	staticHtmlNodeTemplate.tagName[0] = L'/0';
	staticHtmlNodeTemplate.text = NULL;
	*/
	m_HtmlNodes.Append(staticHtmlNodeTemplate, sizeof(HtmlNode));
	HtmlNode* pNode = (HtmlNode*) (m_HtmlNodes.GetPtr() + m_HtmlNodes.GetSize() - sizeof(HtmlNode));
	return pNode;
}
void HtmlParser::ParseHtml(const WCHAR* szHtml)
{
	m_html = szHtml ? szHtml : L"";
	freeHtmlNodes();
	if(szHtml == NULL || *szHtml == L'/0') return;
	WCHAR* p = (WCHAR*) szHtml;
	WCHAR* s = (WCHAR*) szHtml;
	HtmlNode* pNode = NULL;
	WCHAR c;
	bool bInQuotes = false;
	while( c = *p )
	{
		if(c == L'/"')
		{
			bInQuotes = !bInQuotes;
			p++; continue;
		}
		if(bInQuotes)
		{
			p++; continue;
		}
		if(c == L'<')
		{
			if(p > s)
			{
				//Add Text Node
				pNode = NewHtmlNode();
				pNode->type = NODE_CONTENT;
				pNode->text = duplicateStrUtill(s, L'<', true);
			}
			s = p + 1;
		}
		else if(c == L'>')
		{
			if(p > s)
			{
				//Add HtmlTag Node
				pNode = NewHtmlNode();
				while(isspace(*s)) s++;
				pNode->type = (*s != L'/' ? NODE_START_TAG : NODE_CLOSE_TAG);
				if(*s == L'/') s++;
				copyStrUtill(pNode->tagName, MAX_HTML_TAG_LENGTH, s, L'>', true);
				//處理自封閉的結點, 如 <br/>, 刪除tagName中可能會有的'/'字元
				//自封閉的結點的type設置為NODE_START_TAG應該可以接受(否則要引入新的NODE_STARTCLOSE_TAG)
				int tagNamelen = wcslen(pNode->tagName);
				if(pNode->tagName[tagNamelen-1] == L'/')
					pNode->tagName[tagNamelen-1] = L'/0';
				//處理結點屬性
				for(int i = 0; i < tagNamelen; i++)
				{
					if(pNode->tagName[i] == L' ' //第一個空格後面跟的是屬性列表
						|| pNode->tagName[i] == L'=') //擴展支持這種格式: <tagName=value>, 等效於<tagName tagName=value>
					{
						WCHAR* props = (pNode->tagName[i] == L' ' ? s + i + 1 : s);
						pNode->text = duplicateStrUtill(props, L'>', true);
						int nodeTextLen = wcslen(pNode->text);
						if(pNode->text[nodeTextLen-1] == L'/') //去掉最後可能會有的'/'字元, 如這種情況: <img src="..." mce_src="..." />
							pNode->text[nodeTextLen-1] = L'/0';
						pNode->tagName[i] = L'/0';
						parseNodeProps(pNode); //parse props
						break;
					}
				}
				pNode->tagType = getHtmlTagTypeFromName(pNode->tagName);
			}
			s = p + 1;
		}
		p++;
	}
	if(p > s)
	{
		//Add Text Node
		pNode = NewHtmlNode();
		pNode->type = NODE_CONTENT;
		pNode->text = duplicateStr(s, -1);
	}
#ifdef _DEBUG
	dumpHtmlNodes(); //just for test
#endif
}
unsigned int HtmlParser::getHtmlNodeCount()
{
	return (m_HtmlNodes.GetSize() / sizeof(HtmlNode));
}
HtmlNode* HtmlParser::getHtmlNodes()
{
	return (HtmlNode*) m_HtmlNodes.GetPtr();
}
void HtmlParser::freeHtmlNodes()
{
	HtmlNode* pNodes = getHtmlNodes();
	for(int i = 0, count = getHtmlNodeCount(); i < count; i++)
	{
		HtmlNode* pNode = pNodes + i;
		if(pNode->text)
			freeDuplicatedStr(pNode->text);
		if(pNode->props)
			MFreeMemory(pNode->props); //see: CMem::Alloc
	}
	m_HtmlNodes.Empty();
}
//[virtual]
HtmlTagType HtmlParser::getHtmlTagTypeFromName(const WCHAR* szTagName)
{
	//todo: uses hashmap
	struct N2T { const WCHAR* name; HtmlTagType type; };
	static N2T n2tTable[] = 
	{
		{ L"A", TAG_A },
		{ L"FONT", TAG_FONT },
		{ L"IMG", TAG_IMG },
		{ L"P", TAG_P },
		{ L"DIV", TAG_DIV },
		{ L"SPAN", TAG_SPAN },
		{ L"BR", TAG_BR },
		{ L"B", TAG_B },
		{ L"I", TAG_I },
		{ L"HR", TAG_HR },
		{ L"COLOR", TAG_COLOR },
		{ L"BGCOLOR", TAG_BGCOLOR },
	};
	for(int i = 0, count = sizeof(n2tTable)/sizeof(n2tTable[0]); i < count; i++)
	{
		N2T* p = &n2tTable[i];
		if(wcsicmp(p->name, szTagName) == 0)
			return p->type;
	}
	return TAG_UNKNOWN;
}
void skipSpaceChars(WCHAR*& p)
{
	if(p)
	{
		while(isspace(*p)) p++;
	}
}
const WCHAR* nextUnqotedSpaceChar(const WCHAR* p)
{
	const WCHAR* r = getFirstUnquotedChar(p, L' ');
	if(!r)
		r = getFirstUnquotedChar(p, L'/t');
	return r;
}
const WCHAR* duplicateStrAndUnquote(const WCHAR* str, unsigned int nChar)
{
	if( nChar > 1 && (str[0] == L'/"' && str[nChar-1] == L'/"') || (str[0] == L'/'' && str[nChar-1] == L'/'') )
	{
		str++; nChar-=2;
	}
	return duplicateStr(str, nChar);
}
//[virtual]
void HtmlParser::parseNodeProps(HtmlNode* pNode)
{
	if(pNode == NULL || pNode->propCount > 0 || pNode->text == NULL)
		return;
	WCHAR* p = pNode->text;
	WCHAR *ps = NULL;
	CMem mem;
	bool inQuote1 = false, inQuote2 = false;
	WCHAR c;
	while(c = *p)
	{
		if(c == L'/"')
		{
			inQuote1 = !inQuote1;
		}
		else if(c == L'/'')
		{
			inQuote2 = !inQuote2;
		}
		if((!inQuote1 && !inQuote2) && (c == L' ' || c == L'/t' || c == L'='))
		{
			if(ps)
			{
				mem.AddPointer(duplicateStrAndUnquote(ps, p - ps));
				ps = NULL;
			}
			if(c == L'=')
				mem.AddPointer(NULL);
		}
		else
		{
			if(ps == NULL)
				ps = p;
		}
		p++;
	}
	if(ps)
		mem.AddPointer(duplicateStrAndUnquote(ps, p - ps));
	mem.AddPointer(NULL);
	mem.AddPointer(NULL);
	WCHAR** pp = (WCHAR**) mem.GetPtr();
	CMem props;
	for(int i = 0, n = mem.GetSize() / sizeof(WCHAR*) - 2; i < n; i++)
	{
		props.AddPointer(pp[i]); //prop name
		if(pp[i+1] == NULL)
		{
			props.AddPointer(pp[i+2]); //prop value
			i += 2;
		}
		else
			props.AddPointer(NULL); //prop vlalue
	}
	pNode->propCount = props.GetSize() / sizeof(WCHAR*) / 2;
	pNode->props = (HtmlNodeProp*) props.Detach();
}
const HtmlNodeProp* HtmlParser::getNodeProp(const HtmlNode* pNode, const WCHAR* szPropName)
{
	if(pNode == NULL || pNode->propCount <= 0)
		return NULL;
	for(int i = 0; i < pNode->propCount; i++)
	{
		HtmlNodeProp* prop = pNode->props + i;
		if(wcsicmp(prop->szName, szPropName) == 0)
			return prop;
	}
	return NULL;
}
const WCHAR* HtmlParser::getNodePropStringValue(const HtmlNode* pNode, const WCHAR* szPropName, const WCHAR* szDefaultValue /*= NULL*/)
{
	const HtmlNodeProp* pProp = getNodeProp(pNode, szPropName);
	if(pProp)
		return pProp->szValue;
	else
		return szDefaultValue;
}
int HtmlParser::getNodePropIntValue(const HtmlNode* pNode, const WCHAR* szPropName, int defaultValue /*= 0*/)
{
	const HtmlNodeProp* pProp = getNodeProp(pNode, szPropName);
	if(pProp && pProp->szValue)
		return _wtoi(pProp->szValue);
	else
		return defaultValue;
}
void HtmlParser::dumpHtmlNodes()
{
#ifdef _DEBUG
	HtmlNode* pNodes = getHtmlNodes();
	WCHAR buffer[256];
	OutputDebugString(L"/n-------- dumpHtmlNodes --------/n");
	for(int i = 0, count = getHtmlNodeCount(); i < count; i++)
	{
		HtmlNode* pNode = pNodes + i;
		switch(pNode->type)
		{
		case NODE_CONTENT:
			wsprintf(buffer, L"%2d) type: NODE_CONTENT, text: %s", i, pNode->text);
			break;
		case NODE_START_TAG:
			wsprintf(buffer, L"%2d) type: NODE_START_TAG, tagName: %s (%d), text: %s", i, pNode->tagName, pNode->tagType, pNode->text);
			break;
		case NODE_CLOSE_TAG:
			wsprintf(buffer, L"%2d) type: NODE_CLOSE_TAG, tagName: %s", i, pNode->tagName);
			break;
		case NODE_UNKNOWN:
		default:
			wsprintf(buffer, L"%2d) type: NODE_UNKNOWN", i);
			break;
		}
		OutputDebugString(buffer);
		OutputDebugString(L"/n");
		if(pNode->propCount > 0)
		{
			OutputDebugString(L"    props: ");
			for(int i = 0; i < pNode->propCount; i++)
			{
				HtmlNodeProp* prop = pNode->props + i;
				if(prop->szValue)
					wsprintf(buffer, L"%s = %s", prop->szName, prop->szValue);
				else
					wsprintf(buffer, L"%s", prop->szName);
				OutputDebugString(buffer);
				if(i < pNode->propCount - 1)
				{
					OutputDebugString(L", ");
				}
			}
			OutputDebugString(L"/n");
		}
	}
	OutputDebugString(L"-------- end of dumpHtmlNodes --------/n");
#endif
}
//just for test
class TestHtmlParser
{
public:
	TestHtmlParser()
	{
		HANDLE CMem_GetProcessHeap();
		CMem_GetProcessHeap();
		HtmlParser htmlParser;
		HtmlNode node;
		node.text = L" a=1 b c=/'x y=0/' d = abc ";
		htmlParser.parseNodeProps(&node);
		htmlParser.ParseHtml(L"...<p>---<a href="url" mce_href="url">link</a>...");
		htmlParser.ParseHtml(L"<p>---< a   href=url >link</a>");
		htmlParser.ParseHtml(L"<p x=a y=b z = /"c <a href="url" mce_href="url">/" >");
	}
};
TestHtmlParser testHtmlParser;
