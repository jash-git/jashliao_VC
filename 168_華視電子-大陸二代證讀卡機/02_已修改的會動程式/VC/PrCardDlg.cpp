// PrCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyStatic.h"
#include "PrCardDlg.h"
#include "SettingDlg.h"
#include "Utility.h"


// CPrCardDlg dialog

#define PRCARD_TIMER_EVENT 0x501

extern lpCVR_InitComm CVR_InitComm;
extern lpCVR_CloseComm CVR_CloseComm;
extern lpCVR_Authenticate CVR_Authenticate;
extern lpCVR_Read_Content CVR_Read_Content;
extern lpCVR_GetSAMIDU CVR_GetSAMID;

extern lpGetPeopleChineseName CVR_GetPeopleChineseName;
extern lpGetPeopleCertVersion CVR_GetPeopleCertVersion;

extern lpGetPeopleName CVR_GetPeopleName;
extern lpGetPeopleSex CVR_GetPeopleSex;
extern lpGetPeopleNation CVR_GetPeopleNation;
extern lpGetPeopleBirthday CVR_GetPeopleBirthday;
extern lpGetPeopleAddress CVR_GetPeopleAddress;
extern lpGetPeopleIDCode CVR_GetPeopleIDCode;
extern lpGetDepartment CVR_GetDepartment;
extern lpGetStartDate CVR_GetStartDate;
extern lpGetEndDate CVR_GetEndDate;
extern lpGetNationCode CVR_GetNationCode;
extern lpGetNationCodeStrU CVR_GetNationCodeStrU;
extern lpGetNewAppMsgU CVR_GetNewAppAddressU;
extern lpGetCertTypeU CVR_GetCertTypeU;
extern lpGetBMPData CVR_GetBmpData;

IMPLEMENT_DYNAMIC(CPrCardDlg, CDialog)

CPrCardDlg::CPrCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrCardDlg::IDD, pParent)
{
	m_nPort = -1;
	m_nTimer = -1;
	m_nTimerEvent = 0;
	m_nRepeat = FALSE;
	m_pBmp = NULL;
	m_bParamChanged = FALSE;
}

CPrCardDlg::~CPrCardDlg()
{
	if(m_pBmp) delete m_pBmp;
}

void CPrCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_NAME, m_name);
	DDX_Control(pDX, IDC_SEX, m_sex);
	DDX_Control(pDX, IDC_NATION, m_nation);
	DDX_Control(pDX, IDC_BIRTH, m_birth);
	DDX_Control(pDX, IDC_IDCODE, m_idcode);
	DDX_Control(pDX, IDC_DEPART, m_depart);
	DDX_Control(pDX, IDC_VALID, m_valid);
	DDX_Control(pDX, IDC_STATIC_CHINESE_NAME, m_stChineseName);
	DDX_Control(pDX, IDC_STATIC_CERT_VER, m_stCertVer);
	DDX_Control(pDX, IDC_STATIC_DEP_REAL_CODE, m_depCode);
}


BEGIN_MESSAGE_MAP(CPrCardDlg, CDialog)
	ON_BN_CLICKED(ID_READ_FOREIN_ID_CARD, &CPrCardDlg::OnBnClickedReadForeinIdCard)
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CPrCardDlg message handlers

