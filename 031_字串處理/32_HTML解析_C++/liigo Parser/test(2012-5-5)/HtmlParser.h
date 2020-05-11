#ifndef __HtmlParser_H__
#define __HtmlParser_H__

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

// HtmlParser類，用於解析HTML文本
// http://blog.csdn.net/liigo/article/details/6153829 (重要)
// by liigo, @2010-2012

namespace liigo
{

//MemBuffer: 記憶體緩衝區類，管理緩存區中連續存儲的資料
#define MEM_DEFAULT_BUFFER_SIZE  256
class MemBuffer
{
public:
	//nBufferSize指定緩存區初始大小(位元組數), 為-1表示使用默認初始大小(MEM_DEFAULT_BUFFER_SIZE)
	//nBufferSize為0時暫不分配緩存區記憶體，延遲到下一次寫入資料時再分配
	MemBuffer(size_t nBufferSize = -1);
	MemBuffer(const MemBuffer& other); //從other物件複製資料，緩存區是自行分配的
	virtual ~MemBuffer(); //析構時清理緩存區釋放記憶體，除非已經detach()
	const MemBuffer& operator= (const MemBuffer& other); //清空資料後再把other內的資料複製進來

public:
	//向緩存區複製資料塊，寫入現有資料的末尾，必要時會自動擴充緩存區
	//返回新寫入的資料塊首位址在緩存區中的偏移量
	size_t appendData(const void* pData, size_t nSize);
	//在指定索引offset處插入指定長度nSize的資料，pData為NULL時插入的資料均為0位元組值，原有資料自動後移，必要時會自動擴充緩存區
	void insertData(size_t offset, const void* pData, size_t nSize);
	//在指定索引offset處刪除指定長度size的資料，原有資料自動前移
	void deleteData(size_t offset, size_t size);
	//取資料首位址(在資料長度為0時返回NULL)
	//在appendXXX()或insertData()或resetSize()或shrink()或exchange()或operator=調用之後可能會導致資料首位址發生改變
	inline void* getData() const { return (m_nDataSize == 0 ? NULL : m_pBuffer); }
	//取指定偏移處資料位址，偏移offset應小於getDataSize()，否則不保證返回的位址有效
	inline void* getOffsetData(int offset) const { return (m_nDataSize == 0 ? NULL : ((unsigned char*)m_pBuffer + offset)); }
	//取數據長度
	inline size_t getDataSize() const { return m_nDataSize; }
	//重置資料長度，新長度可以為任意值，必要時會自動擴充緩存區，新增加的資料均為0位元組值
	void resetDataSize(size_t size = 0);
	//清空數據，等效於resetDataSize(0)
	inline void empty() { resetDataSize(0); }
	//收縮緩存區，避免長時間佔用不再使用的記憶體，但緩存區中的已有資料仍然完整保留
	void shrink();
	//清理緩存區，釋放記憶體
	void clean();
	//放棄管理緩存區和其中的資料，用戶應自行負責用free()釋放detach()後的資料:
	//返回資料首位址，資料長度為detach()前getDataSize()返回的長度
	//detach()時指定參數bShrink為true可有效避免浪費未經使用的緩存區記憶體
	void* detach(bool bShrink = true);
	//交換兩個物件(this & other)各自管理的所有內容（包括資料和緩存區）
	void exchange(MemBuffer& other);

	//添加基本類型資料
	inline size_t appendInt(int i) { return appendData(&i, sizeof(i)); }
	inline size_t appendChar(char c) { return appendData(&c, sizeof(c)); }
	//把指標p本身的值（而非p指向的資料）添加到緩存區
	inline size_t appendPointer(const void* p) { return appendData(&p, sizeof(p)); }
	//把文本內容添加到緩存區, len為寫入的位元組數（-1表示strlen(szText)），appendZeroChar表示是否額外添加'\0'
	size_t appendText(const char* szText, size_t len = -1, bool appendZeroChar = false);
	//把指定數量的0位元組值添加到緩存區
	size_t appendZeroBytes(int count);

