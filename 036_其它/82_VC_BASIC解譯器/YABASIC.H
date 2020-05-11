/*
     YABASIC --- a tiny integrated Basic Compiler/Interpreter

     header-file
     
     this Program is subject to the GNU General Public License;
     see the file yabasic.c for details.
*/

#define YABASIC_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h>
#include <math.h>
#include <time.h>

#ifdef WINDOWS
#include <windows.h>
#include <io.h>
#endif

#ifdef UNIX
#include <sys/time.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <unistd.h>
#endif

#include <signal.h>
#include <ctype.h>


/*-------------- variables needed in all files ------------------------ */

extern char *string;
extern int errorlevel;
extern int end_of_file;
extern struct command *lastinput; /* last input-command */
extern int interactive; /* true, if commands come from stdin */	


/*-------------------------- defs and undefs ------------------------*/

/* undef symbols */
#undef FATAL
#undef ERROR
#undef WARNING
#undef NOTE
#undef DIAGNOSTIC

#if !defined(TRUE)
#define TRUE (1==1)
#endif

#ifndef FALSE
#define FALSE (1!=1)
#endif

/* I've been told, that some symbols are missing under SunOs ... */
#ifndef RAND_MAX
#define RAND_MAX 32767
#endif
#ifndef FOPEN_MAX
#define FOPEN_MAX 20
#endif

/* length of buffers for system() and input */
#define SYSBUFFLEN 100
#define INBUFFLEN 1000

/* ---------------------- enum types ------------------------------- */

enum error {  /* error levels  */
  FATAL,ERROR,WARNING,NOTE,DIAGNOSTIC
};

enum functions { /* functions in yabasic (sorted by number of arguments) */
  fRAN2,fDATE,fTIME,fZEROARGS,fINKEY,fSIN,fASIN,fCOS,fACOS,fTAN,
  fATAN,fSYSTEM,fSYSTEM2,fPEEK,fPEEK2,fEXP,fLOG,fLEN,fSTR,
  fSQRT,fSQR,fFRAC,fABS,fSIG,fRAN,fINT,fVAL,fASC,fUPPER,fLOWER,
  fLTRIM,fRTRIM,fTRIM,fCHR,fXMAP,fYMAP,fONEARGS,fATAN2,fLEFT,
  fRIGHT,fINSTR,fSTR2,fMOD,fMIN,fMAX,fTWOARGS,fMID
};

enum arraymode { /* type of array access */
  CALLARRAY,ASSIGNARRAY,CALLSTRINGARRAY,ASSIGNSTRINGARRAY,GETSTRINGPOINTER
};

enum cmd_type { /* type of command */
  cFIRST_COMMAND, /* no command, just marks start of list */
  
  cLABEL,cGOTO,cQGOTO,cGOSUB,cQGOSUB,cRETURN,  /* flow control */
  cEND,cDECIDE,cSKIPPER,cNOP,cFINDNOP,cEXCEPTION,
  cSKIPONCE,cRESETSKIPONCE,
  
  cDIM,cFUNCTION,cDOARRAY,                        /* everything with "()" */
  
  cSTARTFOR,cFORCHECK,cFORINCREMENT,              /* for for-loops */

  cDBLADD,cDBLMIN,cDBLMUL,cDBLDIV,cDBLPOW,            /* double operations */
  cNEGATE,cPUSHDBLSYM,cPOPDBLSYM,cPUSHDBL,
  
  cPOKE,cSWAP,cDUPLICATE,                           /* internals */
  
  cAND,cOR,cNOT,cLT,cGT,cLE,cGE,cEQ,cNE,            /* comparisons */
  cSTREQ,cSTRNE,cSTRLT,cSTRLE,cSTRGT,cSTRGE,
  
  cPUSHSTRSYM,cPOPSTRSYM,cPUSHSTR,cCONCAT,           /* string operations */
  cPUSHSTRPTR,cCHANGESTRING,cTOKEN,
  
