// getwme.cpp : implementation file
//

#include "stdafx.h"
#include "playlist.h"
#include "getwme.h"
#include <atlbase.h>
#include <comdef.h>
#include "Mmsystem.h"
#include "MainFrm.h"
////////////////////////////////////////////////////////
// by jash at 2010-10-12
#import "msxml3.dll"//step 1:讀取XML
using namespace MSXML2;
#include "C:\WMSDK\WMEncSDK9\include\wmencode.h"
TCHAR gstrCurDrt[500];//存放目前目錄字串
///////////////////////////////////////////////////////
#include <afxinet.h>		//http_download
#define BUFFER_SIZE 2048//http_download
///////////////////////////////////////////////////////
#include <Shlwapi.h>//判斷檔案是否存在
extern CString StrListUrl;
extern CString StrServiceUrl;
extern CString StrServiceID;
//**********************
extern CString StrKeepLive;
extern CString StrService01;
extern CString StrService00;
extern CString StrHostDir;
extern CString StrHomePath;
extern int ginthttpport;
extern bool blnMultiDir;
///////////////////////////////////////////////////////
extern HRESULT hr;
extern IWMEncoder* pEncoder;

IWMEncSourceGroupCollection* pSrcGrpColl;
IWMEncSourceGroup*  pSrcGrp1A[400];
IWMEncSourceGroup2* pSrcGrp1B[400];
IWMEncSource* pSrcAud1[400];
IWMEncSource* pSrcVid1[400];
IWMEncProfileCollection* pProColl;
IWMEncProfile* pPro;
IWMEncBroadcast* pBrdcst;

IWMEncProfile2* pPro2;
IWMEncAudienceObj* pAudnc;


CComBSTR bstrName = NULL;
int pnum=0;
int showitem=0;
struct PLAYLIST
{
  long date;
  long time;
  long leng;
  char filename[128];

} Playlist[1024];

int Markin;
int Markout;
char Filename[128];
char Promoname[128];

struct WME
{
  char filename[128];
  int markin;
  int markout;
} Wme[2048];
int wmeitem;
int endno;


bool gblnreload;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// getwme dialog


