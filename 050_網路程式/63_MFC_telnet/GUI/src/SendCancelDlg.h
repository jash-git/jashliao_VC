#pragma once
#include "afxwin.h"

#include "Lib\Socket.h"

// CSendCancelDlg dialog

class CSendCancelDlg : public CDialog
{
        DECLARE_DYNAMIC(CSendCancelDlg)

public:
        CSendCancelDlg(Socket *, CWnd* pParent = NULL);   // standard constructor
        virtual ~CSendCancelDlg();

// Dialog Data
        enum { IDD = IDD_SENDCANCEL_DIALOG };

protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

        DECLARE_MESSAGE_MAP()
private:
        Socket *pclients;
        CListBox m_clientsList;

public:
        SOCKET m_clientSock;
        CString m_clientAddr;
        virtual BOOL OnInitDialog();

protected:
        virtual void OnOK();
};
