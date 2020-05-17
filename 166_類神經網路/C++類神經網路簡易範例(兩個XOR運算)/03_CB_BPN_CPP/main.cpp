#include <iostream>
#include <cstdio>

#include "CBackProp.h"

using namespace std;

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
	// prepare XOR traing data
	double data[][4]={
				0,	0,	0,	0,
				0,	0,	1,	1,
				0,	1,	0,	1,
				0,	1,	1,	0,
				1,	0,	0,	1,
				1,	0,	1,	0,
				1,	1,	0,	0,
				1,	1,	1,	1 };

	// prepare test data
	double testData[][3]={
								0,      0,      0,
                                0,      0,      1,
                                0,      1,      0,
                                0,      1,      1,
                                1,      0,      0,
                                1,      0,      1,
                                1,      1,      0,
                                1,      1,      1};


	// defining a net with 4 layers having 3,3,3, and 1 neuron respectively,
	// the first layer is input layer i.e. simply holder for the input parameters
	// and has to be the same size as the no of input parameters, in out example 3
	int numLayers = 4, lSz[4] = {3,3,2,1};


	// Learing rate - beta
	// momentum - alpha
	// Threshhold - thresh (value of target mse, training stops once it is achieved)
	double beta = 0.3, alpha = 0.1, Thresh =  0.00001;


	// maximum no of iterations during training
	long num_iter = 2000000;


	// Creating the net
	CBackProp *bp = new CBackProp(numLayers, lSz, beta, alpha);
	long i=0;

	cout<< endl <<  "Now training the network...." << endl;
	for (i=0; i<num_iter ; i++)
	{

		bp->bpgt(data[i%8], &data[i%8][3]);

		if( bp->mse(&data[i%8][3]) < Thresh) {
			cout << endl << "Network Trained. Threshold value achieved in " << i << " iterations." << endl;
			cout << "MSE:  " << bp->mse(&data[i%8][3])
				 <<  endl <<  endl;
			break;
		}
		if ( i%(num_iter/10) == 0 )
			cout<<  endl <<  "MSE:  " << bp->mse(&data[i%8][3])
				<< "... Training..." << endl;

	}

	if ( i == num_iter )
		cout << endl << i << " iterations completed..."
		<< "MSE: " << bp->mse(&data[(i-1)%8][3]) << endl;

	cout<< "Now using the trained network to make predctions on test data...." << endl << endl;
	for ( i = 0 ; i < 8 ; i++ )
	{
		bp->ffwd(testData[i]);
		cout << testData[i][0]<< "  " << testData[i][1]<< "  "  << testData[i][2]<< "  " << bp->Out(0) << endl;
	}

	Pause();
    return 0;
}
