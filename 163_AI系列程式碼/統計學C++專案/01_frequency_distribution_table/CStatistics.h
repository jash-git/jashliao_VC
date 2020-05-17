#ifndef CSTATISTICS_H
#define CSTATISTICS_H


class CStatistics
{
    public:
        CStatistics();
        virtual ~CStatistics();
        static int calRange(int max,int min);//全距(range)=最大值-最小值
        static double calRange(double max,double min);//全距(range)=最大值-最小值
        static int calNumberOfClass(int nubmber,bool blnSturge);//組數(number of class)= n<=2^m ,n=資料數量;Sturge's法 1+3.32log(n)
        static int calInterval(int range,int number_of_class);//組距(class interval)=全距/組數
        static double calInterval(double range,int number_of_class);//組距(class interval)=全距/組數
        static void calClassLimit(double* data,int number,double class_interval,double *class_limit_L,double *class_limit_U,double *class_mean,int *class_count,int number_of_class,double Minimum_unit);//數據分組計算
        static double calSampleMean(double* array, int size);//樣本平均數(sample mean)=樣本值總和/總個數
        static double calWeightAverage(double* class_mean,int* class_count, int number_of_class,int number);//加權平均數(weight average)=組中點*次數的總和/總個數
        static double calSampleMedian(double* data,int number);//樣本中位數(sample median)
        static double calClassMedian(int number_of_class,int number,double *class_limit_U,int *class_count,double class_interval,double Minimum_unit);//分組中位數(class median)
        static double calSampleMAD(double* data,int number,double SampleMean);//樣本平均差(Sample Mean absolute deviation)
        static double calClassMAD(int number,double* class_mean,int* class_count,int number_of_class,double WeightAverage);//分組平均差(Class Mean absolute deviation)
        static double calSampleVariance(double* data,int number,double SampleMean);//樣本變異數(Sample Variance)
        static double calClassVariance(int number,double* class_mean,int* class_count,int number_of_class,double WeightAverage);//分組變異數(Class Variance)
    protected:
    private:
};

#endif // CSTATISTICS_H