  cPRINT,cREAD,cRESTORE,cQRESTORE,cONESTRING,         /* i/o operations */
  cREADDATA,cDATA,cOPEN,cCLOSE,cSWITCH,cTESTEOF,
  cWAIT,cBELL,cMOVE,cCLEARSCR,cREVERT,cCHKPROMPT,
  
  cOPENWIN,cDOT,cLINE,cCIRCLE,cTEXT,cCLOSEWIN,cCLEARWIN,   /* grafics */
  cOPENPRN,cCLOSEPRN,cMAKEMAP,cTICK,cMAP,cMOVEORIGIN,cRECT,
  cMARKER,
  
  cLAST_COMMAND /* no command, just marks end of list */
};

enum stackentries { /* different types of stackentries */
  stGOTO,stSTRING,stNUMBER,stLABEL,stRETADD,stFREE
};

enum symbols { /* different types of symbols */
  sySTRING,syNUMBER,syFREE,syARRAY
};

enum states { /* current state of program */
  HATCHED,INITIALIZED,COMPILING,RUNNING,FINISHED
};

/* ------------- global types ---------------- */ 

struct stackentry { /* one element on stack */ 
  int type;     /* contents of entry */
  struct stackentry *next;
  struct stackentry *prev;
  void *pointer; /* multiuse ptr */
  double value;  /* double value, only one of pointer or value is used */
};

struct symbol {   /* general symbol; either variable, string, label or call */
  int type;
  struct symbol *next;
  char *name;
  void *pointer;   /* general pointer */
  char *args;      /* used to store number of arguments for functions/array */
  double value;
};

struct command { /* one interpreter command */
  int type;    /* type of command */
  struct command *next;  /* link to next command */
  void *pointer;       /* pointer to command specific data */
  int args;  /* number of arguments for function/array call */
             /* or stream number for open/close             */
  char tag;  /* letter to pass some information */
  int line; /* line this command has been created for */
};

struct array { /* data structure for arrays */
  int bounds[10];  /* index boundaries */
  int dimension; /* dimension of array */
  int total; /* product of all dimensions */
  int dimed;      /* Flag to mark if array has been dimed already */
  void *pointer; /* contents of array */
  char type;  /* decide between string- ('s') and double-Arrays ('d') */
};

struct buff_chain { /* buffer chain for system-input */
  char buff[SYSBUFFLEN]; /* content of buffer */
  struct buff_chain *next; /* next buffer in chain */
};


/* ------------- function prototypes for ... ---------------- */
/* ------------- main program and auxiliary functions ---------------- */
int main(int,char **);
int yyparse(void); /* yyparse is supplied by BISON */
struct symbol *get_sym(char *,int,int); /* find and/or add a symbol */
struct command *add_command(int); /* get room for new command */
void parse_arguments(int,char *argv[]); /* parse arguments from command line */
void initialize(void); /* give correct values to pointers etc ... */
void reset(void); /* reset pointers to their initial values */
void signal_handler(int);  /* handle various signals */
void create_exception(int); /* create command 'exception' */
void exception(struct command *); /* change handling of exceptions */
void error(int,char *); /* reports an error and possibly exits */
char *my_strdup(char *); /* my own version of strdup */
char *my_strndup(char *,int); /*  own version of strndup */
void *my_malloc(unsigned); /* my own version of malloc */
void run_it(void); /* execute the compiled code */
void end_it(int); /* perform shutdown operations */
char *do_system(char *); /* executes command via command.com */
int do_system2(char *); /* execute command as system */
void clear_buff(); /* clear system-input buffers */
void store_buff(char *); /* store system-input buffer */
char *recall_buff(); /* recall store buffer */
void create_poke(char); /* create Command 'POKE' */
void poke(); /* poke in internals */
double peek(char *); /* peek into internals */
char *peek2(char *); /* peek into internals */
void std_diag(char *,int); /* produce standard diegnostic */
void duplicate(void); /* duplicate topmost element of stack */

