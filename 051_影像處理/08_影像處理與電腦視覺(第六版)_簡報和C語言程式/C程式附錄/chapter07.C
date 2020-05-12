/*1.	自定一個存點之X Y座標之結構。*/
typedef  struct xyPoint {
short int X;
  	short int Y;
}XYPoint;
/* 2.	自定一個存圓心座標和半徑之結構。*/
typedef struct circle{
short int CCX;
short int CCY;
short int Rr;
}CIRCLE;


/******************************************************************/
/*隨機式測圓法(八個輸入變數與一個輸出變數)	*/
/*輸入變數：		*/
/*EdgePoin	邊點集	*/
/*EdgeNum	總邊點數	*/
/*ThresholdRnd	測線結果	*/
/*ThresholdCoCircleDist	存第四點和前三點組成之圓周上的距離	*/
/*	多少內算共圓	*/
/*Threshold2PDist	取為圓之三點其彼此間距離差平方要多	*/
/*	少以上之門檻值	*/
/*ThresholdCircleRatio	記錄找到之圓點數要符合理論上圓點數	*/
/*	[4*根號2*半徑] 之多少百分比	*/
/*ThresholdCirclePoint	有多少點可視為共圓, 即多少個其它點	*/
/*	和找到之圓近才當這些點視為一個圓	*/
/*CircleData 	所測到的圓的資料(圓心和半徑)	*/
/*輸出變數：		*/
/*CountLine 	總共測到的圓個數	*/
/*****************************************************************/
int DetectCircleRand1(XYPoint *EdgePoint,int EdgeNum, int ThresholdRnd, 
int ThresholdCoCircleDist, int Threshold2PDist,
int ThresholdCircleRatio, int ThresholdCirclePoint, 
CIRCLE *CircleData)
{
  XYPoint TempEdgePoint[6000] ;
/*存所抓到之隨機四點在TempEdgePoint 一維陣列中的位置*/
  int  p[5]; 
  /*點 1 到 RestEdgeNum 是未視為線點之邊點*/
int RestEdgeNum ; 
/*在沒有確定所抓之點真的是為一條線上之點前,RestEdgeNum 不能變*/
/*所以用 TempRestNum 來暫時存臨時改變之所餘要處理的邊點數*/
int TempRestNum ;    
/*記錄目前已進行抓多少次之三點失敗及抓多少次三點其外積皆不成功[不符合為線]便結束程式之門檻值*/
int RndCount; 
/*用於迴圈控制指標用*/
int i;
/*用於在邊點中隨機抓四點之迴圈控制指標*/
int i4;    
/*隨機抓後, 若有要交換時, 用此來暫存交換之邊點 [存邊點 x,y 座標]*/
XYPoint SwapTemp; 
/*存用 random 抓出之整數值, 用此值來抓出一維邊點陣列中之某點*/
int RndValue; 
/*存四點中 4 組之任三點之所得之圓心的 x, y 座標*/
float Cx123,Cy123, Cx124,Cy124, Cx134,Cy134, Cx234,Cy234; 
/*/為方便方程式計算, 先求出圓心(a,b)及TempD, 再求半徑 r*/
float TempD123, TempD124, TempD134, TempD234; 
/*存四點中 4 組之任三點所求出之圓半徑*/
float Radius123, Radius124, Radius134, Radius234; 
/*存隨機抓 4 點中, 第四點到前三點組成之圓周上的距離*/
float Dist4To123, Dist3To124, Dist2To134, Dist1To234;
/*分別存所求圓之圓心(a=CenterX,b=CenterY) 及半徑 r=RadiusR*/
float CenterX,CenterY,RadiusR;
/*存 X1^2+Y1^2 用, 即第一點和原點之距離的平方*/
int Square1; 
/*存 Xi^2+Yi^2 用, 即第 2,3,4 點和原點之距離的平方*/
int Square2,Square3,Square4; 
/*為程式中表達方便, 把所抓到之隨機 4 個點座標值放在此變數上*/
int X1,Y1, X2,Y2, X3,Y3, X4,Y4; 
/*存第2,3,4點到第一點之 x,y 上的差值*/
int X21,Y21; 
int X31,Y31; 
int X41,Y41; 
int X32,Y32; 
int X42,Y42; 
int X43,Y43; 
int denom123; 
/* denom234 = 2[(X3-X2)(Y4-Y2)-(Y3-Y2)(X4-X2)], 為解 123 圓心 a,b 時要用到之分母 */
int denom124,denom134,denom234 ; 
/*固定某為圓之三點下, 記錄目前有多少第四點和這三點共圓*/
int CountCirclePoint; 
/*找到圓時,存其它第四點和所找到之三點組成之圓周上的距離*/
float DistToCircle; 
/*用來記錄找到幾個圓*/
int CountCircle; 
/*存所找到之線要畫出時之顏色*/
int DrawColor;  
/*為每次取亂數時皆不同, 所以用此指令*/
randomize();   
/*把EdgePoint在TempEdgePoint上備份,以作為後面處理時之可能改變*/
for( i = 1;i<=EdgeNum;i++)  
TempEdgePoint[i] = EdgePoint[i];
/*對一些變數值初時化*/
CountCircle = 0; 
RndCount = 0; 
RestEdgeNum = EdgeNum; 
TempRestNum = RestEdgeNum; 
while ( RndCount <= ThresholdRnd && RestEdgeNum >= 
ThresholdCirclePoint )
{
  /*抓四點來看是否有為圓之證據*/         
  for(i4 = 1; i4<=4;i4++)  
  {
    /*記錄下所抓之第i4點為目前TempEdgePoint邊點陣列的位置*/
    /*因為所抓之點換到後面, 所以其為目前最後之點*/
    p[i4] = TempRestNum; 
    RndValue = ( rand() % TempRestNum + 1); 
    /*抓到之點放到後面的三點上*/
    SwapTemp.X = TempEdgePoint[RndValue].X; 
    SwapTemp.Y = TempEdgePoint[RndValue].Y;
    TempEdgePoint[RndValue].X = TempEdgePoint[TempRestNum].X;
    TempEdgePoint[RndValue].Y = TempEdgePoint[TempRestNum].Y;
    TempEdgePoint[TempRestNum].X = SwapTemp.X;      
TempEdgePoint[TempRestNum].Y = SwapTemp.Y;
    TempRestNum = TempRestNum - 1; /*臨時性的邊點數少一*/
 } 
 /*所抓之四點存在 TempEdgePoint 之 p[1],p[2],p[3],p[4] 位置上*/

  X1=TempEdgePoint[p[1]].X;
  Y1=TempEdgePoint[p[1]].Y;
  X2=TempEdgePoint[p[2]].X;
  Y2=TempEdgePoint[p[2]].Y;
  X3=TempEdgePoint[p[3]].X;
  Y3=TempEdgePoint[p[3]].Y;
  X4=TempEdgePoint[p[4]].X;
  Y4=TempEdgePoint[p[4]].Y;
  /*存所抓之四點之 X^2+Y^2 值*/
  Square1= TempEdgePoint[p[1]].X*TempEdgePoint[p[1]].X+
TempEdgePoint[p[1]].Y*TempEdgePoint[p[1]].Y; 
  Square2= TempEdgePoint[p[2]].X*TempEdgePoint[p[2]].X+
TempEdgePoint[p[2]].Y*TempEdgePoint[p[2]].Y; 
  Square3= TempEdgePoint[p[3]].X*TempEdgePoint[p[3]].X+
TempEdgePoint[p[3]].Y*TempEdgePoint[p[3]].Y; 
  Square4= TempEdgePoint[p[4]].X*TempEdgePoint[p[4]].X+
TempEdgePoint[p[4]].Y*TempEdgePoint[p[4]].Y; 
  /*求第2,3,4點到第1點之X與Y方向上的差值*/
  X21=X2-X1; 
  Y21=Y2-Y1; 
  X31=X3-X1; 
  Y31=Y3-Y1; 
  X41=X4-X1; 
  Y41=Y4-Y1; 
  X32=X3-X2; 
  Y32=Y3-Y2; 
  X42=X4-X2; 
  Y42=Y4-Y2; 
  X43=X4-X3; 
  Y43=Y4-Y3; 

  /*存兩點間之距離用*/
  int SquareDist21 = (X21*X21)+(Y21*Y21); 
  int SquareDist31 = (X31*X31)+(Y31*Y31);
  int SquareDist41 = (X41*X41)+(Y41*Y41);
  int SquareDist32 = (X32*X32)+(Y32*Y32);
  int SquareDist42 = (X42*X42)+(Y42*Y42);
  int SquareDist43 = (X43*X43)+(Y43*Y43);
  /*解由123,124,134,234,點組成之圓的圓心*/
  denom123 = 2*(X21*Y31 - X31*Y21); 
  denom124 = 2*(X21*Y41 - X41*Y21); 
  denom134 = 2*(X31*Y41 - X41*Y31);
  denom234 = 2*(X32*Y42 - X42*Y32);
  /*求第4 點和所算出之圓之差的過程*/
  if (denom123==0) /*分母為 0 表示, 234 三點共線, 不會為圓*/
    Dist4To123= 1000;
  else 
  {
    Cx123=((Square2-Square1)*(Y31)-(Square3-Square1)*(Y21))/denom123;
    Cy123=((Square3-Square1)*(X21)-(Square2-Square1)*(X31))/denom123;
    /*2*X1*a+2*Y1*b+TempD123=X1^2+Y1^2 [由方程式可得]*/
    TempD123= Square1- 2*X1*Cx123 - 2*Y1*Cy123; 
    Radius123= sqrt(TempD123 + Cx123 * Cx123 + Cy123 * Cy123);
    /*TempD= r^2-a^2-b^2 , or r^2 = TempD + a^2 + b^2*/
    Dist4To123=sqrt((X4-Cx123)*(X4-Cx123)+(Y4-Cy123)*(Y4-Cy123))- 
    Radius123;
    /*第四點和圓周之距離為和圓心之距離跟圓半徑之差的絕對值*/
    if (Dist4To123<0)
    Dist4To123 = -1 * Dist4To123; 
  }

  /*求第 3 點和所算出之圓之差的過程*/
  if (denom124==0) // 分母為 0 表示, 234 三點共線, 不會為圓   
    Dist3To124= 1000 ;
  else
 {
    Cx124=((Square2-Square1)*(Y41)-(Square4-Square1)*(Y21))/denom124;
    Cy124=((Square4-Square1)*(X21)-(Square2-Square1)*(X41))/denom124;
    TempD124= Square1- 2*X1*Cx124 - 2*Y1*Cy124; 
    Radius124= sqrt(TempD124 + Cx124 * Cx124 + Cy124 * Cy124);
    Dist3To124=sqrt((X3-Cx124)*(X3-Cx124)+ (Y3-Cy124)*(Y3-Cy124))- 
    Radius124;
    if (Dist3To124<0)
        Dist3To124 = -1 * Dist3To124 ; 
  }
  /*求第 2 點和所算出之圓之差的過程*/
  if (denom134==0) /*分母為 0 表示, 234 三點共線, 不會為圓*/   
    Dist2To134= 1000;
  else
  {
    Cx134=((Square3-Square1)*(Y41)-(Square4-Square1)*(Y31))/denom134;
    Cy134=((Square4-Square1)*(X31)-(Square3-Square1)*(X41))/denom134;
    TempD134= Square1- 2*X1*Cx134 - 2*Y1*Cy134; 
    Radius134= sqrt(TempD134 + Cx134 * Cx134 + Cy134 * Cy134);
    Dist2To134 = sqrt((X2-Cx134)*(X2-Cx134)+ (Y2-Cy134)*(Y2-Cy134))- 
    Radius134;
    if (Dist2To134<0) 
       Dist2To134 = -1 * Dist2To134;
  }

  /*求第 1 點和所算出之圓之差的過程*/
  if (denom234==0)/*分母為 0 表示, 234 三點共線, 不會為圓*/  
    Dist1To234= 1000;
  else 
  {
    Cx234=((Square3-Square2)*(Y42)-(Square4-Square2)*(Y32))/denom234;
    Cy234=((Square4-Square2)*(X32)-(Square3-Square2)*(X42))/denom234;
    TempD234= Square2- 2*X2*Cx234 - 2*Y2*Cy234;
    Radius234= sqrt(TempD234 + Cx234 * Cx234 + Cy234 * Cy234);
    Dist1To234 = sqrt((X1-Cx234)*(X1-Cx234)+ (Y1-Cy234)*(Y1-Cy234))- 
    Radius234;
    if (Dist1To234<0)
    Dist1To234 = -1 * Dist1To234;
  }
/*上面四組資料皆算好了, 下面開始判斷那一組之圓, 可使另一點也在圓上, 即該組為可能之圓*/
/*本指令對三點組成之圓的三點間距離有限制*/
  if((Dist4To123>ThresholdCoCircleDist || SquareDist21 <=Threshold2PDist ||
    SquareDist31 <=Threshold2PDist || SquareDist32<=Threshold2PDist) &&
    (Dist3To124>ThresholdCoCircleDist || SquareDist21<=Threshold2PDist ||
    SquareDist41<=Threshold2PDist || SquareDist42<=Threshold2PDist) &&
    (Dist2To134>ThresholdCoCircleDist || SquareDist31<=Threshold2PDist ||
    SquareDist41<=Threshold2PDist || SquareDist43<=Threshold2PDist) &&
    (Dist1To234>ThresholdCoCircleDist || SquareDist32<=Threshold2PDist ||
    SquareDist42<=Threshold2PDist || SquareDist43<=Threshold2PDist)  )
  {   

    /* 第四點離任三點之圓過大, 表示這次所找之四點不存在共圓之證明, 
    增加抓四點之失敗次數一次*/
    RndCount = RndCount + 1;  
    /*抽樣的四點不成功, 所以TempRestNum要向前推四點*/
    TempRestNum = TempRestNum + 4; 
  }
  else /*找到一組三點之圓和第4點很近, 即這圓可能真是存在圖上之圓*/
  {
    /*存符合條件之圓, 其和第 4 點距離最近者*/
    float MinDist=ThresholdCoCircleDist; 
    if ( Dist4To123 <= ThresholdCoCircleDist && 
        SquareDist21>Threshold2PDist &&
        SquareDist31>Threshold2PDist && SquareDist32>Threshold2PDist )
    { /*123 三點共圓，則記下找到之圓心和半徑*/
      CenterX=Cx123;   
      CenterY=Cy123;
      RadiusR=Radius123;
      MinDist = Dist4To123;
    }
    
    if (Dist3To124 < MinDist  && SquareDist21>Threshold2PDist &&
        SquareDist41>Threshold2PDist && SquareDist42>Threshold2PDist )
    { /*124 三點共圓*/
      CenterX=Cx124; 
      CenterY=Cy124;
      RadiusR=Radius124;
      MinDist = Dist3To124;
    }
    if ( Dist2To134 < MinDist && SquareDist31>Threshold2PDist &&
         SquareDist41>Threshold2PDist && SquareDist43>Threshold2PDist )
    {/*134 三點共圓*/
      CenterX=Cx134;
      CenterY=Cy134;
      RadiusR=Radius134;
      MinDist = Dist2To134;
    }
if ( Dist1To234 < MinDist && SquareDist32>Threshold2PDist &&
     SquareDist42>Threshold2PDist && SquareDist43>Threshold2PDist )
{ /* 234 三點共圓*/
  CenterX=Cx234;
  CenterY=Cy234;
  RadiusR=Radius234;
}
CountCirclePoint=0;
/*三點視為共圓時, 繼續判斷其它點是否為此線上點*/
for(i = TempRestNum ; i >=1 ; i-- ) 
{
 DistToCircle = sqrt((TempEdgePoint[i].X - CenterX)*(TempEdgePoint[i].X
                        - CenterX)+(TempEdgePoint[i].Y-CenterY)*
                        (TempEdgePoint[i].Y-CenterY))- RadiusR;
 /*求其它點到所找圓周上之距離, 依此來判斷這些點是否在圓上*/
 if (DistToCircle <0 )  
   DistToCircle = -1 * DistToCircle; 
 /*可視目前這個邊點在這圓周上*/
 if ( DistToCircle <=  ThresholdCoCircleDist ) 
 {
     CountCirclePoint = CountCirclePoint + 1;
     /*抓到之點為圓上點時, 放到後面以表示已處理找到了*/
     /*把抓到可視為找到之圓上點之其它點和最後面之點交換*/
     SwapTemp.X = TempEdgePoint[i].X; 
     SwapTemp.Y = TempEdgePoint[i].Y;
     TempEdgePoint[i].X = TempEdgePoint[TempRestNum].X; 
     TempEdgePoint[i].Y = TempEdgePoint[TempRestNum].Y;
     TempEdgePoint[TempRestNum].X = SwapTemp.X;
     TempEdgePoint[TempRestNum].Y = SwapTemp.Y;
     TempRestNum = TempRestNum - 1; 
   } 
}
/*要超過理論圓之點數之某百分比才算其為找到之圓*/
if(CountCirclePoint <= 4*sqrt(2)*RadiusR*ThresholdCircleRatio/100)
{
    TempRestNum = RestEdgeNum;
    RndCount = RndCount + 1;
}
else /*前面所找到符合組成線之點數夠大認為其為圓時*/
{
    CircleData[CountCircle].CCX=CenterX;
    CircleData[CountCircle].CCY=CenterY;
    CircleData[CountCircle].Rr=RadiusR;
    CountCircle = CountCircle + 1; 
    RndCount = 0  ; 
    /*組成線之點皆向後移了, 所以最後點位置 RestEdgeNum 向前推*/
     RestEdgeNum = TempRestNum; 
} 
} 
} 
return CountCircle;
}

		
  








	
	
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
