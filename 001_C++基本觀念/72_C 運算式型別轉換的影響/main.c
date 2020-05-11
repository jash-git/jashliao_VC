#include <stdio.h>
#include <stdlib.h>
//=============================
//Type Conversion
//r=3
//4/3*3.14*r*r*r=?
//=============================
int main()
{
    int intr=3;
    float fltAns=0.0;

    fltAns=4/3*3.14*intr*intr*intr;//因為沒有注意型別轉換，導致運算結果錯誤
    printf("r=3\n4/3*3.14*r*r*r=%f\n",fltAns);
    printf("///////////////////////////////\n");

    fltAns=4.0/3*3.14*intr*intr*intr;//有進行型別轉換1
    printf("r=3\n4.0/3*3.14*r*r*r=%f\n",fltAns);
    printf("///////////////////////////////\n");

    fltAns=4/3.0*3.14*intr*intr*intr;//有進行型別轉換2
    printf("r=3\n4/3.0*3.14*r*r*r=%f\n",fltAns);
    printf("///////////////////////////////\n");

    fltAns=(float)4/3*3.14*intr*intr*intr;//有進行型別轉換3
    printf("r=3\n(float)4/3*3.14*r*r*r=%f\n",fltAns);
    printf("///////////////////////////////\n");

    fltAns=4/(float)3*3.14*intr*intr*intr;//有進行型別轉換4
    printf("r=3\n4/(float)3*3.14*r*r*r=%f\n",fltAns);
    printf("///////////////////////////////\n");
    return 0;
}
