This directory contains code implementing the Kohonen network.  Source code
may be found in KNET.CPP.  Sample data isfound in KNETSAMP.PAT.  Program output
can be found in KNETSAMP.OUT.The KNET program accepts input consisting of 
vectors and calculates the weights, thus identifying the cluster centers.
Output is directed to the screen.

Usage for KNET is:
   KNET SOURCEFILE <enter>

The format of the source file is:

  NPat                                     - Number of patterns (int)
  SizeVect                                 - Size of vector  (int)
  vect[1,1]    ... vect[1,SizeVect]        - vector 1 (real)
  vect[2,1]    ... vect[2,SizeVect]        - vector 2 (real)
     .                     .
     .                     .
     .                     .
  vect[NPat,1] ... vect[NClust,SizeVector] - vector N (real)


To compile:
   ICC KNET.CPP  <enter>

