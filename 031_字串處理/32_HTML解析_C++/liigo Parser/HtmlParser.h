#include "common.h"
//HtmlParser類，用於解析HTML文本
//by liigo, @2010
enum HtmlNodeType
{
	NODE_UNKNOWN = 0,
	NODE_START_TAG,
	NODE_CLOSE_TAG,
	NODE_CONTENT,
	NODE_SOFT_LINE,
};
enum HtmlTagType
{
	TAG_UNKNOWN = 0,
	TAG_A, TAG_DIV, TAG_FONT, TAG_IMG, TAG_P, TAG_SPAN, TAG_BR, TAG_B, TAG_I, TAG_HR, 
	TAG_COLOR, TAG_BGCOLOR, //非標準HTML標籤, 可以這樣使用: <color=red>, 等效於 <color color=red>
};
struct HtmlNodeProp
{
	WCHAR* szName;
	WCHAR* szValue;
};
#define MAX_HTML_TAG_LENGTH (15)
struct HtmlNode
{
	HtmlNodeType type;
	HtmlTagType  tagType;
	WCHAR tagName[MAX_HTML_TAG_LENGTH+1];
	WCHAR* text;
	int propCount;
	HtmlNodeProp* props;
};
class HtmlParser
{
	friend class HTMLView;
public:
	HtmlParser() {}
public:
	//html
	void ParseHtml(const WCHAR* szHtml);
	const WCHAR* GetHtml() const { return m_html.GetText(); }
	//nodes
	unsigned int getHtmlNodeCount();
	HtmlNode* getHtmlNodes();
	//props
	const HtmlNodeProp* getNodeProp(const HtmlNode* pNode, const WCHAR* szPropName);
	const WCHAR* getNodePropStringValue(const HtmlNode* pNode, const WCHAR* szPropName, const WCHAR* szDefaultValue = NULL);
	int getNodePropIntValue(const HtmlNode* pNode, const WCHAR* szPropName, int defaultValue = 0);
protected:
	//允許子類覆蓋, 以便識別更多結點(提高解析品質), 或者識別更少結點(提高解析速度)
	virtual HtmlTagType getHtmlTagTypeFromName(const WCHAR* szTagName);
public:
	//允許子類覆蓋, 以便更好的解析節點屬性, 或者乾脆不解析節點屬性(提高解析速度)
	virtual void parseNodeProps(HtmlNode* pNode); //todo: make protected, after testing
private:
	HtmlNode* NewHtmlNode();
	void freeHtmlNodes();
	void dumpHtmlNodes();
private:
	CMem m_HtmlNodes;
	CMString m_html;
};
//一些文本處理函數
WCHAR* duplicateStr(const WCHAR* pSrc, unsigned int nChar);
void freeDuplicatedStr(WCHAR* p);
unsigned int copyStr(WCHAR* pDest, unsigned int nDest, const WCHAR* pSrc, unsigned int nChar);
