
/*                          */
/* Program Name: isxdigit.c */
/*                          */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* Define a table of function names and numbers */
typedef struct FUNC_TABLE
{
   char name[16];
   int funcnum;
}FUNC_TABLE;

#define CNTRL 0
#define DIGIT 1
#define GRAPH 2
#define LOWER 3
#define PRINT 4
#define PUNCT 5
#define SPACE 6
#define UPPER 7
#define XDIGIT 8

/* Now declare the tabel and initialize it */
static FUNC_TABLE isfuncs[9] =
{
   "iscntrl",CNTRL,"isdigit",DIGIT,
   "isgraph",GRAPH,"islower",LOWER,
   "isprint",PRINT,"ispunct",PUNCT,
   "isspace",SPACE,"isupper",UPPER,
   "isxdigit",XDIGIT
};
static int numfunc = sizeof(isfuncs)/sizeof(FUNC_TABLE);

void main(void)
{
   int ch, count, i, test_result;
   int mark=0xdb;   /* to mark characters */
   char *input_func_name;
   printf("Enter function's name of special attribute ASCII"
   " character\nthat you want to find out:");
   scanf("%s",input_func_name);
   /* Search table for function name and pointer */
   for (i=0;i<numfunc;i++) {
      if (strcmp(input_func_name,isfuncs[i].name)==0) {
         break;
      }
   }
   if (i>=numfunc) {
      printf("unknown functions:%s\n",input_func_name);
      exit(0);
   }
   /* Now go over entire ASCII table and mark the */
   /* characters that satisfy requested test      */
   printf("Those marked with a %c satisfy %s\n"
                         ,mark,input_func_name);
   for (count=0,ch=0;ch<=0x7f;ch++) {
      printf("%#04x ",ch);
      /* Print character -- if printable */
      if (isprint(ch)) {
         printf(" %c",ch);
      }
      else {
         printf("  ");
      }
      /* Perform the test and put a mark if test succeeds */
      switch(isfuncs[i].funcnum) {
         case CNTRL:test_result=iscntrl(ch);
                    break;
         case DIGIT:test_result=isdigit(ch);
                    break;
         case GRAPH:test_result=isgraph(ch);
                    break;
         case LOWER:test_result=islower(ch);
                    break;
         case PRINT:test_result=isprint(ch);
                    break;
         case PUNCT:test_result=ispunct(ch);
                    break;
         case SPACE:test_result=isspace(ch);
                    break;
         case UPPER:test_result=isupper(ch);
                    break;
         case XDIGIT:test_result=isxdigit(ch);
                    break;
      }
      if (test_result!=0) {
         printf("%c ",mark);
      }
      else {
         printf("  ",ch);
      }
      count++;
      if (count==6) {
         printf("\n\n");
         count=0;
      }
   }
}
