// PPDlg.cpp : implementation file
//

#include "stdafx.h"
#include "V.h"
#include "PPDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
   
/////////////////////////////////////////////////////////////////////////////
// CPPDlg dialog


CPPDlg::CPPDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPPDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPPDlg)
	//}}AFX_DATA_INIT
}


void CPPDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPPDlg)
	DDX_Control(pDX, IDC_STATICICON, m_icon);
	DDX_Control(pDX, IDC_SLIDER1, m_sld);
	DDX_Control(pDX, IDC_PROGRESS1, m_p);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPPDlg, CDialog)
	//{{AFX_MSG_MAP(CPPDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()




BOOL CPPDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,WS_EX_TOOLWINDOW); 

/*	SetWindowLong(GetSafeHwnd(),GWL_EXSTYLE,GetWindowLong(GetSafeHwnd(),GWL_EXSTYLE)^0x80000);           
	HINSTANCE hInst = LoadLibrary("User32.DLL");            
	if(hInst) 
	{ 
		typedef  BOOL  (WINAPI  *MYFUNC)(HWND, COLORREF, BYTE, DWORD); 
		MYFUNC fun = NULL;
		fun=(MYFUNC)GetProcAddress(hInst, "SetLayeredWindowAttributes");
		if(fun)
			fun(GetSafeHwnd(),0,222,2);   //第三个参数设置透明度
		FreeLibrary(hInst); 
		
	}
*/	
	return TRUE;  
	

}



