/*FORMULC.C 2.1           as of 8\18\94        */
/*A fast interpreter of mathematical functions */

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
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <ctype.h>
#include "formulc.h"

#undef FORMU_DEBUG_ON
/* Substitute #define for #undef to trace evaluation */
#ifdef FORMU_DEBUG_ON
 #define DBG(anything)  anything
#else
 #define DBG(anything) /* nothing */
#endif

static double pi(void);

static double value(UCHAR *function);

static CHAR *i_error; /*pointer to the character in source[]
			that causes an error */
static UCHAR *i_trans(UCHAR *function, CHAR *begin, CHAR *end);
static CHAR  *my_strtok(CHAR *s);
static UCHAR *comp_time(UCHAR *function, UCHAR *fend, int npars);

static double param['z'-'a'+1];
struct formu_item {
     CHAR *name;
	void *f;    /* pointer to function*/
	int n_pars; /* number of parameters (0, 1, 2 or 3) */
};
#define TABLESIZE 256
#define STD_LIB_NUM 12
static struct formu_item ftable[TABLESIZE]=
       {{"exp",(void *) exp,1},
	{"ln", (void *) log,1},
	{"sin",(void *) sin,1},
	{"cos",(void *) cos,1},
	{"tan",(void *) tan,1},
	{"asin",(void *) asin,1},
	{"acos",(void *) acos,1},
	{"atan",(void *) atan,1},
	{"atan2",(void *) atan2,2},
	{"abs", (void *) fabs,1},
	{"sqrt", (void *) sqrt,1},
	{"pi", (void *) pi,0},
	{NULL,NULL,0}};

int read_table(int i, CHAR *name, int *n_pars)
/* returns 1 if succesful */
/* returns 0 otherwise */
{
 if(!ftable[i].f)
  return 0;
 else {
  strcpy(name,ftable[i].name);
  *n_pars=ftable[i].n_pars;
  return 1;
 }
}

int where_table(CHAR *name)
/* If the function exists, where_table() returns the index of its name
    in the table. Otherwise, it returns -1. */
{
 struct formu_item *table_p;

 for(table_p=ftable; table_p->f != NULL &&
	strcmp(name,table_p->name); table_p++)
   ;
 if(table_p->f == NULL) /*The end of the table has been reached,
		 but name[] is not there. */
  return -1;
 else return table_p - ftable;
}

int fdel(CHAR *name)
/* If the function exists, it is deleted and a non-negative value
    is returned. */
/* Otherwise, -1 is returned. */
/* Original library functions may not be deleted. */
{
 int place;
 struct formu_item *scan;

 if((place=where_table(name)) == -1)
  return -1;
 if(place<STD_LIB_NUM)
  return -1;

 free(ftable[place].name);
 for(scan = &ftable[place]; scan->f!=NULL; scan++) {
  DBG(printf("%s %s \t",scan->name,scan->f));
  scan->name  =  (scan+1)->name;
  scan->f     =  (scan+1) -> f;
  scan->n_pars = (scan+1) -> n_pars;
 }
 return scan-ftable;
} /*end of fdel */

int fnew(CHAR *name, void *f, int n_pars)
{
 struct formu_item *where;

 if(n_pars<0 || n_pars>3)
  return 0;

 for(where=ftable; where->f != NULL && strcmp(name,where->name); where++);
 if(where->f != NULL) {
  where->f=f;
  where->n_pars = n_pars;   /*old function is superseded */
  return 1;
 } else if((where-ftable) >= TABLESIZE-1)
  return 0;  /*table is full */
 else {
  where->name = (char *) calloc(strlen(name)+1, sizeof(CHAR));
  if(where->name==NULL) return 0;  /* no memory */
  strcpy(where->name,name);
  where->f=f;
  where->n_pars = n_pars;
  return 1;
 }
}  /* end of fnew */


double f_x_val(UCHAR *function, double x)
{
 param['x'-'a']=x;
 return value(function);
}

double fval(UCHAR *function, CHAR *args, ...)
{
 va_list ap;
 double result;

 DBG(puts("Enter fval"));
 va_start(ap, args);
 while(*args)
  param[(*args++)-'a'] = va_arg(ap, double);
 va_end(ap);
 result=value(function);
 return result;
}

