/*1.自定一個存點之X Y座標之結構*/
typedef  struct xyPoint {
  short int X;
  short int Y;
}XYPoint;
/*2.自定一個存哈克參數空間上某參數點座標值的結構，用此來記錄在參數空間中所找到之第幾條線，小格子(Cell) 其在參數空間上之位置 {I1, I2} 是註標值*/
typedef  struct htlinePoint {
  short int I1;         // 記錄參數空間上第一參數的座標值
  short int I2;         // 記錄參數空間上第二參數的座標值
}HTLinePoint ;  
/*3.自定一個資料結構來儲存哈克轉換的測線結果*/
typedef struct htline
{
  float DeltaNormAngle;    	// 存法角差為
  float DeltaNormDistance; 	// 存法線差[間隔長] 
  int ThetaNum;         	// 存法角量化後之(區間)個數
  int DistNum;          	// 存法距量化後之(區間)個數
  float MinNormdistance;  	// 存法距之最小值用
  HTLinePoint *LinePoint;   // 存在哈克參數空間上測其為一線之小房子的兩個座標index值
}HTLine;

/************************************************************/
/*哈克轉換測線演算法	*/
/*輸入	*/
/*EdgePoin	邊點集	*/
/*EdgeNum	總邊點數	*/
/*DetectedLine	測線結果	*/
/*MaxPointCount	存參數空間中一個小房子多少點可被視為有一線之門檻值*/
/*ThetaNum  	法角量化後之(區間)個數	*/
/*DistNum 	法距量化後之(區間)個數	*/
/*ImgHeight 	待測影像之高度	*/
/*ImgWidth 	待測影像之寬度	*/
 /*輸出：	*/
/*CountLine	總共測到的直線數	*/
/************************************************************/

int HTDetectLine ( XYPoint *EdgePoint, int EdgeNum, HTLine *DetectedLine, int MaxPointCount, int ThetaNum, int DistNum, int ImgHeight, int ImgWidth)
{
  /*存法角及法線差[間隔長], 為求哈克參數空間可分成多少小房子用*/
  float  DeltaNormAngle, DeltaNormDistance ;
  /*存法距之最大值和最小值用*/
  float MaxNormdistance, MinNormdistance ;
  /*將各邊點X,Y在投票時轉成參數空間(Theta, Dist)之值*/
  float Theta , Dist;
  /*用來記錄找到幾條線*/
  int CountLine  ;
  /*作為投票時在哈克空間中某邊點(x,y)所在的小房子其第一index下, 所求出之第二index之臨    時儲存變數 */
  short int TempIndex2 ;
  /*二維之參數空間(累積陣列)*/
  int **HSCellCount;
  /*依照使用者所定大小動態配置累積陣列*/
  HSCellCount=new int *[ThetaNum];
  for(int i=0;i<ThetaNum;i++)
    HSCellCount[i]=new int [DistNum];

  /*法距最大值為sqrt(x^2+y^2)*/
  MaxNormdistance=sqrt(ImgWidth*ImgWidth+ImgHeight*ImgHeight);
  /*法距負最大值為x軸之大小*/
  MinNormdistance= -1*ImgWidth; /*法距負最大為負 x 軸*/
  /*固定參數法角數目下, 其法角差為總長/個數 [總長為 pi]*/
  DeltaNormAngle = M_PI/(ThetaNum -1) ;
  /*固定參數法距數目下, 其法距差*/
  DeltaNormDistance= (MaxNormdistance - MinNormdistance)/(DistNum -1) ;
  /*二維之參數空間, HSCellCount1(i, j) 存投票數, 現設各小房子票數為 0*/
  for (int i=0;i<ThetaNum;i++ )
    for(int j=0;j<DistNum;j++ )
      HSCellCount[i][j]=0  ;
  Theta=0;
  Dist=EdgePoint[0].X*cos(Theta)+EdgePoint[0].Y*sin(Theta) ;
  for(int i=0;i<EdgeNum;i++)
    for(int j=0;j<ThetaNum;j++)
    {
       /*本應加最小法角, 因為 0 故不用, 求法角上各量化區間之法角為
       多少*/
       Theta=j*DeltaNormAngle ;
       /*求某邊點在法角下其法距為多少*/
       Dist=EdgePoint[i].X*cos(Theta)+EdgePoint[i].Y*sin(Theta) ;
       /*算所求法距屬於第幾個區間, 並且在相對應的cell投票*/
       HSCellCount[j][(int)((Dist-MinNormdistance)/DeltaNormDistance)]++;
    }
  /*初值設目前沒有線, 現在測出之線總數為0*/
  CountLine = 0 ;
  /*儲存此次測線所使用的各項參數設定*/
  DetectedLine->DeltaNormAngle=DeltaNormAngle;
  DetectedLine->DeltaNormDistance=DeltaNormDistance;
  DetectedLine->MinNormdistance=MinNormdistance;
  DetectedLine->ThetaNum=ThetaNum;
  DetectedLine->DistNum=DistNum;
  /*求有幾個小房子內投票數大於MaxPointCount, 即在哈克空間中找到幾條線*/
  for(int i=0;i<ThetaNum;i++)     
    for(int j=0;j<DistNum;j++)
    /*當有一小房子投票點數夠大時, 即認定有一線存在*/
      if (HSCellCount[i][j]>=MaxPointCount)
      {
        CountLine++;
        DetectedLine->LinePoint[CountLine].I1=i;
        DetectedLine->LinePoint[CountLine].I2=j;
      }

  for(int i=0;i<ThetaNum;i++)
    delete [] HSCellCount[i];

  delete[] HSCellCount;
  return CountLine;
}
