// Machine generated IDispatch wrapper class(es) created with ClassWizard

/////////////////////////////////////////////////////////////////////////////
// IScriptControl wrapper class

class IScriptControl : public COleDispatchDriver
{
// Operations
public:
	void SetLanguage(LPCTSTR lpszNewValue);
	void SetSitehWnd(HWND hWnd);
	LPDISPATCH GetError();
	void AddObject(LPCTSTR Name, LPDISPATCH Object, BOOL AddMembers);
	void AddCode(LPCTSTR Code);
};

const CLSID CLSID_ScriptControl = {0x0E59F1D5,0x1FBE,0x11D0,{0x8F,0xF2,0x00,0xA0,0xD1,0x00,0x38,0xBC}};

/////////////////////////////////////////////////////////////////////////////
// IScriptError wrapper class

class IScriptError : public COleDispatchDriver
{
// Operations
public:
	long GetNumber();
	long GetLine();
	long GetColumn();
	CString GetText();
};