#define BUFSIZE 500

double value(register UCHAR *function)
{
 double buffer[BUFSIZE];
 register double *bufp = buffer;
	  /* points to the first free space in the buffer */
 double x,y,z;
 register double result;

 if(!function) return 0; /* non-existent function; result of
			    an unsuccesful call to translate */
 for(;;) {
   switch(*function++) {
    case '\0':goto finish; /* this function must be as fast as possible */
    case 'D': *bufp++ = *((double *) function)++;
	      DBG(printf("%g ",*(bufp-1)));
	      break;
    case 'V': *bufp++ = param[(*function++)-'a'];
	      DBG( printf("%c = %g  ",*(function-1),*(bufp-1)) );
	      break;
    case 'M':DBG(printf("Unary - "));
	     result = -(*--bufp);
	     *bufp++ = result;
	     break;
    case '+':DBG(printf("+ "));
	     y = *(--bufp);
	     result = y + *(--bufp);
	     *bufp++ = result;
	  break;
    case '-':DBG(printf("- "));
	     y = *--bufp;
	     result= *(--bufp) - y;
	     *bufp++ = result;
	     break;
    case '*':DBG(printf("* "));
	     y = *(--bufp);
	     result = *(--bufp) * y;
	     *bufp++ = result;
	     break;
    case '/':DBG(printf("/ "));
	     y = *--bufp;
	     result = *(--bufp) / y;
	     *bufp++ = result;
	     break;
    case '^':DBG(printf("^ "));
	     y = *--bufp;
	     result = pow(*(--bufp),y);
	     *bufp++ = result;
	     break;
    case 'F':DBG(printf("%s ",ftable[*function].name));
	     switch(ftable[*function].n_pars) {
	       case 0:*bufp++ = (*((double (*)(void))
				      ftable[*function++].f))();
		      break;
	       case 1:x = *--bufp;
		      *bufp++ = (*((double (*)(double))
				      ftable[*function++].f))(x);
		      break;
	    case 2:y = *--bufp;
		   x = *--bufp;
		   *bufp++ = (*((double (*)(double,double))
				      ftable[*function++].f))(x,y);
		      break;
	       case 3:z = *--bufp;
		      y = *--bufp;
		      x = *--bufp;
		      *bufp++ = (*((double (*)(double, double, double))
				     ftable[*function++].f))(x,y,z);
		      break;
	       default:printf("Bug! too many parameters\n");
		       return 0;
		 break;
	      }
	     break;
    default:puts("Bug! Unrecognizable operator");
	 return 0;
	 break;
   }
 }
 finish: if((bufp-buffer)!=1)
	  {
	   putchar('\n');
	   puts("Bug! Too many things in the buffer");
	   printf("Buffer: ");
	   while(bufp-- > buffer)
	    printf("%g ",*bufp);
	   putchar('\n');
	  }
	 else DBG(putchar('\n'));
	 return buffer[0];
} /* end of value */



static int isoper(CHAR c)
{
 return ((c == '+') || (c == '-') || (c == '*') || (c == '/')
		    || (c == '^'));
}

static int is_code_oper(UCHAR c)
{
 return ((c == '+') || (c == '-') || (c == '*') || (c == '/')
		    || (c == '^') || (c == 'M'));
}
static int isin_real(CHAR c)
/* + and - are not included */
{
 return (isdigit(c) || c=='.' || c=='E');
}

size_t max_size(CHAR *source)
/* gives an upper estimate of the size required for
   the coded form of source (including the final '\0') */
