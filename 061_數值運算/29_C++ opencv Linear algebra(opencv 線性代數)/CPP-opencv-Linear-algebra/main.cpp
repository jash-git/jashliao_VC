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
void addMatrix()
{
    float a[2][2] = {{1, 2},
                     {3, 4}};
    float b[2][2] = {{5, 6},
                     {7, 8}};

    Mat A = Mat(2, 2, CV_32FC1, a);
    Mat B = Mat(2, 2, CV_32FC1, b);
    Mat C;
    C = A + B;
    cout << "A =" << endl << " " << A << endl << endl;
    cout << "B =" << endl << " " << B << endl << endl;
    cout << "A+B =" << endl << " " << C << endl << endl;
}
void subMatrix()
{
    float a[2][2] = {{1, 2},
                     {3, 4}};
    float b[2][2] = {{5, 6},
                     {7, 8}};

    Mat A = Mat(2, 2, CV_32FC1, a);
    Mat B = Mat(2, 2, CV_32FC1, b);
    Mat C;
    C = A - B;
    cout << "A =" << endl << " " << A << endl << endl;
    cout << "B =" << endl << " " << B << endl << endl;
    cout << "A-B =" << endl << " " << C << endl << endl;
}
void dotmatrix()
{
    //Opencv中.dot操作才算得上是真正的“点乘”，A.dot(B)操作相当于数学向量运算中的点乘，也叫向量的内积、数量积。
	Mat A=Mat::ones(2,3,CV_8UC1);
	Mat B=Mat::ones(2,3,CV_8UC1);

	A.at<uchar>(0,0)=1;
	A.at<uchar>(0,1)=2;
	A.at<uchar>(0,2)=3;
	A.at<uchar>(1,0)=4;
	A.at<uchar>(1,1)=5;
	A.at<uchar>(1,2)=6;

	B.at<uchar>(0,0)=1;
	B.at<uchar>(0,1)=2;
	B.at<uchar>(0,2)=3;
	B.at<uchar>(1,0)=4;
	B.at<uchar>(1,1)=5;
	B.at<uchar>(1,2)=6;

	double AB=A.dot(B);

	cout<<"A=\n"<<A<<endl<<endl;
	cout<<"B=\n"<<B<<endl<<endl;
	cout<<"A.B=\t"<<AB<<endl<<endl;
}
void matrixMultiplication(){
    float a[2][3] = {{ 3, 1, 2},
                     {-2, 0, 5}};
    float b[3][2] = {{-1, 3},
                     {0, 5},
                     {2,5}};

    Mat A = Mat(2, 3, CV_32FC1, a);
    Mat B = Mat(3, 2, CV_32FC1, b);
    cout << "A =" << endl << " " << A << endl << endl;
    cout << "B =" << endl << " " << B << endl << endl;

    Mat C;
    C = A * B;
    cout << "A * B=" << endl << " " << C << endl << endl;
    C = B * A;
    cout << "B * A=" << endl << " " << C << endl << endl;
}

void solveLinearEquation()
{
    // 3x + 2y = 7
    // -6x + 6y = 6
    float a[2][2] = {{ 3, 2},
                     {-6, 6}};

    float b[2][1] = { {7},
                      {6} };

    Mat A = Mat(2,2 ,CV_32FC1, a);
    Mat B = Mat(2,1, CV_32FC1, b);
    cout << "A =" << endl << " " << A << endl << endl;
    cout << "B =" << endl << " " << B << endl << endl;

    //X= B/A = A反矩陣*B
    Mat x = A.inv() * B;
    cout << "01.x=B/A" << endl << " " << x << endl;
    //-----------
    solve(A, B, x);//標準函數
    cout << "02.x=B/A" << endl << " " << x << endl;
}
void solveLinear_parabola()//拋物線(線性方程)求解
{
    cv::Point2f pt1, pt2, pt3; ///< 3 points for the parabola
    double a, b, c;            ///< Solved coefficients for the parabola equation

    //set here your 3 points for the parabola
    pt1 = cv::Point2f(1, 0);
    pt2 = cv::Point2f(0, 2);
    pt3 = cv::Point2f(3, 2);

    // OpenCV requires the linear system in the form Ax = B
    //
    // the linear system for 3points parabola is
    //
    // aX^2 + bX + c = Y ---> | a(pt1.x)^2 + b(pt1.x) + c(1) = pt1.y |
    //                        | a(pt2.x)^2 + b(pt2.x) + c(1) = pt2.y |
    //                        | a(pt3.x)^2 + b(pt3.x) + c(1) = pt3.y |
    // coefficients for the system are the 3 points
    // variables for the system are the parabola coefficient a,b,c
    //
    // Finally set the matrix for the linear system solver
    cv::Mat A = (cv::Mat_<float>(3, 3) <<
        std::pow(pt1.x, 2), pt1.x, 1,
        std::pow(pt2.x, 2), pt2.x, 1,
        std::pow(pt3.x, 2), pt3.x, 1);

    cv::Mat B = (cv::Mat_<float>(3, 1) <<
        pt1.y,
        pt2.y,
        pt3.y);

    // declare a vector for results
    cv::Mat abc;

    // solve the linear system
    cv::solve(A, B, abc);

    // printout the result
    cout << "Coefficients:\n " << abc << endl;
    a = abc.at<float>(0);
    b = abc.at<float>(1);
    c = abc.at<float>(2);
    cout << "Equation:\n y = " << a << "x^2 + " << b << "x + " << c << endl;
}

