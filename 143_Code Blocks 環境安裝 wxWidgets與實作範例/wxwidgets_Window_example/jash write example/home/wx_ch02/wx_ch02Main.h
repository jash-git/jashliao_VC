/***************************************************************
 * Name:      wx_ch02Main.h
 * Purpose:   Defines Application Frame
 * Author:    jash.liao (jash.liao@gmail.com)
 * Created:   2014-09-15
 * Copyright: jash.liao (http://jashliao.pixnet.net/blog)
 * License:
 **************************************************************/

#ifndef WX_CH02MAIN_H
#define WX_CH02MAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "wx_ch02App.h"


#include <wx/button.h>
#include <wx/statline.h>
class wx_ch02Dialog: public wxDialog
{
    public:
        wx_ch02Dialog(wxDialog *dlg, const wxString& title);
        ~wx_ch02Dialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // WX_CH02MAIN_H
