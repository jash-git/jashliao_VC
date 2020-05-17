#include "CStatistics.h"
#include "CLib.h"
#include <cmath>

CStatistics::CStatistics()
{
    //ctor
}

CStatistics::~CStatistics()
{
    //dtor
}
int CStatistics::calRange(int max,int min)//全距(range)=最大值-最小值
{
    int intAns=0;

    intAns=max-min;

    return intAns;
}
double CStatistics::calRange(double max,double min)//全距(range)=最大值-最小值
{
    double intAns=0;

    intAns=max-min;

    return intAns;
}
int CStatistics::calNumberOfClass(int nubmber,bool blnSturge=false)//組數(number of class)= n<=2^m ,n=資料數量
{
    int intAns=0;
    if(!blnSturge)
    {
        do{
            intAns++;
        }while(pow(2,intAns)<nubmber);
    }
    else
    {
        intAns=ceil(log10(nubmber)*3.32+1);
    }

    return intAns;
}
int CStatistics::calInterval(int range,int number_of_class)//組距(class interval)=全距/組數
{
    int intAns=0;

    intAns=ceil((double)range/number_of_class);//ceil((double)range/number_of_class)

    return intAns;
}
double CStatistics::calInterval(double range,int number_of_class)//組距(class interval)=全距/組數
{
    double intAns=0;

    intAns=(range/number_of_class);//ceil((double)range/number_of_class)

    return intAns;
}
double CStatistics::calSampleMean(double* array, int size)//未分組平均
{
    double dblAns=0;

    for(int i=0;i<size;i++)
    {
        dblAns+=array[i];
    }
    dblAns=dblAns/size;

    return dblAns;
}
double CStatistics::calWeightAverage(double* class_mean,int* class_count, int number_of_class,int number)//已分組平均
{
    double dblAns=0;

    for(int i=0;i<number_of_class;i++)
    {
        dblAns+=(class_mean[i]*class_count[i]);
    }
    dblAns=dblAns/number;

    return dblAns;
}
void CStatistics::calClassLimit(double* data,int number,double class_interval,double *class_limit_L,double *class_limit_U,double *class_mean,int *class_count,int number_of_class,double Minimum_unit)//數據分組計算
{
    double minvalue=0,maxvalue=0;
    int k=0,count_value=0;;
    for(int i=0;i<number_of_class;i++)
    {
        if(i==0)
        {
            minvalue=CLib::rounding(data[i],1);
        }
        else
        {
            //minvalue=maxvalue+1;
            minvalue=CLib::rounding(maxvalue+Minimum_unit,1);//0.1=最小單位
        }
        //maxvalue=minvalue+class_interval-1;
        maxvalue=CLib::rounding(minvalue+class_interval-Minimum_unit,1);//0.1=最小單位

        for(int j=0+k;j<number;j++)
        {
           if((data[j]>=minvalue)&&(data[j]<=maxvalue))
           {
               count_value++;
           }
           else
           {
               k=j;
               break;
           }
        }
        class_limit_L[i]=minvalue;
        class_limit_U[i]=maxvalue;
        class_mean[i]=(minvalue+maxvalue)/2.0;
        class_count[i]=count_value;
        count_value=0;
    }
}
double CStatistics::calSampleMedian(double* data,int number)////未分組中數值
{
    double dblAns=0;
    if((number%2)==0)
    {
        dblAns=data[(number+1)/2];
    }
    else
    {
        dblAns=(data[(number)/2]+data[(number+1)/2])/2;
    }
    return dblAns;
}
double CStatistics::calClassMedian(int number_of_class,int number,double *class_limit_U,int *class_count,double class_interval,double Minimum_unit)//已分組中數值
{
    double dblAns=0;
    int index=0;
    int sum=0;

    for(int i=0;i<number_of_class;i++)
    {
        sum+=class_count[i];
        if((number/2)<=sum)
        {
            index=i;
            break;
        }
    }
    dblAns=class_limit_U[index]-(class_interval/class_count[index])*(sum-(number/2))+Minimum_unit;

    return dblAns;
}
double CStatistics::calSampleMAD(double* data,int number,double SampleMean)//樣本平均差(Sample Mean absolute deviation)
{
    double dblAns=0;
    for(int i=0;i<number;i++)
    {
        dblAns+=fabs(data[i]-SampleMean);
    }
    dblAns/=number;
    return dblAns;
}
double CStatistics::calClassMAD(int number,double* class_mean,int* class_count,int number_of_class,double WeightAverage)//分組平均差(Class Mean absolute deviation)
{
    double dblAns=0;
    for(int i=0;i<number_of_class;i++)
    {
        dblAns+=fabs((class_mean[i]-WeightAverage)*class_count[i]);
    }
    dblAns/=number;
    return dblAns;
}
double CStatistics::calSampleVariance(double* data,int number,double SampleMean)//樣本變異數(Sample Variance)
{
    double dblAns=0;
    for(int i=0;i<number;i++)
    {
        dblAns+=((data[i]-SampleMean) * (data[i]-SampleMean));
    }
    dblAns/=(number-1);
    return dblAns;
}
double CStatistics::calClassVariance(int number,double* class_mean,int* class_count,int number_of_class,double WeightAverage)//分組變異數(Class Variance)
{
    double dblAns=0;
    for(int i=0;i<number_of_class;i++)
    {
        dblAns+=((class_mean[i]-WeightAverage)*(class_mean[i]-WeightAverage)*class_count[i]);
    }
    dblAns/=(number-1);
    return dblAns;
}
