#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <iostream>
#include <cstdio>

using namespace cv;
using namespace std;
/*
機器學習經典算法剖析 基於OpenCV
第　2章 K近鄰算法
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main( int argc, char** argv )
{
	float trainingData[24][2]={	{4, 3},{1, 3},{3, 3},{3, 7},
                                {3, 4},{4, 1},{1, 4},{5, 6},
                                {3, 7},{6, 2},{4, 6},{4, 4},
                                {5, 8},{7, 8},{7, 7},{10, 5},
                                {7, 6},{4, 10},{9, 7},{5, 4},
                                {8, 5},{6, 6},{7, 4},{8, 8}	};
	CvMat trainingDataCvMat = cvMat( 24, 2, CV_32FC1, trainingData );

	float responses[24] = {'B','B','B','B','B','B','B','B','B','B',
		             'G','G','G','G','G','G','G','G','G','G','G','G','G','G'};
	CvMat responsesCvMat = cvMat( 24, 1, CV_32FC1, responses );
    //参数false表示分类问题
	CvKNearest knn( &trainingDataCvMat, &responsesCvMat, 0, false, 32 );

	int K = 7;    //KNN算法的参数K值
	float myData[2] = {4, 5};
	CvMat myDataCvMat = cvMat(1, 2, CV_32FC1, myData);
	//nearests表示K个最邻近样本的响应值
	CvMat* nearests = cvCreateMat( 1, K, CV_32FC1);
	float r = knn.find_nearest(&myDataCvMat, K, 0, 0, nearests, 0);

	cout<<"result:  "<<(char)r<<endl;
	cout<<K<<" nearest responses:";
	for (int i=0 ;i<K;i++)
		cout<<"  "<<(char)nearests->data.fl[i];

    cout << endl;
    Pause();
	return 0;

 }
