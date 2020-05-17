#include "CLib.h"
#include <cstdio>
#include <cmath>
CLib::CLib()
{
    //ctor
}

CLib::~CLib()
{
    //dtor
}
// 四捨五入 取到 小數點第 X 位
double CLib::rounding(double num, int index)
{
    //https://dotblogs.com.tw/forloop/2016/07/31/rounding
    bool isNegative = false; // whether is negative number or not

    if(num < 0) // if this number is negative, then convert to positive number
    {
        isNegative = true;
        num = -num;
    }

    if(index >= 0)
    {
        int multiplier;
        multiplier = pow(10, index);
        num = (int)(num * multiplier + 0.5) / (multiplier * 1.0);
    }

    if(isNegative) // if this number is negative, then convert to negative number
    {
        num = -num;
    }

    return num;
}
//元素互換
void CLib::Swap(int* array, int x, int y)
{
    int temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}
void CLib::Swap(double* array, int x, int y)
{
    double temp = array[x];
    array[x] = array[y];
    array[y] = temp;
}
//氣泡排序
void CLib::BubbleSort(int* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 1; j < size - i; j++)
        {
            if(array[j] < array[j - 1])
            {
                Swap(array, j, j - 1);
            }
        }
    }
}
void CLib::BubbleSort(double* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 1; j < size - i; j++)
        {
            if(array[j] < array[j - 1])
            {
                Swap(array, j, j - 1);
            }
        }
    }
}
void CLib::outputData(char *str)
{
    printf("%s\n",str);
}
void CLib::outputData(char *title,int data)
{
    printf("%s: %d\n",title,data);
}
void CLib::outputData(char *title,double data)
{
    printf("%s: %.2f\n",title,data);
}
void CLib::outputData(char *title,int* data,int number)
{

    printf("%s:",title);
    for(int i=0;i<number;i++)
    {
        printf("%d,",data[i]);
    }
    printf("\n");
}
void CLib::outputData(char *title,double* data,int number)
{

    printf("%s:",title);
    for(int i=0;i<number;i++)
    {
        printf("%.2f,",data[i]);
    }
    printf("\n");
}
void CLib::pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
