// TestXMLiteDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestXMLite.h"
#include "TestXMLiteDlg.h"
#include "XMLite.h"

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
// CTestXMLiteDlg dialog

CTestXMLiteDlg::CTestXMLiteDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestXMLiteDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestXMLiteDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestXMLiteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestXMLiteDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestXMLiteDlg, CDialog)
	//{{AFX_MSG_MAP(CTestXMLiteDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestXMLiteDlg message handlers

BOOL CTestXMLiteDlg::OnInitDialog()
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

void CTestXMLiteDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestXMLiteDlg::OnPaint() 
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
HCURSOR CTestXMLiteDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//Test. 1: Simple Plane XML Parse
void CTestXMLiteDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<AddressBook description=\"book of bro\">\
<Person type='me'><Name>Cho,Kyung Min</Name><Nick>bro</Nick></Person>\
<Person type='friend'><Name>Baik,Ji Hoon</Name><Nick>bjh</Nick></Person>\
<Person type=friend><Name>Bak,Gun Joo</Name><Nick>dichter</Nick></Person>\
<Information count='3'/>\
</AddressBook>");
	
	XNode xml;
	if( xml.Load( sxml ) )
		AfxMessageBox(xml.GetXML());
	else
		AfxMessageBox(_T("error"));
	/*
	CString data;
	data=xml.GetChildAttrValue("Person","type");
	MessageBox(data);//OK
	*/
	/*
	CString data;
	data.Format("%d", xml.GetChildCount());      
	MessageBox(data);//OK
	*/
}

//Test. 2: Get Child Elements, Attributes
void CTestXMLiteDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<AddressBook description=\"book of bro\">\
<Person type='me'><Name>Cho,Kyung Min</Name><Nick>bro</Nick></Person>\
<Person type='friend'><Name>Baik,Ji Hoon</Name><Nick>bjh</Nick></Person>\
<Person type=friend><Name>Bak,Gun Joo</Name><Nick>dichter</Nick></Person>\
<Information count='3'/>\
</AddressBook>");
	
	XNode xml;
	if( xml.Load( sxml ) == NULL )
	{
		AfxMessageBox(_T("error"));
		return;
	}
	
	int i;
	XNodes childs;

	// DOM tree Childs Traveling 
	// method 1: Using GetChildCount() and GetChild()
	// Result: Person, Person, Person, Information
	LPXNode child;
	for( i = 0 ; i < xml.GetChildCount(); i++)
	{
		child = xml.GetChild(i);
		AfxMessageBox( child->GetXML() );
	}

	// method 2: LPXNodes and GetChilds() ( same result with method 1 )
	// Result: Person, Person, Person, Information
	childs = xml.GetChilds();
	for( i = 0 ; i < childs.size(); i++)
		AfxMessageBox( childs[i]->GetXML() );

	// method 3: Selected Childs with GetChilds()
	// Result: Person, Person, Person
	childs = xml.GetChilds(_T("Person") );
	for( i = 0 ; i < childs.size(); i++)
	{
		AfxMessageBox( childs[i]->GetXML() );
	}

	// method 4: Get Attribute Vaule of Child
	// Result: 3
	AfxMessageBox( xml.GetChildAttrValue( _T("Information"), _T("count") ) );
	int count = XStr2Int( xml.GetChildAttrValue( _T("Information"), _T("count") ));
	ASSERT( count == 3 );
}

//Test. 3: DOM Modify
void CTestXMLiteDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<AddressBook description=\"book of bro\">\
<Person type='me'><Name>Cho,Kyung Min</Name><Nick>bro</Nick></Person>\
<Person type='friend'><Name>Baik,Ji Hoon</Name><Nick>bjh</Nick></Person>\
<Person type=friend><Name>Bak,Gun Joo</Name><Nick>dichter</Nick></Person>\
<Information count='3'/>\
</AddressBook>");
	
	XNode xml;
	xml.Load( sxml );

	// remove 'bro node'
	LPXNode child_bro = xml.GetChild(0);
	xml.RemoveChild( child_bro );

	AfxMessageBox(xml.GetXML());
}

//Test. 4: Error Handling
void CTestXMLiteDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	CString serror_xml;
	serror_xml = _T("<XML>\
<NoCloseTag type='me'><Name>Cho,Kyung Min</Name><Nick>bro</Nick>\
</XML>");
	
	XNode xml;
	PARSEINFO pi;
	if( xml.Load( serror_xml, &pi ) == NULL )
		AfxMessageBox(_T("error") );

	if( pi.erorr_occur ) // is error_occur?
	{
		//result: '<NoCloseTag> ... </XML>' is not wel-formed.
		AfxMessageBox( pi.error_string );
		AfxMessageBox( xml.GetXML()  );
	}
	else
		ASSERT(FALSE);
}

