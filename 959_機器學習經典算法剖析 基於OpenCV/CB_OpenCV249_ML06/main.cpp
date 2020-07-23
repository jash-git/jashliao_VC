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
第　6章 梯度提升樹
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
	Mat trainingDataMat(28, 2, CV_32FC1, trainingData);

	float responses[28] = {	399900, 369000, 539900, 314900, 212000, 239999, 329999,
                        259900, 299900, 499998, 252900, 242900, 573900, 464500,
                        329900, 232000, 299900, 198999, 242500, 347000, 699900,
                        449900, 199900, 599000, 255000, 259900, 249900, 469000};
	Mat responsesMat(28, 1, CV_32FC1, responses);
	//设置参数
    CvGBTreesParams params;
    params.loss_function_type = CvGBTrees::ABSOLUTE_LOSS;
	params.weak_count = 10;
	params.shrinkage = 0.01f;
	params.subsample_portion = 0.8f;
	params.max_depth = 3;
	params.use_surrogates = false;

    CvGBTrees gbt;    //训练样本
    gbt.train(trainingDataMat, CV_ROW_SAMPLE, responsesMat, Mat(), Mat(), Mat(), Mat(),params);

	double sampleData[2]={185.4, 4};    //待预测样本
	Mat sampleMat(2, 1, CV_32FC1, sampleData);

	float r = gbt.predict(sampleMat);    //预测

	cout<<endl<<"result:  "<<r<<endl;
    Pause();
    return 0;
}
