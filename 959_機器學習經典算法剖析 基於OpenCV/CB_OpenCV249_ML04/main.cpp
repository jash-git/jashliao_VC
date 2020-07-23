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
第　4章 決策樹
*/

//5个特征属性的描述
static const char* var_desc[] =
{
    "Age (young=Y, middle=M, old=O)",
    "Salary? (low=L, medium=M, high=H)",
    "Own_House? (false=N, true=Y)",
    "Own_Car? (false=N, true=Y)",
    "Credit_Rating (fair=F, good=G, excellent=E)",
    0
};

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main( int argc, char** argv )
{
    //19个训练样本
    float trainingData[19][5]={ {'Y','L','N','N','F'},
                            {'Y','L','Y','N','G'},
                            {'Y','M','Y','N','G'},
                            {'Y','M','Y','Y','G'},
                            {'Y','H','Y','Y','G'},
                            {'Y','M','N','Y','G'},
                            {'M','L','Y','Y','E'},
                            {'M','H','Y','Y','G'},
                            {'M','L','N','Y','G'},
                            {'M','M','Y','Y','F'},
                            {'M','H','Y','Y','E'},
                            {'M','M','N','N','G'},
                            {'O','L','N','N','G'},
                            {'O','L','Y','Y','E'},
                            {'O','L','Y','N','E'},
                            {'O','M','N','Y','G'},
                            {'O','L','N','N','E'},
                            {'O','H','N','Y','F'},
                            {'O','H','Y','Y','E'}   };
    Mat trainingDataMat(19, 5, CV_32FC1, trainingData);    //样本的矩阵形式
    //样本的分类结果，即响应值
    float responses[19] = {'N','N','Y','Y','Y','N','Y','Y','N','N','Y','N','N','Y','Y','N','N','N','Y'};
    Mat responsesMat(19, 1, CV_32FC1, responses);    //矩阵形式

    float priors[5] = {1, 1};    //先验概率，这里的每个类别都相同
    //定义决策树的参数
    CvDTreeParams params(  15,    // 决策树的最大深度
                          1,    //决策树叶节点的最小样本数
                          0,    //回归精度，这里不需要
                          false,    //是否使用替代分叉属性，由于没有缺失的特征属性，所以这里不需要替代分叉属性
                          25,    //最大的类数量
                          0,    // 交叉验证的子集数，由于样本太少，这里不需要交叉验证
                          false,    //使用1SE规则，这里不需要
                          false,    //是否真正的去掉被剪切的分支，这里不需要
                          priors    //先验概率
                          );
    //类形式的掩码，这里是分类树，而且5个特征属性都是类的形式，因此该变量都为1
    Mat varTypeMat(6, 1, CV_8U, Scalar::all(1));

    CvDTree* dtree = new CvDTree();    //实例化CvDTree类
    //训练样本，构建决策树
    dtree->train (   trainingDataMat,    //训练样本
                    CV_ROW_SAMPLE,    //样本矩阵的行表示样本，列表示特征属性
                    responsesMat,    //样本的响应值矩阵
                    Mat(),    //应用所有的特征属性
                    Mat(),    //应用所有的训练样本
                    varTypeMat,    //类形式的掩码
                    Mat(),    //没有缺失任何特征属性
                    params    //决策树参数
                    );
    //调用get_var_importance函数
    const CvMat* var_importance = dtree->get_var_importance();
    //输出特征属性重要性程度
    for( int i = 0; i < var_importance->cols*var_importance->rows; i++ )
    {
        double val = var_importance->data.db[i];
        char buf[100];
        int len = (int)(strchr( var_desc[i], '(' ) - var_desc[i] - 1);
        strncpy( buf, var_desc[i], len );
        buf[len] = '\0';
        printf( "%s", buf );
        printf( ": %g%%\n", val*100. );
    }

    float myData[5] = {'M','H','Y','N','F'};    //预测样本
    Mat myDataMat(5, 1, CV_32FC1, myData);    //矩阵形式
    double r = dtree->predict( myDataMat, Mat(), false)->value;    //得到预测结果

    cout<<endl<<"result:  "<<(char)r<<endl;    //输出预测结果
    Pause();
    return 0;
}