	//讀取檔全部內容，如果keepExistData=true將保留緩存區原有資料，否則將清除原有資料
	//參數appendZeroChar表示是否額外添加字元'\0'，參數pReadBytesr如果非NULL將寫入從檔中讀取的位元組數
	//在磁片讀寫出錯未完整讀取檔內容的情況下，將返回false，但已經讀取的部分資料仍然保留，pReadBytesr中會寫入讀取的位元組數
	bool loadFromFile(const char* szFileName, bool keepExistData = false, bool appendZeroChar = false, size_t* pReadBytes = NULL);
	//將資料保存到檔，後兩個參數(pBOM,bomLen)為欲寫到文件頭部的BOM(Byte Order Mark)
	//如果檔已經存在，將直接覆蓋掉原有檔內容
	bool saveToFile(const char* szFileName, const void* pBOM = NULL, size_t bomLen = 0);

private:
	//要求緩存區中至少留出長度為size的未使用空間
	//返回未使用空間的首位址，即現有資料的末尾
	void* require(size_t size);

private:
	unsigned char* m_pBuffer; //緩存區首地址
	size_t m_nDataSize, m_nBufferSize; //數據長度，緩存區長度
};

enum HtmlNodeType
{
	NODE_NULL = 0,  //作為所有節點的終結標記
	NODE_START_TAG, //開始標籤，如 <a href="liigo.com"> 或 <br/>
	NODE_END_TAG,   //結束標籤，如 </a>
	NODE_CONTENT,   //內容: 介於開始標籤和/或結束標籤之間的普通文本
	NODE_REMARKS,   //注釋: <!-- -->
	NODE_UNKNOWN,   //未知的節點類型
	_NODE_USER_,    //用戶定義的其他節點類型值應大於_NODE_USER_，以確保不與上面定義的常量值重複
};

enum HtmlTagType
{
	TAG_UNKNOWN = 0, //表示未經識別的標籤類型，參見HtmlParser.onIdentifyHtmlTag()
	TAG_SCRIPT, TAG_STYLE, TAG_TEXTAREA, //出於解析需要必須識別<script>,<style>和<textarea>，內部特別處理
	//以下按標籤字母順序排列, 來源：http://www.w3.org/TR/html4/index/elements.html (HTML4)
	//and http://www.w3.org/TR/html5/section-index.html#elements-1 (HTML5)
	//此處僅定義類型值，不代表解析器一定識別出它們，參見HtmlParser.onIdentifyHtmlTag()
	TAG_A, TAG_ABBR, TAG_ACRONYM, TAG_ADDRESS, TAG_APPLET, TAG_AREA, TAG_ARTICLE, TAG_ASIDE, TAG_AUDIO, 
	TAG_B, TAG_BASE, TAG_BASEFONT, TAG_BDI, TAG_BDO, TAG_BIG, TAG_BLOCKQUOTE, TAG_BODY, TAG_BR, TAG_BUTTON, 
	TAG_CAPTION, TAG_CENTER, TAG_CITE, TAG_CODE, TAG_COL, TAG_COLGROUP, TAG_COMMAND, 
	TAG_DATALIST, TAG_DD, TAG_DEL, TAG_DETAILS, TAG_DFN, TAG_DIR, TAG_DIV, TAG_DL, TAG_DT, TAG_EM, TAG_EMBED, 
	TAG_FIELDSET, TAG_FIGCAPTION, TAG_FIGURE, TAG_FONT, TAG_FOOTER, TAG_FORM, TAG_FRAME, TAG_FRAMESET, 
	TAG_H1, TAG_H2, TAG_H3, TAG_H4, TAG_H5, TAG_H6, TAG_HEAD, TAG_HEADER, TAG_HGROUP, TAG_HR, TAG_HTML, 
	TAG_I, TAG_IFRAME, TAG_IMG, TAG_INPUT, TAG_INS, TAG_ISINDEX, TAG_KBD, TAG_KEYGEN, 
	TAG_LABEL, TAG_LEGEND, TAG_LI, TAG_LINK, TAG_MAP, TAG_MARK, TAG_MENU, TAG_META, TAG_METER, TAG_NAV, TAG_NOFRAMES, TAG_NOSCRIPT, 
	TAG_OBJECT, TAG_OL, TAG_OPTGROUP, TAG_OPTION, TAG_P, TAG_PARAM, TAG_PRE, TAG_PROGRESS, TAG_Q, TAG_RP, TAG_RT, TAG_RUBY, 
	TAG_S, TAG_SAMP, TAG_SECTION, TAG_SELECT, TAG_SMALL, TAG_SOURCE, TAG_SPAN, TAG_STRIKE, TAG_STRONG, TAG_SUB, TAG_SUMMARY, TAG_SUP, 
	TAG_TABLE, TAG_TBODY, TAG_TD, TAG_TFOOT, TAG_TH, TAG_THEAD, TAG_TIME, TAG_TITLE, TAG_TR, TAG_TRACK, TAG_TT, 
	TAG_U, TAG_UL, TAG_VAR, TAG_VIDEO, TAG_WBR, 
	_TAG_USER_TAG_, //用戶定義的其他標籤類型值應大於_TAG_USER_TAG_，以確保不與上面定義的常量值重複
};

enum HtmlNodeFlag
{
	//flags used in HtmlNode.flags
	FLAG_SELF_CLOSING_TAG = 1 << 0, //是自封閉標籤: <br/>
	FLAG_CDATA_BLOCK      = 1 << 1, //是CDATA區塊
	FLAG_NEED_FREE_TEXT   = 1 << 2, //需free(HtmlNode.text)