/* Take care when modifying: the upper estimate
   returned by max_size must not also accomodate
   *proper* output, but also *improper* output
   which takes place before the translator detects an error. */
{
 int numbers=0;
 int functions=0;
 int operators=0;
 int variables=0;

 const size_t func_size=2*sizeof(UCHAR);
 const size_t var_size=2*sizeof(UCHAR);
 const size_t num_size=sizeof(UCHAR)+sizeof(double);
 const size_t op_size=sizeof(UCHAR);
 const size_t end_size=sizeof('\0');

 CHAR *scan;

 for(scan=source; *scan; scan++)
  if(isalpha(*scan) && (*scan != 'E'))
  {
   if(isalpha(*(scan+1))) ; /* it is a function name,
				it will be counted later on */
   else if(*(scan+1) == '(')  functions++;
   else variables++;
  }

 if(isoper(*source)) operators++;
 if(*source != '\0')
  for(scan = source+1; *scan; scan++)
   if(isoper(*scan) && *(scan-1) != 'E') operators++;

 /* counting numbers.. */
 scan=source;
 while(*scan)
  if(isin_real(*scan) || ((*scan == '+' || *scan == '-') &&
			   scan>source && *(scan-1)=='E'))
   {numbers++;
    scan++;
    while(isin_real(*scan) || ((*scan == '+' || *scan == '-') &&
				scan>source && *(scan-1)=='E'))
     scan++;
   }
  else scan++;

 return(numbers*num_size + operators*op_size + functions*num_size
			 + variables*var_size + end_size);
 /*Do you wonder why "functions" is multiplied with "num_size"
   and not with func_size? This function calculates an upper-bound
   (i.e. pessimistic) estimate. It supposes that all functions are
   converted into doubles by comp_time. For example, pi() actually
   becomes a double. */
}

UCHAR *translate(CHAR *source, CHAR *args, int *leng, int *error)
/* source and args are not modified, but the keyword "const"
   is ommitted to avoid complaints of hypersensitive compilers */
{
 UCHAR *result;
 CHAR *scan, *scarg;
 UCHAR *function;
 UCHAR *nfunc; /* used to free unused heap space */
 size_t size_estim; /* upper bound for the size of the
					coded function */

 i_error=NULL;


 /* search for undeclared parameters */
 for(scan=source; *scan != '\0'; scan++) {
  if(islower(*scan) && !isalpha(*(scan+1)) &&
      (scan==source || !isalpha(*(scan-1))) ) {
   for(scarg=args; *scarg != '\0' && *scarg != *scan; scarg++)
     ;
   if(*scarg == '\0') /*parameter not found */
    {
     i_error = scan;

     *leng = 0;
     *error = i_error - source;
     return NULL;
    }
  }
 }  /* end of search for undeclared... */

 size_estim=max_size(source); /* upper estimate of the size
				 of the coded function,
				 which doesn't exist yet */

 if(!(function = (UCHAR *) malloc(size_estim))) {
  /* out of memory */
  *leng = 0;
  *error = -1;
  return NULL;
 }

 result=i_trans(function,source,source+strlen(source));
 if(!result) {
  free(function);
  *leng = 0;
  if(i_error)
   *error = i_error-source;
  else *error = -1; /* out of memory */
  return NULL;
 }
 else { /* OK */
  *result = '\0';
  *error = -1;
  *leng = result-function;

  /* free unused heap space.. */
  if(((*leng)+1) * sizeof(UCHAR) > size_estim)
   /* one must use (*leng)+1 instead of *leng because '\0'
      has not been counted */
   {
    printf("Dangerous bug! The size estimate falls short by %d bytes",
	   ((*leng)+1) * sizeof(UCHAR) - size_estim);
    puts("	Please, tell the author about this error immediately! ");
    puts("Don't forget to write down what mathematical function caused");
    puts("the program to crash. This program's reliability depends on you!");
    puts("Press c and ENTER to continue");
    getchar();
   }
  else if(((*leng)+1) * sizeof(UCHAR) < size_estim) {
   if(nfunc = (UCHAR *) malloc(((*leng)+1) * sizeof(UCHAR))) {
    memcpy( nfunc, function, ((*leng)+1) * sizeof(UCHAR) );
    free(function);
    function=nfunc;
   }
   /* free unused space */
  return function;
  } /* end of if-else stairs */
 } /* end of OK */
}  /* end of translate */

