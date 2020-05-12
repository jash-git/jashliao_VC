#include <stdio.h>
#include <stdlib.h>
#include "image.h"
int main()
{
	ImageData *img,*outimg;
	int res;
	int x,y,mx,my;
/*
	if(ac<3) {
		printf("ƒp??[ƒ^‚ª‘«‚è‚Ü‚¹‚ñ");
		return;
	}

	res=readBMPfile(av[1],&img);
	if(res<0) {
		printf("‰æ?‚ª“Ç‚ß‚Ü‚¹‚ñ");
		return;
	}
*/
	res=readBMPfile("02.bmp",&img);
	outimg=createImage(img->width,img->height,24);

	effect(img,outimg);

	writeBMPfile("022.bmp",outimg);//writeBMPfile(av[2],outimg);
	disposeImage(img);
	disposeImage(outimg);
}
int effect(ImageData *img,ImageData *outimg)
{

    int fil[25]={
     0,0,-1, 0, 0,
     0,-1,-1, 1, 0,
      -1,-1, 0, 1, 1,
      0, -1, 1, 1 , 0,
      0,  0, 1, 0, 0};

    int val;
    int x1,y1,x2,y2;
	int x,y;
	int xx,yy;
	int ff;
	int rr,gg,bb,cc,dd;
	Pixel pix;

	x1=0;
	y1=0;
	x2=img->width-1;
	y2=img->height-1;
	for(y=y1;y<=y2;y++) {
		for(x=x1;x<=x2;x++) {
			val=0;
			ff=0;
			rr=gg=bb=0;
			for(yy=-1;yy<=3;yy++) {
				for(xx=-1;xx<=3;xx++) {
	    			val = getPixel(img,x+xx,y+yy,&pix);
					rr += pix.r * fil[ff];
					gg += pix.g * fil[ff];
					bb += pix.b * fil[ff];
					ff++;
				}
			}
			pix.r=rr;
			pix.g=gg;
			pix.b=bb;
			setPixel(outimg,x,y,&pix);
		}
	}
	return 1;
}

