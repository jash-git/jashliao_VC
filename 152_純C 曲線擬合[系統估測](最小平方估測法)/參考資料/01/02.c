#include<stdio.h>
#include<conio.h>
#include<math.h>
/*
在C指數曲線擬合源代碼：
*/
int main()
{

    int n,i;
    float Y[20],sumx=0,sumy=0,sumxy=0,sumx2=0,x[20],y[20];
    float a,b,A;
    printf("\n  C program for Exponential Curve fitting\n");
    printf("\n Enter the value of number of terms n:");
    scanf("%d",&n);
    printf("\n Enter the values of x:");
    for(i=0;i<=n-1;i++)
    {
        scanf("%f",&x[i]);

    }
    printf("\n Enter the values of y:");
    for(i=0;i<=n-1;i++)
    {
        scanf("%f",&y[i]);
    }
    for(i=0;i<=n-1;i++)
    {
        Y[i]=log(y[i]);
    }
    for(i=0;i<=n-1;i++)
    {
        sumx=sumx +x[i];
        sumx2=sumx2 +x[i]*x[i];
        sumy=sumy +Y[i];
        sumxy=sumxy +x[i]*Y[i];

    }
    A=((sumx2*sumy -sumx*sumxy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    b=((n*sumxy-sumx*sumy)*1.0/(n*sumx2-sumx*sumx)*1.0);
    a=exp(A);
    printf("\n\n The curve is Y= %4.3fe^%4.3fX",a,b);
    return(0);
}