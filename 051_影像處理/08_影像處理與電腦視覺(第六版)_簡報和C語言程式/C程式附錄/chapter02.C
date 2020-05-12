#define M_PI_2     1.57079632679489661923
#define PI 3.14159   
#define SIZE 1024   
int blksz=8;
void dctnbyn(uchar **Dest, uchar **Color, int yoff, int xoff, int blksz);
void idctnbyn( uchar **Dest, uchar **Color, int yoff, int xoff, int blksz, bool truncate);
//DCT 锣传
void dctnbyn(uchar **Dest, uchar **Color, int yoff, int xoff, int blksz)
{
// 繵瞯办 <=> 办
        //  p,q   <=> m,n
double dc_alpha = 1.0/sqrt(double(blksz));
double ac_alpha = sqrt(2.0/blksz);
double coef;
int p, q, m, n;
for (p=0 ; p<blksz ; ++p)
for (q=0 ; q<blksz ; ++q)
        {
coef = 0.0;
for (m=0 ; m<blksz ; ++m)
for (n=0 ; n<blksz ; ++n)
                {
coef += (p?ac_ alpha:dc_alpha) * (q?ac_alpha:dc_alpha) * Color[yoff+m][xoff+n] 
*cos(M_PI_2 * (2*m+1) * p / blksz) * cos(M_PI_2 * (2*n+1) * q / 
blksz);
}
Dest[yoff+p][xoff+q] = coef;
        }
}

//DCT は锣传 
void idctnbyn( uchar **Dest, uchar **Color, int yoff, int xoff, int blksz, bool truncate)
{
        // 繵瞯办 <=> 办
        //  p,q   <=> m,n
double dc_alpha = 1.0/sqrt(double(blksz));
double ac_alpha = sqrt(2.0/blksz);
double coef;
int p, q, m, n;
for (m=0 ; m<blksz ; ++m)
for (n=0 ; n<blksz ; ++n)
        {
coef = 0.0;
for (p=0 ; p<blksz ; ++p)
for (q=0 ; q<blksz ; ++q)
coef += (p?ac_ alpha:dc_alpha) * (q?ac_alpha:dc_alpha) * (Color[yoff+p][xoff+q]) 
*cos(M_PI_2 * (2*m+1) * p / blksz) * cos(M_PI_2 * (2*n+1) * q / 
blksz);
if (truncate && coef > 255)
Dest[yoff+m][xoff+n] = 255;
else if(truncate && coef <0)
Dest[yoff+m][xoff+n] = 0;
else
Dest[yoff+m][xoff+n]= coef;
        }
}