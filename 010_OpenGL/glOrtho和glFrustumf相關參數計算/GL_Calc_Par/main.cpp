#include <iostream>
#include <cmath>
using namespace std;
////////////////////////////////////
double ToRadians (double d);//度轉徑度
double ToDegrees (double r);//徑度轉度
float g_fltWidth=640;//螢幕寬度
float g_fltHight=480;//螢幕高度
float g_fltAspectRatio;//寬高比
float g_fltFieldOfView = 45.0; //視野角度
float g_fltNear = 0.1; //近端
float g_fltFar = 1000; //遠端
float g_fltSize;//glFrustumf函數參數
float g_fltOrthoRange = 420.0f;//空間大小
///////////////////////////////////
double ToRadians (double d)//度轉徑度
{
    return d * M_PI / 180;
}
double ToDegrees (double r)//徑度轉度
{
    return r * 180/ M_PI;
}

int main()
{
    //////////////////////////////
    if(g_fltWidth>g_fltHight)
    {
        g_fltAspectRatio=g_fltWidth/g_fltHight;
    }
    else
    {
        g_fltAspectRatio=g_fltHight/g_fltWidth;
    }
    ///////////////////////////////
    g_fltSize=g_fltNear * tanf(ToRadians(g_fltFieldOfView ) / 2.0);
    cout <<"Width="<<g_fltWidth<< endl;
    cout<<"Hight="<<g_fltHight<< endl;
    cout<<"Aspect Ratio="<<g_fltAspectRatio<< endl;
    cout<<"Field Of View="<<g_fltFieldOfView<<" Degrees"<<endl;
    cout<<"glFrustumf Near="<<g_fltNear<< endl;
    cout<<"glFrustumf Far="<<g_fltFar<< endl;
    cout<<"glFrustumf Left="<<-1*g_fltSize<< endl;
    cout<<"glFrustumf Right="<<g_fltSize<< endl;
    cout<<"glFrustumf Bottom="<<-1*g_fltSize/g_fltAspectRatio<< endl;
    cout<<"glFrustumf Top="<<g_fltSize/g_fltAspectRatio<< endl;
    //glFrustumf(-g_fltSize, g_fltSize, -g_fltSize/g_fltAspectRatio, g_fltSize/g_fltAspectRatio, g_fltNear, g_fltFar);
    cout<<"glOrtho Range"<<g_fltOrthoRange<< endl;
    cout<<"glOrtho Near="<<-1*g_fltOrthoRange*2<< endl;
    cout<<"glOrtho Far="<<g_fltOrthoRange*2<< endl;
    cout<<"glOrtho Left="<<-1*g_fltOrthoRange<< endl;
    cout<<"glOrtho Right="<<g_fltOrthoRange<< endl;
    cout<<"glOrtho Bottom="<<-1*g_fltOrthoRange*g_fltAspectRatio<< endl;
    cout<<"glOrtho Top="<<g_fltOrthoRange*g_fltAspectRatio<< endl;
    //void glOrtho(left,right,bottom,top,nearVal,farVal);
    /*
    if (w <= h)
		glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange*2, nRange*2);
    else
		glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange*2, nRange*2);
    */
    cout << "Hello world!" << endl;
    return 0;
}