getwme::getwme(CWnd* pParent /*=NULL*/)
	: CDialog(getwme::IDD, pParent)
{
	//{{AFX_DATA_INIT(getwme)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void getwme::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(getwme)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_EXPLORER1, m_Web);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(getwme, CDialog)
	//{{AFX_MSG_MAP(getwme)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// getwme message handlers

BOOL getwme::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	

    run();


	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void getwme::run(void)
{
	CString StrPathBuf;
	StrPathBuf=StrHomePath+"11.wmv";
	strcpy(Promoname,StrPathBuf.GetBuffer(0));
   	//strcpy(Promoname,"c:\\movies\\11.wmv");
	getlist(false);
	getwme1();
	pEncoder->Release();
	this->EndDialog(1);
}

void getwme::getlist(bool redo)
{
  _bstr_t pathFrom = "http://watchnow.nownews.com/admin/tc5tv_timelist.php?type=A";  //C US A
  CString StrPathBuf;
  StrPathBuf=StrHomePath+"list.txt";
  _bstr_t pathTo = StrPathBuf.GetBuffer(0);
  //_bstr_t pathTo = "c:\\media\\list.txt";
  /*
  hr = URLDownloadToFile( NULL,pathFrom,pathTo,0,0);
  if (hr==S_OK)  	m_list.AddString("download playlist ok !");
  */
  if(!redo)
  {
	  if(XMLList2TXTList())
	  {
		  gblnreload=false;
		  m_list.AddString("download playlist ok !");
	  }
	  else
	  {
		  m_list.AddString("load playlist error !");
		  if(!CreateDefaultList())
		  {
			return;
		  }
		  else
		  {
			  gblnreload=true;
		  }
	  }
  }
  else
  {
	  gblnreload=true;
  }
  int i,j,k,len;
   FILE *fp;
   char buffer[128],tmp[128];

   StrPathBuf=StrHomePath+"list.txt";
   fp=fopen(StrPathBuf.GetBuffer(0),"r");
   //fp=fopen("c:\\media\\list.txt","r");
  for(i=0;;i++)
  {
	 memset(buffer,0,128);
	 if (fgets(buffer,128,fp) ==NULL) break;
     //m_list.AddString(buffer); 
     len=strlen(buffer);
	 k=0;
	 memset(tmp,0,128);
     for(j=0;j<len;j++)
	 {
	   tmp[k]=buffer[j]; 
	   if (tmp[k]=='|' ) { tmp[k]=0;  strcpy((Playlist+i)->filename,tmp);  break;}
	   k++;
	 }

	 j+=2;
     k=0;
	 memset(tmp,0,128);
     for(;j<len;j++)
	 {
	   tmp[k]=buffer[j]; 
	   if (tmp[k]=='|' ) { tmp[k]=0; (Playlist+i)->leng=atol(tmp);  break;}
	   k++;
	 }

	 j+=2;
     k=0;
	 memset(tmp,0,128);
     for(;j<len;j++)
	 {
	   tmp[k]=buffer[j]; 
	   if (tmp[k]=='|' ) { tmp[k]=0; (Playlist+i)->date=atol(tmp);  break;}
	   k++;
	 }
	  j+=2;
     k=0;
	 memset(tmp,0,128);
     for(;j<len;j++)
	 {
	   tmp[k]=buffer[j]; 
	   if (tmp[k]=='|' ) { tmp[k]=0; (Playlist+i)->time=atol(tmp);  break;}
	   k++;
	 }

	   sprintf(tmp,"%2d. %d %02d:%02d %s",i,(Playlist+i)->date%100,(Playlist+i)->time/100,(Playlist+i)->time%100,(Playlist+i)->filename);
	   m_list.AddString(tmp);

  }

  fclose(fp);
    pnum=i;

    CTime tm;
	CString str;
	tm=CTime::GetCurrentTime();
	
	int hh,mm;
	long dd=tm.GetYear()*10000+tm.GetMonth()*100+tm.GetDay();
    //sprintf(tmp,"nowdate= %d ",dd);
	//m_list.AddString(tmp);
	hh=tm.GetHour()*10000+tm.GetMinute()*100+tm.GetSecond();//hh=tm.GetHour()*100+tm.GetMinute();
	for(i=0;i<pnum;i++)
	{
		if ((Playlist+i)->date != dd) {  continue;}
	    if ( (Playlist+i)->time >= hh   ) break;
	}

	showitem=i-1;
    sprintf(tmp,"Now -> %2d %02d",tm.GetHour(),tm.GetMinute());
	m_list.AddString(tmp);

    sprintf(tmp,"%d=%s %02d:%02d %d",showitem,(Playlist+showitem)->filename,(Playlist+showitem)->time/100,(Playlist+showitem)->time%100,(Playlist+showitem)->leng);
    m_list.AddString(tmp);

	int in,out;
	out=(Playlist+showitem)->leng*1000;//換算成毫秒
	 
    mm=((hh/10000)-((Playlist+showitem)->time/10000))*60;//算出小時單位的部分差幾分鐘
	mm=mm+( ((hh%10000)/100)- (((Playlist+showitem)->time%10000)/100));//算出分鐘單位的部分差幾分鐘
	mm=mm*60;//把小時和分的部分換成秒
	mm=mm+(((hh%10000)%100)-(((Playlist+showitem)->time%10000)%100));//計算出秒數的差
	mm=mm*1000;//換算成毫秒

    in=mm; 
    sprintf(tmp,"in=%d  %d",in,out);
	m_list.AddString(tmp);
       
    Markin=in;
	Markout=out;
	strcpy(Filename,(Playlist+showitem)->filename);

   wmeitem=0; 
   strcpy((Wme+wmeitem)->filename,(Playlist+showitem)->filename);
   //strcpy((Wme+wmeitem)->filename,"z:\\movies\\M01570.wmv"  );
   (Wme+wmeitem)->markin=in;
   (Wme+wmeitem)->markout=out;
   wmeitem++;
	/*
	//系統自行補上廣告
   int dif;
   len=(Playlist+showitem)->leng;
   len+=10; len=(len/10)*10;
   dif=len-(Playlist+showitem)->leng;
   in=0; out=dif*60000;
   strcpy((Wme+wmeitem)->filename,Promoname);
   (Wme+wmeitem)->markin=in;
   (Wme+wmeitem)->markout=out;
   wmeitem++;
	*/
   for(i=showitem+1;i<pnum-1;i++)
   {
    strcpy((Wme+wmeitem)->filename,(Playlist+i)->filename);
	//   strcpy((Wme+wmeitem)->filename,"z:\\movies\\M01570.wmv");
	in=0; out=(Playlist+i)->leng*1000;//out=(Playlist+i)->leng*60000;
    (Wme+wmeitem)->markin=in;
    (Wme+wmeitem)->markout=out;
	wmeitem++;
	/*
	//系統自行補上廣告
    len=(Playlist+i)->leng;
    len+=10; len=(len/10)*10;
    dif=len-(Playlist+i)->leng;
    in=0; out=dif*60000;
    strcpy((Wme+wmeitem)->filename,Promoname);
    (Wme+wmeitem)->markin=in;
    (Wme+wmeitem)->markout=out;
    wmeitem++;
	*/
   }
   
   endno=((Playlist+i)->leng+10)/10;
   endno+=2;


  //for(i=0;i<wmeitem;i++)
  //{
//	sprintf(tmp,"wme %d: %s %d %d %d",i,(Wme+i)->filename,(Wme+i)->markin,(Wme+i)->markout,endno);
//	m_list.AddString(tmp);
//  }



}

void getwme::getwme1(void)
{
   hr = CoInitialize(NULL);
    if ( SUCCEEDED( hr ) )
    {
        hr = CoCreateInstance(CLSID_WMEncoder,
            NULL,
            CLSCTX_INPROC_SERVER,
            IID_IWMEncoder,
            (void**) &pEncoder);
    }



    // Retrieve the source group collection.
    if ( SUCCEEDED( hr ) )
    {
        hr = pEncoder->get_SourceGroupCollection(&pSrcGrpColl);
    }
	m_list.AddString("Init OK !");

	// load prx file 
   if ( SUCCEEDED( hr ) )
    {
        hr = CoCreateInstance(CLSID_WMEncProfile2,
            NULL,
            CLSCTX_INPROC_SERVER,
            IID_IWMEncProfile2,
            (void**) &pPro2);
    }

    // Load the profile from a string sProString.
    CComBSTR sProString; // Replace with a valid string
    if ( SUCCEEDED( hr ) )
    {
		CString StrPathBuf;
		StrPathBuf=StrHomePath+"live.prx";
		CComBSTR bstrFileName(StrPathBuf.GetBuffer(0));
       //CComBSTR bstrFileName("c:\\media\\live.prx");
    	hr = pPro2->LoadFromFile(bstrFileName);
        
    }
   if (SUCCEEDED(hr) ) m_list.AddString("load prx ok !");



   //Add2Group(0,1,Filename);
   //Add2Group(1,0,Promoname);
   int i,j;
   CString StrMessage;
   if(wmeitem<=1)
   {
		CreateDefaultList();
		getlist(true);
		StrMessage="清單時間錯誤";
		WriteLogFile(0,StrMessage);
		EmailError(StrMessage);
   }
   for(i=0;i<wmeitem;i++)
   {
     Add2Group(i,i+1,(Wme+i)->filename,(Wme+i)->markin,(Wme+i)->markout);
   }
   /*
   //系統自行補上廣告
   j=i;
   for(i=0;i<endno;i++)
   {
     
     if (i==endno-1) Add2Group(j,0,Promoname,0,0);
	 else      Add2Group(j,j+1,Promoname,0,0);
	 j++;
   }
   */


	 // Create an IWMEncBroadcast object and specify a port and a protocol.
    if ( SUCCEEDED( hr ) )
    {
        hr = pEncoder->get_Broadcast(&pBrdcst);
    }
    if ( SUCCEEDED( hr ) )
    {
		hr = pBrdcst->put_PortNumber(WMENC_PROTOCOL_HTTP, ginthttpport);
        //hr = pBrdcst->put_PortNumber(WMENC_PROTOCOL_HTTP, 8080);
    }


    m_list.AddString("Save live.wme to HomePath");
	//m_list.AddString("Save live.wme to c:\\media\\");
	CString StrPathBuf;
	StrPathBuf=StrHomePath+"live.wme";
	pEncoder->Save(CComBSTR(StrPathBuf.GetBuffer(0)));
   	//pEncoder->Save(CComBSTR("c:\\media\\live.wme"));
}

void getwme::Add2Group(int num,int next,char *filename,int in,int out)
{
   char gname[32];

   sprintf(gname,"SG_%d",num);
   

	// Add a source group named SG1 to the collection.
    
    if ( SUCCEEDED( hr ) )
    {
        hr = pSrcGrpColl->Add(CComBSTR(gname), &pSrcGrp1A[num]);
    }




    // Retrieve a pointer to an IWMEncSourceGroup2 interface.
    if ( SUCCEEDED( hr ) )
    {
        hr = pSrcGrp1A[num]->QueryInterface(IID_IWMEncSourceGroup2, (void**)&pSrcGrp1B[num]);
    }

    // Create a source object for each type of content in the source group.
    if ( SUCCEEDED( hr ) )
    {
        hr = pSrcGrp1B[num]->AddSource(WMENC_AUDIO, &pSrcAud1[num]);
		
    }
    if ( SUCCEEDED( hr ) )
    {
        hr = pSrcGrp1B[num]->AddSource(WMENC_VIDEO, &pSrcVid1[num]);
		       
    }
 // Specify the input for the sources in the first source group.

       if (out > 0)
	   {
       pSrcAud1[num]->put_MarkIn(in);
       pSrcVid1[num]->put_MarkIn(in);
	   pSrcAud1[num]->put_MarkOut(out);
       pSrcVid1[num]->put_MarkOut(out);
	   }

    // For this example, source group 1 uses file sources.
	 

    if ( SUCCEEDED( hr ) )
    {
        hr = pSrcAud1[num]->SetInput(CComBSTR(filename));
    }
    if ( SUCCEEDED( hr ) )
    {
        hr = pSrcVid1[num]->SetInput(CComBSTR(filename));
    }



    // Specify this profile object as the profile to use in source group 1.
    if ( SUCCEEDED( hr ) )
    {
		//pPro->put_MaxPacketSize(300000);
        //hr = pSrcGrp1B[num]->put_Profile(CComVariant(pPro));
		hr = pSrcGrp1B[num]->put_Profile(CComVariant(pPro2));
    }



   sprintf(gname,"SG_%d",next);   
   if ( SUCCEEDED( hr ) )
    {
        hr = pSrcGrp1B[num]->SetAutoRollover(-1, CComBSTR(gname));
    }


}
bool getwme::XMLList2TXTList()//step 4:讀取XML
{
	FILE *pf=NULL;
	MSXML2::IXMLDOMDocumentPtr pDoc;
	int i,j;
	int k,l;
	CString StrData;
	_variant_t vtStr;
	bool blnRead=false;
	CString StrMessage;
	StrMessage="";
	///////////////////////////////////////////////////////////
	CTime t1;
	t1=CTime::GetCurrentTime();
	int inthr,intmin,intsec;//新增intsec 為了清單起始時間從0時改成4時 而且單位為時分秒 by jash 20120725
	inthr=0;
	intmin=0;
	CString StrtimeData01,StrtimeData02;
	CString StrHr,StrMin,StrSec;//新增StrSec 為了清單起始時間從0時改成4時 而且單位為時分秒 by jash 20120725
	CString StrDate;
	CString StrTime;
	long lngDate;
	long lngTime;
	long lngtimeData01;
	long lngtimeData02; 
	StrtimeData01=t1.Format("%Y%m%d");
	inthr=t1.GetHour();
	intmin=t1.GetMinute();
	intsec=t1.GetSecond();
	if(inthr<10)
	{
		StrHr.Format("0%d",inthr);
	}
	else
	{
		StrHr.Format("%d",inthr);
	}
	if(intmin<10)
	{
		StrMin.Format("0%d",intmin);
	}
	else
	{
		StrMin.Format("%d",intmin);
	}
	if(intsec<10)//為了清單起始時間從0時改成4時 而且單位為時分秒 by jash 20120725
	{
		StrSec.Format("0%d",intsec);
	}
	else
	{
		StrSec.Format("%d",intsec);
	}
	StrtimeData02=StrHr+StrMin+StrSec;
	lngtimeData01=atol(StrtimeData01.GetBuffer(0));
	lngtimeData02=atol(StrtimeData02.GetBuffer(0));
	///////////////////////////////////////////
	if(DownLoadList())
	{
		StrMessage="清單下載完成";
		WriteLogFile(1,StrMessage);
	}
	else
	{
		StrMessage="清單下載失敗";
		WriteLogFile(0,StrMessage);
		EmailError(StrMessage);
		return false;
	}
	::CoInitialize(NULL); //step 2:讀取XML
	HRESULT hr = pDoc.CreateInstance(__uuidof(MSXML2::DOMDocument30));
	if(!SUCCEEDED(hr))
	{
	   StrMessage="建立讀取清單物件失敗";
	   WriteLogFile(0,StrMessage);
	   EmailError(StrMessage);
	   return false;
	}
	int nLen = ::GetCurrentDirectory(500,gstrCurDrt);//取得目前程式路徑
	if( gstrCurDrt[nLen]!='\\' )
	{
		gstrCurDrt[nLen++] = '\\';
		gstrCurDrt[nLen] = '\0';
	}
	CString strFileName1 = gstrCurDrt;
	strFileName1 +="list.xml";
	try//防止清單檔案根本沒有任何字元
	{
		blnRead=pDoc->load((_bstr_t)strFileName1);
	}
	catch(...)
	{
		StrMessage="讀取清單失敗";
		WriteLogFile(0,StrMessage);
		EmailError(StrMessage);
		if(pf!=NULL)
		{
			fclose(pf);
		}
		return false;
	}
	if(blnRead)//第11.0版的功能
	{
		pf=fopen("list.txt","w");
		UpdateData(true);
		MSXML2::IXMLDOMNodeListPtr  pNodeList;
		MSXML2::IXMLDOMNodePtr pNodeRoot;
		pNodeRoot=pDoc->selectSingleNode("//list");
		pNodeRoot->get_childNodes(&pNodeList);
		j=pNodeList->length;
		if(j<=0)
		{
			StrMessage="讀取清單失敗";
			WriteLogFile(0,StrMessage);
			EmailError(StrMessage);
			if(pf!=NULL)
			{
				fclose(pf);
			}
			return false;
		}
		if(j>400)//400筆防呆  by jash 20120730
		{
			StrMessage="清單筆數 > 400筆，導致wme無法負荷，所以切換至防呆模式";
			WriteLogFile(0,StrMessage);
			EmailError(StrMessage);
			if(pf!=NULL)
			{
				fclose(pf);
			}
			return false;
		}
		for(i=0;i<j;i++)
		{
			k=0;
			l=0;
			StrData="";
			CString StrBuff,StrFileName,StrMediaLen,StrGetMediaLen;
			int intMediaLen,intGetMediaLen;
			MSXML2::IXMLDOMNodePtr pRootchildNode;
			MSXML2::IXMLDOMNodeListPtr pchildNodeList;
			pRootchildNode=pNodeList->item[i];
			pRootchildNode->get_childNodes(&pchildNodeList);
			l=pchildNodeList->length;
			if(l<=3)
			{
				StrMessage="讀取清單失敗";
				WriteLogFile(0,StrMessage);
				EmailError(StrMessage);
				if(pf!=NULL)
				{
					fclose(pf);
				}
				return false;
			}
			for(k=0;k<l;k++)
			{
				MSXML2::IXMLDOMNodePtr pchildNode;
				////////////////////////////////////////////////////////
				pchildNode=pchildNodeList->item[k];
				pchildNode->get_nodeTypedValue(&vtStr);
				StrBuff=vtStr.bstrVal;
				StrBuff.MakeLower();//防呆一律轉小寫
				////////////////////////////////////////////////////////
				switch(k)
				{
				case 0:
					if(blnMultiDir==false)
					{
						StrBuff=StrHostDir+StrBuff;//固定單一網路磁碟機
					}
					else
					{
						StrBuff.Replace("5tv-m1","I:");
						StrBuff.Replace("5tv-m2","J:");
						StrBuff.Replace("5tv-m3","K:");
						StrBuff.Replace("5tv-m4","L:");
						StrBuff.Replace("mms1","I:");
						StrBuff.Replace("mms2","J:");
						StrBuff.Replace("mms3","K:");
						StrBuff.Replace("mms4","L:");
						StrBuff.Replace("C:\\",StrHomePath);
						StrBuff.Replace("c:\\",StrHomePath);
					}
					StrBuff.Replace("/","\\");
					StrFileName=StrBuff;
					break;
				case 1:
					StrMediaLen=StrBuff;
					break;
				case 2:
					StrDate=StrBuff;
					lngDate=atol(StrDate.GetBuffer(0));
					break;
				case 3:
					StrTime=StrBuff;
					lngTime=atol(StrTime.GetBuffer(0));;
					break;
				}
				//*********************************************
				StrData+=StrBuff;
				StrData+=" || ";
			}
			if(i==0)
			{
				if(!((lngDate<=lngtimeData01) && (lngTime<=lngtimeData02)))
				{
					StrMessage="清單時間錯誤";
					WriteLogFile(0,StrMessage);
					if(pf!=NULL)
					{
						fclose(pf);
					}
					EmailError(StrMessage);
					return false;
				}
			}
			
			CFileStatus rStatus;
			if(CFile::GetStatus(StrFileName, rStatus))
			//if(::PathFileExists(StrFileName.GetBuffer(0)))
			{
				StrMessage=StrFileName;
				StrMessage+="檔案存在";
				WriteLogFile(1,StrMessage);				
			}
			else
			{
				StrMessage=StrFileName;
				StrMessage+="檔案偵測失敗";
				WriteLogFile(0,StrMessage);
				if(pf!=NULL)
				{
					fclose(pf);
				}
				EmailError(StrMessage);
				return false;
			}
			StrGetMediaLen=GetMediaLen(StrFileName);
			intMediaLen=atoi(StrMediaLen.GetBuffer(0));
			intGetMediaLen=atoi(StrGetMediaLen.GetBuffer(0));

			if(intMediaLen<=intGetMediaLen)
			{
				StrData=StrData.Mid(0,(StrData.GetLength()-1));
				fprintf(pf,"%s\n",StrData.GetBuffer(0));
				StrMessage=StrFileName;
				StrMessage+="影片長度正確";
				WriteLogFile(1,StrMessage);	
			}
			else
			{
				int intsubMediaLen;
				intsubMediaLen=intMediaLen-intGetMediaLen;//相差秒數
				StrData.Format("%s || %d || %s || %s||",StrFileName.GetBuffer(0),intGetMediaLen,StrDate.GetBuffer(0),StrTime.GetBuffer(0));
				fprintf(pf,"%s\n",StrData.GetBuffer(0));
				if(intsubMediaLen<60)
				{
					CString StrFileBuf;
					int year = lngDate/10000;
					int month = (lngDate-(year*10000))/100;
					int date = (lngDate-(year*10000))%100;
					int hour = lngTime/10000;
					int minute = (lngTime-(hour*10000))/100;
					int second = (lngTime-(hour*10000))%100;
					CTime tm01(year,month,date,hour,minute,second);//這意以有問提的時間
					CTimeSpan ts_day(0,0,0,intGetMediaLen); // 日 時 分 秒
					CTime tm02=tm01+ts_day;
					//StrData.Format("C:\\Base.wmv || %d || %04d%02d%02d || %02d%02d%02d ||",intsubMediaLen,tm02.GetYear(),tm02.GetMonth(),tm02.GetDay(),tm02.GetHour(),tm02.GetMinute(),tm02.GetSecond());
					StrFileBuf=StrHomePath+"Base.wmv";
					StrData.Format("%s || %d || %04d%02d%02d || %02d%02d%02d ||",StrFileBuf.GetBuffer(0),intsubMediaLen,tm02.GetYear(),tm02.GetMonth(),tm02.GetDay(),tm02.GetHour(),tm02.GetMinute(),tm02.GetSecond());
					fprintf(pf,"%s\n",StrData.GetBuffer(0));

					//*****************************************
					StrMessage=StrFileName;
					StrMessage+="影片長度錯誤";
					WriteLogFile(0,StrMessage);
					EmailError(StrMessage);
				}
				else
				{
					StrMessage=StrFileName;
					StrMessage+="影片長度錯誤，並且超過60秒";
					WriteLogFile(0,StrMessage);
					if(pf!=NULL)
					{
						fclose(pf);
					}
					EmailError(StrMessage);
					return false;
				}
			}
		}
		StrData="@ || 30 || 30001231 || 0000 || ";
		StrData=StrData.Mid(0,(StrData.GetLength()-1));
		fprintf(pf,"%s",StrData.GetBuffer(0));
	}
	if(pf!=NULL)
	{
		StrMessage="讀取清單完成";
		WriteLogFile(1,StrMessage);
		if(pf!=NULL)
		{
			fclose(pf);
		}
		return true;
	}
	else
	{
		StrMessage="讀取清單失敗";
		WriteLogFile(0,StrMessage);
		EmailError(StrMessage);
		return false;
	}
}
bool getwme::DownLoadList()
{
	DeleteFile("live.wme");
	DeleteFile("list.xml");
	DeleteFile("list.txt");
	bool blnGetFile; 
	CString theUrl=StrListUrl;
	CString Filename="list.xml";
	blnGetFile=GetWebFile(theUrl,Filename);//for .net & PHP
	return blnGetFile;
	
}

bool getwme::GetWebFile(CString theUrl, CString Filename)//http_download
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
void getwme::WriteLogFile(int intindex,CString StrMessage)
{
	FILE *pf=NULL;
	CTime TimeNow;
	CString StrWriteMessage;
	TimeNow=CTime::GetCurrentTime();
	StrWriteMessage=TimeNow.Format("%Y-%m-%d %H:%M:%S ::");
	StrWriteMessage+=StrMessage;
	if(intindex==0)
	{
		//Errlog
		pf=fopen("Errlog.txt","a");
	}
	else
	{
		//Meslog
		pf=fopen("Meslog.txt","a");
	}
	if(pf!=NULL);
	{
		fprintf(pf,"%s\n",StrWriteMessage.GetBuffer(0));
		fclose(pf);
	}
}
CString getwme::GetMediaLen(CString StrSouFileName)
{
	char chrLen[128];
	int i=0;
	long re=-1;
	CString MediaLen;
	CString StrFileName="open ";
	StrFileName+=StrSouFileName;
	StrFileName+=" type MPEGVideo alias Media";
	re=mciSendString(StrFileName.GetBuffer(0),"",0,0);
	re=mciSendString("status Media length", chrLen, 128, 0);
	//i=atoi(chrLen)/1000/60;//分
	i=atoi(chrLen)/1000;//秒
	MediaLen.Format("%d",i);
	re=mciSendString("close Media","",0,0);
	return MediaLen;
}
bool getwme::CreateDefaultList()
{
	CTime t1;
	t1=CTime::GetCurrentTime();
	int inthr,intmin;
	inthr=0;
	intmin=0;
	CString StrData,StrDataBuf;
	CString StrHr,StrMin;
	FILE *pf=NULL;
	pf=fopen("list.txt","w");
	if(pf==NULL)
	{
		return false;
	}
	do
	{
		//StrData="C:\\Base.wmv || 1800 || ";
		StrData=StrHomePath+"Base.wmv || 1800 || ";
		StrDataBuf=t1.Format("%Y%m%d || ");
		if(inthr<10)
		{
			StrHr.Format("0%d",inthr);
		}
		else
		{
			StrHr.Format("%d",inthr);
		}
		if(intmin<10)
		{
			StrMin.Format("0%d",intmin);
		}
		else
		{
			StrMin.Format("%d",intmin);
		}
		StrData=StrData+StrDataBuf;
		StrData=StrData+StrHr+StrMin;
		StrData=StrData+"00";
		StrData=StrData+" ||";
		fprintf(pf,"%s\n",StrData.GetBuffer(0));
		intmin+=30;
		if( intmin>=60)
		{
			inthr++;
			intmin=0;
		}
	}while(inthr<24);
	StrData="@ || 1800 || 30001231 || 0000 || ";
	StrData=StrData.Mid(0,(StrData.GetLength()-1));
	fprintf(pf,"%s",StrData.GetBuffer(0));
	if(pf!=NULL)
	{
		fclose(pf);
		return true;
	}
}
void getwme::EmailError(CString StrWriteMessage)
{
	FILE *pfError;
	pfError=NULL;
	pfError=fopen("ErrorInfo.txt","w");
	if(pfError!=NULL)
	{
		fprintf(pfError,"%s\t%s",StrListUrl.GetBuffer(0),StrWriteMessage.GetBuffer(0));
		fclose(pfError);
	}
	ShellExecute(NULL,"open","MyEmailClient.exe",NULL,NULL,SW_SHOWNORMAL); 
	COleVariant vaUrl=StrService01;;
	COleVariant vtMissing;
	m_Web.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
}
BOOL getwme::SearchFile(CString StrFileName)
{
	CFileFind ff;	
	BOOL res = ff.FindFile(StrFileName);
	ff.Close();//壽敕
	return res;
}