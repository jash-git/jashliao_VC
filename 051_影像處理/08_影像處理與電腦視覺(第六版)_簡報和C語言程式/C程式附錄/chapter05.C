/*******************************************************************************/
/* Otsu 演算法  */
/* 輸入	*/
/* k:代表分群群數,即為預求門檻數加1  */
/* 使用到的global變數  */
/* thresholds[]:存放相對於compact histogram之index的門檻值  */
/* Index[i]:代表compact histogram index i相對應之灰階值  */
/* Sum_H[]: compact histogram H[]的累加個數陣列;Sum_H[i] =H[i]+Sum_H[i-1]  */
/* Sum_i[]: 累加灰階值乘上個數陣列;Sum_i[i] = Index[i]*H[i]+Sum_i[i-1]	*/
/* Sum_i2[]: 累加灰階值平方乘上個數陣列  */
/* Sum_i2[i] =Index[i]*Index[i]*H[i]+Sum_i2[i-1]  */

/* 輸出	*/
/* Min_thresholds[]:代表求得的thresholds值(相對於histogram),在程式過程中存暫時	*/
/* 求得的thresholds compact histogram index值	*/
/************************************************************/
void Ostu(int k) /*k為群數*/
{    /*設定區域變數*/
  int i; 
  int p;
  float min_variance = 100000000;
  float variance;
  long count;
  double mean; /*平均值*/
  double mean2; /*平均值的平方*/
  /***********************************************/
  /* 初設  */
  /* thresholds[],exe:thresholds[0]=0,  */
  /* thresholds[1]=0,thresholds[2]=1,...,  */
  /* thresholds[i]=thresholds[i-1]+1,...,  */
  /* thresholds[k-1]=thresholds[k-2],thresholds[k]=m-1;  */
  /***********************************************/
     
  thresholds[0] = 0;
  thresholds[k] = m-1; /*m是整張影像中有灰階值的個數  */
  thresholds[1] = 0;
  for(i=2;i<k;i++)
    thresholds[i]=thresholds[i-1]+1;
  thresholds[k-1]--; /*減1是為了用於第1次執行while指令  */
  /*利用full search方式求得Ostu所提之最小變異數和  */
  while(1)
  {
    thresholds[k-1]++; /*最大之門檻值(存compact histogram index)加1  */
    /*限制: 第p個thresholds值不能大於 (m-1)-(k-1-p)  */
    /*檢查前面 1..k-1門檻值有無違反限制,違反時需做調整,ex: 類似時鐘概念,  */
    /*秒鐘超過59秒時,分鐘得加1*/

    p = k-1;
    while(thresholds[p] > (m-1)-(k-1-p))
    {
      p--;
      if(p == 0) /*如調整到需要調整index 0則full search完畢  */
        break;
        thresholds[p]++;
    }
    
    if (p == 0)
       break;
    else
    {
      /*調整調整位置p之後(p+1...k-1)之thresholds值為thresholds[p+1] =  */ 
      /*thresholds[p]+1,...,thresholds[k-1]=thresholds[k-2]+1  */
      for(i=p+1;i<k;i++)
        thresholds[i] = thresholds[i-1]+1;
    }
    /*計算 within-variance*/
    variance = 0;
    for(i=0;i<k;i++)
    {
      if (i == 0)
      {
        count = Sum_H[thresholds[i+1]];
        mean = Sum_i[thresholds[i+1]];
        mean2 = Sum_i2[thresholds[i+1]];
      }
      else
      {
        count = Sum_H[thresholds[i+1]]-Sum_H[thresholds[i]];
        mean = (Sum_i[thresholds[i+1]]-Sum_i[thresholds[i]]);
        mean2 = (Sum_i2[thresholds[i+1]]-Sum_i2[thresholds[i]]);
      }
      if (count != 0)
        variance=variance+count/(float)N*(mean2/(float)count-(mean*mean)/(float)count/(float)count);
    }
    /*求得的within-variance比min_variance小,則換調Min_thresholds[]*/
    if(variance < min_variance)
    {
      min_variance = variance;
      for(i=0;i<k+1;i++)
      Min_thresholds[i] = thresholds[i];
    }
  }
  /*將 Min_thresholds[] 之值(原為compact histogram index)轉換為histogram index值*/
  for(i=0;i<k+1;i++)
    Min_thresholds[i] = Index[Min_thresholds[i]];
}

