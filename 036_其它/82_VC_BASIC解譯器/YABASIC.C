/*  
YABASIC ---  a tiny integrated Basic Compiler/Interpreter
written by Marc-Oliver Ihm 1995-99.
e-mail: ihm@kph.uni-mainz.de

  Current Version:
*/
#define BASIC_VERSION            "2.45"
/*
Date of last change: 
*/
#define DOLC                     "February 26, 1999"

char YABLICENSE[]=

"     This program is free software; you can redistribute it and/or       \n"
"     modify it under the terms of the GNU General Public License         \n"
"     as published by the Free Software Foundation; either version        \n"
"     of the License, or (at your option) any later version.              \n"
"                                                                         \n"
"     This program is distributed in the hope that it will be useful,     \n"
"     but WITHOUT ANY WARRANTY; without even the implied warranty of      \n"
"     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the       \n"
"     GNU General Public License for more details.                        \n"
"                                                                         \n"
"     You should have received a copy of the GNU General Public License   \n"
"     along with this program (the file is named COPYING);                \n"
"     if not, write to the Free Software                                  \n"
"     Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.           \n"
;


/* ------------- defines ---------------- */

/*
Define one and only one of the following symbols, depending on your
System:
- UNIX: uses some UNIX-features and X11
- WINDOWS: uses WIN32-features
*/


#define DONE {current=current->next;break;}  /* reduces type-work */

#if defined(UNIX) && defined(WINDOWS)
UNIX and WINDOWS are defined at once; check your compiler settings
#endif


/* ------------- includes ---------------- */


#ifndef YABASIC_INCLUDED
#include "yabasic.h"       /* all prototypes and structures */
#endif
#ifdef UNIX
#include <curses.h>
#endif


/* ------------- external references ---------------- */

extern int yylineno;   /* current line number */
extern void switch_to_my_file(FILE *); /* switches lex input */ 
extern int yyparse();  /* call bison parser */


/* ------------- global variables ---------------- */

struct symbol *symroot; /* first element in symbol list */
struct symbol *symhead; /* last element ind symbol list */
struct stackentry *stackroot; /* lowest element in stack */
struct stackentry *stackhead; /* topmost element in stack */
struct command *current; /* currently executed command */
struct command *cmdroot; /* first command */
struct command *cmdhead; /* last command */
struct command *datapointer; /* current location for read-command */
int infolevel; /* controls issuing of error messages */
int errorlevel; /* highest level of error message seen til now */
int end_of_file=FALSE; /* TRUE, if end of file has been reached */
int diagnostic_count; /* number of diagnostic messages */
int note_count; /* number of notes */
int warning_count; /* number of warning messages */
int error_count; /* number of error messages */
int interactive; /* true, if commands come from stdin */
char *string; /* for trash-strings */
int labelcount=0; /* count self-generated labels */
int commandcount; /* total number of commands */
int program_state;  /* state of program */
int prompted; /* TRUE, if prompt is fresh */
FILE *streams[10]; /* file streams */
FILE *cinstr; /* current stream for input */
FILE *coutstr; /* current stream for output */
char linebuffer[INBUFFLEN]; /* buffer for one line of input */
int curinized=FALSE; /* true, if curses has been initialized */
char *currchar; /* current char to read */
struct buff_chain *buffroot; /* start of sys-input buffer */
struct buff_chain **buffcurr; /* current entry in buff_chain */
int buffcount; /* number of filled buffers */
char *progname; /* name of yabasic-program */
char *explanation[cLAST_COMMAND-cFIRST_COMMAND+1]; /* explanations */
char **yabargv; /* arguments for yabasic */
int yabargc; /* number of arguments in yabargv */

/* printer-related */
FILE *printerfile=NULL; /* file to print on */
char *prfilename=NULL; /* filename to print on */
int print_to_file; /* print to file ? */


/* ------------- global variables for Graphics ---------------- */

char *text_align; /* specifies alignement of text */
char *winorigin; /* direction to increase y */
#ifdef UNIX
Display *display; /* X-Display */
Window window,root; /* ID of window and root window */
GC gc; /* GC for drawing */
GC rgc; /* GC for reverse drawing */
XSizeHints sizehints; /* hints for window manager */
static unsigned long f_colour,b_colour; /* colors */
XFontStruct *myfont; /* properties of default font */
#elif WINDOWS
WNDCLASS myclass; /* window class for my program */
HWND window;   /* handle of my window */
HANDLE this_instance;
HDC devcon; /* device context for screen */
HDC bitcon; /* device context backing bitmap */
HBITMAP backbit; /* backing bitmap */
char *my_class="my_class";
HANDLE wthandle; /* handle of win thread */
DWORD wtid; /* id of win thread */
HANDLE wtevent=INVALID_HANDLE_VALUE; /* handle for win thread event */
LOGFONT logfont; /* structure for font-characteristics */
HFONT myfont; /* handle of font for screen */
HFONT printerfont; /* handle of printer-font */
HPEN printerpen; /* handle of printer-pen */
HDC printer=NULL; /* handle of printer */
float prnscale;  /* scaling factor for printer */
float prnoff;  /* offset for printer */
BOOL Commandline; /* true if launched from command line */
HANDLE ConsoleInput; /* handle for console input */
HANDLE ConsoleOutput; /* handle for console output */
int LINES=0; /* number of lines on screen */
int COLS=0; /* number of columns on screen */
HANDLE mainthread=INVALID_HANDLE_VALUE; /* handle to main thread */
#endif

int winwidth,winheight;  /* size of window */
int winx,winy; /* position of window */
int winopened=FALSE; /* flag if window is open already */
double psscale; /* from pixels to points */
int fontheight; /* height of used font in pixel */
char *foreground=NULL;
char *background=NULL;
char *geometry=NULL;
char *displayname=NULL;
char *font=NULL;

/* for plotting */
double xoff=0.; /* offset for x-mapping */
double xinc=1.; /* inclination of x-mapping */
double yoff=0.; /* offset for y-mapping */
double yinc=1.; /* inclination for y-mapping */

/* timing */
time_t compilation_start,compilation_end,execution_end;


/* ------------- main program ---------------- */

int main(int argc,char **argv)
{
#ifdef WINDOWS
  CONSOLE_SCREEN_BUFFER_INFO csbi;
#endif
	
  string=(char *)malloc(sizeof(char)*INBUFFLEN);
	
  program_state=HATCHED;
  infolevel=WARNING; /* set the initial Infolevel */
	
#ifdef WINDOWS
  /* get handle for current thread */
  DuplicateHandle(GetCurrentProcess(),GetCurrentThread(),
		  GetCurrentProcess(),&mainthread,THREAD_ALL_ACCESS,FALSE,0);

  /* get handle of instance */
  this_instance=GetModuleHandle(NULL);
	
  /* define my window class */
  myclass.style=0;
  myclass.lpfnWndProc=(LPVOID)mywindowproc;
  myclass.cbClsExtra=0; /* no extra bytes */
  myclass.cbWndExtra=0;
  myclass.hInstance=this_instance;
  myclass.hIcon=LoadIcon(this_instance,"yabasicIcon");
  myclass.hCursor=LoadCursor(NULL,IDC_ARROW); /*  standard cursor */
  myclass.hbrBackground=(HBRUSH)COLOR_WINDOW; /* default-background */
  myclass.lpszMenuName=NULL;
  myclass.lpszClassName=my_class;
	
  RegisterClass(&myclass);
	
  /* get console handles */
  ConsoleInput=GetStdHandle(STD_INPUT_HANDLE);
  ConsoleOutput=GetStdHandle(STD_OUTPUT_HANDLE);
	
  /* find out, if launched from commandline */
  GetConsoleScreenBufferInfo(ConsoleOutput,&csbi);
  Commandline=!((csbi.dwCursorPosition.X==0) && (csbi.dwCursorPosition.Y==0));
  if ((csbi.dwSize.X<=0) || (csbi.dwSize.Y <= 0)) Commandline=TRUE;
	
#endif
	
  parse_arguments(argc,argv);
	
  time(&compilation_start);
  initialize();
  program_state=INITIALIZED;
	
  error(NOTE,"Calling parser/compiler");
  if (interactive) {
    printf("Enter your program; type <RETURN> twice, when done.\n");
  }
  program_state=COMPILING;
  if (yyparse() && errorlevel>ERROR) {
    error(ERROR,"Couldn't parse program");
  }
	
  add_command(cEND);
  sprintf(string,"Read %d line(s)",yylineno);
  error(NOTE,string);
  sprintf(string,"Generated %d command(s)",commandcount);
  error(NOTE,string);
	
  time(&compilation_end);
	
  if (errorlevel>ERROR) {
    program_state=RUNNING;
    run_it();}
  else {
    program_state=FINISHED;
    error(ERROR,"Program not executed");
  }
	
  sprintf(string,"%d diagnostic(s), %d note(s), %d warning(s), %d error(s)",
	  diagnostic_count,note_count,warning_count,error_count);
  error(NOTE,string);
  time(&execution_end);
  sprintf(string,"Compilation time = %g second(s)",
	  difftime(compilation_start,compilation_end));
  error(NOTE,string);
  sprintf(string,"Execution time = %g second(s)",
	  difftime(execution_end,compilation_end));
  error(NOTE,string);    
  end_it((errorlevel<=ERROR)?1:0);
  return 0;
}



/* ------------- subroutines ---------------- */


struct symbol *get_sym(char *name,int type,int add) 
     /* gets the value of a symbol, or creates it with initial value type */
{
  struct symbol *curr,*new;
	
  curr=symroot;
  while(curr!=symhead) {   /* search 'til head of list */
    if (curr->type==type  /* do the types match ? */
	&&!strcmp(name,curr->name))  /* do the names match ? */
      return curr; /* give back address */
    curr=curr->next; /* try next entry */
  }
  /* run (ppp) through all variables. */
  if (!add) return NULL;  /* dont create, if not found */
  /* end of list, create new element */
  new=(struct symbol *)my_malloc(sizeof(struct symbol)); /* ceate new item */
  symhead=new;  /* advance head */
  curr->name=my_strdup(name);  /* store new name */
  curr->next=new;
  curr->value=0.0;
  curr->pointer=NULL;
  curr->type=type;
  curr->value=0.0;
  if (type==sySTRING) {   /* create empty string */
    curr->pointer=my_malloc(sizeof(char));
    *(char *)(curr->pointer)='\0';
  }
  return curr;
}

void create_pushdbl(double value) /* create command 'cPUSHDBL' */
{
  struct command *cmd;
	
  cmd=add_command(cPUSHDBL);
  if (cmd->pointer==NULL) cmd->pointer=my_malloc(sizeof(double));
  *(double *)(cmd->pointer)=value;
}


void pushdbl(struct command *cmd) 
{
  /* push double onto stack */
  struct stackentry *p;
	
  p=push();
  p->value= *(double *)cmd->pointer;
  p->type=stNUMBER;
}


void create_pushdblsym(char *symbol) /* create command 'pushdblsym' */
{
  struct command *cmd;
	
  cmd=add_command(cPUSHDBLSYM);
  /* get room to store specific information */
  cmd->pointer= &(get_sym(symbol,syNUMBER,TRUE)->value);
}


void pushdblsym(struct command *cmd) 
{
  /* push double symbol onto stack */
  struct stackentry *p;
	
  p=push();
  p->value=*(double *)cmd->pointer;
  p->type=stNUMBER;
}


void create_popdblsym(char *symbol) /* create command 'popdblsym' */
{
  struct command *cmd;
  struct symbol *s;
	
  cmd=add_command(cPOPDBLSYM);
  if (symbol) {
    /* store specific information: */
    s=get_sym(symbol,syNUMBER,TRUE);
    cmd->pointer= &(s->value);
  }
  else {
    cmd->pointer=NULL;
    return;
  }
}


void popdblsym(struct command *cmd)   /* pop double from stack */
{
  double d;
	
  d=pop()->value;
  if (cmd->pointer==NULL) return;
  *(double *)(cmd->pointer)=d;
}


void create_dblbin(char c) /* create command for binary double operation */
{
  switch(c) {
  case '+':add_command(cDBLADD);break;
  case '-':add_command(cDBLMIN);break;
  case '*':add_command(cDBLMUL);break;
  case '/':add_command(cDBLDIV);break;
  case '^':add_command(cDBLPOW);break;
  }
  /* no specific information needed */
}


void dblbin(struct command *cmd) /* compute with two numbers from stack */
{
  struct stackentry *d;
  double a,b,c;
	
  b=pop()->value;
  a=pop()->value;
  d=push();
  switch(cmd->type) {
  case(cDBLADD):c=a+b; break;
  case(cDBLMIN):c=a-b; break;
  case(cDBLMUL):c=a*b; break;
  case(cDBLDIV): 
    if (fabs(b)<DBL_MIN) {
      sprintf(string,"Division by zero, set to %g",DBL_MAX);
      error(NOTE,string);
      c=DBL_MAX;}
    else
      c=a/b;
    break;
  case(cDBLPOW):
    if (b==2) 
      c=a*a;
    else if (a<0) {
      error(ERROR,"Power of negative value. Don't now what to do");
      return;}
    else
      c=exp(b*log(a));
    break;
  }
  d->value=c;
  d->type=stNUMBER;
}


void negate() /* negates top of stack */
{
  struct stackentry *a,*b;
  double d;
	
  a=pop();
  d=a->value;
  b=push();
  b->type=stNUMBER;
  b->value= -d;
}


void create_pushstrptr(char *symbol) /* push string-pointer onto stack */
{
  struct command *cmd;
	
  cmd=add_command(cPUSHSTRPTR);
  cmd->pointer=&get_sym(symbol,sySTRING,TRUE)->pointer;
}


void pushstrptr(struct command *cmd)  /* push string-pointer onto stack */
{
  struct stackentry *p;
	
  p=push();
  p->pointer=*(char **)cmd->pointer;
  p->type=stSTRING;
}


void create_pushstrsym(char *symbol) /* push string-symbol onto stack */
{
  struct command *cmd;
	
  cmd=add_command(cPUSHSTRSYM);
  /* get room to store specific information */
  cmd->pointer=&get_sym(symbol,sySTRING,TRUE)->pointer;
}


void pushstrsym(struct command *cmd)  /* push string-symbol onto stack */
{
  struct stackentry *p;
	
  p=push();
  p->pointer=my_strdup(*(char **)cmd->pointer);
  p->type=stSTRING;
}


void create_popstrsym(char *symbol) /* create command 'popstrsym' */
{
  struct command *cmd;
  struct symbol *s;
	
  cmd=add_command(cPOPSTRSYM);
  if (symbol) {
    /* storing specific information: */
    s=get_sym(symbol,sySTRING,TRUE);
    cmd->pointer=(char **)&(s->pointer);
  }
  else {
    cmd->pointer=NULL;
  }
}


void popstrsym(struct command *cmd) /* pop string from stack */
{
  struct stackentry *p;
	
  p=pop();
  if (cmd->pointer==NULL) return;
  if (*(char **)cmd->pointer!=NULL) free(*(char **)cmd->pointer);
  *(char **)cmd->pointer=my_strdup(p->pointer);
}


void create_token(int delimiter) /* create command 'token' */
{
  struct command *cmd;
	
  cmd=add_command(cTOKEN);
  cmd->args=delimiter;
}


void token(struct command *cmd) /* extract token from variable */
{
  char *del; /* delimiter for strings */
  struct stackentry *t;
  char *old,*new,*tok;
  
  if (cmd->args) del=pop()->pointer;
  else del=" \t";
  
  t=pop();
  old=t->pointer;
  t->pointer=NULL; /* prevent push from freeing the memory */
  t=push();
  t->type=stSTRING;
  new=old;
  tok=NULL;
  while(*new) {
    if (!tok && !strchr(del,*new)) tok=new; /* found start of token */
    if (tok && strchr(del,*new)) break; /* found end of token */
    new++;
  }
  if (*new) {
    *new='\0'; /* terminate token */
    new++;
    while(*new) {
      if (!strchr(del,*new)) break; /* found start of next token */
      new++;
    }
  }
  t->pointer=my_strdup(tok?tok:""); /* copy token */
  /* move rest of string */
  do {
    *old=*new;
    old++;
    new++;
  } while(*new);
  *old='\0';
}


void concat() /* concetenates two strings from stack */
{
  struct stackentry *a,*b,*c;
  char *aa,*bb,*cc;
	
  a=pop();
  b=pop();
  if (a->type!=stSTRING || b->type!=stSTRING) {
    error(FATAL,"Need strings to concat");
    return;
  }
  aa=a->pointer;
  bb=b->pointer;
  cc=(char *) my_malloc(sizeof(char)*(strlen(aa)+strlen(bb)+1));
  strcpy(cc,bb);
  strcat(cc,aa);
  c=push();
  c->type=stSTRING;
  c->pointer=cc;
}  


void create_pushstr(char *s) /* creates command pushstr */
{
  struct command *cmd;
	
  cmd=add_command(cPUSHSTR);
  cmd->pointer=my_strdup(s); /* store string */
}


void pushstr(struct command *cmd) 
{
  /* push string onto stack */
  struct stackentry *p;
	
  p=push();
  p->pointer=my_strdup((char *)cmd->pointer);
  p->type=stSTRING;
}


void create_goto(char *label) /* creates command goto */
{
  struct command *cmd;
	
  cmd=add_command(cGOTO);
  /* specific info */
  cmd->pointer=my_strdup(label);
}


