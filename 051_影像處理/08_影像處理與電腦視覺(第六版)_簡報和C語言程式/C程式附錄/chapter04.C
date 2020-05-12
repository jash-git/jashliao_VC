/************************************************************************************************/
/*程式中OriginalImg為輸入的灰階影像																*/
/*EdgeImg為輸出的側邊矩陣兩者大小皆為M X N														*/
/*其中M和N為影像的長和寬																		*/
/************************************************************************************************/
void Marr_Hildreth(int OriginalImg[M][N], int EdgeImg[M][N])
{
	int i,j,k;
	int PixelCounter = 0, TH;
	float TmpSum;
	int TempImg[M][N];
	
	for(i=2;i<M-2;i++)
	{
		for(j=2;j<N-2;j++)
		{
			/*帶入如式(3.3.4)之係數至輸入的灰階影響計算*/
			TempImg[i][j]=OriginalImg[i][j]*16-OriginalImg[i][j-1]*2
			-OriginalImg[i][j+1]*2-OriginalImg[i-1][j]*2
			-OriginalImg[i+1][j]*2-OriginalImg[i-1][j-1]*2
			-OriginalImg[i-1][j+1]*2-OriginalImg[i+1][j-1]*2
			-OriginalImg[i+1][j+1]*2-OriginalImg[i][j-2]*2
			-OriginalImg[i][j+2]*2-OriginalImg[i-2][j]*2
			-OriginalImg[i+2][j];
		}
	}
	/*計算Zero Crossing之臨界值*/
	TmpSum=0;
	for(i=1;i<M-1;i++)
	{
		for(j=1;j<N-1;j++)
		{
			PixelCounter++;
			TmpSum=TmpSum+abs(TempImg[i][j]);
		}
	}
	TH=2*(TmpSum/PixelCounter);
	for(i=0;i<M-2;i++)
	{
		for(j=0;j<N-2;j++)
		{
			/*找出通過臨界點之值*/
			EdgeImg[i+1][j+1]=255;/*將影像設為白點*/
			
			/*當左點大於零且右點小於零，且左右兩點之差大於臨界值
			則該點為邊點，其值設為黑點*/
			if(((TempImg[i][j+1]>=0)&&(TempImg[i+2][j+1]<=0))
			&&((TempImg[i][j+1]-TempImg[i+2][j+1])>=TH))
			{
				EdgeImg[i+1][j+1]=0;
				continue;
			}
			
			/*當左點小於零且右點大於零，且左右兩點之差大於臨界值
			則該點為邊點，其值設為黑點*/
			if(((TempImg[i][j+1]<=0)&&(TempImg[i+2][j+1]>=0))
			&&((TempImg[i+2][j+1]-TempImg[i][j+1])>=TH))
			{
				EdgeImg[i+1][j+1]=0;
				continue;
			}
			
			/*當上點大於零且下點小於零，且上下兩點之差大於臨界值
			則該點為邊點，其值設為黑點*/
			if(((TempImg[i+1][j]>=0)&&(TempImg[i+1][j+2]<=0))
			&&((TempImg[i+1][j]-TempImg[i+1][j+2])>=TH))
			{
				EdgeImg[i+1][j+1]=0;
				continue;
			}
			
			/*當上點小於零且下點大於零，且上下兩點之差大於臨界值
			則該點為邊點，其值設為黑點*/
			if(((TempImg[i+1][j]<=0)&&(TempImg[i+1][j+2]>=0))
			&&((TempImg[i+1][j+2]-TempImg[i+1][j])>=TH))
			{
				EdgeImg[i+1][j+1]=0;
				continue;
			}
		}
	}
}