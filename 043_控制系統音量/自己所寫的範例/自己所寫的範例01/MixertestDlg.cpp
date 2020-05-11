// MixertestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Mixertest.h"
#include "MixertestDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	/////setp2-start

	/////setp2-end
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMixertestDlg dialog

CMixertestDlg::CMixertestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMixertestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMixertestDlg)
	m_v1 = 0;
	m_v2 = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMixertestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMixertestDlg)
	DDX_Text(pDX, IDC_EDIT1, m_v1);
	DDX_Text(pDX, IDC_EDIT2, m_v2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMixertestDlg, CDialog)
	//{{AFX_MSG_MAP(CMixertestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMixertestDlg message handlers

BOOL CMixertestDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMixertestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMixertestDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMixertestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
void CMixertestDlg::SetVolume( const DWORD dwVolume )
{
    MMRESULT                        result;
    HMIXER                          hMixer;
    MIXERLINE                       ml   = {0};
    MIXERLINECONTROLS               mlc  = {0};
    MIXERCONTROL                    mc   = {0};
    MIXERCONTROLDETAILS             mcd  = {0};
    MIXERCONTROLDETAILS_UNSIGNED    mcdu = {0};


    // get a handle to the mixer device
    result = mixerOpen(&hMixer, MIXER_OBJECTF_MIXER, 0, 0, 0);
    if (MMSYSERR_NOERROR == result)
    {
        ml.cbStruct        = sizeof(MIXERLINE);
        ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;

        // get the speaker line of the mixer device
        result = mixerGetLineInfo((HMIXEROBJ) hMixer, &ml, MIXER_GETLINEINFOF_COMPONENTTYPE);
        if (MMSYSERR_NOERROR == result)
        {
            mlc.cbStruct      = sizeof(MIXERLINECONTROLS);
            mlc.dwLineID      = ml.dwLineID;
            mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
            mlc.cControls     = 1;
            mlc.pamxctrl      = &mc;
            mlc.cbmxctrl      = sizeof(MIXERCONTROL);

            // get the volume controls associated with the speaker line
            result = mixerGetLineControls((HMIXEROBJ) hMixer, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
            if (MMSYSERR_NOERROR == result)
            {
                mcdu.dwValue    = dwVolume;

                mcd.cbStruct    = sizeof(MIXERCONTROLDETAILS);
                mcd.hwndOwner   = 0;
                mcd.dwControlID = mc.dwControlID;
                mcd.paDetails   = &mcdu;
                mcd.cbDetails   = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
                mcd.cChannels   = 1;

                // set the volume
                result = mixerSetControlDetails((HMIXEROBJ) hMixer, &mcd, MIXER_SETCONTROLDETAILSF_VALUE);
                if (MMSYSERR_NOERROR == result)
                    AfxMessageBox("Volume changed!");
                else
                    AfxMessageBox("mixerSetControlDetails() failed");
            }
            else
                AfxMessageBox("mixerGetLineControls() failed");
        }
        else
            AfxMessageBox("mixerGetLineInfo() failed");
    
        mixerClose(hMixer);
    }
    else
        AfxMessageBox("mixerOpen() failed");
}

//====================================================================

DWORD CMixertestDlg::GetVolume( void )
{
    DWORD                           dwVolume = -1;
    MMRESULT                        result;
    HMIXER                          hMixer;
    MIXERLINE                       ml   = {0};
    MIXERLINECONTROLS               mlc  = {0};
    MIXERCONTROL                    mc   = {0};
    MIXERCONTROLDETAILS             mcd  = {0};
    MIXERCONTROLDETAILS_UNSIGNED    mcdu = {0};


    // get a handle to the mixer device
    result = mixerOpen(&hMixer, 0, 0, 0, MIXER_OBJECTF_HMIXER);
    if (MMSYSERR_NOERROR == result)
    {
        ml.cbStruct        = sizeof(MIXERLINE);
        ml.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;

        // get the speaker line of the mixer device
        result = mixerGetLineInfo((HMIXEROBJ) hMixer, &ml, MIXER_GETLINEINFOF_COMPONENTTYPE);
        if (MMSYSERR_NOERROR == result)
        {
            mlc.cbStruct      = sizeof(MIXERLINECONTROLS);
            mlc.dwLineID      = ml.dwLineID;
            mlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
            mlc.cControls     = 1;
            mlc.pamxctrl      = &mc;
            mlc.cbmxctrl      = sizeof(MIXERCONTROL);

            // get the volume controls associated with the speaker line
            result = mixerGetLineControls((HMIXEROBJ) hMixer, &mlc, MIXER_GETLINECONTROLSF_ONEBYTYPE);
            if (MMSYSERR_NOERROR == result)
            {
                mcd.cbStruct    = sizeof(MIXERCONTROLDETAILS);
                mcd.hwndOwner   = 0;
                mcd.dwControlID = mc.dwControlID;
                mcd.paDetails   = &mcdu;
                mcd.cbDetails   = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
                mcd.cChannels   = 1;

                // get the volume
                result = mixerGetControlDetails((HMIXEROBJ) hMixer, &mcd, MIXER_SETCONTROLDETAILSF_VALUE);
                if (MMSYSERR_NOERROR == result)
                    dwVolume = mcdu.dwValue;
                else
                    AfxMessageBox("mixerGetControlDetails() failed");
            }
            else
                AfxMessageBox("mixerGetLineControls() failed");
        }
        else
            AfxMessageBox("mixerGetLineInfo() failed");
    
        mixerClose(hMixer);
    }
    else
        AfxMessageBox("mixerOpen() failed");

    return (dwVolume);
}

void CMixertestDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
		m_v1=GetVolume();
	UpdateData(false);
}

void CMixertestDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	int data;
	UpdateData(true);
		data=65535*m_v2/100;
		SetVolume(data);
	UpdateData(false);	
}
