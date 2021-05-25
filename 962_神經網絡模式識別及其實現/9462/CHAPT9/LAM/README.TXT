This directory contains code implementing the linear associative memory.
Source code may be found in LAM.CPP.  Sample training and test files are
SAMPLE.TRN and SAMPLE.TST respectively.  LAM accepts training and test
inputs, displays calulation of the weights and thresholds, and performs
retrievals on the test data.  Output is directed to the screen.

Usage for LAM is:
   LAM TRAINING_FILE TEST_FILE <enter>

Training file format is:
NumPatterns         - Number of patterns
NumNeurons          - Number of neurons
V1 V2 ...Vn         - Pattern vector (each V is 0/1)
.  .     .
.  .     .
V1 V2 ...Vn

Test file format is:
NumPatterns         - Number of patterns
V1 V2 ...Vn         - Pattern vector (each V is 0/1)
.  .     .
.  .     .
V1 V2 ...Vn

To compile LAM:
   ICC LAM.CPP <enter>
