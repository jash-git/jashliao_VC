There are two parts to this directory
   1) Training by backprop
   2) The GRID1 user interface for testing

Both source and exe are provided

1) TRAINING BY BACKPROP.

Usage:
bprop TrainingFile ParmFile WeightFile

Parm file format:

Temperature);
ETA          - learning rate
ALPHA        - momentum
MAXITER      - max iteration
ERRTOL       - error tolerence for convergence
NumLayers    - number of layers
N(input)     - Number of neurons in input layer
N(hidden1)   - Number of neurons in 1st hidden layer
N(hidden2)   - Number of neurons in 2nd hidden layer (if present)
   .
   .
   .
N(hiddenK)       -  Number of neurons in Kth hidden layer (if present)
N(output)        -  Number of neurons in output hidden layer 


Training file format:

NumPatterns      -  Number of patterns in training set

I0 I1 ... In  D  -  hex byte input for each input / desire value for pattern 1
I0 I1 ... In  D  -  hex byte input for each input / desire value for pattern 2
 .  .      .  .
 .  .      .  .
 .  .      .  .
I0 I1 ... In  D  -  hex byte input for each input / desire value for pattern P



Example usage may be found in the command files provided to train networks on the sample
training data.  The Samples likewise provide examples of parm and training files.  Note
that after training a .GBL file must be created so that GRID1 will be able to access the
trained weights and network parameters.  (For the sample data these files are provided
with a .gbx extension.  After training rename the .GBX file giving it a .GBL extension.



2) GRID1

To run the program it is only necessary to type GRID1 <ENTER> on the command line.

