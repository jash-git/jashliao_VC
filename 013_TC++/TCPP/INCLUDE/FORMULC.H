/* FORMULA.H     as of 8\18\94 (v2.1)*/
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
#define CHAR char
		    /* this may be signed or unsigned; it must
			only be the usual format for printable
			characters (i.e. characters in the
			source expression) . */
#define UCHAR unsigned char
#define MAXPAR 3
		    /* maximum number of parameters */
UCHAR *translate(CHAR *source, CHAR *args, int *length, int *error);
double fval(UCHAR *function, CHAR *args, ...);
double f_x_val(UCHAR *function, double x);
int fnew(CHAR *name, void *f, int n_of_pars);
int read_table(int i, CHAR *name, int *n_of_pars);
int where_table(CHAR *name);
int fdel(CHAR *name);