static UCHAR *comp_time(UCHAR *function, UCHAR *fend, int npars)
  /* calculates at "compile time" */
  /* Postconditions: If the coded expression in *function..*(fend-1)
      can be calculated, its value is stored in *function..*(fend-1) */
  /* comp_time returns a pointer to the first character after the
     end of the coded function; if this function cannot be evaluated
     at compile time, comp_time returns fend, of course.  */
  /* Only memory positions from *function to *comp_time are touched. */
{
  UCHAR *scan;
  int ok;
  UCHAR temp;
  double tempd;


  ok=1;
  scan=function;
  while(npars-- > 0) {
   if(*scan++ != 'D') ok=0;
   ((double *)scan)++;
  }

  if(!ok ||
      !( ( scan == fend - (sizeof((UCHAR) 'F')+sizeof(UCHAR))
	   && *(fend-2) == 'F' ) ||
	 ( scan == fend - sizeof(UCHAR)
	   && is_code_oper(*(fend-1)) ) )
    )
    /* compile-time evaluation is done only
       if everything but the ending function consists of doubles */
   return fend;

  temp = *fend;
  *fend = '\0';

  tempd = value(function);
  *fend = temp;
  *function++ = 'D';
  *((double *)function)++ = tempd;

  return function;
} /* end of comp_time */

static CHAR *my_strtok(CHAR *s)
/* a version of strtok that respects parentheses */
/* token delimiter = comma */
{
 int pars;
 static CHAR *token=NULL;
 CHAR *next_token;

 if(s!=NULL) token=s;
 else if(token!=NULL) s=token;
 else return NULL;

 for(pars=0; *s != '\0' && (*s != ',' || pars!=0); s++) {
   if(*s == '(') ++pars;
   if(*s == ')') --pars;
 }
 if(*s=='\0') {
  next_token=NULL;
  s=token;

  token=next_token;
  DBG(printf("The token is: %s\n",s));
  return s;
 } else {
  *s = '\0';
  next_token=s+1;
  s=token;

  token=next_token;
  DBG(printf("The token is: %s\n",s));
  return s;
 }
} /* end of my_strtok */

#define TWO_OP {                                 \
  if((tempu=i_trans(function,begin,scan)) &&      \
      (temp3=i_trans(tempu,scan+1,end)) ) {       \
   *temp3++ = *scan; /* copies operator */                 \
   temp3=comp_time(function,temp3,2);   /*tries to simplify expression*/ \
   return temp3; /* expression has been translated */                    \
  } else return NULL;   /* something is wrong with the operands */       \
 }
#define ERROR_MEM {    \
   i_error=NULL;       \
   return NULL;	       \
   /* out of memory */ \
 }

