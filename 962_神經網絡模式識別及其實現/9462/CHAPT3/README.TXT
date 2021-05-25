This directory contains code for 
  1) character compression using run length code 
        - see class RLCX in gridclas.cpp
  2) conversion of stroke data to a pixel map representation.
        - see stk2ras.cpp
For thinning code see the class cthinner in file: \chapt6\features.cpp.
There the features code applies thinning to a bit mapped character as a
prelude to geometric feature extraction.  The output (using the
sample data provided) graphicallyshows the effects of the thinning algorithm

Two programs are included in this directory:

STK2RAS takes a stroke file as input and converts it into a bit-per-pixel
representation (along with some header information, see RASHEADR.H).  The
output of the STK2RAS program is a .RAS file.  The GRID1 program found in
this directory is a PM program which takes a .RAS file as input and 
displays the image. Notice that the GRID1 program uses run length compression.  See
class RLCX to scale the image.

Usage for STK2RAS is
   STK2RAS fname <enter>

   where fname is the filename WITHOUT extention.  A .RAW extention
         is appended on input.  A .RAS extention is appended on output.

Several sample .RAW stroke files are included in this directory.

To compile STK2RAS:
   ICC STK2RAS.CPP  <enter>


Usage for GRID1
   GRID1 <enter>

To compile GRID1
   NMAKE   <enter>

A makefile is included for GRID1.
