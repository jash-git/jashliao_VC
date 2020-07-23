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
第　3章 支持向量機
*/
void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main( int argc, char** argv )
{
    //60个训练样本
    double trainingData[60][4]={{5.1,3.5,1.4,0.2}, {4.9,3.0,1.4,0.2}, {4.7,3.2,1.3,0.2},
                            {4.6,3.1,1.5,0.2}, {5.0,3.6,1.4,0.2}, {5.4,3.9,1.7,0.4},
                            {4.6,3.4,1.4,0.3}, {5.0,3.4,1.5,0.2}, {4.4,2.9,1.4,0.2},
                            {4.9,3.1,1.5,0.1}, {5.4,3.7,1.5,0.2}, {4.8,3.4,1.6,0.2},
                            {4.8,3.0,1.4,0.1}, {4.3,3.0,1.1,0.1}, {5.8,4.0,1.2,0.2},
                            {5.7,4.4,1.5,0.4}, {5.4,3.9,1.3,0.4}, {5.1,3.5,1.4,0.3},
                            {5.7,3.8,1.7,0.3}, {5.1,3.8,1.5,0.3},
                            {7.0,3.2,4.7,1.4}, {6.4,3.2,4.5,1.5}, {6.9,3.1,4.9,1.5},
                            {5.5,2.3,4.0,1.3}, {6.5,2.8,4.6,1.5}, {5.7,2.8,4.5,1.3},
                            {6.3,3.3,4.7,1.6}, {4.9,2.4,3.3,1.0}, {6.6,2.9,4.6,1.3},
                            {5.2,2.7,3.9,1.4}, {5.0,2.0,3.5,1.0}, {5.9,3.0,4.2,1.5},
                            {6.0,2.2,4.0,1.0}, {6.1,2.9,4.7,1.4}, {5.6,2.9,3.6,1.3},
                            {6.7,3.1,4.4,1.4}, {5.6,3.0,4.5,1.5}, {5.8,2.7,4.1,1.0},
                            {6.2,2.2,4.5,1.5}, {5.6,2.5,3.9,1.1},
                            {6.3,3.3,6.0,2.5}, {5.8,2.7,5.1,1.9}, {7.1,3.0,5.9,2.1},
                            {6.3,2.9,5.6,1.8}, {6.5,3.0,5.8,2.2}, {7.6,3.0,6.6,2.1},
                            {4.9,2.5,4.5,1.7}, {7.3,2.9,6.3,1.8}, {6.7,2.5,5.8,1.8},
                            {7.2,3.6,6.1,2.5}, {6.5,3.2,5.1,2.0}, {6.4,2.7,5.3,1.9},
                            {6.8,3.0,5.5,2.1}, {5.7,2.5,5.0,2.0}, {5.8,2.8,5.1,2.4},
                            {6.4,3.2,5.3,2.3}, {6.5,3.0,5.5,1.8}, {7.7,3.8,6.7,2.2},
                            {7.7,2.6,6.9,2.3}, {6.0,2.2,5.0,1.5}	};
    Mat trainingDataMat(60, 4, CV_32FC1, trainingData);
    //训练样本所对应的类别，S表示setosa，V表示versicolor，R表示virginica
    float responses[60] = {'S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S','S',
                      'V','V','V','V','V','V','V','V','V','V','V','V','V','V','V','V','V','V','V','V',
                      'R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R','R'};
    Mat responsesMat(60, 1, CV_32FC1, responses);

    //设置SVM参数
    CvSVMParams params;
    params.svm_type = CvSVM::C_SVC;    //SVM类型为C-SVC
    params.C = 10.0;    //C参数设置为10
    params.kernel_type = CvSVM::RBF;    //核函数为高斯核函数
    params.gamma = 8.0;    //高斯核函数中的γ参数设置为8
    //迭代的终止条件
    params.term_crit = cvTermCriteria(CV_TERMCRIT_EPS, 1000, FLT_EPSILON);

    //建立SVM模型
    CvSVM svm;
    svm.train(trainingDataMat, responsesMat, Mat(), Mat(), params);
    //预测样本数据
    double sampleData[4]={ 6.7, 3.1, 4.7, 1.5};
    Mat sampleMat(4, 1, CV_32FC1, sampleData);
    float r = svm.predict(sampleMat);    //预测结果
    cout<<endl<<"result:  "<<(char)r<<endl;    //输出结果
    Pause();
    return 0;
}
