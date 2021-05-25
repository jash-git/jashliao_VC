// PM Interface for neural network character recognition system!

#define INCL_WIN
#define INCL_GPI
#define INCL_WINDIALOGS
#define MSGID ULONG
#include <os2.h>
#include <string.h>
#include <stdlib.h>
//#include <dos.h>
#include <stdio.h>
#include <math.h>

#include "misclib.h"
#include "grid1.h"
#include "m12chars.h"


void VarShow2(HWND hwnd, char *sx, char *sy,int x, int y);
void VarShow1(HWND hwnd, char *sx, int x);
void VarShow1C(HWND hwnd, char *sx, unsigned char x);

#include "qnet.cpp"


// EXTERNAL CLASS DEFS & STRUCTS
                
RECOSYS  Reco;  // 1 instance of class reco
                // This is the neural net recogniton system containing 10 nets

struct NETRESULTS  NetResBuf;
struct NETRESULTS *NetResPtr=&NetResBuf;

// Internal function prototypes

MRESULT EXPENTRY clientproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );
MRESULT EXPENTRY child1proc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );                           // THE CHARACTER GRID
MRESULT EXPENTRY child2proc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );                           // THE NETWORK PARMS
MRESULT EXPENTRY child3proc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );                           // ALL VALUES OF NET OUTPUT
MRESULT EXPENTRY ColorDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );
MRESULT EXPENTRY LoadWtDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );
MRESULT EXPENTRY GetAscDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 );
SHORT minimum(SHORT,SHORT);
SHORT maximum(SHORT,SHORT);


// global variables 1

FILE *LOGFILE;
char LogFileName[80];

//------------------------------------------------------------------
// CLASS DEFINITIONS
//------------------------------------------------------------------
#define GRIDXMAX 8
#define GRIDYMAX 12

class GRID {
   private:
      HWND          Ghwnd;
      RECTL         Grcl;       //PM's coords for the grid window
      int           Gactive;
      unsigned int  GforgColr;  // Curr active foreground color
      unsigned int  GbackColr;  //             background
      unsigned int  NxtFColr;   // Queued foreground color
      unsigned int  NxtBColr;   //        background      
      unsigned int  GRmatrix[GRIDXMAX][GRIDYMAX];
      int           BlockWidth();
      int           BlockHeight();
      int QueryPixelOn(int x, int y);
   public:
      GRID();
      void SetHandle(HWND hwnd){Ghwnd=hwnd;}
      void Activate(){Gactive=TRUE;}
      void Deactivate(){Gactive=FALSE;}
      int  IsActive(){return Gactive;}
      void Show(HPS hps);
      void SetSize();
      void LoadChar(unsigned char c);  // Std char => GRmatrix
      void MouseButt(int xCoord, int yCoord);
      void SetForgColr(unsigned int NewFcolr);
      void SetBackColr(unsigned int NewBcolr);
      void SetNextColr(void);
      int  QueryForgColr(){return GforgColr;}
      int  QueryBackColr(){return GbackColr;}
      void NextForgColr(unsigned int Fcolr){NxtFColr= Fcolr | 0x4000;} // b14=dirty
      void NextBackColr(unsigned int Bcolr){NxtBColr= Bcolr | 0x4000;}
      void ResetColrDirty(){NxtFColr= 0; NxtBColr= 0; }
      void RunNet(void);
      void SaveToLog(void);
   };


GRID grid;          // Global instance



GRID::GRID(){
   int x,y;
   Gactive=FALSE;
   NxtFColr= 0;
   NxtBColr= 0;
   GforgColr=CLR_RED;
   GbackColr=CLR_BLUE;
   for (x=0; x<GRIDXMAX; x++) {
      for (y=0; y<GRIDYMAX; y++) {
         GRmatrix[x][y]=GbackColr;
      } /* endfor */
   } /* endfor */
   // Open the default log file
   strcpy(LogFileName, "default.log");  // Quick & dirty for now...
   LOGFILE = fopen(LogFileName, "a");   // later add check for err path
}  



int GRID::QueryPixelOn(int x, int y){
   int PelFlag = GRmatrix[x][y] & 0x8000;
   if (PelFlag) {
      return 1;
   } else {
      return 0;
   } /* endif */
}

void GRID::SetForgColr(unsigned int NewFColr){
   int x,y;
   for (x=0; x<GRIDXMAX; x++) {
      for (y=0; y<GRIDYMAX; y++) {
         if (QueryPixelOn(x,y)) {
            GRmatrix[x][y]=NewFColr | 0x8000;
            } /* endif */
      } /* endfor */
   } /* endfor */
   GforgColr=NewFColr;
}

void GRID::SetBackColr(unsigned int NewBColr){
   int x,y;
   for (x=0; x<GRIDXMAX; x++) {
      for (y=0; y<GRIDYMAX; y++) {
         if (!QueryPixelOn(x,y)) {
            GRmatrix[x][y]=NewBColr;
            } /* endif */
      } /* endfor */
   } /* endfor */
   GbackColr=NewBColr;
}                            
                             
void GRID::SetNextColr(){
   if (NxtFColr & 0x4000 ) {        // Check dirty bit
      NxtFColr = NxtFColr & 0xbfff; // remove dirty bit
      SetForgColr(NxtFColr);
      } /* endif */
   if (NxtBColr & 0x4000 ) {        // Check dirty bit
      NxtBColr = NxtBColr & 0xbfff; // remove dirty bit
      SetBackColr(NxtBColr);
      } /* endif */
}


