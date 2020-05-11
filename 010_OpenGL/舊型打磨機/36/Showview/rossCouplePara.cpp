// rossCouplePara.cpp: implementation of the CrossCouplePara class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include <iostream.h>
#include <fstream.h>
#include "rossCouplePara.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CrossCouplePara::CrossCouplePara()
{
	d2r = PI/180;
	kpx = 0;
	kix = 0;
	kdx = 0;

	kpy = 0;
	kiy = 0;
	kdy = 0;

	kpc = 0;
	kic = 0;
	kdc = 0;

	Theta = 0;
	
	ax = 0;
	bx = 0;
	ay = 0;
	by = 0;
	
	Cx = sin(d2r*Theta);
	Cy = cos(d2r*Theta);

}

void CrossCouplePara::SetPara(double Parameter[14])
{
	kdx = Parameter[0];
	kpx = Parameter[1];
	kix = Parameter[2];

	kdy = Parameter[3];
	kpy = Parameter[4];
	kiy = Parameter[5];

	kdc = Parameter[6];
	kpc = Parameter[7];
	kic = Parameter[8];

	Theta = Parameter[9];
	
	ax = Parameter[10];
	bx = Parameter[11];
	ay = Parameter[12];
	by = Parameter[13];
	
	Cx = sin(d2r*Theta);
	Cy = cos(d2r*Theta);


}