void CPrCardDlg::OnLoadForeinerPic() 
{     
	//显示文字

	int nLen;
	CString strResult;
	TCHAR szContent[MAX_PATH];
	nLen = sizeof(szContent);
	if(CVR_GetPeopleName)
	{
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleName((BYTE*)szContent, &nLen);
		strResult = _T("英文姓名：");
		strResult += szContent;
		if(_tcslen(szContent) > 0)
			m_name.SetWindowText(strResult);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleName函数找不到"));
	}

	if(CVR_GetPeopleChineseName)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleChineseName((BYTE*)szContent, &nLen);
		strResult = _T("中文姓名：");
		strResult += szContent;
		if(_tcslen(szContent) > 0)
			m_stChineseName.SetWindowText(strResult);
	}
	if(CVR_GetPeopleCertVersion)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleCertVersion((BYTE*)szContent, &nLen);
		strResult = _T("证件版本：");
		strResult += szContent;
		if(_tcslen(szContent) > 0)
			m_stCertVer.SetWindowText(strResult);
	}

	if(CVR_GetPeopleSex)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleSex((BYTE*)szContent, &nLen);
		strResult = _T("性别：");
		strResult += szContent;
		if (strResult.Find(_T("女")) != -1)
		{
			strResult += _T("/F");
		}
		else if (strResult.Find(_T("男")) != -1)
		{
			strResult += _T("/M");
		}
		if(_tcslen(szContent) > 0)
			m_sex.SetWindowText(strResult);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleSex函数找不到"));
	}

	if(CVR_GetPeopleNation)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleNation((BYTE*)szContent, &nLen);
		strResult = _T("国籍：");
		strResult += szContent;
		if (CVR_GetNationCodeStrU)
		{
			WCHAR szNationStr[64] = {0};
			int nLen = sizeof(szNationStr);
			CStatic *pStatic = (CStatic*)GetDlgItem(IDC_STATIC_NATION_CODE);
			CVR_GetNationCodeStrU((BYTE*)&szNationStr, &nLen);
			strResult += _T("/");
			strResult += szNationStr;
		}
		if(_tcslen(szContent) > 0)
			m_nation.SetWindowText(strResult);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleNation函数找不到"));
	}

	if(CVR_GetPeopleBirthday)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleBirthday((BYTE*)szContent, &nLen);
		strResult = _T("");
		strResult += szContent;
		int nLength = strResult.GetLength();
		if (nLength == 8)
		{
			CString strTmp;
			strTmp = strResult.Mid(0, 4);
			strTmp += _T(".");
			strTmp += strResult.Mid(4, 2);
			strTmp += _T(".");
			strTmp += strResult.Mid(6, 2);
			strResult = _T("出生日期：")+strTmp;
		}
		if(_tcslen(szContent) > 0)
			m_birth.SetWindowText(strResult);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleBirthday函数找不到"));
	}

	if(CVR_GetPeopleIDCode)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleIDCode((BYTE*)szContent, &nLen);
		strResult = _T("证件号码：");
		strResult += szContent;
		if(_tcslen(szContent) > 0)
			m_idcode.SetWindowText(strResult);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleIDCode函数找不到"));
	}

	if(CVR_GetDepartment)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetDepartment((BYTE*)szContent, &nLen);
		strResult = _T("签发机关：");
		strResult += szContent;
		if (strResult.Find(_T("1500")) != -1)
		{
			strResult = _T("签发机关：公安部/Ministry of Public Security");
		}
		if(_tcslen(szContent) > 0)
			m_depart.SetWindowText(strResult);
		strResult = _T("当次申请受理机关代码：");
		strResult += szContent;
		if(_tcslen(szContent) > 0)
			m_depCode.SetWindowText(strResult);
	}
	else
	{
		AfxMessageBox(_T("GetDepartment函数找不到"));
	}

	if(CVR_GetStartDate && CVR_GetEndDate)
	{
		nLen = sizeof(szContent);
		CString strStart, strEnd, strResult;
		memset(szContent, 0, sizeof(szContent));
		CVR_GetStartDate((BYTE*)szContent, &nLen);
		strStart = szContent;
		int nLength = strStart.GetLength();
		if (nLength == 8)
		{
			CString strTmp;
			strTmp = strStart.Mid(0, 4);
			strTmp += _T(".");
			strTmp += strStart.Mid(4, 2);
			strTmp += _T(".");
			strTmp += strStart.Mid(6, 2);
			strStart = strTmp;
		}
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetEndDate((BYTE*)szContent, &nLen);
		strEnd = szContent;
		nLength = strEnd.GetLength();
		if (nLength == 8)
		{
			CString strTmp;
			strTmp = strEnd.Mid(0, 4);
			strTmp += _T(".");
			strTmp += strEnd.Mid(4, 2);
			strTmp += _T(".");
			strTmp += strEnd.Mid(6, 2);
			strEnd = strTmp;
		}
		strResult = _T("有效期限：") + strStart + _T("  -  ") + strEnd;
		if(_tcslen(szContent) > 0)
			m_valid.SetWindowText(strResult);
	}
	else
	{
		AfxMessageBox(_T("GetStartDate或GetEndDate函数找不到"));
	}
	if (CVR_GetNationCodeStrU)
	{
		WCHAR szNationStr[64] = {0};
		int nLen = sizeof(szNationStr);
		CStatic *pStatic = (CStatic*)GetDlgItem(IDC_STATIC_NATION_CODE);
		CVR_GetNationCodeStrU((BYTE*)&szNationStr, &nLen);
		CString strVal;
		strVal = _T("国籍代码：");
		strVal += szNationStr;
		if(_tcslen(szContent) > 0)
			pStatic->SetWindowText(strVal);
	}

	if (CVR_GetCertTypeU)
	{
		TCHAR szData[128] = {0};
		int nSize = sizeof(szData);
		int nRet = CVR_GetCertTypeU((BYTE*)szData, &nSize);
		nRet = 0;
	}

	////////////////////////////////////////////显示照片
	ShowPhoto(IDC_STATIC_PHOTO);
}

void CPrCardDlg::ShowPhoto(int nPhotoID)
{
	if (CVR_GetBmpData)
	{
		int nLen = 40960;
		BYTE * pBmpData = new BYTE[nLen];
		CVR_GetBmpData(pBmpData, &nLen);
		if(m_pBmp) delete m_pBmp;
		m_pBmp = Utility::CreateBitmapFromMemory(pBmpData, nLen);

		Graphics graph(m_hWnd);
		if (m_pBmp)
		{
			CRect rect;
			int cx = m_pBmp->GetWidth(), cy = m_pBmp->GetHeight();
			GetDlgItem(nPhotoID)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			//GetDlgItem(nPhotoID)->MoveWindow(rect.left, rect.top, cx, cy, true);//调整大小	
			graph.DrawImage(m_pBmp, rect.left, rect.top, 0, 0, cx, cy, UnitPixel);
		}
		delete[] pBmpData;
	}
}