/* ------------- WIN95-specific stuff ----------- */
#ifdef WINDOWS
LRESULT CALLBACK mywindowproc(HWND,unsigned,UINT,DWORD); /* window-proc */
void chop_command(char *,int *,char ***); /* chops WIN95-commandline */
void startdraw(void); /* prepare for drawing */
DWORD winthread(LPWORD); /* window-thread */
char *getreg(char *); /* get default from Registry */
BOOL CtrlHandler(DWORD);  /* Handle signals */ 
int is_valid_key(INPUT_RECORD *); /* check if input rec contains valid key */
#endif

/* ------------- double handling ---------------- */
void negate(void);  /* negates top of stack */
void create_pushdblsym(char *); /* create command 'pushdblsym' */
void pushdblsym(struct command *); /* push double symbol onto stack */
void create_popdblsym(char *); /* create command 'popdblsym' */
void popdblsym(struct command *); /* pop double from stack */
void create_pushdbl(double); /* create command 'pushdbl' */
void pushdbl(struct command *); /* push double onto stack */
void create_dblbin(char); /* create binary expression calculation */
void dblbin(struct command *); /* compute with two numbers from stack */
void create_dblrelop(char); /* create command dblrelop */ 
void dblrelop(struct command *);  /* compare topmost double-values */

/* ------------- string handling ---------------- */
void create_pushstrsym(char *); /* push string symbol onto stack */
void pushstrsym(struct command *);   /* push string symbol onto stack */
void create_popstrsym(char *); /* create command 'popstrsym' */
void popstrsym(struct command *); /* pop string from stack */
void concat(void); /* concetenates two strings from stack */
void create_pushstr(char *); /* creates command pushstr */
void pushstr(struct command *); /* push string onto stack */
void pushname(char *); /* push a name on stack */
void create_strrelop(char); /* create command strrelop */ 
void strrelop(struct command *);  /* compare topmost string-values */
void create_changestring(int); /* create command 'changestring' */
void changestring(struct command *); /* changes a string */
void create_pushstrptr(char *); /* push string-pointer onto stack */
void pushstrptr(struct command *);  /* push string-pointer onto stack */
void create_token(int); /* create command 'token' */
void token(struct command *); /* extract token from variable */

/* ------------- for-next loop ---------------- */
void forcheck(void); /* check, if for-loop is done */
void forincrement(void); /* increment value on stack */
void startfor(void); /* compute initial value of for-variable */

/* ------------- i/o ---------------- */
void create_print(char); /* create command 'print' */
void print(struct command *); /* print on screen */
char *replace(char *); /* replace \n,\a, etc. */
void create_myread(char,int); /* create command 'read' */
void myread(struct command *); /* read from file or stdin */
int onechar(); /* read one char from currentinstream */
void backchar(int); /* put char back into stream */
void create_onestring(char *); /* write string to file */
void onestring(char *); /* write string to file */
void chkprompt(void); /* print an intermediate prompt if necessary */
void readline(void); /* read one line from current stream */
void create_prompt(char *); /* create command 'prompt' */
void prompt(struct command *); /* set input prompt */
void create_myopen(double,int); /* create command 'myopen' */
void myopen(struct command *); /* open specified file for given name */
void create_testeof(double); /* create command 'testeof' */
void testeof(struct command *); /* close the specified stream */
void create_myclose(double); /* create command 'myclose' */
void myclose(struct command *); /* close the specified stream */
void create_myswitch(int); /* create command 'myswitch' */
void myswitch(struct command *); /* switch to specified stream */
int badstream(int); /* test for valid stream id */
void create_mymove(); /* create command 'move' */
void mymove(); /* move to specific position on screen */
void clearscreen(); /* clear entire screen */
void curinit(); /* initialize curses */
void create_revert(int); /* create command 'reverse' */