void create_gosub(char *label) /* creates command gosub */
{
  struct command *cmd;
	
  cmd=add_command(cGOSUB);
  /* specific info */
  cmd->pointer=my_strdup(label);
}


void jump(struct command *cmd) 
     /* jump to specific Label; used as goto or gosub */
{
  struct command *curr;
  struct stackentry *ret;
  int type;
	
  type=cmd->type;
  if (type==cQGOSUB || type==cGOSUB) {
    ret=push();
    ret->pointer=current;
    ret->type=stRETADD;
  }
  if (type==cQGOSUB || type==cQGOTO) {
    current=(struct command *)cmd->pointer;
    return;
  }
  curr=cmdroot;
  while(curr!=cmdhead) {   /* go through all commands */
    if (curr->type==cLABEL && !strcmp(curr->pointer,cmd->pointer)) {
      /* found right Label ! */
      current=curr; /* jump to new location */
      /* use the address instead of the name next time ! */
      cmd->pointer=curr;
      cmd->type=(type==cGOTO) ? cQGOTO:cQGOSUB; /* quick jump from now on */
      return;
    }
    curr=curr->next;
  }
  /* label not found */
  sprintf(string,"Can't find label '%s'",(char *)cmd->pointer);
  error(ERROR,string);
}

void myreturn() /* return from gosub */
{
  struct stackentry *address;
	
  address=pop();
  if (address->type!=stRETADD) {
    error(ERROR,"RETURN without GOSUB");
    return;
  }
  current=(struct command *)address->pointer;
  return;
}


void create_label(char *label) /* creates command label */
{
  struct command *cmd,*curr;
	
  /* check, if label is duplicate */
  curr=cmdroot;
  while(curr!=cmdhead) {   /* go through all commands */
    if (curr->type==cLABEL && !strcmp(curr->pointer,label)) {
      /* found duplicate Label ! */
      sprintf(string,"duplicate label '%s'",(char *)curr->pointer);
      error(ERROR,string);
      return;
    }
    curr=curr->next;
  }
	
  cmd=add_command(cLABEL);
  /* store label */
  cmd->pointer=my_strdup(label);
}


void skipper()
     /* used for on_goto/gosub, skip specified number of commands */
{
  int i,len;
  struct command *ahead; /* command to follow */
	
  len=(int)pop()->value;
  i=1;
  current=current->next; /* advance to first goto/gosub */
  for(i=1;i<len;i++) {
    ahead=current->next->next; /* skip interleaving findnop statement */
    if (ahead->type==cNOP) 
      break;
    else
      current=ahead;
  }
}


void skiponce(struct command *cmd) /* skip next command exectly once */
{
  if (cmd->tag) current=current->next;
  cmd->tag=0;
}


void resetskiponce(struct command *cmd) /* find and reset next skip */
{
  struct command *c;
  
  c=cmd;
  while(c->type!=cSKIPONCE) c=c->next;
  c->tag=1;
}


void findnop()
     /* used for on_gosub, find trailing nop command */
{
  while(current->type!=cNOP) {
    current=current->next; /* next label */
  }
}


void create_print(char type) /* create command 'print' */
{
  struct command *cmd;
	
  cmd=add_command(cPRINT);
  cmd->pointer=my_malloc(sizeof(int));
  /* store type of print  */
  cmd->tag=type;
}


void print(struct command *cmd) /* print on screen */
{
  int type;
  struct stackentry *p,*q;
  static int last='n';
  char *s;
#ifdef UNIX
  int x,y;
#endif

  type=cmd->tag;
  switch(type) {
  case 'n':  /* print newline */
    if (curinized && coutstr==stdout) {
#ifdef WINDOWS
      printf("\n");
      break;
#else
      getyx(stdscr,y,x);
      if (y>=LINES-1) {
	scrl(1);
	y=y-1;
      }
      move(y+1,0);
      refresh();
      break;
#endif
    } else {
      string[0]='\n';
      string[1]='\0';
    }
    onestring(string);
    break;
  case 'd':  /* print double value */
    p=pop();
    sprintf(string,"%s%g",(last=='d')?" ":"",p->value);
    onestring(string);
    break;
  case 'u':
    p=pop();
    q=pop();
    type='d';
    s=string;
    if (last=='d') {
      *s=' ';
      s++;
    }
    if (!myformat(s,q->value,p->pointer)) {
      sprintf(string,"'%s' is not a valid format",(char *)p->pointer);
      error(ERROR,string);
      break;
    }
    onestring(string);
    break;
  case 's': 
    p=pop();
    onestring((char *)p->pointer);
    break;
  }
  last=type;
}


void mymove() /* move to specific position on screen */
{
  int x,y;
#ifdef WINDOWS
  COORD coord;
#endif
	
  y=(int)pop()->value;
  if (y<0) y=0;
  if (y>LINES-1) y=LINES-1;
  x=(int)pop()->value;
  if (x<0) x=0;
  if (x>COLS-1) x=COLS-1;
  if (!curinized) {
    error(ERROR,"need to call 'clear screen' first");
    return;
  }
#ifdef UNIX
  move(y,x);
  refresh();
#else
  coord.X=x;
  coord.Y=y;
  SetConsoleCursorPosition(ConsoleOutput,coord);
#endif
}


void clearscreen() /* clear entire screen */
{
#ifdef WINDOWS
  DWORD written; /* number of chars actually written */
  COORD coord; /* coordinates to start writing */
#endif
	
  if (!curinized) curinit();
#ifdef UNIX
  clear();
  refresh();
#else
  coord.X=0;
  coord.Y=0;
  FillConsoleOutputCharacter(ConsoleOutput,' ',LINES*COLS,
			     coord,&written);
  FillConsoleOutputAttribute(ConsoleOutput,
			     FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,LINES*COLS,
			     coord,&written);
  SetConsoleCursorPosition(ConsoleOutput,coord);
#endif
}


void curinit() /* initialize curses */
{
#ifdef WINDOWS
  CONSOLE_SCREEN_BUFFER_INFO coninfo; /* receives console size */
#endif
	
#ifdef UNIX
  initscr();
  setscrreg(0,LINES);
  scrollok(stdscr,TRUE);
  def_prog_mode();
  keypad(stdscr,TRUE);
#else
  GetConsoleScreenBufferInfo(ConsoleOutput,&coninfo);
  COLS=coninfo.dwSize.X;
  LINES=coninfo.dwSize.Y;
#endif
  curinized=TRUE;
}


char *replace(char *string) /* replace \n,\a, etc. */
{
  char *from,*to;
	
  from=to=string;
  while(*from) {
    if (*from=='\\') {
      from++;
      switch(*from) {
      case 'n':	*to='\n';break;
      case 't':	*to='\t';break;
      case 'v':	*to='\v';break;
      case 'b':	*to='\b';break;
      case 'r':	*to='\r';break;
      case 'f':	*to='\f';break;
      case 'a':	*to='\a';break;
      case '\\': *to='\\';break;
      case '\?': *to='\?';break;
      case '\'': *to='\'';break;
      case '\"': *to='\"';break;
      default:
	*to='\\';
	to++;
	*to=*from;
      }
    }
    else
      *to=*from;
    from++;
    to++;
  }
  *to='\0';
  return string;
}


void create_myopen(double stream,int num) /* create command 'myopen' */
{
  struct command *cmd;
	
  if (badstream((int)stream)) return;
  cmd=add_command(cOPEN);
  cmd->args=(int) stream;
  cmd->tag=num;
}


void myopen(struct command *cmd) /* open specified file for given name */
{
  FILE *handle;
  int stream;
  char *name;
  char *mode;
  char **pmode;
  static char *valid_modes[]={"r","w","a","rb","wb","ab",""};

	
  if (cmd->tag==3)
    mode=pop()->pointer;
  else 
    mode="a";
  name=pop()->pointer;
  stream=cmd->args;
  if (streams[stream]!=NULL) {
    error(ERROR,"Stream already in use");
    return;
  }
  for(pmode=valid_modes;**pmode;pmode++) if (!strcmp(*pmode,mode)) break;
  if (!**pmode) {
    sprintf(string,"\'%s\' is not a valid filemode",mode);
    error(ERROR,string);
    return;
  }
	
  handle=fopen(name,mode);
  if (handle==NULL) {
    sprintf(string,"Could not open '%s'",name);
    error(ERROR,string);
    return;
  }
  streams[stream]=handle;
}


void create_myclose(double stream) /* create command 'myclose' */
{
  struct command *cmd;
	
  if (badstream((int)stream)) return;
  cmd=add_command(cCLOSE);
  cmd->args=(int) stream;
  return;
}


void myclose(struct command *cmd) /* close the specified stream */
{
  int s;
	
  s=cmd->args;
  if (streams[s]==NULL) {
    sprintf(string,"Stream %d already closed",s);
    error(WARNING,string);
    return;
  }
  fclose(streams[s]);
  streams[s]=NULL;
}


void create_myswitch(int stream) /* create command myswitch */
{
  struct command *cmd;
	
  if (stream!=0 && badstream((int)stream)) return;
  cmd=add_command(cSWITCH);
  cmd->args=stream;
}


void myswitch(struct command *cmd) /* switch to specified stream */
{
  int stream;
	
  stream=cmd->args;
  if (stream==0) {
    cinstr=stdin;
    coutstr=stdout;
  }
  else  {
    cinstr=streams[stream]; /* switch to stream */
    coutstr=cinstr;
    if (streams[stream]==NULL) {
      sprintf(string,"Stream %d not opened",stream);
      error(ERROR,string);
      return;
    } 
  }
  return;
}


void create_testeof(double stream) /* create command 'testeof' */
{
  struct command *cmd;
	
  if (badstream((int)stream)) return;
  cmd=add_command(cTESTEOF);
  cmd->args=(int) stream;
  return;
}


void testeof(struct command *cmd) /* close the specified stream */
{
  int s,c;
  struct stackentry *result;
	
  s=cmd->args;
  result=push();
  result->type=stNUMBER;
  if (streams[s]==NULL) {
    result->value=TRUE;
    return;
  }
  c=getc(streams[s]);
  if (c==EOF) {
    result->value=TRUE;
    return;
  }
	
  result->value=FALSE;
  ungetc(c,streams[s]);
  return;
}


int badstream(int stream) /* test for valid stream id */
{
  int max;
	
  max=(FOPEN_MAX-3<9)?FOPEN_MAX-3:9;
  if (stream>max || stream<1) {
    sprintf(string,"Can handle only streams from 1 to %d",max);
    error(ERROR,string);
    return TRUE;
  }
  return FALSE;
}


void create_myread(char type,int rl) /* create command 'read' */
{
  struct command *cmd;
	
  cmd=add_command(cREAD);
  cmd->args=rl; /* true, if read should go til eol */
  cmd->tag=type; /* can be 'd' or 's' */
}


void myread(struct command *cmd) /* read string or double */
{
  double d;
  char buffer[INBUFFLEN]; /* buffer with current input */
  int numread; /* number of bytes read */
  int tileol; /* true, if read should go til end of line */
  struct stackentry *s;
  int currch; /* current character */
	
  numread=0; /* no chars read'til now */
  buffer[0]='\0';
  tileol=cmd->args;
	
  /* skip leading whitespace */
  if (!tileol) {
    do {
      currch=onechar();
    } while(currch==' ' || currch=='\t');
    /* put back last char */
    if (currch!=EOF && currch!='\0') backchar(currch);
    if (currch=='\0' || currch==EOF) goto done;
  }      
	
  /* read chars */
  do {
    currch=onechar();
    buffer[numread]=currch;
    numread++;
  } while(((tileol && currch!='\0') ||
	   (!tileol && currch!=' ' &&
	    currch!='\t' && currch!='\0')) &&
	  currch!=EOF && numread<INBUFFLEN);
	
  /* put back last char */
  if (currch!=EOF && currch!='\0') backchar(currch);
  /* and remove it from buff */
  if (currch!=EOF) numread--;
  buffer[numread]='\0';
  if (currch=='\0' || currch==EOF) goto done;
	
  /* skip trailing whitespace */
  if (!tileol) {
    do {
      currch=onechar();
    } while(currch==' ' || currch=='\t');
    if (currch!=EOF && currch!='\0') backchar(currch);
  }
	
 done:
  if (cmd->tag=='s') { /* read string */
    s=push();
    s->type=stSTRING;
    s->pointer=my_strdup(buffer);}
  else { /* read double */
    s=push();
    s->type=stNUMBER;
    s->value=0.0;
    if (buffer[0] && (sscanf(buffer,"%lf",&d)==1)) s->value=d;
  }
}


void readline(void) /* read one line from current stream */
{  
#ifdef UNIX
  char *nl; /* position of newline */
  int x,y;
#endif
	
  memset(linebuffer,'\0',INBUFFLEN);
#ifdef UNIX
  if (curinized && cinstr==stdin) {
    getyx(stdscr,y,x);
#ifdef HAVE_GETNSTR
    getnstr(linebuffer,INBUFFLEN);
#else
    getstr(linebuffer);
#endif
    if ((nl=strchr(linebuffer,'\0'))) *nl='\n';
    if (y>=LINES-1) scrl(1);
    refresh();
  }
  else 
#endif
    {
      fgets(linebuffer,INBUFFLEN,cinstr);
    }
  currchar=linebuffer;
  prompted=FALSE;
}


int onechar() /* read one char from cinstr */
{
  int ch;
	
  if (cinstr==stdin) {
    if (!currchar || !*currchar) {
      readline();
    }
    currchar++;
    ch=*(currchar-1);
  }
  else
    ch=fgetc(cinstr);
	
  if (ch=='\n' || ch==EOF)
    return '\0';
  else
    return ch;
}


void backchar(int ch) /* put char back into stream */
{
  if (cinstr==stdin) {
    if (currchar>linebuffer) currchar--;
  }
  else {
    ungetc(ch,cinstr);
  }
}


void chkprompt() /* print an intermediate prompt if necessary */
{
  if (cinstr==stdin && (!currchar || !*currchar) && !prompted) onestring("?");
}


void create_onestring(char *str) /* create command 'onestring' */
{
  struct command *cmd;
	
  cmd=add_command(cONESTRING);
  cmd->pointer=my_strdup(str);
}


void onestring(char *string) /* write string to file */
{
#ifdef UNIX
  if (curinized && coutstr==stdout) {
    addstr(string);
    refresh();
  }
#else
  DWORD len,written;
	
  if (curinized && coutstr==stdout) {
    len=strlen(string);
    WriteConsole(ConsoleOutput,string,len,&written,NULL);
  }	
#endif
  else
    {
      fprintf(coutstr,"%s",string);
      fflush(coutstr);
    }
  prompted=TRUE;
}


void create_revert(int flag) /* create command 'reverse' */
{
  struct command *c;
	
  c=add_command(cREVERT);
  c->args=flag;
}


