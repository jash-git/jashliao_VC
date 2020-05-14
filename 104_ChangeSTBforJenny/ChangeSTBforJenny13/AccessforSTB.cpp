// AccessforSTB.cpp: implementation of the CAccessforSTB class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AccessforSTB.h"
#include "NetUsebat.h"
#include "FileCopyDelete.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#define BUFFER_SIZE 2048//http_download
extern TCHAR gstrCurDrt[500];//存放目其目錄字串
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CAccessforSTB::CAccessforSTB()
{
	::CoInitialize(NULL); //step 2:讀取XML
}

CAccessforSTB::~CAccessforSTB()
{

}
void CAccessforSTB::InitReadXML()
{
	::CoInitialize(NULL);
}
void CAccessforSTB::GetConfigParameter()//step 4:讀取XML
{
	char d1[200]={'\0'},d2[200]={'\0'},d3[200]={'\0'};
	MSXML2::IXMLDOMDocumentPtr pDoc;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	bool blnRead=false;
	long i=0,lngDataCount=0;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="NabroSTBToolConfig.xml";
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)//第11.0版的功能
	{
		MSXML2::IXMLDOMNodePtr pNodeData;
		pNodeData=pDoc->selectSingleNode("//EnableSTBUrl");
		pNodeData->get_nodeTypedValue(&vtStr);
		m_StrEnableSTBUrl=vtStr.bstrVal;
		pNodeData=pDoc->selectSingleNode("//NetDir");
		pNodeData->get_nodeTypedValue(&vtStr);
		m_StrNetDir=vtStr.bstrVal;
		pNodeData=pDoc->selectSingleNode("//EnableuidUrl");
		pNodeData->get_nodeTypedValue(&vtStr);
		m_StrEnableuidUrl=vtStr.bstrVal;
	}
	/*
	////////////////////////////////
	//test
	MessageBox(m_StrEnableSTBUrl);
	MessageBox(m_StrNetDir);
	///////////////////////////////
	*/
}
bool CAccessforSTB::GetWebFile(CString theUrl, CString Filename)//http_download
{
    CInternetSession session;
    CInternetFile* file = NULL;
    try
    {
        // Try to connect with the URL
        file = (CInternetFile*)session.OpenURL(theUrl); 
    }
    catch (CInternetException* m_pException)
    {
        // if some error occurs, set the file with NULL
        file = NULL; 
        m_pException->Delete();
        return FALSE;
    }

    BOOL bRet = FALSE;
    // use dataStore to save the file content
    CStdioFile dataStore;
    if(dataStore.Open(Filename, CFile::modeCreate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeBinary))
    {
        if (file)
        {
            UINT somelen = 0;
            BYTE somecode[BUFFER_SIZE];
            while((somelen = file->Read(somecode, BUFFER_SIZE)) > 0)
            {
                dataStore.Write(somecode, somelen);
            }
            bRet = TRUE;
        }
        dataStore.Close();
    }
    if(file)
    {
        file->Close();
        delete file;
    }
    return bRet;
}
void CAccessforSTB::GetSTBInformation()
{
	int i,j;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMDocumentPtr pxmldom1;
	MSXML2::IXMLDOMNodeListPtr pNodeList;
	MSXML2::IXMLDOMNodePtr pNodeData;
	MSXML2::IXMLDOMNodePtr pNodeSTBuid;
	MSXML2::IXMLDOMNodePtr pNodeSTBIP;
	CString StrSTBuid;
	CString StrSTBIP;
	CTime t1=CTime::GetCurrentTime();
	_variant_t vtStr;
	_bstr_t bt1;
	bool blnRead=false;
	long lngDataCount=0;
	m_ArraySTBuid.RemoveAll();//CArray Step
	m_ArraySTBIP.RemoveAll();//CArray Step
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="STBEnableList.xml";
	FILE *pfIPMappingUid;
	pfIPMappingUid=fopen("IPMappingUid.txt","w");
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)//第11.0版的功能
	{
		i=0;
		j=0;
		///////////////////////////////////////////////////
		pNodeList=pDoc->selectNodes("//STB");
		j=pNodeList->length;
		for(i=0;i<j;i++)
		{
			pNodeData=pNodeList->item[i];
			bt1=pNodeData->Getxml();
			hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
			blnRead=pxmldom1->loadXML(bt1);
			////////////////////////////////////////////////////////
			pNodeSTBuid=pxmldom1->selectSingleNode("//STB_uid");
			pNodeSTBuid->get_nodeTypedValue(&vtStr);
			StrSTBuid=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeSTBIP=pxmldom1->selectSingleNode("//STB_IP");
			pNodeSTBIP->get_nodeTypedValue(&vtStr);
			StrSTBIP=vtStr.bstrVal;
			///////////////////////////////////////////////////////
			m_ArraySTBuid.Add(StrSTBuid);
			m_ArraySTBIP.Add(StrSTBIP);
			fprintf(pfIPMappingUid,"%s\t%s\n",StrSTBIP.GetBuffer(0),StrSTBuid.GetBuffer(0));
		}
		fclose(pfIPMappingUid);
	}
	/*
	////////////////////////////////
	//test
	MessageBox(StrSTBuid);
	MessageBox(StrSTBIP);
	///////////////////////////////
	*/
}
void CAccessforSTB::GetSTBMovieInformation(CString StrSTBuid)
{
	CString StrUrl;
	CString StrFileName;
	StrUrl=m_StrEnableuidUrl;
	StrUrl+="&STBuid=";
	StrUrl+=StrSTBuid;
	StrFileName=StrSTBuid;
	StrFileName+=".xml";
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="\\STBMovieInformation\\";
	strFileName1 +=StrFileName;
	GetWebFile(StrUrl,strFileName1);

}
bool CAccessforSTB::ConnectSTB(CString StrIP,int count)
{
	CNetUsebat NUB;
	CString StrNetPath;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient";
	NUB.Createbat("nabro","nabro",StrNetPath,count);
	if(NUB.CreateShareDir())
	{
		/*
		////////////////////////////////
		//test
		MessageBox(StrIP);
		///////////////////////////////
		*/
		return true;
	}
	return false;
}
void CAccessforSTB::ReadAVListXML(CString Struid)
{
	CString StrFileName;
	StrFileName=Struid;
	StrFileName+=".xml";
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="\\STBMovieInformation\\";
	strFileName1 +=StrFileName;
	////////////////////////////////////////////////////////////////
	m_ArrayFileSourcePath.RemoveAll();
	m_ArrayFileDestPath.RemoveAll();
	m_ArrayFileStartDate.RemoveAll();
	m_ArrayFileEndDate.RemoveAll();
	///////////////////////////////////////////////////////////////
	int i,j;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	MSXML2::IXMLDOMDocumentPtr pxmldom1;
	MSXML2::IXMLDOMNodeListPtr pNodeList;
	MSXML2::IXMLDOMNodePtr pNodeData;
	MSXML2::IXMLDOMNodePtr pNodeFileSourcePath;
	MSXML2::IXMLDOMNodePtr pNodeFileDestPath;
	MSXML2::IXMLDOMNodePtr pNodeFileStartDate;
	MSXML2::IXMLDOMNodePtr pNodeFileEndDate;
	CString StrFileSourcePath;
	CString StrFileDestPath;
	CString StrFileStartDate;
	CString StrFileEndDate;
	_variant_t vtStr;
	_bstr_t bt1;
	bool blnRead=false;
	long lngDataCount=0;
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   return;
	}
	blnRead=pDoc->load((_bstr_t)strFileName1);
	if(blnRead)//第11.0版的功能
	{
		i=0;
		j=0;
		///////////////////////////////////////////////////
		pNodeList=pDoc->selectNodes("//File");
		j=pNodeList->length;
		for(i=0;i<j;i++)
		{
			pNodeData=pNodeList->item[i];
			bt1=pNodeData->Getxml();
			hr = pxmldom1.CreateInstance(__uuidof(MSXML2::DOMDocument30));
			blnRead=pxmldom1->loadXML(bt1);
			////////////////////////////////////////////////////////
			pNodeFileSourcePath=pxmldom1->selectSingleNode("//FileSourcePath");
			pNodeFileSourcePath->get_nodeTypedValue(&vtStr);
			StrFileSourcePath=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeFileDestPath=pxmldom1->selectSingleNode("//FileDestPath");
			pNodeFileDestPath->get_nodeTypedValue(&vtStr);
			StrFileDestPath=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeFileStartDate=pxmldom1->selectSingleNode("//FileStartDate");
			pNodeFileStartDate->get_nodeTypedValue(&vtStr);
			StrFileStartDate=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			pNodeFileEndDate=pxmldom1->selectSingleNode("//FileEndDate");
			pNodeFileEndDate->get_nodeTypedValue(&vtStr);
			StrFileEndDate=vtStr.bstrVal;
			////////////////////////////////////////////////////////
			m_ArrayFileSourcePath.Add(StrFileSourcePath);
			m_ArrayFileDestPath.Add(StrFileDestPath);
			m_ArrayFileStartDate.Add(StrFileStartDate);
			m_ArrayFileEndDate.Add(StrFileEndDate);
		}
	}
	/*
	////////////////////////////////
	//test
	MessageBox(StrFileSourcePath);
	MessageBox(StrFileDestPath);
	MessageBox(StrFileStartDate);
	MessageBox(StrFileEndDate);
	///////////////////////////////
	*/
}
void CAccessforSTB::ReadSTBAVList(CString StrIP)
{
	int i,j;
	i=0;j=0;
	CString StrNetPath;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\AV\\";
	CFileCopyDelete FCD;
	FCD.BrowseDir(StrNetPath,2);
	m_ArrayBrowseData.RemoveAll();
	FCD.GetArrayData(2,&m_ArrayBrowseData);
	/*
	//////////////////////////////////////////////
	//test
	j=m_ArrayBrowseData.GetSize();
	for(i=0;i<j;i++)
	{
		MessageBox(m_ArrayBrowseData.GetAt(i));
	}
	/////////////////////////////////////////////
	*/
}
void CAccessforSTB::STBAddAVFile(CString Struid,CString StrIP)
{
	int i,j;
	int k,l;
	//來源->m_ArrayFileSourcePath
	//目的->m_ArrayBrowseData
	CString StrNewFilePath;
	CString StrNewFileName;
	CString StrOldFilePath;
	CString StrOldFileName;
	CString StrLogFileName;
	CString StrStartTime;
	CString StrEndTime;
	CString StrInfoFileName;
	j=m_ArrayFileSourcePath.GetSize();//New
	l=m_ArrayBrowseData.GetSize();//Old
	CString StrNetPath;
	CString StrNetPathName;
	StrNetPath="\\\\";
	StrNetPath+=StrIP;
	StrNetPath+="\\D$\\NabroClient\\AV\\";
	bool blnNotFind=true;
	for(i=0;i<j;i++)
	{
		//New Get
		StrStartTime=m_ArrayFileStartDate.GetAt(i);
		StrEndTime=m_ArrayFileEndDate.GetAt(i);
		StrNewFilePath=m_ArrayFileSourcePath.GetAt(i);
		StrNewFileName=GetFilePath2FileName(StrNewFilePath);
		for(k=0;k<l;k++)
		{
			//Old Get
			StrOldFilePath=m_ArrayBrowseData.GetAt(k);
			StrOldFileName=GetFilePath2FileName(StrOldFilePath);
			if(StrNewFileName==StrOldFileName)
			{
				blnNotFind=false;
				break;
			}
		}
		if(blnNotFind==true)
		{
			/////////////////////////////////////////////////////////
			int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
			if( gstrCurDrt[nLen]!='\\' )
			{
				gstrCurDrt[nLen++] = '\\';
				gstrCurDrt[nLen] = '\0';
			}
			CString strFileName1 = gstrCurDrt;
			strFileName1 +="\\STBCheckLogs\\";
			StrLogFileName=StrIP+"_";
			StrLogFileName+=Struid+"_Addlog.txt";
			strFileName1 +=StrLogFileName;
			StrInfoFileName=CreatInfoFileHead(StrStartTime,StrEndTime);
			StrInfoFileName+=StrNewFileName;
			StrInfoFileName+=".info";
			FILE *pfLogFile;
			pfLogFile=fopen(strFileName1.GetBuffer(0),"a");
			StrNetPathName=StrNetPath+StrNewFileName;
			if(CopyFile(StrNewFilePath.GetBuffer(0),StrNetPathName.GetBuffer(0),false))
			{
				fprintf(pfLogFile,"%s\t%s\n",StrNewFilePath.GetBuffer(0),"OK");
			}
			else
			{
				fprintf(pfLogFile,"%s\t%s\n",StrNewFilePath.GetBuffer(0),"Not OK");
			}
			StrNetPathName="";
			StrNetPathName=StrNetPath+"\\Schedule\\";
			StrNetPathName+=StrInfoFileName;
			FILE *pfInfo;
			pfInfo=fopen(StrNetPathName.GetBuffer(0),"w");
			if(pfInfo!=NULL)
			{
				fprintf(pfLogFile,"%s\t%s\n",StrInfoFileName.GetBuffer(0),"OK");
				fprintf(pfLogFile,"\n");
				fclose(pfInfo);
			}
			else
			{
				fprintf(pfLogFile,"%s\t%s\n",StrInfoFileName.GetBuffer(0),"Not OK");
				fprintf(pfLogFile,"\n");
			}
			pfInfo=NULL;
			fclose(pfLogFile);
			pfLogFile=NULL;
			/////////////////////////////////////////////////////////
		}
		else
		{
			blnNotFind=true;
		}
	}
}
void CAccessforSTB::STBDelAVFile(CString Struid,CString StrIP)
{
	int i,j;
	int k,l;
	//來源->m_ArrayFileSourcePath
	//目的->m_ArrayBrowseData
	CString StrNewFilePath;
	CString StrNewFileName;
	CString StrOldFilePath;
	CString StrOldFileName;
	CString StrLogFileName;
	l=m_ArrayFileSourcePath.GetSize();//New
	j=m_ArrayBrowseData.GetSize();//Old
	bool blnNotFind=true;
	for(i=0;i<j;i++)
	{
		//Old Get
		StrOldFilePath=m_ArrayBrowseData.GetAt(i);
		StrOldFileName=GetFilePath2FileName(StrOldFilePath);
		for(k=0;k<l;k++)
		{
			//New Get
			StrNewFilePath=m_ArrayFileSourcePath.GetAt(k);
			StrNewFileName=GetFilePath2FileName(StrNewFilePath);
			if(StrNewFileName==StrOldFileName)
			{
				blnNotFind=false;
				break;
			}
		}
		if(blnNotFind==true)
		{
			/////////////////////////////////////////////////////////
			int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
			if( gstrCurDrt[nLen]!='\\' )
			{
				gstrCurDrt[nLen++] = '\\';
				gstrCurDrt[nLen] = '\0';
			}
			CString strFileName1 = gstrCurDrt;
			strFileName1 +="\\STBCheckLogs\\";
			StrLogFileName=StrIP+"_";
			StrLogFileName+=Struid+"_Dellog.txt";
			strFileName1 +=StrLogFileName;
			FILE *pfLogFile;
			pfLogFile=fopen(strFileName1.GetBuffer(0),"a");
			if(DeleteFile(StrOldFilePath.GetBuffer(0)))
			{
				fprintf(pfLogFile,"%s\t%s\n",StrOldFilePath.GetBuffer(0),"OK");
			}
			else
			{
				fprintf(pfLogFile,"%s\t%s\n",StrOldFilePath.GetBuffer(0),"Not OK");
			}
			fclose(pfLogFile);
			pfLogFile=NULL;
			/////////////////////////////////////////////////////////
		}
		else
		{
			blnNotFind=true;
		}
	}
}
CString CAccessforSTB::GetFilePath2FileName(CString Strdata)
{
	int i,intnumber;
	CString Strbuf;
	intnumber=Strdata.GetLength();
	Strbuf="";
	for(i=(intnumber-1);i>=0;i--)
	{
		if(Strdata.Mid(i,1)!="\\")
		{
			Strbuf=Strdata.Mid(i,1)+Strbuf;

		}
		else
		{
			break;
		}
	}
	return Strbuf;
}
CString CAccessforSTB::CreatInfoFileHead(CString StrStart,CString StrEnd)
{
	CString StrStart_Date,StrEnd_Date; 
	//////////////////////////////////
	CString StrYear,StrMonth,StrDay,StrCount;
	CString StrOutBuf;
	CString StrBuf;
	char *chrbuf;
	int intLen=0;
	int intCountYear=0;
	int intResultYear=0;
	int intYear,intMonth,intDay,intCount;
	/////////////////////////////////////
	int y1,m1,d1;
	int y2,m2,d2;
	//gStrInfoFileHead="";
	StrEnd_Date=StrEnd;
	StrStart_Date=StrStart;
	StrBuf=StrStart_Date.Mid(0,4);
	y1=_ttoi(StrBuf);
	StrBuf=StrStart_Date.Mid(4,2);
	m1=_ttoi(StrBuf);
	StrBuf=StrStart_Date.Mid(6,2);
	d1=_ttoi(StrBuf);
	StrBuf=StrEnd_Date.Mid(0,4);
	y2=_ttoi(StrBuf);
	StrBuf=StrEnd_Date.Mid(4,2);
	m2=_ttoi(StrBuf);
	StrBuf=StrEnd_Date.Mid(6,2);
	d2=_ttoi(StrBuf);
	//sscanf(StrStart_Date.GetBuffer(StrStart_Date.GetLength()),"%d-%d-%d",&y1,&m1,&d1);
	//sscanf(StrEnd_Date.GetBuffer(StrEnd_Date.GetLength()),"%d-%d-%d",&y2,&m2,&d2); 
	CTime t1(y1,m1,d1,0,0,0);//起始時間     
	CTime t2(y2,m2,d2,0,0,0);//終止時間     
	CTimeSpan ts;
	ts =t2-t1;
	//intCount=ts.GetDays()+1;//天數=終止時間-起始時間+1
	intCount=ts.GetDays();
	intYear=y1;
	intMonth=m1;
	intDay=d1;
	do
	{
		intCountYear+=1000;
		intResultYear=intYear-intCountYear;
	}
	while(intResultYear>=0);
	intCountYear-=1000;
	intYear-=intCountYear;
	//////////////////////////////
	StrYear.Format("%x",intYear);
	chrbuf=StrYear.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrYear="0"+StrYear;
	}
	///////////////////////////////
	StrMonth.Format("%x",intMonth);
	chrbuf=StrMonth.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrMonth="0"+StrMonth;
	}
	///////////////////////////
	StrDay.Format("%x",intDay);
	chrbuf=StrDay.GetBuffer(0);
	intLen=strlen(chrbuf);
	if(intLen==1)
	{
		StrDay="0"+StrDay;
	}
	///////////////////////////
	StrCount.Format("%x",intCount);
	chrbuf=StrCount.GetBuffer(0);
	intLen=strlen(chrbuf);
	while(intLen<4)
	{
		StrCount="0"+StrCount;
		chrbuf=StrCount.GetBuffer(0);
		intLen=strlen(chrbuf);
	}
	/////////////////////
	StrOutBuf=StrYear+StrMonth+StrDay+StrCount;
	return StrOutBuf;
}
