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
        mat00 = imread("00.png");
        mat01 = imread("01.png");
        mat02 = imread("02.png");
        mat03 = imread("03.png");


        Mat output;
        output.create(src.cols,src.rows, CV_MAKETYPE(src.depth(), 3));
        output = Scalar::all(0);

        Mat temp;
        temp = output(rect00);
        mat00.copyTo(temp);
        temp = output(rect01);
        mat01.copyTo(temp);
        temp = output(rect02);
        mat02.copyTo(temp);
        temp = output(rect03);
        mat03.copyTo(temp);
        namedWindow("merage_output", CV_WINDOW_AUTOSIZE);
        imshow("merage_output", output);
        imwrite("merage_output.png", output);
    }
    waitKey(0);
    Pause();
    return 0;
}
