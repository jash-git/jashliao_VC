This directory contains code implementing the Kohonen self organizing feature 
map network. Source code may be found in SOFM.CPP.  Sample data is found in 
SOFMSAMP.PAT. The SOFM program accepts input consisting of vectors and 
calculates the weights. Output is directed to the screen.

Usage for SOFM is:
   SOFM SOURCEFILE <enter>

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
   ICC SOFM.CPP  <enter>


