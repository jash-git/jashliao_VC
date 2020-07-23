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
第　8章 極端隨機樹
*/

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main( int argc, char** argv )
{
	double trainingData[28][2]={{210.4, 3}, {240.0, 3}, {300.0, 4}, {153.4, 3}, {138.0, 3},
								{194.0,4}, {189.0, 3}, {126.8, 3}, {132.0, 2}, {260.9, 4},
								{176.7,3}, {160.4, 3}, {389.0, 3}, {145.8, 3}, {160.0, 3},
								{141.6,2}, {198.5, 4}, {142.7, 3}, {149.4, 3}, {200.0, 3},
								{447.8,5}, {230.0, 4}, {123.6, 3}, {303.1, 4}, {188.8, 2},
								{196.2,4}, {110.0, 3}, {252.6, 3} };
	CvMat trainingDataCvMat = cvMat( 28, 2, CV_32FC1, trainingData );

	float responses[28] = {	399900, 369000, 539900, 314900, 212000, 239999, 329999,
                        259900, 299900, 499998, 252900, 242900, 573900, 464500,
                        329900, 232000, 299900, 198999, 242500, 347000, 699900,
                        449900, 199900, 599000, 255000, 259900, 249900, 469000};
	CvMat responsesCvMat = cvMat( 28, 1, CV_32FC1, responses );

	CvRTParams params= CvRTParams(10, 2, 0, false,16, 0, true, 0, 100, 0, CV_TERMCRIT_ITER );

    CvERTrees etrees;
	etrees.train(&trainingDataCvMat, CV_ROW_SAMPLE, &responsesCvMat,
                                  NULL, NULL, NULL, NULL,params);

	double sampleData[2]={201.5, 3};
	Mat sampleMat(2, 1, CV_32FC1, sampleData);
	float r = etrees.predict(sampleMat);
	cout<<endl<<"result:  "<<r<<endl;

    Pause();
    return 0;
}
