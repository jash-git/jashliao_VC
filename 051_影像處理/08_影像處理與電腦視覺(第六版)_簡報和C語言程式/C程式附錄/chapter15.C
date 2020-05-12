// 水平翹曲變形使用 YUV420 格式
#include<stdio.h>
#include<stdlib.h>


// 宣告變數及函式
structParameter
{
	double focal;
	double baseline;
	double Znear;
	double Zfar;
	int height;
	int width;
	int frameNum;
	FILE *origColorMap; // 目前視角的 color 檔案
	FILE *origDepthMap; // 目前視角的 depth 檔案
	FILE *warpColorMap; // 虛擬視角的 color 檔案
	// 目前視角 color 的 YUV
	unsigned char **origColorY;
	unsigned char ***origColorUV;
	// 目前視角 depth 的 YUV
	unsigned char **origDepthY;
	unsigned char ***origDepthUV;
	// 虛擬視角 color 的 YUV
	unsigned char **warpColorY;
	unsigned char ***warpColorUV;
};


// 記憶體操作相關函式宣告
void allocat3DMemory(unsigned char ****target, int dim1, int dim2, int dim3);
void allocat2DMemory(unsigned char ***target, int dim1, int dim2);
void free3DMemory(unsigned char ***target, int dim1, int dim2);
void free2DMemory(unsigned char **target, int dim1);
void InitMemory(Parameter *para);
void FreeMemory(Parameter *para);


//disparity 相關函式宣告525 第 15 章　三維影像的彩現
double DeQuantization(int DepthValue, double Znear, double Zfar);
double DoDisparity(double RealDistance, double Focal, double Baseline);
int Rounding(double Disparity);
int GetDisparity(int depthValue, Parameter *para);
void GenerateDisparityArray(Parameter *para, int *disparityArray);


// 讀寫 YUV 圖檔相關函式宣告
void ReadOneFrameYUV(unsigned char **Y, unsigned char ***UV, int height, int width, FILE *file);
void WriteOneFrameYUV(unsigned char **Y, unsigned char ***UV, int height, int width, FILE *file);


// 翹曲變形相關函式宣告
void Warpping(Parameter *para, int *disparityArray);
void ClearWarpYUV(Parameter *para);


// 主程式
void main(intargc, char* argv[])
{
	// 從參數列取得相關參數
	Parameter *para = (Parameter *)calloc(1, sizeof(Parameter));
	double baseline_curr;
	double baseline_target;
	int disparityArray[256];
	int frameIndex = 0, widthIndex = 0, HeightIndex = 0;
	if (argc< 12)
	{
		printf(" 參數不夠~~\n");
		return;
	}
	para->height = atoi(argv[1]); // 畫面高度
	para->width = atoi(argv[2]); // 畫面寬度
	para->frameNum = atoi(argv[3]); // 影片張數
	baseline_curr = atof(argv[4]); // 目前視角的 baseline
	baseline_target = atof(argv[5]); // 虛擬視角的 baseline
	para->baseline = baseline_target - baseline_curr; // 兩視角間的 baseline 位移
	para->focal = atof(argv[6]); // 攝影機焦距
	para->Znear = atof(argv[7]); // 攝影機最近深度
	para->Zfar = atof(argv[8]); // 攝影機最遠深度
	// 開啟檔案
	para->origColorMap = fopen(argv[9], "rb");
	para->origDepthMap = fopen(argv[10], "rb");
	para->warpColorMap = fopen(argv[11], "wb");
	// 初始化相關變數的記憶體
	InitMemory(para);
	// 計算深度值 0-255 的 disparity
	GenerateDisparityArray(para, disparityArray);
	for (frameIndex = 0; frameIndex<para->frameNum; frameIndex++)
	{
		printf("Processing.....(%d/%d)\n", frameIndex, para->frameNum);
		// 讀取一張 frame
		Re adOneFrameYUV(para->origColorY, para->origColorUV, para->height,
		para->width, para->origColorMap);
		Re adOneFrameYUV(para->origDepthY, para->origDepthUV, para->height, para->width, para->origDepthMap);
		// 將暫存區清空
		ClearWarpYUV(para);
		// 翹曲變形函式
		Warpping(para, disparityArray);
		// 寫入一張 frame
		Wr iteOneFrameYUV(para->warpColorY, para->warpColorUV, para->height, para->width, para->warpColorMap);
	}
	// 關閉檔案
	fclose(para->origColorMap);
	fclose(para->origDepthMap);
	fclose(para->warpColorMap);
	// 釋放記憶體
	FreeMemory(para);
}


