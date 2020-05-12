#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <iostream>
#include <cstdio>

#include <sys/timeb.h>
#if defined(WIN32)
    #define  TIMEB    _timeb
    #define  ftime    _ftime
    typedef __int64 TIME_T;
#else
    #define TIMEB timeb
    typedef long long TIME_T;
#endif

using namespace cv;
using namespace std;
/*
資料來源:
https://cg2010studio.com/2011/06/06/opencv-%E8%BD%89%E6%8F%9B%E5%BD%B1%E5%83%8F%E7%82%BA%E7%81%B0%E9%9A%8E-transform-image-to-gray-level/
https://blog.csdn.net/kuweicai/article/details/73414138
https://cg2010studio.com/2013/03/22/opencv-iplimage-%E5%92%8C-mat-%E4%BA%92%E8%BD%89/

IplImage 和 Mat 互轉
    // IplImage to Mat
    IplImage *img;
    cv::Mat mat(img, 0);

    // Mat to IplImage
    cv::Mat mat;
    IplImage *img = IplImage(mat);
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    //Image Size: 255x255// Image Size: 1000x669
    uchar Blue[256][256];//[669][1000];
    uchar Green[256][256];//[669][1000];
    uchar Red[256][256];//[669][1000];
    uchar Gray[256][256];//[669][1000];
    IplImage *Image1;
    Image1 = cvLoadImage("Lena_original.jpg",1);

    struct TIMEB ts1,ts2;
    TIME_T t1,t2;

    ftime(&ts1);//开始计时

    /* Load Image RGB Values */
    for(int i=0;i<Image1->height;i++){
        for(int j=0;j<Image1->widthStep;j=j+3){
            Blue[i][(int)(j/3)]=Image1->imageData[i*Image1->widthStep+j];
            Green[i][(int)(j/3)]=Image1->imageData[i*Image1->widthStep+j+1];
            Red[i][(int)(j/3)]=Image1->imageData[i*Image1->widthStep+j+2];
        }
    }

    /* Implement Algorithms */
    for(int i=0;i<Image1->height;i++){
        for(int j=0;j<Image1->width;j++){
            Gray[i][j]=(uchar)(0.299*Red[i][j] + 0.587*Green[i][j] + 0.114*Blue[i][j]);
            Red[i][j]=Gray[i][j];
            Green[i][j]=Gray[i][j];
            Blue[i][j]=Gray[i][j];
        }
    }

    /* Save Image RGB Values */
    for(int i=0;i<Image1->height;i++){
        for(int j=0;j<Image1->widthStep;j=j+3){
            Image1->imageData[i*Image1->widthStep+j]=Blue[i][(int)(j/3)];
            Image1->imageData[i*Image1->widthStep+j+1]=Green[i][(int)(j/3)];
            Image1->imageData[i*Image1->widthStep+j+2]=Red[i][(int)(j/3)];
        }
    }

    cvSaveImage("Lena_original_gray00.jpg",Image1);

    ftime(&ts2);//停止计时
    t1=(TIME_T)ts1.time*1000+ts1.millitm;
    t2=(TIME_T)ts2.time*1000+ts2.millitm;
    int t01=t2-t1;//获取时间间隔，ms为单位的
    cout<<t01<<"ms"<< endl;

    cvNamedWindow("Gray Level",1);
    cvShowImage("Gray Level",Image1);

    cvWaitKey(0);

    cvReleaseImage(&Image1);
    cvDestroyWindow("Gray Level");


    //-----------------------------

    cv::Mat src, gray;
    struct TIMEB ts3,ts4;
    TIME_T t3,t4;
    ftime(&ts3);//开始计时

	gray=cv::imread("Lena_original.jpg", cv::IMREAD_GRAYSCALE);//由imread()得到的灰度图像
    cv::imwrite("Lena_original_gray01.jpg",gray);

	ftime(&ts4);//停止计时
    t3=(TIME_T)ts3.time*1000+ts3.millitm;
    t4=(TIME_T)ts4.time*1000+ts4.millitm;
    int t02=t4-t3;//获取时间间隔，ms为单位的
    cout<<t02<<"ms"<< endl;

	src = cv::imread("Lena_original.jpg");
	cv::imshow("scr",src);
	cv::imshow("gray", gray);

    cvWaitKey(0);

    Pause();
    return 0;

}
