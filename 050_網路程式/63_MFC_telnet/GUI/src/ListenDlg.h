#pragma once
#include "afxwin.h"


// CListenDlg dialog

class CListenDlg : public CDialog
{
        DECLARE_DYNAMIC(CListenDlg)

public:
        CListenDlg(CWnd* pParent = NULL);   // standard constructor
        virtual ~CListenDlg();

// Dialog Data
        enum { IDD = IDD_LISTEN_DIALOG };

protected:
        virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

        DECLARE_MESSAGE_MAP()
public:
        UINT m_Port;
private:
        CEdit m_Edit;
public:
        virtual BOOL OnInitDialog();
};
