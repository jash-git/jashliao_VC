/***************************************
*                                      *
*           OUTLOOK-LIKE BAR           *
*                                      *
*             Written by               *
*           Massimo Guccione           *
*            Multimedia Lab            *
*       Intersiel S.p.A. (W)1999       *
*                                      *
* Important: to use this script don't  *
*            remove these comments     *
*                                      *
* Version 1.0Beta Freeware (MSIE only) *
*                                      *
* mail : m.guccione@telcal.it          *
*        obyone@antares.it             *
*        please report for bugs        *
*                                      *
*  for both Netscape and MSIE version  *
*  contact me! (freeware of course)    *
****************************************/


/********************************************
folder name must be OutBarFolder# where # start with 1 and increase by 1
first element of array is the folder label, next elements are :
1) url for icon of item
2) label for item
3) action link : put 'javascript:MyFunction()' to execute javascript instead of hyperlink
4) target frame : ignored if you use 'javascript:' in the action link (use 'window' instead of 'parent.MAIN' if you wish the link to load in the CURRENT page
********************************************/

OutBarFolder1=new Array(
"Folder 1",
"mail.gif","Try this link","javascript:fnCallFunction()","parent.MAIN",
"chat.gif","Chat","javascript:Run(2)","",
"news.gif","Newsgroup","javascript:Run(3)","",
"netm.gif","Netmeeting","javascript:Run(4)",""
);

OutBarFolder2=new Array(
"Folder 2",
"word.gif","Word","javascript:Run(5)","",
"excel.gif","Excel","javascript:Run(6)","",
"ppt.gif","Powerpoint","javascript:Run(7)","",
"access.gif","Access","javascript:Run(8)","",
"peditor.gif","Photo Editor","javascript:Run(9)",""
);

OutBarFolder3=new Array(
"Folder 3",
"word.gif","Word","javascript:Run(5)","",
"ppt.gif","Powerpoint","javascript:Run(7)",""
);

OutBarFolder4=new Array(
"Folder 4",
"mail.gif","E-Mail","javascript:Run(1)","",
"chat.gif","Chat","javascript:Run(2)","",
"news.gif","Newsgroup","javascript:Run(3)","",
"netm.gif","Netmeeting","javascript:Run(4)","",
"word.gif","Word","javascript:Run(5)","",
"excel.gif","Excel","javascript:Run(6)","",
"ppt.gif","Powerpoint","javascript:Run(7)","",
"access.gif","Access","javascript:Run(8)","",
"peditor.gif","Photo Editor","javascript:Run(9)",""
);


