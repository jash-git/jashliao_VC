This directory contains code implementing the adaptive resonance theory (ART)
network.  Source code may be found in ART.CPP.  Sample training data is found
in ART001.DAT and ART002.DAT. Sample results are found in ART001.OUT and 
ART002.OUT.  The ART program accepts input consisting of vectors and 
calculates the ART networks top down and bottom up weights.  Output is
directed to the screen.

Usage for ART is:
   ART PATTERN_FILE_NAME <enter>

   Specification of a test file is optional.

The format of both the pattern file is:

  NumPatterns                              - Number of patterns (int)
  SizeVector                               - Size of vector  (int)
  VigilThresh                              - Vigilence threshold (real)
  vect[1,1]    ... vect[1,SizeVect]        - pattern vector 1 (int)
  vect[2,1]    ... vect[2,SizeVect]        - pattern vector 2 (int)
     .                     .
     .                     .
     .                     .
  vect[NPat,1] ... vect[NClust,SizeVector] - pattern vector N (int)


To compile:
   ICC ART.CPP  <enter>



