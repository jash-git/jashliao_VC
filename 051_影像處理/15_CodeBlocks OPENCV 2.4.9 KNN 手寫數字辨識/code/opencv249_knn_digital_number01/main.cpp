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

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    char ad[128]={0};
    int  filename = 0,filenum=0;
    Mat img = imread("input.png");
    Mat gray;
    cvtColor(img, gray, CV_BGR2GRAY);
    int b = 20;
    int m = gray.rows / b;   //原图为1000*2000
    int n = gray.cols / b;   //裁剪为5000个20*20的小图块

    for (int i = 0; i < m; i++)
    {
        int offsetRow = i*b;  //行上的偏移量
        if(i%5==0&&i!=0)
        {
            filename++;
            filenum=0;
        }
        for (int j = 0; j < n; j++)
        {
           int offsetCol = j*b; //列上的偏移量
           sprintf(ad, "data\\%d\\%d.jpg",filename,filenum++);
           //截取20*20的小块
           Mat tmp;
           /*
           访问cv::Mat m中点（i0, j0,）和点（i1-1, j1-1）围成的矩形范围
           cv::Mat m0 = m(cv::Range(i0, i1), cv::Range(j0, j1))
           */
           gray(Range(offsetRow, offsetRow + b), Range(offsetCol, offsetCol + b)).copyTo(tmp);
           /*
           ps:
            访问cv::Mat m的第i行
            cv::Mat m0 = m.row(i)
            访问cv::Mat m的第j列
            cv::Mat m0 = m.col(j)
            访问cv::Mat m的第i0行到第i1-1行
            cv::Mat m0 = m.rowRange(i0, i1)
            cv::Mat m0 = m.rowRange(cv::Range(i0, i1))
            访问cv::Mat m的第j0行到第j1-1列
            cv::Mat m0 = m.colRange(j0, j1)
            cv::Mat m0 = m.colRange(cv::Range(j0, j1))
            访问cv::Mat m偏移量为d的对角线
            cv::Mat m0 = m.diag(d)
            访问cv::Mat m的矩形（i0, i1, w, h）范围
            cv::Mat m0 = m(cv::Rect(i0, i1, w, h))
           */
           imwrite(ad,tmp);
        }
    }
    return 0;
}