//---
//擬合曲線(最小平方法)
bool polynomial_curve_fit(std::vector<cv::Point>& key_point, int n, cv::Mat& A)
{
	//Number of key points
	int N = key_point.size();

	//构造矩阵X
	cv::Mat X = cv::Mat::zeros(n + 1, n + 1, CV_64FC1);
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			for (int k = 0; k < N; k++)
			{
				X.at<double>(i, j) = X.at<double>(i, j) +
					std::pow(key_point[k].x, i + j);
			}
		}
	}

	//构造矩阵Y
	cv::Mat Y = cv::Mat::zeros(n + 1, 1, CV_64FC1);
	for (int i = 0; i < n + 1; i++)
	{
		for (int k = 0; k < N; k++)
		{
			Y.at<double>(i, 0) = Y.at<double>(i, 0) +
				std::pow(key_point[k].x, i) * key_point[k].y;
		}
	}

	A = cv::Mat::zeros(n + 1, 1, CV_64FC1);
	//求解矩阵A
	cv::solve(X, Y, A, cv::DECOMP_LU);
	return true;
}
void Test_polynomial_curve_fit()
{
	//创建用于绘制的深蓝色背景图像
	cv::Mat image = cv::Mat::zeros(480, 640, CV_8UC3);
	image.setTo(cv::Scalar(100, 0, 0));

	//输入拟合点
	std::vector<cv::Point> points;
	points.push_back(cv::Point(100., 58.));
	points.push_back(cv::Point(150., 70.));
	points.push_back(cv::Point(200., 90.));
	points.push_back(cv::Point(252., 140.));
	points.push_back(cv::Point(300., 220.));
	points.push_back(cv::Point(350., 400.));

	//将拟合点绘制到空白图上
	for (int i = 0; i < points.size(); i++)
	{
		cv::circle(image, points[i], 5, cv::Scalar(0, 0, 255), 2, 8, 0);
	}

	//绘制折线
	cv::polylines(image, points, false, cv::Scalar(0, 255, 0), 1, 8, 0);

	cv::Mat A;

	polynomial_curve_fit(points, 3, A);
	std::cout << "A = " << A << std::endl;

	std::vector<cv::Point> points_fitted;

	for (int x = 0; x < 400; x++)
	{
		double y = A.at<double>(0, 0) + A.at<double>(1, 0) * x +
			A.at<double>(2, 0)*std::pow(x, 2) + A.at<double>(3, 0)*std::pow(x, 3);

		points_fitted.push_back(cv::Point(x, y));
	}
	cv::polylines(image, points_fitted, false, cv::Scalar(0, 255, 255), 1, 8, 0);

	cv::imshow("image", image);
}
//---擬合曲線(最小平方法)

int main()
{
    addMatrix();
    cout << endl << "===================" << endl << endl;
    subMatrix();
    cout << endl << "===================" << endl << endl;
    dotmatrix();
    cout << endl << "===================" << endl << endl;
    matrixMultiplication();
    cout << endl << "===================" << endl << endl;
    solveLinearEquation();
    cout << endl << "===================" << endl << endl;
    solveLinear_parabola();//拋物線(線性方程)求解
    cout << endl << "===================" << endl << endl;
    Test_polynomial_curve_fit();//擬合曲線(最小平方法)
	cv::waitKey(0);
    Pause();
    return 0;
}
