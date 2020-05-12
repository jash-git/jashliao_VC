#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <iostream>
#include <cstdio>
#include <cstdlib> //srand() ,rand() ,system()
#include <ctime>   //time()

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
int Rand_M2N(int intstart,int intrange)
{
    int i;
    srand(time(NULL));
    return intstart+(rand()%intrange);
}
int main()
{
    char ad[128]={0};
    Mat traindata ,trainlabel;
    int k=5,testnum=0,truenum=0;
    //读取训练数据 4000张
    for (int i = 0; i < 10; i++)
    {
        for (int j =0;j<400;j++)
        {
             sprintf(ad, "data\\%d\\%d.jpg",i,j);
             Mat srcimage = imread(ad);
             /*
                Mat::reshape( ) 
                只是在逻辑上改变矩阵的行列数或者通道数，没有任何的数据的复制，也不会增减任何数据，因此这是一个O(1)的操作，它要求矩阵是连续的。
                C++: Mat Mat::reshape(int cn, int rows=0 const)

                cn：目标通道数，如果是0则保持和原通道数一致；

                rows：目标行数，同上是0则保持不变；

                改变后的矩阵要满足 rows*cols*channels  跟原数组相等，所以如果原来矩阵是单通道3*3的，调用Reshape(0,2)是会报错的，因为3*3*1不能被2*1整除。
             */
             srcimage = srcimage.reshape(1,1);
             traindata.push_back(srcimage);//将元素添加到矩阵的底部。（在为mat增加一行的时候，用到push_back）
             trainlabel.push_back(i);//将元素添加到矩阵的底部。（在为mat增加一行的时候，用到push_back）
        }
    }


    traindata.convertTo(traindata,CV_32F);
    CvKNearest knn( traindata, trainlabel, cv::Mat(), false, k);


    /*
    RNG rng;
    int digital=rng.uniform(0, 9);
    int index=rng.uniform(400, 499);
    */
    int digital=Rand_M2N(0,(9-0));
    int index=Rand_M2N(400,(499-400));
    sprintf(ad, "data\\%d\\%d.jpg",digital,index);
    cout << "test image path : " << ad << endl;

    Mat testdata = imread(ad);
    Mat showdata=testdata.clone();

    testdata = testdata.reshape(1,1);
    testdata.convertTo(testdata,CV_32F);
    cv::Mat nearests( 1, k, CV_32F);
    int  response = knn.find_nearest(testdata,k,0,0,&nearests,0);

    if(digital==response)
    {
        cout << "test is " << digital << endl;
        cout << "ANS : "<< response << " is OK" << endl;
    }
    else
    {
        cout << "test is " << digital << endl;
        cout << "ANS : "<< response << " is faill" << endl;
    }

    namedWindow(ad, CV_WINDOW_NORMAL);
    imshow(ad,showdata);

    waitKey(0);
    Pause();
    return 0;
}
