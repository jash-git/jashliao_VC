This directory contains code implementing Vector Quantization.  Source code
may be found in VQ.CPP.  Sample data isfound in VQ1.DAT, VQ2.DAT AND VQ3.DAT.
Program output can be found in VQ1.OUT, VQ2.OUT AND VQ3.OUT.The VQ program accepts 
input consisting of vectors and calculates the corresponding cluster centers.
Output is directed both to the screen and to the specified destination file.

Usage for VQ is:
   VQ SOURCEFILE DESTINATIONFILE <enter>

The format of the source file is:

  NPat                                   -  Number of patterns to be processed  (int)
  SizeVect                               -  Size of the vectors to be processed (int)
  Threshold                              -  Max dist permitted between cluster centers(real)
  vect[1,1]    ... vect[1,SizeVect]      -  Pattern definitions  (real)
  vect[2,1]    ... vect[2,SizeVect]            "         "
     .                     .                   "         "
     .                     .                   "         "
     .                     .                   "         "
  vect[NPat,1] ... vect[NClust,SizeVector]     "         " 


To compile:
   ICC VQ.CPP  <enter>