	//flags used in HtmlAttribute.flags
	FLAG_NEED_FREE_NAME   = 1 << 0, //需free(HtmlAttribute.name)
	FLAG_NEED_FREE_VALUE  = 1 << 1, //需free(HtmlAttribute.value)
};

struct HtmlAttribute
{
	char* name;   //屬性名稱
	char* value;  //屬性值
	size_t flags; //bit OR of HtmlNodeFlag
};

#define MAX_HTML_TAG_LENGTH  15 //節點名稱的最大字元長度,超出將被截斷

struct HtmlNode
{
	HtmlNodeType type;    //節點類型
	HtmlTagType  tagType; //標籤類型（僅當節點類型為NODE_START_TAG或NODE_END_TAG時有意義）
	char tagName[MAX_HTML_TAG_LENGTH+1]; //標籤名稱（如<A href="...">對應的標籤名稱為"A"）
	char* text; //文本，視標籤類型(tagType)不同意義也不同，可能為NULL
				//如果type==NODE_START_TAG, text指向標籤名稱後面的屬性文本
				//如果type==NODE_CONTENT或NODE_REMARKS, text指向內容或注釋文本
	int attributeCount;    //屬性個數（僅當屬性被解析後有效，參見HtmlParser.parseAttributes()，下同）
	MemBuffer* attributes; //屬性（名稱=值），參見HtmlParser.getAttribute()。將來可以動態添加屬性。
	size_t flags;    //bit OR of HtmlNodeFlag
	void* pUser;     //user customized, default to NULL
};


//HtmlParser: HTML文本解析類
class HtmlParser
{
public:
	HtmlParser() {}
	virtual ~HtmlParser() { cleanHtmlNodes(); }

private:
	//disallow copy and assign: only declare, no implementation
	HtmlParser(const HtmlParser&);
	void operator=(const HtmlParser&);

public:
	//解析HTML，解析結果是一系列連續存儲的HtmlNode節點（可通過getHtmlNode(index)獲取）
	//最後必然會額外添加一個NODE_NULL節點(HtmlNode.type==NODE_NULL)作為所有節點的終結標記
	//參數parseAttributes為true時，虛函數onParseAttributes()必要時將被調用，用戶有機會決定是否解析屬性
	//參數parseAttributes為false表示不解析任何屬性，甚至連onParseAttributes()也不會調用
	void parseHtml(const char* szHtml, bool parseAttributes = true);

