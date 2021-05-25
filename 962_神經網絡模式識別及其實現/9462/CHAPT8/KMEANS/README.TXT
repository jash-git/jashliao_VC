This directory contains code implementing the K-means algorithm.  Source code
may be found in KMEANS.CPP.  Sample data isfound in KM2.DAT.  The KMEANS
program accepts input consisting of vectors and calculates the given
number of cluster centers using the K-means algorithm.  Output is
directed to the screen.

Usage for KMEANS is:
   KMEANS SOURCEFILE <enter>

The format of the source file is:

  NPat                                     - Number of patterns (int)
  SizeVect                                 - Size of vector  (int)
  NClust                                   - Number of cluster centers(int)
  vect[1,1]    ... vect[1,SizeVect]        - vector 1 (real)
  vect[2,1]    ... vect[2,SizeVect]        - vector 2 (real)
     .                     .
     .                     .
     .                     .
  vect[NPat,1] ... vect[NClust,SizeVector] - vector N (real)


To compile:
   ICC KMEANS.CPP  <enter>
