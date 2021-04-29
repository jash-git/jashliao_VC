/***************************************************************
 * Name:      wx_ch02App.cpp
 * Purpose:   Code for Application Class
 * Author:    jash.liao (jash.liao@gmail.com)
 * Created:   2014-09-15
 * Copyright: jash.liao (http://jashliao.pixnet.net/blog)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wx_ch02App.h"
#include "wx_ch02Main.h"

IMPLEMENT_APP(wx_ch02App);

bool wx_ch02App::OnInit()
{
    
    wx_ch02Dialog* dlg = new wx_ch02Dialog(0L, _("wxWidgets Application Template"));
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
