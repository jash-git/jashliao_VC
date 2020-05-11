#ifndef _MOTION
#define _MOTION

#define _WIN95

#define _MSC

#if defined(_WINNT)
	#undef _MSDOS
	#undef _WIN95
	#define _WINNT95
#elif defined(_MSDOS)
	#undef _WINNT
	#undef _WIN95
#elif defined(_WIN95)
	#undef _WINNT
	#undef _MSDOS
	#define _WINNT95
#endif

#if defined(_BC31)
	#undef _MSC
#elif defined(_MSC)
	#undef _BC31
#endif

/////////////////////////////////////////////////////////////////////

#ifdef _WINNT 
  #define FNTYPE PASCAL
#endif

#ifdef _WIN95
  #define FNTYPE PASCAL
#endif

#ifdef _MSDOS
  #define FNTYPE 
#endif

#ifdef _BC31

  #define _OUTPORTB outportb
  #define _OUTPORTW outport
  #define _INPORTB inportb
  #define _INPORTW inport

#endif

#ifdef _MSC

  #define _OUTPORTB _outp
  #define _OUTPORTW _outpw
  #define _INPORTB _inp
  #define _INPORTW _inpw

#endif


#endif