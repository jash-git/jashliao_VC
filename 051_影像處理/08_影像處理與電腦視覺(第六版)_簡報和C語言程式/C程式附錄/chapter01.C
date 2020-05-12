/************************************************************/
/**  盢RGB家Α纗紇钩锣传ΘHSV家Α纗紇钩  **/
/**  把计﹍RGB紇钩                                 **/
/**  把计锣传HSV紇钩                             **/
/************************************************************/
void RGB2HSV(double RGB[3][M][N], double HSV[3][M][N])
{
  int i, j, k;
  double H1, Max, min, R, G, B ; PI=3.1415926;
  for(i=0 ;i<M ;i++)
  {
    for(j=0 ;j<N ;j++)
    {
      B = RGB [0][i][j];
      G = RGB [1][i][j];
      R = RGB [2][i][j];          
/*弄RGB獽笲衡*/
      k=0;                     
/*HSV痻皚HS㎝V index*/
/*-----------―RGBMax㎝min-----------*/
      Max=R;
      min=R;       
/*秨﹍盢Max㎝min砞ΘR*/
      if(Max<=G)
        Max=G;   
      else
        min=G;   
/*璝Max单G玥穝Max砞G玥穝min砞G*/
      if(Max<=B)
        Max=B;
      else if(min>=B)
        min=B;
/*璝Max单B玥穝Max砞B*/
/*玥璝minB玥穝min砞B*/

/*------------―︹秸H(Hue)-----------------*/
       H1=acos(0.5*((R-G)+(R-B))/sqrt(((R-G)*(R-G)+(R-B)*(G-B))));
       if(B<=G)
         HSV[k][i][j]=H1;
       else
         HSV[k][i][j]=2*PI-H1;
       k++;
/*-------------―埂㎝S----------------------*/
       HSV[k][i][j]=(Max-min)/Max;
       k++;
/*-------------―獹V----------------------*/
       HSV[k][i][j]=Max/255;
       k++;
    }/*end for j*/
  }/*end for i*/
}
