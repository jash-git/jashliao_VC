// gl1.cpp : implementation file
//

#include "stdafx.h"
#include "gl.h"
#include "gl1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// gl dialog


gl::gl(CWnd* pParent /*=NULL*/)
	: CDialog(gl::IDD, pParent)
{
	//{{AFX_DATA_INIT(gl)
	m_waist_x = 0.0f;
	m_waist_y = 0.0f;
	m_waist_z = 0.0f;
	m_left1 = 0.0f;
	m_left2 = 0.0f;
	m_left3 = 0.0f;
	m_right1 = 0.0f;
	m_right2 = 0.0f;
	m_right3 = 0.0f;
	//}}AFX_DATA_INIT
}


void gl::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(gl)
	DDX_Text(pDX, IDC_waist_x, m_waist_x);
	DDX_Text(pDX, IDC_waist_y, m_waist_y);
	DDX_Text(pDX, IDC_waist_z, m_waist_z);
	DDX_Text(pDX, left1, m_left1);
	DDX_Text(pDX, left2, m_left2);
	DDX_Text(pDX, left3, m_left3);
	DDX_Text(pDX, right1, m_right1);
	DDX_Text(pDX, right2, m_right2);
	DDX_Text(pDX, right3, m_right3);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(gl, CDialog)
	//{{AFX_MSG_MAP(gl)
	ON_EN_CHANGE(IDC_EDIT1, waist_x)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// gl message handlers

void gl::waist_x() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	
}
