/************************************************************/
/**  功能：利用平滑法來改善影像的品質                      **/
/**  參數一：原始影像之暫存區                              **/
/**  參數二：經由平滑法運算後的結果影像之暫存區            **/
/**  參數三：原始影像之長                                  **/
/**  參數四：原始影像之寬                                  **/
/**  參數五：面罩大小(例：3:表示3×3、5:表示5×5、7:表示7×7) **/
/************************************************************/

void MeanFilter(unsigned char **arg_imgsrc_buf, unsigned char **arg_imgresult_buf, int arg_img_h, int arg_img_w, int arg_masksize)
{
  float meangray;
  int weightsum;

  /* weightsum表在面罩之總共權重 */
  weightsum = arg_masksize * arg_masksize; 
  
  for(int y=0;y<arg_img_h-2;y++)
    for(int x=0;x<arg_img_w-2;x++)
    {
      meangray = 0;  /* 初始存放經由平滑法運算結果之變數 */
      
      /* 平滑法運算主體 */
      for(int i=y;i<arg_masksize+y;i++)
        for(int j=x;j<arg_masksize+x;j++)
          meangray = meangray + (float)(arg_imgsrc_buf[i][j] /weightsum);

      /* 將經由平滑法運算後之結果存回結果影像暫存區 */
      arg_imgresult_buf[y+1][x+1] = meangray;
    }
}
