/******************************************************************/
/*向量排序統計為基礎的彩色測邊器*/
/*引用函數：*/
/* #include <math.h>*/
/*常數：*/
/* Threshold  門檻值*/
/* SubImageSize	面罩大小*/
/* MedianNum	取多少個中位數來平均消除高斯雜訊*/
/* AllowImpulsiveNoise	面罩內容忍的脈衝雜訊個數*/
/*輸入變數：*/
/* InputCIEColorMap	輸入影像/
/* ImageHeight	輸入影像之列數*/
/* ImageWidth	輸入影像之行數*/
/*自定結構：*/
typedef struct
{		
  double Y;	
  double u;
  double v;
}CIEColor;		
/*輸出變數：*/
/* EdgeMap 邊圖*/
/*****************************************************************/

//---插入排序法------------------------------------------------------------
void Insertion_sort(double *a,int *b)
{
  int l = SubImageSize;
  int i,j;
  int key2;
  double key1;

  for(j=1; j<l;j++)
  {
    key1 = a[j];
    key2 = b[j];

    for (i = j-1; i>=0 && a[i]>key1; i--)
    {
      a[i+1] = a[i];
      b[i+1] = b[i];
    }

    a[i+1] = key1;
    b[i+1] = key2;
  }
}

//---測邊演算法-----------------------------------------------------------
double MaskEdgeDetector(CIEColor *ColorPixel)
{
  double VD;
  CIEColor midXi,TempColor;

  MVD=infinte;
  int *order=new int [SubImageSize];
  double *d=new double [SubImageSize];

  for(int i=0;i<SubImageSize;i++)
  {
    d[i]=0.0;
  }

  //---測量面罩內各點之間距離
  for (int m=0; m<SubImageSize; m++)
  {
    for (int n=0; n<SubImageSize; n++)
    {
      TempColor.Y=fabs(ColorPixel[m].Y - ColorPixel[n].Y);                 
      TempColor.u=fabs(ColorPixel[m].u - ColorPixel[n].u);                 
      TempColor.v=fabs(ColorPixel[m].v - ColorPixel[n].v);                 
      d[m] += TempColor.Y+TempColor.u+TempColor.v;             
    }
  }

  for (int k=0; k<SubImageSize; k++)
    order[k] = k;

  Insertion_sort(d,order);

   midXi.Y = 0;
   midXi.u = 0;
   midXi.v = 0;

  //---取數個中位數平均，以去除高斯雜訊
  for (int l=0; l<MedianNum; l++)
  {
    midXi.Y += ColorPixel[order[l]].Y;
    midXi.u += ColorPixel[order[l]].u;
    midXi.v += ColorPixel[order[l]].v;
  }
  midXi.Y /= MedianNum;
  midXi.u /= MedianNum;
  midXi.v /= MedianNum;

  //---允許面罩內脈衝雜訊，以去除脈衝雜訊
  for (int k=0; k<AllowImpulsiveNoise; k++)
  {
    TempColor.Y=fabs(ColorPixel[order[(SubImageSize-1)-k]].Y - midXi.Y);             
    TempColor.u=fabs(ColorPixel[order[(SubImageSize-1)-k]].u - midXi.u);             
    TempColor.v=fabs(ColorPixel[order[(SubImageSize-1)-k]].v - midXi.v);             
    //取得VD值
    VD=TempColor.Y+TempColor.u+TempColor.v;  
    if (VD < MVD)
      MVD = VD;   //找到最小VD為MVD
    }
    delete order;
    delete d;
    return MVD;
}

EdgeMapCreate(CIEColor **InputCIEColorMap, bool **EdgeMap int ImageHeight,int ImageWidth)
{
  double MVD;
  ImgWidth=ImageWidth;
  ImgHeight=ImageHeight;

  CIEColor *SubImageCIEColor;

  int Temp=(int)(sqrt(SubImageSize)/2); //取得面罩邊長
  int StartCount=-Temp;
  int EndCount=Temp;
  SubImageCIEColor=new CIEColor [SubImageSize];
  for(int i=1;i<ImgHeight-1;i++)      //掃瞄圖片
  {
    for(int j=1;j<ImgWidth-1;j++)
    {
      EdgeMap[i][j]=false;
      int tempNum=0;
      //掃描面罩內容
      for(int m=StartCount;m<=EndCount;m++)
      {
        for(int n=StartCount;n<=EndCount;n++)
        { 
          SubImageCIEColor[tempNum].Y =InputCIEColorMap[i+m][j+n].Y;                                          
          SubImageCIEColor[tempNum].u = InputCIEColorMap[i+m][j+n].u;
          SubImageCIEColor[tempNum].v = InputCIEColorMap[i+m][j+n].v;
          tempNum++;
        }
      }
      MVD=MaskEdgeDetector(SubImageCIEColor); //把面罩內容送入測邊演算法計算
      If (MVD>=Threshold)                           
        EdgeMap[i][j]=true;
      }
    }
  }
  delete SubImageCIEColor;
}