int  GRID::BlockWidth(){
   double tmpval;
   tmpval=((double)Grcl.xRight- (double)Grcl.xLeft)/GRIDXMAX;
   return ((int)tmpval);
}
int  GRID::BlockHeight(){
   double tmpval;
   tmpval=((double)Grcl.yTop - (double)Grcl.yBottom)/GRIDYMAX;
   return ((int)tmpval);
}

void GRID::Show(HPS hps){
   int    x,y;
   BOOL   fSuccess;          // return from API
   POINTL HorLinCoord1;      // coord for line designating decender
   POINTL HorLinCoord2;      // coord for line designating decender
   unsigned int color;


   RECTL prctlBlkPixel= {0,Grcl.yTop-BlockHeight(),BlockWidth(),Grcl.yTop};
   HorLinCoord1.x= 0;
   HorLinCoord2.x= Grcl.xRight;
   for (y=0; y<GRIDYMAX; y++) {
      for (x=0; x<GRIDXMAX; x++) {
         prctlBlkPixel.xLeft   = x*BlockWidth()+1;
         prctlBlkPixel.yBottom = Grcl.yTop- (y+1)*BlockHeight()+1;
         prctlBlkPixel.xRight  = (x+1)*BlockWidth()-1;
         prctlBlkPixel.yTop    = Grcl.yTop- y*BlockHeight()-1;
         color= GRmatrix[x][y] & 0x7fff;
         fSuccess=WinFillRect(hps, &prctlBlkPixel, color);
      } /* endfor */
      if (y==12) {
         HorLinCoord1.y= prctlBlkPixel.yTop;
         HorLinCoord2.y= prctlBlkPixel.yTop;
         GpiMove(hps,&HorLinCoord1);
         GpiLine(hps,&HorLinCoord2);
         } 
       else {
         } /* endif */
   } /* endfor */
}


void GRID::MouseButt(int xCoord, int yCoord){
   int BlockX, BlockY;
   BlockX = xCoord/BlockWidth();
   BlockY = ((Grcl.yTop/BlockHeight())-(yCoord/BlockHeight()))-1;

   if (QueryPixelOn(BlockX,BlockY)) {
      GRmatrix[BlockX][BlockY]=GbackColr;
      }
    else {
      GRmatrix[BlockX][BlockY]=GforgColr | 0x8000;
      } /* endif */
   }

void GRID::LoadChar(unsigned char c){
   unsigned int x,y,mask;
   for (y=0; y<GRIDYMAX; y++) {
      mask=1;
      for (x=0; x<GRIDXMAX; x++) {
         if ( (M12FontDef[c][y] & mask) != 0) {
            GRmatrix[GRIDXMAX-x-1][y]= GforgColr | 0x8000;
         } else {
            GRmatrix[GRIDXMAX-x-1][y]= GbackColr;
         } /* endif */
         mask=mask<<1;
      } /* endfor */
   } /* endfor */
}

void GRID::SetSize(){
   WinQueryWindowRect(Ghwnd,&Grcl);
   WinInvalidateRect(Ghwnd,&Grcl,FALSE);
}

void GRID::RunNet(void) {
   unsigned int x,y;
   unsigned char mask;
   static unsigned char NetVector[GRIDYMAX];
   for (y=0; y<GRIDYMAX; y++) {
      mask=1;
      NetVector[y]=0;
      for (x=0; x<GRIDXMAX; x++) {
         if ( QueryPixelOn(GRIDXMAX-x-1, y) ) {
            NetVector[y]= NetVector[y] | mask;
         } else {
         } /* endif */
         mask=mask<<1;
      } /* endfor */
   } /* endfor */
   NetVector[GRIDYMAX]='\0';
   Reco.ApplyVector(NetVector, GRIDYMAX);
   Reco.RunReco();
}

void GRID::SaveToLog(void){
   unsigned int x,y;
   unsigned int i;
   unsigned char mask;
   unsigned char logpic[GRIDXMAX][GRIDYMAX];
   static unsigned char NetVector[GRIDYMAX];
   for (y=0; y<GRIDYMAX; y++) {
      mask=1;
      NetVector[y]=0;
      for (x=0; x<GRIDXMAX; x++) {
         if ( QueryPixelOn(GRIDXMAX-x-1, y) ) {
            NetVector[y]= NetVector[y] | mask;
            logpic[x][y]= 'X';
         } else {
            logpic[x][y]= '.';
         } /* endif */
         mask=mask<<1;
      } /* endfor */
   } /* endfor */

   for (y=0; y<GRIDYMAX; y++) {
      for (x=0; x<GRIDXMAX; x++) {
         fprintf(LOGFILE,"%c", logpic[GRIDXMAX-x-1][y]);
         } /* endfor */
      fprintf(LOGFILE,"    ",NetVector[y]);
      fprintf(LOGFILE,"0x%x\n",NetVector[y]);
      } /* endfor */

   NetVector[GRIDYMAX]='\0';
   NETRESULTS results;
   for (i=0; i<Reco.QueryNetCount(); i++) {
      Reco.QueryNthBest( i, &results );
      fprintf(LOGFILE,"NET[%d] = %6.3lf\n",results.index,results.value);
      } /* endfor */
   fprintf(LOGFILE,"\n-------------------------------------------\n\n");

}



int main ( int argc, char *argv[] );
VOID error ( PSZ psz );

// global variables 2

    HWND    hwndClient;        // client window handle
    HWND    hwndFrame;         // frame window handle
// CHILD WINDOW 1 DISPLAYS THE CHARACTER GRID
    HWND    hwndChild1;        // client window handle
    HWND    hwndChild1frame;   // frame window handle
