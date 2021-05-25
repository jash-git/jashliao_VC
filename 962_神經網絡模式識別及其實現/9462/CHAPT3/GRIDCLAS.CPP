#define GRIDXMAX     1024
#define GRIDYMAX     722

#define GRIDPELON    0x01
#define GRIDPELMARK  0x02
#define GRIDDIRTYNOT 0x7f
#define GRIDDIRTY    0x80

#define RLCXMAXX 1024
#define RLCXMAXY 1024

//------------------------------------------------------------------
// RLC CLASS DEFINITION
//------------------------------------------------------------------


class RLCX {
   private:
      unsigned int RLmatrix[RLCXMAXX][RLCXMAXY];
      int          LargestX;
   public:
      RLCX();
      void Setup(unsigned char *data, int width, int height );
      void Clear();
      void Compress(int width, int height, double Scale);
      unsigned int  Query(int x, int y){return RLmatrix[x][y];}
      unsigned int  QueryIndx(){return LargestX;}
   };

RLCX::RLCX(){
   int i,j;
   LargestX=0;
   for (i=0; i<RLCXMAXX; i++) {
      for (j=0; j<RLCXMAXY; j++) {
         RLmatrix[i][j]=0;
      } /* endfor */
   } /* endfor */
}

void RLCX::Clear(){
   int i,j;
   LargestX=0;
   for (i=0; i<RLCXMAXX; i++) {
      for (j=0; j<RLCXMAXY; j++) {
         RLmatrix[i][j]=0;
      } /* endfor */
   } /* endfor */
}

void RLCX::Setup(unsigned char *data, int width, int height ) {
   unsigned int Target,indx,Count,Query,i,j,x,Bit;
   unsigned char mask;

   Clear();
   x=0;
   for (j=0; j<height; j++) {
      Target=1;
      i=0;
      indx=0;
      Count=0;
      while (i<width) {
         Bit=i&0x07;
         mask=0x80>>Bit;
         if ((data[x] & mask)!=0) Query=1;
                             else Query=0;
         if (Query==Target) {
            Count++;
            i++;
            if ((i&0x07)==0) x++;
         } else {
            RLmatrix[indx][j]=Count | 0x8000;
            if(indx>LargestX)LargestX=indx;
            indx++;
            if (Target==0) Target=1;
                      else Target=0;
            Count=0;
         } /* endif */
      } /* endwhile */
      RLmatrix[indx][j]=Count | 0x8000;
   } /* endfor */
}

void RLCX::Compress(int width, int height, double Scale){
   int i,j,bpl,k;
   double erf;
   double  r,frac,ipart;
   bpl=width>>3;
   for (j=0; j<height; j++) {
      i=0;
      erf=0;
      while ((RLmatrix[i][j] & 0x8000) != 0) {
         r=(double)(RLmatrix[i][j] & 0x7fff);
         r=Scale*r;
         frac=modf(r,&ipart);
         if (frac>0.5) {
            k=(int)ipart+1;
            /* erf = erf- (1.0-frac); */
         } else {
            k=(int)ipart;
            /* erf += frac; */
         } /* endif */
         erf = erf + (r-(double)k);
         if (erf >= 1.0) {
            k=k+1;
            erf=erf-1.0;
         } /* endif */
         if (erf <= -1.0) {
            k=k-1;
            erf=erf+1.0;
         } /* endif */
/*       RLmatrix[i][j] = (2*(RLmatrix[i][j] & 0x7fff))/3;  */
         RLmatrix[i][j] = k;
         RLmatrix[i][j] = RLmatrix[i][j] | 0x8000;
         i++;
      } /* endwhile */
   } /* endfor */
}
//------------------------------------------------------------------
// GRID CLASS DEFINITION
//------------------------------------------------------------------

