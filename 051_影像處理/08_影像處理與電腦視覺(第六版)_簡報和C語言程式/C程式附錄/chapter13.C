/******************************************************************************/
/* 功能：將RGB彩色空間轉換至CIE二維座標彩度平面空間*/
/* 參數一：原始影像的R平面之暫存區*/
/* 參數二：原始影像的G平面之暫存區*/
/* 參數三：原始影像的B平面之暫存區*/
/* 參數四：運算後的CIE影像X平面暫存區*/
/* 參數五：運算後的CIE影像Y平面暫存區*/
/* 參數六：原始影像之長*/
/* 參數七：原始影像之寬*/
/******************************************************************************/

void RGBtoCIE ( unsigned char ** OriginalImgR, unsigned char ** OriginalImgG, unsigned char ** OriginalImgB, unsigned char **CIEX, unsigned char **CIEY,int ImgHeight, int ImgWidth )
{
  int **CIEx, **CIEy, **CIEz;

  CIEx = new int *[ImgHeight];
  CIEy = new int *[ImgHeight];
  CIEz = new int *[ImgHeight];

  for(int i=0; i<ImgHeight; i++)
  {
    CIEx[i] = new int [ImgWidth];
    CIEy[i] = new int [ImgWidth];
    CIEz[i] = new int [ImgWidth];
  }

  // 將RGB空間轉成CIE的xyz 
  for(int i=0; i<ImgHeight; i++)                   
    for(int j=0; j<ImgWidth; j++)
    {
      CIEx[i][j]=(int)((0.607*OriginalImgR[i][j])+(0.174*OriginalImgG[i][j])+(0.200*OriginalImgB[i][j]));      CIEy[i][j]=(int)((0.299*OriginalImgR[i][j])+(0.587*OriginalImgG[i][j])+(0.114*OriginalImgB[i][j])) ;
      CIEz[i][j]= (int)((0.066*OriginalImgG[i][j])+(1.111*OriginalImgB[i][j])) ;
    }

//從CIE的xyz轉到XY平面座標系統
  for( int p=0; p<ImgHeight; p++)                      
    for( int q=0; q<ImgWidth; q++)
    {
      if(CIEx[p][q]!=0||CIEy[p][q]!=0||CIEz[p][q]!=0)
      {
        CIEX[p][q]= (int)(256*(CIEx[p][q])/(CIEx[p][q]+CIEy[p][q]+CIEz[p][q]));
        CIEY[p][q]= (int)(256*(CIEy[p][q])/(CIEx[p][q]+CIEy[p][q]+CIEz[p][q]));
      }
    }
}