// CHILD WINDOW 2 DISPLAYS THE NET PARMS
    HWND    hwndChild2;        // client window handle
    HWND    hwndChild2frame;   // frame window handle
// CHILD WINDOW 3 DISPLAYS ALL NET OUTPUTS SORTED BY VALUE
    HWND    hwndChild3;        // client window handle
    HWND    hwndChild3frame;   // frame window handle

    int     OutLayerSize;

int main ( int argc, char *argv[] )
{
    HAB     hab;               // anchor block handle
    HMQ     hmq;               // message queue handle
    QMSG    qmsg;              // message from message queue
    ULONG   flCreate;          // window creation control flags
    ULONG   flCreate2;         // window creation control flags
    ULONG   flCreate3;         // window creation control flags
    ULONG   flCreate4;         // window creation control flags 
    BOOL    fSuccess;          // return from API
    BYTE   *szChild1Name; 
    BYTE   *szChild2Name;
    BYTE   *szChild3Name;
    BYTE   *szParentName;

    OutLayerSize=1;      //default

    szParentName = new BYTE[strlen("Parent")+1];
    strcpy((char *)szParentName, "Parent");
    szChild1Name = new BYTE[strlen("Child1")+1];
    strcpy((char *)szChild1Name, "Child1");
    szChild2Name = new BYTE[strlen("Child2")+1];
    strcpy((char *)szChild2Name, "Child2");
    szChild3Name = new BYTE[strlen("Child3")+1];
    strcpy((char *)szChild3Name, "Child3");

    static CHAR *MSG1R="CANNOT REGISTER PARENT";
    static CHAR *MSG2R="CANNOT REGISTER CHILD1";
    static CHAR *MSG3R="CANNOT REGISTER CHILD2";
    static CHAR *MSG4R="CANNOT REGISTER CHILD3";
    static CHAR *MSG1C="CANNOT CREATE PARENT";
    static CHAR *MSG2C="CANNOT CREATE CHILD1";
    static CHAR *MSG3C="CANNOT CREATE CHILD2";
    static CHAR *MSG4C="CANNOT CREATE CHILD3";

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

    fSuccess = WinRegisterClass(
       hab,               // Anchor block handle
       szChild1Name,      // Window class name
       (PFNWP)child1proc, // Address of window procedure
       0,                 // No special Class Style
       0                  // No extra window words
       );
    if ( fSuccess == FALSE )
        error((PSZ)MSG2R);

    fSuccess = WinRegisterClass(
       hab,               // Anchor block handle
       szChild2Name,      // Window class name
       (PFNWP)child2proc, // Address of window procedure
       0,                 // No special Class Style
       0                  // No extra window words
       );
    if ( fSuccess == FALSE )
        error((PSZ)MSG3R);

    fSuccess = WinRegisterClass(
       hab,               // Anchor block handle
       szChild3Name,      // Window class name
       (PFNWP)child3proc, // Address of window procedure
       0,                 // No special Class Style
       0                  // No extra window words
       );
    if ( fSuccess == FALSE )
        error((PSZ)MSG4R);

    flCreate =FCF_TITLEBAR |FCF_SYSMENU |FCF_MENU | FCF_SIZEBORDER | 
                      FCF_MINMAX |FCF_SHELLPOSITION |FCF_TASKLIST;

    static CHAR *ParTitBar="CHARACTER RECOGNITION SYSTEM";
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

    flCreate2 =FCF_TITLEBAR |FCF_SYSMENU |
                             FCF_MENU | FCF_SIZEBORDER |
                             FCF_MINMAX |FCF_SHELLPOSITION |
                             FCF_TASKLIST;
    static CHAR *Ch1TitBar="CHARACTER GRID MAP";
    hwndChild1frame = WinCreateStdWindow(
                      hwndClient,      // Parent window is parent
                      WS_VISIBLE,      // Frame Window Style
                      &flCreate2,      // Frame creation flag
                      szChild1Name,    // Client window class name
                      (PSZ)Ch1TitBar,  // Title bar text
                      0L,              // No special class style
                      0,               // Resource is in .EXE file
                      ID_CHILD1,       // Frame window identifier 
                      &hwndChild1      // Client window handle
                      );
    if ( hwndChild1frame == 0 )
        error ( (PSZ)MSG2C );

    flCreate3 =FCF_TITLEBAR |FCF_SYSMENU | FCF_SIZEBORDER |
                             FCF_MINMAX |FCF_SHELLPOSITION |
                             FCF_TASKLIST;
    static CHAR *Ch2TitBar="NETWORK PARAMETERS";
    hwndChild2frame = WinCreateStdWindow(
                      hwndClient,      // Parent window is parent
                      WS_VISIBLE,      // Frame Window Style
                      &flCreate3,      // Frame creation flag
                      szChild2Name,    // Client window class name
                      (PSZ)Ch2TitBar,  // Title bar text
                      0L,              // No special class style
                      0,               // Resource is in .EXE file
                      ID_CHILD2,       // Frame window identifier 
                      &hwndChild2      // Client window handle
                      );
    if ( hwndChild2frame == 0 )
        error ( (PSZ)MSG3C );

    flCreate4 =FCF_TITLEBAR |FCF_SYSMENU  | FCF_SIZEBORDER    |
                             FCF_MINMAX   | FCF_SHELLPOSITION |
                             FCF_TASKLIST | FCF_VERTSCROLL;
    static CHAR *Ch3TitBar="NETWORK - ALL OUTPUTS";
    hwndChild3frame = WinCreateStdWindow(
                      hwndClient,      // Parent window is parent
                      WS_VISIBLE,      // Frame Window Style
                      &flCreate4,      // Frame creation flag
                      szChild3Name,    // Client window class name
                      (PSZ)Ch3TitBar,  // Title bar text
                      0L,              // No special class style
                      0,               // Resource is in .EXE file
                      ID_CHILD3,       // Frame window identifier
                      &hwndChild3      // Client window handle
                      );
    if ( hwndChild3frame == 0 )
        error ( (PSZ)MSG4C );

    WinSetWindowPos( hwndFrame, HWND_TOP,
                      10, 10, 400, 450,
                      SWP_MAXIMIZE);
    WinSetWindowPos( hwndChild1frame, HWND_TOP,
                      4, 4, 400, 710,
                      SWP_SIZE | SWP_MOVE | SWP_ZORDER);
    WinSetWindowPos( hwndChild2frame, HWND_TOP,
                      404, 4, 622, 177,
                      SWP_SIZE | SWP_MOVE | SWP_ZORDER);
    WinSetWindowPos( hwndChild3frame, HWND_TOP,
                      404, 181, 622, 533,
                      SWP_SIZE | SWP_MOVE | SWP_ZORDER);
    WinSendMsg(hwndChild1frame, WM_SETICON,
                     (MPARAM)WinQuerySysPointer(HWND_DESKTOP, SPTR_APPICON, FALSE),
                      MPFROM2SHORT(0,0) );


    while ( WinGetMsg ( hab, &qmsg, (HWND)0, 0, 0 ) != FALSE )
        WinDispatchMsg ( hab, &qmsg );

    WinDestroyWindow ( hwndFrame );
    WinDestroyMsgQueue ( hmq );
    WinTerminate ( hab );
    if (LOGFILE) fclose(LOGFILE);
    return 0;
}
//*******************************************************************
MRESULT EXPENTRY clientproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 )
{
    HPS     hps;                // cached PS handle
    BOOL    fSuccess;           // return from API

    static  POINTL   ptlPaint;      // string coord
    static  CHAR     szString[80];  // string to display
    static  ULONG    ulLen;         // string length
    static  PSZ      pszString;
    RECTL            rcl;
    switch( msg )
    {
        case WM_CLOSE:
            WinPostMsg( hwnd, WM_QUIT, 0L, 0L );
            return (MRESULT)0;

        case WM_CREATE:
            ptlPaint.x=0L;
            ptlPaint.y=0L;
            strcpy(szString,"NEURAL CHARACTER RECOGNITION");
            ulLen=strlen(szString);
            pszString= (PSZ) &szString[0];
            return (MRESULT)FALSE;

        case WM_PAINT:
            hps = WinBeginPaint ( hwnd, NULLHANDLE, (PRECTL)NULL );
            GpiSetBackMix(hps,BM_OVERPAINT);
            GpiSetColor(hps,CLR_WHITE);
            GpiSetBackColor(hps,CLR_DARKGRAY);
            WinQueryWindowRect(hwnd,&rcl);
            fSuccess=WinFillRect(hps, &rcl, CLR_DARKGRAY);
            WinEndPaint ( hps );
            return (MRESULT)0;

        case WM_SIZE:
            ptlPaint.y=SHORT2FROMMP(mp2)-16;
            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl,TRUE);
            return (MRESULT)0;

        case WM_COMMAND:
            switch (COMMANDMSG(&msg)->cmd) {
               case IDM_RUN:
                  if (Reco.QueryAlive()) {
                     grid.RunNet();
                     WinSendMsg(hwndChild3,WM_USER1,MPFROMSHORT(0),MPFROMSHORT(0));
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     } 
                   else {
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     WinMessageBox(
                         HWND_DESKTOP, hwnd,
                         (PSZ)("PLEASE SELECT \"INITIALIZE WEIGHTS\" FROM THE ACTION BAR"),
                         (PSZ)("NETWORKS MUST BE INITIALIZED:"),
                         0, MB_OK | MB_ICONASTERISK );
                     } /* endif */
                  return (MRESULT)0;
               case IDM_WEIGHTS:
                  if (WinDlgBox(HWND_DESKTOP, hwnd, LoadWtDlgproc,
                                   NULLHANDLE, IDD_NETFILE, NULL)) {
                     WinSendMsg(hwndChild2,WM_USER1,MPFROMSHORT(0),MPFROMSHORT(0));
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     }
                   else {
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     }

                  return (MRESULT)0;
               case IDM_SAVELOG:
                  grid.SaveToLog();
                  WinAlarm(HWND_DESKTOP,WA_NOTE);
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
    int          ndebug;

    switch( msg )
       {
       case WM_INITDLG:
            WinSendDlgItemMsg(hwnd, IDD_FLIST, LM_DELETEALL,NULL,NULL);
            ndebug=0;
            rc=DosFindFirst((PSZ)("*.GBL"), &hDir, 0x0000L, (PVOID)&FindBuf,
                            (ULONG)(sizeof FindBuf), &usSearchCount, FIL_STANDARD);
            while ((rc==0) && (usSearchCount != 0)) {
               WinSendDlgItemMsg(hwnd, IDD_FLIST, LM_INSERTITEM,
                             MPFROM2SHORT(LIT_SORTASCENDING,0),
                             MPFROMP(FindBuf.achName));
               rc=DosFindNext(hDir, (PVOID)&FindBuf, (ULONG)(sizeof FindBuf),
                              &usSearchCount );
               ndebug++;
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
                     if (Reco.Setup(szFnameBuff)==0)
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
                     if (Reco.Setup(szFnameBuff)==0)
                        WinDismissDlg(hwnd, TRUE);
                      else
                        WinMessageBox( HWND_DESKTOP, hwnd, (PSZ) szFnameBuff,
                          (PSZ)("ERROR: UNABLE TO OPEN"), 0, MB_OK|MB_ICONASTERISK);
                     return (MRESULT)0;
                case DID_CANCEL:
                     WinMessageBox(
                         HWND_DESKTOP, hwnd,
                         (PSZ)("CHANGE NETWORK WEIGHTS CANCELLED BY USER"),
                         (PSZ)("DIALOG"),
                         0, MB_OK | MB_ICONASTERISK );
                     WinDismissDlg(hwnd, FALSE);
                     return (MRESULT)0;
                } /* endswitch */
       break;
       } /* endswitch */
    return WinDefDlgProc(hwnd,msg,mp1,mp2);
}   

unsigned char AscDlgIniChar=0x30;
ULONG         AscDlgIniButID=IDD_DIGITS09;

//******************************************************************* */
MRESULT EXPENTRY GetAscDlgproc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 ){
    char szIChar[2];
    char szAChar[3];
    unsigned char code;
    int i,MaxChars;

    switch( msg )
       {
       case WM_INITDLG:

            WinSendDlgItemMsg(hwnd,AscDlgIniButID, BM_SETCHECK,
                              MPFROM2SHORT(TRUE,0), NULL);
            szIChar[0]=AscDlgIniChar;
            szIChar[1]=0;
            WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_DELETEALL,NULL,NULL);
            if (AscDlgIniButID==IDD_DIGITS09) {
               MaxChars=10;
               }
             else {
               MaxChars=26;
               } /* endif */
            for (i=0; i<MaxChars; i++) {
               WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_INSERTITEM,
                            MPFROM2SHORT(LIT_SORTASCENDING,0),
                            MPFROMP(szIChar) );
               szIChar[0]++;
               } /* endfor */
            WinSendDlgItemMsg(hwnd, IDD_ASCIIEDIT, EM_SETTEXTLIMIT,
                            MPFROM2SHORT(2, 0),NULL);
            break;
         case WM_CONTROL:
            char    szTempBuff[4];
            char    szCbuff[4];
            switch (SHORT1FROMMP(mp1)) {
               case IDD_ASCIILIST:
                  dlgrc.mres =  WinSendDlgItemMsg(hwnd, IDD_ASCIILIST,
                                LM_QUERYSELECTION, 0L, 0L);
                  WinSendDlgItemMsg(hwnd, IDD_ASCIILIST,LM_QUERYITEMTEXT,
                                MPFROM2SHORT(dlgrc.sSelect,sizeof(szTempBuff)),
                                MPFROMP(szTempBuff));
                  switch (SHORT2FROMMP(mp1)) {
                     case LN_SELECT:
                        ByteToHexString(szTempBuff[0], szCbuff);
                        WinSetDlgItemText(hwnd, IDD_ASCIIEDIT, (PSZ)szCbuff);
                        break;
                     case LN_ENTER:
                        WinDismissDlg(hwnd, szTempBuff[0]);
                        break;
                        default:;
                     } /* endswitch */
                  break;
               case IDD_UPPERCASE:
                  AscDlgIniChar= 0x41;
                  AscDlgIniButID= IDD_UPPERCASE;
                  szIChar[0]=0x41;
                  szIChar[1]=0;
                  WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_DELETEALL,NULL,NULL);
                  for (i=0; i<26; i++) {
                     WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_INSERTITEM,
                                  MPFROM2SHORT(LIT_SORTASCENDING,0),
                                  MPFROMP(szIChar) );
                     szIChar[0]++;
                     } 
                  break;
               case IDD_LOWERCASE:
                  AscDlgIniChar= 0x61;
                  AscDlgIniButID= IDD_LOWERCASE;
                  szIChar[0]=0x61;
                  szIChar[1]=0;
                  WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_DELETEALL,NULL,NULL);
                  for (i=0; i<26; i++) {
                     WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_INSERTITEM,
                                  MPFROM2SHORT(LIT_SORTASCENDING,0),
                                  MPFROMP(szIChar) );
                     szIChar[0]++;
                     } 
                  break;
               case IDD_DIGITS09:
                  AscDlgIniChar= 0x30;
                  AscDlgIniButID= IDD_DIGITS09;
                  szIChar[0]=0x30;
                  szIChar[1]=0;
                  WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_DELETEALL,NULL,NULL);
                  for (i=0; i<10; i++) {
                     WinSendDlgItemMsg(hwnd, IDD_ASCIILIST, LM_INSERTITEM,
                                  MPFROM2SHORT(LIT_SORTASCENDING,0),
                                  MPFROMP(szIChar) );
                     szIChar[0]++;
                     } /* endfor */
                  break;
               } /* endswitch */
            break;
       case WM_COMMAND:
            switch (SHORT1FROMMP( mp1 ) )
                {
                case DID_OK:
                     WinQueryDlgItemText(hwnd, IDD_ASCIIEDIT,
                          sizeof szAChar, (PSZ)szAChar);
                     if (IsHexString(szAChar)) {
                        WinDismissDlg(hwnd, HexStringToByte(szAChar));
                        }
                      else {
                        WinMessageBox( HWND_DESKTOP, hwnd,
                                (PSZ)("INVALID ASCII CODE!!"),
                                (PSZ)("ASCII DLG"),
                                0, MB_ERROR | MB_MOVEABLE | MB_OK );
                        WinDismissDlg(hwnd, FALSE);
                        } /* endif */
                     return (MRESULT)0;
                case DID_CANCEL:
                     WinMessageBox(
                         HWND_DESKTOP, hwnd,
                         (PSZ)("CHANGE ASCII CHARACTER CANCELLED BY USER"),
                         (PSZ)("DIALOG"),
                         0, MB_OK | MB_ICONASTERISK );
                     WinDismissDlg(hwnd, FALSE);
                     return (MRESULT)0;
                } /* endswitch */
            break;

       } /* endswitch */
    return WinDefDlgProc(hwnd,msg,mp1,mp2);
}
//******************************************************************* */
 