class GRID {
   private:
      RLCX           rlcx;
      int            width,height;
      HWND           Ghwnd;
      RECTL          Grcl;       //PM's coords for the grid window
      int            Gactive;
      unsigned int   GforgColr;  // Curr active foreground color
      unsigned int   GbackColr;  //             background
      unsigned int   GmarkColr;  //             marked obj
      unsigned int   NxtFColr;   // Queued foreground color
      unsigned int   NxtBColr;   //        background
      unsigned char  GRmatrix[GRIDXMAX][GRIDYMAX];
      int            MouseX,MouseY;
      int QueryPixelOn(int x, int y);
   public:
      GRID();
      void SetHandle(HWND hwnd){Ghwnd=hwnd;}
      void Activate(){Gactive=TRUE;}
      void Deactivate(){Gactive=FALSE;}
      int  IsActive(){return Gactive;}
      void Show(HPS hps);
      void Show2(HPS hps);
      void SetSize();
      void LoadChar(unsigned char c);  // Std char => GRmatrix
      int  LoadRas(char *FileName);
      void MouseButt(int xCoord, int yCoord);
      void SetForgColr(unsigned int NewFcolr);
      void SetBackColr(unsigned int NewBcolr);
      long SetNextColr(void);
      int  QueryForgColr(){return GforgColr;}
      int  QueryBackColr(){return GbackColr;}
      void NextForgColr(unsigned int Fcolr){NxtFColr= Fcolr | GRIDDIRTY;}   // SET DIRTY BIT ON
      void NextBackColr(unsigned int Bcolr){NxtBColr= Bcolr | GRIDDIRTY;}
      void ResetColrDirty(){NxtFColr= 0; NxtBColr= 0; }
      void Clear();
      unsigned int  QueryRLCsize(){return(rlcx.QueryIndx());}
      void ShowWinCoord();
   };


GRID grid;          // Global instance



GRID::GRID(){
   int x,y;
   Gactive=FALSE;
   NxtFColr= 0;
   NxtBColr= 0;
   GforgColr=CLR_BLACK;
   GbackColr= CLR_WHITE;
   GmarkColr=CLR_RED;
   width=0; 
   height=0;
   for (x=0; x<GRIDXMAX; x++) {
      for (y=0; y<GRIDYMAX; y++) {
         GRmatrix[x][y]= 0;                                                         /*GbackColr;  */
      } /* endfor */
   } /* endfor */
}  


void GRID::Clear(){
   int x,y;
   for (x=0; x<GRIDXMAX; x++) {
      for (y=0; y<GRIDYMAX; y++) {
         GRmatrix[x][y]= 0;                                                           /*GbackColr;*/
      } /* endfor */
   } /* endfor */
}


int GRID::QueryPixelOn(int x, int y){
   int PelFlag = GRmatrix[x][y] & GRIDPELON;                                           /* 0x8000; */
   if (PelFlag) {
      return 1;
   } else {
      return 0;
   } /* endif */
}

void GRID::SetForgColr(unsigned int NewFColr){
   GforgColr=NewFColr;
}

void GRID::SetBackColr(unsigned int NewBColr){
   GbackColr=NewBColr;
}                            
                             
long GRID::SetNextColr(){
   if (NxtFColr & GRIDDIRTY ) {           // Check dirty bit
      NxtFColr = NxtFColr & GRIDDIRTYNOT; // remove dirty bit  
      SetForgColr(NxtFColr);
      } /* endif */
   if (NxtBColr & GRIDDIRTY ) {           // Check dirty bit
      NxtBColr = NxtBColr & GRIDDIRTYNOT; // remove dirty bit
      SetBackColr(NxtBColr);
      return (NxtBColr);
      } /* endif */
   return (GbackColr);
}


void GRID::Show(HPS hps){
   int    x,y;
   BOOL   fSuccess;          // return from API
   int    BlkH, BlkW;        // Temp block height and width to save computations
   unsigned int color;
   POINTL ptl1, ptl2;
   LINEBUNDLE lbnd;

     lbnd.lColor=GforgColr;
     GpiSetAttrs(hps,PRIM_LINE,LBB_COLOR,LBB_WIDTH,&lbnd);
   for (y=0; y<GRIDYMAX; y++) {
      ptl1.y=Grcl.yTop-30-y; ptl2.y=Grcl.yTop-30 -y;
      for (x=0; x<GRIDXMAX; x++) {
        ptl1.x= x; ptl2.x=x; 
        if ((GRmatrix[x][y] & GRIDPELON)!=0) {
           GpiMove(hps, &ptl1);
           GpiLine(hps, &ptl2);
           }
      } /* endfor */
   } /* endfor */
}


