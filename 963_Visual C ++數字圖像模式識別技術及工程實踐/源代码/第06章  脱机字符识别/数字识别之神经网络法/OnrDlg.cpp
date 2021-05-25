/* ============================================= *\
 * File:		OnrDlg.cpp						 *
 * Description: ���Ի���ͷ�ļ�                   *
 *				�������еĺ���                   *
\* ============================================= */

#include "stdafx.h"
#include "Onr.h"
#include "OnrDlg.h"

#include <fstream.h>
#include <time.h>
#include <stdlib.h>

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
	virtual BOOL OnInitDialog();
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
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// COnrDlg dialog

COnrDlg::COnrDlg(CWnd* pParent) : CDialog(COnrDlg::IDD, pParent) {
	//{{AFX_DATA_INIT(COnrDlg)
	//}}AFX_DATA_INIT

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COnrDlg::DoDataExchange(CDataExchange* pDX) {
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COnrDlg)
	DDX_Control(pDX, IDC_TRAINSPIN, m_Trainspin);
	DDX_Control(pDX, IDC_TESTSPIN, m_Testspin);
	DDX_Control(pDX, IDC_TRAININFO, m_TrainInfo);
	DDX_Control(pDX, IDC_INFOBOX, m_cInfoBox);
	DDX_Control(pDX, IDC_TESTWINDOW, m_TestWindow);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(COnrDlg, CDialog)
	//{{AFX_MSG_MAP(COnrDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TRAIN, OnTrain)
	ON_BN_CLICKED(IDC_CLASSIFY, OnClassify)
	ON_NOTIFY(UDN_DELTAPOS, IDC_TRAINSPIN, OnDeltaposTrainspin)
	ON_NOTIFY(UDN_DELTAPOS, IDC_TESTSPIN, OnDeltaposTestspin)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

///////////////////////////////////////////////////////////////////////////////
// ��ʼ���Ի���
BOOL COnrDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();

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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon((HICON)(LoadImage(AfxGetResourceHandle(), 
		MAKEINTRESOURCE(IDR_MAINFRAME), IMAGE_ICON, 16, 16, 0)), FALSE);

	// ���ù������ķ�Χ
	m_Testspin.SetRange(0,NN_NUMBERS-1);
	m_Trainspin.SetRange(0,NN_NUMBERS-1);
	m_Testspin.SetPos(0);
	m_Trainspin.SetPos(0);
	
	// ���ļ�
	ifstream data("learn.dat", ios::nocreate);
	ifstream test("test.dat", ios::nocreate);

	// ����ļ�����Ч��
	if (!test || !data) 
	{
		MessageBox("No learning or test data present.", "Cannot run...",
			MB_OK | MB_ICONERROR);
	}

	// ���ļ�
	for(int i=0;i<NN_NUMBERS;i++) 
	{
		for(int j=0;j<NN_RESX * NN_RESY;j++) 
		{
			int onoff;
			test >> onoff;
			m_bTestData[i][j] = onoff;

			data >> onoff;
			m_bNumbers[i][j] = onoff;
		}
	}

	// ���ó�ʼҪ��������ָ��
	m_ipDrawNum = &m_bNumbers[0][0];

	return true;
}

