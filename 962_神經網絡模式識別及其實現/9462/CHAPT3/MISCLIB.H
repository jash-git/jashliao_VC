#include <ctype.h>
#include <process.h>

int IsHexString(char *xStr) {
   int flg=1; //default true
   int i;
   for (i=0; i<strlen(xStr); i++) {
      if (!isxdigit(xStr[i])) {
         flg=0;
         } /* endif */
   } /* endfor */
   return flg;
}

unsigned char HexStringToByte(char *xStr) {
   char digit[4];
   if ((strlen(xStr)>2)||(strlen(xStr)==0)) return 0; //invalid length
   if (strlen(xStr)<2) {
      strcpy(digit,"0");
      strcat(digit,xStr);
      }
    else {
      strcpy(digit,xStr);
      } /* endif */
   digit[0] = toupper(digit[0]);
   digit[1] = toupper(digit[1]);
   unsigned char bh = (unsigned char)digit[0];
   unsigned char bl = (unsigned char)digit[1];
   if (bh<=0x39) {
      bh= bh-0x30;
      }
    else {
      bh= bh-0x37;
      } /* endif */
   if (bl<=0x39) {
      bl= bl-0x30;
      }
    else {
      bl= bl-0x37;
      } /* endif */
   return ( (bh<<4) | bl );
}

void ByteToHexString(unsigned char x, char *xStr) {
    unsigned char d0,d1;

     d0 = x >> 4;
     d1 = x & 0x0f;

    if (d0 <= 0x09) {
       xStr[0] = d0+0x30;
       }
      else {
       xStr[0] = d0+0x37;
       } /* endif */
    if (d1 <= 0x09) {
       xStr[1] = d1+0x30;
       }
      else {
       xStr[1] = d1+0x37;
       } /* endif */

    xStr[2] = 0;

}


char *DoubleToString(double x, char *dst, int Ndigits) {
  char *tmp;
  int decimalpt,sign;
  int i;

  tmp=fcvt(x, Ndigits, &decimalpt, &sign);
  if (sign) 
     strcpy(dst,"-");
   else
     strcpy(dst,"+");
  if (decimalpt<= -20 ) {
     strcat(dst,"0.0");
     return dst;
     }
   else {
     } /* endif */
  if (decimalpt<=0) {
     strcat(dst,"0.");
     decimalpt= -1*decimalpt;
     for (i=0; i<decimalpt; i++) {
        strcat(dst,"0");
        } /* endfor */
     strcat(dst,tmp);
     } 
   else {
     for (i=0; i<decimalpt; i++) {
        dst[i+1]=tmp[i];
        } /* endfor */
     dst[decimalpt+1]='.';
     for (i=decimalpt; i<strlen(tmp); i++) {
        dst[i+2]=tmp[i];
        } /* endfor */
     dst[strlen(tmp)+2]=0;
     } /* endif */
  return dst;
}


void StringPadLeft(char *szUser, int N) {
  char temp[128];

  strcpy(temp,szUser);
  szUser[0]=0;
  while ( (strlen(temp) + strlen(szUser)) < N) {
     strcat(szUser," ");
  } /* endwhile */
  strcat(szUser,temp);
}
