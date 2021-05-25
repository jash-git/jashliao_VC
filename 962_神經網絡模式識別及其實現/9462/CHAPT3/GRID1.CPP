// PM Interface for stroke data base!

#define INCL_WIN
#define INCL_GPI
#define INCL_GPIPRIMATIVES
#define INCL_WINDIALOGS
#define MSGID ULONG

#include <os2.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "misclib.h"
#include "grid1.h"
#include "rasheadr.h"


void UtilShow2(HWND hwnd, char *sx, char *sy,int x, int y);
void UtilShow1(HWND hwnd, char *sx, int x);
void UtilShow1C(HWND hwnd, char *sx, unsigned char x);


// EXTERNAL CLASS DEFS & STRUCTS



// Internal function prototypes

MRESULT EXPENTRY clientproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );
MRESULT EXPENTRY ColorDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );
MRESULT EXPENTRY LoadWtDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );
SHORT minimum(SHORT,SHORT);
SHORT maximum(SHORT,SHORT);



//------------------------------------------------------------------
// GRID CLASS DEFINITION
//------------------------------------------------------------------
#include "gridclas.cpp"


int main ( int argc, char *argv[] );
VOID error ( PSZ psz );

// global variables 

    HWND    hwndClient;        // client window handle
    HWND    hwndFrame;         // frame window handle


int main ( int argc, char *argv[] )
{
    HAB     hab;               // anchor block handle
    HMQ     hmq;               // message queue handle
    QMSG    qmsg;              // message from message queue
    ULONG   flCreate;          // window creation control flags
    BOOL    fSuccess;          // return from API
    BYTE   *szParentName;


    szParentName = new BYTE[strlen("Parent")+1];
    strcpy((char *)szParentName, "Parent");

    static CHAR *MSG1R="CANNOT REGISTER PARENT";
    static CHAR *MSG1C="CANNOT CREATE PARENT";

    hab = WinInitialize ( 0 );
    hmq = WinCreateMsgQueue ( hab, 0 );

    fSuccess = WinRegisterClass(
       hab,                  // Anchor block handle
       szParentName,         // Window class name
       (PFNWP)clientproc,    // Address of window procedure
       0,                    // No special Class Style
       0                     // No extra window words
       );
    if ( fSuccess == FALSE )
        error ( (PSZ)MSG1R);


    flCreate =FCF_TITLEBAR |FCF_SYSMENU |FCF_MENU | FCF_SIZEBORDER | 
                      FCF_MINMAX |FCF_SHELLPOSITION |FCF_TASKLIST;

    static CHAR *ParTitBar="STROKE DATA DISPLAY TOOL.";
    hwndFrame = WinCreateStdWindow(
         HWND_DESKTOP,  // Desktop window is parent
         WS_VISIBLE,    // Frame Window Style
         &flCreate,     // Frame creation flag
         szParentName,  // Client window class name
         (PSZ)ParTitBar,// Title bar text
         0L,            // No special class style
         0,             // Resource is in .EXE file
         ID_LAB1,       // Frame window identifier 
         &hwndClient    // Client window handle
         );
    if ( hwndFrame == 0 )
        error ( (PSZ)MSG1C );

    WinSendMsg(hwndFrame, WM_SETICON,
               (MPARAM)WinQuerySysPointer(HWND_DESKTOP, SPTR_APPICON, FALSE),
               MPFROM2SHORT(0,0) );


    WinSetWindowPos( hwndFrame, HWND_TOP,
                      10, 10, 400, 450,
                      SWP_MAXIMIZE);

    while ( WinGetMsg ( hab, &qmsg, (HWND)0, 0, 0 ) != FALSE )
        WinDispatchMsg ( hab, &qmsg );

    WinDestroyWindow ( hwndFrame );
    WinDestroyMsgQueue ( hmq );
    WinTerminate ( hab );
    return 0;
}