MRESULT EXPENTRY child1proc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 )
{
    HPS     hps;                // cached PS handle
    BOOL    fSuccess;           // return from API

    static  HWND     hwndEntryField;// HANDLE FOR ENTRY FIELD CONTROL
    static  HWND     hwndButtOK;    // HANDLE FOR 'OK' BUTTON CONTROL
    static  HWND     hwndButtCAN;   // HANDLE FOR 'CAN' BUTTON CONTROL
    static  POINTL   ptlPaint;      // string coord
    static  CHAR     szString[80];  // string to display
    static  ULONG    ulLen;         // string length
    unsigned char    ChActive;      // Current grid character
    RECTL            rcl;
    static  int      MousePaintFlg=0;
    static  char     EFbuf[80];
    switch( msg )
    {
        case WM_CLOSE:
            WinDestroyWindow ( WinQueryWindow(hwnd,QW_PARENT) );//kill window only
            return (MRESULT)0;

        case WM_CREATE:
            grid.SetHandle(hwnd);
            ptlPaint.x= 7L;
            ptlPaint.y=12L;
            strcpy(szString,"Enter ASCII code: ");
            ulLen=strlen(szString);
            return (MRESULT)FALSE;

        case WM_PAINT:
            hps = WinBeginPaint ( hwnd, (HPS)0, (PRECTL)NULL );
            GpiSetBackMix(hps,BM_OVERPAINT);
            GpiSetColor(hps,CLR_WHITE);
            GpiSetBackColor(hps,CLR_BLACK);
            if (!MousePaintFlg) {
               WinQueryWindowRect(hwnd,&rcl);
               fSuccess=WinFillRect(hps, &rcl, CLR_BLACK);
               MousePaintFlg=0;
               } /* endif */
            grid.Show(hps);
            WinEndPaint ( hps );
            return (MRESULT)0;

        case WM_ACTIVATE:
        case WM_SIZE:
            grid.SetSize();
            MousePaintFlg=0;
            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl,TRUE);
            return (MRESULT)0;

        case WM_CONTROL:
            if ((SHORT1FROMMP (mp1) == IDM_ENTFIELD) && 
                (SHORT2FROMMP (mp1) == EN_CHANGE) ) {
               WinQueryWindowText(hwndEntryField,80,(PSZ)&EFbuf[0]);
               return (MRESULT)0;
            } else {
               break;
            } /* endif */

        case WM_BUTTON1DOWN:
           grid.MouseButt(SHORT1FROMMP (mp1),SHORT2FROMMP (mp1));
           MousePaintFlg=1;
           WinQueryWindowRect(hwnd,&rcl);     //GET AREA
           WinInvalidateRect(hwnd,&rcl,TRUE); //FORCE A PAINT
           break;  // Continue to allow Default proc to handle this msg
        case WM_COMMAND:
            switch (COMMANDMSG(&msg)->cmd) {
               case IDM_CLEARGRID:  
                  grid.LoadChar(0);
                  MousePaintFlg=0;
                  WinQueryWindowRect(hwnd,&rcl);     //GET AREA     
                  WinInvalidateRect(hwnd,&rcl,TRUE); //FORCE A PAINT
                  return (MRESULT)0;
               case IDM_NEWCHAR:
                  ChActive=WinDlgBox(HWND_DESKTOP, hwnd, GetAscDlgproc, 
                               NULLHANDLE, IDD_ASCIIDLG, NULL);
                  if (ChActive) {
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     grid.LoadChar(ChActive);
                     }
                   else {
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     WinAlarm(HWND_DESKTOP,WA_NOTE);
                     WinAlarm(HWND_DESKTOP,WA_ERROR);
                     }

                  MousePaintFlg=0;
                  WinQueryWindowRect(hwnd,&rcl);
                  WinInvalidateRect(hwnd,&rcl,TRUE);
                  return (MRESULT)0;

               case IDM_COLORS:
                  if (WinDlgBox(HWND_DESKTOP, hwnd, ColorDlgproc,
                                   NULLHANDLE, IDD_COLORS, NULL)) {
                     grid.SetNextColr();
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

               default:;
               } /* endswitch 2 */
            return (MRESULT)0;
        default:
            return WinDefWindowProc( hwnd, msg, mp1, mp2 );
    } /* endswitch 1 */
    return WinDefWindowProc ( hwnd, msg, mp1, mp2 );
}




