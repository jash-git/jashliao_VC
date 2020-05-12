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
Mat src;//input image

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
   Mat input;
	input = imread("Lena_original.jpg");
	if (!input.data)
    {
		printf("could not load image...\n");
	}
    else
    {
        //放大
        pyrUp(input, src, Size(input.cols*2, input.rows*2));

        const char*  window_image = "input image";
        namedWindow(window_image, CV_WINDOW_AUTOSIZE);
        imshow(window_image, src);

        Rect rect00(0,0,src.cols/2,src.rows/2);   //创建一个Rect框，属于cv中的类，四个参数代表x,y,width,heigh
        Rect rect01(0,0+src.rows/2,src.cols/2,src.rows/2);
        Rect rect02(0+src.cols/2,0,src.cols/2,src.rows/2);
        Rect rect03(0+src.cols/2,0+src.rows/2,src.cols/2,src.rows/2);

        Mat mat00,mat01,mat02,mat03;

        Mat image_cut = Mat(src, rect00);      //从img中按照rect进行切割，此时修改image_cut时image中对应部分也会修改，因此需要copy
        mat00 = image_cut.clone();   //clone函数创建新的图片

        image_cut = Mat(src, rect01);
        mat01 = image_cut.clone();

        image_cut = Mat(src, rect02);
        mat02 = image_cut.clone();

        image_cut = Mat(src, rect03);
        mat03 = image_cut.clone();

        imshow("mat00", mat00);
        imshow("mat01", mat01);
        imshow("mat02", mat02);
        imshow("mat03", mat03);

        imwrite("00.png", mat00);
        imwrite("01.png", mat01);
        imwrite("02.png", mat02);
        imwrite("03.png", mat03);
    }
    waitKey(0);
    Pause();
    return 0;
}