void GRID::Show2(HPS hps){
   int    x,y;
   POINTL ptl1, ptl2;
   LINEBUNDLE lbnd;
   int Sense;

     lbnd.lColor=GforgColr;
     GpiSetAttrs(hps,PRIM_LINE,LBB_COLOR,LBB_WIDTH,&lbnd);

   for (y=0; y<height; y++) {
      Sense=1;
      ptl1.y=Grcl.yTop-20-y; ptl2.y=Grcl.yTop-20-y;
      ptl1.x=0;  ptl2.x=0;
      x=0;
      if ( rlcx.Query(x,y)==0 ) {
         Sense=0;
         x++;
      } else {
      } /* endif */
      while ((x==0) || (rlcx.Query(x,y)!=0) ) {
        ptl2.x = ptl1.x + (rlcx.Query(x,y)& 0x7fff)-1;
        if (Sense==1) {
           GpiMove(hps, &ptl1);
           GpiLine(hps, &ptl2);
           Sense=0;
           }
         else {
           Sense=1;
           }
        ptl1.x=ptl2.x +1;
        x++;
      } /* endwhile */
   } /* endfor */
   lbnd.lColor=GmarkColr;
   GpiSetAttrs(hps,PRIM_LINE,LBB_COLOR,LBB_WIDTH,&lbnd);
   ptl1.y = MouseY;   ptl2.y = MouseY;
   ptl1.x = MouseX;   ptl2.x = MouseX;
   GpiMove(hps, &ptl1);
   GpiLine(hps, &ptl2);


}

void GRID::ShowWinCoord(){
   UtilShow2(Ghwnd, "GRID.ShowWinCoord (window)\nRight=","\nLeft=", Grcl.xRight,Grcl.xLeft);
   UtilShow2(Ghwnd, "GRID.ShowWinCoord (window)\nTop   =","\nBottom=", Grcl.yTop,Grcl.yBottom);
}

void GRID::MouseButt(int xCoord, int yCoord){
   int BlockX, BlockY;

   MouseX=xCoord;
   MouseY=yCoord;

   UtilShow2(Ghwnd, "GRID.MouseButt \nX=","\nLY=", MouseX,MouseY);
   }

void GRID::LoadChar(unsigned char c){
}

int  GRID::LoadRas(char *FileName){
   FILE              *fpIn;
   struct rasterfile rasterhdr;
   int               filesize,BytesPerLine,i,j,k;
   unsigned char     *data;
   unsigned char     mask;
   int               CurrByte;
   int               x, pelval;
   double            Scale,S1,S2;

   if((fpIn = fopen(FileName,"r")) == NULL){
      return 0;
      }
   fread(&rasterhdr,sizeof(struct rasterfile),1,fpIn);
   width = rasterhdr.ras_width;
   height= rasterhdr.ras_height;
   filesize = (width>>3) * height;
   BytesPerLine=(width>>3);

   data = new unsigned char[filesize];
   fread(data,sizeof(unsigned char),filesize,fpIn);

   rlcx.Setup(data, width, height );
   if (width>Grcl.xRight){
      S1= (double) Grcl.xRight;
      S2= (double) width;
      Scale = S1/S2;
      rlcx.Compress(width,height, Scale);
      }
   Clear();
   CurrByte=0;
   mask=0x80;
   for (i=0; i<height; i++) {
      for (j=0; j<BytesPerLine; j++) {
         for (k=0; k<8; k++) {
            x= j*8+k;
            if ( ((mask>>k) & data[CurrByte]) !=0   )
                pelval = GRIDPELON; 
              else
                pelval = 0; 
            if ( (x<GRIDXMAX) && (i<GRIDYMAX) ) {
               GRmatrix[x][i]= pelval;
            } else {
            } /* endif */
         } /* endfor */
         CurrByte++;
      } /* endfor */
   } /* endfor */

   delete data;
   fclose(fpIn);
   return 1;
}

void GRID::SetSize(){
   WinQueryWindowRect(Ghwnd,&Grcl);
   WinInvalidateRect(Ghwnd,&Grcl,FALSE);
}


