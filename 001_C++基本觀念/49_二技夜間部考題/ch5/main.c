#include <stdio.h>
#include <stdlib.h>
#include <math.h>//引用數學函式庫 

int main(int argc, char *argv[])
{
  float fltPI;//系統的PI定義 
  float fltpi=3.14;//自己的PI定義
  float fltinput=0;//接收存放變數 
  float flt_r01=0;//半徑1 
  float flt_r02=0;//半徑2
  float flt_2r01=0;//直徑1 
  float flt_2r02=0;//直徑2
  fltPI=4*atan(1);//atan(1)=PI/4 
  printf("請輸入圓的半徑或直徑\t"); 
  scanf("%f",&fltinput); 
  flt_r01=fltinput;//半徑1 
  flt_2r01=fltinput*2.0;//直徑1 
  flt_r02=fltinput/2.0;//半徑2
  flt_2r02=fltinput;//直徑2
  
  printf("若您剛才輸入為半徑=%f\n",flt_r01); 
  printf("則該圓的直徑為=%f\n",flt_2r01);
  printf("則該圓的周長為=%f\n",(2*fltpi*flt_r01));
  printf("則該圓的面積為=%f\n",(flt_r01*flt_r01*fltpi));
  printf("===============================================\n"); 
  printf("若您剛才輸入為直徑=%f\n",flt_2r02);
  printf("則該圓的半徑為=%f\n",flt_r02); 
  printf("則該圓的周長為=%f\n",(2*fltpi*flt_r02));
  printf("則該圓的面積為=%f\n",(flt_r02*flt_r02*fltpi));
  printf("===============================================\n"); 
  printf("以上計算的圓週率定義為=%f\n",fltpi);
  printf("C語言的圓週率定義為=%f\n",fltPI);
  printf("系統圓周率和自行定義的誤差=%f\n",(fltPI-fltpi));
  system("PAUSE");	
  return 0;
}
