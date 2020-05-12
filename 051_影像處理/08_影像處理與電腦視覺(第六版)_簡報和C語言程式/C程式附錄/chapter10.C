/*******************************************************/
/*本程式為灰階影像轉S樹的程式　　　　　　　　　　　　　　　*/
/*首先使用者必須自設維數n、誤差值th、以及允許的誤差數cntlim*/
/*在處理block的過程中，我們先求出block四個角點，　　　　　　*/
/*灰階值相減後再取絕對值，一旦大於誤差值則累加其個數；　　　*/
/*然後利用四個角點灰階值做內插，所得到內插影像與原始影像的　*/
/*如果大於誤差值的個數超過預設的誤差數( cntlim)時，則進行分割。*/
/*接下來求算分割後子block 的四個角點，並重覆上行步驟。　　　*/
/*******************************************************/

void find(int ii,int jj,int kk) 
{ 
  int ib,jb,kb,ic,jc,kc,kd; 
  int id,jd,fg,cnt;
  float x1, xa, ya, g5, g6, g7, g8, g12, g34;
  int g1,g2,g3,g4;
  cnt=0;
  /*由左上角點(ii,jj)以及目前的層數kk，可以求算出
  左下角點(ic,jj)、右上角點(ii,jc)、右下角點(ic,jc)的位置*/ 
  kc=1<<((int) (kk+1)/2); 
  kd=1<<((int) kk/2);
  ic=ii+ma/kc;
  jc=jj+ma/kd;
  id=ii;
  fg=0;
  x1=(float) ic-ii;
  /*截取四個角點的灰階值*/
  g1=(int) greyc[ii][jj] & 0xff;
  g2=(int) greyc[ic][jj] & 0xff;
  g3=(int) greyc[ii][jc] & 0xff;
  g4=(int) greyc[ic][jc] & 0xff;
  g12=(float) (g2-g1)/x1;
  g34=(float) (g4-g3)/x1;
  if((jc-jj)>1)
  {
    while(id<=ic && fg==0)
    {
      /*根據block的四個角點的灰階值做內插*/
      xa=(float)(id-ii);   
      g5=(float) g1+g12*xa;
      g6=(float) g3+g34*xa;
      g8=(float)(g6-g5)/(jc-jj);
      jd=jj;
      while(jd<=jc && fg==0)
      {
        g7=g5+g8*(jd-jj);
        if(abs(g7-(((int) greyc[id][jd])&0xff))>TH)
        {
          /*******************************************/
          /*g7 為內插出來的值                        */
          /*內插出的值與原圖的灰階值相減後取絕對值   */
          /*如果大於誤差值，則cnt++，                */
	  /*一旦cnt大於cntlim，則要切割，fg設成 1    */
	  /*******************************************/
	  if(cnt<CNTLIM)
	    cnt++;  
          else
            fg=1;
        }
	jd++;
      }
      id++;
    }
  }
  if(fg==0)
  {
    /*如果不需切割，則輸出block四個角點值*/
    fprintf(fp1,"%d %d %d %d %d %d %d\n",
    ii+xlow,jj+ylow,kk+la,(int) greyc[ii][jj] & 0xff,
    (int) greyc[ic][jj] & 0xff,(int) greyc[ii][jc] & 0xff,
    (int) greyc[ic][jc] & 0xff);
    num++;
    if((kk+la)==(2*n))
      num1++;
  }
  else            
  { 
    /*否則，使用遞迴方式繼續切割*/
    ib=ii;
    jb=jj;
    kb=kk+1;
    find(ib,jb,kb);
    if((kb&1)==1)
    {
      ib=ii+ma/kc/2;
    }
    else
    {
      jb=jj+ma/kd/2;
    }
    find(ib,jb,kb);
  }
}
