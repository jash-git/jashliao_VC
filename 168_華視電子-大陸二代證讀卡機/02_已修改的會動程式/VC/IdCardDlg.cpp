// IdCardDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyStatic.h"
#include "IdCardDlg.h"
#include "SettingDlg.h"
#include "Utility.h"
#include "atlimage.h"
const int UNICODE_TXT_FLG = 0xFEFF;  //UNICODE文本标示 

// CIdCardDlg dialog


#define IDCARD_TIMER_EVENT 0x500

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


IMPLEMENT_DYNAMIC(CIdCardDlg, CDialog)

void CIdCardDlg::PictureSave(UINT ID)
{
	CWnd* bmpShow = GetDlgItem(ID);
	CDC *pdc = bmpShow->GetDC();
	CImage  imag;//#include "atlimage.h"
	CRect rect;

	GetClientRect(&rect);        //获取画布大小
	bmpShow->GetWindowRect(&rect);
	imag.Create(rect.Width(), rect.Height(), 32);
	::BitBlt(imag.GetDC(), 0, 0, rect.Width(), rect.Height(), pdc->m_hDC, 0, 0, SRCCOPY);

	/*
	TCHAR szFilter[] = _T("jpg file(*.jpg)|*.jpg|bmp file(*.bmp)|*.bmp|所有文件(*.*)|*.*||");  //文件格式过滤
																						   // 构造保存文件对话框    
	CFileDialog fileDlg(FALSE, _T("jpg"), _T("*.jpg"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	fileDlg.m_ofn.lpstrTitle = _T("保存直方图");  //保存对话窗口标题名
	CString picturePath;
	if (IDOK == fileDlg.DoModal())  //按下确认键
	{
		picturePath = fileDlg.GetPathName();  //文件路径
	}
	*/
	CString picturePath="cv.jpg";
	HRESULT hResult = imag.Save(picturePath); //保存图片
	ReleaseDC(pdc);
	imag.ReleaseDC();
}

CIdCardDlg::CIdCardDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIdCardDlg::IDD, pParent)
{
	m_nTimerEvent = 0;
	m_nPort = -1;
	m_nTimer = -1;
	m_nRepeat = FALSE;
	m_pBmp = NULL;
	m_bParamChanged = FALSE;
}

CIdCardDlg::~CIdCardDlg()
{
	if(m_pBmp) delete m_pBmp;
}

void CIdCardDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_NAME_CIVIC, m_civicName);
	DDX_Control(pDX, IDC_SEX_CIVIC, m_civicSex);
	DDX_Control(pDX, IDC_NATION_CIVIC, m_civicNation);
	DDX_Control(pDX, IDC_STATIC_NATION_CODE_CIVIC, m_civicNationCode);
	DDX_Control(pDX, IDC_BIRTH_CIVIC, m_civicBirthday);
	DDX_Control(pDX, IDC_IDCODE_CIVIC, m_civicCardID);
	DDX_Control(pDX, IDC_ADDR_CIVIC, m_civicAddress);
	DDX_Control(pDX, IDC_DEPART_CIVIC, m_civicDepartment);
	DDX_Control(pDX, IDC_VALID_CIVIC, m_civicValidDate);
	DDX_Control(pDX, IDC_SAM_ID_CIVIC, m_civicSamID);
	DDX_Control(pDX, IDC_STATIC_TIME_CIVIC, m_civicReadTime);
}


BEGIN_MESSAGE_MAP(CIdCardDlg, CDialog)
	ON_BN_CLICKED(ID_READ_ID_CARD, &CIdCardDlg::OnBnClickedReadIdCard)
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CIdCardDlg message handlers