static UCHAR *i_trans(UCHAR *function, CHAR *begin, CHAR *end)
 /* the source is *begin .. *(end-1) */
 /* returns NULL if an error occured; otherwise, returns a
    pointer to the first character after the end of function[] */
 /* i_trans() does not write a '\0' at the end of function[], */
 /* but it MAY touch its end (i.e. *i_trans) without changing it.*/
{
 int pars;     /* parentheses */
 CHAR *scan;
 UCHAR *tempu, *temp3;
 CHAR *temps;
 CHAR tempch;
 double tempd;
 CHAR *endf;     /* points to the opening
		    parenthesis of a function (e.g. of sin(x) ) */
 int n_function;
 int space;
 int i;

 CHAR *paramstr[MAXPAR];
 CHAR *par_buf;

 if(begin>=end) {
  i_error = begin;
  return NULL;
 }

 DBG(tempch = *end);
 DBG(*end = '\0');
 DBG(puts(begin));
 DBG(*end = tempch);

 /* test paired parentheses */
 for(pars=0, scan=begin; scan<end && pars>=0; scan++) {
  if(*scan == '(') pars++;
  else if(*scan == ')') pars--;
 }
 if(pars<0 || pars>0) {
  i_error = scan-1;
  return NULL;
 }

 /* plus and binary minus */
 for(pars=0, scan=end-1; scan>=begin; scan--) {
  if(*scan == '(') pars++;
  else if(*scan == ')') pars--;
  else if(!pars && (*scan == '+' || ((*scan == '-') && scan!=begin))
					  /* recognizes unary
					     minuses */
	     && (scan==begin || *(scan-1)!='E') )
	  /* be wary of misunderstanding exponential notation */
   break;
 }

 if(scan >= begin) TWO_OP

 /* multiply and divide */
 for(pars=0, scan=end-1; scan>=begin; scan--) {
  if(*scan == '(') pars++;
  else if(*scan == ')') pars--;
  else if(!pars && (*scan == '*' || *scan == '/' ))
   break;
 }

 if(scan >= begin) TWO_OP

 /* power */
 for(pars=0, scan=end-1; scan>=begin; scan--) {
  if(*scan == '(') pars++;
  else if(*scan == ')') pars--;
  else if(!pars && (*scan == '^'))
   break;
 }

 if(scan >= begin) TWO_OP

 /* unary minus */
 if(*begin == '-') {
  if(tempu=i_trans(function,begin+1,end)) {
   *tempu++ = 'M';
   tempu=comp_time(function,tempu,1); /*tries to simplify
					expression*/
   return tempu;
  } else return NULL;
 }

 /* erase white space */
 while(isspace(*begin))
  begin++;
 while(isspace(*(end-1)))
  end--;

 /* parentheses around the expression */
 if(*begin == '(' && *(end-1) == ')')
  return i_trans(function,begin+1,end-1);

 /* variable */
 if(end == begin+1 && islower(*begin)) {
  *function++ = 'V';
  *function++ = *begin;
  return function;
 }

 /* number */
 tempch = *end;
 *end = '\0';
 tempd=strtod(begin,(CHAR**) &tempu);
 *end = tempch;
 if((CHAR*) tempu == end) {
  *function++ = 'D';
  *((double *)function)++ = tempd;
  return function;
 }

 /*function*/
 if(!isalpha(*begin) && *begin != '_')
			/* underscores are allowed */
 {
  i_error=begin;
  return NULL;
 }
 for(endf = begin+1; endf<end && (isalnum(*endf) || *endf=='_');
							   endf++);
 tempch = *endf;
 *endf = '\0';
 if((n_function=where_table(begin)) == -1) {
  *endf = tempch;
  i_error=begin;
  return NULL;
 }
 *endf = tempch;
 if(*endf != '(' || *(end-1) != ')') {
  i_error=endf;
  return NULL;
 }
 if(ftable[n_function].n_pars==0) {
  /*function without parameters (e.g. pi() ) */
   space=1;
   for(scan=endf+1; scan<(end-1); scan++)
    if(!isspace(*scan)) space=0;
   if(space) {
    *function++ = 'F';
    *function++ = n_function;
    function = comp_time(function-2,function,0);
    return function;
   } else {
    i_error=endf+1;
    return NULL;
   }
 } else {    /*function with parameters*/
    tempch = *(end-1);
    *(end-1) = '\0';
    par_buf = (CHAR *) malloc(strlen(endf+1)+1);
    if(!par_buf)
     ERROR_MEM;
    strcpy(par_buf, endf+1);
    *(end-1) = tempch;
    /* look at the first parameter */
    for(i=0; i<ftable[n_function].n_pars; i++) {
     if( ( temps=my_strtok((i==0) ? par_buf : NULL) ) == NULL )
      break; /* too few parameters */
     paramstr[i]=temps;
    }
    if(temps==NULL) {
     /* too few parameters */
     free(par_buf);
     i_error=end-2;
     return NULL;
    }
    if((temps=my_strtok(NULL))!=NULL) {
     /* too many parameters */
     free(par_buf);
     i_error=(temps-par_buf)+(endf+1); /* points to the first character
					  of the first superfluous
					  parameter */
     return NULL;
    }

    tempu=function;
    for(i=0; i<ftable[n_function].n_pars; i++)
     if(!(tempu=i_trans( tempu, paramstr[i],
				 paramstr[i]+strlen(paramstr[i]) ) ) )
     {
      i_error=(i_error-par_buf)+(endf+1); /* moves i_error to
					   the permanent copy of the
					   parameter */
      free(par_buf);
      return NULL; /* error in one of the parameters */
     }
    /* OK */
    free(par_buf);
    *tempu++ = 'F';
    *tempu++ = n_function;
    tempu = comp_time(function,tempu,ftable[n_function].n_pars);
    return tempu;
 }
}

static double pi(void)
{
 return 3.14159265358979323846264;
}