void revert(struct command *cmd) /* switch reverse-printing */
{
  static int reverse=FALSE;
	
  if (((cmd->args)?TRUE:FALSE)==reverse) return;
  if (cmd->args) {
    if (!curinized) {
      error(ERROR,"need to call 'clear screen' first");
      return;
    }
#ifdef UNIX
    attron(A_REVERSE);
#else
    SetConsoleTextAttribute(ConsoleOutput,BACKGROUND_RED | 
			    BACKGROUND_GREEN | BACKGROUND_BLUE);
#endif
    reverse=TRUE;
  }
  else {
#ifdef UNIX
    attroff(A_REVERSE);
#else
    SetConsoleTextAttribute(ConsoleOutput,FOREGROUND_RED | 
			    FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
    reverse=FALSE;
  }
}


void create_restore(char *label) /* create command 'restore' */
{
  struct command *c;
	
  c=add_command(cRESTORE);
  c->pointer=my_strdup(label);
}


void restore(struct command *cmd) /* reset data pointer to given label */
{
  struct command *curr;
	
  if (cmd->type==cRESTORE) { /* first time; got to search the label */
    if (*((char *)cmd->pointer)=='\0') {
      cmd->pointer=cmdroot;
      cmd->type=cQRESTORE;
      goto found; /* restore to first command */
    }
    curr=cmdroot;
    while(curr!=cmdhead) {   /* go through all commands */
      if (curr->type==cLABEL && !strcmp(curr->pointer,cmd->pointer)) {
				/* found right Label ! */
				/* use the address instead of the name next time ! */
	cmd->pointer=curr;
	cmd->type=cQRESTORE;
	goto found;
      }
      curr=curr->next;
    }
    /* did not found label */
    sprintf(string,"couldn't found label '%s'",(char *)cmd->pointer);
    error(ERROR,string);
    return;
  }
 found:
  datapointer=cmd->pointer;
  return;
}


void create_dbldata(double value)  /* create command dbldata */
{
  struct command *c;
	
  c=add_command(cDATA);
  c->pointer=my_malloc(sizeof(double));
  *((double *)c->pointer)=value;
  c->tag='d'; /* double value */
}


void create_strdata(char *value)  /* create command strdata */
{
  struct command *c;
	
  c=add_command(cDATA);
  c->pointer=my_strdup(value);
  c->tag='s'; /* string value */
}


void create_readdata(char type) /* create command readdata */
{
  struct command *cmd;
	
  cmd=add_command(cREADDATA);
  cmd->tag=type;
}


void readdata(struct command *cmd) /* read data items */
{
  struct stackentry *read;
  char type;
	
  type=cmd->tag;
  while(datapointer->type!=cDATA) {
    if (datapointer==cmdhead) {
      error(ERROR,"Run out of data items");
      return;
    }
    datapointer=datapointer->next;
  }
  if (type!=datapointer->tag) {
    error(ERROR,"Type of READ and DATA don't match");
    return;
  }
  read=push();
  if (type=='d') { /* read a double value */
    read->type=stNUMBER;
    read->value= *((double *)datapointer->pointer);}
  else {
    read->type=stSTRING;
    read->pointer=my_strdup(datapointer->pointer);
  }
  datapointer=datapointer->next; /* next item */
}


void create_dblrelop(char c) /* create command dblrelop */ 
{
  int type;
	
  switch(c) {
  case '=': type=cEQ;break;
  case '!': type=cNE;break;
  case '<': type=cLT;break;
  case '{': type=cLE;break;
  case '>': type=cGT;break;
  case '}': type=cGE;break;
  }
  add_command(type);
}


void dblrelop(struct command *type)  /* compare topmost double-values */
{
  double a,b,c;
  struct stackentry *result;
	
  b=pop()->value;
  a=pop()->value;
  switch(current->type) {
  case cEQ:c=(a==b);break;
  case cNE:c=(a!=b);break;
  case cLE:c=(a<=b);break;
  case cLT:c=(a<b);break;
  case cGE:c=(a>=b);break;
  case cGT:c=(a>b);break;
  }
  result=push();
  result->value=c;
  result->type=stNUMBER;
}    


void create_strrelop(char c) /* create command strrelop */ 
{
  int type;
	
  switch(c) {
  case '=': type=cSTREQ;break;
  case '!': type=cSTRNE;break;
  case '<': type=cSTRLT;break;
  case '{': type=cSTRLE;break;
  case '>': type=cSTRGT;break;
  case '}': type=cSTRGE;break;
  }
  add_command(type);
}


void strrelop(struct command *type)  /* compare topmost string-values */
{
  char *a,*b;
  double c;
  struct stackentry *result;
	
  b=pop()->pointer;
  a=pop()->pointer;
  switch(current->type) {
  case cSTREQ:c=(strcmp(a,b)==0);break;
  case cSTRNE:c=(strcmp(a,b)!=0);break;
  case cSTRLT:c=(strcmp(a,b)<0);break;
  case cSTRLE:c=(strcmp(a,b)<=0);break;
  case cSTRGT:c=(strcmp(a,b)>0);break;
  case cSTRGE:c=(strcmp(a,b)>=0);break;
  }
  result=push();
  result->value=c;
  result->type=stNUMBER;
}    


void create_boole(char c) /* create command boole */ 
{
  int type;
	
  switch(c) {
  case '|': type=cOR;break;
  case '&': type=cAND;break;
  case '!': type=cNOT;break;
  }
  add_command(type);
}


void boole(struct command *type)  /* perform and/or/not */
{
  int a,b,c;
  struct stackentry *result;
	
  a=(int)pop()->value;
  if (current->type==cNOT) 
    c=!a;
  else {
    b=(int)pop()->value;
    if (current->type==cAND)
      c=a&&b;
    else
      c=a||b;
  }
  result=push();
  result->value=c;
  result->type=stNUMBER;
}    


void decide() /*  skips next command, if not 0 on stack */
{
  struct stackentry *a;
	
  a=pop();
  if (a->value!=0) current=current->next; /* skip one command */
}


void create_doarray(char *symbol,int command) /* creates array-commands */ 
{
  struct command *cmd;
  struct symbol *a;
  struct array *ar;
  int dimcount;
	
  a=get_sym(symbol,syARRAY,FALSE);
  if (a==NULL) {
    sprintf(string,"array '%s' has not been dimed",symbol);
    error(ERROR,string);
    return;
  }
	
  dimcount=(int)pop()->value;
  ar=a->pointer;
  if (dimcount!=ar->dimension) {
    sprintf(string,"improper array dimension %d for '%s'",dimcount,symbol);
    error(ERROR,string);
    return;
  }
	
  cmd=add_command(cDOARRAY);
	
  switch(command) {
  case CALLARRAY:
    cmd->args=CALLARRAY;
    break;
  case ASSIGNARRAY:
    cmd->args=ASSIGNARRAY;
    break;
  case CALLSTRINGARRAY:
    cmd->args=CALLSTRINGARRAY;
    break;
  case ASSIGNSTRINGARRAY:
    cmd->args=ASSIGNSTRINGARRAY;
    break;
  case GETSTRINGPOINTER:
    cmd->args=GETSTRINGPOINTER;
    break;
  }
	
  cmd->pointer=ar;
  cmd->args=command;
	
  return;
}


void doarray(struct command *current) /* call an array */
{
  struct array *ar;
  struct stackentry *stack;
  void *p;
  char **str;
  double *dbl;
  int i,j,bnd,index,call;
	
  call=(current->args==CALLARRAY || 
	current->args==CALLSTRINGARRAY ||
	current->args==GETSTRINGPOINTER);
  if (!call) stack=pop();
	
  ar=(struct array *)current->pointer;
  index=0;
  for(i=0;i<ar->dimension;i++) {
    bnd=(ar->bounds[i]);
    index*=bnd;
    j=(int)pop()->value;
    if (j<0 || j>=bnd) {
      sprintf(string,"index %d (=%d) out of range",ar->dimension-i,j);
      error(ERROR,string);
      return;
    }
    index+=j;
  }
	
  if (call) stack=push();
	
  p=ar->pointer;
  switch(current->args) {
  case CALLARRAY:
    dbl=(double *)p+index;
    stack->value= *dbl;
    stack->type=stNUMBER;
    break;
  case ASSIGNARRAY:
    dbl=(double *)p+index;
    *dbl=stack->value;
    break;
  case CALLSTRINGARRAY:
    str=((char **)p+index);
    stack->pointer=my_strdup(*str);
    stack->type=stSTRING;
    break;
  case ASSIGNSTRINGARRAY:
    str=((char **)p+index);
    if (*str!=NULL) free(*str);
    *str=my_strdup(stack->pointer);
    break;
  case GETSTRINGPOINTER:
    str=((char **)p+index);
    stack->pointer=*str;
    stack->type=stSTRING;
    break;
  }
}


void create_changestring(int type) /* create command 'changestring' */
{
  struct command *cmd;
	
  cmd=add_command(cCHANGESTRING);
  cmd->args=type;
}


void changestring(struct command *current) /* changes a string */
{
  int type,a2,a3;
  char *newpart;
  char *oldstring;
  int i,len;
  struct stackentry *a1;
	
  type=current->args;
  newpart=pop()->pointer;
  if (type>fTWOARGS) a3=(int)pop()->value;
  if (type>fONEARGS) a2=(int)pop()->value;
  a1=pop();
  oldstring=a1->pointer; 
  a1->pointer=NULL; /* this prevents push from freeing the memory */
	
  switch(type) {
  case fMID:
    for(i=1;i<a2+a3;i++) {
      if (!oldstring[i-1]) break;
      if (i>=a2) {
	if (!newpart[i-a2]) break;
	oldstring[i-1]=newpart[i-a2];
      }
    }
    break;
  case fLEFT:
    for(i=1;i<=a2;i++) {
      if (!oldstring[i-1] || !newpart[i-1]) break;
      oldstring[i-1]=newpart[i-1];
    }
    break;
  case fRIGHT:
    len=strlen(oldstring);
    for(i=1;i<=len;i++) {
      if (i>len-a2) {
	if (!newpart[i-1-len+a2]) break;
	oldstring[i-1]=newpart[i-1-len+a2];
      }
    }
    break;
  }
}


void create_function(int type) /* create command 'function' */
     /* type can be sin,cos,mid$ ... */
{
  struct command *cmd;
	
  cmd=add_command(cFUNCTION);
  cmd->args=type;  
}


void function(struct command *current) /* performs a function */
{
  struct stackentry *stack,*a1,*a2,*a3;
  char *pointer;
  double value;
  time_t datetime;
  int type,result,len,start,i,max;
  char *str,*str2;
	
  type=current->args;
  if (type>fTWOARGS) a3=pop();
  if (type>fONEARGS) a2=pop();
  if (type>fZEROARGS) a1=pop();
	
  switch (type) {
  case fSIN:
    value=sin(a1->value);
    result=stNUMBER;
    break;
  case fASIN:
    value=asin(a1->value);
    type=stNUMBER;
    break;
  case fCOS:
    value=cos(a1->value);
    result=stNUMBER;
    break;
  case fACOS:
    value=acos(a1->value);
    result=stNUMBER;
    break;
  case fTAN:
    value=tan(a1->value);
    result=stNUMBER;
    break;
  case fATAN:
    value=atan(a1->value);
    result=stNUMBER;
    break;
  case fEXP:
    value=exp(a1->value);
    result=stNUMBER;
    break;
  case fLOG:
    value=log(a1->value);
    result=stNUMBER;
    break;
  case fXMAP:
    value=a1->value*xinc+xoff;
    result=stNUMBER;
    break;
  case fYMAP:
    value=a1->value*yinc+yoff;
    result=stNUMBER;
    break;
  case fLEN:
    value=(double) strlen(a1->pointer);
    result=stNUMBER;
    break;
  case fSTR:
    sprintf(string,"%g",a1->value);
    pointer=my_strdup(string);
    result=stSTRING;
    break;
  case fSTR2:
    result=stSTRING;
    if (!myformat(string,a1->value,a2->pointer)) {
      pointer=my_strdup("");
      sprintf(string,"'%s' is not a valid format",(char *)a2->pointer);
      error(ERROR,string);
      break;
    }
    pointer=my_strdup(string);
    break;
  case fSQRT:
    value=sqrt(a1->value);
    result=stNUMBER;
    break;
  case fSQR:
    value=exp(log(a1->value)/2);
    result=stNUMBER;
    break;
  case fINT:
    value=(int) a1->value;
    result=stNUMBER;
    break;
  case fFRAC:
    value=a1->value-(int)a1->value;
    result=stNUMBER;
    break;
  case fABS:
    value=fabs(a1->value);
    result=stNUMBER;
    break;
  case fSIG:
    if (a1->value<0) value=-1.;
    else if (a1->value>0) value=1.;
    else value=0.;
    result=stNUMBER;
    break;
  case fMOD:
    value=a1->value-a2->value*(int)(a1->value/a2->value);
    result=stNUMBER;
    break;
  case fRAN:
    value=a1->value*(float)rand()/RAND_MAX;
    result=stNUMBER;
    break;
  case fRAN2:
    value=(float)rand()/RAND_MAX;
    result=stNUMBER;
    break;
  case fMIN:
    if (a1->value>a2->value)
      value=a2->value;
    else
      value=a1->value;
    result=stNUMBER;
    break;
  case fMAX:
    if (a1->value>a2->value)
      value=a1->value;
    else
      value=a2->value;
    result=stNUMBER;
    break;
  case fVAL:
    i=sscanf((char *) a1->pointer,"%lf",&value);
    if (i!=1) value=0;
    result=stNUMBER;
    break;
  case fATAN2:
    value=atan2(a1->value,a2->value);
    result=stNUMBER;
    break;
  case fLEFT:
    str=a1->pointer;
    len=(int)a2->value;
    pointer=fromto(str,0,len-1);
    result=stSTRING;
    break;
  case fRIGHT:
    str=a1->pointer;
    max=strlen(str);
    len=(int)a2->value;
    pointer=fromto(str,max-len,max-1);
    result=stSTRING;
    break;
  case fMID:
    str=a1->pointer;
    start=(int)a2->value;
    len=(int)a3->value;
    pointer=fromto(str,start-1,start+len-2);
    result=stSTRING;
    break;
  case fINKEY:
    pointer=inkey(a1->value);
    result=stSTRING;
    break;
  case fCHR:
    pointer=my_malloc(2);
    i=(int)floor(a1->value);
    if (i>255 || i<0) {
      sprintf(string,"can´t convert %g to character",a1->value);
      error(ERROR,string);
      return;
    }
    pointer[1]='\0';
    pointer[0]=(unsigned char)i;
    result=stSTRING;
    break;
  case fASC:
    value=((unsigned char *)a1->pointer)[0];
    result=stNUMBER;
    break;
  case fUPPER:
    str=a1->pointer;
    pointer=my_malloc(strlen(str)+1);
    i=-1;
    do {
      i++;
      pointer[i]=toupper((int)str[i]);
    } while(pointer[i]);
    result=stSTRING;
    break;
  case fLOWER:
    str=a1->pointer;
    pointer=my_malloc(strlen(str)+1);
    i=-1;
    do {
      i++;
      pointer[i]=tolower((int)str[i]);
    } while(pointer[i]);
    result=stSTRING;
    break;
  case fLTRIM:
    str=a1->pointer;
    while(isspace(*str)) str++;
    pointer=my_strdup(str);
    result=stSTRING;
    break;
  case fRTRIM:
    str=a1->pointer;
    i=strlen(str)-1;
    while(isspace(str[i]) && i>=0) i--;
    str[i+1]='\0';
    pointer=my_strdup(str);
    result=stSTRING;
    break;
  case fTRIM:
    str=a1->pointer;
    i=strlen(str)-1;
    while(isspace(str[i]) && i>=0) i--;
    str[i+1]='\0';
    while(isspace(*str)) str++;
    pointer=my_strdup(str);
    result=stSTRING;
    break;
  case fINSTR:
    str=a1->pointer;
    str2=a2->pointer;
    pointer=strstr(str,str2);
    if (pointer==NULL) 
      value=0;
    else
      value=pointer-str+1;
    result=stNUMBER;
    break;   
  case fDATE:
    pointer=my_malloc(100);
    time(&datetime);
    strftime(pointer,100,"%w-%m-%d-%Y-%a-%b",localtime(&datetime));
    result=stSTRING;
    break;
  case fTIME:
    pointer=my_malloc(100);
    time(&datetime);
    strftime(pointer,100,"%H-%M-%S",localtime(&datetime));
    sprintf(pointer+strlen(pointer),"-%d",
	    (int)difftime(time(NULL),compilation_start));
    result=stSTRING;
    break;
  case fSYSTEM:
    str=a1->pointer;
    pointer=do_system(str);
    result=stSTRING;
    break;
  case fSYSTEM2:
    str=a1->pointer;
    value=do_system2(str);
    result=stNUMBER;
    break;
  case fPEEK:
    str=a1->pointer;
    value=peek(str);
    result=stNUMBER;
    break;
  case fPEEK2:
    str=a1->pointer;
    pointer=peek2(str);
    result=stSTRING;
    break;
  default:
    error(ERROR,"function called but not implemented");
    return;
  }
  
  stack=push();
  /* copy result */
  stack->type=result;
  if (result==stSTRING)
    stack->pointer=pointer;
  else
    stack->value=value;
}

int myformat(char *dest,double num,char *format) /* format number according to string */
{
  int i1,i2; /* dummy */
  char c1; /* dummy */
  static char ctrl[6];
  char *found,*form;
  int pre,post,dot,len,i,digit;
  int ip,neg=FALSE;
  double fp,round;
  static char *digits="0123456789";
  
  form=format;
  if (*form=='%') { /* c-style format */
    strcpy(ctrl,"+- #0"); /* allowed control chars for c-format */
    form++;
    while((found=strchr(ctrl,*form))!=NULL) {
      *found='?';
      form++;
    } 
    if (sscanf(form,"%u.%u%c%n",&i1,&i2,&c1,&i)!=3 &&
	sscanf(form,"%u.%c%n",&i2,&c1,&i)!=2 &&
	sscanf(form,".%u%c%n",&i2,&c1,&i)!=2 &&
	sscanf(form,"%u%c%n",&i2,&c1,&i)!=2) return FALSE;
    if (!strchr("feEgG",c1) || form[i]) return FALSE;
    /* seems okay, let's print */
    sprintf(dest,format,num);
  } else { /* basic-style format */
    if (num<0) {
      neg=TRUE;
      num=-num;
    }
    for(pre=0;*format=='#';pre++) format++;
    dot=*format;
    if (*format) {
      if (*format!='.') return FALSE;
      format++;
    }
    for(post=0;*format=='#';post++) format++;
    if (dot) *(dest+pre)=dot;
    len=pre+post+(dot?1:0);
    dest[len]='\0';
    round=0.5;
    for(i=0;i<post;i++) round/=10.;
    num+=round;
    ip=(int)num;
    fp=num-ip;
    for(i=pre-1;i>=0;i--) {
      if (ip) {
	digit=ip%10;
	ip/=10;
	dest[i]=digits[digit];
      } else {
	break;
      }
    }
    if ((neg && i<0) || ip) {
      for(i=0;i<len;i++) dest[i]='*';
      return TRUE;
    }
    if (neg) dest[i--]='-';
    for(;i>=0;i--) dest[i]=' ';
    for(i=pre+1;i<len;i++) {
      fp*=10;
      digit=(int)fp;
      fp-=digit;
      dest[i]=digits[digit];
    }
    return TRUE;
  }
  return TRUE;
}

void create_dim(char *name,char type) /* create command 'dim' */
     /* type can be 's'=string or 'd'=double Array */
{ 
  struct command *cmd;
  struct symbol *s;
  struct array *ar;
  int dimcount;
	
  dimcount=(int)pop()->value;
  cmd=add_command(cDIM);
  s=get_sym(name,syARRAY,FALSE); /* search for array */
  if (s!=NULL) {
    sprintf(string,"array '%s' has been dimed already",name);
    error(ERROR,string);
    return;
  }
  s=get_sym(name,syARRAY,TRUE); /* create array */
  ar=my_malloc(sizeof(struct array));
  cmd->pointer=ar;
  s->pointer=ar;
  ar->type=type;
  ar->dimed=FALSE;
  ar->dimension=dimcount;
  if (dimcount>10) {
    error(ERROR,"Dimension larger than 10");
    return;
  }
}


void dim(struct command *cmd) /* get room for array */
{
  struct array *ar;
  struct stackentry *s;
  char *nul,**str;
  double *dbl;
  int total,size,i;
	
  ar=(struct array *)cmd->pointer;
  if (ar->dimed) {
    error(ERROR,"Array has been dimed already");
    return;
  }
  total=1; /* count total amount of memory */
  for(i=0;i<ar->dimension;i++) {
    s=pop();
    size=(int) s->value;
    if (size<=0) {
      error(ERROR,"One bound is less or equal zero");
      return;
    }
    size++; /* allow for zero-index-element */
    (ar->bounds)[i]=size;
    total*=size;
  }
  ar->total=total;
  if (ar->type=='s')         /* it is a string array */
    ar->pointer=my_malloc(total*sizeof(char *));
  else
    ar->pointer=my_malloc(total*sizeof(double));
  if (ar->pointer==NULL) {
    error(ERROR,"Could not get enough memory for dim");
    return;
  }
  /* initialize Array */
  if (ar->type=='s') { 
    str=ar->pointer;
    for(i=0;i<total;i++) {
      nul=my_malloc(sizeof(char));
      *nul='\0';
      *(str+i)=nul;}}
  else {
    dbl=ar->pointer;
    for(i=0;i<total;i++) *(dbl+i)=0.0;
  }
  ar->dimed=TRUE;
}


char *fromto(char *str,int from,int to) /* gives back portion of string */
     /* from and to can be in the range 1...strlen(str) */
{
  int len,i;
  char *part;
	
  len=strlen(str);
  if (from>to || to<0 || from>len-1) {
    /* give back empty string */
    part=my_malloc(1);
    part[0]='\0';
  }
  else {
    if (from<=0) from=0;
    if (to>=len) to=len-1;
    part=my_malloc(sizeof(char)*(to-from+2)); /* characters and '/0' */
    for(i=from;i<=to;i++) part[i-from]=str[i]; /* copy */
    part[i-from]='\0';
  }
  return part;
}


char *inkey(double tmout) /* gets char from keyboard, blocks and doesn´t print */
{
  char keybuff[20];
  char *skey;
  int key; /* returned key */
  int ms; /* number of milliseconds to wait*/
#ifdef WINDOWS
  DWORD oflags; /* saves normal state of console input buffer */
  DWORD flags; /* new input mode for console input buffer */
  INPUT_RECORD inrec; /* for reading key-event */
  int ret,end,now,left,num;
#endif
  ms=(int)(tmout*1000);
  if (!curinized) {
#ifdef UNIX
    error(ERROR,"need to call 'clear screen' first");
    return my_strdup("");
#endif
  }
#ifdef UNIX
  noecho();
  cbreak();
  timeout(ms);
  do key=getch(); while(ms<0 && key==ERR);
  echo();
  nocbreak();
  skey=keybuff;
  switch(key) {
  case ERR: skey="";break;
  case KEY_UP: skey="up";break;
  case KEY_DOWN: skey="down";break;
  case KEY_LEFT: skey="left";break;
  case KEY_RIGHT: skey="right";break;
  case KEY_DC: skey="del";break;
  case KEY_IC: skey="ins";break;
  case KEY_IL: skey="ins";break;
  case KEY_CLEAR: skey="clear";break;
  case KEY_HOME: skey="home";break;
  case KEY_F0: skey="f0";break;
  case KEY_F(1): skey="f1";break;
  case KEY_F(2): skey="f2";break;
  case KEY_F(3): skey="f3";break;
  case KEY_F(4): skey="f4";break;
  case KEY_F(5): skey="f5";break;
  case KEY_F(6): skey="f6";break;
  case KEY_F(7): skey="f7";break;
  case KEY_F(8): skey="f8";break;
  case KEY_F(9): skey="f9";break;
  case KEY_F(10): skey="f10";break;
  case KEY_F(11): skey="f11";break;
  case KEY_F(12): skey="f12";break;
  case KEY_F(13): skey="f13";break;
  case KEY_F(14): skey="f14";break;
  case KEY_F(15): skey="f15";break;
  case KEY_F(16): skey="f16";break;
  case KEY_F(17): skey="f17";break;
  case KEY_F(18): skey="f18";break;
  case KEY_F(19): skey="f19";break;
  case KEY_F(20): skey="f20";break;
  case KEY_F(21): skey="f21";break;
  case KEY_F(22): skey="f22";break;
  case KEY_F(23): skey="f23";break;
  case KEY_F(24): skey="f24";break;
  case KEY_BACKSPACE: skey="backspace";break;
  case KEY_NPAGE: skey="scrndown";break;
  case KEY_PPAGE: skey="scrnup";break;
  case KEY_ENTER: skey="enter";break;
  default:
    if (isprint(key)) {
      keybuff[0]=key;
      keybuff[1]='\0';
    }
    else {
      switch(key) {
      case 0x1b:skey="esc";break;
      case 0x7f:skey="del";break;
      case 0xa:skey="enter";break;
      case 0x9:skey="tab";break;
      default:
	sprintf(keybuff,"key%x",key);
      }
    }
    break;
  }
#elif WINDOWS
  GetConsoleMode(ConsoleInput,&oflags);
  flags=oflags&~(ENABLE_LINE_INPUT|ENABLE_ECHO_INPUT);
  SetConsoleMode(ConsoleInput,flags);
  skey="";
  if (ms==0) {
    PeekConsoleInput(ConsoleInput,&inrec,1,&num);
    if (num==0) goto keydone;
    ReadConsoleInput(ConsoleInput,&inrec,1,&num);
    if (!is_valid_key(&inrec)) goto keydone;
  }
  else if (ms>0) {
    end=GetTickCount()+ms;
    do {	
      now=GetTickCount();
      left=end-now;
      if (left>0) {
	ret=WaitForSingleObject(ConsoleInput,left);
	if (ret==WAIT_OBJECT_0) ReadConsoleInput(ConsoleInput,&inrec,1,&num);
      }
    } while(left>0 && ret==WAIT_OBJECT_0 && !is_valid_key(&inrec));
    if (left<=0 || ret!=WAIT_OBJECT_0) goto keydone;
  }
  else { /* if (ms<0) */
    do {
      ReadConsoleInput(ConsoleInput,&inrec,1,&num);
    } while(!is_valid_key(&inrec));	
  }
  skey=keybuff;
  if (isprint(inrec.Event.KeyEvent.uChar.AsciiChar)) {
    keybuff[0]=inrec.Event.KeyEvent.uChar.AsciiChar;
    keybuff[1]='\0';
  }
  else {
    key=inrec.Event.KeyEvent.wVirtualKeyCode;
    switch(key) {
    case 0x1b: skey="esc";break;
    case 0x0d: skey="enter";break;
    case 0x09: skey="tab";break;
    case 0x21: skey="scrnup";break;
    case 0x22: skey="scrndown";break;
    case 0x70: skey="f1";break;
    case 0x71: skey="f2";break;
    case 0x72: skey="f3";break;
    case 0x73: skey="f4";break;
    case 0x74: skey="f5";break;
    case 0x75: skey="f6";break;
    case 0x76: skey="f7";break;
    case 0x77: skey="f8";break;
    case 0x78: skey="f9";break;
    case 0x79: skey="f10";break;
    case 0x7a: skey="f11";break;
    case 0x7b: skey="f12";break;
    case 0x24: skey="home";break;
    case 0x23: skey="end";break;
    case 0x2d: skey="ins";break;
    case 0x2e: skey="del";break;
    case 0x08: skey="backspace";break;
    case 0x27: skey="right";break;
    case 0x25: skey="left";break;
    case 0x28: skey="down";break;
    case 0x26: skey="up";break;
    default:
      sprintf(keybuff,"key%02x",key);
    }
  }
 keydone:
  SetConsoleMode(ConsoleInput,oflags);
#endif
  return my_strdup(skey);
}

#ifdef WINDOWS	
int is_valid_key(INPUT_RECORD *rec) /* check if input rec contains valid key */
{
  if (rec->EventType!=KEY_EVENT || 
      !rec->Event.KeyEvent.bKeyDown ||
      rec->Event.KeyEvent.wVirtualKeyCode==VK_SHIFT ||
      rec->Event.KeyEvent.wVirtualKeyCode==VK_CONTROL) {
    return FALSE;
  }
  return TRUE;
}
#endif		
		

void create_openwin(int fnt) /* create Command 'openwin' */
{
  struct command *cmd;
	
  cmd=add_command(cOPENWIN);
  cmd->args=fnt;
}


void openwin(struct command *cmd) /* open a Window */
{
  int fnt;
  static int first=TRUE; /* flag to decide if initialization is necessary */
#ifdef UNIX
  static XEvent event; /* what has happened ? */
  XSetWindowAttributes attrib; /* properties of window */
#endif
	
  if (winopened) {
    error(WARNING,"Window already open");
    return;
  }
	
  fnt=cmd->args;
  if (fnt) font=my_strdup(pop()->pointer);
	
  winheight=(int)pop()->value;
  if (winheight<1) {
    error(ERROR,"winheight less than 1 pixel");
    return;
  }
	
  winwidth=(int)pop()->value;
  if (winwidth<1) {
    error(ERROR,"winwidth less than 1 pixel");
    return;
  }
	
  /* initialize grafics */
  if (first && !grafinit()) return;
	
#ifdef UNIX
	
  /* create the window */
  /*  window=XCreateSimpleWindow(display,root,winx,winy,winwidth,winheight,
      0,0,b_colour); */

  attrib.backing_store=Always;
  attrib.save_under=TRUE;
  attrib.background_pixel=b_colour;
  window=XCreateWindow(display,root,winx,winy,winwidth,winheight,0,
		       CopyFromParent,CopyFromParent,CopyFromParent,
		       CWBackingStore|CWSaveUnder|CWBackPixel,
		       &attrib);

  if (window==None) {
    error(ERROR,"Could not create window");
    return;
  }

  /* put in name for the window */
  XStoreName(display,window,progname);
	
  /* set size hints */
  XSetWMNormalHints(display,window,&sizehints);
	
  /* display it */
  XMapWindow(display,window);
	
  /* wait for exposure */
  XSelectInput(display,window,0xffffff);
  XFlush(display);
  do {
    XNextEvent(display,&event);
  } while(event.type!=VisibilityNotify);
  XSelectInput(display,window,0);
	
#else /* WINDOWS */
	
  if (wtevent==INVALID_HANDLE_VALUE) wtevent=CreateEvent(NULL,FALSE,FALSE,"winevent");
  ResetEvent(wtevent);
  /* create thread to care for window */
  wthandle=CreateThread(NULL,0,(LPTHREAD_START_ROUTINE)winthread,
			     0,0,(LPDWORD)&wtid);
  if (wthandle==NULL) {
    error(ERROR,"can't create thread for window");
    return;
  }
	
  WaitForSingleObject(wtevent,INFINITE);
  	
#endif
  first=FALSE;
  winopened=TRUE;
  calc_psscale();
}


int grafinit(void)  /* initialize grafics (either X or WIN95) */
{
	
#ifdef UNIX
  static int screen; /* Number of Screen on Display */
  static XColor asked,got; /* color is complex ... */
  static Colormap map; /* my color map */
  static XGCValues xgcvalues; /* Values for Graphics Context */
  static unsigned int w,h; /* width and height of window */
#elif WINDOWS
  int n;
  int f; /* int-value of font */
  char *family; /* font family */
#endif
	
#ifdef UNIX
	
  /* get display */
  display=XOpenDisplay(displayname);
  if (display==NULL) {
    error(ERROR,"Can't open Display");
    return FALSE;
  }
    
  /* get screen */
  screen=DefaultScreen(display);
  root=RootWindow(display,screen);
	
  /* care for colors */
  if (DefaultDepth(display,screen)==1) {  /* BW-Screen ? */
    f_colour=BlackPixel(display,screen);
    b_colour=WhitePixel(display,screen); }
  else {
    map=DefaultColormap(display,screen);
    if (foreground==NULL) 
      foreground=XGetDefault(display,"yabasic","foreground");
    if (foreground==NULL) foreground="black";
		
    if (!XAllocNamedColor(display,map,foreground,&got,&asked)) {
      sprintf(string,"could not get fg-color '%s', trying 'black' instead",
	      foreground);
      error(WARNING,string);
      if (!XAllocNamedColor(display,map,"black",&got,&asked)) {
	error(ERROR,"could not get it");
	return FALSE;
      }
    }
    f_colour=got.pixel;
		
    if (background==NULL) 
      background=XGetDefault(display,"yabasic","background");
    if (background==NULL) background="white";
    if (!XAllocNamedColor(display,map,background,&got,&asked)) {
      sprintf(string,"could not get bg-color '%s', trying 'white' instead",
	      background);
      error(WARNING,string);
      if (!XAllocNamedColor(display,map,"white", &got,&asked)) {
	error(ERROR,"could not get it");
	return FALSE;
      }
    }
    b_colour=got.pixel;
  }
	
  /* get size hints */
  if (geometry==NULL) geometry=XGetDefault(display,"yabasic","geometry");
  XParseGeometry(geometry,&winx,&winy,&w,&h);
  sizehints.x=winx;
  sizehints.y=winy;
  sizehints.flags=USPosition;
	
  /* get font height */
  if (!font) font=XGetDefault(display,"yabasic","font");
  if (!font) font="6x10";
  myfont=XLoadQueryFont(display,font);
  if (!myfont) {
    sprintf(string,"could not load font '%s', trying 'fixed' instead",font);
    error(WARNING,string);
    myfont=XLoadQueryFont(display,"fixed");
    if (!myfont) {
      error(ERROR,"could not get it");
      return FALSE;
    }
  }
  xgcvalues.font=myfont->fid;
  fontheight=myfont->ascent;
    
  /* create graphics context, accept defaults ... */
  xgcvalues.foreground=f_colour;
  xgcvalues.background=b_colour;
  gc=XCreateGC(display,root,GCForeground|GCBackground|GCFont,&xgcvalues);
  /* create graphics context for reverse drawing */
  xgcvalues.foreground=b_colour;
  xgcvalues.background=f_colour;
  rgc=XCreateGC(display,root,GCForeground|GCBackground,&xgcvalues);
	
#elif WINDOWS
	
  /* choose font */
  if (!font) font=getreg("font");
  if (!font) font="swiss13";
  f=FF_SWISS;
  fontheight=13;    
    
  family=my_strdup(font);
  for(n=0;*(family+n)!='\0' && !isdigit(*(family+n));n++)
    *(family+n)=tolower((int)*(family+n));
  if (isdigit(*(family+n))) sscanf(family+n,"%d",&fontheight);
  *(family+n)='\0';
    
  if (!strcmp("decorative",family)) f=FF_DECORATIVE;
  else if (!strcmp("dontcare",family)) f=FF_DONTCARE;
  else if (!strcmp("modern",family)) f=FF_MODERN;
  else if (!strcmp("roman",family)) f=FF_ROMAN;
  else if (!strcmp("script",family)) f=FF_SCRIPT;
  else if (!strcmp("swiss",family)) f=FF_SWISS;
  else {
    sprintf(string,"Don't know font '%s' using 'swiss' instead",font);
    error(WARNING,string);
    f=FF_SWISS;
  }
    
  logfont.lfHeight=-fontheight;
  logfont.lfWidth=0;
  logfont.lfEscapement=0;
  logfont.lfOrientation=0;
  logfont.lfWeight=FW_DONTCARE;
  logfont.lfItalic=FALSE;
  logfont.lfUnderline=FALSE;
  logfont.lfStrikeOut=FALSE;
  logfont.lfCharSet=DEFAULT_CHARSET;
  logfont.lfOutPrecision=OUT_DEFAULT_PRECIS;
  logfont.lfClipPrecision=CLIP_DEFAULT_PRECIS;
  logfont.lfQuality=DEFAULT_QUALITY;
  logfont.lfPitchAndFamily=DEFAULT_PITCH | f;
  logfont.lfFaceName[0]='\0';
  myfont=CreateFontIndirect(&logfont);
	
  if (myfont==NULL) {
    sprintf(string,"Could not create font '%s' for screen",font);
    error(ERROR,string);
    return FALSE;
  }
#endif
  return TRUE;
}

void calc_psscale()  /* calculate scale-factor for postscript */
{
  if ((float)winwidth/winheight>(float)18/25)
    psscale=18*0.39*72/winwidth;
  else
    psscale=25*0.39*72/winheight;
}


void dot() /* draw a dot */
{
  double x,y;
	
  y=pop()->value;
  x=pop()->value;
  transform(&x,&y);
  if (!winopened) {
    error(ERROR,"Got no window to draw");
    return;
  }
#ifdef UNIX
  XDrawPoint(display,window,gc,x,y);
  XFlush(display);
  if (printerfile) {
    fprintf(printerfile,"%g %g D\n",
            (x-0.5)*psscale,(winheight-y+0.5)*psscale);
  }
#elif WINDOWS
  startdraw();
  SetPixelV(devcon,(int)x,(int)y,RGB(0,0,0));
  SetPixelV(bitcon,(int)x,(int)y,RGB(0,0,0));
  if (printer) {
    MoveToEx(printer,(int)(x*prnscale+prnoff),(int)(y*prnscale+prnoff),NULL);
    LineTo(printer,(int)(x*prnscale+prnoff),(int)(y*prnscale+prnoff));
  }
  ReleaseDC(window,devcon);
#endif
}


void create_line(char flag) /* create Command 'line' */
{
  struct command *cmd;
	
  cmd=add_command(cLINE);
  cmd->tag=flag;
}


void line(struct command *cmd) /* draw a line */
{
  double x1,y1,x2,y2;
  double nx,ny,px,py,norm;
  int arrow;
  static double lastx,lasty;
  static int lastvalid=FALSE;
	
  if (!winopened) {
    error(ERROR,"Got no window to draw");
    return;
  }
	
  if (cmd->tag=='n') {
    lastvalid=FALSE;
    return;
  }
  arrow=(cmd->tag=='a');
  y2=pop()->value;
  x2=pop()->value;
  if (cmd->tag=='t') {
    if (!lastvalid) {
      lastx=x2;
      lasty=y2;
      lastvalid=TRUE;
      return;
    }
    y1=lasty;
    x1=lastx;
  }
  else {
    y1=pop()->value;
    x1=pop()->value;
  }
  lastx=x2;
  lasty=y2;
  transform(&x1,&y1);
  transform(&x2,&y2);
	
  if (arrow) {
    px=x2-x1;
    py=y2-y1;
    nx=py;
    ny=-px;
    norm=sqrt(nx*nx+ny*ny);
    nx*=0.4*fontheight/norm;
    ny*=0.4*fontheight/norm;
    px*=0.8*fontheight/norm;
    py*=0.8*fontheight/norm;
  }
	
  do_line(x1,y1,x2,y2);
  if (arrow) {
    do_line(x2,y2,x2-px+nx,y2-py+ny);
    do_line(x2,y2,x2-px-nx,y2-py-ny);
  }
}


void do_line(double x1,double y1,double x2,double y2) /* draw a line */
{
#ifdef UNIX
  XDrawLine(display,window,gc,x1,y1,x2,y2);
  XFlush(display);
  if(printerfile) {
    fprintf(printerfile,"N\n");
    fprintf(printerfile,"%g %g M\n",
            x1*psscale,(winheight-y1)*psscale);
    fprintf(printerfile,"%g %g L S\n",
            x2*psscale,(winheight-y2)*psscale);
  }
  fflush(printerfile);
#elif WINDOWS
  startdraw();
  MoveToEx(devcon,(int)x1,(int)y1,NULL);
  LineTo(devcon,(int)x2,(int)y2);
  MoveToEx(bitcon,(int)x1,(int)y1,NULL);
  LineTo(bitcon,(int)x2,(int)y2);
  if (printer) {
    MoveToEx(printer,(int)(x1*prnscale+prnoff),(int)(y1*prnscale+prnoff),NULL);
    LineTo(printer,(int)(x2*prnscale+prnoff),(int)(y2*prnscale+prnoff));
  }
  ReleaseDC(window,devcon);
#endif
}


void circle() /* draw a circle */
{
  double x,y,r;
	
  r=pop()->value;
  y=pop()->value;
  x=pop()->value;
  transform(&x,&y);
  if (!winopened) {
    error(ERROR,"Got no window to draw");
    return;
  }
  do_circle(x,y,r);
}


void do_circle(double x,double y,double r) /* actually draw the circle */
{
#ifdef UNIX
  XDrawArc(display,window,gc,x-r,y-r,2*r,2*r,0*64,360*64);
  XFlush(display);
  if(printerfile) {
    fprintf(printerfile,"N\n");
    fprintf(printerfile,"%g %g %g C S\n",
            x*psscale,(winheight-y)*psscale,r*psscale);
    fflush(printerfile);
  }
#else /* WINDOWS */
  startdraw();
  Arc(devcon,(int)(x-r),(int)(y-r),(int)(x+r),(int)(y+r),0,0,0,0);
  Arc(bitcon,(int)(x-r),(int)(y-r),(int)(x+r),(int)(y+r),0,0,0,0);
  if (printer) {
    Arc(printer,(int)((x-r)*prnscale+prnoff),(int)((y-r)*prnscale+prnoff),
	(int)((x+r)*prnscale+prnoff),(int)((y+r)*prnscale+prnoff),0,0,0,0); 
  }
  ReleaseDC(window,devcon);
#endif
}


void create_text(int has_alignement) /* create Command 'text' */
{
  struct command *cmd;
	
  cmd=add_command(cTEXT);
  cmd->args=has_alignement;
}


void text(struct command *cmd) /* write a text */
{
  double x,y;
  char *text,*alignement;
	
  if (cmd->args) {
    alignement=pop()->pointer;
    if (!check_alignement(alignement)) return;
  }    
  else {
    alignement=text_align;
  }
  text=pop()->pointer;
  y=pop()->value;
  x=pop()->value;
  transform(&x,&y);
  if (!winopened) {
    error(ERROR,"Got no window to draw");
    return;
  }
  do_text((int)x,(int)y,text,alignement);
}


int check_alignement(char *al) /* checks, if text-alignement is valid */
{
  al[0]=tolower((int)al[0]);
  al[1]=tolower((int)al[1]);
  if (al[2]!='\0' || !strchr("clr",al[0]) || !strchr("ctb",al[1])) {
    error(ERROR,"invalid text-alignement");
    return FALSE;
  }
  return TRUE;
}


void do_text(int x,int y,char *text,char *align) /* actually write a text */
{
  int xoff,yoff,len;
#ifdef UNIX
  int i,d1,d2,d3; /* dummies */
  XCharStruct size;
#else
  UINT algn;
#endif
	
  len=strlen(text);
#ifdef UNIX
  XTextExtents(myfont,text,len,&d1,&d2,&d3,&size);
  if (align[0]=='l') xoff=0;
  else if (align[0]=='r') xoff=-size.width;
  else xoff=-size.width/2;
  if (align[1]=='t') yoff=fontheight;
  else if (align[1]=='b') yoff=0;
  else yoff=fontheight/2;
  XDrawString(display,window,gc,x+xoff,y+yoff,text,len);
  XFlush(display);
  if (printerfile) {
    for(i=0;i<INBUFFLEN;i++) {
      if (*text=='(' || *text==')') {
	string[i]='\\';
	i++;
      }
      string[i]=*text;
      text++;
    }
    fprintf(printerfile,"%g %g (%c) (%s) AT\n",
	    x*psscale,(winheight-y-yoff)*psscale,align[0],string);
  }
#else /* WINDOWS */
  startdraw();
  SelectObject(devcon,myfont);
  SetBkMode(devcon,TRANSPARENT);
  SelectObject(bitcon,myfont);
  SetBkMode(bitcon,TRANSPARENT);
  algn=0;
  xoff=yoff=0;
  if (align[0]=='l') algn|=TA_LEFT;
  else if (align[0]=='r') algn|=TA_RIGHT;
  else algn|=TA_CENTER;
  if (align[1]=='t') algn|=TA_TOP;
  else if (align[1]=='b') algn|=TA_BOTTOM;
  else {
    algn|=TA_BOTTOM;
    yoff=fontheight/2;
  }
  SetTextAlign(devcon,algn);
  TextOut(devcon,x+xoff,y+yoff,text,len);
  SetTextAlign(bitcon,algn);
  TextOut(bitcon,x+xoff,y+yoff,text,len);
  ReleaseDC(window,devcon);
  if (printer) {
    SetBkMode(printer,TRANSPARENT);
    SetTextAlign(printer,algn);
    TextOut(printer,(int)((x+xoff)*prnscale+prnoff),
	    (int)((y+yoff)*prnscale+prnoff),text,strlen(text));
  }
#endif
}


void closewin() /* close the window */
{
  if (!winopened) {
    error(WARNING,"Got no window to close");
    return;
  }
  winopened=FALSE;
#ifdef UNIX
  XDestroyWindow(display,window); 
  XFlush(display);
#else /* WINDOWS */
  PostThreadMessage(wtid,WM_QUIT,0,0);
#endif
}


void clearwin() /* clear the window */
{
#ifdef WINDOWS
  RECT interior;
#endif
	
  if (!winopened) {
    error(WARNING,"Got no window to clear");
    return;
  }
#ifdef UNIX
  XClearWindow(display,window); 
  if (printerfile) {
    fprintf(printerfile,"showpage\n");
    fflush(printerfile);
  }
#else /* WINDOWS */
  startdraw();
  GetClientRect(window,&interior);
  FillRect(devcon,&interior,(HBRUSH) COLOR_WINDOW);
  FillRect(bitcon,&interior,(HBRUSH) COLOR_WINDOW);
  if (printer) {
    EndPage(printer);
    StartPage(printer);
  }
  ReleaseDC(window,devcon);
#endif
}


void makemap() /* make map for plotting */
{
  double x1,x2,y1,y2,p1,p2,q1,q2;
  y2=pop()->value;
  x2=pop()->value;
  y1=pop()->value;
  x1=pop()->value;
  q2=pop()->value;
  p2=pop()->value;
  q1=pop()->value;
  p1=pop()->value;
  if (q1==q2 || p1==p2) {
    error(ERROR,"singular mapping");
    return;
  }
  xoff=(x2*p1-x1*p2)/(p1-p2);
  xinc=(x1-x2)/(p1-p2);
  yoff=(y2*q1-y1*q2)/(q1-q2);
  yinc=(y1-y2)/(q1-q2);
  if (infolevel>=DIAGNOSTIC) {
    sprintf(string,"xoff=%g, xinc=%g, yoff=%g, yinc=%g",
	    xoff,xinc,yoff,yinc);
    error(DIAGNOSTIC,string);
  }
  return;
}


void map() /* map coordinates for plotting */
{
  double p,q;
  struct stackentry *x,*y;
	
  q=pop()->value;
  p=pop()->value;
	
  x=push();
  y=push();
  x->value=p*xinc+xoff;
  x->type=stNUMBER;
  y->value=q*yinc+yoff;
  y->type=stNUMBER;
  if (infolevel>=DIAGNOSTIC) {
    sprintf(string,"Mapping (%g,%g) to (%g,%g)",p,q,x->value,y->value);
    error(DIAGNOSTIC,string);
  }
	
  return;
}


void create_tick(int flag) /* create Command 'cTICK' */
{
  struct command *cmd;
	
  cmd=add_command(cTICK);
  cmd->args=flag;
}


void tick(struct command *cmd) /* draw tick on axes */
{
  int xtick,ticklen;
  char *text=NULL;
  double x,y;
	
  if (!winopened) {
    error(ERROR,"Got no window to draw");
    return;
  }
  xtick=(cmd->args&2)==0;
  if (cmd->args&1) text=pop()->pointer;
  y=pop()->value;
  x=pop()->value;
  transform(&x,&y);
	
  ticklen=(text)?(2*fontheight/3):(fontheight/3);
  if (xtick) {
    do_line(x,y,x,y+ticklen);
    if (text) do_text((int)x,(int)(y+ticklen+fontheight/3),text,"ct");
  }
  else {
    do_line(x,y,x-ticklen,y);
    if (text) do_text((int)(x-ticklen-fontheight/3),(int)y,text,"rc");
  }
  return;
}


void moveorigin(char *or) /* move origin of window */
{
  if (or==NULL) or=pop()->pointer;
  or[0]=tolower((int)or[0]);
  or[1]=tolower((int)or[1]);
  if (or[2]!='\0' || !strchr("lcr",or[0]) || !strchr("tbc",or[1])) {
    error(ERROR,"invalid window origin");
    return;
  }
  strcpy(winorigin,or);
  return;
}


void transform(double *x,double *y) /* do transformation */
{
  double xz,yz,xd,yd;
  double xalt,yalt;
	
  if (infolevel>=DIAGNOSTIC) {
    xalt=*x;
    yalt=*y;
  }
  switch(winorigin[0]) {
  case 'l': xz=0;xd=1.0;break;
  case 'c': xz=winwidth/2;xd=1.0;break;
  case 'r': xz=winwidth;xd=-1.0;break;
  }
  switch(winorigin[1]) {
  case 't': yz=0;yd=1.0;break;
  case 'c': yz=winheight/2;yd=1.0;break;
  case 'b': yz=winheight;yd=-1.0;break;
  }
  *x=(*x)*xd+xz;
  *y=(*y)*yd+yz;
  if (infolevel>=DIAGNOSTIC) {
    sprintf(string,"transforming (%g,%g) into (%g,%g)",xalt,yalt,*x,*y);
    error(DIAGNOSTIC,string);
  }
}


void create_rect(int filled) /* create Command 'cRECT' */
{
  struct command *cmd;
	
  cmd=add_command(cRECT);
  cmd->args=filled;
}


void rect(struct command *cmd) /* draw a (filled) rect */
{
#ifdef WINDOWS
  RECT box;
#endif
  int filled;
  double x1,y1,x2,y2,s;
	
  if (!winopened) {
    error(ERROR,"Got no window to draw");
    return;
  }
  filled=cmd->args;
  y2=pop()->value;
  x2=pop()->value;
  y1=pop()->value;
  x1=pop()->value;
  transform(&x1,&y1);
  transform(&x2,&y2);
  if (x1>x2) {s=x2;x2=x1;x1=s;}
  if (y1>y2) {s=y2;y2=y1;y1=s;}
#ifdef UNIX
  if (filled) {
    XFillRectangle(display,window,rgc,x1,y1,x2-x1,y2-y1);
    if (printerfile) {
      fprintf(printerfile,"%g %g %g %g F\n",
	      x1*psscale,(winheight-y1)*psscale,
	      x2*psscale,(winheight-y2)*psscale);
      fflush(printerfile);
    }
  }
#else
  startdraw();
  box.right=(long)x1;
  box.left=(long)x2;
  box.top=(long)y1;
  box.bottom=(long)y2;
  FillRect(devcon,&box,(HBRUSH) COLOR_WINDOW);
  FillRect(bitcon,&box,(HBRUSH) COLOR_WINDOW);
  if (printer) {
    box.right=(long)(x1*prnscale+prnoff);
    box.left=(long)(x2*prnscale+prnoff);
    box.top=(long)(y1*prnscale+prnoff);
    box.bottom=(long)(y2*prnscale+prnoff);
    FillRect(printer,&box,GetStockObject(WHITE_BRUSH));
  }
  ReleaseDC(window,devcon);
#endif
  do_line(x1,y1,x1,y2);
  do_line(x1,y2,x2,y2);
  do_line(x2,y2,x2,y1);
  do_line(x2,y1,x1,y1);
}


void create_marker(int args) /* create command 'cMARKER' */
{
  struct command *cmd;
	
  cmd=add_command(cMARKER);
  cmd->args=args;
}


void marker(struct command *cmd) /* draw a marker */
{
  char *text,*t;
  double x,y,s1,s2,s3,r3;
	
  if (cmd->args>4) s2=pop()->value;
  if (cmd->args>3) s1=pop()->value;
  else s1=fontheight/2;
  if (cmd->args<=4) s2=s1;
  text=pop()->pointer;
  y=pop()->value;
  x=pop()->value;
  if (!winopened) {
    error(ERROR,"Got no window to draw");
    return;
  }
  transform(&x,&y);
  for(t=text;*t;t++) *t=tolower((int)*t);
  if (!strcmp(text,"error") || !strcmp(text,"err")) {
    s3=fontheight/4;
    s1*=yinc;
    s2*=yinc;
    do_line(x,y-s1,x,y+s2);
    do_line(x-s3,y-s1,x+s3,y-s1);
    do_line(x-s3,y+s2,x+s3,y+s2);
  }
  else if (cmd->args>4) {
    sprintf(string,"Too many parameters for marker '%s'",text);
    error(ERROR,string);
    return;
  }
  else if (!strcmp(text,"dot") || !strcmp(text,"point") || 
	   !strcmp(text,".") || !strcmp(text,"circle")) {
    do_circle(x,y,s1);
  }
  else if (!strcmp(text,"square") || !strcmp(text,"sq")) {
    do_line(x-s1,y-s1,x+s1,y-s1);
    do_line(x+s1,y-s1,x+s1,y+s1);
    do_line(x+s1,y+s1,x-s1,y+s1);
    do_line(x-s1,y+s1,x-s1,y-s1);
  }
  else if (!strcmp(text,"star") || !strcmp(text,"*")) {
    do_line(x,y-s1,x,y+s1);
    do_line(x-s1,y,x+s1,y);
    s1*=sqrt(2)/2;
    do_line(x-s1,y-s1,x+s1,y+s1);
    do_line(x+s1,y-s1,x-s1,y+s1);
  }
  else if (!strcmp(text,"cross") || !strcmp(text,"+")) {
    do_line(x,y-s1,x,y+s1);
    do_line(x-s1,y,x+s1,y);
  }
  else if (!strcmp(text,"triangle") || !strcmp(text,"tri")) {
    r3=sqrt(3);
    do_line(x-s1,y+s1/r3,x+s1,y+s1/r3);
    do_line(x-s1,y+s1/r3,x,y-s1*(r3-1/r3));
    do_line(x+s1,y+s1/r3,x,y-s1*(r3-1/r3));
  }
  else {
    sprintf(string,"'%s' is not a valid marker",text);
    error(ERROR,string);
    return;
  }
}


void mywait() /* wait given number of seconds */
{
  double delay;
	
#if defined(UNIX)
#ifdef HAVE_SETITIMER
  struct itimerval new;
#else
  time_t start,now;
#endif
#endif
	
#ifdef WINDOWS
  MSG msg;
  int timerid;
#endif
	
  delay=fabs(pop()->value);
#ifdef UNIX
#ifdef HAVE_SETITIMER
  new.it_interval.tv_sec=0.0;
  new.it_interval.tv_usec=0.0;
  new.it_value.tv_sec=floor(delay);
  new.it_value.tv_usec=1000000*(delay-floor(delay));
  setitimer(ITIMER_REAL,&new,NULL);
  signal(SIGALRM,signal_handler);
  pause();
#else /* not HAVE_SETITIMER */
  time(&start);
  do {
    time(&now);
  } while(difftime(now,start)<delay);
#endif
#else /* WINDOWS */
  timerid=SetTimer(NULL,0,(int)(delay*1000),(TIMERPROC) NULL);
  GetMessage((LPMSG)&msg,NULL,WM_TIMER,WM_TIMER);
  KillTimer(NULL,timerid);
#endif
}

#if !defined(HAVE_DIFFTIME) && defined(UNIX)
double difftime(long a,long b) /* compute time differences */
{
  return (double)(a-b);
}
#endif


void mybell() /* ring ascii bell */
{
#ifdef UNIX
  printf("\007");
  fflush(stdout);
#else /* WINDOWS */
  Beep(1000,100);
#endif
}


void duplicate(void) /* duplicate topmost element of stack */
{
  struct stackentry *s;
  double actual;
	
  actual=stackhead->prev->value;
  s=push();
  s->type=stNUMBER;
  s->value=actual;
}


void forcheck(void) /* check, if for-loop is done */
{
  double start,bound,step,val;
	
  val=pop()->value;
  step=pop()->value;
  bound=pop()->value;
  start=stackhead->prev->value;
  if ((val<=bound && val>=start) || (val<=start && val>=bound)) 
    stackhead->prev->value=1.;
  else
    stackhead->prev->value=0.;
}


void forincrement(void) /* increment value on stack */
{
  /* expecting on stack: BOUND,STEP,VAL,stackhead
     where for VAL=START to BOUND step STEP */
  stackhead->prev->value+=stackhead->prev->prev->value;
}


void startfor(void) /* compute initial value of for-variable */
{
  struct stackentry *p;
	
  p=push();
  p->value=stackhead->prev->prev->prev->prev->value-stackhead->prev->prev->value;
  p->type=stNUMBER;

  return;
}


void pushname(char *name) /* push a name on stack */
{
  struct stackentry *s;
	
  s=push();
  s->pointer=my_strdup(name);
  s->type=stSTRING;
}


void pushlabel() /* generate goto and push label on stack */
{
  char *st;
  struct stackentry *en;
	
  st=(char *) my_malloc(sizeof(char)*20);
  sprintf(st,"***%d",labelcount);
  labelcount++;
  create_goto(st);
  en=push();
  en->type=stLABEL;
  en->pointer=st;
}


void poplabel() /* pops a label and generates the matching command */
{
  struct stackentry *en;
	
  en=pop();   /* get name of label */
  if (en->type!=stLABEL) {
    error(FATAL,"Not a goto on stack");
    return;
  }
  create_label(en->pointer);  /* and create it */
}


void pushgoto() /* generate label and push goto on stack */
{
  char *st;
  struct stackentry *en;
	
  st=(char *) my_malloc(sizeof(char)*20);
  sprintf(st,"***%d",labelcount);
  labelcount++;
  create_label(st);
  en=push();
  en->type=stGOTO;
  en->pointer=st;
}


void popgoto() /* pops a goto and generates the matching command */
{
  struct stackentry *en;
	
  en=pop();   /* get name of goto */
  if (en->type!=stGOTO) {
    error(FATAL,"Not a goto on stack");
    return;
  }
  create_goto(en->pointer);  /* and create it */
}


void pushcounter(void) 
{
  /* push number '0' on stack, will be used as a counter */
	
  struct stackentry *p;
	
  p=push();
  p->type=stNUMBER;
  p->value=0;
}


void inccounter(void) 
{
  /* increment topmost stack element */
	
  (stackhead->prev->value)++;
}


void storelabel() /* push label on stack */
{
  char *st;
  struct stackentry *en;
	
  st=(char *)my_malloc(sizeof(char)*20);
  sprintf(st,"***%d",labelcount);
  labelcount++;
  en=push();
  en->type=stLABEL;
  en->pointer=st;
}


void matchgoto() /* generate goto matching label on stack */
{
  create_goto(stackhead->prev->pointer);
}


void swap() /*swap topmost elements on stack */
{
  struct stackentry *a,*b;
	
  if ((a=stackhead->prev)==NULL || (b=a->prev)==NULL) {
    error(ERROR,"Nothing to swap on stack !");
    return;
  }
  a->prev=b->prev;b->next=a->next;   /* just swap the pointers */
  a->next=b;b->prev=a;
  stackhead->prev=b;
  if (b==stackroot) stackroot=a;  /* treat root special */
  else (a->prev)->next=a;
}


struct stackentry *push() 
     /* push element on stack and enlarge it*/
{
  struct stackentry *new;
	
  if (stackhead->next==NULL) { /* no next element */
    /* create new element */
    new=(struct stackentry *)my_malloc(sizeof(struct stackentry)); 
    /* and initialize it */
    new->next=NULL;  
    new->value=0.0;
    new->type=stFREE;
    new->prev=stackhead;
    new->pointer=NULL;
    stackhead->next=new;
  }
  stackhead=stackhead->next; /* advance head */
  /* any content is set free */
  if ((stackhead->prev)->pointer!=NULL && (stackhead->prev)->type==stSTRING) 
    free((stackhead->prev)->pointer);
  (stackhead->prev)->pointer=NULL;
  return stackhead->prev;
}


struct stackentry *pop()
     /* pops element to memory and looks for pop-error */
{
  /* test if there is something on the stack */
  if (stackhead==stackroot) {
    error(FATAL,"Popped too much.");
    return stackhead;
  }
  stackhead=stackhead->prev; /* move down in stack */
  return stackhead;  /* this is your value; use it quickly ! */
}


void std_diag(char *head,int type) /* produce standard diegnostic */
{
  int n,i;
  char *s;
  struct stackentry *sp;

  if (infolevel>=DIAGNOSTIC) {
    s=string;
    if (type>cLAST_COMMAND || type<cFIRST_COMMAND) {
      sprintf(s,"%s Illegal %d %n",head,type,&n);
    }
    else {
      sprintf(s,"%s '%s' %n",head,explanation[type],&n);
    }
    s+=n;
    if (stackhead->prev!=stackroot) {
      sprintf(s,"(");
      s++;
      sp=stackhead;
      for(i=0;i<3;i++) {
	sp=sp->prev;
	if (sp==stackroot) break;
	if (i>0) {
	  sprintf(s,",");
	  s++;
	}
	switch(sp->type) {
	case stGOTO:
	  sprintf(s,"goto%n",&n);
	  break;
	case stSTRING:
	  sprintf(s,"\"%s\"%n",(char *)sp->pointer,&n);
	  break;
	case stNUMBER:
	  sprintf(s,"%g%n",sp->value,&n);
	  break;
	case stLABEL:
	  sprintf(s,"label%n",&n);
	  break;
	case stRETADD:
	  sprintf(s,"retadd%n",&n);
	  break;
	case stFREE:
	  sprintf(s,"free%n",&n);
	  break;
	default:
	  sprintf(s,"unknown%n",&n);
	  n=0;
	}
	s+=n;
      }
      sprintf(s,")");
    }
    error(DIAGNOSTIC,string);
  }
}


struct command *add_command(int type) 
     /* get room for new command, and make a link from old one */
{
  struct command *new,*old;
	
  std_diag("creating",type);
  cmdhead->type=type;  /* store command */
  cmdhead->line=yylineno;
  commandcount++;
  cmdhead->pointer=NULL;  /* no data yet */ 
  /* no next element, so, create it: */
  new=(struct command *)my_malloc(sizeof(struct command)); 
  /* and initialize */
  new->next=NULL;
  new->pointer=NULL;
  cmdhead->next=new;
  old=cmdhead;
  cmdhead=cmdhead->next;
  return old;
}


void parse_arguments(int cargc,char *cargv[])
     /* parse arguments from the command line */
{
  char **argv;
  int argc,larg;
#ifdef UNIX
  char *parg;
  int i;
#endif
  int ar;
  FILE *inputfile;
  char *option;
  char info;
  int opened=FALSE;

  if (cargc>1) larg=strlen(cargv[1]);
  else larg=0;
#ifdef UNIX
  if (cargc>0) {
    /* get room for arguments */
    argv=(char **)my_malloc((larg+cargc+1)*sizeof(char *));
    /* copy zero argument */
    argv[0]=cargv[0];
    argc=0;
    /* chop first argument into pieces */
    if (cargc>=2) {
      parg=strtok(my_strdup(cargv[1])," \t");
      for(argc=1;parg;argc++) {
	argv[argc]=parg;
	parg=strtok(NULL," \t");
      }
    }
    /* copy other arguments */
    for(i=2;i<cargc;i++) {
      argv[argc]=cargv[i];
      argc++;
    }
  }
#else
  argc=cargc;
  argv=cargv;
#endif
  yabargv=(char **)my_malloc((larg+cargc+1)*sizeof(char *));
  yabargc=0;

  /* process options */
  for(ar=1;ar<argc;ar++) {
    option=argv[ar];
    if (!strcmp("-help",option) || !strcmp("--help",option) ||
	!strcmp("-h",option)    || !strcmp("-?",option))
      goto usage;
    else if (!strcmp("-i",option) || !strcmp("-info",option) ||
	     !strcmp("-infolevel",option)) {
      ar++;
      info=tolower((int)*argv[ar]);
      switch(info) {
      case 'd':infolevel=DIAGNOSTIC;break;
      case 'n':infolevel=NOTE;break;
      case 'w':infolevel=WARNING;break;
      case 'e':infolevel=ERROR;break;
      case 'f':infolevel=FATAL;break;
      default:
	fprintf(stderr,"There's  no infolevel '%s'.\n",argv[ar]);
	goto usage;
      }
    }
    else if (!strcmp("-fg",option)) {   
      ar++;
      foreground=my_strdup(argv[ar]);
    }
    else if (!strcmp("-bg",option)) {           
      ar++;
      background=my_strdup(argv[ar]);   
    }
    else if (!strcmp("-geometry",option)) {             
      ar++;
      geometry=my_strdup(argv[ar]);     
    }
    else if (!strcmp("-display",option)) {              
      ar++;
      displayname=my_strdup(argv[ar]);
    }
    else if (!strcmp("-font",option)) {         
      ar++;
      font=my_strdup(argv[ar]);
    }
    else if (!strcmp("-licence",option)) {
      fprintf(stderr,"\n%s\n",YABLICENSE);
      end_it(0);
    }
    else if (*option=='-') {
      fprintf(stderr,"Don't know option '%s'.\n",option);
      goto usage;
    }
    else if (!opened) { /* not an option */
      inputfile=fopen(argv[ar],"r");
      if (inputfile==NULL) {
	fprintf(stderr,"Could not open '%s'.\n",argv[ar]);
	end_it(1);
      }
      else {
#ifdef WINDOWS
	progname=strrchr(argv[ar],'\\');
	if (!progname) progname=strrchr(argv[ar],'/');
	if (progname) 
	  progname++;
	else 
	  progname=argv[ar];
	if (!progname) progname="Yabasic";
	SetConsoleTitle(progname);
#else
	progname=argv[ar];
#endif
	opened=TRUE;
      }
    }
    else {    /* option for yabasic program */
      yabargv[yabargc]=my_strdup(argv[ar]);
      yabargc++;
    }
  }
	
  interactive=FALSE;
  if (!opened) {
    interactive=TRUE;
    inputfile=stdin;
  }
    
  /* open a flex buffer for the file */
  switch_to_my_file(inputfile);
  return;
	
 usage: /* print a short usage message and then exit */
  fprintf(stderr,"\nyabasic "BASIC_VERSION", last change on "DOLC", subject to GNU copyleft.\n");
  fprintf(stderr,"Usage:\n");
  fprintf(stderr,"                yabasic [options] [filename]\n");
  fprintf(stderr,"\n  options:\n");
  fprintf(stderr,"    -i [d|n|w|e|f]  :  set infolevel to diagnostic,note,warning(default),\n                       error or fatal.\n");
  fprintf(stderr,"    -?,-help        :  issue this message.\n");
  fprintf(stderr,"    -geometry       :  e.g. 10+20 to position window at x=10,y=20.\n");
#ifdef UNIX
  fprintf(stderr,"    -fg,-bg         :  colors for grafic.\n");
  fprintf(stderr,"    -display        :  screen, where window will be displayed.\n");
  fprintf(stderr,"    -font           :  font for grafics.\n");
#else /* WINDOWS */
  fprintf(stderr,"    -font           :  font for grafics, specify style and size, e.g swiss10\n");
  fprintf(stderr,"                       style=[decorative|dontcare|modern|roman|script|swiss]\n");
#endif
  fprintf(stderr,"    -licence        :  print licence, then exit.\n");
  fprintf(stderr,"\n  filename: File to read basic-code from. If yabasic is called\n");
  fprintf(stderr,"            without any filename, it will read and execute a program\n");
  fprintf(stderr,"            from STDIN and then exit.\n\n");
  fprintf(stderr,"For further infos on yabasic see the file \"yabasic.htm\".\n");
#ifdef UNIX
  fprintf(stderr,"\n");
#endif
  end_it(0);
}


void chop_command(char *command,int *argc,char ***argv)
     /* chop the WIN95-commandline into seperate strings */
{
  int i,j,count;
  int quote;
  char c,last;
  char *curr;
  char **list;
	
  /* count, how many arguments */
  count=i=0;
  last=' ';
  quote=FALSE;
  while((c=*(command+i))!='\0') {
    if (!quote && c!=' ' && last==' ') count++;
    if (c=='\"') quote=!quote;
    last=c;
    i++;
  }
	
  /* fill yabasic into argv[0] */
  *argv=malloc((count+1)*sizeof(char *));
  list=*argv;
  *argc=count+1;
  *list=my_strdup("yabasic");
	
  /* fill in other strings */
  i=0;
  count=1;
  last=' ';
  quote=FALSE;
  do {
    c=*(command+i);
    if (!quote && c!=' ' && last==' ') j=i;
    if (c=='\"') {
      quote=!quote;
      if (quote) j++;
    }
    if (((c==' ' && !quote) || c=='\0') && last!=' ') {
      *(list+count)=malloc((i-j+1)*sizeof(char));
      strncpy(*(list+count),command+j,i-j);
      curr=*(list+count)+i-j;
      *curr='\0';
      if (*(curr-1)=='\"') *(curr-1)='\0';
      count++;
    }
    last=c;
    i++;
  } while(c!='\0');
}

void end_it(int rc) /* perform shutdown-operations */
{
#ifdef UNIX
  if ((winopened && rc==0) || (curinized && rc!=0)) {
#else
    if (!Commandline || winopened) {
#endif
      coutstr=stdout;
#ifdef UNIX
      if (curinized) {
#endif
	onestring("Program done --- Press any key \n");
	inkey(-1);
#ifdef UNIX
      }
      else {
	onestring("Program done. \n");
      }
    }
#else
  }
#endif
#ifdef UNIX
  if (curinized) {
    endwin();
  }
#else
  if (printerfont) DeleteObject(printerfont);
  if (myfont) DeleteObject(myfont);
  if (printer) DeleteDC(printer);
#endif
  exit(rc);
}


int do_system2(char *cmd) /* execute command as system */
{
#ifdef UNIX
  int ret;
  if (curinized) reset_shell_mode();
  ret=system(cmd);
  if (curinized) reset_prog_mode();
  return ret;
#else
  STARTUPINFO start;
  PROCESS_INFORMATION proc;
  DWORD ec; /* exit code */
  SECURITY_ATTRIBUTES prosec;
  SECURITY_ATTRIBUTES thrsec;
		
  ZeroMemory(&prosec,sizeof(prosec));
  prosec.nLength=sizeof(prosec);
  prosec.bInheritHandle=TRUE;
  ZeroMemory(&thrsec,sizeof(thrsec));
  thrsec.nLength=sizeof(thrsec);
  thrsec.bInheritHandle=TRUE;
  ZeroMemory(&start,sizeof(start));
  start.cb=sizeof(STARTUPINFO); 
  start.dwFlags=STARTF_USESTDHANDLES;
  start.hStdOutput=GetStdHandle(STD_OUTPUT_HANDLE);
  start.hStdError=GetStdHandle(STD_ERROR_HANDLE);
  start.hStdInput=GetStdHandle(STD_INPUT_HANDLE);
  sprintf(string,"command.com /C %s",cmd);
  if (!CreateProcess(NULL,string,&prosec,&thrsec,TRUE,0,
		     NULL,NULL,&start,&proc)) {
    sprintf(string,"couldn't execute '%s'",cmd);
    error(ERROR,string);
    return -1;
  }
  WaitForSingleObject(proc.hProcess,INFINITE);
  CloseHandle(proc.hProcess);
  CloseHandle(proc.hThread);
  if (GetExitCodeProcess(proc.hProcess,&ec)) return ec;
  return -1;
#endif  
}
	
	
char *do_system(char *cmd) /* executes command via command.com */
{
  static char buff[SYSBUFFLEN]; /* buffer to store command */
  int len; /* number of bytes read */
#ifdef UNIX
  FILE *p; /* points to pipe */
  int c; /* char read from pipe */
#else
  STARTUPINFO start;
  PROCESS_INFORMATION proc;
  HANDLE piperead,pipewrite; /* both ends of pipes */
  SECURITY_ATTRIBUTES prosec;
  SECURITY_ATTRIBUTES thrsec;
#endif
  
  clear_buff();
  
#ifdef UNIX
  p=popen(cmd,"r");
  if (p==NULL) {
    sprintf(string,"couldn't execute '%s'",cmd);
    error(ERROR,string);
    return my_strdup("");
  }
  do {
    len=0;
    while(len<SYSBUFFLEN) {
      c=fgetc(p);
      if (c==EOF) {
	buff[len]='\0';
	break;
      }
      buff[len]=c;
      len++;
    }
    store_buff(buff);
  } while(c!=EOF);
  pclose(p);
		
#else	     
  ZeroMemory(&prosec,sizeof(prosec));
  prosec.nLength=sizeof(prosec);
  prosec.bInheritHandle=TRUE;
  ZeroMemory(&thrsec,sizeof(thrsec));
  thrsec.nLength=sizeof(thrsec);
  thrsec.bInheritHandle=TRUE;
		
  /* create pipe for writing */
  CreatePipe(&piperead,&pipewrite,&prosec,0);
		
  ZeroMemory(&start,sizeof(start));
  start.cb=sizeof(STARTUPINFO); 
  start.dwFlags=STARTF_USESTDHANDLES;
  start.hStdOutput=pipewrite;
  start.hStdError=pipewrite;
  start.hStdInput=GetStdHandle(STD_INPUT_HANDLE);
		
  sprintf(string,"command.com /C %s",cmd);
  if (!CreateProcess(NULL,string,&prosec,&thrsec,TRUE,0,
		     NULL,NULL,&start,&proc)) {
    sprintf(string,"couldn't execute '%s'",cmd);
    error(ERROR,string);
    return my_strdup("");
  }
		
  /* wait for output to arrive */
  WaitForSingleObject(proc.hProcess,INFINITE);
  do {
    ReadFile(piperead,buff,SYSBUFFLEN,(LPDWORD)&len,NULL);
    if (len<SYSBUFFLEN) buff[len]='\0';
    store_buff(buff);
  } while(len==SYSBUFFLEN);
  CloseHandle(piperead);
  CloseHandle(pipewrite);  
  CloseHandle(proc.hProcess);
  CloseHandle(proc.hThread);
#endif
  return recall_buff();
}
	
void clear_buff() /* clear system-input buffers */
{
  buffcurr=&buffroot;
  buffcount=0;
}
	
void store_buff(char *buff) /* store system-input buffer */
{
  *buffcurr=my_malloc(sizeof(struct buff_chain));
  memcpy((*buffcurr)->buff,buff,SYSBUFFLEN);
  buffcurr=&((*buffcurr)->next);
  buffcount++;
}
	
char *recall_buff() /* recall store buffer */
{
  struct buff_chain *curr,*old;
  char *result;
  int done;
		
  result=(char *)my_malloc(buffcount*SYSBUFFLEN);
  curr=buffroot;
  for(done=0;done<buffcount;done++) {
    memcpy(result+done*SYSBUFFLEN,curr->buff,SYSBUFFLEN);
    old=curr;
    curr=curr->next;
    free(old);
  }
  return result;
}
	
	
void create_poke(char flag) /* create Command 'cPOKE' */
{
  struct command *cmd;
		
  cmd=add_command(cPOKE);
  cmd->tag=flag;
}
	
	
void poke(struct command *cmd) /* poke in internals */
{
  char *dest,*s,c;
  char *sarg=NULL;
  double darg;
		
  if (cmd->tag=='s')
    sarg=pop()->pointer;
  else 
    darg=pop()->value;
		
  dest=pop()->pointer;
  for(s=dest;*s;s++) *s=tolower((int)*s);
  if (!strcmp(dest,"fontheight") && !sarg) {
    fontheight=(int)darg;
    calc_psscale();
  }
  else if (!strcmp(dest,"font") && sarg) {
    font=my_strdup(sarg);
  }
  else if (!strcmp(dest,"winwidth") && !sarg) {
    winwidth=(int)darg;
    if (winwidth<1) {
      error(ERROR,"winwidth less than 1 pixel");
      return;
    }
    calc_psscale();
  }
  else if (!strcmp(dest,"winheight") && !sarg) {
    winheight=(int)darg;
    if (winheight<1) {
      error(ERROR,"winheight less than 1 pixel");
      return;
    }
    calc_psscale();
  }
  else if (!strcmp(dest,"textalign") && sarg) {
    if (!check_alignement(sarg)) return;
    strncpy(text_align,sarg,2);
  }
  else if (!strcmp(dest,"windoworigin") && sarg) {
    moveorigin(sarg);
  }
  else if (!strcmp(dest,"infolevel") && sarg) {
    c=tolower((int)*sarg);
    switch(c) {
    case 'd': infolevel=DIAGNOSTIC;break;
    case 'n': infolevel=NOTE;break;
    case 'w': infolevel=WARNING;break;
    case 'e': infolevel=ERROR;break;
    case 'f': infolevel=FATAL;break;
    default:
      error(ERROR,"invalid infolevel");
      return;
    }
    if (infolevel>=DIAGNOSTIC) {
      sprintf(string,"switching infolevel to '%c'",c);
      error(DIAGNOSTIC,string);
    }
  }
  else if (!strcmp(dest,"stdout") && sarg) {
    fputs(sarg,stdout);
  }
  else {
    error(ERROR,"invalid poke");
  }
  return;
}
	
	
double peek(char *dest) /* peek into internals */
{
  char *s;
		
  for(s=dest;*s;s++) *s=tolower((int)*s);
  if (!strcmp(dest,"winwidth")) return winwidth;
  else if (!strcmp(dest,"winheight")) return winheight;
  else if (!strcmp(dest,"fontheight")) return fontheight;
  else if (!strcmp(dest,"screenheight")) return LINES;
  else if (!strcmp(dest,"screenwidth")) return COLS;
  else if (!strcmp(dest,"argument")) return yabargc;
  else {
    error(ERROR,"invalid peek");
  }
  return 0;
}
	
	
char *peek2(char *dest) /* peek into internals */
{
  char *s;
		
  for(s=dest;*s;s++) *s=tolower((int)*s);
  if (!strcmp(dest,"infolevel")) {
    if (infolevel==DIAGNOSTIC) return my_strdup("diagnostic");
    else if (infolevel==NOTE) return my_strdup("note");
    else if (infolevel==WARNING) return my_strdup("warning");
    else if (infolevel==ERROR) return my_strdup("error");
    else if (infolevel==FATAL) return my_strdup("fatal");
    else return my_strdup("unkown");
  }
  else if (!strcmp(dest,"textalign")) return my_strdup(text_align);
  else if (!strcmp(dest,"windoworigin")) return my_strdup(winorigin);
  else if (!strcmp(dest,"os")) {
#ifdef UNIX
    return my_strdup("unix");
#else
    return my_strdup("windows");
#endif
  }
  else if (!strcmp(dest,"font")) return my_strdup(font);
  else if (!strcmp(dest,"argument")) {
    if (yabargc>0) {
      s=yabargv[0];
      yabargc--;
      yabargv++;
    }
    else {
      s="";
    }
    return my_strdup(s);
  }
  else {
    error(ERROR,"invalid peek");
  }
  return my_strdup("");
}
	
	
#ifdef WINDOWS  /* routines needed only for WIN95 */
/* procedure to process WIN95 messages */
LRESULT CALLBACK mywindowproc(HWND handle,unsigned msg,
			      UINT wparam,DWORD lparam)
{
	RECT cr; /* client area rectangle */
	PAINTSTRUCT ps; /* receives information for painting */
	
	switch(msg) {
	case WM_PAINT:
		if (GetUpdateRect(handle,&cr,0)) {
			BeginPaint(handle,&ps);
			devcon=GetDC(handle);	
			BitBlt(devcon,cr.left,cr.top,cr.right-cr.left,cr.bottom-cr.top,
				bitcon,cr.left,cr.top,SRCCOPY);
			ReleaseDC(handle,devcon);
			EndPaint(handle,&ps);
			SetEvent(wtevent);
		}
		return 0;
	default:
	  return(DefWindowProc(handle,msg,wparam,lparam));
  }
}


/* procedure for WIN95-thread */
DWORD winthread(LPWORD par) {
	MSG msg;
  int w,h;
  RECT cr; /* client area rectangle */
		
  if (!geometry) geometry=getreg("geometry");
  if (geometry) 
    if (sscanf(geometry,"%ix%i+%i+%i",&w,&h,&winx,&winy)!=4)
      if (sscanf(geometry,"+%i+%i",&winx,&winy)!=2)
	if (sscanf(geometry,"%i+%i",&winx,&winy)!=2) 
	  winx=winy=30;
					
  /* get window-size from client-area size */
  cr.left=winx;
  cr.right=winx+winwidth;
  cr.top=winy;
  cr.bottom=winy+winheight;
  AdjustWindowRect(&cr,WS_VISIBLE|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,FALSE);
					
  /* create my window */
  window=CreateWindow(my_class, 
	  NULL,            /* my style */
	  WS_VISIBLE|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,/* window style */
	  winx,               /* initial x-position */
	  winy,               /* initial y-position */
	  cr.right-cr.left,      /* initial x-size */
	  cr.bottom-cr.top,    /* initial y-size */
	  NULL,            /* parent window */
	  NULL,            /* menu handle */
	  this_instance,   /* my instance */
	  (LPVOID) NULL);  /* dont know why */
  
  /* show my window */
  sprintf(string,"%s - Grafic Window",progname);
  SetWindowText(window,string);
  ShowWindow(this_instance,SW_SHOW);
  UpdateWindow(this_instance);
  SetForegroundWindow(window);
  winopened=TRUE;
  
  /* create bitmap device context */
  devcon=GetDC(window);
  bitcon=CreateCompatibleDC(devcon);
  cr.left=cr.top=0;
  cr.right=winwidth;
  cr.bottom=winheight;
  backbit=CreateCompatibleBitmap(devcon,cr.right-cr.left,cr.bottom-cr.top);
  SelectObject(bitcon,backbit);
  SelectClipRgn(bitcon,NULL);
  IntersectClipRect(bitcon,0,0,winwidth,winheight);
  FillRect(bitcon,&cr,(HBRUSH) COLOR_WINDOW);
  SelectObject(bitcon,GetStockObject(BLACK_PEN));
  ReleaseDC(window,devcon);
  
  /* get and dispatch messages */
  while(GetMessage((LPMSG)&msg,NULL,0,0)) {
	  DispatchMessage((LPMSG)&msg);
  }
  
  DestroyWindow(window);
  DeleteObject(backbit);
  DeleteDC(bitcon);
  ExitThread(0);
  return 0;
}
	
	
void startdraw() /* prepare for drawing */
{
  RECT interior;
		
  devcon=GetDC(window);
  GetClientRect(window,&interior);
  SelectClipRgn(devcon,NULL);
  IntersectClipRect(devcon,interior.left,interior.top,
		    interior.right,interior.bottom);
  if (printer) {
    if (!SelectObject(printer,printerfont)) {
      error(ERROR,"Could not select font for printer");
      return;
    }
    if (!SelectObject(printer,GetStockObject(BLACK_BRUSH))) {
      error(ERROR,"Could not select brush for printer");
      return;
    }
    if (SelectObject(printer,printerpen)==NULL) {
      error(ERROR,"Could not select pen for printer");
      return;
    }
  }
}
	
	
char *getreg(char *name) /* get default from Registry */
{
  char *keyname="SOFTWARE\\yabasic";
  HKEY key;
  char reg[80];
  DWORD n;
		
  RegOpenKeyEx(HKEY_LOCAL_MACHINE,keyname,0,KEY_ALL_ACCESS,&key);
  n=80;
  reg[0]='\0';
  RegQueryValueEx(key,name,NULL,NULL,reg,&n);
  if (reg[0]=='\0') return NULL;
  return my_strdup(reg);
}
#endif  /* WIN95-stuff ... */
	
	
void create_openprinter(int num) /* create command 'openprinter' */
{
  struct command *cmd;
		
  cmd=add_command(cOPENPRN);
  cmd->args=num;
}
	
	
void openprinter(struct command *cmd) /* opens a printer for WIN95 */
{
  static int first=TRUE;
#ifdef WINDOWS
  char PrinterName[200]; /* Name of default Printer */
  char *p; /* points into PrinterName */
  DOCINFO di;
  float prnwidth,prnheight;
  LOGBRUSH mybrush;
  RECT interior;
#endif  
		
  /* close file, if already open */
#ifdef UNIX
  if (printerfile) closeprinter();
#endif
		
  if (cmd->args==1) {
    prfilename=my_strdup((char *)(pop()->pointer));
    print_to_file=TRUE;}
  else {
    prfilename=my_strdup("\0");
    print_to_file=FALSE;
  }
#ifdef UNIX
  if (*prfilename=='\0') {
    free(prfilename);
    prfilename=my_strdup("/tmp/yabasic.ps");
  }
  printerfile=fopen(prfilename,"w");
  if (!printerfile) {
    sprintf(string,"could not open file '%s' for printing",prfilename);
    error(ERROR,string);
  }
#endif
  if (!first) return;
		
#ifdef WINDOWS
  /* query win.ini for defaul printer */
  GetProfileString("windows","device",",,,",
		   PrinterName,200);
		
  /* truncate printer name */
  p=PrinterName;
  while(*p && *p!=',') p++;
  *p='\0';
		
  printer=CreateDC(NULL,PrinterName,NULL,NULL);
  if (!printer) printer=CreateDC(NULL,"winspool",NULL,NULL);
		
  if (!printer) {
    error(ERROR,"Couldn't get handle for printer");
    return;
  }

  /* calculate scaling-factors */
  prnwidth=(float)GetDeviceCaps(printer,HORZRES);
  prnheight=(float)GetDeviceCaps(printer,VERTRES);
  if (prnwidth/winwidth>prnheight/winheight) {
    prnscale=(float)(0.7*prnheight/winheight);
    prnoff=(float)(0.15*prnheight);}
  else {
    prnscale=(float)(0.7*prnwidth/winwidth);
    prnoff=(float)(0.15*prnwidth);
  }

  /* create printerpen */
  mybrush.lbStyle=BS_SOLID;
  mybrush.lbColor=RGB(0,0,0);
  mybrush.lbHatch=HS_DIAGCROSS;
  printerpen=ExtCreatePen(PS_GEOMETRIC,(long)prnscale,&mybrush,0,NULL);
		
  /* set clipping region */
  GetClientRect(window,&interior);
  SelectClipRgn(printer,NULL);
  IntersectClipRect(printer,
		    (int)(interior.left*prnscale+prnoff),
		    (int)(interior.top*prnscale+prnoff),
		    (int)(interior.right*prnscale+prnoff),
		    (int)(interior.bottom*prnscale+prnoff));
		
  /* create printerfont */
  logfont.lfHeight=(long)(-fontheight*prnscale);
  printerfont=CreateFontIndirect(&logfont);
  if (printerfont==NULL) {
    sprintf(string,"Could not create font for printer");
    error(ERROR,string);
    return;
  }
				
  di.cbSize=sizeof(DOCINFO);
  di.lpszDocName="yabasic grafics";
  di.lpszOutput=(print_to_file)?prfilename:(LPTSTR)NULL;
  di.lpszDatatype=(LPTSTR)NULL;
  di.fwType=0;
  if (StartDoc(printer,&di)==SP_ERROR) {
    error(ERROR,"Couldn't start printing");
    return;
  }
  StartPage(printer);
  first=FALSE;
#else /* UNIX */
  fprintf(printerfile,"%%!PS-Adobe-1.0\n");
  fprintf(printerfile,"%%%%Title: %s grafic\n",progname);
  fprintf(printerfile,"%%%%BoundingBox: 0 0 %i %i\n",
	  (int)(winwidth*psscale),(int)(winheight*psscale));
  fprintf(printerfile,"%%%%DocumentFonts: Helvetica\n");
  fprintf(printerfile,"%%%%Creator: yabasic\n");
  fprintf(printerfile,"%%%%Pages: (atend)\n");
  fprintf(printerfile,"%%%%EndComments\n");
  fprintf(printerfile,"gsave\n");
  fprintf(printerfile,"/mem 4 dict def\n");
  fprintf(printerfile,"/pt 4 dict def\n");
  fprintf(printerfile,"/M {moveto} def\n");
  fprintf(printerfile,"/RL {rlineto} def\n");
  fprintf(printerfile,"/L {lineto} def\n");
  fprintf(printerfile,"/N {newpath} def\n");
  fprintf(printerfile,"/S {stroke} def\n");
  fprintf(printerfile,"/D {0 setgray N M 0 %g RL %g 0 RL 0 %g RL"
	  " closepath fill} def\n",psscale,psscale,-psscale);
  fprintf(printerfile,"/C {N 0 360 arc} def\n");
  fprintf(printerfile,"/AT {mem /txt 3 -1 roll put \n");
  fprintf(printerfile,"     mem /xa 3 -1 roll put\n");
  fprintf(printerfile,"     mem /y 3 -1 roll put\n");
  fprintf(printerfile,"     mem /x 3 -1 roll put    \n");
  fprintf(printerfile,"     N mem /x get mem /y get M\n");
  fprintf(printerfile,"     mem /txt get false charpath pathbbox\n");
  fprintf(printerfile,"     pop exch pop exch sub\n");
  fprintf(printerfile,"     mem /x get exch\n");
  fprintf(printerfile,"     mem /xa get (c) eq {2 div sub} if\n");
  fprintf(printerfile,"     mem /xa get (l) eq {pop} if\n");
  fprintf(printerfile,"     mem /xa get (r) eq {sub} if\n");
  fprintf(printerfile,"     mem /y get M\n");
  fprintf(printerfile,"     mem /txt get show\n");
  fprintf(printerfile,"} def\n");
  fprintf(printerfile,"/F {pt /y2 3 -1 roll put\n");
  fprintf(printerfile,"pt /x2 3 -1 roll put\n");
  fprintf(printerfile,"pt /y1 3 -1 roll put\n");
  fprintf(printerfile,"pt /x1 3 -1 roll put\n");
  fprintf(printerfile,"N 1 setgray\n");
  fprintf(printerfile,"pt /x1 get pt /y1 get M\n");
  fprintf(printerfile,"pt /x1 get pt /y2 get L\n");
  fprintf(printerfile,"pt /x2 get pt /y2 get L\n");
  fprintf(printerfile,"pt /x2 get pt /y1 get L\n");
  fprintf(printerfile,"pt /x1 get pt /y1 get L\n");
  fprintf(printerfile,"fill\n");
  fprintf(printerfile,"0 setgray} def\n");
  fprintf(printerfile,"/Helvetica findfont\n");
  fprintf(printerfile,"%g scalefont setfont\n",(double)fontheight*psscale);
  fprintf(printerfile,"30 30 translate\n");
  fflush(printerfile);
#endif
}


void closeprinter() /* closes printer for WIN95 */
{
#ifdef WINDOWS
  EndPage(printer);
  EndDoc(printer);
#else /* UNIX */
  if (printerfile) {
    fprintf(printerfile,"showpage\ngrestore\n%%%%Trailer\n");
    fclose(printerfile);
    printerfile=NULL;
    if (!strncmp(prfilename,"/tmp/",5)) {
      sprintf(string,"lpr %s",prfilename);
      if (system(string)) {
	sprintf(string,"couldn't print '%s'",prfilename);
	error(ERROR,string);
	return;
      }
      remove(prfilename);
    }
  }
#endif
  if (prfilename) {
    free(prfilename);
    prfilename=NULL;
  }
}


void create_exception(int flag) /* create command 'exception' */
{
  struct command *cmd;  
	
  cmd=add_command(cEXCEPTION);
  cmd->args=flag;
}


void exception(struct command *cmd) /* change handling of exceptions */
{
  if (cmd->args) {
    signal(SIGINT,signal_handler); /* enable keyboard interrupt */
  }
  else {
    signal(SIGINT,SIG_IGN); /* ignore keyboard interrupt */
  }
  return;
}


void initialize() 
     /* give correct values to pointers etc ... */
{
  int i;
	
  /* install exception handler */
  signal(SIGFPE,signal_handler);
  signal(SIGSEGV,signal_handler);
  signal(SIGINT,signal_handler);
	
  /* initialize error handling: no errors seen 'til now */
  errorlevel=DIAGNOSTIC;  
  diagnostic_count=0;
  note_count=0;
  warning_count=0;
  error_count=0;
	
  /* initialize symbol table */
  symroot=(struct symbol *)my_malloc(sizeof(struct symbol)); /* ceate first */
  symroot->type=syFREE;
  symroot->pointer=NULL;
  symroot->next=NULL;
  symroot->name=NULL;
  symroot->value=0.0;
	
  /* initialize numeric stack */
  /* create first : */
  stackroot=(struct stackentry *)my_malloc(sizeof(struct stackentry)); 
  stackroot->next=NULL;
  stackroot->prev=NULL;
  stackroot->value=0.0;
	
  /* initialize command stack */
  /* create first : */
  cmdroot=(struct command *)my_malloc(sizeof(struct command)); 
  cmdroot->next=NULL;
	
  /* initialize random number generator */
  srand((unsigned int)time(NULL));
	
  /* specify default text-alignement and window origin */
  text_align=my_strdup("lb");
  winorigin=my_strdup("lt");
	
  reset();
	
  datapointer=cmdroot; /* restore for read data */
	
  /* file stuff */
  for(i=1;i<=9;i++) streams[i]=NULL;
  printerfile=NULL; /* no ps-file yet */
	
  /* array with explanation */
  for(i=cFIRST_COMMAND;i<=cLAST_COMMAND;i++) explanation[i]="???";
  explanation[cFIRST_COMMAND]="FIRST_COMMAND";
  explanation[cFINDNOP]="FINDNOP";
  explanation[cEXCEPTION]="EXCEPTION";
  explanation[cLABEL]="LABEL";
  explanation[cGOTO]="GOTO";
  explanation[cQGOTO]="QGOTO";
  explanation[cGOSUB]="GOSUB";
  explanation[cQGOSUB]="QGOSUB";
  explanation[cRETURN]="RETURN";
  explanation[cEND]="END";
  explanation[cDECIDE]="DECIDE";
  explanation[cSKIPPER]="SKIPPER";
  explanation[cSKIPONCE]="SKIPONCE";
  explanation[cRESETSKIPONCE]="RESETSKIPONCE";
  explanation[cNOP]="NOP";
  explanation[cDIM]="DIM";
  explanation[cFUNCTION]="FUNCTION";
  explanation[cDOARRAY]="DOARRAY";
  explanation[cDBLADD]="DBLADD";
  explanation[cDBLMIN]="DBLMIN";
  explanation[cDBLMUL]="DBLMUL";
  explanation[cDBLDIV]="DBLDIV";
  explanation[cDBLPOW]="DBLPOW";
  explanation[cNEGATE]="NEGATE";
  explanation[cPUSHDBLSYM]="PUSHDBLSYM";
  explanation[cPOPDBLSYM]="POPDBLSYM";
  explanation[cPUSHDBL]="PUSHDBL";
  explanation[cPOKE]="POKE";
  explanation[cAND]="AND";
  explanation[cOR]="OR";
  explanation[cNOT]="NOT";
  explanation[cLT]="LT";
  explanation[cGT]="GT";
  explanation[cLE]="LE";
  explanation[cGE]="GE";
  explanation[cEQ]="EQ";
  explanation[cNE]="NE";
  explanation[cSTREQ]="STREQ";
  explanation[cSTRNE]="STRNE";
  explanation[cPUSHSTRSYM]="PUSHSTRSYM";
  explanation[cPOPSTRSYM]="POPSTRSYM";
  explanation[cPUSHSTR]="PUSHSTR";
  explanation[cCONCAT]="CONCAT";
  explanation[cPUSHSTRPTR]="PUSHSTRPTR";
  explanation[cCHANGESTRING]="CHANGESTRING";
  explanation[cTOKEN]="TOKEN";
  explanation[cPRINT]="PRINT";
  explanation[cREAD]="READ";
  explanation[cRESTORE]="RESTORE";
  explanation[cQRESTORE]="QRESTORE";
  explanation[cREADDATA]="READDATA";
  explanation[cONESTRING]="ONESTRING";
  explanation[cDATA]="DATA";
  explanation[cOPEN]="OPEN";
  explanation[cCLOSE]="CLOSE";
  explanation[cSWITCH]="SWITCH";
  explanation[cWAIT]="WAIT";
  explanation[cBELL]="BELL";
  explanation[cMOVE]="MOVE";
  explanation[cCLEARSCR]="CLEARSCR";
  explanation[cOPENWIN]="OPENWIN";
  explanation[cDOT]="DOT";
  explanation[cLINE]="LINE";
  explanation[cCIRCLE]="CIRCLE";
  explanation[cTEXT]="TEXT";
  explanation[cCLOSEWIN]="CLOSEWIN";
  explanation[cCLEARWIN]="CLEARWIN";
  explanation[cOPENPRN]="OPENPRN";
  explanation[cCLOSEPRN]="CLOSEPRN";
  explanation[cTESTEOF]="TESTEOF";
  explanation[cREVERT]="REVERT";
  explanation[cMAKEMAP]="MAKEMAP";
  explanation[cTICK]="TICK";
  explanation[cMAP]="MAP";
  explanation[cMARKER]="MARKER";
  explanation[cDUPLICATE]="DUPLICATE";
  explanation[cEND]="END";
  explanation[cSTARTFOR]="STARTFOR";
  explanation[cFORCHECK]="FORCHECK";
  explanation[cFORINCREMENT]="FORINCREMENT";
  explanation[cLAST_COMMAND]="???";
}


void signal_handler(int sig)   /* handle signals */
{
  signal(sig,SIG_DFL);
#ifdef WINDOWS
  SuspendThread(mainthread);
#endif
  if (program_state==FINISHED) {
    exit(1);
  }
  switch(sig) {
  case SIGFPE:
    error(FATAL,"Floating point exception, cannot proceed.");
  case SIGSEGV:
    error(FATAL,"Segmentation violation, cannot proceed.");
  case SIGINT:
    error(FATAL,"Keyboard interrupt, cannot proceed.");
#ifdef UNIX
  case SIGALRM: /* ignore */
    break;
#endif
  default:
    break;
  }
}


void reset() 
     /*
reset pointers to their initial values, 
initialize variables and functions 
*/
{
  struct symbol *s;
  struct stackentry *base;
  int i;
	
  symhead=symroot; /* list of double symbols */
  stackhead=stackroot; /* stack of double values */
  base=push();
  base->type=stFREE; /* push nil, so that pop will not crash */
  cmdhead=cmdroot; /* list of commands */;
  commandcount=0;
	
  /* create useful variables */
  s=get_sym("PI",syNUMBER,TRUE);
  s->value=3.14159265359;
  s=get_sym("pi",syNUMBER,TRUE);
  s->value=3.14159265359;
  s=get_sym("EULER",syNUMBER,TRUE);
  s->value=2.71828182864;
  s=get_sym("euler",syNUMBER,TRUE);
  s->value=2.71828182864;
	
  /* add internal string variables */
  s=get_sym("yabos$",sySTRING,TRUE);
  free(s->pointer);
#ifdef UNIX
  s->pointer=my_strdup("unix");
#else
  s->pointer=my_strdup("windows");
#endif
	
  /* set default-scales for grafics */
  fontheight=10;
  winheight=100;
  winwidth=100;
  calc_psscale();
	
  /* file stuff */
  for(i=1;i<=9;i++) 
    if (streams[i]!=NULL) {
      sprintf(string,"Stream %d not closed; closing it now",i);
      error(NOTE,string);
      fclose(streams[i]);
    }
}


void run_it()
     /* execute the compiled code */
{
  int endflag=FALSE;
	
  current=cmdroot; /* start with first comand */
  while(current!=cmdhead && !endflag && errorlevel>ERROR) {
    /* print command name */
    std_diag("executing",current->type);
    switch(current->type) {
    case cGOTO:case cQGOTO:case cGOSUB:case cQGOSUB:
      jump(current); DONE;
    case cEXCEPTION:
      exception(current); DONE;
    case cSKIPPER: 
      skipper(); break;
    case cSKIPONCE:
      skiponce(current); DONE;
    case cRESETSKIPONCE:
      resetskiponce(current); DONE;
    case cFINDNOP:
      findnop(); DONE;
    case cLABEL:case cDATA:case cNOP: 
      DONE;
    case cRETURN:
      myreturn(); DONE;
    case cPUSHDBLSYM: 
      pushdblsym(current); DONE;
    case cPUSHDBL:
      pushdbl(current); DONE;
    case cPOPDBLSYM:
      popdblsym(current); DONE;
    case cPOPSTRSYM:
      popstrsym(current); DONE;
    case cPUSHSTRSYM: 
      pushstrsym(current); DONE;
    case cPUSHSTR:
      pushstr(current); DONE;
    case cCONCAT:
      concat(); DONE;
    case cPRINT:
      print(current); DONE;
    case cMOVE:
      mymove(); DONE;
    case cREVERT:
      revert(current); DONE;
    case cCLEARSCR:
      clearscreen(); DONE;
    case cONESTRING:
      onestring(current->pointer); DONE;
    case cTESTEOF:
      testeof(current); DONE;
    case cOPEN:
      myopen(current); DONE;
    case cCLOSE:
      myclose(current); DONE;
    case cSWITCH:
      myswitch(current); DONE;
    case cCHKPROMPT:
      chkprompt(); DONE;
    case cREAD:
      myread(current); DONE;
    case cRESTORE:case cQRESTORE:
      restore(current); DONE;
    case cREADDATA:
      readdata(current); DONE;
    case cDBLADD:case cDBLMIN:case cDBLMUL:case cDBLDIV:case cDBLPOW:
      dblbin(current); DONE;
    case cNEGATE:
      negate(); DONE;
    case cEQ:case cNE:case cGT:case cGE:case cLT:case cLE:
      dblrelop(current); DONE;
    case cSTREQ:case cSTRNE:case cSTRLT:case cSTRLE:case cSTRGT:case cSTRGE:
      strrelop(current); DONE;
    case cAND:case cOR:case cNOT:
      boole(current); DONE;
    case cFUNCTION:
      function(current); DONE;
    case cTOKEN:
      token(current); DONE;
    case cDOARRAY:
      doarray(current); DONE;
    case cCHANGESTRING:
      changestring(current); DONE;
    case cPUSHSTRPTR:
      pushstrptr(current); DONE;
    case cDIM:
      dim(current); DONE;
    case cDECIDE:
      decide(); DONE;
    case cOPENWIN:
      openwin(current); DONE;
    case cMOVEORIGIN:
      moveorigin(NULL); DONE;
    case cOPENPRN:
      openprinter(current); DONE;
    case cCLOSEPRN:
      closeprinter(); DONE;
    case cDOT:
      dot(); DONE;
    case cLINE:
      line(current); DONE;
    case cCIRCLE:
      circle(); DONE;
    case cTEXT:
      text(current); DONE;
    case cCLOSEWIN:
      closewin(); DONE;
    case cCLEARWIN:
      clearwin(); DONE;
    case cMAKEMAP:
      makemap(); DONE;
    case cMAP:
      map(); DONE;
    case cTICK:
      tick(current); DONE;
    case cRECT:
      rect(current); DONE;
    case cMARKER:
      marker(current); DONE;
    case cWAIT:
      mywait(); DONE;
    case cBELL:
      mybell(); DONE;
    case cPOKE:
      poke(current); DONE;
    case cSWAP:
      swap(); DONE;
    case cDUPLICATE:
      duplicate(); DONE;
    case cFORCHECK:
      forcheck(); DONE;
    case cFORINCREMENT:
      forincrement(); DONE;
    case cSTARTFOR:
      startfor(); DONE;
    case cEND:
      endflag=TRUE; break;
    default:
      sprintf(string,"Command %s (%d) not implemented",
	      explanation[current->type],current->type);
      error(ERROR,string);
    }
  }
  program_state=FINISHED;
  switch(errorlevel) {
  case NOTE:case DIAGNOSTIC: 
    error(NOTE,"Program ended normally."); break;
  case WARNING:
    error(WARNING,"Program ended with a warning"); break;
  case ERROR:
    error(ERROR,"Program stopped due to an error"); break;
  case FATAL: /* should not come here ... */
    error(FATAL,"Program terminated due to FATAL error");
    break;
  }
}


void error(int severe, char *message) 
     /* reports an basic error to the user and possibly exits */
{
	
  if (severe<=infolevel) {
#ifdef UNIX
    if (curinized) reset_shell_mode();
#endif
    fprintf(stderr,"---");
    switch(severe) {
    case(DIAGNOSTIC): 
      fprintf(stderr,"Diagnostic"); 
      diagnostic_count++;
      break;
    case(NOTE): 
      fprintf(stderr,"Note"); 
      note_count++;
      break;
    case(WARNING): 
      fprintf(stderr,"Warning"); 
      warning_count++;
      break;
    case(ERROR): 
      fprintf(stderr,"Error"); 
      error_count++;
      break;
    case(FATAL): 
      fprintf(stderr,"Fatal"); 
      break;
    }
    if (program_state==COMPILING) {
      if (end_of_file) 
	fprintf(stderr," at end of file");
      else
	fprintf(stderr," in line %d",yylineno);
    }
    else if (program_state==RUNNING && current->line>0) 
      fprintf(stderr," in line %d",current->line);
		
    fprintf(stderr,": %s\n\r",message);
  }
  if (severe<errorlevel) errorlevel=severe;
  if (severe<=ERROR) program_state=FINISHED;
  if (severe<=FATAL) {
    program_state=FINISHED;
    fprintf(stderr,"---Immediate exit to system, due to a fatal error.\n");
    end_it(1);
  }
#ifdef UNIX
  if (curinized && severe<=infolevel) reset_prog_mode();
#endif
}


char *my_strndup(char *arg,int len) /*  own version of strndup */
{
  char *copy;
	
  copy=my_malloc(len+1);
  if (!copy) return NULL;
	
  strncpy(copy,arg,len);
  copy[len]='\0';
	
  return copy;
}


char *my_strdup(char *arg)  /* my own version of strdup, checks for failure */
{
  int l;
	
  l=strlen(arg);
  return my_strndup(arg,l);
}


void *my_malloc(unsigned num) /* Alloc memory and issue warning on failure */
{
  void *room;
	
  room=malloc(num);
  if (room==NULL) {
    sprintf(string,"Can't malloc %d bytes of memory",num);
    error(FATAL,string);
  }
  return room;
}