CrossCouplePara::Compute(void)
{
	Delta[0] = 1;
	Delta[1] = (ay+by*kdy+by*kdc*pow(Cy,2))+(ax+bx*kdx+bx*kdc*pow(Cx,2));
	Delta[2] = (by*kpy+by*kpc*pow(Cy,2))+(ax+bx*kdx+bx*kdc*pow(Cx,2))*(ay+by*kdy+by*kdc*pow(Cy,2))
				+(bx*kpx+bx*kpc*pow(Cx,2))-(bx*by*pow(Cx,2)*pow(Cy,2)*pow(kdc,2));
	Delta[3] = (by*kiy*by*kic*pow(Cy,2))+(ax+bx*kdx+bx*kdc*pow(Cx,2))*(by*kpy+by*kpc*pow(Cy,2))
				+(bx*kpx+bx*kpc*pow(Cx,2))*(ay+by*kdy+by*kdc*pow(Cy,2))+(bx*kix+bx*kic*pow(Cx,2))-(2*bx*by*pow(Cx,2)*pow(Cy,2)*kdc*kpc);
	Delta[4] = (ax+bx*kdx+bx*kdc*pow(Cx,2))*(by*kiy+by*kic*pow(Cy,2))+(bx*kpx+bx*kpc*pow(Cx,2))*(by*kpy+by*kpc*pow(Cy,2))
				+(bx*kix+bx*kic*pow(Cx,2))*(ay+by*kdy+by*kdc*pow(Cy,2))-(bx*by*pow(Cx,2)*pow(Cy,2)*(2*kdc*kic+pow(kpc,2)));
	Delta[5] = (bx*kpx+bx*kpc*pow(Cx,2))*(by*kiy+by*kic*pow(Cy,2))+(bx*kix+bx*kic*pow(Cx,2))*(by*kpy+by*kpc*pow(Cy,2))
				-(2*bx*by*pow(Cx,2)*pow(Cy,2)*kpc*kic);
	Delta[6] = (bx*kix+bx*kic*pow(Cx,2))*(by*kiy+by*kic*pow(Cy,2))-(bx*by*pow(Cx,2)*pow(Cy,2)*pow(kic,2));


	K11[0] = (bx*kdx+bx*kdx*pow(Cx,2));
	K11[1] = (bx*kpx+bx*kpc*pow(Cx,2))+(ay+bx*kdy+by*kdc*pow(Cy,2))*(bx*kdx+bx*kdc*pow(Cx,2))
			-(bx*by*pow(Cx,2)*pow(Cy,2)*pow(kdc,2));
	K11[2] = (bx*kix+bx*kic*pow(Cx,2))+(ay+by*kdy+by*kdc*pow(Cy,2))*(bx*kpx+bx*kpc*pow(Cx,2))
			+(by*kpy+by*kpc*pow(Cy,2))*(bx*kdx+bx*kdc*pow(Cx,2))-(2*bx*by*pow(Cx,2)*pow(Cy,2)*kdc*kpc);
	K11[3] = (ay+by*kdy+by*kdc*pow(Cy,2))*(bx*kix+bx*kic*pow(Cx,2))+(by*kpy+by*kpc*pow(Cy,2))*(bx*kpx+bx*kpc*pow(Cx,2))
			+(by*kiy+by*kic*pow(Cy,2))*(bx*kdx+bx*kdc*pow(Cx,2))-(bx*by*pow(Cx,2)*pow(Cy,2)*(2*kdc*kic+pow(kpc,2)));
	K11[4] = (by*kpy+by*kpc*pow(Cy,2))*(bx*kix+bx*kic*pow(Cx,2))+(by*kiy+by*kic*pow(Cy,2))*(bx*kpx+bx*kpc*pow(Cx,2))
			-(2*bx*by*pow(Cx,2)*pow(Cy,2)*kpc*kic);
	K11[5] = (by*kiy+by*kic*pow(Cy,2))*(bx*kix+bx*kic*pow(Cx,2))-(bx*by*pow(Cx,2)*pow(Cy,2)*pow(kic,2));

	K12[0] = (bx*kdc*Cx*Cy);
	K12[1] = (ay*bx*kdc*Cx*Cy)+(bx*kpc*Cx*Cy);
	K12[2] = (ay*bx*kpc*Cx*Cy)+(bx*kic*Cx*Cy);
	K12[3] = (ay*bx*kic*Cx*Cy);
	K12[4] = 0;
	K12[5] = 0;

	K21[0] = (by*kdc*Cx*Cy);
	K21[1] = (ax*by*kdc*Cx*Cy)+(by*kpc*Cx*Cy);
	K21[2] = (ax*by*kpc*Cx*Cy)+(by*kic*Cx*Cy);
	K21[3] = (ax*by*kic*Cx*Cy);
	K21[4] = 0;
	K21[5] = 0;

	K22[0] = (by*kdy+by*kdc*pow(Cy,2));
	K22[1] = (by*kpy+by*kpc*pow(Cy,2))+(ax+bx*kdx+bx*kdc*pow(Cx,2))*(by*kdy+by*kdc*pow(Cy,2))
			-(bx*by*pow(Cx,2)*pow(Cy,2)*pow(kdc,2));
	K22[2] = (by*kiy+by*kic*pow(Cx,2))+(ax+bx*kdx+bx*kdc*pow(Cx,2))*(by*kpy+by*kpc*pow(Cx,2))
			+(bx*kpx+bx*kpc*pow(Cx,2))*(by*kdy+by*kdc*pow(Cy,2))-(2*bx*by*pow(Cx,2)*pow(Cy,2)*kdc*kpc);
	K22[3] = (ax+bx*kdx+bx*kdc*pow(Cx,2))*(by*kiy+by*kic*pow(Cy,2))+(bx*kpx+bx*kpc*pow(Cx,2))*(by*kpy+by*kpc*pow(Cy,2))
			+(bx*kix+bx*kic*pow(Cx,2))*(by*kdy+by*kdc*pow(Cy,2))-(bx*by*pow(Cx,2)*pow(Cy,2)*(2*kdc*kic+pow(kpc,2)));
	K22[4] = (bx*kpx+bx*kpc*pow(Cx,2))*(by*kiy+by*kic*pow(Cy,2))+(bx*kix+bx*kic*pow(Cx,2))*(by*kpy+by*kpc*pow(Cy,2))
			-(2*bx*by*pow(Cx,2)*pow(Cy,2)*kpc*kic);
	K22[5] = (bx*kix+bx*kic*pow(Cx,2))*(by*kiy+by*kic*pow(Cy,2))-(bx*by*pow(Cx,2)*pow(Cy,2)*pow(kic,2));
/*
	int i;
	cout<<endl<<endl;
	cout<<"===Under Object====================================="<<endl;
	cout<<"0\t"<<"1\t"<<"2\t"<<"3\t"<<"4\t"<<"5\t"<<"6\t"<<endl;
	cout<<"===================================================="<<endl;
	cout<<"Delta"<<endl;
	for(i=0;i<=6;i++)
	{
		cout<<*(Delta+i)<<"\t";
	}
	cout<<endl<<endl;
	cout<<"K11"<<endl;
	for(i=0;i<=5;i++)
	{
		cout<<*(K11+i)<<"\t";
	}
	cout<<endl<<endl;
	cout<<"K12"<<endl;
	for(i=0;i<=5;i++)
	{
		cout<<*(K12+i)<<"\t";
	}
	cout<<endl<<endl;
	cout<<"K21"<<endl;
	for(i=0;i<=5;i++)
	{
		cout<<*(K21+i)<<"\t";
	}
	cout<<endl<<endl;
	cout<<"K22"<<endl;
	for(i=0;i<=5;i++)
	{
		cout<<*(K22+i)<<"\t";
	}
	cout<<endl;
*/
}

void CrossCouplePara::GetPara (double delta[7], double k11[6], double k12[6], double k21[6], double k22[6])
{
	for(int i=0;i<=6;i++)
	{
		*(delta+i) = *(Delta+i);
	}
	for(int j=0;j<=5;j++)
	{
		*(k11+j) = *(K11+j);
		*(k12+j) = *(K12+j);
		*(k21+j) = *(K21+j);
		*(k22+j) = *(K22+j);
	}
}

CrossCouplePara::~CrossCouplePara()
{

}
