/*
  Encode an RLE buffer
  Return the length in the output buffer
  Note: this is not my code, it was handed to me as is.
  If you are the author or know the author please let me know
  so I can give appropriate credit.
*/
#include "tiffiop.h"

unsigned int DTTPackbitsEncodeImage(unsigned char * out,unsigned char *pixels,const size_t length)
{
  int count;

  register long i, j;

  unsigned char *packbits;
  long lPos = 0;

  /*
    Compress pixels with Packbits encoding.
  */
  packbits=(unsigned char *) new unsigned char[ 128 ];

  if (packbits == (unsigned char *) NULL)
    return 0;

  i=(long) length;
  while (i != 0)
  {
    switch (i)
    {
      case 1:
      {
        i--;
        out[ lPos++ ] = 0;
        out[ lPos++ ] = *pixels;
        break;
      }
      case 2:
      {
        i-=2;
        out[ lPos++ ] = 1;
        out[ lPos++ ] = *pixels;
        out[ lPos++ ] = pixels[ 1 ];
        break;
      }
      case 3:
      {
        i-=3;
        if ((*pixels == *(pixels+1)) && (*(pixels+1) == *(pixels+2)))
          {
            out[ lPos++ ] = (256-3)+1;
            out[ lPos++ ] = *pixels;
            break;
          }
            out[ lPos++ ] = 2;
            out[ lPos++ ] = *pixels;
            out[ lPos++ ] = pixels[ 1 ];
            out[ lPos++ ] = pixels[ 2 ];
        break;
      }
      default:
      {
        if ((*pixels == *(pixels+1)) && (*(pixels+1) == *(pixels+2)))
          {
            /*
              Packed run.
            */
            count=3;
            while (((long) count < i) && (*pixels == *(pixels+count)))
            {
              count++;
              if (count >= 127)
                break;
            }
            i-=count;
            out[ lPos++ ] = (unsigned char)((256-count)+1);
            out[ lPos++ ] = *pixels;
            pixels+=count;
            break;
          }
        /*
          Literal run.
        */
        count=0;
        while ((*(pixels+count) != *(pixels+count+1)) ||
               (*(pixels+count+1) != *(pixels+count+2)))
        {
          packbits[count+1]=pixels[count];
          count++;
          if (((long) count >= (i-3)) || (count >= 127))
            break;
        }
        i-=count;
        *packbits=count-1;
        for (j=0; j <= (long) count; j++)
          out[ lPos++ ] = packbits[ j ];
        pixels+=count;
        break;
      }
    }
  }
  out[ lPos ] = 128;
  delete[] packbits;
  return(lPos);
}
