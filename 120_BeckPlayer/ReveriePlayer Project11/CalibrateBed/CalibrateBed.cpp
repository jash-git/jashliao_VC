// CalibrateBed.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CalibrateBed.h"
#include "RS232.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#import "msxml3.dll"
using namespace MSXML2;//XML_Setp 1
/////////////////////////////////////////////////////////////////////////////
// The one and only application object

CWinApp theApp;

using namespace std;
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member function
	void InitialVariable(void);
	////////////////////////////////////////////////////////////////////
	//Jash.Liao add member variable
	TCHAR m_chrCurDrt[500];//存放目前目錄字串
	CString m_StrSettingFileName;
	long m_lngTop,m_lngLeft,m_lngWidth,m_lngHeight;
	CRgn m_rgn;
	int m_intCOMPort;
	CString m_StrRVideo,m_StrOVideo,m_StrTitelVideo;
	////////////////////////////////////////////////////////////////////
	void InitRS485andBed();
	bool blnopenRS485;
	CRS232 RS;
	void StepControl00();
void StepControl00()
{
	char buf[3];
	//buf[0]=35;//#
	//buf[1]=71;//G
	//buf[2]=buf[0]^buf[1];//# XOR G
	//if(blnopenRS485)
	//{
	//	RS.Write(buf,3);
	//}
	//else
		//MessageBox("Not Open RS485");	
	//Sleep(1000);
	buf[0]=35;//#
	buf[1]=66;//B
	buf[2]=buf[0]^buf[1];//# XOR B
	if(blnopenRS485)
	{
		RS.Write(buf,3);
		cout << "Wait...." << endl;
	}
	else
	{
		cout << "RS485 error" << endl;
	}
	///////////////
}
void InitRS485andBed()
{
	/////////////////////////////////////////////////////
	//open RS485
	blnopenRS485=RS.OpenCom(m_intCOMPort,9600,8,0,1);
	////////////////////////////////////////////////
	/*
	//step 00
	char buf[4];
	buf[0]=35;//#
	buf[1]=72;//H
	buf[2]=01;//1->TV,2->Zero
	buf[3]=buf[0]^buf[1]^buf[2];//# XOR H XOR 1
	if(blnopenRS485)
	{
		RS.Write(buf,4);
		Sleep(1000);
		char Output[50];
		long count;
		RS.Read(Output,&count);
	}
	else
		MessageBox("init_Not Open RS485");
	*/
}
void InitialVariable(void)
{
	MSXML2::IXMLDOMDocumentPtr pDoc;
	int nLen=0;
	bool blnRead=false;
	_variant_t vtStr;
	CString StrValue;
	m_lngTop=0;m_lngLeft=0;m_lngWidth=0;m_lngHeight=0;
	m_intCOMPort=1;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	nLen= ::GetCurrentDirectory(500,m_chrCurDrt);//取得目前程式路徑
	m_StrSettingFileName+="Resources\\Config.xml";
	blnRead=pDoc->load((_bstr_t)m_StrSettingFileName);
	if(blnRead)
	{
		//////////////////////////////////////////////////
		MSXML2::IXMLDOMNodePtr Position_Size;
		Position_Size=pDoc->selectSingleNode("//Top");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngTop=_ttoi(static_cast<LPCTSTR>(StrValue)); 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Left");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngLeft=_ttoi(static_cast<LPCTSTR>(StrValue));  
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Width");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngWidth=_ttoi(static_cast<LPCTSTR>(StrValue));  
		//************************************************
		Position_Size=pDoc->selectSingleNode("//Height");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_lngHeight=_ttoi(static_cast<LPCTSTR>(StrValue)); 
		//************************************************
		Position_Size=pDoc->selectSingleNode("//COM_Port");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_intCOMPort=_ttoi(static_cast<LPCTSTR>(StrValue)); 
		//////////////////////////////////////////////////
		Position_Size=pDoc->selectSingleNode("//R_Video");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrRVideo=StrValue;
		//////////////////////////////////////////////////
		Position_Size=pDoc->selectSingleNode("//O_Video");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrOVideo=StrValue;
		//////////////////////////////////////////////////
		Position_Size=pDoc->selectSingleNode("//Title_Video");
		Position_Size->get_nodeTypedValue(&vtStr);
		StrValue=vtStr.bstrVal;
		m_StrTitelVideo=StrValue;
	}
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		cerr << _T("Fatal Error: MFC initialization failed") << endl;
		nRetCode = 1;
	}
	else
	{
		// TODO: code your application's behavior here.
		::CoInitialize(NULL);
		CString strHello;
		strHello="Read Variable...";
		cout << (LPCTSTR)strHello << endl;
		InitialVariable();
		strHello="setting RS48...";
		cout << (LPCTSTR)strHello << endl;
		InitRS485andBed();
		strHello="Calibrate Bed...";
		cout << (LPCTSTR)strHello << endl;
		StepControl00();
		Sleep(25000);	
	}
	return nRetCode;
}