//*******************************************************************
MRESULT EXPENTRY clientproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 )
{
    HPS     hps;                // cached PS handle
    BOOL    fSuccess;           // return from API

    static  PSZ      pszString;
    RECTL            rcl;
    unsigned char    ChActive;      // Current grid character
    static  int      MousePaintFlg=0;
    static long      BakColor=CLR_DARKGRAY;

    switch( msg )
    {
        case WM_CLOSE:
            WinPostMsg( hwnd, WM_QUIT, 0L, 0L );
            return (MRESULT)0;

        case WM_CREATE:
            grid.SetHandle(hwnd);
            return (MRESULT)FALSE;

        case WM_PAINT:
            hps = WinBeginPaint ( hwnd, NULLHANDLE, (PRECTL)NULL );
            if(BakColor==15)
              GpiErase(hps);
            else {
               GpiSetBackMix(hps,BM_OVERPAINT);
               GpiSetColor(hps,CLR_WHITE);
               GpiSetBackColor(hps,BakColor);
               WinQueryWindowRect(hwnd,&rcl);
               fSuccess=WinFillRect(hps, &rcl, BakColor);
               }
            grid.Show(hps);
            WinEndPaint ( hps );
            return (MRESULT)0;

        case WM_ACTIVATE:
            grid.SetSize();
            return (MRESULT)0;
        case WM_SIZE:
            grid.SetSize();
            WinQueryWindowRect(hwnd,&rcl);
            return (MRESULT)0;


        case WM_COMMAND:
            switch (COMMANDMSG(&msg)->cmd) {
//               case IDM_RLC:
//                  WinMessageBox(
//                       HWND_DESKTOP, hwnd,
//                       (PSZ)("VIEW OF RLC MATRIX MAX X-DIMENSION"),
//                       (PSZ)("PARENT"),
//                       0, MB_OK | MB_ICONASTERISK );
//                  UtilShow1(hwnd, "Max RLC matrix x-dimension: ", grid.QueryRLCsize());
//                  return (MRESULT)0;
               case IDM_LOADIMAGE:
                  if (WinDlgBox(HWND_DESKTOP, hwnd, LoadWtDlgproc,
                                   NULLHANDLE, IDD_NETFILE, NULL)) {
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     }
                   else {
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     }
                  return (MRESULT)0;


               case IDM_COLORS:
                  if (WinDlgBox(HWND_DESKTOP, hwnd, ColorDlgproc,
                                   NULLHANDLE, IDD_COLORS, NULL)) {
                     BakColor=grid.SetNextColr();
                     }
                   else {
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     }

                  MousePaintFlg=0;
                  WinQueryWindowRect(hwnd,&rcl);     //GET AREA     
                  WinInvalidateRect(hwnd,&rcl,TRUE); //FORCE A PAINT
                  return (MRESULT)0;

               case IDM_EXITNOW:
                  WinPostMsg( hwnd, WM_QUIT, 0L, 0L );
                  return (MRESULT)0;

               default:;
               } /* endswitch */
            return (MRESULT)0;
        default:
            return WinDefWindowProc( hwnd, msg, mp1, mp2 );
    }
    return WinDefWindowProc ( hwnd, msg, mp1, mp2 );
}

//******************************************************************* */

MRESULT EXPENTRY ColorDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 )
{
   int FgColr;
   int BkColr;
   int CtlID;
    switch( msg )
       {
       case WM_INITDLG:
            BkColr = grid.QueryBackColr()+300;
            WinSendDlgItemMsg(hwnd,BkColr, BM_SETCHECK,
                              MPFROM2SHORT(TRUE,0), NULL);
            FgColr = grid.QueryForgColr()+200;
            WinSendDlgItemMsg(hwnd,FgColr, BM_SETCHECK,
                              MPFROM2SHORT(TRUE,0), NULL);
            return (MRESULT)1;
       case WM_CONTROL:
          CtlID= SHORT1FROMMP (mp1);
          if ((CtlID>=IDD_FCLRBLUE) && (CtlID<=IDD_FCLRPLGRAY)) {
             grid.NextForgColr(CtlID-200);
             return (MRESULT)0; 
             }
            else {
             if ((CtlID>=IDD_BCLRBLUE) && (CtlID<=IDD_BCLRPLGRAY)) {
                grid.NextBackColr(CtlID-300);
                return (MRESULT)0;
                } 
               else {
                } /* endif */
             } /* endif */
          return (MRESULT)0;

       case WM_COMMAND:
            switch (SHORT1FROMMP( mp1 ) )
                {
                case DLG_OK:
                     WinDismissDlg(hwnd, TRUE);
                     return (MRESULT)0;
                case DLG_CANCEL:
                     grid.ResetColrDirty();
                     WinDismissDlg(hwnd, FALSE);
                     return (MRESULT)0;
                } /* endswitch */
       break;
       } /* endswitch */
    return WinDefDlgProc(hwnd,msg,mp1,mp2);
}   

//******************************************************************* */
union kluge {
   USHORT       sSelect;
   MRESULT      mres;
   }   dlgrc;

