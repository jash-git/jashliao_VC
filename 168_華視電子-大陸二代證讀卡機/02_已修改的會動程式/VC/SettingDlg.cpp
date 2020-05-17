// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyStatic.h"
#include "SettingDlg.h"


// CSettingDlg dialog

#define CVR_APP _T("设置")
#define PORT_NUM_KEY _T("端口号")
#define AUTO_READ_CARD_KEY _T("自动读卡")
#define REPEAT_READ_CARD_KEY _T("重复读卡")
#define READ_CARD_TIMER_KEY _T("读卡间隔")


IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)
{
	m_nPort = -1;
	m_nTimer = -1;
	m_nRepeat = FALSE;
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
	ON_BN_CLICKED(IDC_BUTTON_SAVE_CONFIG, &CSettingDlg::OnBnClickedButtonSaveConfig)
	ON_BN_CLICKED(IDC_RADIO_AUTO_PORT, &CSettingDlg::OnBnClickedRadioAutoPort)
	ON_BN_CLICKED(IDC_RADIO_USB, &CSettingDlg::OnBnClickedRadioUsb)
	ON_BN_CLICKED(IDC_RADIO_SERIAL_PORT, &CSettingDlg::OnBnClickedRadioSerialPort)
END_MESSAGE_MAP()


// CSettingDlg message handlers

BOOL CSettingDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here

	int nPortNum		= -1;
	int nAutoRead		= -1;
	int nRepeatRead		= -1;
	int nReadTimer		= -1;

	CString strFileName = GetMoudulePath();
	strFileName += L"config.ini";
	if (_taccess(strFileName, 0) == 0)
	{
		nPortNum = this->GetSaveSetting(SIT_PORT_NO);
		nAutoRead = this->GetSaveSetting(SIT_AUTO_READ);
		nRepeatRead = this->GetSaveSetting(SIT_REPEAT_READ);
		nReadTimer = this->GetSaveSetting(SIT_READ_TIME);
	}
	else
	{
		nPortNum = this->GetDefaultSetting(SIT_PORT_NO);
		nAutoRead = this->GetDefaultSetting(SIT_AUTO_READ);
		nRepeatRead = this->GetDefaultSetting(SIT_REPEAT_READ);
		nReadTimer = this->GetDefaultSetting(SIT_READ_TIME);
	}

	m_nPort = nPortNum;
	m_nTimer = nReadTimer;
	m_nRepeat = nRepeatRead;

	CButton * pChooseAuto	= (CButton*)GetDlgItem(IDC_RADIO_AUTO_PORT);
	CButton * pChooseUsb	= (CButton*)GetDlgItem(IDC_RADIO_USB);
	CButton * pAutoRead		= (CButton*)GetDlgItem(IDC_CHECK_AUTO_READ);
	CButton * pRepeatRead	= (CButton*)GetDlgItem(IDC_CHECK_REPEAT);
	CButton * pChooseSerial	= (CButton*)GetDlgItem(IDC_RADIO_SERIAL_PORT);
	CComboBox * pCombUsbPorts		= (CComboBox*)GetDlgItem(IDC_COMBO_USB);
	CComboBox * pCombSerialPorts	= (CComboBox*)GetDlgItem(IDC_COMBO_SERIAL);
	CEdit * pTimer = (CEdit*)GetDlgItem(IDC_EDIT_TIMER);

	if (pChooseAuto && pChooseUsb && pChooseSerial && pCombUsbPorts && 
		pCombSerialPorts && pAutoRead && pRepeatRead && pTimer)
	{
		pCombUsbPorts->SetCurSel(0);
		pCombSerialPorts->SetCurSel(0);
		if (nPortNum == AutoPort)
		{
			pChooseAuto->SetCheck(BST_CHECKED);
			pChooseUsb->SetCheck(BST_UNCHECKED);
			pChooseSerial->SetCheck(BST_UNCHECKED);
			pCombUsbPorts->EnableWindow(FALSE);
			pCombSerialPorts->EnableWindow(FALSE);
		}
		else if (nPortNum >= UsbPort1 && nPortNum <= UsbPort16)
		{
			pCombUsbPorts->SetCurSel(nPortNum-1001);
			pChooseAuto->SetCheck(BST_UNCHECKED);
			pChooseUsb->SetCheck(BST_CHECKED);
			pChooseSerial->SetCheck(BST_UNCHECKED);
			pCombUsbPorts->EnableWindow(TRUE);
			pCombSerialPorts->EnableWindow(FALSE);
		}
		else if (nPortNum >= ComPort1 && nPortNum <= ComPort16)
		{
			pCombSerialPorts->SetCurSel(nPortNum-1);
			pChooseAuto->SetCheck(BST_UNCHECKED);
			pChooseUsb->SetCheck(BST_UNCHECKED);
			pChooseSerial->SetCheck(BST_CHECKED);
			pCombUsbPorts->EnableWindow(FALSE);
			pCombSerialPorts->EnableWindow(TRUE);
		}
		if (nAutoRead == TRUE)
			pAutoRead->SetCheck(BST_CHECKED);
		else
			pAutoRead->SetCheck(BST_UNCHECKED);
		if (nRepeatRead == TRUE)
			pRepeatRead->SetCheck(BST_CHECKED);
		else
			pRepeatRead->SetCheck(BST_UNCHECKED);

		CString strTimer;
		strTimer.Format(_T("%d"), nReadTimer);
		pTimer->SetWindowText(strTimer);
	}



	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

int CSettingDlg::GetDefaultSetting(int nItem)
{
	int nRet = -1;
	switch(nItem)
	{
	case SIT_PORT_NO:
		nRet = UsbPort1;
		break;
	case SIT_AUTO_READ:
		nRet = TRUE;
		break;
	case SIT_REPEAT_READ:
		nRet = TRUE;
		break;
	case SIT_READ_TIME:
		nRet = 500;
		break;
	default:
		break;
	}
	return nRet;
}

int CSettingDlg::GetSaveSetting(int nItem)
{
	int nRet = -1;
	switch(nItem)
	{
	case SIT_PORT_NO:
		GetSettingItem(CVR_APP, PORT_NUM_KEY, nRet);
		break;
	case SIT_AUTO_READ:
		GetSettingItem(CVR_APP, AUTO_READ_CARD_KEY, nRet);
		break;
	case SIT_REPEAT_READ:
		GetSettingItem(CVR_APP, REPEAT_READ_CARD_KEY, nRet);
		break;
	case SIT_READ_TIME:
		GetSettingItem(CVR_APP, READ_CARD_TIMER_KEY, nRet);
		break;
	default:
		break;
	}
	return nRet;
}

void CSettingDlg::OnBnClickedButtonSaveConfig()
{
	// TODO: Add your control notification handler code here
	CButton * pChooseAuto	= (CButton*)GetDlgItem(IDC_RADIO_AUTO_PORT);
	CButton * pChooseUsb	= (CButton*)GetDlgItem(IDC_RADIO_USB);
	CButton * pAutoRead		= (CButton*)GetDlgItem(IDC_CHECK_AUTO_READ);
	CButton * pRepeatRead	= (CButton*)GetDlgItem(IDC_CHECK_REPEAT);
	CButton * pChooseSerial	= (CButton*)GetDlgItem(IDC_RADIO_SERIAL_PORT);
	CComboBox * pCombUsbPorts		= (CComboBox*)GetDlgItem(IDC_COMBO_USB);
	CComboBox * pCombSerialPorts	= (CComboBox*)GetDlgItem(IDC_COMBO_SERIAL);
	CEdit * pTimer = (CEdit*)GetDlgItem(IDC_EDIT_TIMER);

	int nPort = -1;
	int nReadTimer = -1;
	BOOL bSave = TRUE;
	BOOL bAutoRead = FALSE;
	BOOL bRepeatRead = FALSE;
	if (pChooseAuto && pChooseUsb && pChooseSerial && pCombUsbPorts && 
		pCombSerialPorts && pAutoRead && pRepeatRead && pTimer)
	{
		if (pChooseAuto->GetCheck() == BST_CHECKED)
		{
			nPort = AutoPort;
			bSave = bSave && TRUE;
			SaveSettingItem(CVR_APP, PORT_NUM_KEY, nPort);
		}
		else
		{
			// 保存端口
			if (pChooseUsb->GetCheck() == BST_CHECKED)
			{
				nPort = pCombUsbPorts->GetCurSel() + 1001;
			}
			else if (pChooseSerial->GetCheck() == BST_CHECKED)
			{
				nPort = pCombSerialPorts->GetCurSel() + 1;
			}
			else
			{
				bSave = bSave && FALSE;
				AfxMessageBox(_T("端口选择不正确"));
			}
			SaveSettingItem(CVR_APP, PORT_NUM_KEY, nPort);
		}
		// 保存自动读卡
		if (pAutoRead->GetCheck() == BST_CHECKED)
			bAutoRead = TRUE;
		else
			bAutoRead = FALSE;
		SaveSettingItem(CVR_APP, AUTO_READ_CARD_KEY, bAutoRead);

		if (pRepeatRead->GetCheck() == BST_CHECKED)
			bRepeatRead = TRUE;
		else
			bRepeatRead = FALSE;
		SaveSettingItem(CVR_APP, REPEAT_READ_CARD_KEY, bRepeatRead);

		CString strTimer;
		pTimer->GetWindowText(strTimer);
		nReadTimer = _ttoi(strTimer);
		if(nReadTimer < 500)
		{
			bSave = bSave && FALSE;
			AfxMessageBox(_T("读卡间隔不建议小于500毫秒"));
		}
		else
		{
			if(bAutoRead)
				SaveSettingItem(CVR_APP, READ_CARD_TIMER_KEY, nReadTimer);
			else
			{
				strTimer = _T("0");
				pTimer->SetWindowText(strTimer);
				SaveSettingItem(CVR_APP, READ_CARD_TIMER_KEY, 0);
			}
		}
		if(bSave)
		{
			m_nPort = nPort;
			m_nTimer = nReadTimer;
			m_nRepeat = bRepeatRead;
			AfxMessageBox(_T("保存成功"));
		}
	}
}


void CSettingDlg::GetSettingItem(LPCTSTR lpszAppName, LPCTSTR lpszKeyName, int & nVal)
{
	CFile fIni;

	CString strFileName = GetMoudulePath();
	strFileName += L"config.ini";

	BOOL bOpen = fIni.Open(strFileName, CFile::modeNoTruncate|CFile::modeReadWrite|CFile::shareDenyNone);
	if(!bOpen)
		bOpen = fIni.Open(strFileName, CFile::modeCreate|CFile::modeReadWrite|CFile::shareDenyNone);
	if(!bOpen) return;

	TCHAR szValue[MAX_PATH] = {0};
	DWORD dwLen = GetPrivateProfileString(lpszAppName, lpszKeyName, NULL, szValue, MAX_PATH, strFileName);
	if(dwLen == 0) 
	{
		fIni.Close();
		return;
	}

	if(_tcslen(szValue) > 0)
		nVal = _ttoi(szValue);

	fIni.Close();
}

CString CSettingDlg::GetMoudulePath()
{
	CString strRetun = L"";

	HMODULE module = AfxGetInstanceHandle();
	if (module == NULL)
	{
		return _T("");
	}
	wchar_t szBuff[MAX_PATH];
	GetModuleFileName(module, szBuff, sizeof(szBuff));

	wchar_t acBuf[200];
	GetShortPathName(szBuff, acBuf, 200);
	wchar_t acText[200];
	GetLongPathName(acBuf, acText, 200);

	CString strTemp(acBuf);
	strTemp = acText;
	int n = strTemp.ReverseFind('\\');
	strRetun = strTemp.Mid(0, n+1);

	return strRetun;
}

void CSettingDlg::SaveSettingItem(LPCTSTR lpszAppName, LPCTSTR lpszKeyName, int nVal)
{
	CFile fIni;

	CString strFileName = GetMoudulePath();
	strFileName += L"config.ini";

	BOOL bOpen = fIni.Open(strFileName, CFile::modeNoTruncate|CFile::modeReadWrite|CFile::shareDenyNone);
	if(!bOpen)
		bOpen = fIni.Open(strFileName, CFile::modeCreate|CFile::modeReadWrite|CFile::shareDenyNone);
	if(!bOpen) return;

	CString strVal;
	strVal.Format(_T("%d"), nVal);
	DWORD dwLen = WritePrivateProfileString(lpszAppName, lpszKeyName, strVal, strFileName);
	if(dwLen == 0) 
	{
		fIni.Close();
		return;
	}


	fIni.Close();
}
void CSettingDlg::OnBnClickedRadioAutoPort()
{
	// TODO: Add your control notification handler code here
	CButton * pChooseAuto	= (CButton*)GetDlgItem(IDC_RADIO_AUTO_PORT);
	CButton * pChooseUsb	= (CButton*)GetDlgItem(IDC_RADIO_USB);
	CButton * pChooseSerial	= (CButton*)GetDlgItem(IDC_RADIO_SERIAL_PORT);
	CComboBox * pCombUsbPorts		= (CComboBox*)GetDlgItem(IDC_COMBO_USB);
	CComboBox * pCombSerialPorts	= (CComboBox*)GetDlgItem(IDC_COMBO_SERIAL);

	if (pChooseAuto && pChooseUsb && pChooseSerial && pCombUsbPorts && pCombSerialPorts)
	{
		pChooseAuto->SetCheck(BST_CHECKED);
		pChooseUsb->SetCheck(BST_UNCHECKED);
		pChooseSerial->SetCheck(BST_UNCHECKED);
		pCombUsbPorts->EnableWindow(FALSE);
		pCombSerialPorts->EnableWindow(FALSE);
	}
}

void CSettingDlg::OnBnClickedRadioUsb()
{
	// TODO: Add your control notification handler code here
	CButton * pChooseAuto	= (CButton*)GetDlgItem(IDC_RADIO_AUTO_PORT);
	CButton * pChooseUsb	= (CButton*)GetDlgItem(IDC_RADIO_USB);
	CButton * pChooseSerial	= (CButton*)GetDlgItem(IDC_RADIO_SERIAL_PORT);
	CComboBox * pCombUsbPorts		= (CComboBox*)GetDlgItem(IDC_COMBO_USB);
	CComboBox * pCombSerialPorts	= (CComboBox*)GetDlgItem(IDC_COMBO_SERIAL);

	if (pChooseAuto && pChooseUsb && pChooseSerial && pCombUsbPorts && pCombSerialPorts)
	{
		pChooseAuto->SetCheck(BST_UNCHECKED);
		pChooseUsb->SetCheck(BST_CHECKED);
		pChooseSerial->SetCheck(BST_UNCHECKED);
		pCombUsbPorts->EnableWindow(TRUE);
		pCombSerialPorts->EnableWindow(FALSE);
	}
}

void CSettingDlg::OnBnClickedRadioSerialPort()
{
	// TODO: Add your control notification handler code here
	CButton * pChooseAuto	= (CButton*)GetDlgItem(IDC_RADIO_AUTO_PORT);
	CButton * pChooseUsb	= (CButton*)GetDlgItem(IDC_RADIO_USB);
	CButton * pChooseSerial	= (CButton*)GetDlgItem(IDC_RADIO_SERIAL_PORT);
	CComboBox * pCombUsbPorts		= (CComboBox*)GetDlgItem(IDC_COMBO_USB);
	CComboBox * pCombSerialPorts	= (CComboBox*)GetDlgItem(IDC_COMBO_SERIAL);

	if (pChooseAuto && pChooseUsb && pChooseSerial && pCombUsbPorts && pCombSerialPorts)
	{
		pChooseAuto->SetCheck(BST_UNCHECKED);
		pChooseUsb->SetCheck(BST_UNCHECKED);
		pChooseSerial->SetCheck(BST_CHECKED);
		pCombUsbPorts->EnableWindow(FALSE);
		pCombSerialPorts->EnableWindow(TRUE);
	}
}

BOOL CSettingDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	if(pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE ) return TRUE;
	return CDialog::PreTranslateMessage(pMsg);
}