//Test. 5: Entity and Escape Char Test
void CTestXMLiteDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<XML>\
<TAG attr='<\\'asdf\\\">'>asdf</TAG>\
</XML>");
	
	XNode xml;
	PARSEINFO pi;
	pi.escape_value = '\\';
	xml.Load( sxml, &pi );

	AfxMessageBox( xml.GetXML()  );
}

//Test. 6: Configurate Parse and Display
void CTestXMLiteDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<XML>\
<TAG attr='   qwer      '>        asdf       </TAG>\
</XML>");
	
	XNode xml;
	
	xml.Load( sxml );
	AfxMessageBox( xml.GetXML()  );

	PARSEINFO pi;
	pi.trim_value = true; // trim value
	xml.Load( sxml, &pi );
	AfxMessageBox( xml.GetXML()  );

	DISP_OPT opt;
	opt.newline = false; // no new line
	
	AfxMessageBox( xml.GetXML( &opt )  );	
}

//Test. 6: Using Custom Entity Table
void CTestXMLiteDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<XML>\
<TAG attr='&asdf>'></TAG>\
</XML>");

	// customized entity list
static const XENTITY entity_table[] = {
		{ '<', _T("&lt;"), 4 } ,
		{ '&', _T("&amp;"), 5 }
	};
	XENTITYS entitys( (LPXENTITY)entity_table, 2 ) ;
	
	PARSEINFO pi;
	XNode xml;
	pi.entity_value = true; // force to use custom entitys
	pi.entitys = &entitys;
	xml.Load( sxml, &pi );
	AfxMessageBox( xml.GetXML()  );

	DISP_OPT opt;
	opt.entitys = &entitys;
	opt.reference_value = true; // force to use custom entitys
	
	AfxMessageBox( xml.GetXML( &opt )  );	
}

void CTestXMLiteDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<XML>\
<TAG attr='c:\\\\myaa'>asdf</TAG>\
</XML>");
	
	XNode xml;
	PARSEINFO pi;
	pi.escape_value = '\\';
	xml.Load( sxml, &pi );

	AfxMessageBox( xml.GetXML()  );
	
	AfxMessageBox( xml.GetChildAttrValue("TAG", "attr")  );
	
}

void CTestXMLiteDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<AddressBook description=\"book of bro\">\
<Person type='me'><Name>Cho,Kyung Min</Name><Nick>bro</Nick></Person>\
<Person type='friend'><Name>Baik,Ji Hoon</Name><Nick>bjh</Nick></Person>\
<Person type=friend><Name>Bak,Gun Joo</Name><Nick>dichter</Nick></Person>\
<Information count='3'/>\
</AddressBook>");

	XNode xml;
	xml.Load( sxml );
	AfxMessageBox( xml.GetXML()  );

	XNode xml2;
	xml2.CopyNode( &xml );
	AfxMessageBox( xml2.GetXML()  );

	XNode xml3;
	//same with xml3 = xml;
	xml3.CopyBranch( &xml );
	AfxMessageBox( xml3.GetXML()  );

	XNode xml4;
	//same with xml3.CopyBranch( &xml );
	xml4.AppendChildBranch( &xml );
	AfxMessageBox( xml4.GetXML()  );
}

void CTestXMLiteDlg::OnButton10() 
{
	// TODO: Add your control notification handler code here
	CString sxml;
	sxml = _T("<?xml version='1.0'?>\
<!-- comment -->\
<![CDATA[some data]]>\
<a>\
	<![CDATA[some data]]>\
	value\
	<![CDATA[some data2]]>\
</a><!-- comment2-->");
	
	XNode xml;
	xml.Load( sxml );

	AfxMessageBox( xml.GetXML()  );
}

void CTestXMLiteDlg::OnButton11() 
{
	// TODO: Add your control notification handler code here
	CString sXML = "\
<html>\
  <body width='100'>\
     Some times I got say...\
	 <font name='system' size='1'/>\
	 <a href='http://www.a.com' target=_blank>\
	 <HR>\
	 Thanks\
  </body>\
</html>";

	XDoc xml;

	PARSEINFO pi;
	pi.force_parse = true;
	if( xml.Load( sXML, &pi ) )
	{
		LPXNode root = xml.GetRoot();
		//root->AppendChild( _T("child"), _T("value") );
		AfxMessageBox( xml.GetXML() );
	}

	// you can't not parse without force_parse on un-welformed xml!
	XNode node;
	if( node.Load( sXML ) )
	{
		AfxMessageBox( node.GetXML() );
	}	
}

void CTestXMLiteDlg::OnButton12() 
{
	// TODO: Add your control notification handler code here
	CString sXML = "\
<A>\
  <B>\
	 <C/>\
	 <D/>\
  </B>\
</A>";

	XNode node;
	if( node.Load( sXML ) )
	{
		AfxMessageBox( node.GetXML() );

		LPXNode found = NULL;
		found = node.Find( _T("D") );
		if( found )
		{
			AfxMessageBox( found->GetXML() );
		}
	}	
}
