// ShowImageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShowHospital.h"
#include "ShowImageDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
TCHAR strCurDrt[500];
long glngCount;
/////////////////////////////////////////////////////////////////////////////
// CShowImageDlg dialog


CShowImageDlg::CShowImageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShowImageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowImageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CShowImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowImageDlg)
	DDX_Control(pDX, IDC_EXPLORER1, m_WebControl);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowImageDlg, CDialog)
	//{{AFX_MSG_MAP(CShowImageDlg)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowImageDlg message handlers
void CShowImageDlg::BrowseDir(CString strDir,CString strtype)//Step 1:列出檔案清單
{
	CFileFind ff;
	CString szDir = strDir;
	
	if(szDir.Right(1) != "\\")
		szDir += "\\";
	
	szDir += strtype;
	
	BOOL res = ff.FindFile(szDir);
	while(res)
	{
		res = ff.FindNextFile();
		if(ff.IsDirectory() && !ff.IsDots())
		{
			BrowseDir(ff.GetFilePath(),strtype);
		}
		else if(!ff.IsDirectory() && !ff.IsDots())
		{
			//m_Array.Add(ff.GetFilePath());
			m_Array.Add(ff.GetFileName()); 
		}
	}
	ff.Close();
}

BOOL CShowImageDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	int nLen = ::GetCurrentDirectory(500,strCurDrt);
	if( strCurDrt[nLen]!='\\' )
	{
		strCurDrt[nLen++] = '\\';
		strCurDrt[nLen] = '\0';
	}
	CString strFileName = strCurDrt;
	CString StrDir;
	StrDir=strFileName+"Resources\\web";
	CString Strtype;
	Strtype="*.jpg";
	BrowseDir(StrDir,Strtype);
	Strtype="*.gif";
	BrowseDir(StrDir,Strtype);
	strFileName+="Resources\\web\\show.html";
	//****************************************************
	FILE *pfhtml;
	CString StrDataBuf;
	int i,j;
	pfhtml=fopen(strFileName.GetBuffer(0),"w");
	//
	StrDataBuf="<HTML><HEAD><META CONTENT=\"text/html; charset=big5\" HTTP-EQUIV=\"Content-Type\"></HEAD><title>中華聯合多頻道</title>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="<SCRIPT language=JavaScript>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	//StrDataBuf="var slideShowSpeed = 6000;";
	StrDataBuf.Format("var slideShowSpeed = %d;",(m_lngChangeImage*1000));
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="var Pic = new Array();";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	j=m_Array.GetSize(); 
	for(i=0;i<j;i++)
	{
		StrDataBuf.Format("Pic[%d] = '",i); 
		StrDataBuf+=m_Array.GetAt(i);
		StrDataBuf+="'";
		fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	}
	//
	StrDataBuf="var t;var j = 0;var p = Pic.length;var preLoad = new Array();var crossFadeDuration = 3";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="for (i = 0; i < p; i++) {preLoad[i] = new Image();preLoad[i].src = Pic[i];}";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="function runSlideShow() {if (document.all) {document.images.SlideShow.style.filter=\"blendTrans(duration=2)\";document.images.SlideShow.style.filter=\"blendTrans(duration=crossFadeDuration)\";document.images.SlideShow.filters.blendTrans.Apply();}document.images.SlideShow.src = preLoad[j].src;if (document.all) {document.images.SlideShow.filters.blendTrans.Play();}j = j + 1;if (j > (p - 1)) j = 0;t = setTimeout('runSlideShow()', slideShowSpeed);}";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="</SCRIPT>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	//
	StrDataBuf="<BODY onload=runSlideShow() TOPMARGIN=\"0\" LEFTMARGIN=\"0\" MARGINWIDTH=\"0\" MARGINHEIGHT=\"0\" scroll=\"no\" onload=runSlideShow()><TABLE BORDER=\"0\" CELLPADDING=\"0\" CELLSPACING=\"0\"><TR><TD><IMG src=\"Images/CHTV_01.jpg\" border=0 name=SlideShow></TD></TR></TABLE></BODY></HTML>";
	fprintf(pfhtml,"%s\n",StrDataBuf.GetBuffer(0));
	fclose(pfhtml);
	//****************************************************
	COleVariant vaUrl=strFileName;
	COleVariant vtMissing;
	m_WebControl.Navigate2(&vaUrl,&vtMissing,&vtMissing,&vtMissing,&vtMissing); 
	//***************************************************************************
	CRect rect;
	CRgn m_rgn;//裁減(切)視窗相關物件
	::SetWindowPos(this->m_hWnd,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE);
	this->MoveWindow((m_lngLeft-5),(m_lngTop-29),(m_lngWidth+12),(m_lngHeight+34),TRUE);
	this->GetClientRect(rect);
	m_rgn.CreateRectRgn(5,29,rect.Width(),(rect.Height()+25));
	::SetWindowRgn(GetSafeHwnd(),(HRGN)m_rgn,TRUE);
	//*****************************************************************************************
	RECT rc;
	this->GetClientRect(&rc);
	m_WebControl.MoveWindow( &rc, true );
	//******************************************
	glngCount=0;
	SetTimer(1,1000,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShowImageDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	glngCount++;
	if(glngCount>m_lngShowImageTime)
		this->OnOK(); 
	CDialog::OnTimer(nIDEvent);
}