void COnrDlg::OnSysCommand(UINT nID, LPARAM lParam) {
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

void COnrDlg::OnPaint() 
{
	if (IsIconic())	{
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
	} else {
		CPaintDC dc(this);
		CDialog::OnPaint();

		// ���ַ��������ο����е��ػأ�������ȷ���Թ���
		CRect rect;

		m_TestWindow.GetClientRect(&rect);
		m_TestWindow.ClientToScreen(&rect);
		ScreenToClient(&rect);
		dc.FrameRect(&rect, &CBrush(RGB(0,0,0)));
		rect.DeflateRect(1,1);
		dc.FillSolidRect(rect, RGB(255,255,255));

		// ������
		DrawNumber(&dc, m_ipDrawNum, &rect);
	}
}

HCURSOR COnrDlg::OnQueryDragIcon() 
{
	return (HCURSOR) m_hIcon;
}

///////////////////////////////////////////////////////////
// ����ĳЩԭ���������"Maxinum Speed"�Ż�������������е�
// ʧ�ܣ������ȹص��Ż����ڸöδ���������ٴ��Ż�����
///////////////////////////////////////////////////////////

#pragma optimize( "", off )

//////////////////////////////////////////////////////////////////////////
//  ѵ������
void COnrDlg::OnTrain() 
{
	srand((unsigned)time(NULL));			// ���������
	m_cInfoBox.ResetContent();
	
	// ����Ȩֵ0��ʼ��
	memset(&m_fWeights,0,sizeof(m_fWeights));

	// ����һЩ�������������ѵ������
	m_cInfoBox.InsertString(-1, "Generating noisy data...");
	int num = 0;
	for (int i=0;i<NN_NUMBERS * NN_NOISY;i++) 
	{
		for(int j=0;j<NN_RESX * NN_RESY;j++) 
		{
			if (rand() % 100 < 7) 
			{
				m_iNoisy[i][j] = !m_bNumbers[num][j];
			} 
			else 
				m_iNoisy[i][j] = m_bNumbers[num][j];
		}
		
		if ((float)(i+1)/NN_NOISY == (i+1)/NN_NOISY && i != 0) 
			num++;
	}

	m_cInfoBox.InsertString(-1, "Learning...");

	RunNet(true);

	m_TrainInfo.SetWindowText("Complete...");
	m_cInfoBox.InsertString(-1,"Training Complete!");
	GetDlgItem(IDC_CLASSIFY)->EnableWindow(true);
}

///////////////////////////////////////////////////////////////////////////
// ������
void COnrDlg::DrawNumber(CDC *dc, int *cell, CRect *rect) 
{
	// ����ļ�����Ҫ��ʹ�����ֻ��ھ��ο��������
	CPoint tl;
	tl.x = rect->Width()/2 - (NN_RESX*10)/2;
	tl.y = rect->Height()/2 - (NN_RESY*10)/2;

	tl.Offset(rect->TopLeft());
	int ix = tl.x;
	
	// ����һЩΧ�����ֵĺ�ɫ����
	CPen pen;
	if (pen.CreatePen(PS_DOT, 1, RGB(127,0,0))) 
	{
		CPen *pOldPen = dc->SelectObject(&pen);

		CPoint pt1 = rect->TopLeft();
		CPoint pt2 = rect->BottomRight();
		dc->MoveTo(tl.x-5, tl.y-2);
		dc->LineTo(tl.x+NN_RESX*10+5, tl.y-2);
		dc->MoveTo(tl.x-5, tl.y+10*NN_RESY+1);
		dc->LineTo(tl.x+NN_RESX*10+5, tl.y+10*NN_RESY+1);
		dc->MoveTo(tl.x-2, tl.y-7);
		dc->LineTo(tl.x-2, tl.y+NN_RESY*10+7);
		dc->MoveTo(tl.x+NN_RESX*10+2, tl.y-7);
		dc->LineTo(tl.x+NN_RESX*10+2, tl.y+NN_RESY*10+7);

		dc->SelectObject(pOldPen);
	}

	// ��ʾһЩ�ı�
	CRect format(tl.x+1, tl.y+NN_RESY*10+2,
				 tl.x+NN_RESX*10-1, tl.y+NN_RESY*10+18);
	if (m_bDisplayString) 
	{
		CFont fnt;
		if (fnt.CreatePointFont(80,"Arial")) 
		{
			CFont* pOldFont = dc->SelectObject(&fnt);

			dc->SetTextColor(RGB(0,0,127));
			dc->DrawText(m_Str,format,DT_CENTER);
			dc->SelectObject(pOldFont);
		}	
	}

	// ������
	for(int i=0;i<NN_RESX*NN_RESY;i++) 
	{
		if ((*cell) == 1) 
		{
			dc->FillSolidRect(tl.x,tl.y,10,10,RGB(0,0,0));
		}
		tl.x += 10;
		if (tl.x == ix + 10*NN_RESX) 
		{
			tl.x = ix;
			tl.y += 10;
		}
		cell++;
	}
}

//////////////////////////////////////////////////////////////////////////////////
// ʶ��
void COnrDlg::OnClassify() 
{
	int pos = (BYTE)m_Testspin.GetPos();
	
	m_ipDrawNum = &m_bTestData[pos][0];
	InvalidateNumber();

	float d[NN_NUMBERS];
	for(int j=0;j<NN_NUMBERS;j++) 
	{
		d[j] = 0;
		for(int k=0;k<NN_RESX * NN_RESY;k++) 
		{
			d[j] += m_fWeights[j][k]*m_bTestData[pos][k];
		}
	}
	
	int bestind = 0;
	for(j=1;j<NN_NUMBERS;j++) 
		if (d[j] > d[bestind]) 
			bestind = j;

	// ���㻭�ı�������
	CRect size;
	m_TestWindow.GetClientRect(&size);
	int x = size.Width()/2  - (NN_RESX*10)/2;
	int y = size.Height()/2 - (NN_RESY*10)/2;
	CRect format(x,size.Height()-y+1, size.Width()-x, size.Height()-5);
	
	m_bDisplayString = true;
	GetText(m_Str, bestind+1);
}

/////////////////////////////////////////////////////////////////////////////
// ��������
// ������training��Ϊ��ʱ��ʾ�������ѵ��״̬
void COnrDlg::RunNet(bool training) 
{
	// ����������������
	float d[NN_NUMBERS];
	int cycles = 0;//��ʼ��ѭ������Ϊ0
	bool correct;

	do 
	{
		correct = true;
		for(int i=0;i<NN_NUMBERS * NN_NOISY;i++) 
		{
			for(int j=0;j<NN_NUMBERS;j++) 
			{
				d[j] = 0;
				for(int k=0;k<NN_RESX * NN_RESY;k++) 
				{
					d[j] += m_fWeights[j][k]*m_iNoisy[i][k];
				}
			}
			
			int bestind = 0;
			for(j=1;j<NN_NUMBERS;j++) 
				if (d[j] > d[bestind]) 
					bestind = j;
			
			int realval = (int)(i/NN_NOISY);
			if (bestind == realval) continue;
			
			if (training) 
			{
				CString result;
				result.Format("Guessed %d instead of %d.",bestind, realval);
				m_TrainInfo.SetWindowText(result);
				correct = false;
				
				for(j=0;j<NN_RESX * NN_RESY;j++) 
				{
					m_fWeights[bestind][j] -= m_iNoisy[i][j];
					m_fWeights[realval][j] += m_iNoisy[i][j];
				}
			}
		}
		
		SetDlgItemInt(IDC_ITERATE, ++cycles);
	} while (!correct && cycles <= NN_MAXITER);
	
	//���ѭ������̫��ÿ�õ�������˳�
	if (cycles >= NN_MAXITER) 
	{
		MessageBox("Training has timed-out.",
			"Error in Training", MB_OK | MB_ICONINFORMATION);
		return;
	}
}

//�ָ�ϵͳ�Ż�
#pragma optimize( "", on )

////////////////////////////////////////////////////////////////////////
// ����ѵ�����ݵĹ�����
void COnrDlg::OnDeltaposTrainspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	int iPos = pNMUpDown->iPos;
	int iDelta = pNMUpDown->iDelta;
	
	m_bDisplayString = false;

	if ((iPos == 0 && iDelta == -1) || (iPos == NN_NUMBERS-1 && iDelta == 1)) 
	{
		if (iDelta == -1) 
		{
			m_ipDrawNum = &m_bNumbers[0][0];
			InvalidateNumber();
		} 
		else 
		{
			m_ipDrawNum = &m_bNumbers[NN_NUMBERS-1][0];
			InvalidateNumber();
		}
	} 
	else 
	{
		m_ipDrawNum = &m_bNumbers[iPos+iDelta][0];
		InvalidateNumber();
	}
	
	*pResult = 0;
}