// 配置三維記憶體
void allocat3DMemory(unsigned char ****target, intdim1, intdim2, intdim3)
{
	int dim1Index, dim2Index;
		*target = (unsigned char ***)calloc(dim1, sizeof(unsigned char **));
	for (dim1Index = 0; dim1Index<dim1; dim1Index++)
	{
		(*target)[dim1Index] = (unsigned char **)calloc(dim2, sizeof(unsigned char *));
		for (dim2Index = 0; dim2Index<dim2; dim2Index++)
		{
			(*target)[dim1Index][dim2Index] = (unsigned char *)calloc(dim3, sizeof(unsigned char));
		}
	}
}


// 配置二維記憶體
void allocat2DMemory(unsigned char ***target, intdim1, intdim2)
{
	int dim1Index;
	*target = (unsigned char **)calloc(dim1, sizeof(unsigned char *));
	for (dim1Index = 0; dim1Index<dim1; dim1Index++)
		(*target)[dim1Index] = (unsigned char *)calloc(dim2, sizeof(unsigned char));
}


// 釋放三維記憶體
void free3DMemory(unsigned char ***target, intdim1, intdim2)
{
	int dim1Index, dim2Index;
	for (dim1Index = 0; dim1Index<dim1; dim1Index++)
	{
		for (dim2Index = 0; dim2Index<dim1; dim2Index++)
			free(target[dim1Index][dim2Index]);

		free(target[dim1Index]);
	}
	free(target);
}


// 釋放二維記憶體
void free2DMemory(unsigned char **target, intdim1)
{
	int dim1Index = 0, dim2Index = 0;
	for (dim1Index = 0; dim1Index<dim1; dim1Index++)
		free(target[dim1Index]);
	free(target);
}


// 配置記憶體給相關變數
void InitMemory(Parameter *para)
{
	allocat2DMemory(&(para->origColorY), para->height, para->width);
	allocat2DMemory(&(para->warpColorY), para->height, para->width);
	allocat2DMemory(&(para->origDepthY), para->height, para->width);
	allocat3DMemory(&(para->origColorUV), 2, para->height, para->width);
	allocat3DMemory(&(para->warpColorUV), 2, para->height, para->width);
	allocat3DMemory(&(para->origDepthUV), 2, para->height, para->width);
}


// 釋放記憶體
void FreeMemory(Parameter *para)
{
	free2DMemory(para->origColorY, para->height);
	free2DMemory(para->warpColorY, para->height);
	free2DMemory(para->origDepthY, para->height);
	free3DMemory(para->origColorUV, 2, para->height);
	free3DMemory(para->warpColorUV, 2, para->height);
	free3DMemory(para->origDepthUV, 2, para->height);
}


// 對深度值反量化，取得實際深度值
double DeQuantization(int DepthValue, double Znear, double Zfar)
{
	double RealDistance;
	RealDistance = 1 / ((DepthValue / 255.0)*(1 / Znear - 1 / Zfar) + 1 / Zfar);
	return RealDistance;
}


// 給予實際深度值，計算 disparity
double DoDisparity(double RealDistance, double Focal, double Baseline)
{
	double Disparity;
	Disparity = Focal*Baseline / RealDistance;
	return Disparity;
}


