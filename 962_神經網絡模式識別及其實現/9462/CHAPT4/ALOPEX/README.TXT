Usage:

       ALOPEX  TrainFileName ParmFileName WeightFileName

Parm file format:

Qzero            -  Sigmoidal Gain (Neuron sigmoidal fn's Temperature)
ETA              -  ALOPEX learning rate
delta            -  ALOPEX step size
T                -  Alopex's temperature const (starting value)
MaxIter          -  Max # of iterations
ERRTOL           -  Error Tolerence for converence
NumLayers        -  Number of layers in target network
N(input)         -  Number of neurons in input layer
N(hidden1)       -  Number of neurons in 1st hidden layer
N(hidden2)       -  Number of neurons in 2nd hidden layer (if present)
   .
   .
   .
N(hiddenK)       -  Number of neurons in Kth hidden layer (if present)
N(output)        -  Number of neurons in output hidden layer 


Trainining file format:

NumPatterns      -  Number of patterns in training set

I0 I1 ... In  D  -  Real input for each input / desire value for pattern 1
I0 I1 ... In  D  -  Real input for each input / desire value for pattern 2
 .  .      .  .
 .  .      .  .
 .  .      .  .
I0 I1 ... In  D  -  Real input for each input / desire value for pattern P




