#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef unsigned char BYTE;


typedef	struct STRUCT_IMAGE{
	int width,height;
	int depth;
	void* pixels;
}ImageData;

#define PIXELMAX 255
typedef struct STRUCT_PIXEL{
	int r,g,b;
}Pixel;

ImageData* createImage(int width,int height,int depth);
void disposeImage(ImageData *img);
int readBMPfile(char *fname,ImageData **img);
int writeBMPfile(char *fname,ImageData *img);
int getPixel(ImageData *img,int x,int y,Pixel *pix);
int setPixel(ImageData *img,int x,int y,Pixel *pix);

