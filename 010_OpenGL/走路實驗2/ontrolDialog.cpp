// ontrolDialog.cpp : implementation file
//

#include "stdafx.h"
#include "gl.h"
#include "ontrolDialog.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ControlDialog dialog


ControlDialog::ControlDialog(CWnd* pParent /*=NULL*/)
	: CDialog(ControlDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(ControlDialog)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ControlDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ControlDialog)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ControlDialog, CDialog)
	//{{AFX_MSG_MAP(ControlDialog)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ControlDialog message handlers

