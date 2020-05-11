#include <stdio.h>
#include <stdlib.h>
long g_lngDispalyWide,g_lngDispalyHigh;
long g_lngDispalyGCD;
long g_lngDispalyX,g_lngDispalyY;

long g_lngImageWide,g_lngImageHigh;
long g_lngImageGCD;
long g_lngImageX,g_lngImageY;

long g_lngBlankWide,g_lngBlankHigh;
float g_fltProportion;

void Calculate()
{
    if((g_lngDispalyX==g_lngImageX)&&(g_lngDispalyY==g_lngImageY))
    {
        g_lngBlankWide=0;g_lngBlankHigh=0;
        g_fltProportion=(float)g_lngDispalyWide/(float)g_lngImageWide;
    }
    else
    {
        g_fltProportion=(float)g_lngDispalyWide/(float)g_lngImageWide;
        if((g_fltProportion*g_lngImageHigh)<=((float)g_lngDispalyHigh))
        {
            g_lngBlankWide=g_lngDispalyWide-(g_lngImageWide*g_fltProportion);
            g_lngBlankHigh=g_lngDispalyHigh-(g_lngImageHigh*g_fltProportion);
        }
        else
        {
            g_fltProportion=(float)g_lngDispalyHigh/(float)g_lngImageHigh;
            g_lngBlankWide=g_lngDispalyWide-(g_lngImageWide*g_fltProportion);
            g_lngBlankHigh=g_lngDispalyHigh-(g_lngImageHigh*g_fltProportion);
        }
    }
}

long GCDfun(long a,long b)//求最大公因數_2_以輾轉相除法
{
	int c=0;
	c=a%b;
	if(c==0)
		return b;
	return GCDfun(b,c);
}
int main()
{
    g_lngDispalyWide=1280;
    g_lngDispalyHigh=720;
    g_lngDispalyGCD=GCDfun(g_lngDispalyWide,g_lngDispalyHigh);
    g_lngDispalyX=g_lngDispalyWide/g_lngDispalyGCD;
    g_lngDispalyY=g_lngDispalyHigh/g_lngDispalyGCD;
    printf("DispalyWide=%ld,DispalyHigh=%ld\n",g_lngDispalyWide,g_lngDispalyHigh);
    printf("DispalyX=%ld : DispalyY=%ld\t(DispalyGCD=%ld)\n",g_lngDispalyX,g_lngDispalyY,g_lngDispalyGCD);

    g_lngImageWide=1280;
    g_lngImageHigh=800;
    g_lngImageGCD=GCDfun(g_lngImageWide,g_lngImageHigh);
    g_lngImageX=g_lngImageWide/g_lngImageGCD;
    g_lngImageY=g_lngImageHigh/g_lngImageGCD;
    printf("ImageWide=%ld,ImageHigh=%ld\n",g_lngImageWide,g_lngImageHigh);
    printf("ImageX=%ld : ImageY=%ld\t(ImageGCD=%ld)\n",g_lngImageX,g_lngImageY,g_lngImageGCD);

    Calculate();
    printf("BlankWide=%ld\tBlankHigh=%ld\tProportion=%f\n",g_lngBlankWide,g_lngBlankHigh,g_fltProportion);
    return 0;
}
