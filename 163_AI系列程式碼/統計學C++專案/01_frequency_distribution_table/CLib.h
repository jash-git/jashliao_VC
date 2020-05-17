#ifndef CLIB_H
#define CLIB_H


class CLib
{
    public:
        CLib();
        virtual ~CLib();
        static double rounding(double num, int index);
        static void Swap(int* array, int x, int y);
        static void Swap(double* array, int x, int y);
        static void BubbleSort(int* array, int size);
        static void BubbleSort(double* array, int size);
        static void outputData(char *str);
        static void outputData(char *title,int data);
        static void outputData(char *title,double data);
        static void outputData(char *title,int* data,int number);
        static void outputData(char *title,double* data,int number);
        static void pause();
    protected:
    private:
};

#endif // CLIB_H