void CIdCardDlg::OnLoadCivicPic() 
{     
	////////////////////////////////////////////显示文字
	int nLen;
	CString strVal;
	TCHAR szContent[MAX_PATH];
	nLen = sizeof(szContent);
	//----
	DeleteFile(L"cv.txt");
	DeleteFile(L"cv.jpg");
	/*
	FILE* WriteF;
	WriteF = NULL;
	*/
	CString Wstr = "";//_T("一个测试写入文本");
	//----

	if(CVR_GetPeopleName)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleName((BYTE*)szContent, &nLen);
		strVal = _T("姓名：");
		strVal += szContent;

		/*
		WriteF = NULL;
		WriteF = fopen("cv00.txt", "w+");
		Wstr = szContent;
		if (WriteF)
		{
			fwrite(&UNICODE_TXT_FLG, 2, 1, WriteF);
			fwrite(Wstr.GetBuffer(Wstr.GetLength()), Wstr.GetLength() * 2, 1, WriteF);
			fclose(WriteF);
		}
		*/
		Wstr += szContent;
		Wstr += L",";

		if(_tcslen(szContent) > 0)
			m_civicName.SetWindowText(strVal);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleName函数找不到"));
	}

	if(CVR_GetPeopleSex)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleSex((BYTE*)szContent, &nLen);
		strVal = _T("性别：");
		strVal += szContent;
		
		/*
		WriteF = NULL;
		WriteF = fopen("cv01.txt", "w+");
		Wstr = szContent;
		if (WriteF)
		{
			fwrite(&UNICODE_TXT_FLG, 2, 1, WriteF);
			fwrite(Wstr.GetBuffer(Wstr.GetLength()), Wstr.GetLength() * 2, 1, WriteF);
			fclose(WriteF);
		}
		*/
		Wstr += szContent;
		Wstr += L",";

		if(_tcslen(szContent) > 0)
			m_civicSex.SetWindowText(strVal);
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
		strVal = _T("民族：");
		strVal += szContent;
		if(_tcslen(szContent) > 0)
			m_civicNation.SetWindowText(strVal);
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
		strVal = _T("出生日期：");
		strVal += szContent;

		/*
		WriteF = NULL;
		WriteF = fopen("cv02.txt", "w+");
		Wstr = szContent;
		if (WriteF)
		{
			fwrite(&UNICODE_TXT_FLG, 2, 1, WriteF);
			fwrite(Wstr.GetBuffer(Wstr.GetLength()), Wstr.GetLength() * 2, 1, WriteF);
			fclose(WriteF);
		}
		*/
		Wstr += szContent;
		Wstr += L",";

		if(_tcslen(szContent) > 0)
			m_civicBirthday.SetWindowText(strVal);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleBirthday函数找不到"));
	}

	if(CVR_GetPeopleAddress)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleAddress((BYTE*)szContent, &nLen);
		strVal = _T("地址：");
		strVal += szContent;
		/*
		WriteF = NULL;
		WriteF = fopen("cv03.txt", "w+");
		Wstr = szContent;
		if (WriteF)
		{
			fwrite(&UNICODE_TXT_FLG, 2, 1, WriteF);
			fwrite(Wstr.GetBuffer(Wstr.GetLength()), Wstr.GetLength() * 2, 1, WriteF);
			fclose(WriteF);
		}
		*/
		/*
		Wstr = szContent;
		CFile file;
		file.Open(L"cv03.txt", CFile::modeCreate | CFile::modeWrite);
		file.SeekToBegin();
		WORD unicode = 0xFEFF; //UNICODE編碼文件頭
		file.Write(&unicode, 2);//file.Write(&unicode, 2);
		file.Write(Wstr, Wstr.GetLength() * 2);
		file.Flush();
		file.Close();
		*/
		Wstr += szContent;
		Wstr += L",";

		if(_tcslen(szContent) > 0)
			m_civicAddress.SetWindowText(strVal);
	}
	else
	{
		AfxMessageBox(_T("GetPeopleAddress函数找不到"));
	}

	if(CVR_GetPeopleIDCode)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetPeopleIDCode((BYTE*)szContent, &nLen);
		strVal = _T("证件号码：");
		strVal += szContent;
		/*
		WriteF = NULL;
		WriteF = fopen("cv04.txt", "w+");
		Wstr = szContent;
		if (WriteF)
		{
			fwrite(&UNICODE_TXT_FLG, 2, 1, WriteF);
			fwrite(Wstr.GetBuffer(Wstr.GetLength()), Wstr.GetLength() * 2, 1, WriteF);
			fclose(WriteF);
		}
		*/
		Wstr += szContent;

		if(_tcslen(szContent) > 0)
			m_civicCardID.SetWindowText(strVal);
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
		strVal = _T("签发机关：");
		strVal += szContent;
		if(_tcslen(szContent) > 0)
			m_civicDepartment.SetWindowText(strVal);
	}
	else
	{
		AfxMessageBox(_T("GetDepartment函数找不到"));
	}

	if(CVR_GetStartDate && CVR_GetEndDate)
	{
		CString strStart, strEnd, strResult;
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetStartDate((BYTE*)szContent, &nLen);
		strStart = szContent;
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetEndDate((BYTE*)szContent, &nLen);
		strEnd = szContent;
		strResult = strStart + _T("-") + strEnd;
		strVal = _T("有效期限：");
		strVal += strResult;
		if(_tcslen(szContent) > 0)
			m_civicValidDate.SetWindowText(strVal);
	}
	else
	{
		AfxMessageBox(_T("GetStartDate或GetEndDate函数找不到"));
	}
	if (CVR_GetNationCode)
	{
		nLen = sizeof(szContent);
		memset(szContent, 0, sizeof(szContent));
		CVR_GetNationCode((BYTE*)szContent, &nLen);
		CString strVal;
		strVal = _T("民族代码：");
		strVal += szContent;
		m_civicNationCode.SetWindowText(strVal);
	}

	if (CVR_GetNewAppAddressU)
	{
		TCHAR szData[128] = {0};
		int nSize = sizeof(szData);
		int nRet = CVR_GetNewAppAddressU((BYTE*)szData, &nSize);
		nRet = 0;
	}

	////////////////////////////////////////////显示照片
	ShowPhoto(IDC_STATIC_PHOTO2);
	if (Wstr.GetLength()>4)
	{
		//---
		CFile file;
		file.Open(L"cv.txt", CFile::modeCreate | CFile::modeWrite);
		file.SeekToBegin();
		WORD unicode = 0xFEFF; //UNICODE編碼文件頭
		file.Write(&unicode, 2);//file.Write(&unicode, 2);
		file.Write(Wstr, Wstr.GetLength() * 2);
		file.Flush();
		file.Close();
		//---

		//---
		PictureSave(IDC_STATIC_PHOTO2);
		//---

		//----
		OnBnClickedReadIdCard();
		//----
	}
	
}


