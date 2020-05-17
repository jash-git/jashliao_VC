#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include "CLib.h"
#include "CStatistics.h"
using namespace std;
/*===================
次數分配表[ frequency distribution table ]
公式定義:
1.全距(range)=最大值-最小值
2.組數(number of class)= n<=2^m ,n=資料數量
3.組距(class interval)=全距/組數
4.組中點(class mean)=(min+max)/2
5.樣本平均數(sample mean)=樣本值總和/總個數
6.加權平均數(weight average)=組中點*次數的總和/總個數
7.樣本中位數(sample median)
    數據資料筆數為奇數=第(n+1)/2的值
    數據資料筆數為偶數=[第n/2+(n+1)/2的兩個值]/2
8.分組中位數(class median)
====================*/

int main()
{
    //p2-13,ex2-7 int data[]={65,82,47,33,14,22,16,81,57,62,21,83,66,43,47,27,36,51,27,19,66,42,38,29,51,27,40,41};
    //p2-14,ex2-8
    double data[]={5.1,5.6,5.3,5.7,5.8,6.4,4.3,5.9,5.4,4.7,5.6,6.8,6.9,4.8,5.6,
                  6.4,5.9,6.0,5.5,5.4,4.4,5.1,5.6,5.8,5.7,4.9,6.6,5.7,5.4,5.9,
                  5.6,6.7,5.4,4.8,6.4,5.8,5.3,5.7,6.3,4.5,5.6,6.2,4.2,5.2,5.8,
                  6.1,5.1,5.9,5.5,4.7};
    double Minimum_unit=0.1;
    //int number=sizeof(data)/sizeof(int);//數量
    int number=sizeof(data)/sizeof(double);//數量
    CLib::outputData("data",data,number);
    CLib::outputData("number",number);

    CLib::BubbleSort(data,number);
    CLib::outputData("data_Sort",data,number);

    //int range=CStatistics::calRange(data[number-1],data[0]);
    double range=CStatistics::calRange(data[number-1],data[0]);
    CLib::outputData("range",range);

    int number_of_class=0;
    number_of_class=CStatistics::calNumberOfClass(number,true);//Sturge's法
    CLib::outputData("number of class",number_of_class);

    //int class_interval= CStatistics::calInterval(range,number_of_class);
    double class_interval= CLib::rounding(CStatistics::calInterval(range,number_of_class),1);
    CLib::outputData("class interval",class_interval);
    CLib::outputData("------------------------------------------------");
    char strdata[400];

    double *class_mean = new double[number_of_class];
    int *class_count = new int[number_of_class];
    double *class_limit_L = new double[number_of_class];
    double *class_limit_U = new double[number_of_class];
    double sample_mean=0.0f;
    double weight_average=0.0f;

    CStatistics::calClassLimit(data,number,class_interval,class_limit_L,class_limit_U,class_mean,class_count,number_of_class,Minimum_unit);
    for(int i=0;i<number_of_class;i++)
    {
        sprintf(strdata,"class[%d]\t%.2f-%.2f\t%.2f\t%d",(i+1),class_limit_L[i],class_limit_U[i],class_mean[i],class_count[i]);
        CLib::outputData(strdata);
    }
    CLib::outputData("------------------------------------------------\n");

    sample_mean=CStatistics::calSampleMean(data, number);
    CLib::outputData("sample mean",sample_mean);

    weight_average=CStatistics::calWeightAverage(class_mean,class_count,number_of_class,number);
    CLib::outputData("weight average",weight_average);

    double sample_median=0;
    sample_median=CStatistics::calSampleMedian(data,number);
    CLib::outputData("sample median",sample_median);

    double class_median=0;
    class_median=CStatistics::calClassMedian(number_of_class,number,class_limit_U,class_count,class_interval,Minimum_unit);
    CLib::outputData("class median",class_median);

    double sample_mad=0;
    sample_mad=CStatistics::calSampleMAD(data,number,sample_mean);
    CLib::outputData("sample mad",sample_mad);

    double class_mad=0;
    class_mad=CStatistics::calClassMAD(number,class_mean,class_count,number_of_class,weight_average);
    CLib::outputData("class mad",class_mad);

    double sample_variance=0;
    sample_variance=CStatistics::calSampleVariance(data,number,sample_mean);
    CLib::outputData("sample variance",sample_variance);

    double class_variance=0;
    class_variance=CStatistics::calClassVariance(number,class_mean,class_count,number_of_class,weight_average);
    CLib::outputData("class variance",class_variance);

    double sample_standard_deviation=sqrt(sample_variance);//取樣標準差(sample standard deviation)
    CLib::outputData("sample standard deviation",sample_standard_deviation);

    double class_standard_deviation=sqrt(class_variance);//分組標準差(class standard deviation)
    CLib::outputData("class standard deviation",class_standard_deviation);

    double sample_CV=sample_standard_deviation/sample_mean;//取樣變異係數(sample coefficient of Variation)
    CLib::outputData("sample CV",sample_CV);

    double class_CV=class_standard_deviation/weight_average;//分組變異係數(class coefficient of Variation)
    CLib::outputData("class CV",class_CV);

    CLib::pause();
    delete class_mean;
    delete class_count;
    delete class_limit_L;
    delete class_limit_U;
    return 0;
}

