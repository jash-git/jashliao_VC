/*
	NAME:		CdToWAV
	FUNCTION:	CD抓轨转成WAVE工具
	AUTHOR:		黄利龙(HuangLilong) Email:landyu@163.com
	DATE:		2003-7
*/
#include "stdafx.h"
#include "CdToWav.h"
#include "CdToWavDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CCdToWavDlg 对话框



CCdToWavDlg::CCdToWavDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCdToWavDlg::IDD, pParent)
	, m_SavePath(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCdToWavDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_COMBO_CDROM, m_Combo_Cdrom);
	DDX_Control(pDX, IDC_PROGRESS, m_Progress);
	DDX_Text(pDX, IDC_EDIT, m_SavePath);
}

BEGIN_MESSAGE_MAP(CCdToWavDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_GETPATH, OnBnClickedGetpath)
	ON_BN_CLICKED(IDC_CHANGE, OnBnClickedChange)
	ON_WM_TIMER()
	ON_CBN_SELCHANGE(IDC_COMBO_CDROM, OnCbnSelchangeComboCdrom)
	ON_LBN_SELCHANGE(IDC_LIST, OnLbnSelchangeList)
END_MESSAGE_MAP()


// CCdToWavDlg 消息处理程序

BOOL CCdToWavDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将\“关于...\”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	CString m_csTemp;
	for(char temp='C';temp<'Z';temp++)
	{
		m_csTemp.Format("%c:",temp);
		if(GetDriveType(m_csTemp)==DRIVE_CDROM)
		{
			m_Combo_Cdrom.AddString(m_csTemp);
		}
	}
	for(int i=0;m_hDevice!= INVALID_HANDLE_VALUE;i++)
	{
		m_Combo_Cdrom.SetCurSel(i);
		m_Combo_Cdrom.GetWindowText(m_csTemp);
		m_hDevice =CreateFile("\\\\.\\"+m_csTemp,GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL);
		if(m_hDevice!= INVALID_HANDLE_VALUE)
			break;
	}
	if(m_hDevice!= INVALID_HANDLE_VALUE)
			SetTimer(0,1000,NULL);
	return TRUE;  // 除非设置了控件的焦点，否则返回 TRUE
}

void CCdToWavDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。


void CCdToWavDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CCdToWavDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
UINT ReadThread(LPVOID pParam)
{
	CCdToWavDlg* pDlg = (CCdToWavDlg*)pParam;
	if (pDlg == NULL )//||!pDlg->IsKindOf(RUNTIME_CLASS(CCdToWavDlg)))
		return -1;
	DWORD m_WaveHeaderSize = 38;
	DWORD m_WaveFormatSize = 18;
	DWORD m_AudioDataSize =0;
	DWORD m_WrittenBytes = 0;
	WAVEFORMATEX m_WaveFormatEx;
	m_WaveFormatEx.wFormatTag=WAVE_FORMAT_PCM ;
	m_WaveFormatEx.nSamplesPerSec=48000;
	m_WaveFormatEx.wBitsPerSample=16;
	m_WaveFormatEx.nChannels=2;
	m_WaveFormatEx.cbSize=0;
	m_WaveFormatEx.nBlockAlign=m_WaveFormatEx.nChannels*(m_WaveFormatEx.wBitsPerSample/8);
	m_WaveFormatEx.nAvgBytesPerSec=m_WaveFormatEx.nSamplesPerSec*m_WaveFormatEx.nBlockAlign;
	
	CFile m_file;
	CFileException fileException;
	CString m_csFileName=pDlg->m_SavePath;
	m_file.Open(m_csFileName,CFile::modeCreate|CFile::modeReadWrite, &fileException);
	int StartSect=pDlg->GetStartSector(pDlg->m_List.GetCurSel()+1);
	int EndSect=pDlg->GetEndSector(pDlg->m_List.GetCurSel()+1);
	DWORD Bytes2Read=(EndSect - StartSect)*CB_AUDIO;
	m_AudioDataSize=Bytes2Read;
	BYTE  Data[CB_AUDIO*NSECTORS];
	pDlg->m_Progress.SetRange32(0,Bytes2Read);
	pDlg->m_Progress.SetPos(0);

	m_file.SeekToBegin();
	m_file.Write("RIFF",4);
	unsigned int Sec=(m_AudioDataSize + m_WaveHeaderSize);
	m_file.Write(&Sec,sizeof(Sec));
	m_file.Write("WAVE",4);
	m_file.Write("fmt ",4);
	m_file.Write(&m_WaveFormatSize,sizeof(m_WaveFormatSize));
	m_file.Write(&m_WaveFormatEx.wFormatTag,sizeof(m_WaveFormatEx.wFormatTag));
	m_file.Write(&m_WaveFormatEx.nChannels,sizeof(m_WaveFormatEx.nChannels));
	m_file.Write(&m_WaveFormatEx.nSamplesPerSec,sizeof(m_WaveFormatEx.nSamplesPerSec));
	m_file.Write(&m_WaveFormatEx.nAvgBytesPerSec,sizeof(m_WaveFormatEx.nAvgBytesPerSec));
	m_file.Write(&m_WaveFormatEx.nBlockAlign,sizeof(m_WaveFormatEx.nBlockAlign));
	m_file.Write(&m_WaveFormatEx.wBitsPerSample,sizeof(m_WaveFormatEx.wBitsPerSample));
	m_file.Write(&m_WaveFormatEx.cbSize,sizeof(m_WaveFormatEx.cbSize));
	m_file.Write("data",4);
	m_file.Write(&m_AudioDataSize,sizeof(m_AudioDataSize));

	DWORD m_seek=46;
	for (int sector = StartSect; (sector < EndSect); sector+=NSECTORS)
	{
		int Sectors2Read = ( (sector + NSECTORS) < EndSect )?NSECTORS:(EndSect-sector);
		if (pDlg->ReadSector(sector, Data, Sectors2Read))					
		{						
			m_file.Write(Data,CB_AUDIO*Sectors2Read);
			m_file.Seek(m_seek+=CB_AUDIO*Sectors2Read,CFile::begin);
			pDlg->m_Progress.SetPos(m_seek);
		}	
	}
	m_file.Close();
	pDlg->GetDlgItem(IDC_GETPATH)->EnableWindow(true);
	pDlg->GetDlgItem(IDC_CHANGE)->EnableWindow(true);
	pDlg->GetDlgItem(IDCANCEL)->EnableWindow(true);
	pDlg->MessageBox("OK");
	return 0;
}
void CCdToWavDlg::OnBnClickedGetpath()
{
	CDirDialog dlg;
	if(dlg.DoBrowse(this)==IDOK)
	{
		m_csSavePath=dlg.m_strPath; 
		if(m_csSavePath.Right(1)=="\\")
			m_SavePath=m_csSavePath+m_csTrack+".wav";
		else
			m_SavePath=m_csSavePath+"\\"+m_csTrack+".wav";
		UpdateData(false);
	}
}
DWORD CCdToWavDlg::GetStartSector(int track)
{
	return (CdromTOC.TrackData[track-1].Address[1]*60*75 + CdromTOC.TrackData[track-1].Address[2]*75 + CdromTOC.TrackData[track-1].Address[3])-150;
}
DWORD CCdToWavDlg::GetEndSector(int track)
{
	return (CdromTOC.TrackData[track].Address[1]*60*75 + CdromTOC.TrackData[track].Address[2]*75 + CdromTOC.TrackData[track].Address[3])-151;
}
BOOL CCdToWavDlg::ReadSector(int sector,BYTE Buffer[], int NumSectors) 
{
	DWORD dwOutBytes;
	RAW_READ_INFO rri;
	rri.TrackMode =(TRACK_MODE_TYPE)2;
	rri.SectorCount = (DWORD)NumSectors;
	rri.DiskOffset =(DWORD64)(sector*CB_CDROMSECTOR);
	if (DeviceIoControl(m_hDevice,IOCTL_CDROM_RAW_READ,&rri, sizeof(rri),Buffer, (DWORD)NumSectors*CB_AUDIO,&dwOutBytes,(LPOVERLAPPED)NULL))			
			return true;		
	return false;
}
BOOL CCdToWavDlg::IsReady()
{
	DWORD dwOutBytes;
	return (DeviceIoControl(m_hDevice,IOCTL_STORAGE_CHECK_VERIFY, NULL, 0,NULL, 0, &dwOutBytes, (LPOVERLAPPED)NULL));
}
void CCdToWavDlg::OnBnClickedChange()
{
	if(IsReady()&&m_csSavePath!=""&&m_csTrack!="")
	{
		GetDlgItem(IDC_GETPATH)->EnableWindow(false);
		GetDlgItem(IDC_CHANGE)->EnableWindow(false);
		GetDlgItem(IDCANCEL)->EnableWindow(false);
		AfxBeginThread(ReadThread,this);
	}
	else
		AfxMessageBox("光驱中无光盘或文件和路径没选好");
}

void CCdToWavDlg::OnTimer(UINT nIDEvent)
{
	if(m_hDevice!= INVALID_HANDLE_VALUE)
	{
		BOOL bResult;
		DWORD dwOutBytes;
		bResult =DeviceIoControl(m_hDevice,IOCTL_CDROM_READ_TOC,NULL, 0,&CdromTOC, sizeof(CdromTOC),&dwOutBytes,(LPOVERLAPPED)NULL);
		if(bResult)
		{
			for(int i=0;i<CdromTOC.LastTrack;i++)
			{
				m_List.DeleteString(0);
			}
			for(int i=1;i<=CdromTOC.LastTrack;i++)
			{
				CString strTrack;
				strTrack.Format("曲目%d",i);
				m_List.AddString(strTrack);
			}
			KillTimer(0);
		}
	}
	else
	{
		KillTimer(0);
	}
	CDialog::OnTimer(nIDEvent);
}

void CCdToWavDlg::OnCbnSelchangeComboCdrom()
{
	CString m_csTemp;
	m_Combo_Cdrom.GetWindowText(m_csTemp);
	m_hDevice =CreateFile("\\\\.\\"+m_csTemp,GENERIC_READ,FILE_SHARE_READ | FILE_SHARE_WRITE,NULL,OPEN_EXISTING,0,NULL);
	if(m_hDevice!= INVALID_HANDLE_VALUE)
			SetTimer(0,1000,NULL);
}

void CCdToWavDlg::OnLbnSelchangeList()
{
	m_List.GetText(m_List.GetCurSel(),m_csTrack);
	if(m_csSavePath.Right(1)=="\\")
		m_SavePath=m_csSavePath+m_csTrack+".wav";
	else
		m_SavePath=m_csSavePath+"\\"+m_csTrack+".wav";
	UpdateData(false);
}