void CPrCardDlg::OnBnClickedReadForeinIdCard()
{
	// TODO: Add your control notification handler code here
	CButton * pRead = (CButton*)GetDlgItem(ID_READ_FOREIN_ID_CARD);
	if (m_nTimerEvent != 0)
	{
		this->KillTimer(m_nTimerEvent);
		m_nTimerEvent = 0;
		pRead->SetWindowText(_T("读身份证"));
	}
	else
	{
		if (m_nTimer >= 500)	// 读卡间隔要大于500毫秒
		{
			m_nTimerEvent = this->SetTimer(PRCARD_TIMER_EVENT, m_nTimer, NULL);
			pRead->SetWindowText(_T("停止读身份证"));
		}
		else if(m_nTimer == 0)
			ReadCard();
		else
			AfxMessageBox(_T("读卡间隔最好大于500毫秒"));
	}
}

BOOL CPrCardDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class

	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE ) return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}


void CPrCardDlg::SetReadParam(int nPort, int nTimer, int nRepeat)
{
	m_nPort = nPort;
	m_nTimer = nTimer;
	m_nRepeat = nRepeat;
	m_bParamChanged = TRUE;
}

void CPrCardDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if (PRCARD_TIMER_EVENT == nIDEvent)
	{
		ReadCard();
	}
	CDialog::OnTimer(nIDEvent);
}

void CPrCardDlg::ReadCard()
{
	int iRetUSB = 0, iRetCOM = 0;
	DWORD dwStart = ::GetTickCount();
	CStatic * pStTime = (CStatic*)GetDlgItem(IDC_STATIC_TIME);
	CString strTime;
	pStTime->SetWindowText(strTime);

	if (m_nPort == CSettingDlg::AutoPort)	// 自动寻找端口
	{
		for (int iPort=1001; iPort<=1016; iPort++)
		{
			iRetUSB = CVR_InitComm(iPort);
			if (iRetUSB == 1)
			{
				break;
			}
		}
		if(iRetUSB != 1)
		{
			for (int iPort=1; iPort<=16; iPort++)
			{
				iRetCOM = CVR_InitComm(iPort);
				if (iRetCOM == 1)
				{
					break;
				}
			}
		}
	}
	else if (m_nPort >= CSettingDlg::ComPort1 && m_nPort <= CSettingDlg::ComPort16)	// 查询串口
	{
		iRetCOM = CVR_InitComm(m_nPort);
	}
	else if (m_nPort >= CSettingDlg::UsbPort1 && m_nPort <= CSettingDlg::UsbPort16)	// 查询串口
	{
		iRetUSB = CVR_InitComm(m_nPort);
	}

	if  ((iRetCOM==1)||(iRetUSB==1))
	{
		if (CVR_GetSAMID)
		{
			wchar_t szSamID[256] = {0};
			CStatic * stSamID = (CStatic*)GetDlgItem(IDC_SAM_ID);
			if(CVR_GetSAMID((BYTE*)szSamID) == 1)
			{
				CString strSamID;
				strSamID = _T("安全模块号：");
				strSamID += szSamID;
				stSamID->SetWindowText(strSamID);
			}
			else
			{
				stSamID->SetWindowText(_T("安全模块号"));
			}
		}
		int nAuthenticate = CVR_Authenticate();
		if (1 == nAuthenticate && m_nRepeat == FALSE)
		{
			if (1==CVR_Read_Content() )
			{
				dwStart = ::GetTickCount() - dwStart;
				strTime.Format(_T("读卡时间：%dms"), dwStart);
				pStTime->SetWindowText(strTime);
				OnLoadForeinerPic();
			}
			else
			{
				MessageBox(_T("读卡失败！"));
			}
		}
		else if (m_nRepeat == TRUE)
		{
			int nRead = CVR_Read_Content();
			dwStart = ::GetTickCount() - dwStart;
			strTime.Format(_T("读卡时间：%dms"), dwStart);
			pStTime->SetWindowText(strTime);
			OnLoadForeinerPic();
		}
		else
		{
			MessageBox(_T("找卡失败！"));
		}
	}
	else
	{
		MessageBox(_T("端口打开失败！"));
	}    

	CVR_CloseComm(); 
}
void CPrCardDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	Graphics graph(m_hWnd);
	if (m_pBmp)
	{
		CRect rect;
		int cx = m_pBmp->GetWidth(), cy = m_pBmp->GetHeight();
		GetDlgItem(IDC_STATIC_PHOTO)->GetWindowRect(&rect);
		ScreenToClient(&rect);
		GetDlgItem(IDC_STATIC_PHOTO)->MoveWindow(rect.left, rect.top, cx, cy, true);//调整大小	
		graph.DrawImage(m_pBmp, rect.left, rect.top, 0, 0, cx, cy, UnitPixel);
	}
}

BOOL CPrCardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	CRect rect;
	GetDlgItem(IDC_STATIC_PHOTO)->GetWindowRect(&rect);
	rect.right = rect.left + 102;
	rect.bottom = rect.top + 126;
	ScreenToClient(&rect);
	GetDlgItem(IDC_STATIC_PHOTO)->MoveWindow(rect, true);//调整大小
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