MRESULT EXPENTRY LoadWtDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 )
{
    static CHAR szFnameBuff[80];
    HDIR         hDir=1;
    FILEFINDBUF3 FindBuf;
    ULONG        usSearchCount=1;
    UINT         rc;
    int          ndeb;

    switch( msg )
       {
       case WM_INITDLG:
            WinSendDlgItemMsg(hwnd, IDD_FLIST, LM_DELETEALL,NULL,NULL);
            ndeb=0;
            rc=DosFindFirst((PSZ)("*.RAS"), &hDir, 0x0000L, (PVOID)&FindBuf,
                            (ULONG)(sizeof FindBuf), &usSearchCount, FIL_STANDARD);
            while ((rc==0) && (usSearchCount != 0)) {
               WinSendDlgItemMsg(hwnd, IDD_FLIST, LM_INSERTITEM,
                             MPFROM2SHORT(LIT_SORTASCENDING,0),
                             MPFROMP(FindBuf.achName));
               rc=DosFindNext(hDir, (PVOID)&FindBuf, (ULONG)(sizeof FindBuf),
                              &usSearchCount );
               ndeb++;
               }
 
            WinSendDlgItemMsg(hwnd, IDD_FLEDIT, EM_SETTEXTLIMIT,
                              MPFROM2SHORT(80, 0),NULL);
            break;
       case WM_CONTROL:
            if (SHORT1FROMMP(mp1) == IDD_FLIST) {
               dlgrc.mres =  WinSendDlgItemMsg(hwnd, IDD_FLIST,
                             LM_QUERYSELECTION, 0L, 0L);
               WinSendDlgItemMsg(hwnd, IDD_FLIST,LM_QUERYITEMTEXT, 
                             MPFROM2SHORT(dlgrc.sSelect,sizeof(szFnameBuff)),
                             MPFROMP(szFnameBuff));
               switch (SHORT2FROMMP(mp1)) {
                  case LN_SELECT:
                     WinSetDlgItemText(hwnd, IDD_FLEDIT, (PSZ)szFnameBuff);
                     break;
                  case LN_ENTER:
                     WinQueryDlgItemText(hwnd, IDD_FLEDIT, 
                          sizeof szFnameBuff, (PSZ)szFnameBuff);
                     if ( grid.LoadRas(szFnameBuff)!=0)
                        WinDismissDlg(hwnd, TRUE);
                      else
                        WinMessageBox( HWND_DESKTOP, hwnd, (PSZ) szFnameBuff,
                          (PSZ)("ERROR: UNABLE TO OPEN"), 0, MB_OK|MB_ICONASTERISK);
                     break;
                     default:;
                  } /* endswitch */
               } /* endif */
            break;
       case WM_COMMAND:
            switch (SHORT1FROMMP( mp1 ) )
                {
                case DID_OK:
                     WinQueryDlgItemText(hwnd, IDD_FLEDIT, 
                          sizeof szFnameBuff, (PSZ)szFnameBuff);
                     if ( grid.LoadRas(szFnameBuff)!=0)
                        WinDismissDlg(hwnd, TRUE);
                      else
                        WinMessageBox( HWND_DESKTOP, hwnd, (PSZ) szFnameBuff,
                          (PSZ)("ERROR: UNABLE TO OPEN"), 0, MB_OK|MB_ICONASTERISK);
                     return (MRESULT)0;
                case DID_CANCEL:
                     WinMessageBox(
                         HWND_DESKTOP, hwnd,
                         (PSZ)("CHANGE IMAGE CANCELLED BY USER"),
                         (PSZ)("DIALOG"),
                         0, MB_OK | MB_ICONASTERISK );
                     WinDismissDlg(hwnd, FALSE);
                     return (MRESULT)0;
                } /* endswitch */
       break;
       } /* endswitch */
    return WinDefDlgProc(hwnd,msg,mp1,mp2);
}   




//*******************************************************************
// error: displays an error message
//*******************************************************************
VOID error ( PSZ psz )
{
    static CHAR *Error="Error";
    WinMessageBox ( HWND_DESKTOP, HWND_DESKTOP, psz, (PSZ)Error, 0
                  , MB_ERROR | MB_MOVEABLE | MB_OK );
    DosExit ( 1, 1 );
}


//*******************************************************************


// Informational message boxes

void UtilShow1(HWND hwnd, char *sx, int x){
   char Report[255], num1[10], *Rptr;
   Rptr=itoa(x,num1,10);
   strcpy(Report,sx);
   strcat(Report,Rptr);
   WinMessageBox(
                HWND_DESKTOP, hwnd,
                (PSZ)Report,
                (PSZ)("USER MESSAGE"),
                0, MB_OK | MB_ICONASTERISK );
}

void UtilShow1C(HWND hwnd, char *sx, unsigned char x){
   char Report[255], num1[10], *Rptr;
   ByteToHexString( x, num1);
   //Rptr=itoa(x,num1,10);
   strcpy(Report,sx);
   strcat(Report,num1);
   WinMessageBox(
                HWND_DESKTOP, hwnd,
                (PSZ)Report,
                (PSZ)("USER MESSAGE"),
                0, MB_OK | MB_ICONASTERISK );
}

void UtilShow2(HWND hwnd, char *sx, char *sy,int x, int y){
   char Report[255], num1[10], *Rptr;
   Rptr=itoa(x,num1,10);
   strcpy(Report,sx);
   strcat(Report,Rptr);
   Rptr=itoa(y,num1,10);
   strcat(Report,sy);
   strcat(Report,Rptr);
   WinMessageBox(
                HWND_DESKTOP, hwnd,
                (PSZ)Report,
                (PSZ)("USER MESSAGE"),
                0, MB_OK | MB_ICONASTERISK );
}

SHORT minimum(SHORT a,SHORT b){
   if (a<=b) {
      return a;
   } else {
      return b;
   } /* endif */
}
SHORT maximum(SHORT a,SHORT b){
   if (a>b) {
      return a;
   } else {
      return b;
   } /* endif */
}

