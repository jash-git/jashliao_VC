This README-file is part of the source-code-package
of yabasic. This package contains all sources for
yabasic, but no executable. Therefore it is of interest
only for those, who want to modify the program.
All files are subject to the GNU-copyleft, have
a look at the file copying.txt.

The package contains the following files:

     bison.c --- bison-generated routines, coding the
                 grammar of yabasic
     bison.h --- header for bison.c
      flex.c --- flex-generated routines for tokenization
                 of the input
   yabasic.c --- hand-coded file, implementing the rest
     		 of yabasic
   yabasic.h --- header file to yabasic.c
 yabasic.dsp --- project file for yabasic and MS VC++ 6.0
   yabinst.c --- source for the installation program
  resource.h --- resource file for installation program
 yabasic.ico --- icon for setup program and yabasic
 yabinst.dsp --- project file for installation program and MS VC++ 6.0
yabbison.txt --- bison input file
 yabflex.txt --- flex input file
 copying.txt --- GNU-copyleft file for all sources

Note for developers:
  Anyone who is interested in modify the grammar of
  yabasic should do this under Unix. Because the
  main tools used to code its grammar (bison and flex)
  are available only (?) under Unix.
