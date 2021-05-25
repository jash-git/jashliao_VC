This directory contains code implementing the Learning vector quantization
network.  Source code may be found in LVQ.CPP.  Sample training data is found
in LVQ1.PAT. Sample test data is found in LVQTEST1.TST and LVQTEST2.TST.  The
LVQ program accepts input consisting of vectors and calculates the LVQ
network weights. If a test set is specified, the winning neuron (class) for 
each neuron is identified and the Euclidean distance between the pattern and
each neuron is reported. Output is directed to the screen.

Usage for LVQ is:
   LVQ TRAININGFILE [TESTFILE] <enter>

   Specification of a test file is optional.

The format of both the training and the test file is:

  NumPatterns                              - Number of patterns (int)
  SizeVector                               - Size of vector  (int)
  NumClasses                               - Number of classes (int)
  vect[1,1]    ... vect[1,SizeVect]        - pattern vector 1 (real)
  vect[2,1]    ... vect[2,SizeVect]        - pattern vector 2 (real)
     .                     .
     .                     .
     .                     .
  vect[NPat,1] ... vect[NClust,SizeVector] - pattern vector N (real)
  Class                                    - Desired/Expected class membership


To compile:
   ICC LVQ.CPP  <enter>


