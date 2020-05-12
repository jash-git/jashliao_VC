#include <iostream>
#include <cmath>
#include <cstdio>
#include <malloc.h>
#include <time.h>
#include "FreeImage.h"
#define  PI  3.141592645

using namespace std;


// 自定义一个4字节的结构体
class byte4
{
public:
    BYTE r; // 用于存放 red
    BYTE g; // 用于存放 green
    BYTE b; // 用于存放 blue
    BYTE a; // 用于存放 alpha
};

static int maskHeight = 3; // 掩模高度
static int maskWidth  = 3; // 掩模宽度
//高斯滤波掩模
float mask[3][3] =
    {
    {0.0751 ,  0.1238  , 0.0751},
    {0.1238 ,  0.2042  , 0.1238},
    {0.0751 ,  0.1238  ,  0.0751}};

//串行图像滤波
void cpu_filter(byte4** inbuf,  byte4** outbuf, int w, int h)
{
    for(int row = 1; row < h - 1; row ++)
    {
        for(int col = 1; col < w - 1; col ++)
        {
            outbuf[row][col].r = 0;
            outbuf[row][col].g = 0;
            outbuf[row][col].b = 0;
            outbuf[row][col].a = 0;
            float t1 = 0, t2 = 0, t3 = 0, t4 = 0;
            for(int i = 0; i < maskHeight; i ++)
                for(int j = 0; j < maskWidth; j++)
                {
                     t1 += inbuf[row + i - 1][col + j - 1].r * mask[i][j];
                     t2 += inbuf[row + i - 1][col + j - 1].g * mask[i][j];
                     t3 += inbuf[row + i - 1][col + j - 1].b * mask[i][j];
                     t4 += inbuf[row + i - 1][col + j - 1].a * mask[i][j];
                }

            outbuf[row][col].r = (int)t1;
            outbuf[row][col].g = (int)t2;
            outbuf[row][col].b = (int)t3;
            outbuf[row][col].a = (int)t4;
        }
    }
}

//CPU旋转图像
void cpu_rotate(byte4** inbuf, byte4** outbuf, int w, int h, float angle)
{
    if(w % 2 == 0) w --;
    if(h % 2 == 0) h --;
    int i, j;
    int xc = w/2;
    int yc = h/2;

    float cosTheta = cos(PI * angle/180);
    float sinTheta = sin(PI * angle/180);

    for(i = 0; i < h; i++)
    {
        for(j=0; j< w; j++)
        {
            int xpos = (int)( (i-xc)*cosTheta  + (j-yc)*sinTheta + xc );
            int ypos = (int)( -(i-xc)*sinTheta + (j-yc)*cosTheta + yc );

            if(xpos>=0 && ypos>=0 && xpos<h && ypos < w )
                outbuf[xpos][ypos] = inbuf[i][j];
        }
    }
}