void CIdCardDlg::ShowPhoto(int nPhotoID)
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
			graph.DrawImage(m_pBmp, rect.left, rect.top, 0, 0, cx, cy, UnitPixel);
		}
		delete[] pBmpData;
	}
}

void CIdCardDlg::ReadCard()
{
	int iRetUSB = 0,iRetCOM = 0;
	DWORD dwStart = ::GetTickCount();
	CStatic * pStTime = (CStatic*)GetDlgItem(IDC_STATIC_TIME_CIVIC);
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


	if( iRetCOM == 1 || iRetUSB == 1 )
	{
		if (CVR_GetSAMID)
		{
			wchar_t szSamID[256] = {0};
			CStatic * stSamID = (CStatic*)GetDlgItem(IDC_SAM_ID_CIVIC);
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
				OnLoadCivicPic();
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
			OnLoadCivicPic();
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

void CIdCardDlg::OnBnClickedReadIdCard()
{
	// TODO: Add your control notification handler code here
	CButton * pRead = (CButton*)GetDlgItem(ID_READ_ID_CARD);
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
			m_nTimerEvent = this->SetTimer(IDCARD_TIMER_EVENT, m_nTimer, NULL);
			pRead->SetWindowText(_T("停止读身份证"));
		}
		else if(m_nTimer == 0)
			ReadCard();
		else
			AfxMessageBox(_T("读卡间隔最好大于500毫秒"));
	}
}

BOOL CIdCardDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class

	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE ) return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}

void CIdCardDlg::SetReadParam(int nPort, int nTimer, int nRepeat)
{
	m_nPort = nPort;
	m_nTimer = nTimer;
	m_nRepeat = nRepeat;
	m_bParamChanged = TRUE;
}


void CIdCardDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default

	if (nIDEvent == IDCARD_TIMER_EVENT)
	{
		ReadCard();
	}
	CDialog::OnTimer(nIDEvent);
}

void CIdCardDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: Add your message handler code here
	// Do not call CDialog::OnPaint() for painting messages
	Graphics graph(m_hWnd);
	if (m_pBmp)
	{
		CRect rect;
		int cx = m_pBmp->GetWidth(), cy = m_pBmp->GetHeight();
		GetDlgItem(IDC_STATIC_PHOTO2)->GetWindowRect(&rect);
		ScreenToClient(&rect);
		GetDlgItem(IDC_STATIC_PHOTO2)->MoveWindow(rect.left, rect.top, cx, cy, true);//调整大小	
		graph.DrawImage(m_pBmp, rect.left, rect.top, 0, 0, cx, cy, UnitPixel);
	}
}

BOOL CIdCardDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	CRect rect;
	GetDlgItem(IDC_STATIC_PHOTO2)->GetWindowRect(&rect);
	rect.right = rect.left + 102;
	rect.bottom = rect.top + 126;
	ScreenToClient(&rect);
	GetDlgItem(IDC_STATIC_PHOTO2)->MoveWindow(rect, true);//调整大小	
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