/* ------------- grafics ---------------- */
void create_openwin(int); /* create Command 'openwin' */
void openwin(struct command *); /* open a Window */
void create_openps(double,int); /* create Command 'open_ps' */
void openps(struct command *); /* store information for postscript-output */
void create_closeps(void);  /* create Command 'closeps' */
void closeps(void); /* close the ps-file */
void create_openprinter(int); /* create command 'openprinter' */
void openprinter(struct command *); /* opens a printer for WIN95 */
void closeprinter(void); /* closes printer for WIN95 */
void dot(void); /* draw a dot */
void create_line(char); /* create Command 'line' */
void line(struct command *); /* draw a line */
void do_line(double,double,double,double); /* actually draw a line */
void moveorigin(); /* move origin of window */
void transform(double *,double *); /* do transformation */
int check_alignement(char *); /* checks, if text-alignement is valid */
void circle(void); /* draw a circle */
void do_circle(double,double,double); /* actually draw the circle */
void create_text(int); /* create Command 'text' */
void text(struct command *); /* write a text */
void do_text(int,int,char *,char *); /* actually write a text */
void closewin(void); /* close the window */
void clearwin(void); /* clear the window */
void calc_psscale(void);  /* calculate scale-factor for postscript */
int grafinit(void);  /* initialize grafics (either X or WIN95) */
void makemap(); /* make map for plotting */
void map(); /* make map for plotting */
void create_tick(int flag); /* create Command 'cTICK' */
void tick(); /* draw tick on axes */
void create_rect(int); /* create Command 'RECT' */
void rect(struct command *); /* draw a (filled) rect */
void create_marker(int); /* create command 'cMARKER' */
void marker(struct command *); /* draw a marker */


/* ------------- flow--control ---------------- */
void create_goto(char *); /* creates command goto */
void create_gosub(char *); /* creates command gosub */
void create_label(char *); /* creates command label */
void pushgoto(void); /* generate label and push goto on stack */
void popgoto(void); /* pops a goto and generates the matching command */
void jump(struct command *); /* jump to specific Label */
void myreturn(void); /* return from gosub */
void findnop(); /* used for on_gosub, find trailing nop command */
void skipper(void); /* used for on_goto/gosub, skip commands */
void skiponce(struct command *); /* skip next command once */
void resetskiponce(struct command *); /* find and reset next skip */
void decide(void); /*  skips next command, if not 0 on stack */

/* ------------- miscellanous basic commands ---------------- */
void create_boole(char); /* create command boole */ 
void boole(struct command *);  /* perform and/or/not */
void create_function(int); /* create command 'function' */
void function(struct command *); /* performs a function */
int myformat(char *,double,char *); /* format number */
void create_doarray(char *,int); /* creates array-commands */ 
void doarray(struct command *);  /* call an array */
void create_dim(char *,char); /* create command 'dim' */
void dim(struct command *); /* get room for array */
void create_restore(char *); /* create command 'restore' */
void restore(struct command *); /* reset data pointer to given label */
void create_dbldata(double);  /* create command dbldata */
void create_strdata(char *);  /* create command strdata */
void create_readdata(char); /* create command readdata */
void readdata(struct command *); /* read data items */
void mywait(); /* wait given number of seconds */
void mybell(); /* ring ascii bell */


/* ------------- basic functions ---------------- */

char *fromto(char *,int,int); /* portion of string (for mid$,left$,right$) */
char *inkey(double); /* gets char from keyboard, blocks and doesn´t print */


/* ------------- other stack operations ---------------- */

void pushcounter(void); /* push number '0' on stack */
void inccounter(void); /* increment topmost stack element */
void pushletter(char *); /* push letter on stack (for argument test) */
void pushlabel(void); /* generate goto and push label on stack */
void poplabel(void); /* pops a label and generates the matching command */
void storelabel(); /* push label on stack */
void matchgoto(); /* generate goto matching label on stack */
void swap(void); /*swap topmost elements on stack */
struct stackentry *push(void); /* push element on stack and enlarge it*/
struct stackentry *pop(void); /* pops element to memory */

/* ------------- flex ------------------------ */
void yyerror(char *); /* yyerror message */

/* ------------- fixes for missing functions ----------- */
/* fix for missing functions */
#if defined(HAVE_SETITIMER) && !defined(HAVE_SETITIMER_PROTO)
extern int setitimer(int,struct itimerval *,struct itimerval *);
#endif
#if !defined(HAVE_DIFFTIME) && defined(UNIX)
double difftime(long a,long b);
#endif
