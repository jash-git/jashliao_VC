// UTextInputDlg.cpp : implementation file
//

#include "stdafx.h"
#include "UVectorFont.h"
#include "UTextInputDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CUVectorFontApp theApp;
#define U_FONT "U_FONT_SECTION"

/////////////////////////////////////////////////////////////////////////////
// CUTextInputDlg dialog


CUTextInputDlg::CUTextInputDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CUTextInputDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CUTextInputDlg)
	m_sTextEdit = _T("Ê¸Á¿ÎÄ×Ö");
	m_iFontHeight = 144;
	m_iFontSpace = 3;
	//}}AFX_DATA_INIT
    m_sFontFaceName = _T("ËÎÌå");
}


void CUTextInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CUTextInputDlg)
	DDX_Control(pDX, IDC_FONT_FACE_NAME, m_cFontFaceName);
	DDX_Text(pDX, IDC_TEXT_EDIT, m_sTextEdit);
	DDX_Text(pDX, IDC_FONT_HEIGHT, m_iFontHeight);
	DDX_Text(pDX, IDC_FONT_SPACE, m_iFontSpace);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CUTextInputDlg, CDialog)
	//{{AFX_MSG_MAP(CUTextInputDlg)
	ON_CBN_SELCHANGE(IDC_FONT_FACE_NAME, OnSelchangeFontFaceName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CUTextInputDlg message handlers

void CUTextInputDlg::OnOK() 
{
	// TODO: Add extra validation here
    UpdateData(true);
    save();	
	CDialog::OnOK();
}

void CUTextInputDlg::save()
{
    theApp.WriteProfileString(U_FONT, "sTextEdit", m_sTextEdit);
    theApp.WriteProfileString(U_FONT, "sFontFaceName", m_sFontFaceName);
    theApp.WriteProfileInt(U_FONT, "iFontHeight", m_iFontHeight);
    theApp.WriteProfileInt(U_FONT, "iFontSpace", m_iFontSpace);

}

void CUTextInputDlg::load()
{
    m_sTextEdit = theApp.GetProfileString(U_FONT, "sTextEdit", m_sTextEdit);
    m_sFontFaceName = theApp.GetProfileString(U_FONT, "sFontFaceName", m_sFontFaceName);
    m_iFontHeight = theApp.GetProfileInt(U_FONT, "iFontHeight", m_iFontHeight);
    m_iFontSpace = theApp.GetProfileInt(U_FONT, "iFontSpace", m_iFontSpace);

    CString str;
    bool bFontFaceNameFind = false;
    for (int i = 0; i < m_cFontFaceName.GetCount(); i++)
    {
        m_cFontFaceName.GetLBText(i, str);
        if (str == m_sFontFaceName)
        {    
            m_cFontFaceName.SetCurSel(i);
            bFontFaceNameFind = true;
            break;
        }
    }
    if (!bFontFaceNameFind && (m_cFontFaceName.GetCount() > 0))
    {
        m_cFontFaceName.GetLBText(0 , m_sFontFaceName);
        m_cFontFaceName.SetCurSel(0);
    }
}

BOOL CUTextInputDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    fillFontFaceName();
    load();
	UpdateData(false);
    CString fdsfd= m_sTextEdit;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CUTextInputDlg::fillFontFaceName()
{
    m_cFontFaceName.ResetContent();
    LOGFONT logfont;
    logfont.lfCharSet = ANSI_CHARSET;
    strcpy(logfont.lfFaceName,"");
    CClientDC dc (this);
    ::EnumFontFamiliesEx((HDC) dc,&logfont,
        (FONTENUMPROC)EnumFontFamProc,(LPARAM) this,0);
    //m_cFontFaceName.SetCurSel(0);
}

int CALLBACK EnumFontFamProc(LPENUMLOGFONT lpelf,LPNEWTEXTMETRIC lpntm,DWORD nFontType,long lparam)
{
	CUTextInputDlg* pWnd = (CUTextInputDlg*) lparam;
    if (nFontType==TRUETYPE_FONTTYPE )
	    pWnd->m_cFontFaceName.AddString(lpelf->elfLogFont.lfFaceName);
	return 1;
}

void CUTextInputDlg::OnSelchangeFontFaceName() 
{
    m_cFontFaceName.GetLBText(m_cFontFaceName.GetCurSel(), m_sFontFaceName);	
}
