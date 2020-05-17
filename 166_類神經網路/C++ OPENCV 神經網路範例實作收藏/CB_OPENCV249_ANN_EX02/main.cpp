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
	int width = 512, height = 512;
	Mat img = Mat::zeros(height, width, CV_8UC3);

	//建立训练样本
	float train_data[6][2] = {{500,60},{245,40},{480,250},{160,380},{400,25},{55,400}};
	float labels[6] = { 0, 0, 0, 1, 0, 1 };
	Mat train_data_mat(6, 2, CV_32FC1, train_data);
	Mat labels_mat(6, 1, CV_32FC1, labels);
	Mat layers_size = (Mat_<int>(1, 3) << 2, 6, 1);

    //the BPNetwork
    CvANN_MLP bp;

    //BPNetwork's parameters
	CvANN_MLP_TrainParams params(
        cvTermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, 10000, 0.000001),    //终止条件
        CvANN_MLP_TrainParams::BACKPROP,    // BACKPROP算法
        0.1, 0.1);    //激活函数的两个参数

    bp.create(layers_size,CvANN_MLP::SIGMOID_SYM);//CvANN_MLP::SIGMOID_SYM
                                               //CvANN_MLP::GAUSSIAN
                                               //CvANN_MLP::IDENTITY
    bool blntrained = bp.train(train_data_mat, labels_mat, Mat(),Mat(), params);

    if(blntrained)
    {
        Vec3b green(0, 255, 0), blue(255, 0, 0);
        for (int i = 0; i<img.rows; ++i)
        {
            for (int j = 0; j<img.cols; ++j)
            {
                Mat sample_mat = (Mat_<float>(1, 2) << j, i);
                Mat response_mat;
                bp.predict(sample_mat, response_mat);
                float response = response_mat.ptr<float>(0)[0];
                if (response > 0.5)
                {
                    img.at<Vec3b>(i, j) = green;
                }
                else if (response < 0.5)
                {
                    img.at<Vec3b>(i, j) = blue;
                }
            }
        }
        //画出训练样本数据
        int thickness = -1;
        int lineType = 8;
        circle(img, Point(500, 60), 5, Scalar(255, 255, 255), thickness, lineType);
        circle(img, Point(245, 40), 5, Scalar(255, 255, 255), thickness, lineType);
        circle(img, Point(480, 250), 5, Scalar(255, 255, 255), thickness, lineType);
        circle(img, Point(160, 380), 5, Scalar(0, 0, 255), thickness, lineType);
        circle(img, Point(400, 25), 5, Scalar(255, 255, 255), thickness, lineType);
        circle(img, Point(55, 400), 5, Scalar(0, 0, 255), thickness, lineType);

        imwrite("Ans.jpg",img);
        imshow("Example", img);
        waitKey(0);
    }
    else
    {
        Pause();
    }

    return 0;
}