// 四捨五入
int Rounding(double Disparity)
{
	if (Disparity >= 0.0f)
		return ((int)(Disparity + 0.5f));

	return ((int)(Disparity - 0.5f));
}


// 給予一個深度值，獲得一個 disparity
int GetDisparity(int depthValue, Parameter *para)
{
	double realZ;
	double disparity;
	int RoundDisparity;
	realZ = DeQuantization(depthValue, para->Znear, para->Zfar);
	disparity = DoDisparity(realZ, para->focal, para->baseline);
	RoundDisparity = Rounding(disparity);
	return RoundDisparity;
}


// 產生深度值 0 至 255 的 disparity
void GenerateDisparityArray(Parameter *para, int *disparityArray)
{
	int depthValue;
	for (depthValue = 0; depthValue<256; depthValue++)
		disparityArray[depthValue] = GetDisparity(depthValue, para);
}


// 讀一張 YUV420 的圖
void ReadOneFrameYUV(unsigned char **Y, unsigned char ***UV, int height,
int width, FILE *file)
{
	int heightIndex, uvIndex;
	for (heightIndex = 0; heightIndex<height; heightIndex++)
		fread(Y[heightIndex], sizeof(unsigned char), width, file);
	for (uvIndex = 0; uvIndex<2; uvIndex++)
	for (heightIndex = 0; heightIndex<height / 2; heightIndex++)
	{
		fread(UV[uvIndex][heightIndex], sizeof(unsigned char), width / 2, file);
	}
}


// 寫一張 YUV420 的圖
void WriteOneFrameYUV(unsigned char **Y, unsigned char ***UV, int height,
	int width, FILE *file)
{
	int heightIndex, uvIndex;
	for (heightIndex = 0; heightIndex<height; heightIndex++)
		fwrite(Y[heightIndex], sizeof(unsigned char), width, file);
	for (uvIndex = 0; uvIndex<2; uvIndex++)
	for (heightIndex = 0; heightIndex<height / 2; heightIndex++)
	{
		fwrite(UV[uvIndex][heightIndex], sizeof(unsigned char), width / 2, file);
	}
	fflush(file);
}


// 翹曲變形程式
void Warpping(Parameter *para, int *disparityArray)
{
	int widthIndex = 0, heightIndex = 0;
	for (heightIndex = 0; heightIndex<para->height; heightIndex++)
	for (widthIndex = 0; widthIndex<para->width; widthIndex++)
	{
		int disparity;
		// 獲得該深度值的 disparity
		disparity = disparityArray[para->origDepthY[heightIndex][widthIndex]];
		// 邊界判斷
		if (widthInd ex + disparity > 0 && widthIndex + disparity < para->width)
		{
			// 一維翹曲變形，多對一時以最後覆蓋的像素為主
			para->warpColorY[heightIndex][widthIndex + disparity] = para->origColorY[heightIndex][widthIndex];
			para->warpColorUV[0][heightIndex / 2][(widthIndex + disparity) / 2] = para->origColorUV[0][heightIndex / 2][widthIndex / 2];
			para->warpColorUV[1][heightIndex / 2][(widthIndex + disparity) / 2] = para->origColorUV[1][heightIndex / 2][widthIndex / 2];
		}
	}
}


// 清除翹曲變數暫存區
void ClearWarpYUV(Parameter *para)
{
	int heightIndex, widthIndex, uvIndex;
	for (heightIndex = 0; heightIndex<para->height; heightIndex++)
	for (widthIndex = 0; widthIndex<para->width; widthIndex++)
		para->warpColorY[heightIndex][widthIndex] = 0;

	for (uvIndex = 0; uvIndex<2; uvIndex++)
	for (heightIndex = 0; heightIndex<para->height; heightIndex++)
	for (widthIndex = 0; widthIndex<para->width; widthIndex++)
	{
		// UV 無值時為 128
		para->warpColorUV[uvIndex][heightIndex][widthIndex] = 128;
	}
}