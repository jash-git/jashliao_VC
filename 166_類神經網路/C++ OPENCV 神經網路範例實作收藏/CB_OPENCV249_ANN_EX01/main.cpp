#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/ml/ml.hpp>

#include <iostream>
#include <cstdio>

using namespace cv;
using namespace std;

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    //the BPNetwork
    CvANN_MLP bp;

    //BPNetwork's parameters
	CvANN_MLP_TrainParams params(
        cvTermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, 1000, 0.000001),    //终止条件
        CvANN_MLP_TrainParams::BACKPROP,    // BACKPROP算法
        0.1, 0.1);    //激活函数的两个参数

    // Set up training data
    float trainingData[8][3] = {{0,0,0},{0,0,1},{0,1,0},{0,1,1},{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
    Mat trainingDataMat(8, 3, CV_32FC1, trainingData);
    float labels[8][2] = {{1,-1},{-1,1},{-1,1},{1,-1},{-1,1},{1,-1},{1,-1},{-1,1}};
    Mat labelsMat(8, 2, CV_32FC1, labels);


    Mat layerSizes=(Mat_<int>(1,3) << 3,10,2);//(1 dimension,3 parameter)<< input=3,1-hidden=10,output=2

    bp.create(layerSizes,CvANN_MLP::SIGMOID_SYM);//CvANN_MLP::SIGMOID_SYM
                                               //CvANN_MLP::GAUSSIAN
                                               //CvANN_MLP::IDENTITY
    bool blntrained = bp.train(trainingDataMat, labelsMat, Mat(),Mat(), params);

    if(blntrained)
    {
        bp.save("3xor_param");
        Mat p_output_01;
        bp.predict(trainingDataMat, p_output_01);
        cout << "output:" << endl << p_output_01 << endl << endl;

        CvANN_MLP bp_3xor;
        bp_3xor.load("3xor_param");

        Mat p_output_02;
        bp_3xor.predict(trainingDataMat, p_output_02);
        cout << "Predicted output:" << endl << p_output_02 << endl << endl;

        float IN01[2][3]={{0,0,0},{1,1,1}};
        Mat IN01Mat(2, 3, CV_32FC1, IN01);
        Mat p_output_03;
        bp_3xor.predict(IN01Mat, p_output_03);
        cout << "test output:" << endl << p_output_03 << endl << endl;

    }
    else
    {
        cout << "NN train ERROR" << endl;
    }

    Pause();
    return 0;
}
