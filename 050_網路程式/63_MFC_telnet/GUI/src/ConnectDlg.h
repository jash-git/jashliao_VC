

#pragma once
#include "afxwin.h"


// CConnectDlg dialog

class CConnectDlg : public CDialog
{
        DECLARE_DYNAMIC(CConnectDlg)

public:
        CConnectDlg(CStringList *, CWnd* pParent = NULL);   // standard constructor
        virtual ~CConnectDlg();

// Dialog Data
        enum { IDD = IDD_CONNECT_DIALOG };

protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

        DECLARE_MESSAGE_MAP()
private:
        CStringList *addrs;
        CComboBox m_addrCombo;

public:
        virtual BOOL OnInitDialog();
        CString m_Address;
        DWORD m_Port;
};