int main()
{
    FreeImage_Initialise(TRUE);
    /*
    // https://blog.csdn.net/silangquan/article/details/44056445
    FIBITMAP * JPEG = FreeImage_Load(FIF_JPEG, "C:\\Users\\usernb\\Documents\\ChangeDesktop\\02_RGB.JPG", JPEG_DEFAULT);
    //获取影像的宽高，都以像素为单位
    int Width = FreeImage_GetWidth(JPEG);
    int Height = FreeImage_GetHeight(JPEG);
    cout << "Width: " << Width <<  "\nHeight: "  <<Height << std::endl;
    FreeImage_Unload(JPEG);
    */

    /*
    //http://www.makaidong.com/%E5%8D%9A%E5%AE%A2%E5%9B%AD/20150927/119235.html
	// 讀取圖像
	char *imageFile="C:\\Users\\usernb\\Documents\\ChangeDesktop\\02_RGB.JPG";
    FIBITMAP * bitmap = FreeImage_Load(FIF_JPEG, imageFile);
    if(bitmap) printf("Image Load successfully!\n");
    // 獲得圖像的寬和高（圖元）
    int width  = FreeImage_GetWidth(bitmap);
    int height = FreeImage_GetHeight(bitmap);
    // 計算每個圖元的位元組數
    //************************************************************************
    //* 已經測試有JPEG格式：每圖元位元組數3
    //* 已經測試有JPEG格式：每圖元位元組數4
    //************************************************************************
    int bytespp = FreeImage_GetLine(bitmap)/ width;
    printf("Width:%d\t Height:%d\t 每圖元位元組數:%d\n", width, height, bytespp);



    // 測試 int, float, byte4的各自的位元組數
    printf("int: %d \nfloat: %d\nbyte4: %d\n", sizeof(int), sizeof(float), sizeof(byte4));

    // 用於存放圖元值得矩陣
    byte4 **matrix;
    // 動態開闢2維陣列
    matrix = (byte4 **)calloc(height, sizeof(byte4*));
    for(int i = 0; i < height; i++)
    {
        matrix[i] = (byte4*)calloc(width, sizeof(byte4));
    }
    // 用於存放輸出圖元值矩陣
    byte4 ** matrix_dst;
    // 動態開闢2維陣列
    matrix_dst = (byte4 **)calloc(height, sizeof(byte4*));
    for(int i = 0; i < height; i++)
    {
        matrix_dst[i] = (byte4*)calloc(width, sizeof(byte4));
    }
    if(matrix && matrix_dst)
        printf("記憶體申請成功！\n");

    for(unsigned y = 0; y < height; y++)
    {
        BYTE *bitsLine = FreeImage_GetScanLine(bitmap, y);
        for(unsigned x = 0; x < width; x++)
        {
            // 設置圖元顏色
            matrix[y][x].r = bitsLine[FI_RGBA_RED]   ;
            matrix[y][x].g = bitsLine[FI_RGBA_GREEN] ;
            matrix[y][x].b = bitsLine[FI_RGBA_BLUE]  ;
            matrix[y][x].a = bitsLine[FI_RGBA_ALPHA] ;
            bitsLine += bytespp;
        }
    }

    // 執行旋轉， 濾波
    int start = clock();
    cpu_rotate(matrix, matrix_dst, width, height, 360);
    //cpu_filter(matrix, matrix_dst, width, height);
    printf("Time elapsed: %d ms\n", (clock() - start)); // 輸出FreeImage 圖像
    FIBITMAP * dst =  bitmap;

    for(unsigned y = 0; y < height; y++)
    {
        BYTE *bitsLine = FreeImage_GetScanLine(dst, y);
        for(unsigned x = 0; x < width; x++)
        {
            // 設置圖元顏色
            bitsLine[FI_RGBA_RED]   = matrix_dst[y][x].r ;
            bitsLine[FI_RGBA_GREEN] = matrix_dst[y][x].g ;
            bitsLine[FI_RGBA_BLUE]  = matrix_dst[y][x].b ;
            bitsLine[FI_RGBA_ALPHA] = matrix_dst[y][x].a ;
            bitsLine += bytespp;
        }
    }

    // 存儲圖像
    FreeImage_Save(FIF_JPEG, dst, "dst.jpg");
    FreeImage_Unload(bitmap);
    */

    //http://freeimage.sourceforge.net/fnet/html/FFB6F9A2.htm
    char *imageFile="C:\\Users\\usernb\\Documents\\ChangeDesktop\\02_RGB.JPG";
    FIBITMAP * bitmap = FreeImage_Load(FIF_JPEG, imageFile);
    FIBITMAP * dst = FreeImage_Rescale(bitmap,1024,768);
    FreeImage_Save(FIF_JPEG, dst, "dst.jpg");
    FreeImage_Unload(bitmap);
    FreeImage_Unload(dst);
    FreeImage_DeInitialise();
    return 0;
}
