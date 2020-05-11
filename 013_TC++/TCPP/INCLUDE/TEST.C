/* TEST.C  Demonstration program for FORMULC -- link with FORMULC.C */
/* Copyright (c) 1994 by Harald Helfgott */

/*Copyright (c) 1994 by Harald Helfgott        */
/* This program must be distributed with its corresponding README.DOC */
/* The full copyright and availability notice is in README.DOC	      */
/* 	This program is provided "as is", without any explicit or */
/* implicit warranty. */


/* Programmer's Address:
	    Harald Helfgott
	    MB 1807, Brandeis University
	    P.O. Box 9110
	    Waltham, MA 02254-9110
		   OR
	     (during the summer)
	    2606 Willett Apt. 427
	    Laramie, Wyoming 82070
	    seiere@uwyo.edu */

#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <ctype.h>
#include "formulc.h"
#include <math.h>
#include <time.h>
int main()
{
 int length,error;
 char source[200];
 UCHAR *code;
 double x,result;
 char answer;
 int i;

 puts("FORMULC v2.1 (c) 1994 by Harald Helfgott");
 puts("		Demonstration program");
 puts("");
 puts("    FORMULC is a set of  routines  that  enables  you  to  enter  a");
 puts("mathematical function by keyboard and lets your C or  C++  programs");
 puts("understand it. It is flexible, can run in almost any  computer  and");
 puts("OS, understands many different types of expressions and is extremely");
 puts("fast. The code interpreted by   FORMULC  is  not  much  slower  than");
 puts("compiled C code.");
 puts("         First of all, let's see how much time it takes for FORMULC");
 puts("to calculate the standard normal pdf ( exp(-x*x/2)/sqrt(2*pi) ) at ");
 puts("1000 different points. Press c and ENTER or RETURN to continue.	  ");
 getchar();
 code=translate("exp(-x*x/2)/sqrt(2*pi())", "x", &length, &error);
 if(!code) puts("Bug!");
 answer=0;
 for(x=0.0; x<5.0; x += 0.005)
  answer+=f_x_val(code,x);
 puts(" DONE. Now, C compiled code will do it. Press c and ENTER.");
 getchar();
 getchar();
 answer=0;
 for(x=0.0; x<5.0; x+= 0.005)
  answer+=exp(-x*x/2)/sqrt(2*3.14159265358979323846264);
 puts(" DONE. The difference was not too large, was it? Other interpreters");
 puts("are often several times slower than  the  C  compiler! Of course,");
 puts("the slowest process is to change your program every time you want to");
 puts("change a function which should be determined by the user.");
 puts("");
 puts("    This time, you will enter a function and FORMULC will parse it.");
 puts("Multivariate  functions  are supported,  but,  for  the   sake   of");
 puts("simplicity, you should only use x this time. The notation  must  be");
 puts("similar to C's: don't forget the multiplication sign  (*)  and  use");
 puts("exp(x) instead of e(x) . You MAY use ^ (the power operator) as well");
 puts("as pi() (without  parameters).  Uppercase  scientific  notation  is");
 puts("allowed.");
 do {
  printf("\nEnter your function: ");
  scanf("%s",source);
  getchar();
  code=translate(source, "x", &length, &error);
  if(!code)
   printf("Error at character #%d of the function\n",error);
  else
  {
   printf("      The function has been parsed. Now, enter the value of x: ");
   scanf("%lg",&x);
   getchar();
   result=f_x_val(code,x);
   if(errno==ERANGE) puts("Range error.");
   else if(errno==EDOM) puts("Domain error.");
   else printf("The result is %g\n",result);
   puts("	FORMULC will now evaluate your function for 1000 random");
   puts("values of x. Press Enter to continue.");
   getchar();

   result=0;
   for(i=0; i<1000; i++)
    result +=
     f_x_val(code,-10.0+20.0*((double) rand())/RAND_MAX);

   puts("DONE");
  }
  printf("Do you want to enter another function (y/n) ? ");
  answer=getchar();
 } while(tolower(answer) == 'y');
 puts("Good luck with FORMULC! Read the copyright and availability notice");
 puts("(README.DOC) and the manual (FORMULC.DOC).");
 return(0);
}