MRESULT EXPENTRY child2proc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 ) {
    HPS     hps;                // cached PS handle
    BOOL    fSuccess;           // return from API
    static  CHAR     szString[80];  // string to display
    static  CHAR     pszCoord1String[80];
    static  CHAR     pszParmStr1[80];
    static  CHAR     szTemp1[80];
    CHAR             num1[10];
    static  ULONG    ulLen;         // string length
    static  PSZ      pszString;
    static  POINTL   ptlPaint;      // string coord
    POINTL           ptlCPaint;
    RECTL            rcl;
    int              Layer;
    double Temperature;
    double Threshold;

    switch( msg ) {
        case WM_CREATE:
            ptlPaint.x=0L;
            ptlPaint.y=0L;
            strcpy(szString,"NEURAL PARAMETERS");
            ulLen=strlen(szString);
            pszString= (PSZ) &szString[0];
         case WM_PAINT:                                                
            Temperature = Reco.QueryTemp();
            Threshold   = Reco.QueryThresh();
            hps = WinBeginPaint ( hwnd, (HPS)0, (PRECTL)NULL );            
            GpiSetColor(hps,CLR_CYAN );                              
            WinQueryWindowRect(hwnd,&rcl);                             
            fSuccess=WinFillRect(hps, &rcl, CLR_BLACK);
            GpiCharStringAt(hps,&ptlPaint,ulLen,pszString);            
            if (Temperature>=0) {
               ptlCPaint.x=ptlPaint.x;
               ptlCPaint.y=ptlPaint.y -32;
               strcpy(pszParmStr1,"Temperature = ");
               strcat(pszParmStr1,DoubleToString(Temperature,szTemp1,10));
               GpiCharStringAt(hps,&ptlCPaint,strlen(pszParmStr1),(PSZ)pszParmStr1);
               strcpy(pszParmStr1,"TOPOLOGY:  ");
               int Lindx=0;
               Layer=Reco.QueryLayerSize(Lindx);
               while (Layer>0) {
                  strcat(pszParmStr1, itoa(Layer,szTemp1,10));
                  strcat(pszParmStr1, " / ");
                  Lindx++;
                  Layer= Reco.QueryLayerSize(Lindx);
                  if (Layer>0) {
                     OutLayerSize=Layer;
                     } /* endif */
                  } /* endwhile */
               pszParmStr1[strlen(pszParmStr1)-2]=' ';
               ptlCPaint.y=ptlPaint.y -64;
               GpiCharStringAt(hps,&ptlCPaint,strlen(pszParmStr1),(PSZ)pszParmStr1);
               } 
             else {
               strcpy(pszParmStr1,"NETWORK IS NOT INITIALIZED");
               ptlCPaint.x=ptlPaint.x;
               ptlCPaint.y=ptlPaint.y -32;
               GpiCharStringAt(hps,&ptlCPaint,strlen(pszParmStr1),(PSZ)pszParmStr1);
               strcpy(pszParmStr1,"NETWORK DATA IS NOT AVAILABLE");
               ptlCPaint.x=ptlPaint.x;
               ptlCPaint.y=ptlPaint.y -48;
               GpiCharStringAt(hps,&ptlCPaint,strlen(pszParmStr1),(PSZ)pszParmStr1);
               } /* endif */


            WinEndPaint ( hps );
            return (MRESULT)0;
        case WM_SIZE:
            ptlPaint.y=SHORT2FROMMP(mp2)-16;
            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl,TRUE);
            return (MRESULT)0;
        case WM_USER1:
            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl,TRUE);
            return (MRESULT)0;
        } /* endswitch 1 */
    return WinDefWindowProc ( hwnd, msg, mp1, mp2 );
}

