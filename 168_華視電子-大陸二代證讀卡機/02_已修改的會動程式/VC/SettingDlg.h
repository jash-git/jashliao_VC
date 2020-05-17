#pragma once


// CSettingDlg dialog

class CSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CSettingDlg();

// Dialog Data
	enum { IDD = IDD_SETTINGDLG };

public:
	enum SettingItem
	{
		AutoPort		= 0,
		ComPort1		= 1,
		ComPort2		= 2,
		ComPort3		= 3,
		ComPort4		= 4,
		ComPort5		= 5,
		ComPort6		= 6,
		ComPort7		= 7,
		ComPort8		= 8,
		ComPort9		= 9,
		ComPort10		= 10,
		ComPort11		= 11,
		ComPort12		= 12,
		ComPort13		= 13,
		ComPort14		= 14,
		ComPort15		= 15,
		ComPort16		= 16,
		UsbPort1		= 1001,
		UsbPort2		= 1002,
		UsbPort3		= 1003,
		UsbPort4		= 1004,
		UsbPort5		= 1005,
		UsbPort6		= 1006,
		UsbPort7		= 1007,
		UsbPort8		= 1008,
		UsbPort9		= 1009,
		UsbPort10		= 1010,
		UsbPort11		= 1011,
		UsbPort12		= 1012,
		UsbPort13		= 1013,
		UsbPort14		= 1014,
		UsbPort15		= 1015,
		UsbPort16		= 1016
	};

	enum SettingItemType
	{
		SIT_PORT_NO = 2,
		SIT_AUTO_READ = 3,
		SIT_REPEAT_READ = 4,
		SIT_READ_TIME = 5
	};

public:
	int m_nPort;
	int m_nTimer;
	BOOL m_nRepeat;

protected:
	int GetDefaultSetting(int nItem);
	int GetSaveSetting(int nItem);
	void GetSettingItem(LPCTSTR lpszAppName, LPCTSTR lpszKeyName, int & nVal);
	void SaveSettingItem(LPCTSTR lpszAppName, LPCTSTR lpszKeyName, int nVal);

	CString GetMoudulePath();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonSaveConfig();
	afx_msg void OnBnClickedRadioAutoPort();
	afx_msg void OnBnClickedRadioUsb();
	afx_msg void OnBnClickedRadioSerialPort();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