	//取節點個數（不包括最後一個額外添加的NODE_NULL節點）
	int getHtmlNodeCount();
	//取指定索引處的節點，索引必須合法: 0 <= index <= getHtmlNodeCount()
	//其中最後一個節點（即index==getHtmlNodeCount()處）為額外添加的NODE_NULL節點
	HtmlNode* getHtmlNode(int index);

	static bool cloneHtmlNode(const HtmlNode* pSrcNode, HtmlNode* pDestNode); //需使用cleanHtmlNode()清理
	static void cleanHtmlNode(HtmlNode* pNode); //只清理節點中動態分配的內容，保留type,tagType,tagName,flags,pUser
	void cleanHtmlNodes(); //清理所有節點並釋放所佔用記憶體

	//attributes
	static const HtmlAttribute* getAttribute(const HtmlNode* pNode, size_t index); //must: 0 <= index < pNode->attributeCount
	static const HtmlAttribute* getAttribute(const HtmlNode* pNode, const char* szAttributeName); //return NULL if attribute not exist
	static const char* getAttributeStringValue(const HtmlNode* pNode, const char* szAttributeName, const char* szDefaultValue = NULL);
	static int getAttributeIntValue(const HtmlNode* pNode, const char* szAttributeName, int defaultValue = 0);
	static void parseAttributes(HtmlNode* pNode); //解析pNode->text裏面的屬性, 通常在onParseAttributes()內使用
	static void parseExtraAttributes(const char* szAttributesText, HtmlNode* pTargetNode, const char* szNamePrefix = NULL); //解析文本szAttributesText裏的屬性並存入pTargetNode（保留原有屬性）, 參數szNamePrefix用於指定額外添加的屬性名稱首碼（以防新解析的屬性與原有屬性名稱衝突）
	//output
	void outputHtml(MemBuffer& buffer, bool keepBufferData = false);
	static void outputHtmlNode(MemBuffer& buffer, const HtmlNode* pNode);
	void dumpHtmlNodes(FILE* f = stdout); //for debug or test
	static void dumpHtmlNode(const HtmlNode* pNode, int nodeIndex = -1, FILE* f = stdout);

protected:
	//允許子類覆蓋, 以便識別更多標籤(提高解析品質), 或者識別更少標籤(提高解析速度)
	//默認僅識別涉及HTML基本結構和資訊的有限幾個開始標籤: A,IMG,META,BODY,TITLE,FRAME,IFRAME
	//onIdentifyHtmlTag()先於onParseAttributes()被調用
	virtual HtmlTagType onIdentifyHtmlTag(const char* szTagName, HtmlNodeType nodeType);
	//允許子類覆蓋, 以便更好的解析節點屬性, 或者部分解析甚至乾脆不解析節點屬性(提高解析速度)
	//可以根據標籤名稱(pNode->tagName)或標籤類型(pNode->tagType)判斷是否需要解析屬性（parseAttributes()）
	//默認僅解析"已識別出標籤類型"的標籤屬性（即pNode->tagType != TAG_UNKNOWN）
	virtual void onParseAttributes(HtmlNode* pNode);
	//允許子類覆蓋, 在某節點解析完成後被調用, 如果返回false則立刻停止解析HTML
	//這裏也許是一個恰當的時機初始化pNode->pUser
	virtual bool onNodeReady(HtmlNode* pNode) { return true; }

private:
	HtmlNode* appendHtmlNode();

private:
	MemBuffer m_HtmlNodes;
};

} //namespace liigo

#endif //__HtmlParser_H__