MRESULT EXPENTRY child3proc( HWND hwnd, MSGID msg, MPARAM mp1,
                 MPARAM mp2 ) {
    HPS               hps;                  // cached PS handle
    BOOL              fSuccess;             // return from API
    static  HWND      hwndVscroll;
    static  CHAR      szField1[80];         // string to display
    CHAR              num1[10];
    RECTL             rcl,rclInvalid;
    static  POINTL    ptlPaint;             // string coord
    static  POINTL    ptlCPaint;            // string coord
    static  SHORT     sVscrollPos,sVscrollMax;
    static  SHORT     cyChar, cyDesc, cxCaps, cyClient;
    SHORT             sVscrollInc, SLine;
    SHORT             SPaintBeg,SPaintEnd;
    int               i;
    FONTMETRICS       fm;
    static struct NETRESULTS ResultBuf;           // ret values from net class
    static struct NETRESULTS *pResultBuf;         // ret values from net class
    static CHAR       NumBuf[255];                // work area for double to str
    static int    MaxLines;                       // =OutLayerSize;

    switch( msg ) {
        case WM_CREATE:
            MaxLines= Reco.QueryNetCount();         //OutLayerSize;
            sVscrollPos=0;
            ptlPaint.x=0L;
            ptlPaint.y=0L;
            hps=WinGetPS(hwnd);
            GpiQueryFontMetrics(hps,(LONG)sizeof fm, &fm);
            cyChar=fm.lMaxBaselineExt;
            cyDesc=fm.lMaxDescender;
            cxCaps=fm.lEmInc;
            WinReleasePS(hwnd);
            hwndVscroll = WinWindowFromID( WinQueryWindow(hwnd,QW_PARENT),
                                 FID_VERTSCROLL);
            return (MRESULT)0;
        case WM_CLOSE:
            break;
        case WM_PAINT:                                                
            hps = WinBeginPaint ( hwnd, (HPS)0, &rclInvalid );
            WinQueryWindowRect(hwnd,&rcl);                             
            fSuccess=WinFillRect(hps, &rcl, CLR_BLACK);
            SPaintBeg = maximum(0,sVscrollPos +
                       (cyClient-(SHORT)rclInvalid.yTop)/cyChar);
            SPaintEnd = minimum(MaxLines,sVscrollPos +
                       (cyClient-(SHORT)rclInvalid.yBottom)/cyChar+1);
            GpiSetColor(hps,CLR_CYAN );
            pResultBuf = &ResultBuf;

            for (SLine=SPaintBeg; SLine<SPaintEnd; SLine++) {
              Reco.QueryNthBest(SLine, pResultBuf); //Show data sorted by value
              ptlCPaint.x=0;            
              ptlCPaint.y=cyClient-cyChar*(SLine+1-sVscrollPos)+cyDesc;
              strcpy (szField1, itoa(SLine,num1,10));
              GpiCharStringAt(hps,&ptlCPaint,strlen(szField1),(PSZ)szField1);
              ptlCPaint.x += 2*cxCaps;
              strcpy (szField1, "DIGIT: ");
              char szTemp1[80];
              strcat (szField1, itoa(pResultBuf->index,szTemp1,10));
              szTemp1[0]= pResultBuf->character; szTemp1[1]='\0';
              GpiCharStringAt(hps,&ptlCPaint,strlen(szField1),(PSZ)szField1);
              ptlCPaint.x += 8*cxCaps;
              strcpy (szField1, "OUT: ");
              double xOut= pResultBuf->value;
              char *pNumBuf = DoubleToString(xOut, NumBuf,6);
              strcat (szField1, NumBuf);
              GpiCharStringAt(hps,&ptlCPaint,strlen(szField1),(PSZ)szField1);
              } /* endfor */

            WinEndPaint ( hps );
            return (MRESULT)0;
        case WM_SIZE:
            MaxLines= Reco.QueryNetCount();
            cyClient=SHORT2FROMMP(mp2);
            sVscrollMax= maximum(0, (MaxLines-cyClient/cyChar));
            sVscrollPos= minimum(sVscrollPos,sVscrollMax);
            WinSendMsg(hwndVscroll, SBM_SETSCROLLBAR,
                                 MPFROM2SHORT(sVscrollPos,0),
                                 MPFROM2SHORT(0,sVscrollMax) );
            WinEnableWindow(hwndVscroll, sVscrollMax ? TRUE:FALSE);
            return (MRESULT)0;
        case WM_VSCROLL:
            switch (SHORT2FROMMP(mp2)) {
               case SB_LINEUP:
                  sVscrollInc = -1;
                  break;
               case SB_LINEDOWN:
                  sVscrollInc = 1;
                  break;
               case SB_PAGEUP:
                  sVscrollInc = minimum(-1,-cyClient/cyChar);
                  break;
               case SB_PAGEDOWN:
                  sVscrollInc = maximum(1,cyClient/cyChar);
                  break;
               case SB_ENDSCROLL:
                  sVscrollInc = 0;
                  break;
               case SB_SLIDERPOSITION:
                  sVscrollInc = 0;
                  break;
               case SB_SLIDERTRACK:
                  sVscrollInc = SHORT1FROMMP(mp2)-sVscrollPos;
                  break;
               default:
                  sVscrollInc = 0;
                  break;
               } /* endswitch */

            sVscrollInc=maximum(-sVscrollPos,
                               minimum(sVscrollInc,sVscrollMax-sVscrollPos));

            if (sVscrollInc != 0)
               {
               sVscrollPos+=sVscrollInc;
               WinScrollWindow(hwnd,0,(LONG)(cyChar*sVscrollInc),
                              (PRECTL)NULL,(PRECTL)NULL,
                              (HRGN)NULL,(PRECTL)NULL,SW_INVALIDATERGN);

               WinSendMsg(hwndVscroll,SBM_SETPOS,MPFROMSHORT(sVscrollPos), NULL);
               WinUpdateWindow(hwnd);
               } /* endif */
            return (MRESULT)0;
        case WM_USER1:
            MaxLines= Reco.QueryNetCount();

            sVscrollMax= maximum(0, (MaxLines-cyClient/cyChar));     
            sVscrollPos= minimum(sVscrollPos,sVscrollMax);           
            WinSendMsg(hwndVscroll, SBM_SETSCROLLBAR,                
                                 MPFROM2SHORT(sVscrollPos,0),        
                                 MPFROM2SHORT(0,sVscrollMax) );      
            WinEnableWindow(hwndVscroll, sVscrollMax ? TRUE:FALSE);  

            WinQueryWindowRect(hwnd,&rcl);
            WinInvalidateRect(hwnd,&rcl,TRUE);
            return (MRESULT)0;
        } /* endswitch 1 */
    return WinDefWindowProc ( hwnd, msg, mp1, mp2 );
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


// Routines which may be used to display program data under PM

void VarShow1(HWND hwnd, char *sx, int x){
   char Report[255], num1[10], *Rptr;
   Rptr=itoa(x,num1,10);
   strcpy(Report,sx);
   strcat(Report,Rptr);
   WinMessageBox(
                HWND_DESKTOP, hwnd,
                (PSZ)Report,
                (PSZ)("PGM MESSAGE"),
                0, MB_OK | MB_ICONASTERISK );
}

void VarShow1C(HWND hwnd, char *sx, unsigned char x){
   char Report[255], num1[10], *Rptr;
   ByteToHexString( x, num1);
   strcpy(Report,sx);
   strcat(Report,num1);
   WinMessageBox(
                HWND_DESKTOP, hwnd,
                (PSZ)Report,
                (PSZ)("PGM MESSAGE"),
                0, MB_OK | MB_ICONASTERISK );
}

void VarShow2(HWND hwnd, char *sx, char *sy,int x, int y){
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
                (PSZ)("PGM MESSAGE"),
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