//////////////////////////////////////////////////////////////////////////////////
// ����������ݵĹ�����
void COnrDlg::OnDeltaposTestspin(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	int iPos = pNMUpDown->iPos;
	int iDelta = pNMUpDown->iDelta;

	m_bDisplayString = false;

	if ((iPos == 0 && iDelta == -1) || (iPos == NN_NUMBERS-1 && iDelta == 1)) 
	{
		if (iDelta == -1) 
		{
			m_ipDrawNum = &m_bTestData[0][0];
			InvalidateNumber();
		} 
		else 
		{
			m_ipDrawNum = &m_bTestData[NN_NUMBERS-1][0];
			InvalidateNumber();
		}
	} 
	else 
	{
		m_ipDrawNum = &m_bTestData[iPos+iDelta][0];
		InvalidateNumber();
	}
	
	*pResult = 0;
}

//////////////////////////////////////////////////////////////////////////
// �õ��������Ӧ���ı�
void COnrDlg::GetText(CString &str, int num) {
	switch (num) {
	case 1:
		str = "Result:1"; 
		break;
	case 2:
		str = "Result:2"; 
		break;
	case 3:
		str = "Result:3"; 
		break;
	case 4:
		str = "Result:4"; 
		break;
	case 5:
		str = "Result:5"; 
		break;
	case 6:
		str = "Result:6"; 
		break;
	case 7:
		str = "Result:7"; 
		break;
	case 8:
		str = "Result:8"; 
		break;
	case 9:
		str = "Result:9"; 
		break;
	default:
		str = "Undetermined";
	}
}

///////////////////////////////////////////////////////////////////////////////
// ǿ���ػ�
void COnrDlg::InvalidateNumber() 
{
	CRect rect;
	
	m_TestWindow.GetClientRect(&rect);
	m_TestWindow.ClientToScreen(&rect);
	ScreenToClient(&rect);

	InvalidateRect(rect, false);
}
