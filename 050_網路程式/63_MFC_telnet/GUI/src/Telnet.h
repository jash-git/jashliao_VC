// Telnet.h : main header file for the Telnet application
//
#pragma once

#ifndef __AFXWIN_H__
#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CTelnetApp:
// See Telnet.cpp for the implementation of this class
//

class CTelnetApp : public CWinApp
{
        CMultiDocTemplate* pClientDocTemplate;
        CMultiDocTemplate* pServerDocTemplate;

public:
        bool wsaStarted;
        WSADATA wsaData;
        CStringList m_addrList;

        CTelnetApp();


// Overrides
public:
        virtual BOOL InitInstance();

// Implementation
        afx_msg void OnAppAbout();
        DECLARE_MESSAGE_MAP()
        virtual int ExitInstance();
        afx_msg void OnClntNew();
        afx_msg void OnServNew();
};

extern CTelnetApp theApp;